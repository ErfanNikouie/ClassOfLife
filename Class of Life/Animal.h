#pragma once
#include <iostream>
#include <vector>
#include "FYShuffle.h"
#include "Genome.h"
#include "Cell.h"

template<typename T>
using vector = std::vector <T>;
typedef std::pair<string, string> DNAPair;
typedef Genome Gene;

//Why even inherit Cell??
class Animal : Cell
{
private:
	Cell cell; //Selected cell for an animal.

	// Checks if two animals are similar: if both have the same amount of chromosomes and the same chromosomes for at least 70%.
	/// <summary> Returns a float between 0 and 1.</summary>
	static float GetSimilarity(Animal a, Animal b)
	{
		auto geneA = a.cell.GetChromosomes();
		auto geneB = b.cell.GetChromosomes();

		int min = (geneA.size() > geneB.size())? geneB.size() : geneA.size();

		//Cache
		int c = 0;
		bool condition = false;
		DNAPair dnaA, dnaB;

		for (int i = 0; i < min; i++)
		{
			dnaA = geneA[i].GetDNA();
			dnaB = geneB[i].GetDNA();
			condition = dnaA.first == dnaB.first || dnaA.second == dnaB.second || dnaA.second == dnaB.first || dnaA.first == dnaB.second;

			if (condition)
				c++;
		}

		return (float)c / (float)min;
	}

	/// <summary> Returns another object of Animal class.</summary>
	static Animal AsexualReproduction(Animal a)
	{
		srand((unsigned)time(NULL));
		int random = 0;

		auto v = a.cell.GetChromosomes();
		int size = v.size();

		Gene* gene = new Gene[size];
		std::copy(v.begin(), v.end(), gene);

		Gene* chromosomes = new Gene[size];

		int indexSize = ceil((float)size * 7.0f / 10.0f);
		int startIndex = rand() % ((size % indexSize) + 1);

		// 7/10 random same indices
		for (int i = 0; i < indexSize; i++)
			chromosomes[i + startIndex] = gene[i + startIndex];

		// Shuffle and fill for the rest
		FYShuffle(gene, size);

		for (int i = 0; i < startIndex; i++)
			chromosomes[i] = gene[i];

		for (int i = startIndex + indexSize; i < size; i++)
			chromosomes[i] = gene[i];

		return Animal(Cell(chromosomes, size));
	}

	/// <summary> Returns another object of Animal class.</summary>
	static Animal SexualReproduction(Animal a, Animal b)
	{
		Animal childA = AsexualReproduction(a);
		Animal childB = AsexualReproduction(b);
		
		auto va = childA.cell.GetChromosomes();
		auto vb = childA.cell.GetChromosomes();
		int size = va.size();

		Gene* geneA = new Gene[size];
		std::copy(va.begin(), va.end(), geneA);

		Gene* geneB = new Gene[size];
		std::copy(vb.begin(), vb.end(), geneB);

		Gene* chromosomes = new Gene[size];

		int indexSize = (int)ceil(((float)size / 2.0f) * 7.0f / 10.0f);

		// 4/10 same indices
		for (int i = 0; i < indexSize; i++)
			chromosomes[i] = geneA[i];

		// 4/10 same indices
		for (int i = 0; i < indexSize; i++)
			chromosomes[i + indexSize + 2] = geneA[i + indexSize + 2];

		FYShuffle(geneA, size);
		FYShuffle(geneB, size);

		for (int i = indexSize; i < (int)ceil((float)size / 2.0f); i++)
			chromosomes[i] = geneA[i];
		for (int i = (int)ceil((float)size / 2.0f) + indexSize; i < size; i++)
			chromosomes[i] = geneB[i];

		return Animal(Cell(chromosomes, size));
	}

public:
	Animal(Cell c)
	{
		cell = c;
	}

	/// <summary> Checks if two species are the same: Similarity > 0.7f and the same amount of chromosomes.</summary>
	bool operator==(Animal& other)
	{
		return (GetSimilarity(*this, other) >= 0.7f) && (this->cell.GetChromosomes().size() == other.cell.GetChromosomes().size());
	}

	/// <summary> Sexual reproduction.</summary>
	Animal operator+(Animal& other)
	{
		return SexualReproduction(*this, other);
	}
	
	/// <summary> A-Sexual reproduction.</summary>
	Animal operator!()
	{
		return AsexualReproduction(*this);
	}
};