struct node{
    int value;
    struct node * next;
};


struct root{
    //the next null node is given by the length;
    //eg if lengt = 0 is the 0th node is null so the list is empty
    struct node * address[1000];
    int length;
    struct node *list;
};


typedef struct root root;
typedef struct node node;

node * newNode(int);

void insert(root *, int);

int find(root, int n);
    

int delete(root, int);
    
int printindex(root, int);
    



