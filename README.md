# ClassOfLife

This program uses a command-style interaction. These are all the valid commands:
> **_Or jump to:_ [Sample Input](#sample-input)**


## Commands:

### Create:
Create a genome object using RNA or DNA:

```
create genome rna 'string' 
```
``` 
create genome dna 'string' 'string' 
```

Create a cell object from a new DNA:
``` 
create cell new 'string' 'string' 
```

Create a cell object from an existing genome:
``` 
create cell genome 'index' 
```

Create an animal object from an existing cell:
``` 
create animal cell 'index' 
```
Create a DNA string from an input string:
``` 
create dna 'string' 
```
>Only shows the complement of the input string.

>Note: This does not have any effect on any part of the program.

### Show:

Show all created genomes:
```
show all genome
```

Show all created cells:
``` 
show all cell
```

Show all created animals:
``` 
show all animal
```

Show all genomes in a created cell:
``` 
show cell 'index'
```

### Cell:

Add a new chromosome(genome) to a cell:
``` 
cell add 'index' new 'string' 'string'
```

Add a new chromosome(genome) to a cell from an existing genome:
``` 
cell add 'index' genome 'index'
```

Destruct a created cell:
``` 
cell destruct 'index'
``` 

### Animal:

A-sexual reproduction of a created animal:
```
animal arep 'index'
```
>Note: This creates another animal which can be seen using the 'show' command.

Sexual reproduction of two created animals:
``` 
animal srep 'index' 'index'
```
>Note: This creates another animal which can be seen using the 'show' command.

Get the similarity percentage of two created animals:
``` 
animal sim 'index' 'index'
```

Check if two created animals are of the same species:
``` 
animal same 'index' 'index'
```

### Point:

Point mutation on the RNA/DNA of a created genome:
``` 
point rna 'index' 'char' 'char' 'count'
```
``` 
point dna 'index' 'char' 'char' 'count'
```

Point mutation on the DNA of a chromosome(genome) in a created cell:
``` 
point cell 'index' 'char' 'char' 'count' 'index'
``` 

### Large:

Large mutation on the RNA/DNA of a created genome:
```
large rna 'index' 'string' 'string'
```
``` 
large dna 'index' 'string' 'string'
```

Large mutation on the DNA of two chromosomes(genomes) in a created cell:
``` 
large cell 'index' 'string' 'string' 'index' 'index'
```

### Reverse:

Reverse mutation on the RNA/DNA of a created genome:
```
reverse rna 'index' 'string'
```
``` 
reverse dna 'index' 'string'
```

Reverse mutation on the DNA of a chromosome(genome) in a created cell:
``` 
reverse cell 'index' 'string' 'index'
```

### Palindrome:

Get all complement-palindromes of an input string:
```
palindrome 'string'
```

### Remove:

Remove an index of the list of genomes/cells/animals:
```
remove genome 'index'
```
``` 
remove cell 'index'
```
``` 
remove animal 'index'
```

### Exit:

Exit the program:
```
exit
```

### Sample Input:

Sample creation of objects:
```
create genome rna AATTAAGCTC
create genome dna AATTAAGCTC TTAATTCGAG
create genome dna ATTGCGATCG TAACGCTAGC
show all genome

create cell genome 1
create cell genome 2
show all cell

create animal cell 0
create animal cell 0
create animal cell 1
show all animal

```

Sample use of the created objects:
```
animal sim 0 1
animal same 0 1
animal arep 0
animal srep 0 2
animal sim 0 4
animal same 0 4
remove animal 1
show all animal

```
