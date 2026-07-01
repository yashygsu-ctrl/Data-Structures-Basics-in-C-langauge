#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node* createNode(int data){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}

struct Node* build(){
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d",&x);
    if(x==-1) return NULL;
    struct Node* root=createNode(x);
    printf("Left of %d\n",x);
    root->left=build();
    printf("Right of %d\n",x);
    root->right=build();
    return root;
}

void inorder(struct Node* root){
    if(root){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node* root=build();
    printf("Inorder: ");
    inorder(root);
    return 0;
}