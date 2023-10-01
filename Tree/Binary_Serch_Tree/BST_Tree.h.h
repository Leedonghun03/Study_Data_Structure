#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

class BST_TREE
{
private:

public:
  Node* root;

  Node* create_tree(int data)
  {
    root = new Node{data, NULL, NULL};
    cout << data << "를 기초를 한 BST_TREE 생성." << endl;
    
    return root;
  }

  Node* find_Node(Node* start_node, int find_data)
  {
    if(!start_node)
    {
      cout << "초기 값이 없습니다. -> create_tree를 이용해 생성해주세요." << endl;
      return NULL;
    }

    if(start_node->data == find_data)
    {
      cout << "값이 존재함 -> " << find_data << endl;
      return start_node;
    }
    else
    {
      if(find_data < start_node->data)
        return find_Node(start_node->left, find_data);
      else
        return find_Node(start_node->right, find_data);
    }
  }

  void insert_Node(Node* root, int insert_data)
  {
    Node* parent;
    
    if(root == NULL)
      cout << "초기 값이 없습니다. -> create_tree를 이용해 생성해주세요." << endl;
    else
    {
      while(root)
        {
          parent = root;

          if(parent->data > insert_data)
            root = root->left;
          else
            root = root->right;
        }
      
      Node* new_node = new Node{insert_data, NULL, NULL};

      if(parent->data > insert_data)
      {
        cout << parent->data << "에 " << insert_data << "를 추가했습니다." << endl;
        parent->left = new_node;
      }
      else if(parent->data < insert_data)
      {
        cout << parent->data << "에 " << insert_data << "를 추가했습니다." << endl;
        parent->right = new_node;
      }
      else
        cout << insert_data << "은 " << parent->data << "에 이미 있는 값입니다." << endl;
    }
  }

  void preOrder(Node* start) //전위 출력
  {
    if(!start)
      return;
    
    cout << start->data << "  ";

    preOrder(start->left);
    preOrder(start->right);
  }
  
  void inOder(Node* start) //중위 출력
  {
    if (!start)
      return;

    inOder(start->left);
    
    cout << start->data << "  ";
    
    inOder(start->right);
  }

  void postOrder(Node* start) //후위 출력
  {
    if (!start)
      return;

    preOrder(start->left);
    preOrder(start->right);
    
    cout << start->data << "  ";
  }
};
