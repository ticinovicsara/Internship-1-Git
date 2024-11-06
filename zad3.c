#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LEN 1000
#define MAX_LINE_LEN 100

int main(){
    int m, n;

    printf("Type max number of characters per line: ");
    scanf("%d", &m);
    getchar();
    printf("Type max number of lines: ");
    scanf("%d", &n);
    getchar();  //remove \n

    if(n < m){
        printf("max number of lines cannot be less than max number of characters!\n");
        return -1;
    }

    char text[MAX_TEXT_LEN];
    printf("Type in your multiline text: \n");

    //get multiple lines
    char buffer[MAX_LINE_LEN];
    while(1){
        fgets(buffer, sizeof(buffer), stdin);

        if(strcmp(buffer, "\n") == 0){
            break;
        }

        strncat(text, buffer, sizeof(text) - strlen(text) -1);
    }

    //split up the words
    char *words[MAX_TEXT_LEN / 2];
    int word_counter = 0;

    char* token = strtok(text, " \n");
    while(token != NULL){
        words[word_counter++] = token;
        token = strtok(NULL, " \n");
    }

    char line[MAX_LINE_LEN];

    printf("\nCentered text: \n");
    int i=0;
    while(i < word_counter){
        int line_len = 0;
        int start = i;

        while(i < word_counter){
            int curr_len = strlen(words[i]);
            if(line_len > 0){
                curr_len++;
            }

            if(line_len + curr_len <= m){
                line_len += curr_len;
                i++;
            }
            else{
                break;
            }
        }


        //create line with words
        line[0] = '\0';
        for(int j = start; j<i; j++){
            strcat(line, words[j]);
            if(j < i-1){
                strcat(line, " ");
            }
        }

        //spaces
        int total_spaces = m - line_len;
        int left_spaces = total_spaces / 2;
        int right_spaces = total_spaces - left_spaces;

        for(int k=0; k<left_spaces; k++){
            printf(" ");
        }

        printf("%s", line);

        for(int k=0; k<right_spaces; k++){
            printf(" ");
        }

        printf("\n");
    }
    
    printf("\n");

    return 0;
}