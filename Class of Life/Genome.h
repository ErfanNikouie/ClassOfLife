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

	string Replace(string main, string rep, int index, int diff)
	{
		string prefix = main.substr(0, index);
		string suffix = main.substr(index + rep.length() + diff, main.length() - index - rep.length() - diff);

		string merge = prefix + rep + suffix;

		return merge;
	}

protected:

	static string GetReverse(string s)
	{
		string out = "";

		for (int i = s.length() - 1; i >= 0; i--)
			out += s[i];

		return out;
	}

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

	Genome()
	{
		RNA = "";
		DNA.first = "";
		DNA.second = "";
	}

	/// <summary> Initialize genome with RNA.</summary>
	Genome(string rna)
	{
		RNA = rna;
	}

	/// <summary> Initialize genome with DNA.</summary>
	Genome(string first, string second)
	{
		DNA.first = first;
		DNA.second = second;
	}

	/// <summary> Returns DNA.</summary>
	DNAPair GetDNA()
	{
		return DNA;
	}
	/// <summary> Returns RNA.</summary>
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

	/// <summary> DNA Large Mutation. Replaces the first 'a' with 'b'.</summary>
	void LargeMutationDNA(string a, string b)
	{
		int diff = a.length() - b.length();

		//Find a in DNA first and second
		int firstOccurance = RKSearch(DNA.first, a);
		int secondOccurance = RKSearch(DNA.second, a);

		if (firstOccurance <= secondOccurance)
		{
			DNA.first = Replace(DNA.first, b, firstOccurance, diff);
			DNA.second = Replace(DNA.second, GetStringCompliment(b), firstOccurance, diff);
		}
		else
		{
			DNA.second = Replace(DNA.second, b, secondOccurance, diff);
			DNA.first = Replace(DNA.first, GetStringCompliment(b), secondOccurance, diff);
		}
	}

	/// <summary> RNA Large Mutation. Replaces the first 'a' with 'b'.</summary>
	void LargeMutationRNA(string a, string b)
	{
		int diff = a.length() - b.length();
		//Find a in RNA
		int occurance = RKSearch(RNA, a);
		RNA = Replace(RNA, b, occurance, diff);
	}

	/// <summary> DNA Reverse Mutation. Replaces the first 'a' with 'a'-reversed.</summary>
	void ReverseMutationDNA(string a)
	{
		//Find a in DNA first and second
		int firstOccurance = RKSearch(DNA.first, a);
		int secondOccurance = RKSearch(DNA.second, a);

		string reva = GetReverse(a);

		if (firstOccurance <= secondOccurance)
		{
			DNA.first = Replace(DNA.first, reva, firstOccurance, 0);
			DNA.second = Replace(DNA.second, GetStringCompliment(reva), firstOccurance, 0);
		}
		else
		{
			DNA.first = Replace(DNA.first, GetStringCompliment(reva), secondOccurance, 0);
			DNA.second = Replace(DNA.second, reva, secondOccurance, 0);
		}
	}

	/// <summary> RNA Reverse Mutation. Replaces the first 'a' with 'a'-reversed.</summary>
	void ReverseMutationRNA(string a)
	{
		int occurance = RKSearch(RNA, a);

		string reva = GetReverse(a);

		for (int i = 0; i < a.length(); i++)
			RNA[occurance + i] = reva[i];
	}
	
	/// <summary> Returns the compliment of input string. Has no effect on the actual object as the method is static.</summary>
	static string CreateDNA(string rna)
	{
		return GetStringCompliment(rna);
	}
};

