#ifndef BRITISH
#define BRITISH

#include "struct.h"
#include <stdlib.h>

int british_museum_search(struct node* map, int crnt, int goal, struct path* p, int count){
    printf("\n%d",crnt);
    if(crnt == goal){
        struct path* t = p;
        while(t->next != NULL){
            t = t->next;
        }
        t->p = (int*)malloc(sizeof(int)*count);
        t->s = count;
        for(int i = 0;i<t->s;i++){
            *(t->p+i) = 0;
        }
        *(t->p+t->s-1) = crnt;
        t->next = (struct path*)malloc(sizeof(struct path));
        t = t->next;
        t->next = NULL;
        return 1;
    }
    for(int i = 0;i<(map+crnt)->s;i++){
        clock_t s,e;
        s = clock();
        int f = *(((map+crnt)->node)+i);
        e = clock()-s;
        printf("\nt = %f",(double)e);
        int t = british_museum_search( map, f, goal, p, count+1);
        struct path* temp = p;
        while(temp != NULL){
            if( count-1 < temp->s){
                if(*(temp->p+count-1) == 0){
                    *(temp->p+count-1) = crnt;
                }
            }
            temp = temp->next;
        }
    }
    if(p->s == 0){
        return 0;
    }
    return 1;
}

#endif