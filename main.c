#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Skeleton for the enemy
struct Enemy {
    int level;
    int health;
    int attack;
    int defence;
    char name[100];
};

//Skeleton for the player
struct Player {
    int level;
    int health;
    int attack;
    int defence;
    char *class;
};

//List of enemies
struct Enemy e[] = {
    {1, 2, 3, 2, "Wolf"},
    {1, 4, 2, 2, "Elf"},
    {1, 3, 1, 1, "Goblin"}
};

int main(){
    int     player_die, enemy_die, enemy_to_fight;
    char    roll;
    int     class;
    time_t  t;
    struct  Player *p;
    
    //Intializes the random number generator
    srand((unsigned) time(&t));

    //Choosing a class...
    printf("Choose a class:\n  1. Wizard\n  2. Thief\n  3. Warrior\nEnter: ");
    scanf(" %i", &class);
    if(!(class == 1 || class == 2 || class == 3)){
        printf("Invalid input.\n");
        return -1;
    }
    else if (class == 1){
        p->class    = "Wizard";
        p->level    = 1;
        p->health   = 3;
        p->attack   = 3;
        p->defence  = 1;
    }
    else if (class == 2){
        p->class    = "Thief";
        p->level    = 1;
        p->health   = 3;
        p->attack   = 3;
        p->defence  = 2;
    }
    else if(class == 3){
        p->class    = "Warrior";
        p->level    = 1;
        p->health   = 5;
        p->attack   = 2;
        p->defence  = 3;
    }

    printf("\nYou are a powerful level %d %s with %d HP. You got %d attack and %d defence.\n",
            p->level, p->class, p->health, p->attack, p->defence);
    
    //Pick a random enemy from e[]
    enemy_to_fight = rand() % (int)( sizeof(e) / sizeof(e[0]));
    printf("You encounter a level %d %s with %d HP. It has %d attack and %d defence.\n", 
            e[enemy_to_fight].level, e[enemy_to_fight].name, e[enemy_to_fight].health, e[enemy_to_fight].attack, e[enemy_to_fight].defence);

    do {
        printf("Press 'R' to roll. ");
        scanf(" %c", &roll);
        if(!(roll == 'r' || roll == 'R')){ //want this to try the condition again instead of quitting, but not rolling...
            printf("Got to hit R!\r");     //"else: jump back to start"
            return -1;
        }

        //Roll a random number between 0-20
        player_die = rand() % 21;
        printf("Player roll: %d\n", player_die);

        enemy_die = rand() % 21;
        printf("Enemy  roll: %d\n", enemy_die);

        //The highest roller can attack, if equal neither will make a move
        if (player_die > enemy_die){
            printf("Player attacks the enemy for %d damage!\n", p->attack - e[enemy_to_fight].defence);
            e[enemy_to_fight].health -= p->attack - e[enemy_to_fight].defence;
        }
        else if (enemy_die > player_die){
            printf("Enemy attacks the player for %d damage!\n", e[enemy_to_fight].attack - p->defence);
            p->health -= e[enemy_to_fight].attack - p->defence;
        }
        else{
            printf("The attack were deflected!.\n");
        }
        printf("Current enemy HP: %d\n", e[enemy_to_fight].health);
        printf("Current player HP: %d\n", p->health);

    }while(((e[enemy_to_fight].health >= 1) && (p->health >= 1)) && ((roll == 'r') || (roll == 'R')));
        //while either health is above 0 and 'r' is pressed...

    //Print out the battle result.
    if(e[enemy_to_fight].health < 1){
        printf("You have defeated the enemy!\n");
    }
    else if(p->health < 1){
        printf("You have been defeated!\n");
    }

    return 0;
}

/* NOTES AND SOURCES
to do: weapon types, randomize enemy (array?), inventory management, text-based dungeon crawl
    store player level, exp, items, learned abilities somehow
    graphics to display enemy? check opengl
https://stackoverflow.com/questions/44574856/initialize-c-struct-through-a-function


OBSOLETE (keep for notes)
=========================
struct  Enemy *e  = initialize_enemy();

Initialize the enemy - randomize later
struct Enemy *initialize_enemy(){
    //Allocate enough memory for the struct
    struct Enemy *enemy = malloc(sizeof(*enemy));
    if (!enemy) {
        perror("malloc failed");
        exit(1);
    }

    enemy->level = 1;
    enemy->health = 5;
    enemy->attack = 4;
    enemy->defence = 1;
    enemy->name = "Wolf";

    return enemy;
}

//Initialize the player - choose class, race etc later? random start?
struct Player *initialize_player(){
    //Allocate enough memory for the struct
    struct Player *player = malloc(sizeof(*player));
    if (!player) {
        perror("malloc failed");
        exit(1);
    }

    player->level = 1;
    player->health = 3;
    player->attack = 5;
    player->defence = 1;
    player->class = "Wizard";

    return player;
}

*/
