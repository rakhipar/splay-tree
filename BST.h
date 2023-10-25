#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <chrono>

using std::string;
using std::endl;
using std::cout;

using namespace std;
class BST_Node{
public:
    BST_Node *left, *right;
    int data;
    BST_Node(int);
    ~BST_Node();
};

class BST{
private:
    BST_Node* root;
    int traversalCount;
    void destroyHelper(BST_Node*);
public:
    BST();
    ~BST();
    void insertHelper(BST_Node* &, int);
    bool searchNodeHelper(BST_Node*, int);
    bool deleteNodeHelper(BST_Node* &, int);
    BST_Node* removeMin(BST_Node*, BST_Node*);
    void insert(int);
    bool searchNode(int);
    bool deleteNode(int);
    int getTraversalCount(){return traversalCount;}
    void print();
    void printHelper(BST_Node*);
    void DFS(BST_Node *);
};