#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorithm.h"
#include "struct.h"

int main(void){
    srand(time(NULL));
    int val[4] = {0};
    get_values(val);
    struct node* map = map_generator(*val,*(val+1),*(val+2),*(val+3));
    print_map(map,*val);
    map_write(map,"test.txt",*val);
    struct node* map2 = map_read("test.txt", *val);
    print_map(map2,*val);
    int a = -1;
    int s = 1;
    while(1){//comment
        int a = which_search();
        switch(a){
            case 1: ;
                struct path* bms = (struct path*)malloc(sizeof(struct path));
                bms->p = NULL;
                bms->s = 0;
                bms->next = NULL;
                british_museum_search(map,0,22,bms,s);
                print_paths(bms);
                break;
            case 2: ;
                struct path* dfs = (struct path*)malloc(sizeof(struct path));
                dfs->p = NULL;
                dfs->s = 0;
                dfs->next = NULL;
                depth_first_search(map,0,98,s,dfs);
                print_paths(dfs);
                break;
        }
        if(a==0){
            break;
        }
    }
    return 0;
}
