// Class of Life.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include "Genome.h"
#include "Cell.h"
#include "Animal.h"
using namespace std;

std::vector<Genome> genomeList = std::vector<Genome>();
std::vector<Cell> cellList = std::vector<Cell>();
std::vector<Animal> animalList = std::vector<Animal>();

template <typename T>
void Print(std::vector<T> v)
{
    return;
}

template <> void Print<Genome>(std::vector<Genome> genes)
{
    cout << endl;

    for (int i = 0; i < genes.size(); i++)
    {
        cout << i << ". " << "RNA: " << genes[i].GetRNA() << endl;
        cout << "   " << "DNA: " << genes[i].GetDNA().first << endl;
        cout << "   " << "DNA: " << genes[i].GetDNA().second << endl;

        cout << endl;
    }

    cout << endl;
}

template <> void Print<Cell>(std::vector<Cell> cells)
{
    cout << endl;

    for (int i = 0; i < cells.size(); i++)
    {
        cout << i << ". Chromosomes: " << cells[i].GetChromosomes().size() << endl;
    }

    cout << endl;
}

template <> void Print<Animal>(std::vector<Animal> animals)
{
    cout << endl;

    for (int i = 0; i < animals.size(); i++)
    {
        cout << i << ". Animal Cell Chromosomes: " << animals[i].GetCell().GetChromosomes().size() << endl;
    }

    cout << endl;
}


void Create()
{
    string maincmd = "";
    cin >> maincmd;

    if (maincmd == "genome")
    {
        string subcmd = "";
        cin >> subcmd;

        Genome gen;

        if (subcmd == "rna")
        {
            string input = "";
            cin >> input;

            gen = Genome(input);
        }
        else if (subcmd == "dna")
        {
            string first = "";
            cin >> first;

            string second = "";
            cin >> second;

            gen = Genome(first, second);
        }

        genomeList.push_back(gen);
    }
    else if (maincmd == "cell")
    {
        string first = "";
        cin >> first;

        string second = "";
        cin >> second;

        Cell cell = Cell(Genome(first, second));

        cellList.push_back(cell);
    }
    else if (maincmd == "animal")
    {
        string subcmd = "";
        cin >> subcmd;

        Cell cell;

        if (subcmd == "cell")
        {
            int index = 0;
            cin >> index;

            cell = cellList[index];
        }

        animalList.push_back(Animal(cell));
    }
    else if (maincmd == "dna")
    {
        cout << endl;

        string input = "";
        cin >> input;

        cout << "DNA is: " << input << endl;
        cout << "        " << Genome::CreateDNA(input) << endl;

        cout << endl;
    }
}

void Show()
{
    string maincmd = "";
    cin >> maincmd;

    if (maincmd == "all")
    {
        string subcmd = "";
        cin >> subcmd;

        if (subcmd == "genome")
        {
            Print(genomeList);
        }
        else if (subcmd == "cell")
        {
            Print(cellList);
        }
        else if (subcmd == "animal")
        {
            Print(animalList);
        }
    }
    else if (maincmd == "cell")
    {
        int index = 0;
        cin >> index;

        Print(cellList[index].GetChromosomes());
    }
}

void AnimalCommands()
{
    string maincmd = "";
    cin >> maincmd;

    if (maincmd == "arep")
    {
        int index = 0;
        cin >> index;

        animalList.push_back(!animalList[index]);
    }
    else if (maincmd == "srep")
    {
        int indexA = 0;
        cin >> indexA;

        int indexB = 0;
        cin >> indexB;

        animalList.push_back(animalList[indexA] + animalList[indexB]);
    }
    else if (maincmd == "sim")
    {
        int indexA = 0;
        cin >> indexA;

        int indexB = 0;
        cin >> indexB;

        cout << endl;
        cout << "Similarity is: " << (animalList[indexA] % animalList[indexB]) * 100 << "%." << endl;
        cout << endl;

    }
    else if (maincmd == "same")
    {
        int indexA = 0;
        cin >> indexA;

        int indexB = 0;
        cin >> indexB;

        string ans = (animalList[indexA] == animalList[indexB]) ? "Yes." : "No.";

        cout << endl;
        cout << "Are these animals the same? " << ans << endl;
        cout << endl;

    }
}

