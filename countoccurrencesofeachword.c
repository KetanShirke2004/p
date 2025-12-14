#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[200], words[50][20];
    int count[50], n = 0;
    int i, j;
    char temp[20];

    printf("Enter text:\n");
    gets(text);

    /* Replace punctuation with space */
    for (i = 0; text[i]; i++) {
        if (ispunct(text[i]))
            text[i] = ' ';
    }

    /* Read words */
    i = 0;
    while (sscanf(text + i, "%s", temp) == 1) {
        int found = 0;

        for (j = 0; j < n; j++) {
            if (strcmp(words[j], temp) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(words[n], temp);
            count[n] = 1;
            n++;
        }

        i += strlen(temp);
        while (text[i] == ' ')
            i++;
    }

    /* Display result */
    printf("\nWord Count:\n");
    for (i = 0; i < n; i++) {
        printf("%s : %d\n", words[i], count[i]);
    }

    return 0;
}
