#include <stdio.h>
#define CHECKUPTO 10000


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

	int primePlay[CHECKUPTO] = {}; 
	for(int i=0;i<CHECKUPTO;++i) {
		primePlay[i] = 1+i;
	}
	int currentIteratedNumber;
	int previousIteratedNumber;

	for(int j = 0; j < CHECKUPTO; j++) {
	     printf("%d ", primePlay[j]);
	}
	printf("\n");
/*
	fwrite(ALL MY DATA,record);
	fclose(record);
*/
}
