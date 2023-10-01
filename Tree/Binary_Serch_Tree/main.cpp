#include "BST_Tree.h"
#include <iostream>

using namespace std;

int main() 
{
  //BST_tree
  BST_TREE tree;

  tree.create_tree(8);
  cout << endl;

  {
    tree.insert_Node(tree.root, 3);
    tree.insert_Node(tree.root, 3);      //중복값 추가
    tree.insert_Node(tree.root, 10);
    tree.insert_Node(tree.root, 1);
    tree.insert_Node(tree.root, 6);
    tree.insert_Node(tree.root, 14);
    tree.insert_Node(tree.root, 4);
    tree.insert_Node(tree.root, 7);
    tree.insert_Node(tree.root, 13);
    cout << endl;
  }

  cout << "전위 출력: ";
  tree.preOrder(tree.root);
  cout << endl;

  cout << "중위 출력: ";
  tree.inOder(tree.root);
  cout << endl;

  cout << "후위 출력: ";
  tree.postOrder(tree.root);
  cout << endl;
  
  tree.find_Node(tree.root, 3);
  
  return 0;
}
