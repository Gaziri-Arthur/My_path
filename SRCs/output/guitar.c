#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <ctype.h>

/* Constants definitions */
#define NOTE_COUNT 4
#define LINES 20
#define COLUMNS 5
#define NOTE_DELAY 500
#define PAUSE getch();
#define CLS printf("\033[2J\033[1;1H");
#define SPAUSE printf("Press any key to continue..."); PAUSE

/* Struct definitions*/
typedef struct{
    int lin; // Position of the note (line)
    int col; // Position of the note (column)
} TPosition;

typedef struct{
    char key; // Corresponding key
    TPosition pos; // Position of the note
} TNote;

/* Function declarations */
void menu(); // Show main menu
void start(); // Start the game
void title(); // Type the title: "Guitar Hero"
void option(int op); // Choose option
void play(); // Play the game
void showRecords(); // Show player records
void showRanking(); // Show players rankings
int catchKey(); // Get user input
void game(TNote note); // Game logic
void exitGame(); // Exit the game

int main(){
    int op;
    srand((unsigned)time(NULL));

    CLS
    start();
    do{
        menu();
        op = catchKey();

        option(op);
    } while(op != 4);

    return 0;
}

void menu(){
    CLS
    printf("-- Guitar Hero --\n");
    printf("1. Play\n");
    printf("2. Records\n");
    printf("3. Ranking\n");
    printf("4. Exit\n\n");
    printf("** Enter your choice: ");
}

void option(int op){
    CLS
    switch(op){
        case 1:
            play();
            break;
        case 2:
            showRecords();
            break;
        case 3:
            showRanking();
            break;
        case 4:
            exitGame();
            break;
        default:
            printf("Option not found. Try again!\n\n");
            SPAUSE
    }
}

void play(){
    TNote note;
    const char key[NOTE_COUNT] = {'A', 'S', 'D', 'F'};

    note.pos.lin = 0;
    note.pos.col = rand() % COLUMNS;
    note.key = key[rand() % NOTE_COUNT];
    for(int i = 0; i < LINES; i++){
        CLS
        game(note);

        note.pos.lin++;
        Sleep(NOTE_DELAY);
    }

    printf("Game Over (Simulation)");
    PAUSE
}

void game(TNote note){
    printf("  _______\n");
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < COLUMNS; j++){
            if (i == note.pos.lin && j == note.pos.col && i != 10){
                printf("  %c ", note.key);
            } else if(i == 10 && j == 0){
                if(note.pos.lin == 10 && note.pos.col == 0){
                    printf("  %c__|_|_|__|", note.key);
                } else if(note.pos.lin == 10 && note.pos.col == 1){
                    printf("  |_%c__|_|__|", note.key);
                } else if(note.pos.lin == 10 && note.pos.col == 2){
                    printf("  |_|_%c__|__|", note.key);
                } else if(note.pos.lin == 10 && note.pos.col == 3){
                    printf("  |_|_|_%c___|", note.key);
                } else if(note.pos.lin == 10 && note.pos.col == 4){
                    printf("  |_|_|_|_%c", note.key);
                } else{
                    printf("  |_|_|_|_|");
                }
            } else if(i != 10){
                printf("  | ");
            }
        }
        printf("\n");
    }
}

void showRecords(){
    printf("--- Records ---\n");
    printf("(Function not implemented yet)\n\n");
    SPAUSE
}

void showRanking(){
    printf("\t--- Ranking ---\n");
    printf("1 - 6PedrinGameplays9 [500 points]\n");
    printf("2 - Beniio_reidelas69 [460 points]\n");
    printf("3 - NeutronJimmy_2009 [300 points]\n");
    printf("4 - Gaybriels101Negao [290 points]\n");
    printf("5 - LittleMilkinho123 [10 points]\n\n");
    SPAUSE
}

void start(){
    char *start_messages[3] = {"Connecting amplifiers", "Adjusting volume", "Tuning the guitar"};
    printf("%s...\n", start_messages[rand()%3]);
    for(int i = 0; i <= 50; i++){
        int percent = (i * 100) / 50;

        printf("\r[");
        for(int j = 0; j < 50; j++){
            if (j < i) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("] %d%%", percent);

        fflush(stdout);
        Sleep(50);
    }
    sleep(1);
    CLS
    title("-- Guitar Hero --");
}

void title(char *title){
    for(int i = 0; title[i] != '\0'; i++){
        printf("%c", title[i]);
        Sleep(100);
    }
    printf("\n");
}

void exitGame(){
    char *exit_messages[3] = {"Saving the setlist", "Packing the gear", "Turning off the amps"};
    printf("%s", exit_messages[rand()%3]);
    for(int i = 0; i < 3; i++){
        printf(".");
        Sleep(500);
    }
}

int catchKey(){
    char choice;
    int op;

    choice = getch();
    fflush(stdin);
    op = atoi(&choice);

    return op;
}