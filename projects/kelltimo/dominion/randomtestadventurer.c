#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h> 
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

void randomTest(int player, int numPlayers, int maxDeck, int position, struct gameState g); 

	
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

	printf("Testing Adventurer card \n"); 
	for(i = 0; i < numTests; i++) {
		numPlayers = (rand()%3)+2; 				// rand num of players
		initializeGame(numPlayers, k, 1000, &g); 
		maxDeck = rand()%deckSize + 1;  		// rand deck size
		g.deckCount[player] = maxDeck; 
		g.handCount[player] = rand()%6 + 1; 			// rand starting hand
		position = rand()%g.handCount[player] + 1; 
		g.hand[player][position] = adventurer; 	
		for(j = 0; j < maxDeck; j++) {
			if(j == position) 
				continue; 
			g.deck[player][j] = rand()%17+1; 
		}
	}

	printf("Inputs: \nDeck size: %d\n Hand Count: %d\n Players: %d\nPosition: %d\n", maxDeck, g.handCount[player], numPlayers, position); 

	randomTest(player, numPlayers, maxDeck, position, g); 

	return 0; 

}

void randomTest(int player, int numPlayers, int maxDeck, int position, struct gameState g) {
	int j; 
	int player2 = 1; 
	int preCount; 
	int amount = 0; 
	int preAmount; 
	struct gameState testState; 

	printf("\nTest - Play adventurer card until two coins are drawn\n"); 
	memcpy(&testState, &g, sizeof(struct gameState)); 
	preCount = g.coins; 
	amount = 0; 
	printf("Coin cards in hand originally - "); 
	for(j = 0; j < testState.handCount[player]; j++) {
		if(testState.hand[player][j] == copper) {
			printf("copper, "); 
			preAmount += 1; 
			preCount++; 
		}
		if(testState.hand[player][j] == silver) {
			printf("silver, "); 
			preAmount += 2; 			// increment by silver val
			preCount++; 
		}
		if(testState.hand[player][j] == gold){
			printf("gold, "); 
			preAmount += 3; 
			preCount++; 
		}
		printf("\n"); 
	}
	cardEffect(adventurer, 0, 0, 0, &testState, 0, 0); 
	printf("Cards found: "); 
	for(j = 0; j < testState.handCount[player]; j++) {
		if(testState.hand[player][j] == copper){
			printf("copper, "); 
			amount+= 1; 				// increment by copper val
		}
		if(testState.hand[player][j] == silver){
			printf("silver, "); 
			amount+= 2; 				// increment by silver val
		}
		if(testState.hand[player][j] == gold){
			printf("gold, "); 
			amount+= 3; 				// increment by gold val
		}
	}

	printf("\n"); 
	if(amount == testState.coins) 		// should only pull two coin cards
		printf("Passed. Expected %d finished amount: %d\n", amount, testState.coins); 
	else
		printf("Failed. Expected: %d received: %d\n", amount, testState.coins); 

	printf("Test - gained proper amount of cards: \n"); 
	if(testState.handCount[player2] == g.handCount[player2]) 
		printf("Passed - hand size start: %d hand size finish: %d\n", g.handCount[player2], testState.handCount[player2]); 
	else 
		printf("Failed - hand size start: %d hand size finish: %d\n", g.handCount[player2], testState.handCount[player2]);

	printf("Test - proper amount of cards should be in the deck\n"); 			// no extra cards should be removed
	if(g.deckCount[player] - testState.discardCount[player] - 2 == testState.deckCount[player])
		printf("Passed - expected deck: %d, deck actual: %d\n", g.deckCount[player] - testState.discardCount[player] - 2, testState.deckCount[player]); 
	else
		printf("Failed - expected deck: %d, deck actual: %d\n", g.deckCount[player] - testState.discardCount[player] - 2, testState.deckCount[player]);

	printf("Test - adventurer card added to played pile after using\n"); 
	if(testState.playedCardCount = 1) 
		printf("Passed - expected played pile to increase by %d, actually increased by %d\n", 1, testState.playedCardCount); 
	else 
		printf("Failed - expected played pile to increase by %d, actually increased by %d\n", 1, testState.playedCardCount);

	printf("Test - test supply counts for treasures were given out\n"); 
	if(g.supplyCount[copper] != testState.supplyCount[copper])
		printf("Failed - mismatch of copper, expected %d, received %d\n", g.supplyCount[copper], testState.supplyCount[copper]);
	if(g.supplyCount[silver] != testState.supplyCount[silver])
		printf("Failed - mismatch of copper, expected %d, received %d\n", g.supplyCount[silver], testState.supplyCount[silver]);
	if(g.supplyCount[gold] != testState.supplyCount[gold])
		printf("Failed - mismatch of copper, expected %d, received %d\n", g.supplyCount[gold], testState.supplyCount[gold]);

	else 
		printf("Passed - all supply counts passed\n"); 

	printf("Test - test supply counts for points match\n"); 
	if(g.supplyCount[estate] != testState.supplyCount[estate])
		printf("Failed, expected %d estates, actual %d\n", g.supplyCount[estate], testState.supplyCount[estate]); 
	if(g.supplyCount[duchy] != testState.supplyCount[duchy])
		printf("Failed, expected %d duchy, actual %d\n", g.supplyCount[duchy], testState.supplyCount[duchy]); 
	if(g.supplyCount[province] != testState.supplyCount[province])
		printf("Failed, expected %d provinces, actual %d\n", g.supplyCount[province], testState.supplyCount[province]); 
	if(g.supplyCount[curse] != testState.supplyCount[curse])
		printf("Failed, expected %d curses, actual %d\n", g.supplyCount[curse], testState.supplyCount[curse]);

	else 
		printf("Passed - supply counts for victory cards and curses equal\n"); 
}
