#include <bits/stdc++.h>
using namespace std;


const int inf = numeric_limits<int>::max();

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
 
  vector<long> dist(adj.size(), inf);
  dist[0] = 0;
  for (int i = 0; i < adj.size(); i++) {
    for(int u = 0; u < adj.size(); u++){
	  for (int k = 0; k < adj[u].size(); k++) {
	    int v = adj[u][k];
	    if(dist[v] > dist[u] + cost[u][k]) {  //updating the distance of v from source if it is greater than 
		    dist[v] = dist[u] + cost[u][k];   // the sum of distance of u from source and edge cost between u and v
			if(i == adj.size() - 1) 
			  return 1;
		}
	  }
	}
  }
  return 0;
}

int main() {
	
	
     #ifdef _DEBUG
     freopen("input.txt", "r", stdin);
     //	freopen("output.txt", "w", stdout);
     #endif
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);  

   int n, m;
   cin >> n >> m;
   vector<vector<int> > adj(n, vector<int>());
   vector<vector<int> > cost(n, vector<int>());
   
   for (int i = 0; i < m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
   
   cout << negative_cycle(adj, cost);
   return 0;
}
