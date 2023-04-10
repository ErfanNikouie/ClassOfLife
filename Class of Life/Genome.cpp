#include "Genome.h"
using Genome;

	char Genome::GetCharCompliment(char c)
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
	static string Genome::GetStringCompliment(string s)
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

	void LargeMutationDNA(string a, string b)
	{

	}

	void LargeMutationRNA(string a, string b)
	{

	}

	static string CreateDNA(string rna)
	{
		return GetStringCompliment(rna);
	}
