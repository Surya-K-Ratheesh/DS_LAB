#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data);

int main(){
    struct node *p = createNode(2); //Root node
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);

    // Linking root node with children
    p->left = p1;
    p->right = p2;

    return 0;
}


struct node* createNode(int data){
    struct node* n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}






//     Constructing the root node
//     p = (struct node *)malloc(sizeof(struct node));
//     p->data = 2;
//     p->left = NULL;
//     p->right = NULL;

//     // Constructing the 1st node
//     struct node* p1;
//     p1 = (struct node *)malloc(sizeof(struct node));
//     p->data = 1;
//     p1->left = NULL;
//     p1->right = NULL;

//     // Constructing the 2nd node
//     struct node* p2;
//     p2 = (struct node *)malloc(sizeof(struct node));
//     p->data = 2;
//     p2->left = NULL;
//     p2->right = NULL;


//     // Linking the root node with left and right children
//     p->left = p1;
//     p->right = p2;