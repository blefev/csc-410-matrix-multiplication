//Hash Sequential
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define LENGTH 4
int FOUND = 0;

unsigned long hash(char *str);
void findPermutations(char* hashedVal);

// translate char
char xlt(char c) {
	if (c < 123) return c;
	switch (c) {
		case 123: return '@';
		case 124: return '*';
		case 125: return '&';
	}
	return c;
}


int main(int argc, char **argv)
{
	char* hashedVal;

	if (argc != 2)
	{
		printf("Must include hashed number. Exiting.\n");
		return -1;
	}

	hashedVal = argv[1];

	findPermutations(hashedVal);

	return 0;
}

void findPermutations(char* hashedVal)
{
	char ans[LENGTH+1];
	//ans[LENGTH] = '\0';

	#pragma omp parallel for num_threads(4) schedule(static) private(ans)
	for (unsigned short int i = 97; i < 125; i++) {
		for (unsigned short int j = 'a'; j < 'z'+3; j++) {
			for (unsigned short int k = 'a'; k < 'z'+3; k++) {
				for (unsigned short int l = 'a'; l < 'z'+3; l++) {
					sprintf(ans, "%c%c%c%c",xlt(i),xlt(j),xlt(k),xlt(l));

					printf("%s\n", ans);

					if (atol(hashedVal) == hash(ans)) {
						printf("found answer!: %s\n", ans);

						exit(0);
					}
				}
			}
		}
	}
}


