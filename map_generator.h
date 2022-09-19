#ifndef MAP
#define MAP
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"


void create_edge(struct node*,int,int,int);
void xy(struct node*,int,int);

struct node* map_generator(int no_nodes,int no_paths, int max_x, int max_y){

    struct node* map = (struct node*)malloc(sizeof(struct node)*no_nodes);

    int m[2*max_x][2*max_y];
    for(int i = 0;i<2*max_x;i++)
    {
        for(int j = 0;j<2*max_y;j++)
        {
            m[i][j]=0;
        }
    }

    m[0][0]=1;
    int i = 0;
    while(i<no_nodes)
    {
        (map+i)->val = i+1;
        (map+i)->x = 0;
        (map+i)->y = 0;
        while(m[max_x + (map+i)->x][max_y + (map+i)->y] != 0){
            xy((map+i),max_x,max_y);
        }
        m[max_x + (map+i)->x][max_y + (map+i)->y] = 1;
        i++;
        create_edge(map+i-1,i,no_nodes,no_paths);
    }
    return map;
}

void create_edge(struct node* a, int d, int size, int n){
    //Randomly assigns upto n nodes as edges to the current node
    int o = size-d;
    if(o < 1){
        a->node = NULL;
        a->s = 0;
    }
    int r = ((o > n)?(n+1):(o)+1);
    r = rand()%r;
    int m[r];
    a->s = r;
    if(r == 0){
        a->node = NULL;
    }
    else{
        a->node = (int*)malloc(sizeof(int)*r);
    }
    while(r != 0){
        r--;
        *((a->node)+r) = d + rand()%(o);
        for(int i = 0;i<(a->s-r-1);i++){
            if(m[i] == *(a->node+r)){
                r++;
                break;
            }
        }
        m[(a->s-r-1)] = *(a->node+r);
    }
    return;
}

void xy(struct node* a, int x, int y){
    //Initializes the x and y values of a given node.
    a->x = rand()%x;
    a->y = rand()%y;
    int t = rand()%4;
    if(t%2==0){
        a->x *= -1;
    }
    if(t<2){
        a->y *= -1;
    }
    return;
}

void map_write(FILE* fptr,struct node* map, int no_nodes){
    printf("\nHello");
    for(int i = 0;i<no_nodes;i++){
        fprintf(fptr,"%d=%d=%d=%d\n",(map+i)->val,(map+i)->s,(map+i)->x,(map+i)->y);
        for(int j = 0;j<(map+i)->s;j++){
            fprintf(fptr,"%d=",*((map+i)->node+j));
        }
        fprintf(fptr,"\n");
    }
    printf("\nGoodbye");
    return;
}

int getint(FILE*,int*);

struct node* map_read(FILE* fptr, int no_nodes){
    printf("hello");
    if(fptr == NULL){
        return NULL;
    }
    struct node* map = (struct node*)malloc(sizeof(struct node*)*no_nodes);
    int r = 0;
    int i = 0;
    char c;
    while(r<no_nodes){
        (map+r)->val = getint(fptr,&i);
        (map+r)->s = getint(fptr,&i);
        (map+r)->x = getint(fptr,&i);
        (map+r)->y = getint(fptr,&i);
        (map+r)->node = (int*)malloc(sizeof(int)*(map+r)->s);
        for(int j = 0;j<(map+r)->s;j++){
            *((map+r)->node+j) = getint(fptr,&i);
        }
        i++;
        r++;
    }
    printf("bye1");
    fclose(fptr);
    printf("\nbye2");
    return map;
}

int getint(FILE* fptr, int* seek){
    fseek(fptr,*seek,SEEK_SET);
    char c;
    fscanf(fptr,"%c",&c);
    int i = 0,j = 1;
    while(c != '\n' && c != '='){
        if(c == '-'){
            j = -1;
        }
        else{
            i = 10*i;
            i += ((int)c - 48);
        }
        *seek +=1;
        fseek(fptr,*seek,SEEK_SET);
        fscanf(fptr,"%c",&c);
    }
    *seek +=1;
    return j*i;
}

#endif
