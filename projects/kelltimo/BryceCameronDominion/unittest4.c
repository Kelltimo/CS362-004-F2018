#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main () {
    int province = 1; 
    struct gameState G;
    struct gameState G2;
    int numPlayers = 2;  
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room}; 
    int seed = 1000; 
    memcpy(&G2, &G, sizeof(struct gameState)); 	
    initializeGame(numPlayers, k, seed, &G);
    int r = isGameOver(&G); 

    if(G.supplyCount[province] > 0) {
	printf("game is not over, returns %d\n", r); 
	province--; 

	} else if(G.supplyCount[province] == 0) { 
		printf("game is over, correctly returns %d\n", r); 
	}
	return 0; 
}  
 
 








