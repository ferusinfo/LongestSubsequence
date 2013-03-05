/* Longest Common Subsequences */
/* Zadanie PD1.2, wersja B */
/* @author Maciej Kołek <kontakt@ferus.info> */

/* libs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* variables */
char stringX[] = "ABA";
char stringY[] = "ACA";

/* max function */
int max(int a, int b)
{
	return a>b ? a : b;
}

/* recursive LCS */
int recursiveLCS(int i, int j)
{
	//LCS variable is just for testing purposes.
	int LCS;

	if (stringX[i] == '\0' || stringY[j] == '\0') LCS = 0;
	else if (stringX[i] == stringY[j]) LCS = 1 + recursiveLCS(i+1, j+1);
	else LCS = max(recursiveLCS(i+1, j), recursiveLCS(i, j+1));

	printf("Debug: looking for i = %i and j = %i, LCS = %i\n", i, j, LCS);
	return LCS;
}

/* main */
int main()
{
	//We start from first letters in both words.
	int longestLCS = recursiveLCS(0,0);
	printf("Najwiekszy LCS to: %i", longestLCS);

	return 0;
}
