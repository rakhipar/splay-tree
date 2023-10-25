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
class Node{
public:
    Node *left, *right;
    Node *parent;
    int data;
    Node(int);
    ~Node();
};


class Splay{
private:
    Node* root;
    int traversalCount;
    void destroyHelper(Node*);

public:
    Splay();
    ~Splay();
    void insertHelper(Node* &, int);
    void searchNodeHelper(Node*, int);
    void deleteNodeHelper(Node* &, int);
    Node* getMax(Node*);
    void insert(int);
    void searchNode(int);
    void deleteNode(int);
    int getTraversalCount(){return traversalCount;}
    void print();
    void printHelper(Node*);
    void DFS(Node *);
    void rightRotate(Node*);
    void leftRotate(Node*);
    void splayFunction(Node *);
};