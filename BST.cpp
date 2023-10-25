#include "BST.h"

BST_Node::BST_Node(int x){
    data = x;
    left = right = NULL;
}

BST_Node::~BST_Node(){
}

BST::~BST(){
    destroyHelper(root);
}

void BST::destroyHelper(BST_Node* node){
    if(node != NULL){        
        destroyHelper(node->left);
        destroyHelper(node->right);
        delete node;
    }
}

BST::BST(){
   root = NULL;
   traversalCount = 0;
}

void BST::insertHelper(BST_Node* &node, int i){
    traversalCount++;
    if (node == NULL) {
        node = new BST_Node(i);
        node->left = NULL;
        node->right = NULL;
    }
    else if(i < node->data){
        if(node->left != NULL){
            insertHelper(node->left, i);
        }
        else{
            traversalCount++;
            node->left = new BST_Node(i);
        }
    }
    else if(i > node->data){
        if(node->right != NULL){
            insertHelper(node->right, i);
        }
        else{
            traversalCount++;
            node->right = new BST_Node(i);
        }
    }
}

bool BST::deleteNodeHelper(BST_Node* &root, int val){
    traversalCount++;
    //BST_Node to delete not found
    if(root == NULL) {
        return false;
    }
    else{
        if(root->data < val){
            deleteNodeHelper(root->right, val);
        }
        else if(root->data > val){
            deleteNodeHelper(root->left, val);
        }
        else if (root->left != NULL && root->right != NULL){
            //case 2 - node found 2 children
            BST_Node* minRightSubtree = removeMin(root, root->right);
            root->data = minRightSubtree->data; // copy data
            delete minRightSubtree;
        }
        else{
            BST_Node* trash = root;
            if(root->left != NULL){
                root = root->left;
            }
            else{
                root = root->right;
            }
            delete trash;
        }
        return true;
    }
}

BST_Node* BST::removeMin(BST_Node * parent, BST_Node * node){
    traversalCount++;
    if(node != NULL){
        if(node->left == NULL){ //found min value
            if(node == parent->left){
                parent->left = node->right;
            }
            else if(node == parent->right){
                parent->right = node->right;
            }
            return node;
        }
        else{
            //recursively go to left most child in right subtree
            return removeMin(node, node->left);
        }
    }
    else{
        //subtree is empty
        return NULL;
    }
}
bool BST::searchNodeHelper(BST_Node* root, int key){
    traversalCount++;
    if(root == NULL){
        return false;
    } 
    else if(root->data == key){
        return true;
    }
    if(root->data < key){
        return searchNodeHelper(root->right, key);
    }
    else{
        return searchNodeHelper(root->left, key);
    }

}

void BST::insert(int val){  
    return (insertHelper(root, val));
}

bool BST::searchNode(int val){  
    return (searchNodeHelper(root, val));
}

bool BST::deleteNode(int val){  
    return (deleteNodeHelper(root, val));
}

void BST::print()
{
   // Call tree printing function
   printHelper(root);
   cout << endl;
}

void BST::printHelper(BST_Node * root)
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
    //print null child
    
    cout << "]";
}