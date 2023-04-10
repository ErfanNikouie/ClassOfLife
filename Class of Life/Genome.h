#pragma once
#include <iostream>
#include <string>
#include "RK.h"

typedef std::string string;
typedef std::pair<string, string> DNAPair;

class Genome
{
private:
	DNAPair DNA;
	string RNA;


	static char GetCharCompliment(char c)
	{
		if (c == 'A')
			return 'T';

		if (c == 'T')
			return 'A';

		if (c == 'G')
			return 'C';

		if (c == 'C')
			return 'G';
	}
	static string GetStringCompliment(string s)
	{
		string c = s;
		for (int i = 0; i < c.length(); i++)
			c[i] = GetCharCompliment(c[i]);

		return c;
	}

public:

	Genome(string rna)
	{
		RNA = rna;
		DNA.first = rna;
		DNA.second = GetStringCompliment(DNA.first);
	}

	DNAPair GetDNA()
	{
		return DNA;
	}

	string GetRNA()
	{
		return RNA;
	}

	/// <summary> DNA Small Mutation. Changes every 'a' to 'b', 'n' times.</summary>
	void PointMutationDNA(char a, char b, int n)
	{
		int iterator = 0;
		for (int i = 0; i < DNA.first.length(); i++)
		{
			if (DNA.first[i] == a)
			{
				DNA.first[i] = b;
				DNA.second[i] = GetCharCompliment(b);
			}

			if (DNA.second[i] == a)
			{
				DNA.second[i] = b;
				DNA.first[i] = GetCharCompliment(b);
			}

			if ((DNA.first[i] == a) || (DNA.second[i] == a))
				iterator++;

			if (iterator == n)
				break;
		}
	}

	/// <summary> RNA Small Mutation. Changes every 'a' to 'b', 'n' times.</summary>
	void PointMutationRNA(char a, char b, int n)
	{
		int iterator = 0;
		for (int i = 0; i < DNA.first.length(); i++)
		{
			if (RNA[i] == a)
			{
				RNA[i] = b;
				iterator++;
			}

			if (iterator == n)
				break;
		}
	}

	/// <summary> DNA Large Mutation. Replaces the first a with b.</summary>
	void LargeMutationDNA(string a, string b)
	{
		int diff = a.length() - b.length();

		//Find a in DNA first and second
		int firstOccurance = RKSearch(DNA.first, a);
		int secondOccurance = RKSearch(DNA.second, a);

		if (firstOccurance <= secondOccurance)
		{
			string prefix = DNA.first.substr(0, firstOccurance);
			string suffix = DNA.first.substr(firstOccurance + b.length() + diff, DNA.first.length() - firstOccurance - b.length() - diff);

			string merge = prefix + b + suffix;
			
			DNA.first = merge;
			DNA.second = GetStringCompliment(merge);
		}
		else
		{
			string prefix = DNA.second.substr(0, secondOccurance);
			string suffix = DNA.second.substr(secondOccurance + b.length() + diff, DNA.second.length() - secondOccurance - b.length() - diff);

			string merge = prefix + b + suffix;

			DNA.second = merge;
			DNA.first = GetStringCompliment(merge);
		}
		
	}

	/// <summary> RNA Large Mutation. Replaces the first a with b.</summary>
	void LargeMutationRNA(string a, string b)
	{
		int diff = a.length() - b.length();
		//Find a in RNA
		int occurance = RKSearch(RNA, a);
		
		string prefix = RNA.substr(0, occurance);
		string suffix = RNA.substr(occurance + b.length() + diff, RNA.length() - occurance - b.length() - diff);

		string merge = prefix + b + suffix;

		RNA = merge;
	}
	
	static string CreateDNA(string rna)
	{
		return GetStringCompliment(rna);
	}
};

