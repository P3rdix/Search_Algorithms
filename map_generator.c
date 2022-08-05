#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"

struct list
{
    struct node* p;
    struct list* next;
};

int copycheck(struct list*,struct node*);

struct node* map_generator(int no_nodes,int max_value,int max_path,int max_x,int max_y)
{
    srand(time(NULL));
    int i=0;
    struct list* a = NULL, *b=NULL;
    while(i<no_nodes){
        struct node* new = (struct node*)malloc(sizeof(struct node));
        new->val = rand()%max_value;
        new->x = rand()%max_x;
        new->y = rand()%max_y;
        new->next=NULL;
        int quadrant=rand()%4;
        switch (quadrant){
            case 1:
                new->x *= -1;
                break;
            case 2:
                new->x *= -1;
                new->y *= -1;
                break;
            case 3:
                new->y *= -1;
                break;
        }
        if(copycheck(a,new)==0){
            free(new);
        }
        else{
            if(a==NULL){
                a=(struct list*)malloc(sizeof(struct list));
                a->p=new;
                a->next=NULL;
                b=a;
            }
            else{
                b->next=(struct list*)malloc(sizeof(struct list));
                b=b->next;
                b->p=new;
                b->next=NULL;
            }
            i++;
        }
    }
    return a->p;
}

int copycheck(struct list* a, struct node*b){
    struct list* c=a;
    int i=0;
    while(c!=NULL){
        if(c->p->x==b->x && c->p->y==b->y){
            return 0;
        }
        else{
            c=c->next;
        }
        i++;
    }
    return 1;
}


