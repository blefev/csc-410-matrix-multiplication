//Hash Sequential
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 4
#define START_ASCII 'a'
#define END_ASCII 't'
int FOUND = 0;

unsigned long hash(char *str);
void findCombinations(char ans[], int k, char* hashedVal);

int main(int argc, char **argv)
{
	char* hashedVal;
	int i;
	char ans[LENGTH + 1] = "";

	if (argc != 2)
	{
		printf("Must include hashed number. Exiting.\n");
		return -1;
	}

	hashedVal = argv[1];

	findCombinations(ans, LENGTH, hashedVal);

	return 0;
}

void findCombinations(char ans[], int k, char* hashedVal)
{
	char i;
	int j;
	char newAns[LENGTH + 1];

	if (FOUND == 1)
		return;

	if (k == 0)
	{
		if (hash(ans) == atol(hashedVal))
		{
			printf("%s\n", ans);
			FOUND = 1;
		}

		return;
	}

	for (i = START_ASCII; i <= END_ASCII; i++)
	{
		for (j = 0; j < LENGTH + 1; j++)
			newAns[j] = ans[j];

		newAns[strlen(ans)] = i;
		findCombinations(newAns, k - 1, hashedVal);
	}
}
