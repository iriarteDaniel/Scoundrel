#include <stdio.h>
#include <stdlib.h>
#include "Deck.h"

int main(){
    Card card = {"T10", 10};
    Deck deck = create();
    add(deck, card);
    

    return 0;
}