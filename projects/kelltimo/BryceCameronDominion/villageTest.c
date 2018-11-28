#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main () {
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	struct gameState G, testG;
	int newCards = 0; 
	int currentPlayer = 0;
	int handPos = 0; 
	int expectedNumActions  = 2;
	int numPlayers = 2;
	int seed = 1000;
	int numActions = 0;  

	initializeGame(numPlayers, k, seed, &G);

 	printf("Test 1: %s\n", TESTCARD); 
 	memcpy(&testG, &G, sizeof(struct gameState)); 
 	useVillage(currentPlayer, &testG, handPos); 
	
	if(G.numActions == expectedNumActions) {
 	printf("expected %d cards, received %d cards\n", expectedNumActions, testG.numActions); 

	}else  {
	printf("Test failed\n"); 
	}


 	printf("Tests completed\n"); 

return 0;

}

