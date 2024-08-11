#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node * createNode(int data);

void preorder(struct node* root);
void postorder(struct node * root);
void inorder(struct node * root);

int main(){
    struct node* p = createNode(7);
    struct node* p1 = createNode(2);
    struct node* p2 = createNode(1);
    struct node* p3 = createNode(0);
    struct node* p4= createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder\n");
    preorder(p);
    printf("\n"); 

    printf("\nPostorder\n");
    postorder(p);
    printf("\n");

    printf("\nInorder\n");
    inorder(p);
    printf("\n");
    
    return 0;
}

struct node * createNode(int data){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));

    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorder(struct node* root){
    if (root != NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node * root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void inorder(struct node * root){
    if (root != NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}