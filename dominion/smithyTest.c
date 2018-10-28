#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

int main () {
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	struct gameState G, testG;
	int seed = 1000;
	int newCards = 3; 
	int currentPlayer = 0;
	int handPos = 0; 
	int numPlayers = 2;
	int expectedCards = 3;
	int thisPlayer = 0; 
	int discarded = 1; 

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

 	printf("Test 1: %s\n", TESTCARD); 
 	memcpy(&testG, &G, sizeof(struct gameState)); 
 	smithy_func(currentPlayer, &testG, handPos);
 	printf("expected %d cards, received %d cards\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded); 
	printf("expected %d cards to be discarded, discarded %d\n", discarded, G.handCount[thisPlayer]-newCards); 

	printf("Test 2: %s\n", TESTCARD); 
	memcpy(&testG, &G, sizeof(struct gameState)); 
	smithy_func(currentPlayer, &testG, handPos); 
	printf("discared cards should be %d, actual was %d\n", testG.handCount[thisPlayer] - testG.handCount[thisPlayer] + discarded, discarded);  


	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;


}
