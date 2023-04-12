#pragma once
#include <iostream>
#include <vector>
#include "Genome.h"

template<typename T>
using vector = std::vector <T>;
typedef std::pair<string, string> DNAPair;

class Cell : Genome
{
private:
	vector<Genome> chromosomes;


	static void FindComplimentPalindromes(string main, int start, int end, string firstHalf = "")
	{
		if (start >= end)
		{
			if(firstHalf.length() > 1)
				std::cout << firstHalf << GetStringCompliment(GetReverse(firstHalf)) << std::endl;

			return;
		}

		string s = main.substr(start, end - start + 1);

		if (firstHalf.length() > 0 && s[0] != GetCharCompliment(s[s.length() - 1]))
			return;

		for (int i = 0; i < s.length(); i++)
		{
			for (int j = s.length() - 1; j > i + 1; j--)
			{
				if (s[j] == GetCharCompliment(s[i]))
				{
					FindComplimentPalindromes(s, i + 1, j - 1, firstHalf + s[i]);
				}
			}
		}
	}

public:
	Cell(); //Constructor?

	void CellDestruction()
	{
		for (int i = 0; i < chromosomes.size(); i++)
		{
			DNAPair pair = chromosomes[i].GetDNA();
			string firstCompliment = GetStringCompliment(pair.first);
			int diffCount = 0;

			for (int j = 0; j < pair.first.length(); j++)
			{
				if (pair.second[j] != firstCompliment[j])
					diffCount += 1;
			}

			if (diffCount > 5)
				delete this;

			int atCount = 0, gcCount = 0;

			for (int j = 0; j < pair.first.length(); j++)
			{
				if (pair.first[j] == 'A' || pair.first[j] == 'T' || pair.second[j] == 'A' || pair.second[j] == 'T')
					atCount += 1;
				if (pair.first[j] == 'G' || pair.first[j] == 'C' || pair.second[j] == 'G' || pair.second[j] == 'C')
					gcCount += 1;
			}

			if (atCount > 3 * gcCount)
				delete this;
		}
	}

	void LargeMutation(string a, int n, string b, int m)
	{
		chromosomes[n].LargeMutationDNA(a, b);
		chromosomes[m].LargeMutationDNA(b, a);
	}

	void PointMutation(char a, char b, int n, int index)
	{
		chromosomes[index].PointMutationDNA(a, b, n);
	}

	void ReverseMutation(string a, int n)
	{
		chromosomes[n].ReverseMutationDNA(a);
	}

	static void FindComplimentPalindromes(string main)
	{
		FindComplimentPalindromes(main, 0, main.length() - 1);
	}
};