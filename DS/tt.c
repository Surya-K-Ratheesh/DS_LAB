#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node * createNode(int data);
void inorder(struct node* root);
void preorder(struct node* root);
void postorder(struct node* root);

int main(){
    int ch;
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    while(ch != 4){
        printf("\n\t\t********MENU********\n");
        printf("\n1. INORDER \n2. PREORDER \n3. POSTORDER \n4. EXIT \n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d",&ch);

        switch(ch){
            case 1 : inorder(p);
                break;

            case 2 : preorder(p);
                break;

            case 3 : postorder(p);
                break;

            case 4 : printf("\nEXITTED\n");
                break;

            default : printf("\nENTER A VALID CHOICE\n");
        }
    }

    printf("\n");

    return 0;
}

struct node * createNode(int data){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL; 
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}