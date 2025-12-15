
#include<Stdio.h>
#include<string.h>
#include<ctype.h>
void CountWordsOccurrences(char text[]){
    char words[100][50]; // to store unique words
    int count[100]={0}; // to store occurrences of each word
    int wordCount=0; // to keep track of number of unique words
    char word[50]; // to store current word
    int w=0; // index for current word
    for(int i=0;text[i]!='\0';i++){
        if(isalpha(text[i])){// check if character is part of a word
            word[w++]=text[i];
        }
        else if(w>0){
            word[w]='\0';// terminate current word
            w=0;// reset index for next word
            int found=0;
            for(int j=0;j<wordCount;j++){// check if word already exists
                if(strcmp(words[j],word)==0){
                    count[j]++;// increment count if found
                    found=1;
                    break;
                }

            }
            if(!found){
                strcpy(words[wordCount],word);// add new word
                count[wordCount]++;// initialize count
                wordCount++;// increment unique word count
            }

        }
    }
    // check for last word if text doesn't end with punctuation
    if(w>0){
        word[w]='\0';
        int found=0;
        for(int j=0;j<wordCount;j++){
            if(strcmp(words[j],word)==0){
                count[j]++;
                found=1;
                break;
            }
        }
        if(!found){
            strcpy(words[wordCount],word);
            count[wordCount]++;
            wordCount++;
        }
    }
    // display results
    printf("Word Occurrences:\n");
    for(int i=0;i<wordCount;i++){
        printf("%s: %d\n",words[i],count[i]);
    }
}
int main(){
    char text[1000];
    printf("Enter the text:\n");
    fgets(text, sizeof(text), stdin);
    CountWordsOccurrences(text);
    return 0;
}
