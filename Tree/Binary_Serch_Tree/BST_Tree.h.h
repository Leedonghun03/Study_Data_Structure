#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* Left;
  Node* Right;
};

class BST_TREE
{
private:

public:
  Node* root;

  Node* create_tree(int data)
  {
    Node* node = new Node{data, NULL, NULL};

    return root;
  }

  Node* find_Node(Node* node, int find_data)
  {
    if(node == NULL)
      cout << "초기 값이 없습니다. -> create_tree를 이용해 생성해주세요." << endl;

    if(root->data == find_data)
      return root;
    else
    {
      if(root->data > find_data)
        return find_Node(root, find_data);
      else
        return find_Node(root, find_data);
    }
  }

  void insert_Node(Node* node, int insert_data)
  {
    Node* parent;
    
    if(node == NULL)
      cout << "초기 값이 없습니다. -> create_tree를 이용해 생성해주세요." << endl;
    
      while(node)
        {
          parent = node;

          if(parent->data > insert_data)
            node = node->Left;
          else
            node = node->Right;
        }
      
      Node* new_node = new Node{insert_data, NULL, NULL};

      if(parent->data > insert_data)
        parent->Left = new_node;
      else if(parent->data < insert_data)
        parent->Right = new_node;
      else
        cout << insert_data << "는 " << parent->data << "에 이미 있는 값입니다." << endl;
  }
};