void CellCommands()
{
    string maincmd = "";
    cin >> maincmd;

    if (maincmd == "add")
    {
        int index = 0;
        cin >> index;

        string subcmd = "";
        cin >> subcmd;

        if (subcmd == "new")
        {
            string first = "";
            cin >> first;

            string second = "";
            cin >> second;

            cellList[index].Chromosomes().push_back(Genome(first, second));
        }
        else if (subcmd == "genome")
        {
            int genomeIndex = 0;
            cin >> genomeIndex;

            cellList[index].Chromosomes().push_back(genomeList[genomeIndex]);
        }
    }
    else if (maincmd == "destruct")
    {
        int index = 0;
        cin >> index;

        bool destruct = cellList[index].CellDestruction();
        
        if (destruct)
            cellList.erase(cellList.begin() + index);

        string ans = (destruct) ? "The corrupted cell was deleted." : "The cell is not corrupted.";

        cout << ans << endl;
    }
}

void Point()
{
    string maincmd = "";
    cin >> maincmd;

    int index = 0;
    cin >> index;

    string a = "";
    cin >> a;

    string b = "";
    cin >> b;

    int count = 0;
    cin >> count;

    if (maincmd == "cell")
    {
        int i = 0;
        cin >> i;

        cellList[index].PointMutation(a[0], b[0], count, i);
    }
    else if (maincmd == "rna")
    {
        genomeList[index].PointMutationRNA(a[0], b[0], count);
    }
    else if (maincmd == "dna")
    {
        genomeList[index].PointMutationDNA(a[0], b[0], count);
    }
}

void Large()
{
    string maincmd = "";
    cin >> maincmd;

    int index = 0;
    cin >> index;

    string a = "";
    cin >> a;

    string b = "";
    cin >> b;

    if (maincmd == "cell")
    {
        int n = 0;
        cin >> n;

        int m = 0;
        cin >> m;

        cellList[index].LargeMutation(a, n, b, m);
    }
    else if (maincmd == "rna")
    {
        genomeList[index].LargeMutationRNA(a, b);
    }
    else if (maincmd == "dna")
    {
        genomeList[index].LargeMutationDNA(a, b);
    }
}

void Reverse()
{
    string maincmd = "";
    cin >> maincmd;

    int index = 0;
    cin >> index;

    string a = "";
    cin >> a;

    if (maincmd == "cell")
    {
        int i = 0;
        cin >> i;

        cellList[index].ReverseMutation(a, i);
    }
    else if (maincmd == "rna")
    {
        genomeList[index].ReverseMutationRNA(a);
    }
    else if (maincmd == "dna")
    {
        genomeList[index].ReverseMutationDNA(a);
    }
}

void Compliment()
{
    string input = "";
    cin >> input;

    Cell::FindComplimentPalindromes(input);
}

void Remove()
{
    string maincmd = "";
    cin >> maincmd;

    int index = 0;
    cin >> index;

    if (maincmd == "genome")
    {
        genomeList.erase(genomeList.begin() + index);
    }
    else if (maincmd == "cell")
    {
        cellList.erase(cellList.begin() + index);
    }
    else if (maincmd == "animal")
    {
        animalList.erase(animalList.begin() + index);
    }
}

int main()
{
    cout << "Check the ReadMe.Md file for instructions on how to use the commands." << endl;

    while (true)
    {
        string maincmd = "";
        cin >> maincmd;

        try
        {
            if (maincmd == "create") Create();
            else if (maincmd == "show") Show();
            else if (maincmd == "animal") AnimalCommands();
            else if (maincmd == "cell") CellCommands();
            else if (maincmd == "point") Point();
            else if (maincmd == "large") Large();
            else if (maincmd == "reverse") Reverse();
            else if (maincmd == "compliment") Compliment();
            else if (maincmd == "remove") Remove();
            else if (maincmd == "exit") return 0;
        }
        catch(...)
        {
            continue;
        }
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
