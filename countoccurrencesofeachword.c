#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[200];
    char words[50][20];
    int count[50] = {0};
    int i, j, n = 0;

    printf("Enter text:\n");
    gets(text);   // for simplicity (exam use)

    /* Convert to lowercase */
    for (i = 0; text[i]; i++)
        text[i] = tolower(text[i]);

    /* Extract words */
    i = 0;
    while (text[i] != '\0') {
        if (isalpha(text[i])) {
            j = 0;
            char temp[20];

            while (isalpha(text[i])) {
                temp[j++] = text[i++];
            }
            temp[j] = '\0';

            /* Check if word already exists */
            int found = 0;
            for (j = 0; j < n; j++) {
                if (strcmp(words[j], temp) == 0) {
                    count[j]++;
                    found = 1;
                    break;
                }
            }

            /* New word */
            if (!found) {
                strcpy(words[n], temp);
                count[n] = 1;
                n++;
            }
        } else {
            i++;
        }
    }

    /* Display result */
    printf("\nWord Count:\n");
    for (i = 0; i < n; i++)
        printf("%s : %d\n", words[i], count[i]);

    return 0;
}
