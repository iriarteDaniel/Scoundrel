#include <stdio.h>
#include <stdlib.h>
#include "Deck.h"

int main(){
    _Card card = {"T10", 10, CLUBS};
    Card ptrCard = &card;

    Deck deck = create();

    add(deck, ptrCard);

    printDeck(deck);

    destroy(deck);
    return 0;
}