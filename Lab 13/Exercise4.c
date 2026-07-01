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

int height(struct Node* root){
    if(!root) return 0;
    int l=height(root->left);
    int r=height(root->right);
    return (l>r?l:r)+1;
}

int main(){
    struct Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);

    printf("Height: %d",height(root));
    return 0;
}