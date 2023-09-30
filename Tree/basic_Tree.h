#include <iostream>
#include <queue>

using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};

class tree
{
private:
  int parent_node;

public:
  Node* root;

  Node* create_tree(int data)
  {
    root = new Node{data, NULL, NULL};

    return root;
  }

  Node* serch_Node(Node* root, int data)
  {
    if(root == NULL)
      return NULL;

    if(root->data == data)
      return root;
    
    auto firstFound = serch_Node(root->left, data);

    if(firstFound != NULL)
      return firstFound;

    return serch_Node(root->right, data);
  }

  bool add_Node(int find_parent_node, int data)
  {
    auto parent_node = serch_Node(root, find_parent_node);

    if(!parent_node)
    {
      cout << parent_node->data << "를 찾을 수 없음" << endl;
      return false;
    }

    if(parent_node->left && parent_node->right)
    {
      cout << parent_node->data << "에 더이상 추가 불가능" << endl;
      
      return false;
    }

    if(!parent_node->left)
      parent_node->left = new Node{data, NULL, NULL};
    else
      parent_node->right = new Node{data, NULL, NULL};

    cout << parent_node->data << "에 " << data << "를 추가 완료" << endl;

    return true;
  }

  //전위 출력
  void preOrder(Node *start) 
  {
    if (!start)
      return;

    cout << start->data << " -> ";
    
    preOrder(start->left);
    preOrder(start->right);
  }

  //중위 출력
  void inOder(Node* start)
  {
    if (!start)
      return;

    inOder(start->left);
    
    cout << start->data << " -> ";
    
    inOder(start->right);
  }

  //후위 출력
  void postOrder(Node* start)
  {
    if (!start)
      return;

    preOrder(start->left);
    preOrder(start->right);
    
    cout << start->data << " -> ";
  }

  //레벨 출력
  void levelOder(Node* start)
  {
    if(!start)
      return;

    queue<Node*> que;
    que.push(start);

    while(!que.empty())
      {
        for(int i = 0; i < que.size(); i++)
          {
            auto que_front_node = que.front();
            que.pop();

            cout << que_front_node->data << ", ";

            if(que_front_node->left)
              que.push(que_front_node->left);
            if(que_front_node->right)
              que.push(que_front_node->right);
          }
        cout << endl;
      }
  }
};