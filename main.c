#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algorithm.h"

int main(void){
    srand(time(NULL));
    int val[4] = {0};
    get_values(val);
    struct node* map = map_generator(*val,*(val+1),*(val+2),*(val+3));
    print_map(map,*val);
    int a = -1;
    int s = 1;
    while(1){
        int a = which_search();
        switch(a){
            case 1:
                struct path* bms = (struct path*)malloc(sizeof(struct path));
                bms->p = NULL;
                bms->s = 0;
                bms->next = NULL;
                if(british_museum_search(map,0,9,bms,s)){
                    print_paths(bms);
                }
                else{
                    printf("\nno dice");
                }
                break;
            case 2:
                struct path* dfs = (struct path*)malloc(sizeof(struct path));
                dfs->p = NULL;
                dfs->s = 0;
                dfs->next = NULL;
                if(depth_first_search(map,0,9,s,dfs)){
                    print_paths(dfs);
                }
                else{
                    printf("\nno dice");
                }
                break;
            case 3:
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
            case 4:
                struct path* hc = (struct path*)malloc(sizeof(struct path));
                hc->p = NULL;
                hc->s = 0;
                hc->next = NULL;
                if(hill_climb_search(map,0,99,*val,hc)){
                    print_paths(hc);
                }
                else{
                    printf("\nno dice");
                }
            default:
                printf("\nPlease enter a valid input\n");

        }
        if(a==0){
            break;
        }
    }
    return 0;
}
