#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int main () {

  int r;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;
  
  r = initializeGame(2, k, 1, &G);  // initalize game 

  printf ("initializeGame(2, k, 1, &G) = %d\n", r);   // initialize game with 2 players
  assert(r == 0);

  r = supplyCount(great_hall, &G); 
  printf("supplyCount(great_hall, &G) = %d\n", r); 
  assert(r == 8); // if two players supply of adventurers should be 8

  printf("TEST COMPLETED");

  return 0; 

} 
