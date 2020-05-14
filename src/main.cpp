#include <iostream>
#include "BinaryTree.h"
#include "AVLTree.h"
#include "Reader.h"

using namespace std;
int main() {
    AVLTree tree2;
    int op = 2;
    switch (op) {
        case 1:{
            tree2.add("D");
            tree2.add("E");
            tree2.add("B");
            tree2.add("A");
            tree2.add("C");
            tree2.add("F");
            tree2.add("F");
            tree2.postOrder(tree2.getRoot());
            if(tree2.search("A"))
                std::cout<<"true"<<std::endl;
            else
                std::cout<<"false"<<std::endl;
            tree2.del("B");
            tree2.preOrder(tree2.getRoot());
            std::cout<<"false"<<std::endl;
            tree2.inOrder(tree2.getRoot());
            break;
        }
        case 2:{
            cout<<"step 1"<<endl;
            Reader reader("Dracula.txt");
            cout<<"step 2"<<endl;
            reader.clean();
            cout<<"step 3"<<endl;
            reader.buildAVLTree(tree2);
            cout<<"step 4"<<endl;
            tree2.preOrder(tree2.getRoot());
            cout<<"step 5"<<endl;
            break;
        }

    }
    return 0;
}
