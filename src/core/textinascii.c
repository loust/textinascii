#ifndef TEXTINASCII_C
#define TEXTINASCII_C
#include <stdio.h>
#include <ctype.h>

#include "../inc/includes.h"

void interpretor(char *str,int init){
    if (str[init] != '\n' && str[init] != '\0'){
        enqueue(str[init]);
        interpretor(str,++init);
    }
}

void printVertical(char *str){
    init();
    interpretor(str,0);
    while (!isEmpty()){

        char holder = dequeue2();
        int atozi = ((int)holder - 0x41);

        if (isalpha((int)holder)){
            printf("%s\n", AtoZ[atozi]);
        }
    }
    if (!isEmpty()){
        killqueue();
    }
}

void printHorizontal(char *str){
    init();
    interpretor(str,0);
    int i, j, e, limit, atozi;
    char holder;

    //have an array to store the letters in from the queue (after they get dequeued)
    //check if the word's end reaches \n or move to the next letter after the 10th index
    //NOTE: Loop 50 times because of the '\'s in after each matrix, it is basically a one liner
    //"*********\n*********\n ... " etc.
    for (e = 0; e < 5; ++e) {
        for (i = 0; i < count; i++) {

            //NOTICE that the use of atozi = ((int)str[i] - 0x41)
            //would have eliminated the use of queues, but
            //this is a demonstration of queue use.
            //Though, the use of direct parameter (str[i]) would be more efficient.
            holder = dequeue2();
            enqueue(holder); //* line 56
            atozi = ((int)holder - 0x41);

            //note that it's reading from line 2, which is the 10s.
            //it is skipping 1 2 3 4
            //nake a variable to hold e*10 and if e=1, it will only multiply it by 1 instead of 10
            for (j = 0; j < 10; ++j) {
                limit = j+(e*10);
                if (isalpha((int)holder) && AtoZ[atozi][limit] != '\n'){
                    printf("%c",(char)AtoZ[atozi][limit]);
                }else{
                    printf("  ");
                }
            }
        }
        putchar('\n');
    }
    //*
    //empties the queue, because the method I'm using is a forced
    //queue use, and rewrites the queue over again while it loops.
    if (!isEmpty()){
        killqueue();
    }
}

void printHelp(){
    printf("\n\t\tTextInASCII\n\n \
DESCRIPTION:\n \
    Prints your string in the form of an ASCII art.\n \
\n \
example:\n \
    textinascii NAME\n \
    textinascii \"GREEN PEPPER\"\n \
    textinascii -v VERTICAL\n \
\n \
OPTIONS:\n \
    -v    Vertical printing.\n \
    -h    Help menu.\n\n");
}

#endif
