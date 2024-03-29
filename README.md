## Matrix Multiplication with various parallelization techniques

Matrix multiplication implemented sequentially and in various paralellization methods for comparing performance.

# Authors
* Caitlin Rudolph
* Brendan Lefevre
* Teresa Bitterman
* Hunter Comer

## Building

To build all: `make all`

To clean all: `make clean`
	
## MMSEQ.C
* To Build: ``make mmseq``
* To Run  : `./mmseq`
* To Test : `./a.out maxrandom seed size`
* EX: `./a.out 25 7 12`
	

## MMPTHREAD.C
* To Build: `make mmpthread`
* To Run  : `./mmpthread`


## MMOMP.C
* To Build: `make mmomp`
* To Run  : `./mmomp`

## EHASHP.C
* To Build: `make hasht1`
* To Run  : `./hasht1 <hash>`

## EHASHS.C
* To Build: `make hasht2`
* To Run  : `./hasht2 {hash_number}`
