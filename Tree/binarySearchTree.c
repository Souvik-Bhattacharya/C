#include<stdio.h>
#include<stdlib.h>

struct bst{
    int data;
    struct bst *left;
    struct bst *right;
};
typedef struct bst node;

node *create(int data){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node *root, int data){
    if(root == NULL) return create(data);
    else{
        if(data == root->data) printf("%d is already exist in the binary search tree!\n",data);
        else if(data < root->data) root->left = insert(root->left, data);
        else if(data > root->data) root->right = insert(root->right, data);
    }
    return root;
}

void display(node *root){
    if(root != NULL){
        display(root->left);
        printf("%d ",root->data);
        display(root->right);
    }
    return;
}

void search(node *root, int val){
    if(root == NULL) printf("%d is not present in the BST!\n", val);
    else{
        if(val == root->data) printf("%d is present in the BST!\n", val);
        else if(val < root->data) search(root->left, val);
        else search(root->right, val);
    }
    return;
}

node *findPre(node *root){
    root = root->left;
    while(root->right != NULL) root = root->right;
    return root;
}

node *delete(node *root, int data){
    if(root == NULL) printf("%d is not present in the BST!\n",data);
    else{
        if(data < root->data) root->left = delete(root->left, data);
        else if(data > root->data) root->right = delete(root->right, data);
        else{
            if(root->right == NULL && root->left == NULL){
                free(root);
                return NULL;
            }
            else if(root->left == NULL){
                node *temp = root;
                root = root->right;
                free(temp);
            }
            else{
                node *pre = findPre(root);
                root->data = pre->data;
                root->left = delete(root->left, pre->data);
            }
        }
    }
    return root;
}

int main(){
    int choice, val;
    node *root = NULL;
    L:
    printf("Enter 1 to insert a new node, 2 for deletion, 3 for searchig a node & 4 for exit:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the new data:");
            scanf("%d",&val);
            root = insert(root, val);
            printf("The inorder view of the BST is: ");
            if(root != NULL) display(root);
            else printf("Tree is empty!");
            printf("\n");
            goto L;
        case 2:
            printf("Enter the data for for deletion:");
            scanf("%d",&val);
            root = delete(root, val);
            printf("The inorder view of the BST is: ");
            if(root != NULL) display(root);
            else printf("Tree is empty!");
            printf("\n");
            goto L;
        case 3:
            printf("Enter the data for searching:");
            scanf("%d", &val);
            search(root, val);
        case 4:
            printf("Program ended...");
            break;
    }
    return 0;
}