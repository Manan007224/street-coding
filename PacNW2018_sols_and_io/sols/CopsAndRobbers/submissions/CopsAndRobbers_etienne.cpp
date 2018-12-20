#include <iostream>
#include <vector>
#include <limits>
#include <queue>

bool bfs(int *rGraph, int N, int s, int t, int *parent)
{

  bool *visited = new bool[N];
  for(int i=0; i<N; i++)
    visited[i] = false;

  std::queue <int> q;
  q.push(s);
  visited[s] = true;
  parent[s] = -1;

  while (!q.empty())
    {
      int u = q.front();
      q.pop();

      for (int v=0; v<N; v++)
	{
	  if (visited[v]==false && rGraph[u*N + v] > 0)
	    {
	      q.push(v);
	      parent[v] = u;
	      visited[v] = true;
	    }
	}
    }

  bool ret = visited[t];
  delete[] visited;
  return ret;
}

int fordFulkerson(int *graph, int N, int s, int t)
{
  int u, v;

  int *rGraph = new int[N*N];

  for (u = 0; u < N; u++)
    for (v = 0; v < N; v++)
      rGraph[u*N + v] = graph[u*N + v];

  int *parent = new int[N];

  int max_flow = 0;

  while (bfs(rGraph, N, s, t, parent))
    {
      int path_flow = std::numeric_limits<int>::max();
      for (v=t; v!=s; v=parent[v])
	{
	  u = parent[v];
	  path_flow = std::min(path_flow, rGraph[u*N + v]);
	}

      if(path_flow == std::numeric_limits<int>::max())
	{
	  delete[] rGraph;
	  delete[] parent;
	  return -1;
	}
      
      for (v=t; v != s; v=parent[v])
	{
	  u = parent[v];
	  rGraph[u*N + v] -= path_flow;
	  rGraph[v*N + u] += path_flow;
	}

      max_flow += path_flow;
    }

  delete[] rGraph;
  delete[] parent;
  return max_flow;
} 

int main()
{
  int m, n, c;
  std::cin >> n >> m >> c;
  char *grid = new char[m*n];

  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
      std::cin >> grid[i*n+j];
  

  std::vector<int> costs;
  for(int i=0; i<c; i++)
    {
      int ci;
      std::cin >> ci;
      costs.push_back(ci);
    }


  int N = 2*m*n+1;
  int *graph = new int[N*N];
  for(int i=0; i<N*N; i++)
    graph[i]=0;

  int bank = -1;
  
  for(int i=0; i<m; i++)
    {
      for(int j=0; j<n; j++)
	{
	  int curidx = m*n + i*n+j;
	  int dx[] = {1, -1, 0, 0};
	  int dy[] = {0, 0, 1, -1};
	  for(int k=0; k<4; k++)
	    {
	      int newi = i + dy[k];
	      int newj = j + dx[k];
	      if(newi < 0 || newj < 0 || newi >= m || newj >= n)
		{
		  graph[curidx*N + 2*m*n] = std::numeric_limits<int>::max();
		}
	      else
		{
		  int newidx = newi*n+newj;
		  graph[curidx*N + newidx] = std::numeric_limits<int>::max();
		}
	    }
	  if(grid[i*n+j] == 'B')
	    bank = i*n+j;
	  if(grid[i*n+j] == 'B' || grid[i*n+j] == '.')
	    {
	      graph[(i*n+j)*N + curidx] = std::numeric_limits<int>::max();
	    }
	  else
	    {
	      graph[(i*n+j)*N + curidx] = costs[grid[i*n+j]-'a'];
	    }
	}
    }

  std::cout << fordFulkerson(graph, N, bank, 2*m*n) << std::endl;
  delete[] graph;
  delete[] grid;
}
