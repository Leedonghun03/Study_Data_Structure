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
  Node* tree;

  Node* create_tree(int data)
  {
    tree = new Node{data, NULL, NULL};
    cout << data << "를 기초를 한 BST_TREE 생성." << endl;
    
    return tree;
  }

  Node* find_Node(Node* root, int find_data)
  {
    if(!root)
    {
      cout << "찾는 값이 존재하지 않음 -> " << find_data << endl;
      return NULL;
    }

    if(root->data == find_data)
    {
      cout << "값이 존재함 -> " << find_data << endl;
      return root;
    }
    else
    {
      if(find_data < root->data)
        return find_Node(root->left, find_data);
      else
        return find_Node(root->right, find_data);
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
        cout << parent->data << " left에 " << insert_data << "를 추가했습니다." << endl;
        parent->left = new_node;
      }
      else if(parent->data < insert_data)
      {
        cout << parent->data << " right에 " << insert_data << "를 추가했습니다." << endl;
        parent->right = new_node;
      }
      else
        cout << insert_data << "은 " << parent->data << "에 이미 있는 값입니다." << endl;
    }
  }

  Node* delete_Node(Node* root, int targetNode)
  {
    if(!root)
      cout << "초기 값이 없습니다. -> create_tree를 이용해 생성해주세요." << endl;

    if(root->data < targetNode)
      root->right = delete_Node(root->right, targetNode);
    else if(root->data > targetNode)
      root->left = delete_Node(root->left, targetNode);
    else
    {
      Node* tmp;
      
      if(!root->left)
      {
        tmp = root->right;
        delete root;
        return tmp;
      }
      else if(!root->right)
      {
        tmp = root->left;
        delete root;
        return tmp;
      }
      else
      {
        Node* pn = root;      //3
        Node* n = pn->left;   //1

        //후임자 찾기
        while(n->right)
          {
            pn = n;          //1
            n = n->right;    //4
          }

        //후임자 값을 root에 적용
        root->data = n->data;

        //후임자를 자식으로 대채
        if(pn == root)
          root->left = n->left;
        else
          pn->right = n->left;

        //후임자 삭제
        delete n;
      }
    }
    return root;
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

    postOrder(start->left);
    postOrder(start->right);
    
    cout << start->data << "  ";
  }
};
