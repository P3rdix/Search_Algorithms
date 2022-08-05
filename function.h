#ifndef FUNCTION_H
#define FUNCTION_H

struct edge;

struct node
{
    //map node;
    int x,y,val;
    struct edge* next;
};

struct edge
{
    //Struct denoting a edge connecting two vertices
    //two directional for now ig?
    int wt;
    struct node *b;
    struct edge* next;
};

struct path
{
    //The final path which we get from a search
    struct node *now;
    struct path *next;
    struct path *prev;
};

#include "map_generator.c"
struct node* map_generator(int,int,int,int,int);
struct path* british_museum(struct node* map_start,int goal_value);
struct path* depth_first(struct node* map_start,int goal_value);
struct path* breadth_first(struct node* map_start,int goal_value);
struct path* hill_climb(struct node* map_start,struct node* goal);
struct path* beam_search(struct node* map_start,struct node* goal, int max_width);
struct path* oracle(struct node* map_start,struct path* verify);
struct path* branch_and_bound(struct node* map_start,int goal_value);
struct path* branch_and_bound_extended_list(struct node* map_start,int goal_value);
struct path* branch_and_bound_heuristics(struct node* map_start,struct node* goal);
struct path* A_star(struct node* map_start,struct node* goal);
struct path* best_first_search(struct node* map_start,struct node* goal);

#endif