#include "struct.h"
#include <stdio.h>

int square_root(int);
void swap(struct node*, struct node*);
int disp(int,int,struct node*,int,int);

int hash_keys(int no_nodes){
    int a = square_root(no_nodes);
    int i = 1,j = a,k=no_nodes;
    while(i<=(a/5)){
        int r = (i%2==0)?(a - i/2):(a + i/2);
        if(no_nodes%r == 0){
            j = r;
            break;
        }
        else if(no_nodes%r <= k){
            j = r;
            k = no_nodes%r;
        }
        i++;
    }
    return j;
}

void place(struct node* new, struct node* mx, int size, int hash, int x_r, int y_r){
    int a = disp(hash,size/hash,new,x_r,y_r);
    int b = 0;
    while(b < size){
        if((mx+a+b)->val==0){
            if(b==0){
                (mx+a)->val = new->val;
                (mx+a)->x = new->x;
                (mx+a)->y = new->y;
                (mx+a)->next = new->next;
            }
            else{
                struct edge* temp = (struct edge*)malloc(sizeof(struct edge));
                struct edge* temp2 = (mx+a)->next;
                temp->node = (mx+a+b);
                temp->next = NULL;
                struct edge* t2 = (mx+a)->next;
                if(temp2 == NULL){
                    (mx+a)->next =temp;
                    temp2 = temp;
                }
                else{
                    while(t2->next!=NULL){
                        t2 = t2->next;
                    } 
                    t2->next = temp;
                }
                (mx+a+b)->val = new->val;
                (mx+a+b)->x = new->x;
                (mx+a+b)->y = new->y;
                temp2->node = (mx+a);
                temp2->next = NULL;
                (mx+a+b)->next = temp2;
            
            }
            free(new);
            return;
        }
        else{
            if(b == 0){
                if(a!= disp(hash,size/hash,(mx+a),x_r,y_r)){
                    swap(new, (mx+a+b));
                }
            }
        }
        b++;
        if(a+b==size){
            b = -a;
        }
    }
    return;
}

int copycheck(struct node* new, struct node* mx, int hash, int size, int x_r, int y_r){
    int a = disp(hash,size/hash,new,x_r,y_r);
    if((mx+a)->val!=0 && (a == disp(hash,size/hash,(mx+a),x_r,y_r))){
        if(new->x == (mx+a)->x && new->y == (mx+a)->y){
            return 0;
        }
        else{
            struct edge* temp = (mx+a)->next;
            while(temp != NULL){
                if(temp->node->x == new->x && temp->node->y == new->y){
                    return 0;
                }
                temp = temp->next;
            }
        }
    }
    return 1;
}

int square_root(int a){
    int i = 0;
    while(i*i<=a){
        i++;
    }
    return i-1;
}

void swap(struct node* a, struct node* b){
    int x = a->x;
    int y = a->y;
    int val = a->val;
    struct edge* next = a->next;
    a->x = b->x;
    a->y = b->y;
    a->val = b->val;
    a->next = b->next;
    b->x = x;
    b->y = y;
    b->val = val;
    b->next = next;
    return;
}

int disp(int x, int y, struct node* new, int x_r, int y_r){
    int i = (x/2.0 + (x/2.0)*((new->x/(x_r*1.0))));
    int j = (y/2.0 + (y/2.0)*((new->y/(y_r*1.0))));
    int a = floor(i + x*j);

    return a;
}