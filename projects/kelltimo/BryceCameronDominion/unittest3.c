#include "dominion.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


int main () {
	
	int a = 1; 
	int  b = 0; 
	compare(&a, &b); 
	struct gameState G; 
	struct gameState G2; 

	memcpy(&G2, &G, sizeof(struct gameState));
	int r = shuffle(0,&G); 

	if(G.deckCount[0] > 0) { // if deckCount is greater than zero 
		assert(r != 0); 
		printf("r returns %d\n", r);
		qsort ((void*)(G.deck[0]), G.deckCount[0], sizeof(int), compare); 
		qsort ((void*)(G.deck[0]), G2.deckCount[0], sizeof(int), compare);  

 	} else 

		assert (r == -1); 
		printf("r correctly returns %d\n", r); 

	assert(memcmp(&G, &G2, sizeof(struct gameState)) == 0); 

	return 0; 
} 

