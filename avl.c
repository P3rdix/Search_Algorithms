#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"


struct tree{
    struct node* p;
    struct tree *less,*eql,*grt;
};

struct tree* insert(struct node* a, struct tree* treeptr){
    struct tree* start=treeptr;
    struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
    temp->p=a;
    temp->grt=NULL;
    temp->less=NULL;
    temp->eql=NULL;
    while(start->p->val!=a->val || (start->grt==NULL && start->less==NULL)){
        (start->p->x>a->x)?(start=start->less):(start=start->grt);
    }
    if(start->p->val==a->val){
        while(start->eql!=NULL){
            start=start->eql;
        }
        start->eql=temp;
    }
    else{
        (start->p->x>a->x)?(start->less=temp):(start->grt=temp);
        avl(treeptr);
    }
    return treeptr;
}

int avl(struct tree *p){
    if(p==NULL){
        return 0;
    }
    int r=avl(p->less),l=avl(p->grt),x;
    if(l<0 && r<0){
        x=-1*(l-r);
        if(x>2){
            
        }
    }
    else if(l>0 && r<0){
        x=l+r;
    }
    else if(l<0 && r<0){
        x=l+r;
    }
    else{
        x=l-r;
    }

    if(r-l==2){
        
    }
}