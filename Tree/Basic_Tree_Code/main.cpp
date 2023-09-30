#include "Tree/basic_Tree.h"
#include <iostream>

using namespace std;

int main() 
{
  tree m_tree;

  {
    m_tree.create_tree(3);
  
    m_tree.add_Node(3, 5);
    m_tree.add_Node(3, 7);
    m_tree.add_Node(3, 9);
    cout << endl;
  
    m_tree.add_Node(5, 6);
    m_tree.add_Node(5, 1);
    cout << endl;
  
    m_tree.add_Node(7, 2);
    m_tree.add_Node(7, 4);
    cout << endl;
  }

  m_tree.preOrder(m_tree.root);
  cout << endl;

  m_tree.inOder(m_tree.root);
  cout << endl;

  m_tree.postOrder(m_tree.root);
  cout << endl;

  m_tree.levelOder(m_tree.root);
  cout << endl;
  
  return 0;
}