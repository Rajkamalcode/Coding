#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
    int height;
    struct tree* visited;
};

struct tree* create(int d) {
    struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->data = d;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


int h=0;
struct tree* insert(struct tree* root, int key) {
    if (root == NULL) {
        return create(key);
    }

    if (root->data >= key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    root->height = 1 + ((height(root->left) > height(root->right)) ? height(root->left) : height(root->right));

    int balance=calcubalance(root);

    if(balance>1 && key<=root->left->data){
        return rightrotate(root);
    }

    if(balance<-1 && key>=root->right->data){
        return leftrotate(root);
    }

    if(balance>1 && key>=root->left->data){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<-1 && key<=root->right->data){
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

int rightrotate(struct tree *root){
    struct tree *newroot=root->left;
    root->left=newroot->left;
    newroot->right=root;
    return newroot;
}

int leftrotate(struct tree *root){
    struct tree *newroot=root->right;
    newroot->left=root;
    newroot->right=root->right;
    return newroot;

}

void inorder(struct tree* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);

        preorder(root->right);
    }
}

void postorder(struct tree* root) {

    if (root != NULL) {

        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
//inorder successor finder, its the bst prop plus logically finding a smallest element in right sub tree does the job as the new root for the deleted.
struct tree* minvalue(struct tree* root){
    struct tree *current=root;

    while(current!=NULL&&current->left!=NULL){
        current=current->left;
    }
    return current;
}

struct tree* delete(struct tree* root, int value){
    if(root==NULL){
        return root;
    }
    //traversing
    if(value<root->data){
        root->left=delete(root->left, value);
    }
    else if(value>root->data){
        root->right=delete(root->right, value);
    }

    else{
            //deleting left sub tree with no childern switching link to next right
        if(root->left==NULL){
            struct tree *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct tree *temp=root->left;
            free(root);
            return temp;
        }

        //deleting if two childern ie right and left !=NULL
        else{

            struct tree *temp=minvalue(root->right);

            root->data=temp->data;

            root->right=delete(root->right, temp->data);

        }

    }
    return root;

}
int pos_left=0;int pos_right=0;int pos=0;
struct tree* search(struct tree* root, int x){

    if(root==NULL){
        printf("not found");
        return root;
    }

    if(root->data==x){
        printf("element found at pos %d", pos);
    }
    else if(x<root->data){
        root->left=search(root->left,x);
    }
    else if(x>root->data){
        root->right=search(root->right,x);
    }

}

void DFS(struct tree *root){
    if(root==NULL){
        return;
    }

    int visited=1;
    struct tree *current=root->left;
    while(current!=NULL){
        if(current->visited==0){
            DFS(current);
        }
        current=current->right;
    }
    printf("%d ", root->data);
}

int height(struct tree *root){
    int height_left=0,height_right=0;
    if(root==NULL){
        return -1;
    }
    else{
        height_left=height(root->left);
        height_right=height(root->right);

        root->height = 1+(height_left>height_right ? height_left:height_right);
        return root->height;
    }
}

int calcubalance(struct tree *root){
    if(root==NULL){
        return -1;
    }
    else{
        int h_left=height(root->left);
        int h_right=height(root->right);
        return (h_left- h_right);
    }
}

void Balance(struct tree *root){
    if(root==NULL){
        return;
    }
    Balance(root->left);
    printf("element %d height is %d\n", root->data,calcubalance(root));
    Balance(root->right);
}

int main() {

    printf("Enter root: ");
    int value;
    scanf("%d", &value);
    struct tree* root = create(value);
    int n = 6;
    while (n--) {
        printf("Enter element: ");
        scanf("%d", &value);
        insert(root, value);
    }
    printf("inorder: ");
    inorder(root);
    printf("\n");

    printf("preorder: ");
    preorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");

    //printf("Deleting element\n");
    //delete(root, 10);
    //inorder(root);

    height(root);
    Balance(root);
    //printf("searching\n");
    //search(root, 8);
    //DFS(root);
    return 0;
}
