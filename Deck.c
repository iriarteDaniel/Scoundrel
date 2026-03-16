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

// Sets a deck to the default 
int setDefault(Deck d){
    if (d == NULL) return 0;
    Deck tempDeck = create();

    _Card def[44] = {
        {"H2",2,HEARTS},{"H3",3,HEARTS},{"H4",4,HEARTS},{"H5",5,HEARTS},
        {"H6",6,HEARTS},{"H7",7,HEARTS},{"H8",8,HEARTS},{"H9",9,HEARTS},
        {"H10",10,HEARTS},

        {"D2",2,DIAMONDS},{"D3",3,DIAMONDS},{"D4",4,DIAMONDS},{"D5",5,DIAMONDS},
        {"D6",6,DIAMONDS},{"D7",7,DIAMONDS},{"D8",8,DIAMONDS},{"D9",9,DIAMONDS},
        {"D10",10,DIAMONDS},

        {"S2",2,SPADES},{"S3",3,SPADES},{"S4",4,SPADES},{"S5",5,SPADES},
        {"S6",6,SPADES},{"S7",7,SPADES},{"S8",8,SPADES},{"S9",9,SPADES},
        {"S10",10,SPADES},{"SJ",11,SPADES},{"SQ",12,SPADES},{"SK",13,SPADES},{"SA",14,SPADES},

        {"C2",2,CLUBS},{"C3",3,CLUBS},{"C4",4,CLUBS},{"C5",5,CLUBS},
        {"C6",6,CLUBS},{"C7",7,CLUBS},{"C8",8,CLUBS},{"C9",9,CLUBS},
        {"C10",10,CLUBS},{"CJ",11,CLUBS},{"CQ",12,CLUBS},{"CK",13,CLUBS},{"CA",14,CLUBS}
    };

    Card tempCard;
    for (int i = 0; i < 44; i++)
    {
        tempCard = createCard(def[i]);
        add(tempDeck, tempCard);
    }

    d->cards = tempDeck->cards;
    d->size = DECK_SIZE;

    return 1;
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
    if (d->size == 0)
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