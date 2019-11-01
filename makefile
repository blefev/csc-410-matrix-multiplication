all: ehashs ehashp mmomp mmpthread mmseq

clean:
	rm -i ehashs ehashp mmomp mmpthread mmseq

ehashs: ehashs.c hashfun.o
	gcc ehashs.c hashfun.o -o ehashs

ehashp: ehashp.c hashfun.o
	gcc -openmp ehashp.c hashfun.o -o ehashp

mmomp: mmomp.c
	gcc -openmp mmomp.c -o mmomp

mmpthread: mmpthread.c
	gcc -pthread mmpthread.c -o mmpthread

mmseq: mmseq.c
	gcc mmseq.c -o mmseq
