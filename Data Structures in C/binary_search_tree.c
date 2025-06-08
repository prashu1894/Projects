#include <stdio.h>
#include <stdlib.h>

struct BST {
    int value;
    struct BST* left;
    struct BST* right;
};

struct Queue {
    struct BST* node;
    struct Queue* next;
};

struct BST * create_node(int val) {
    struct  BST* newnode = (struct BST*)malloc(sizeof(struct BST));
    newnode->value = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void  inorder_traversal(struct BST* root) {
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}
void  preorder_traversal(struct BST* root) {
    if(root == NULL)
        return;
    printf("%d ", root->value);
    inorder_traversal(root->left);
    inorder_traversal(root->right);
}

void  postorder_traversal(struct BST* root) {
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    inorder_traversal(root->right);
    printf("%d ", root->value);
}

struct Queue* create_queue_node(struct BST* node) {
    struct Queue* newnode = (struct Queue*)malloc(sizeof(struct Queue));
    newnode->node = node;
    newnode->next = NULL;
}
void breadth_first_traversal(struct BST* root) {
    if(root == NULL)
        return;
    struct Queue* head  = NULL;
    
    return;
}
struct BST* insert_child(struct BST*root, int val) {
    if(root == NULL){
        return create_node(val);
    }
    if(val < root->value) {
        root->left = insert_child(root->left, val);
    } else {
        root->right = insert_child(root->right, val);
    }
    return root;
}

struct BST* search_node(struct BST* root, int val) {
    if(root == NULL || root->value == val) {
        return root;
    }
    if (root->value > val) {
        return search_node(root->left, val);
    } else {
        return search_node(root->right, val);
    }
}

int main() {
    struct BST *root = NULL;
    root = insert_child(root, 10);
    inorder_traversal(root);
    insert_child(root, 20);
    printf("\n");
    preorder_traversal(root);
    insert_child(root, 30);
    insert_child(root, 25);
    printf("\n");
    insert_child(root, 5);
    insert_child(root, 1);
    inorder_traversal(root);
    printf("\n");
    
    if(search_node(root, 10)) {
        printf("Entry present");
    } else {
        printf("Entry not present");
    }
    return 0;
}