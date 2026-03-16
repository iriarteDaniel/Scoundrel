#include <stdio.h>
#include <stdlib.h>
//#include "Deck.h"
#include "Card.h"

int main(){
    _Card card = {"T10", 10, 0};
    Card ptrCard = &card;

    print(ptrCard);

    return 0;
}