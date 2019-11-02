//Hash Sequential
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define LENGTH 4
int FOUND = 0;

unsigned long hash(char *str);
void findPerms();
void findPermsWorker(char* str, unsigned int pos);

char* Hashed_Val;

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
	if (argc != 2)
	{
		printf("Must include hashed number. Exiting.\n");
		return -1;
	}

	Hashed_Val = argv[1];

	findPerms(Hashed_Val);

	return 0;
}

void findPermsWorker(char str[], unsigned int pos) {
	// we have made a full string, check if it is the one
	if (pos == LENGTH) {
		//printf("%s\n", str);
		if (atol(Hashed_Val) == hash(str)) {
			printf("%s\n", str);

			exit(0);
		}
		return;
	}

	for (unsigned short int j = 'a'; j < 'z'+3; j++) {
		str[pos] = xlt(j);
		findPermsWorker(str, pos+1);
	}
}

void findPerms()
{
	char str[LENGTH+1];
	str[LENGTH] = '\0';

	#pragma omp parallel for  private(str)
	for (unsigned short int i = 97; i < 125; i++) {
		str[0] = i;
		findPermsWorker(str, 1);
	}
}


