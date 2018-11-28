#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h> 
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

void villageRandom(int player, int numPlayers, int maxDeck, struct gameState g); 

	
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

	printf("Testing village card \n"); 
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

	villageRandom(player, numPlayers, maxDeck, g); 

	return 0; 
}


void villageRandom(int player, int numPlayers, int maxDeck, struct gameState g){
	int player2 = 1; 
	struct gameState testState; 				// our test state 

	memcpy(&testState, &g, sizeof(struct gameState)); 
	cardEffect(village, 0, 0, 0, &testState, 0, 0); 


	printf("Test - draw one card, discard one card for the hand count");
	if(testState.handCount[player] == g.handCount[player]) 
		printf("Passed - expected hand count %d, actual count %d\n", g.handCount[player], testState.handCount[player]); 
	else
		printf("Failed - expected hand count %d, actual count %d\n", g.handCount[player], testState.handCount[player]);  



	printf("Test - player is drawing from own pile\n"); 
	if(g.deckCount[player] == testState.deckCount[player]) 
		printf("Passed - expected %d deck size actual of %d\n", g.deckCount[player], testState.deckCount[player]); 
	else 
		printf("Failed - expected %d deck size actual of %d\n", g.deckCount[player], testState.deckCount[player]); 

	printf("Test - village card is added to played pile\n");
	if(testState.playedCardCount == 1)
		printf("Passed - expected played piled to be %d, actual of %d\n", 1, testState.playedCardCount); 
	else
		printf("Failed - expected played piled to be %d, actual of %d\n", 1, testState.playedCardCount); 	



}
