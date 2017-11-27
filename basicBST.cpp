#include<iostream>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};
//Creating a new node
struct node* newNode(int n) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->left = temp->right = NULL;
    return temp;
}
//minimum value in the tree
struct node* minValueNode(struct node* temp) {
    while(temp->left != NULL)
        temp = temp->left;
    return temp;
}
//maximum value in the tree
struct node* maxValueNode(struct node* temp) {
    while(temp->right != NULL)
        temp = temp->right;
    return temp;
}
//Insert function
struct node* insertNode(struct node* temp, int key) {
    if(temp == NULL) return newNode(key);   //Insert node at right place

    if(key > temp->data)
        temp->right = insertNode(temp->right, key);
    else
        temp->left = insertNode(temp->left, key);

    return temp;
}

/*Deletion of a node
1) Node to be deleted is leaf: Simply remove from the tree.

              50                            50
           /     \         delete(20)      /   \
          30      70       --------->    30     70
         /  \    /  \                     \    /  \
       20   40  60   80                   40  60   80
2) Node to be deleted has only one child: Copy the child to the node and delete the child

              50                            50
           /     \         delete(30)      /   \
          30      70       --------->    40     70
            \    /  \                          /  \
            40  60   80                       60   80
3) Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor
to the node and delete the inorder successor. Note that inorder predecessor can also be used.

              50                            60
           /     \         delete(50)      /   \
          40      70       --------->    40    70
                 /  \                            \
                60   80                           80
*/
struct node* deleteNode(struct node* root, int n) {
    if(root == NULL) return root;   //return if empty tree
    //find the right node to be deleted
    if(root->data > n)
        root->left = deleteNode(root->left, n);
    else if(root->data < n)
        root->right = deleteNode(root->right, n);
    else {  //node found, arranging the nodes & deleting the node
        if(root->left == NULL) {    //node with one child or no childs
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        else {  //finding the successor of deleting node, replacing root & deleting the successor.
            struct node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
}

//Inorder traversal of the tree
void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
//Preorder traversal of the tree
void preorder(struct node* root) {
    if(root != NULL) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
//Postorder traversal of the tree
void postorder(struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main() {

    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 20);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 70);
    insertNode(root, 80);

    inorder(root);
    cout<<endl;
    //preorder(root);
    //cout<<endl;
    //postorder(root);
    //cout<<endl;\

    deleteNode(root, 50);
    cout<<"Inorder traversal after deleting 50: ";
    inorder(root);

    return 0;
}

