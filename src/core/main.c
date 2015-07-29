#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../headers/textinascii.h"
#include "../headers/font.h"

int main(int argc, const char *argv[]){
    if (argc > 1){
        int i, j;
        bool vert = false;
        bool help = false;
        for (i = 1; i < argc; i++){
            switch(*(char*)argv[i]){
                case 0x2D:
                    for (j = 0; j < sizeof argv[i]; j++) {
                        (argv[i][j]==0x76) ? vert = true : 0;
                        (argv[i][j]==0x68) ? help = true : 0;
                    }
                    if (help){
                        printHelp();
                        return 0;
                    }
                    break;
                default:{
                    char *str = (char*)argv[i];
                    //scanf("%ms",&str);
                    //printVertical(str);
                    //(help) ? printHelp() : 0;
                    (!vert) ? printHorizontal(str) : printVertical(str);
                    break;
                }
            }
        }
    }
    return 0;
}
