#include "BST_Tree.h"
#include <iostream>

using namespace std;

int main() 
{
  //BST_tree
  BST_TREE BSTtree;

  {
              //tree
            //    8
          //  3      10
        //  1   6       14
      //      4   7  13
    
    BSTtree.create_tree(8);
    cout << endl;
    
    BSTtree.insert_Node(BSTtree.tree, 3);
    BSTtree.insert_Node(BSTtree.tree, 3);      //중복값 추가
    BSTtree.insert_Node(BSTtree.tree, 10);
    BSTtree.insert_Node(BSTtree.tree, 1);
    BSTtree.insert_Node(BSTtree.tree, 6);
    BSTtree.insert_Node(BSTtree.tree, 14);
    BSTtree.insert_Node(BSTtree.tree, 4);
    BSTtree.insert_Node(BSTtree.tree, 7);
    BSTtree.insert_Node(BSTtree.tree, 13);
    cout << endl;

    BSTtree.delete_Node(BSTtree.tree, 3);
    BSTtree.find_Node(BSTtree.tree, 3);
  }

  cout << "전위 출력: ";
  BSTtree.preOrder(BSTtree.tree);
  cout << endl;

  cout << "중위 출력: ";
  BSTtree.inOder(BSTtree.tree);
  cout << endl;

  cout << "후위 출력: ";
  BSTtree.postOrder(BSTtree.tree);
  cout << endl;
  
  BSTtree.find_Node(BSTtree.tree, 3);
  
  return 0;
}
