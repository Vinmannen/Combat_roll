#include <stdio.h>
#include <stdlib.h>

//Skeleton for the enemy
struct Enemy {
    int level;
    int health;
    int attack;
    int defence;
    char *name;
};

//Skeleton for the player
struct Player {
    int level;
    int health;
    int attack;
    int defence;
    char *class;
};

//Initialize the enemy - randomize later
struct Enemy *initialize_enemy(){
    //Allocate enough memory for the struct
    struct Enemy *enemy = malloc(sizeof(*enemy));
    if (!enemy) {
        perror("malloc failed");
        exit(1);
    }

    enemy->level =1;
    enemy->health = 3;
    enemy->attack = 3;
    enemy->defence = 2;
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

    player->level =1;
    player->health = 3;
    player->attack = 3;
    player->defence = 2;
    player->class = "Wizard";

    return player;
}

int main(){
    int    player_die, enemy_die;
    char   roll;
    time_t t;
    struct Enemy *e  = initialize_enemy();
    struct Player *p = initialize_player();

    printf("You are a powerful level %d %s with %d HP. You got %d attack and %d defence.\n",
            p->level, p->class, p->health, p->attack, p->defence);
    printf("You encounter a level %d %s with %d HP. It has %d attack and %d defence.\n", 
            e->level, e->name, e->health, e->attack, e->defence);

    do {
        printf("Press 'R' to roll. ");
        scanf(" %c", &roll);
        if(!(roll == 'r' || roll == 'R')){ //want this to try the condition again instead of quitting, but not rolling...
            printf("Got to hit R!\r");     //"else: jump back to start"
            break;
        }
        //Intializes the random number generator
        srand((unsigned) time(&t));

        //Roll a random number between 0-20
        player_die = rand() % 21;
        printf("Player roll: %d\n", player_die);

        enemy_die = rand() % 21;
        printf("Enemy  roll: %d\n", enemy_die);

        //The highest roller can attack, if equal neither will make a move
        if (player_die > enemy_die){
            printf("Player attacks the enemy for %d damage!\n", p->attack - e->defence);
            e->health -= p->attack - e->defence;
        }
        else if (enemy_die > player_die){
            printf("Enemy attacks the player for %d damage!\n", e->attack - p->defence);
            p->health -= e->attack - p->defence;
        }
        else{
            printf("The attack were deflected!.\n");
        }
        printf("Current enemy HP: %d\n", e->health);
        printf("Current player HP: %d\n", p->health);

    }while(((e->health >= 1) && (p->health >= 1)) && ((roll == 'r') || (roll == 'R')));
        //while either health is above 0 and 'r' is pressed...

    //Print out the battle result.
    if(e->health < 1){
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
*/