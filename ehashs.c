//Hash Sequential
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 4
#define START_ASCII 'a'
#define END_ASCII 'z'

unsigned long hash(char *str);
int searchCharSet(char val, char charSet[]);
void printAnswer(char charSet[], char* hashedVal);
void findCombinations(char arr[], char ans[], int n, int k, char* hashedVal, int found);

int main(int argc, char **argv)
{
	char* hashedVal;
	int i;
	char charSet[62] =  { '0','1','2','3','4','5','6','7','8','9',
	'a','b','c','d','e','f','g','h','i','j' ,'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'A','B','C','D','E','F','G','H','I','J','C','L','M','N','O','P','Q','R','S','T','U','V','X','Y','Z' };

	if (argc != 2)
	{
		printf("Must include hashed number. Exiting.\n");
		return -1;
	}

	hashedVal = argv[1];

	printAnswer(charSet, hashedVal);

	return 0;
}

//n = length of char set
//k = LENGTH
void printAnswer(char charSet[], char* hashedVal)
{
	int i = 0, j;
	char ans[LENGTH] = "";

	findCombinations(charSet, ans, strlen(charSet), LENGTH, hashedVal, -1);
}

void findCombinations(char arr[], char ans[], int n, int k, char* hashedVal, int found)
{
	int i, j;
	char newAns[LENGTH];

	if (found == 0)
		return;

	if (k == 0)
	{
		if (hash(ans) == atol(hashedVal))
		{
			printf("%s\n", ans);
			found = 0;
		}
		return;
	}

	for (i = searchCharSet(START_ASCII, arr); i < searchCharSet(END_ASCII, arr) + 1; i++)
	{
		for (j = 0; j < LENGTH; j++)
			newAns[j] = ans[j];

		newAns[strlen(ans)] = arr[i];
		findCombinations(arr, newAns, n, k - 1, hashedVal, found);
	}
}

int searchCharSet(char val, char charSet[])
{
	int i; 

	for (i = 0; i < strlen(charSet); i++)
	{
		if (charSet[i] == val)
			return i;
	}

	return -1;
}