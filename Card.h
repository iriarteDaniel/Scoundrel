#include <string.h>
#define NA 0
#define HEARTS 1
#define DIAMONDS 2
#define SPADES 3
#define CLUBS 3

typedef struct _card
{
    char name[4];
    int value;
    int type;
}_Card;

typedef _Card* Card;

void printCard(Card c);
Card createCard(_Card c);