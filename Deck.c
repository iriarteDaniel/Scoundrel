#include <stdlib.h>
#include "Deck.h"

/*Creates an empty deck of 44 cards, the game of scoundrel only uses 44 out of the 52 cards*/
Deck create(){
    Deck deck = (Deck) malloc(sizeof(_Deck));
    if (deck == NULL) return NULL;

    deck->cards = (Card*) malloc(sizeof(Card) * 44);
    if (deck->cards == NULL) {
        free(deck);
        return NULL;
    }

    deck->size = 0;

    return deck;
}

int add(Deck d, Card c){
    if (d == NULL) return 0;
    d->cards[d->size] = c;
    d->size++;

    return 1;
}