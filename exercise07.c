#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function initiation.
int countWord (char* line);

int main(void){
    // variable to hold the number of lines, words, chars.
    int num_line, num_word, num_char = 0;
    
    // Open the text file in read mode.
    FILE* fptr = fopen("exercise07-input.txt","r");

    // We will store the chunk into a line buffer
    char chunk[100]; // maximum 100 characters to read using fgets
    size_t len = sizeof(chunk);
    
    // a buffer to read a line in case it has more than 100 characters
    char *line = malloc(len);
    if(line == NULL) {
        printf("Unable to allocate memory for the line buffer.\n");
        exit(1);
    }

    // "Empty" the line buffer with empty string
    line[0] = '\0';
    
    while(fgets(chunk,sizeof(chunk),fptr) != NULL){
        // in each iteration, fgets only stops in case of either 1 of these 3 conditions:
        // 1. it reads the number of sizeof(line)
        // 2. it reach the end of line, i.e. line[len-1] == "\n"
        // 3. it reach the end of file, i.e. feof(fp) != 0
        
        // Resize the line buffer if necessary
        size_t len_used = strlen(line);
        size_t chunk_used = strlen(chunk);

        // Expand the line buffer if we had encounter a line with more than 100 chars.
        if(len - len_used < chunk_used) {
            len *= 2;
            if((line = realloc(line, len)) == NULL) {
                printf("Unable to reallocate memory for the line buffer.\n");
                free(line);
                exit(1);
            }
        }

        // Copy the chunk to the end of the line buffer
        // char * strncpy ( char * destination, const char * source, size_t num );
        strncpy(line + len_used, chunk, len - len_used);
        len_used += chunk_used;

        // Check if line contains '\n', if do the counting
        if(line[len_used - 1] == '\n') {
            // count number of lines, characters, and words
            num_line ++;
            num_char += len_used;
            num_word += countWord(line);
            // fputs(line, stdout);
            // fputs("|*\n", stdout); // for debugging purpose
            
            // "Empty" the line buffer
            line[0] = '\0';
        }
    }

    // write output
    printf("num of lines: %d\n", num_line);
    printf("num of words: %d\n", num_word);
    printf("num of chars: %d\n", num_char);
    return 0;
}

// Function implementation to count number of words in a line
int countWord (char* line){
    // prev_char and curr_char = 0 represent whitespace
    int prev_char = 0;
    int curr_char = 0;
    
    int word_count = 0; // number of words to return
    int i;
    int line_len = strlen(line);
    
    // Traverse through each char in that line, 
    // see if current/previous character is whitespace or not
    for (i=0;i<line_len;++i){
        if (isspace(line[i])){
            prev_char = curr_char;
            curr_char = 0;
        }
        else{
            prev_char = curr_char;
            curr_char = 1;            
        }
        
        // If prev char is a whitespace and current char is not, count it as a word
        if ((prev_char == 0) && (curr_char == 1))
            ++word_count;
    }
    return word_count;
}