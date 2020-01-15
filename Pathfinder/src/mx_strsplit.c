#include "libmx.h"

char **mx_strsplit(const char* s, char c) {
    int i = 0;
    int j = 0;
    int letters;
    char **new;

    if (s == NULL)
        return NULL;
    new = (char **)malloc(sizeof(char *) * (mx_count_words(s, c) + 1));

    while (s[i]) {
        if (s[i] == c)
            i++;
        else {
            letters = count_letters(&s[i], c);
            new[j] = mx_strnew(letters);
            for (int k = 0; k < letters; k++)
                new[j][k] = s[i++];
            j++;
        }
    }
    new[j] = NULL;
    return new;
}   
