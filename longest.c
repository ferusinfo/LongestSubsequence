/* Longest Common Subsequences */
/* Zadanie PD1.2, wersja B */
/* @author Maciej Kołek <kontakt@ferus.info> */

/* libs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* variables */
char stringX[] = "ABABB";
char stringY[] = "ACABB";
int L[100][100];

/* max function */
int max(int a, int b)
{
	return a>=b ? a : b;
}

/* recursive LCS */
int recursiveLCS(int i, int j)
{
	if (L[i][j] < 0) {
		if (stringX[i] == '\0' || stringY[j] == '\0')L[ i][j] = 0;
		else if (stringX[i] == stringY[j]) L[i][j] = 1 + recursiveLCS(i+1, j+1);
		else L[i][j] = max(recursiveLCS(i+1, j), recursiveLCS(i, j+1));
	}
	printf("Debug: looking for i = %i and j = %i, LCS = %i\n", i, j, L[i][j]);
	return L[i][j];
}

/* main */
int main()
{
	int i,j;
	int m = (int)strlen(stringX);
	int n = (int)strlen(stringY);

	//Fill out our array with -1 statuses.
	for (i = 0; i <= m; i++)
	    for (j = 0; j <= n; j++)
		L[i][j] = -1;

	int longestLCS = recursiveLCS(0,0);
	printf("\nNajwiekszy LCS to: %i\n", longestLCS);
	return 0;
}
