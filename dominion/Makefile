CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g unittest1.c dominion.o rngs.o  $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS) 

outpostTest: outpostTest.c dominion.o rngs.o
	gcc -o outpostTest -g outpostTest.c dominion.o rngs.o $(CFLAGS)

villageTest: villageTest.c dominion.o rngs.o
	gcc -o villageTest -g villageTest.c dominion.o rngs.o $(CFLAGS)

smithyTest: smithyTest.c dominion.o rngs.o
	gcc -o smithyTest -g smithyTest.c dominion.o rngs.o $(CFLAGS)

adventurerTest: adventurerTest.c dominion.o rngs.o
	gcc -o adventurerTest -g adventurerTest.c dominion.o rngs.o $(CFLAGS)  

default: unittestresults.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c outpostTest.c villageTest.c smithyTest.c adventurerTest.c dominion.c rngs.c 

	echo "Result for running tests:" > unittestresults.out 
	echo "unittest1.c:" >> unittestresults.out
	gcc -o unittest1 unittest1.c dominion.c rngs.c $(CFLAGS) 
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c dominion.c rngs.c $(CFLAGS) 
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

	echo "unittest3.c:" >> unittestresults.out
	gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS) 
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

		echo "unittest4.c:" >> unittestresults.out
	gcc -o unittest4 unittest4.c dominion.c rngs.c $(CFLAGS) 
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

	echo "outpostTest.c:" >> unittestresults.out
	gcc -o outpostTest outpostTest.c dominion.c rngs.c $(CFLAGS) 
	./outpostTest >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

	echo "villageTest.c:" >> unittestresults.out
	gcc -o villageTest villageTest.c dominion.c rngs.c $(CFLAGS) 
	./villageTest >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

	echo "smithyTest.c:" >> unittestresults.out
	gcc -o smithyTest smithyTest.c dominion.c rngs.c $(CFLAGS) 
	./smithyTest >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

	echo "adventurerTest.c:" >> unittestresults.out
	gcc -o adventurerTest adventurerTest.c dominion.c rngs.c $(CFLAGS) 
	./adventurerTest >> unittestresults.out
	gcov dominion.c >> unittestresults.out 

clean: 
	rm unittestresults.out

cleanall: 
	rm unittestresults.out unittest1 unittest2 unittest3 unittest4 outpostTest villageTest smithyTest adventurerTest *.gcda *.gcno *.gcov



testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

	


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

