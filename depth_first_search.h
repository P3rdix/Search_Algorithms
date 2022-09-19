#ifndef DFS
#define DFS

int depth_first_search(struct node* map, int crnt, int goal, int j, struct path* p){
    printf("\n%d",crnt);
    /*j starts at 1
    d starts at user initialized value
    goal is user based value*/
    if(crnt == goal){
        p->p = (int*)malloc(sizeof(int)*j);
        p->s = j;
        *(p->p+p->s-1) = crnt;
        return 1;
    }
    for(int i = 0;i<(map+crnt)->s;i++){
        int t = depth_first_search(map,*(((map+crnt)->node)+i),goal,j+1,p);
        if(t == 1){
            *(p->p+j-1) = crnt;
            return t;
        }
    }
    if(p->s == 0){
        return 0;
    }
    return 1;
}

#endif 