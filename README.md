# ClassOfLife

This program uses a command-style interaction. These are all the valid commands:

Create:
create genome rna 'string'
create genome dna 'string' 'string'
create cell new 'string' 'string'
create cell genome 'index'
create animal cell 'index'
create dna 'string'

Show:
show all genome
show all cell
show all animal
show cell 'index'

Animal:
animal arep 'index'
animal srep 'index' 'index'
animal sim 'index' 'index'
animal same 'index' 'index'

Cell:
cell add 'index' new 'string' 'string'
cell add 'index' genome 'index'
cell destruct 'index'

Point:
point rna 'index' 'char' 'char' 'count'
point dna 'index' 'char' 'char' 'count'
point cell 'index' 'char' 'char' 'count' 'index'

Large:
large rna 'index' 'string' 'string'
large dna 'index' 'string' 'string'
large cell 'index' 'string' 'string' 'index' 'index'

Reverse:
reverse rna 'index' 'string'
reverse dna 'index' 'string'
reverse cell 'index' 'string' 'index'

Palindrome:
palindrome 'string'

Remove:
remove genome 'index'
remove cell 'index'
remove animal 'index'

Exit:
exit