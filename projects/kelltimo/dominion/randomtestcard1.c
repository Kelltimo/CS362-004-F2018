#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h> 
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

void smithyRandom(int player, int numPlayers, int maxDeck, struct gameState g); 

	
int main() {
	int i, j; 
	int numTests = 20000; 
	int numPlayers; 
	int maxDeck; 
	int position; 
	int player = 0; 
	struct gameState g; 
	int k[10] = {duchy, gardens, province, estate, tribute, mine, cutpurse, ambassador, great_hall, adventurer}; 
	int deckSize = 27; 

	srand(time(NULL)); 

	printf("Testing Smithy card \n"); 
	for(i = 0; i < numTests; i++) {
		numPlayers = (rand()%3)+2; 				// rand num of players
		initializeGame(numPlayers, k, 1000, &g); 
		maxDeck = rand()%deckSize;  		// rand deck size
		g.deckCount[player] = maxDeck; 
		g.handCount[player] = rand()%6; 			// rand starting hand
		for(j = 0; j < maxDeck; j++) {
			g.deck[player][j] = (rand()%17)+1; 		// randomize deck 
		}
	}

	printf("Inputs: \nDeck size: %d\n Hand Count: %d\n Players: %d\nPosition: %d\n", maxDeck, g.handCount[player], numPlayers, position); 

	smithyRandom(player, numPlayers, maxDeck, g); 

	return 0; 

}


void smithyRandom(int player, int numPlayers, int maxDeck, struct gameState g) {
	int player2 = 1; 
	struct gameState testState; 				// our test state 

	memcpy(&testState, &g, sizeof(struct gameState)); 
	cardEffect(smithy, 0, 0, 0, &testState, 0, 0); 

	printf("Test - play Smithy gain 3 cards\n"); 
	if(testState.handCount[player] == g.handCount[player] + 2) 			// gain 3 cards -1 smithy card = 2
		printf("Passed - expected hand count of %d, actual count %d\n", g.handCount[player] +2, testState.handCount[player]); 

	else 
		printf("Failed - expected hand count of %d, actual count %d\n", g.handCount[player] +2, testState.handCount[player]); 

	printf("Test - Other players deck will remain unchained\n"); 
	if(testState.deckCount[player2] == g.deckCount[player2]) 
		printf("Passed - deck size expected %d, actual size of %d\n", g.deckCount[player2], testState.deckCount[player2]); 
	else 
		printf("Failed - deck size expected %d, actual size of %d\n", g.deckCount[player2], testState.deckCount[player2]); 

	printf("Test - Other players hand count will remain unchained\n"); 
	if(testState.handCount[player2] == g.handCount[player2]) 
		printf("Passed - hand count size expected %d, actual size of %d\n", g.handCount[player2], testState.handCount[player2]); 
	else 
		printf("Failed - hand count size expected %d, actual size of %d\n", g.handCount[player2], testState.handCount[player2]); 

	printf("Test - Smithy card is in played pile after use\n"); 
	if(testState.playedCardCount == 1)								// count should always be - 3
		printf("Passed - expected increase in played of %d, actual of played %d\n", 1, testState.playedCardCount);
	else 
		printf("Failed - expected increase in played of %d, actual of played %d\n", 1, testState.playedCardCount);

	printf("Test - Test supply counts to make sure they aren't distributed\n");
	if(g.supplyCount[estate] != testState.supplyCount[estate]) 
		printf("Failed - expected %d estates, received %d\n", g.supplyCount[estate], testState.supplyCount[estate]); 
	if(g.supplyCount[duchy] != testState.supplyCount[duchy]) 
		printf("Failed - expected %d duchy, received %d\n", g.supplyCount[duchy], testState.supplyCount[duchy]); 
	if(g.supplyCount[province] != testState.supplyCount[province]) 
		printf("Failed - expected %d province, received %d\n", g.supplyCount[province], testState.supplyCount[province]); 
	if(g.supplyCount[curse] != testState.supplyCount[curse]) 
		printf("Failed - expected %d curses, received %d\n", g.supplyCount[curse], testState.supplyCount[curse]); 

	else
		printf("Passed - supply counts for victory and curses are the same\n"); 

	printf("Test - test supply counts for treasure that should have been given out\n"); 
	if(g.supplyCount[copper] != testState.supplyCount[copper])
		printf("Failed - copper doesn't match expected %d, actual %d\n", g.supplyCount[copper], testState.supplyCount[copper]); 
	if(g.supplyCount[silver] != testState.supplyCount[silver])
		printf("Failed - silver doesn't match expected %d, actual %d\n", g.supplyCount[silver], testState.supplyCount[silver]); 
	if(g.supplyCount[gold] != testState.supplyCount[gold])
		printf("Failed - gold doesn't match expected %d, actual %d\n", g.supplyCount[gold], testState.supplyCount[gold]); 

	else 
		printf("Passed - supply counts for treasure cards equal\n"); 

}
