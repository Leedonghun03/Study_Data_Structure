#include "Graph/graph.h"
#include <iostream>

using namespace std;

int main() 
{
  //그래프
  graph grp;

  grp.create_vertex(9);
  
  //그래프 vertex 다리 연결
  {
  grp.Add_Edge(0, 1);
  grp.Add_Edge(0, 2);
  grp.Add_Edge(0, 7);
  
  grp.Add_Edge(1, 0);
  grp.Add_Edge(1, 6);

  grp.Add_Edge(2, 0);
  grp.Add_Edge(2, 3);
  grp.Add_Edge(2, 4);

  grp.Add_Edge(3, 2);
  grp.Add_Edge(3, 4);

  grp.Add_Edge(4, 2);
  grp.Add_Edge(4, 3);

  grp.Add_Edge(5, 6);

  grp.Add_Edge(6, 1);
  grp.Add_Edge(6, 5);
  grp.Add_Edge(6, 7);

  grp.Add_Edge(7, 0);
  grp.Add_Edge(7, 6);

  cout << endl;
  }
  
  grp.show_board();
  cout << endl;

  //DFS
  cout << "---- DFS ----" << endl;
  grp.show_DFS(0);
  cout << endl;
  
  grp.Visitied_Clear();
  
  //BFS
  cout << "---- BFS ----" << endl;
  grp.show_BFS(0);
  
  
  return 0;
}