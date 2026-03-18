#include "Game.h"
#include <stdio.h>

#define ROOM_SIZE 4
#define MAX_HEALTH 20

Deck deck;
int health;
_Card room[ROOM_SIZE];
int roomSize;
int weaponDamage;
int weaponDurability;
int runInt = 1;
int winInt = 0;
int loseInt = 0;


void init(){
    //Initialize the variables for a new game
    deck = create();
    setDefault(deck);
    shuffle(deck);
    health = MAX_HEALTH;
    weaponDamage = 0;
    weaponDurability = 0;
    roomSize = 0;

    //Main game loop
    while(1){
        if (winInt){        //Win condition
            win();
            return;
        }
        if (loseInt) { //Lose condition
            lose();
            return;
        }
        choice();
    }

    printf("Ending game...");
    destroy(deck);
}

void printRoom(){
    printf("\nCards left %d", deck->size);
    printf("\nHealth: %d", health);
    printf("\nWeapon Damage: %d", weaponDamage);
    printf("\nWeapon Durability: %d", weaponDurability);
    for (int i = 0; i < roomSize; i++)
    {
        printCard(&room[i]);
    }
    
}

void choice(){
    if (roomSize <= 1) restartRoom();
    printRoom();

    int op;
    printf("\nChoose a card (number) ");
    printf("\n5 to run\n");
    scanf("%d", &op);

    handleCard(op);
}

void restartRoom(){
    for (roomSize; roomSize < 4; roomSize++)
    {
        if (deck->size == 0) return;
        room[roomSize] = take(deck);
    }
}

int handleCard(int option){
    if(option < 1 || option > 5) return 0;
    if(option == 5 && roomSize == 4){
        if (runInt == 0)
        {
            printf("You can't run right now");
            return 0;
        }
        run();
        
    }
    switch (room[option-1].type)
    {
    case 0:
        return 0;
    case 1:
        caseHeart(room[option-1]);
        break;
    case 2:
        caseDiamond(room[option-1]);
        break;
    case 3:
        caseBlack(room[option-1]);
        break;
    
    default:
        return 0;
        break;
    }

    //remove option from room[]
    for (int i = option-1; i < roomSize; i++)
    {
        room[i] = room[i+1];
    }
    roomSize--;
    runInt = 1;

    if (roomSize == 1) return 2;

    return 1;
}

void caseHeart(_Card card){
    health+= card.value;
    if (health > 20) health=20;
}

void caseDiamond(_Card card){
    weaponDamage = card.value;
    weaponDurability = 15;
}

void caseBlack(_Card card){
    if(weaponDurability > card.value){
        weaponDurability = card.value;
        if (card.value >= weaponDamage)
        {
            health -= (card.value - weaponDamage);
        }
    }
    else{
        health -= card.value;
    }
    if (health <= 0) loseInt = 1;
}

void run(){
    Card temp;
    for (roomSize; roomSize>0; roomSize--)
    {
        temp = createCard(room[roomSize-1]);
        add(deck, temp);
    }
    restartRoom();
    runInt = 0;
}

void win(){
    printf("You won!");
    return;
}

void lose(){
    printf("You lost");
    return;
}