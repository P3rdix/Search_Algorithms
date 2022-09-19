#ifndef ALGORITHM
#define ALGORITHM

#include "struct.h"
#include "map_generator.h"
#include "dfs.h"
#include "bms.h"
#include "bfs.h"

int* get_values(int* val){
    while(*(val) <= 0){
        printf("\nPlease enter number of nodes. Number must be positive and greater than 0. Enter:");
        scanf("%d",val);
    }
     while(*(val+1) <= 0){
        printf("\nPlease enter number of paths to a node. Number must be positive and greater than 0. Enter:");
        scanf("%d",val+1);
    }
     while(*(val+2) <= 0){
        printf("\nPlease enter maximum possible x value . Number must be positive and greater than 0. Enter:");
        scanf("%d",val+2);
    }
     while(*(val+3) <= 0){
        printf("\nPlease enter maximum possible y value. Number must be positive and greater than 0. Enter:");
        scanf("%d",val+3);
    }
    return val;
}

void print_paths(struct path* p){
    while(p!=NULL){
        printf("\n");
        for(int i = 0;i<p->s;i++){
            printf("%d\t",*(p->p+i));
        }
        p = p->next;
    }
    return;
}

int which_search(){
    int a = -1;
    while(a<0 || a>=12){
        printf("\nEnter search algorithm to be used. Press:\n1. for British Museum Search\n2. for Depth First Search\n3. for Breadth First Search\n4. for Hill Climb Search\n 5. for Beam Search\n6. for Oracle \n7. for Branch and Bound Search\n8. for Branch and Bound with Estimated Heuristics\n9. for Branch and Bound with Extended list Pruning\n10. for A* search\n0. to exit\nEnter : ");
        scanf("%d",&a);
    }
    return a;
}

void print_map(struct node* map, int size){
    for(int i = 0;i<size;i++){
        printf("\n%d\n",(map+i)->val);
        for(int j = 0;j<(map+i)->s;j++){
            printf("\t%d",*(((map+i)->node)+j));
        }
    }
    return;
}

#endif
