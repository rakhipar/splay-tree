#include "splay.h"

Node::Node(int x){
    data = x;
    left = right = NULL;
    parent = NULL;
}

Node::~Node(){
}

Splay::~Splay(){
    destroyHelper(root);
}

void Splay::destroyHelper(Node* node){
    if(node != NULL){        
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }
}

Splay::Splay(){
   root = NULL;
   traversalCount = 0;
}

void Splay::leftRotate(Node* x){//zag
    Node *y = x->right;
    if(y){
        x->right = y->left;
        if(y->left){
            y->left->parent = x;
        }
        y->parent = x->parent;
    }
    if(x==root){
        root = y;
        y->parent = NULL;
    }
    else if(x == x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    if(y){
        y-> left = x;
    }    
    x->parent = y;

}

void Splay::rightRotate(Node* x){//zig
    Node *y = x->left;
    if(y){
        x->left = y->right;
        if(y->right){
            y->right->parent = x;
        }
        y->parent = x->parent;
    }
    if(!x->parent){
        root = y;
        y->parent = NULL;
    }
    else if(x==x->parent->left){
        x->parent->left = y;
    }
    else{
        x->parent->right = y;
    }
    if(y){
        y->right = x;
    }
    x->parent = y;
}

void Splay::splayFunction(Node* x){
    if(x == root || x == NULL){
        return;
    }
    traversalCount++;

        //zig case
    if(x->parent == root){ 
        if(x->parent->left == x){
            rightRotate(x->parent);
        }
        else{
            leftRotate(x->parent);
        }
    }
    //zig zig case
    else if (x->parent->left == x && x->parent->parent->left == x->parent) {
        rightRotate(x->parent->parent);
        rightRotate(x->parent);
    } 
    else if (x->parent->right == x && x->parent->parent->right == x->parent) {//zag-zag
        leftRotate(x->parent->parent);
        leftRotate(x->parent);
    } 
    else if (x->parent->left == x && x->parent->parent->right == x->parent) { //zig-zag
        rightRotate(x->parent);
        leftRotate(x->parent);
    }
    else {//zag-zig
        leftRotate(x->parent);
        rightRotate(x->parent);
    }
    splayFunction(x);
}

void Splay::insert(int x){
    insertHelper(root, x);
}

void Splay::insertHelper(Node *& node, int x){
    traversalCount++;
    if(node == NULL){
        root = new Node(x);
        return;
    }
    if(node->left == NULL && node->data > x){
        node->left = new Node(x);
        node->left->parent = node;
        splayFunction(node->left);
    }
    else if (node->right == NULL && x > node->data){
        node->right = new Node(x);
        node->right->parent = node;
        splayFunction(node->right);
    }
    else if(x < node->data){
        insertHelper(node->left, x);
    }
    else if(x > node->data){
        insertHelper(node->right, x);
    }
    else{//already exists
        node->data = x;
        splayFunction(node);
    }
}

void Splay::searchNode(int x){
      searchNodeHelper(root, x);
}

void Splay::searchNodeHelper(Node* node, int x){
    traversalCount++;
    if(node->data == x){//search successful, splay node
        splayFunction(node);
        return;
    }
    if(node->left == NULL && x < node->data){//search unsucessful, splay last accessed node
        splayFunction(node);
    }
    else if(node->right == NULL && x > node->data){//search unsucessful, splay last accessed node
        splayFunction(node);
    }
    else if (x < node->data){
        searchNodeHelper(node->left, x);
    }
    else{
        searchNodeHelper(node->right, x);
    }
}

void Splay::deleteNode(int x){
    deleteNodeHelper(root, x);
}

void Splay::deleteNodeHelper(Node* & node, int x){
    traversalCount++;
    if(root == NULL){
        return;
    }
    searchNode(x);
    if(root->data != x){
        return;
    }
    Node* curr = root;
    if(root->left == NULL){
        root = root->right;
        delete curr;
        root->parent = NULL;
    }
    else if(root->right == NULL){
        root = root->left;
        delete curr;
        root->parent = NULL;
    }
    else{
        Node* l = root->left;
        Node* r = root->right;
        delete curr;
        root = l;
        splayFunction(getMax(l));
        root->right = r;
        r->parent = root;
        root->parent = NULL;
    }
}

Node* Splay::getMax(Node* node){
   while(node->right != NULL){
    traversalCount++;
    node = node->right;
   }
   return node;
}

void Splay::print()
{ 
   // Call tree printing function
   printHelper(root);
    cout << endl;
}

void Splay::printHelper(Node * root)
{
 if (root == NULL)
        return;
 
    // process root here (preorder)
    cout << " [" << root->data;

    // recur on left subtree
    printHelper(root->left);
    //print null child
    if(root->left && !root->right){
        cout << "[]";
    }
    if(root->right && !root->left){
        cout << "[]";
    }
    // recur on right subtree 
    printHelper(root->right);
    
    cout << "]"   ;
}