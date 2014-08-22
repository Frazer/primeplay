#include <stdio.h>
#define CHECKUPTO 10000


typedef struct PRIMEPLAYITERATOR
{
	int prime;
	int currentIteratedNumber ;
	int previousIteratedNumber ;
} PRIMEPLAYITERATOR;

int main(){
/*
	FILE *record;
	record=fopen("recordOfPlay.txt","wb");
 */

	int primePlay[CHECKUPTO] = {}; 
	for(int i=0;i<CHECKUPTO;++i) {
		primePlay[i] = 1+i;
	}
/*
 *
 * at this point each position in the array points to the next position
 * by the algorithms process, this is equivalent to running through with 
 * a 'prime' of 1
 *
 */
	int currentPrime = 2;
	PRIMEPLAYITERATOR cp = {currentPrime,currentPrime+1,currentPrime};	
	
	for(; cp.currentIteratedNumber < CHECKUPTO; ) {     /*   will check up to previous iterator */
		if (cp.currentIteratedNumber%cp.prime){
		/*
		 * not a multiple, so can skip and move on
		 *
		 */
			cp.previousIteratedNumber = cp.currentIteratedNumber;
			cp.currentIteratedNumber = primePlay[cp.currentIteratedNumber];

		}else{
		/*
		 * is a multiple, so should be knocked out
		 * so previous number needs to point to where this is pointing
		 * and set this to 0.
		 */
			primePlay[cp.previousIteratedNumber] = primePlay[cp.currentIteratedNumber];
			primePlay[cp.currentIteratedNumber]=0;
			cp.currentIteratedNumber = primePlay[cp.previousIteratedNumber]; 
		}

	}

	
	
	
	for(int j = 1; j < CHECKUPTO; j++) {
	  if (primePlay[j]){
	     printf("%d ",j);
	  }
	}
	printf("\n");
/*
	fwrite(ALL MY DATA,record);
	fclose(record);
*/
}
