#include <stdio.h>
#include <stdlib.h>
#include "Card.h"

//Shows the name of the card
void printCard(Card c){
    printf("\n");
    printf(c->name);
}

//Creates a Card pointer from a struct _Card
Card createCard(_Card c){
    Card card = (Card) malloc(sizeof(_Card));
    if (card == NULL) return NULL;

    strcpy(card->name, c.name);
    card->value = c.value;
    card->type = c.type;

    return card;
}