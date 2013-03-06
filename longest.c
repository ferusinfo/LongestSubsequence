/* Longest Common Subsequences */
/* Zadanie PD1.2, wersja B */
/* @author Maciej Kołek <kontakt@ferus.info> */

/* libs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* defines */
#define ACROSS 4
#define UP 2
#define LEFT 3
#define UNDEFINED 0

/* variables */
char stringX[] = "ABABB";
char stringY[] = "ACABB";
int L[100][100];
int B[100][100];
char newWord[30];

/* max function */
int max(int a, int b)
{
	return a>=b ? a : b;
}

/* recursive LCS */
int recursiveLCS(int i, int j)
{
	if (L[i][j] < 0) {
		if (stringX[i] == '\0' || stringY[j] == '\0') {
			L[i][j] = 0;
		}
		else if (stringX[i] == stringY[j]) {
			L[i][j] = 1 + recursiveLCS(i+1, j+1);
			B[i+1][j+1] = ACROSS;
		}
		else {
			int a = recursiveLCS(i+1, j);
			int b = recursiveLCS(i, j+1);

			if (a>=b) {
				L[i][j] = a;
				B[i+1][j+1] = UP;
			}
			else {
				L[i][j] = b;
				B[i+1][j+1] = LEFT;
			}
		}
	}
	//printf("Debug: looking for i = %i and j = %i, LCS = %i\n", i, j, L[i][j]);
	return L[i][j];
}

char yesno(int que)
{
	return que == 1 ?  'Y' : 'N';
}

void recursivePrinter(int i, int j)
{
	int wyswietl = 0;

	if (i > 0 && j > 0)
	{
		if (ACROSS == B[i][j]) {
			wyswietl = 1;
			recursivePrinter(i-1, j-1);

			//Concatinate string here.
			strncat(newWord, &stringX[i-1], 1);
			printf("Aktualny stan: %s Dodaje: %c\n", newWord, stringX[i-1]);

		}
		else {
			if (UP == B[i][j]) {
				recursivePrinter(i-1, j);
			}
			else {
				recursivePrinter(i, j-1);
			}
		}
		//Debug
		printf("Debug: i = %i, j = %i, B[i][j] = %i, Letter = %c, Wyswietl: %c\n", i, j, B[i][j], stringX[i-1], yesno(wyswietl));
	}
}

/* Print LCS table */
void debugPrintTable(int m, int n)
{
	int i,j;
	char temp[30];
	for (i=1; i<=m; i++) {
		for(j=1; j<=n; j++) {
			switch(B[i][j])
			{
				case ACROSS:
					printf(" \\ [%i][%i]", i,j);
				break;

				case UP:
					printf(" | [%i][%i]", i,j);
				break;

				case LEFT:
					printf(" < [%i][%i]", i,j);
				break;
				default:
					printf(" 0 [%i][%i]", i,j);
				break;
			}
		}
		printf("\n");
	}
}

/* main */
int main()
{
	int i,j;
	int m = (int)strlen(stringX);
	int n = (int)strlen(stringY);

	//Print length
	printf("StringX.length: %i | StringY.length: %i\n", m, n);

	//Fill out our array with -1 statuses.
	for (i = 0; i <= m; i++)
	    for (j = 0; j <= n; j++)
		L[i][j] = -1;

	int longestLCS = recursiveLCS(0,0);
	printf("\nNajwiekszy LCS to: %i\n", longestLCS);
	debugPrintTable(m,n);

	recursivePrinter(m,n);
	printf("\n\n %s \n\n", newWord);
	return 0;
}
