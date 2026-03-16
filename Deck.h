#include "Card.h"

#define DECK_SIZE 44

typedef struct _deck
{
    Card* cards;
    int size;
}_Deck;

typedef _Deck* Deck;

Deck create();
int setDefault(Deck d);
int add(Deck d, Card c);
int pop(Deck d);
_Card take(Deck d);
int shuffle(Deck d);
void printDeck(Deck d);
void destroy(Deck d);
