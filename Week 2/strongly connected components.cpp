#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define mod 1000000007
using namespace std;
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); auto hash2 = hash<T2>{}(p.second);return hash1 ^ hash2; 
    } 
}; 

vector<vector<int> > reverseEdges(vector<vector<int> > &adj){
	vector<vector<int> > rAdj(adj.size(), vector<int>());
    for(int i = 0; i < adj.size(); i++){
	  // Recur for all the vertices adjacent to this vertex
	  for(int j = 0; j < adj[i].size(); j++){
		rAdj[adj[i][j]].push_back(i);
	  }
	}
	return rAdj;
}

void dfs(vector<vector<int> > &adj, int x, vector<int> &visited, stack<int> &Stack) {
	// Mark the current node as visited
	visited[x] = 1;
	
	// Recur for all the vertices adjacent to this vertex
	for (int i = 0; i < adj[x].size(); i++) {
      if(!visited[adj[x][i]]){
        //visited[adj[x][i]] = 1;
		dfs(adj, adj[x][i], visited, Stack);
	  }	
	}
	
	// All vertices reachable from x are processed by now, push x to Stack
	Stack.push(x);
}

int number_of_scc(vector<vector<int> > adj) {
  int result = 0;
  stack<int> Stack;
  
  // Mark all the vertices as not visited (For first DFS)
  vector<int> visited(adj.size(), 0);
  
  // Fill vertices in stack according to their finishing times
  /*for (int i = 0; i < adj.size(); i++) {
	if(!visited[i]){
	  dfs(adj, i, visited, Stack);
	}
  }*/
	
  // get the reversed adj list
  vector<vector<int> > rAdj = reverseEdges(adj);
	
  // Mark all the vertices as not visited (For second DFS)
  /*for(int i = 0; i < adj.size(); i++) {
	visited[i] = 0;
  }*/
  for (int i = 0; i < rAdj.size(); i++) {
	if(!visited[i]){
	  dfs(rAdj, i, visited, Stack);
	}
  }
	
  // Now process all vertices in order defined by Stack
  fill(visited.begin(), visited.end(), 0);
  while (! Stack.empty()) {
	// Pop a vertex from stack
    int x = Stack.top();
    Stack.pop();
 
    // get one Strongly connected component of the popped vertex
    if (!visited[x]) {
	  stack<int> componentStack;
	  dfs(adj, x, visited, componentStack);
	  result++;
	}
  }
  return result;
}

int main() {
	
	  #ifdef _DEBUG
     freopen("input.txt", "r", stdin);
     //	freopen("output.txt", "w", stdout);
     #endif
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);  

	
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > v(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x - 1].push_back(y - 1);
  }
  cout << number_of_scc(v);
}
