#ifndef BRITISH
#define BRITISH

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
        return 0;
    }
    for(int i = 0;i<(map+crnt)->s;i++){
	FILE* fptr = fopen("bms_hash_time.csv", "a");
        struct timespec s,e;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &s);
        int f = *(((map+crnt)->node)+i);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &e);
	long time = (e.tv_nsec - s.tv_nsec);
        fprintf(fptr,"%ld,\n",time);
	fclose(fptr);
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
    return 0;
}

#endif
