#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "outpost"

int outpost_func(struct gameState *state, int currentPlayer, int handPos);

int main () {

	struct gameState G, testG;
	int newCards = 0; 
	int currentPlayer = 0;
	int handPos = 0; 
	int seed = 1000;
	int expectedFlag = 1; 
	int numPlayers = 2;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	initializeGame(numPlayers, k, seed, &G);


	printf("Test 1: %s\n", TESTCARD); 
 	memcpy(&testG, &G, sizeof(struct gameState)); 
 	outpost_func(&testG, currentPlayer, handPos); 

 	printf("expected outpost flag to be set to %d, actually set to %d\n", expectedFlag, testG.outpostPlayed); 

 	printf("TESTS COMPLETED\n"); 

 }
