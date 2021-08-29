#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
This program displays all possible permutations of a given input string.
Here is a sample for the input cat:
 - cat
 - cta
 - act
 - atc
 - tac
 - tca
*/
void permute(char *str, int cursor);
char* swap(char *to_permute, int cursorA, int cursorB);

int main(){
    char string[30];

    // read string from user
    printf("what is the string you want to permute (max 30 chars)? ");
    scanf("%s", string);

    // perform permutation string, put cursor at index 0 (the beginning of string)
    permute(string,0);
    return 0;
}

void permute(char *str_to_permute, int cursor){
    // If cursor is pointing at the last character of string, print out that string
    if (cursor == strlen(str_to_permute)-1){        
        printf("%s\n",str_to_permute);
    }

    // Loop for to get all permutation possibility.
    // In each loop swap the character between cursor and its next character,
    // while at the same time, move forward the cursor.
    // Image: 
    //  permute('cat',0)
    //  |_ permute('cat',1)     --> swap (cat,0,0) == cat
    //     |_ permute('cat',2)  --> swap (cat,1,1) == cat
    //     |_ permute('cta',2)  --> swap (cat,1,2) == cta
    //  |_ permute('act',1)     --> swap (cat,0,1) == act
    //     |_ permute('act',2)  --> swap (act,1,1) == act
    //     |_ permute('atc',2)  --> swap (act,1,2) == atc
    //  |_ permute('tac',1)     --> swap (cat,0,2) == tac
    //     |_ permute('tac',2)  --> swap (tac,1,1) == tac
    //     |_ permute('tac',2)  --> swap (tac,1,2) == tca
    for(int next_char = cursor; next_char<strlen(str_to_permute); ++next_char){
        permute(swap(str_to_permute,cursor,next_char),cursor+1);
    }    
}

// This function copies string to a new one, while swapping the char in cursorA and cursorB
char* swap(char *to_permute, int cursorA, int cursorB){
    char *new_string = malloc(sizeof(to_permute));
    if(new_string == NULL) {
        printf("Unable to allocate memory for the new string.\n");
        exit(1);
    }
    strcpy(new_string,to_permute);
    new_string[cursorA] = new_string[cursorB];
    new_string[cursorB] = to_permute[cursorA];
    return new_string;
}