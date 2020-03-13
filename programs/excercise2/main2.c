#include <stdio.h>
#include "fileReader.h"
#include "ADTMap.h"

int main(void) {
    int lines;
    Map m = get_occurences_map("../../misc/words/words-10", &lines);

    MapNode n;
    n = map_first(m);
    while(n != MAP_EOF) {
        Pointer key, val;
        key = map_node_key(m, n);
        val = map_node_value(m, n);
        printf("%s : %d\n", *(char**)key, *(int*)val);
        n = map_next(m, n);
    }
    map_destroy(m);
    return 0;
}