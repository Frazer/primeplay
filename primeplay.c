#include <stdio.h>
struct primes
{
	int prime;
	int iteratedUpTo;
};

int main(){
/*
	FILE *record;
	record=fopen("recordOfPlay.txt","wb");
 */

	int checkUpTo = 10000;
	int primePlay[10000] = {}; 
	for(int i=0;i<checkUpTo;++i) {
		primePlay[i] = 1+i;
	}
	int currentIteratedNumber;
	int previousIteratedNumber;

	for(int j = 0; j < checkUpTo; j++) {
	     printf("%d ", primePlay[j]);
	}
	printf("\n");
/*
	fwrite(ALL MY DATA,record);
	fclose(record);
*/
}
