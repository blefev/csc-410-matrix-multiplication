asll: ehashs ehashp mmomp mmpthread mmseq

clean:
	rm -f ehashs ehashp mmomp mmpthread mmseq

ehashs: ehashs.c hashfun.o
	gcc ehashs.c hashfun.o -o ehashs

hasht2: ehashp.c hashfun.o
	gcc ehashp.c hashfun.o -o hasht2

ehashp: ehashp.c hashfun.o
	gcc -fopenmp ehashp.c hashfun.o -o ehashp

mmomp: mmomp.c
	gcc -fopenmp mmomp.c -o mmomp

mmpthread: mmpthread.c
	gcc -lpthread mmpthread.c -o mmpthread

mmseq: mmseq.c
	gcc mmseq.c -o mmseq
