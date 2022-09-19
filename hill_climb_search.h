#ifndef HILL
#define HILL

#include "struct.h"
#include <math.h>

int choose_heuristic();
void closest_value_node_arrange(struct node*,int);
void closest_value_goal_arrange(struct node*,int,int);
void euclidean_distance_arrange(struct node*,int,int);
void manhattan_distance_arrange(struct node*,int,int);
void highest_value_first_arrange(struct node*,int);
void lowest_value_first_arrange(struct node*,int);
void swap(int*,int*);

int hill_climb_search(struct node* map,int start,int goal,int size, struct path* p){
    int a = choose_heuristic();
    switch(a){
        case 1:
            closest_value_node_arrange(map,size);
            break;
        case 2:
            closest_value_goal_arrange(map,size,goal);
            break;
        case 3:
            euclidean_distance_arrange(map,size,goal);
            break;
        case 4:
            manhattan_distance_arrange(map,size,goal);
            break;
        case 5:
            highest_value_first_arrange(map,size);
            break;
        case 6:
            lowest_value_first_arrange(map,size);
            break;
    }
    return depth_first_search(map,start,goal,1,p);
}

int choose_heuristic(){
    int i = 0;
    while(i<1 || i>6){
        printf("\nChoose heuristic. Press:\n1. Closest value to node first\n2. Closest value to Goal\n3. Euclidean distance\n4. Manhattan distance\n5. highest value first\n6. lowest value first\nEnter: ");
        scanf("%d", &i);
    }
    return i;
}

void closest_value_node_arrange(struct node *map, int size){
    for(int i = 0;i<size;i++){
        int s = (map+i)->s;
        int *a = (map+i)->node;
        int b[s];
        for(int j = 0; j<s; j++){
            b[j] = *(a+j)-((map+i)->val-1);
        }
        for(int j = 1; j<s; j++){
            int t = j;
            while(b[t]<b[t-1] && t-1>=0){
                swap(b+t,b+t-1);
                swap(a+t,a+t-1);
                t--;
            }
        }
    }
}

void closest_value_goal_arrange(struct node *map, int size, int goal){
    for(int i = 0;i<size;i++){
        int s = (map+i)->s;
        int *a = (map+i)->node;
        int b[s];
        for(int j = 0; j<s; j++){
            b[j] = *(a+j)-(goal);
            b[j] *=-1;
        }
        for(int j = 1; j<s; j++){
            int t = j;
            while(b[t]<b[t-1] && t-1>=0){
                swap(b+t,b+t-1);
                swap(a+t,a+t-1);
                t--;
            }
        }
    }
}

void euclidean_distance_arrange(struct node *map, int size, int goal){
    for(int i = 0;i<size;i++){
        int s = (map+i)->s;
        int *a = (map+i)->node;
        float b[s];
        printf("\nvalues =");
        for(int j = 0; j<s; j++){
            int x = ((map+*(a+j))->x) - ((map+goal)->x);
            int y = ((map+*(a+j))->y) - ((map+goal)->y);
            b[j] = sqrt((x*x)+(y*y));
            printf("\t%f",b[j]);
        }
        for(int j = 1; j<s; j++){
            int t = j;
            while(b[t]<b[t-1] && t-1>=0){
                *(b+t) += *(b+t-1);
                *(b+t-1) -= *(b+t);
                
                *(b+t-1) *= (*(b+t-1) == 0)?(1):(-1);
                *(b+t) -= *(b+t-1);
                swap(a+t,a+t-1);
                t--;
            }
        }
        printf("\nValues 2 =");
        for(int j = 0;j<s;j++){
            printf("\t%f",b[j]);
        }
    }
}

void manhattan_distance_arrange(struct node *map, int size, int goal){
    for(int i = 0;i<size;i++){
        int s = (map+i)->s;
        int *a = (map+i)->node;
        int b[s];
        for(int j = 0; j<s; j++){
            int x = ((map+*(a+j))->x) - ((map+goal)->x);
            x *= (x>0)?(1):(-1);
            int y = ((map+*(a+j))->y) - ((map+goal)->y);
            y *= (y>0)?(1):(-1);
            b[j] = x+y;
        }
        for(int j = 1; j<s; j++){
            int t = j;
            while(b[t]<b[t-1] && t-1>=0){
                swap(b+t,b+t-1);
                swap(a+t,a+t-1);
                t--;
            }
        }
    }
}

void highest_value_first_arrange(struct node *map, int size){
    for(int i = 0;i<size;i++){
        int s = (map+i)->s;
        int *a = (map+i)->node;
        for(int j = 1; j<s; j++){
            int t = j;
            while(*(a+t)>*(a+(t-1)) && t-1>=0){
                swap(a+t,a+t-1);
                t--;
            }
        }
    }
}

void lowest_value_first_arrange(struct node *map, int size){
    for(int i = 0;i<size;i++){
        int s = (map+i)->s;
        int *a = (map+i)->node;
        for(int j = 1; j<s; j++){
            int t = j;
            while(*(a+t)<*(a+(t-1)) && t-1>=0){
                swap(a+t,a+t-1);
                t--;
            }
        }
    }
}

void swap(int*a,int*b){
    *a += *b;
    *b -= *a;
    *b *= -1;
    *a -= *b;
    return;
}

#endif