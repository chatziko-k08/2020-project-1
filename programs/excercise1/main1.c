#include <stdio.h>
#include "fileReader.h"

int main(void) {
    int lines = 0;
    char** words = file_reader("../../misc/words/words-100000", &lines);
    for(int i = 0; i < lines; i++) {
        printf("%d. %s\n", i+1, words[i]);
    }
    return 0;
}