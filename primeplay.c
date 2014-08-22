#include <stdio.h>
#include <math.h>
#define CHECKUPTO 1000000


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

	int currentPrime = 1;
	int maxPrimeIteror = sqrt(CHECKUPTO)-6;
	while(currentPrime< maxPrimeIteror){
		currentPrime = primePlay[currentPrime];
		int startingPrimeSquared = currentPrime*currentPrime;

		/*
		 * jumps to prime^2
		 * and needs to step back to find which place points to it
		 *
		 */
		int placePointingAtPrimeSquared = 1; 
		for(int j = startingPrimeSquared-1; j >1 ; j--) {
		  if (primePlay[j]){
		     placePointingAtPrimeSquared = j;
		     break;
		  }
		}

		PRIMEPLAYITERATOR cp = {currentPrime,startingPrimeSquared,placePointingAtPrimeSquared};
		
		printf("prime:%d :",cp.prime);
		int  counter = 0;
		int  numberOfCountersPrinted = 0;
		for(; cp.currentIteratedNumber < CHECKUPTO; ) {     /*   will check up to previous iterator */
			if (cp.currentIteratedNumber%cp.prime){
			/*
			 * not a multiple, so can skip and move on
			 *
			 */
				cp.previousIteratedNumber = cp.currentIteratedNumber;
				cp.currentIteratedNumber = primePlay[cp.currentIteratedNumber];
				counter++;

			}else{
			/*
			 * is a multiple, so should be knocked out
			 * so previous number needs to point to where this is pointing
			 * and set this to 0.
			 */
				
				if (numberOfCountersPrinted<19){
					printf("%d, ",counter+1); 
			/*		printf("%d[%d], ",counter+1,cp.currentIteratedNumber);  */
					counter=0;
					numberOfCountersPrinted++;
				}
				primePlay[cp.previousIteratedNumber] = primePlay[cp.currentIteratedNumber];
				primePlay[cp.currentIteratedNumber]=0;
				cp.currentIteratedNumber = primePlay[cp.previousIteratedNumber]; 

			}

		}
		printf("\n");
		
	}		
	int displayRowCounter = 0;
	for(int j = 2; j < CHECKUPTO; ) {
	  
	   printf("   %d",j);
	  
		displayRowCounter++;
		if (displayRowCounter==10){
			printf("\n");
			displayRowCounter=0;
		}
	  
	  j = primePlay[j];
	}
	printf("\n");
/*
	fwrite(ALL MY DATA,record);
	fclose(record);
*/
}
