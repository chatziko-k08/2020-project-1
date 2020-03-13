#pragma once
#include "ADTMap.h"

//Άσκηση 1:
//Συνάρτηση που βρίσκει πόσες γραμμές έχει το fin και το μέγιστο μήκος των λέξεων που περιέχει
void calc_lines_max_str_len(char *fin_name, int *lines, int *len);

//Συνάρτηση που γυρνάει πίνακα από strings όπου κάθε index του περιέχει μία γραμμή-λέξη
// του αρχείου fin( ταυτόχρονα σου δίνει και το πλήθος των γραμμών του αρχείου)
char **file_reader(char *fin_name, int *lines);


//Άσκηση2:
Map get_occurences_map(char *fin_name, int *lines);