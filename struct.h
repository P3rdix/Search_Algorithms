#ifndef STRUCT
#define STRUCT

struct node{
    int x,y,val,s;
    int* node;
};

struct path{
    int s;
    int* p;
    struct path* next;
};

#endif