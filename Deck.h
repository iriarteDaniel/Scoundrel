typedef struct _card
{
    char* name;
    int value;
}Card;

typedef struct _deck
{
    Card* cards;
    int size;
}_Deck;

typedef _Deck* Deck;

Deck create();
int setDefault(Deck d);
int add(Deck d);
int take(Deck d);
int shuffle(Deck d);
void destroy(Deck d);