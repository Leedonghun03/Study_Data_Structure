#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class graph 
{
private:
  vector<vector<int>> grp;
  bool isVisited[100] = { 0, };

public:
  void create_vertex(int vertexs)
  {
    vector<int> row(vertexs);

    fill(row.begin(), row.end(), -1);

    for(int i = 0; i < vertexs; i++)
      grp.push_back(row);
  }

  void Add_Edge(int vertex1, int vertex2) 
  {
    grp[vertex1][vertex2] = 1;
    grp[vertex2][vertex1] = 1;

    cout << vertex1 << " 과 " << vertex2 << " 연결했습니다." << endl;
  }

  void Delete_Edge(int vertex1, int vertex2)
  {
    grp[vertex1][vertex2] = -1;
    grp[vertex2][vertex1] = -1;

    cout << vertex1 << " 과 " << vertex2 << " 연결을 해제했습니다." << endl;
  }

  void show_board()
  {
    int size = grp.size();
    
    cout << "vertex size: " << size << endl;
    cout << "   ";
    
    for(int i = 0; i < size; i++)
      cout << i << " ";

    cout << endl;

    for(int i = 0; i < size; i++)
      {
        cout << i << ": ";
        
        for(int j = 0; j < size; j++)
          {
            if(grp[i][j] == -1)
              cout << "0 ";
            else
              cout << grp[i][j] << " ";
          }

        cout << endl;
      }
  }

  void show_DFS(int visit_node)
  {
    isVisited[visit_node] = true;

    cout << "방문한 Vertex: " << visit_node << endl;
    
    for(int i = 0; i < grp[visit_node].size(); i++)
      {
        int nextVertex = grp[visit_node][i];

        if(nextVertex != -1 && !isVisited[i])
          show_DFS(i);
      }
  }

  void show_BFS(int visit_node)
  {
    queue<int> que;
    
    que.push(visit_node);
    isVisited[visit_node] = true;
    
    while(!que.empty())
      {
        auto front = que.front();
        que.pop();
        
        cout << "방문한 vertex: " << front << endl;
        
        for(int i = 0; i < grp[visit_node].size(); i++)
          {
            int nextVertex = grp[front][i];

            if(nextVertex != -1 && !isVisited[i])
            {
              que.push(i);
              isVisited[i] = true;
            }
          }
      }
  }

  void Visitied_Clear()
  {
    for(int i = 0; i < grp.size(); i++)
      isVisited[i] = 0;
  }
};