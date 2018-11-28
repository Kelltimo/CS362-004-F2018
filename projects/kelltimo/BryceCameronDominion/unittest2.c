#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main () {
	struct gameState G;
	struct gameState G2; 

	memcpy (&G2,&G, sizeof(struct gameState));
	int *a = 0; 
	int *b = 1; 	
	int r = compare(&a, &b);
	if(a < b) { 
		assert(r == -1);
		printf("%d correctly returns true\n", r);   
	}
	a = 1; 
	b = 0; 
	r = compare(&a, &b); 
	if(a > b) { 
		assert(r == 1); 
		printf("%d correctly returns true\n", r); 
	}
	a = 1; 
	b = 1; 
	r = compare(&a,&b); 
	if(a == b) {
		assert(r == 0);
		printf("%d correctly returns true\n", r);  
	}
	printf("TESTS COMPLETED");

	return 0; 

}
