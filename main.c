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
    FILE *fptr = fopen("test.txt","w+");
    map_write(fptr,map,*val);
    fseek(fptr,0,SEEK_SET);
    printf("\nHello main");
    printf("\nHELLO2");
    struct node* map2 = map_read(fptr, *val);
    fclose(fptr);
    print_map(map2,*val);
    int a = -1;
    int s = 1;
    while(1){
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
            case 3: ;
                struct path* bfs = (struct path*)malloc(sizeof(struct path));
                bfs->p = NULL;
                bfs->s = 0;
                bfs->next = NULL;
                if(breadth_first_search(map,0,9,bfs)){
                    print_paths(bfs);
                }
                else{
                    printf("\nno dice");
                }
                break;
        }
        if(a==0){
            break;
        }
    }
    return 0;
}
