#include <stdlib.h>
#include <stdio.h>
#include "Deck.h"

/*Creates an empty deck of 44 cards, the game of scoundrel only uses 44 out of the 52 cards*/
Deck create(){
    Deck deck = (Deck) malloc(sizeof(_Deck));
    if (deck == NULL) return NULL;

    deck->cards = (Card*) malloc(sizeof(Card) * DECK_SIZE);
    if (deck->cards == NULL) {
        free(deck);
        return NULL;
    }

    deck->size = 0;

    return deck;
}

//Adds a card to the end of a deck, as long as it isn't full.
int add(Deck d, Card c){
    if (d == NULL) return 0;
    if (d->size == DECK_SIZE) return 0;

    d->cards[d->size] = c;
    d->size++;

    return 1;
}

//Deletes the first card from a deck, reorganizes the deck after.
int pop(Deck d){
    if (d == NULL) return 0;
    for (int i = 0; i < d->size; i++)
    {
        d->cards[i] = d->cards[i+1];
    }
    d->size--;

    return 1;
}

//Takes a card from the deck, returns the card and deletes it from the deck.
_Card take(Deck d){
    _Card def = {"NA", 0, 0};
    if (d == NULL) {
        return def;
    }
    if (d->size = 0)
    {
        printf("No hay cartas para sacar");
        return def;
    }
    
    Card card = d->cards[0];

    pop(d);
    
    return *card;
}

// Print the cards form the deck
void printDeck(Deck d){
    if (d == NULL) {
        printf("No hay mazo");
    }
    Card temp;
    for (int i = 0; i < d->size; i++)
    {
        temp = d->cards[i];
        printCard(temp);
    }
}

// Frees the memory
void destroy(Deck d){
    free(d->cards);
    free(d);
}