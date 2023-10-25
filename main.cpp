#include "main.h"

int main(int argc, const char * argv[]){
    if(argc < 2){
        throw std::invalid_argument("There are not at least two command line arguments.\n");
    }
    string inputFileName = argv[1];
    std::ifstream inputFile(inputFileName);

    /* - - - - - - - - - - - - - Testing Binary search tree - - - - - - - - - - - - */
    int BSTtime = 0;
    BST myBST;
    
    //testing BST insert
    int BST_insertinput = 0;
    string BST_insertline = "";
    getline(inputFile, BST_insertline);
    stringstream BST_insertss(BST_insertline);
    auto start1bst = std::chrono::steady_clock::now();
    while(BST_insertss >> BST_insertinput){
        myBST.insert(BST_insertinput); 
    }
    auto finish1bst = std::chrono::steady_clock::now();
    BSTtime+= std::chrono::duration_cast<std::chrono::nanoseconds>(finish1bst-start1bst).count();

    cout << endl << "Structure of initialized BST: " << endl;
    myBST.print();
    
    string BST_firstdump = "";
    getline(inputFile, BST_firstdump);

    //testing BST search
    string BST_searchline = "";
    int BST_searchinput = 0;
    getline(inputFile, BST_searchline);
    stringstream BST_searchss(BST_searchline);
    auto start2bst = std::chrono::steady_clock::now();
    while(BST_searchss >> BST_searchinput){
        myBST.searchNode(BST_searchinput);
    }
    auto finish2bst = std::chrono::steady_clock::now();
    BSTtime+= std::chrono::duration_cast<std::chrono::nanoseconds>(finish2bst-start2bst).count();

    string BST_seconddump = "";
    getline(inputFile, BST_seconddump);

    //testing BST delete
    string BST_deleteline = "";
    int BST_deleteinput = 0;
    getline(inputFile, BST_deleteline);
    stringstream BST_deletess(BST_deleteline);
    auto start3bst = std::chrono::steady_clock::now();
    while(BST_deletess >> BST_deleteinput){
        myBST.deleteNode(BST_deleteinput);
    }
    auto finish3bst = std::chrono::steady_clock::now();
    BSTtime+= std::chrono::duration_cast<std::chrono::nanoseconds>(finish3bst-start3bst).count();
    cout << endl << "Final structure of BST:" << endl;
    myBST.print();
    inputFile.close();
/* - - - - - - - - - - - - - Now testing splay tree - - - - - - - - - - - - */

    inputFile.open(inputFileName);
    int splayTime = 0;
    Splay mySplay;
    
    //testing Splay tree insert
    int splay_insertinput = 0;
    string splay_insertline = "";
    getline(inputFile, splay_insertline);
    stringstream splay_insertss(splay_insertline);
    auto start1splay = std::chrono::steady_clock::now();
    while(splay_insertss >> splay_insertinput){
        mySplay.insert(splay_insertinput); 
    }
    auto finish1splay = std::chrono::steady_clock::now();
    splayTime+= std::chrono::duration_cast<std::chrono::nanoseconds>(finish1splay-start1splay).count();
    cout << endl << "Structure of initialized splay tree: " << endl;
    mySplay.print();

    string splay_firstdump = "";
    getline(inputFile, splay_firstdump);

    //testing splay tree search
    string splay_searchline = "";
    int splay_searchinput = 0;
    getline(inputFile, splay_searchline);
  //  cout << "serach line: " << searchline << endl;
    stringstream splay_searchss(splay_searchline);
    auto start2splay = std::chrono::steady_clock::now();
    while(splay_searchss >> splay_searchinput){
        //cout << "about to search for " << searchinput << endl;
        mySplay.searchNode(splay_searchinput);
        //cout << "searched for " << searchinput << endl;
    }
    auto finish2splay = std::chrono::steady_clock::now();
    splayTime+= std::chrono::duration_cast<std::chrono::nanoseconds>(finish2splay-start2splay).count();
   
    string seconddump = "";
    getline(inputFile, seconddump);

    string splay_deleteline = "";
    int splay_deleteinput = 0;
    getline(inputFile, splay_deleteline);
    stringstream deletess(splay_deleteline);
    auto start3splay = std::chrono::steady_clock::now();
    while(deletess >> splay_deleteinput){
        mySplay.deleteNode(splay_deleteinput);
    }
    auto finish3splay = std::chrono::steady_clock::now();
    splayTime+= std::chrono::duration_cast<std::chrono::nanoseconds>(finish3splay-start3splay).count();
       
    cout << endl << "Final structure of splay tree: " << endl;
    mySplay.print();

    cout << endl << "BST traversal Count: " << myBST.getTraversalCount() << endl;
    cout << "BST elapsed time: " << BSTtime << " nanoseconds" << endl;
    cout << endl << "Splay tree traversal Count: " << mySplay.getTraversalCount() << endl;
    cout << "Splay tree elapsed time: " << splayTime << " nanoseconds" << endl;

    cout << endl;
    if(myBST.getTraversalCount() == mySplay.getTraversalCount()){
        cout << "BST and Splay tree are equally efficient with regard to Traversal Count." << endl;
    }
    else if(myBST.getTraversalCount() < mySplay.getTraversalCount()){
        cout << "BST was more efficient than Splay tree with regard to Traversal Count." << endl;
    }
    else{
        cout << "Splay tree was more efficient than BST with regard to Traversal Count." << endl;
    }

    if(BSTtime == splayTime){
        cout << "BST and Splay tree are equally efficient with regard to elapsed time." << endl;
    }
    else if(BSTtime < splayTime){
        cout << "BST was more efficient than Splay tree with regard to elapsed time." << endl;
    }
    else{
        cout << "Splay tree was more efficient than BST with regard to elapsed time." << endl;
    }
}

