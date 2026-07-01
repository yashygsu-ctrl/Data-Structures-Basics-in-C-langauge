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

void printLeaf(struct Node* root){
    if(root){
        if(!root->left && !root->right)
            printf("%d ",root->data);
        printLeaf(root->left);
        printLeaf(root->right);
    }
}

int main(){
    struct Node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);

    printf("Leaf Nodes: ");
    printLeaf(root);
    return 0;
}