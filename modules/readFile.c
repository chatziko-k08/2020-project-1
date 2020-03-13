#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//Χρήση του ADTMap μόνο για την άσκηση 2

#include "ADTMap.h"

void calc_lines_max_str_len(char* fin_name, int* lines, int* len) {
    *lines = 0;
    *len = 0;
    FILE* fin = fopen(fin_name, "r");

    assert(fin != NULL);
    
    char ch;
    int len_cnt = 0;
    while((ch = fgetc(fin)) != EOF) {
        if(ch == '\n') {
            (*lines) ++; //Διαβάσαμε νεα γραμμή άρα πρέπει να αυξήσουμε τον counter *lines
            //Αν το len της λέξης που διαβάσαμε τώρα είναι μεγαλύτερο 
            //από το max length (*len) που έχουμε συναντήσει ως τώρα, 
            //άλλαζουμε την τιμή του τελευταίου
            *len = *len < len_cnt? len_cnt : *len; 
        }
        else {
            len_cnt ++; //Αν είμαστε ακόμα στην ίδια γραμμή αυξάνουμε 
        }
    }
    fclose(fin);
}

char** file_reader(char* fin_name, int *lines) {
    int max_len;
    //Για να βρούμε το max string length και τα lines του αρχείου θα φτίαξουμε μια συνάρτηση που θα κάνει ακριβώς αυτό,
    //και καθώς δεν μπορούμε να κάνουμε return πάνω από 1 τιμή θα περάσουμε τις παραπάνω μεταβλητές με pass-by-reference
    calc_lines_max_str_len(fin_name, lines, &max_len);
    
    FILE* fin = fopen(fin_name, "r"); //Ανοίγουμε τον φάκελο για να διαβάσουμε τα strings
    
    char** str_arr = malloc(*lines * sizeof(char*)); 
    for(int i = 0; i < *lines; i++) {
        str_arr[i] = malloc((max_len+1) * sizeof(char)); //Θα μπορούσαμε να μην βάλουμε και το sizeof(char).
        fscanf(fin, "%s", str_arr[i]);
    }

    fclose(fin);
    return str_arr;
}

/////////////////////////////
//////////Άσκηση2////////////
/////////////////////////////

int comp(Pointer A, Pointer B) {
    return strcmp(*(char**)A,*(char**)B);
}

void destroy_key(Pointer a) {
    free(*(char**)a);
    free(a);
}

void destroy_value(Pointer a) {
    free(a);
}

Map get_occurences_map(char* fin_name, int* lines) {

    FILE *fin = fopen(fin_name, "r");
    assert(fin != NULL);
    Map occ_map =map_create(comp, destroy_key, destroy_value);
    char *str;
    int *value;
    int len;
    calc_lines_max_str_len(fin_name, lines, &len);
    str = malloc(sizeof(char) * (len + 1));
    //Σκανάρουμε όλο το αρχείο 
    for(int i = 0; i < 10; i++) {
        fscanf(fin, "%s", str);
        //Τσεκάρουμε αν υπάρχει το key-string μέσα στο map 
        if((value = (int*)map_find(occ_map, &str)) != NULL) {
            //Αν όντως υπάρχει τότε πρέπει να αυξήσουμε τον counter (το value)
           (*(int*)value) ++;
        }
        else {
            //Σε περίπτωση που δεν υπάρχει τότε το βάζουμε στο map με value 1
            Pointer temp = malloc(sizeof(char*));
            *(char**)temp = malloc(sizeof(char) * (strlen(str) + 1));
            strcpy((*(char**)temp), str);

            value = malloc(sizeof(int));
            *value = 1;

            map_insert(occ_map, temp, value);
        }
    }
    free(str);
    fclose(fin);
    return occ_map;
}
