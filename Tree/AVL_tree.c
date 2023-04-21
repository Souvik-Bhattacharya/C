#include<stdio.h>
#include<stdlib.h>

struct AVL{
    int data;
    struct AVL *left;
    struct AVL *right;
    int height;
};
typedef struct AVL node;

node *create(int data){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

void search(node *root, int val){
    if(root == NULL) printf("%d is not present in the AVL tree!\n\n", val);
    else{
        if(val == root->data) printf("%d is present in the AVL tree!\n\n", val);
        else if(val < root->data) search(root->left, val);
        else search(root->right, val);
    }
    return;
}

void inOrder(node *root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
    return;
}

int getHeight(node *root){
    if(root == NULL) return 0;
    else return root->height;
}

int getBalanceFactor(node *root){
    if(root == NULL) return 0;
    else return (getHeight(root->right) - getHeight(root->left));
}

int max(int x, int y){
    if(x >= y) return x;
    else return y;
}

void printLevel(node* root, int level)
{
    if (root == NULL) return;
    else if (level == 1) printf("%d ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
 
void levelOrder(node* root)
{
    int h = getHeight(root);
    int i;
    for (i = 1; i <= h; i++) {
        printLevel(root, i);
        printf("\n");
    }
}
node *leftRotate(node *root){
    node *y = root->right;
    node *T2 = y->left;
    y->left = root;
    root->right = T2;
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    return y;
}

node *rightRotate(node *root){
    node *y = root->left;
    node *T2 = y->right;
    y->right = root;
    root->left = T2;
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    return y;
}

node *insert(node *root, int data){
    int bf;
    if(root == NULL) return create(data);
    else{
        if(data == root->data) printf("%d is already exist in the AVL tree!\n",data);
        else if(data < root->data) root->left = insert(root->left, data);
        else if(data > root->data) root->right = insert(root->right, data);
    }
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    bf = getBalanceFactor(root);
    if(bf < -1 && data < root->left->data) root = rightRotate(root);
    else if(bf > 1 && data > root->right->data) root = leftRotate(root);
    else if(bf < -1 && data > root->left->data){
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if(bf > 1 && data < root->right->data){
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    }
    return root;
}

node *findPre(node *root){
    root = root->left;
    while(root->right != NULL) root = root->right;
    return root;
}

node *delete(node *root, int data){
    int bf;
    if(root == NULL) printf("%d is not present in the AVL tree!\n",data);
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
    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    bf = getBalanceFactor(root);
    if(bf < -1 && data < root->left->data) root = rightRotate(root);
    else if(bf > 1 && data > root->right->data) root = leftRotate(root);
    else if(bf < -1 && data > root->left->data){
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    }
    else if(bf > 1 && data < root->right->data){
        root->right = rightRotate(root->right);
        root = leftRotate(root);
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
            if(root != NULL){
                printf("The levelorder view of the AVL tree is:\n");
                levelOrder(root);
            }
            else printf("Tree is empty!\n");
            printf("\n");
            goto L;
        case 2:
            printf("Enter the data for for deletion:");
            scanf("%d",&val);
            root = delete(root, val);
            if(root != NULL){
                printf("The levelorder view of the AVL tree is:\n");
                levelOrder(root);
            }
            else printf("Tree is empty!\n");
            printf("\n");
            goto L;
        case 3:
            printf("Enter the data for searching:");
            scanf("%d", &val);
            search(root, val);
            goto L;
        case 4:
            printf("The inorder view of the AVL tree is: ");
            inOrder(root);
            printf("\nProgram ended...");
            break;
    }
    return 0;
}