GROUP 3
	Caitlin Rudolph
	Brendan Lefevre
	Teresa Bitterman
	Hunter Comer
	
MMSEQ.C
	To Build: gcc mmseq.c -o mmseq
	To Run  : ./mmseq
	To Test : ./a.out maxrandom seed size
		  EX: ./a.out 25 7 12
	

MMPTHREAD.C
	To Build: gcc mmpthread.c -lpthread -o mmpthread
	To Run  : ./mmpthread
	To Test : time ./a.out


MMOMP.C
	To Build: gcc mmomp.c -fopenmp -o mmomp
	To Run  : ./mmomp
	To Test :


EHASHS.C - you must go into the code and add the length of the word at the start
	   and end characters used in the hash. These are defined at the top of the
	   program
	To Build: gcc ehashs.c hashfun.o -o ehashs
	To Run  : ./ehash {hash_number}
	To Test :