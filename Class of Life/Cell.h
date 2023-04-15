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

public:
	Cell()
	{
		chromosomes = vector<Genome>();
	}

	Cell(Genome gen)
	{
		chromosomes = vector<Genome>();
		chromosomes.push_back(gen);
	}

	Cell(Genome* chs, int size)
	{
		chromosomes = vector<Genome> (chs, chs + size);
	}

	vector<Genome> GetChromosomes()
	{
		return chromosomes;
	}

	vector<Genome>& Chromosomes()
	{
		return chromosomes;
	}

	/// <summary>Checks if the cell should die. If so, returns true.</summary>
	bool CellDestruction()
	{
		for (int i = 0; i < chromosomes.size(); i++)
		{
			DNAPair pair = chromosomes[i].GetDNA();
			string firstCompliment = GetStringCompliment(pair.first);
			int diffCount = 0;

			for (int j = 0; j < pair.first.length(); j++)
			{
				if (pair.second[j] != firstCompliment[j])
					diffCount++;
			}

			if (diffCount > 5)
				return true;

			int atCount = 0, gcCount = 0;

			for (int j = 0; j < pair.first.length(); j++)
			{
				if (pair.first[j] == 'A' || pair.first[j] == 'T' || pair.second[j] == 'A' || pair.second[j] == 'T')
					atCount++;
				if (pair.first[j] == 'G' || pair.first[j] == 'C' || pair.second[j] == 'G' || pair.second[j] == 'C')
					gcCount++;
			}

			if (atCount > 3 * gcCount)
				return true;

			return false;
		}
	}

	/// <summary> DNA Large Mutation. Swaps the first 'a' in chromosome 'n' with 'b' in chromosome 'm'.</summary>
	void LargeMutation(string a, int n, string b, int m)
	{
		chromosomes[n].LargeMutationDNA(a, b);
		chromosomes[m].LargeMutationDNA(b, a);
	}

	/// <summary> DNA Small Mutation. Changes every 'a' to 'b', 'n' times in chromosome 'index'.</summary>
	void PointMutation(char a, char b, int n, int index)
	{
		chromosomes[index].PointMutationDNA(a, b, n);
	}

	/// <summary> Replaces 'a' with 'a'-reversed in chromosome 'n'.</summary>
	void ReverseMutation(string a, int n)
	{
		chromosomes[n].ReverseMutationDNA(a);
	}

	/// <summary> Finds and prints all Compliment Palindromes in input string. Has no effect on the actual object as the method is static.</summary>
	static void FindComplimentPalindromes(string s)
	{
		std::cout << std::endl;

		int length = s.length();

		//Cache
		string sub = "";
		int sublen = 0;
		string half = "";
		string secondHalf = "";

		for (int i = 0; i < length; i++)
		{
			for (int j = length - 1; j >= i; j--)
			{
				if (s[i] == GetCharCompliment(s[j]))
				{
					sublen = j - i + 1;

					if (sublen % 2 != 0 || sublen < 4)
						continue;

					sub = s.substr(i, sublen);
					half = s.substr(i, sublen / 2);

					if (half + GetStringCompliment(GetReverse(half)) == sub)
						std::cout << sub << std::endl;
				}
			}
		}

		std::cout << std::endl;
	}
};