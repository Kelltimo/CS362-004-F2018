#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

int main () {
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};
	struct gameState G, testG;
	int seed = 1000;
	int newCards = 3; 
	int currentPlayer = 0;
	int handPos = 0; 
	int numPlayers = 2;
	int expectedTreasure = 1;
	int thisPlayer = 0; 
	int discarded = 1; 
	int drawnTreasure = 0; 
	int cardDrawn = 0;  //set to copper 

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("Test 1:%s\n", TESTCARD); 

	memcpy(&testG, &G, sizeof(struct gameState)); 
	adventurer_func(drawnTreasure, &testG, currentPlayer, cardDrawn); 
	if(cardDrawn == 0) {
		drawnTreasure++; 
	}

	printf("expected %d coppers to be drawn, actual of %d\n", expectedTreasure, drawnTreasure); 
	printf("expected %d cards to be in hand, actual of %d\n", testG.handCount[thisPlayer] - 1, testG.handCount[thisPlayer]); 

	expectedTreasure++; 
	if(cardDrawn == 0) {
		drawnTreasure++;
	}

	printf("expected %d coppers to be drawn, actual of %d\n", expectedTreasure, drawnTreasure); 
	printf("expected %d cards to be in hand, actual of %d\n", testG.handCount[thisPlayer] - 1, testG.handCount[thisPlayer]); 

	memcpy(&testG, &G, sizeof(struct gameState));
	drawnTreasure = 0;
	expectedTreasure = 1;  
	cardDrawn = 3; // change to silver
	adventurer_func(drawnTreasure, &testG, currentPlayer, cardDrawn); 
	if(cardDrawn == 3) {
		drawnTreasure++; 
	}

	printf("expected %d silvers to be drawn, actual of %d\n", expectedTreasure, drawnTreasure); 
	printf("expected %d cards to be in hand, actual of %d\n", testG.handCount[thisPlayer] - 1, G.handCount[thisPlayer]); 

	expectedTreasure++; 
	if(cardDrawn == 3) {
		drawnTreasure++;
	}

	printf("expected %d silvers to be drawn, actual of %d\n", expectedTreasure, drawnTreasure); 
	printf("expected %d cards to be in hand, actual of %d\n", testG.handCount[thisPlayer] - 1, G.handCount[thisPlayer]); 


return 0; 


}





