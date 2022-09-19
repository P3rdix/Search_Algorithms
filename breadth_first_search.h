#ifndef BFS
#define BFS

#include <stdlib.h>
#include "struct.h"

void print_paths(struct path*);
struct path* enqueue(struct path*,struct path*, struct path*, int, struct node*);

int breadth_first_search(struct node* map, int start, int goal, struct path* p){
    struct path *head, *tail;
    head = (struct path*)malloc(sizeof(struct path));
    head->s = 1;
    head->p = (int*)malloc(sizeof(int));
    *(head->p) = start;
    head->next = NULL;
    tail = head;
    p->s = -1;
    while(head != NULL){
        tail = enqueue(head,tail,p,goal,map);
        if(p->s != -1){
            tail = NULL;
            while(head == NULL){
                struct path* t2 = head;
                free(head->p);
                head = head->next;
                free(t2);
            }
            return 1;
        }
        struct path* t2 = head;
        free(head->p);
        head = head->next;
        if(head == NULL){
            tail == NULL;
        }
        free(t2);
    }
    return 0;
}

struct path* enqueue(struct path* head, struct path* tail, struct path* t, int goal, struct node* map){
    int s = (map+*((head->p)+(head->s-1)))->s;
    for(int i = 0;i<s;i++){
        struct path* temp = (struct path*)malloc(sizeof(struct path));
        temp->next = NULL;
        temp->s = head->s+1;
        temp->p = (int*)malloc(sizeof(int)*(temp->s));
        
        for(int j = 0;j<temp->s-1;j++){
            *(temp->p+j) = *(head->p+j);
        }
        *(temp->p+(temp->s-1)) = *((map+*((head->p)+(head->s-1)))->node+i);
        tail->next = temp;
        tail = tail->next;
        if(*(temp->p+(temp->s-1)) == goal){
            t->next = NULL;
            t->s = temp->s;
            t->p = (int*)malloc(sizeof(int)*(t->s));
            for(int j = 0;j<temp->s;j++){
                *(t->p+j) = *(temp->p+j);
                printf("\n%d", *(t->p+j));
            }
            return tail;
        }
        
    }
    return tail;
}

#endif