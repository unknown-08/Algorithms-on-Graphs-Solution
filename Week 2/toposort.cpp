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

class Graph 
{ 
    ll V;    
  
    list<ll> *adj; 
   
    void topologicalSortUtil(ll v, bool visited[], stack<ll> &Stack); 
public: 
    Graph(ll V);  
  
    void addEdge(ll v, ll w); 
  
    void topologicalSort(); 
}; 
  
Graph::Graph(ll V) 
{ 
    this->V = V; 
    adj = new list<ll>[V]; 
} 
  
void Graph::addEdge(ll v, ll w) 
{ 
    adj[v].push_back(w);  
} 
  

void Graph::topologicalSortUtil(ll v, bool visited[],  
                                stack<ll> &Stack) 
{  // mark current node as true
    visited[v] = true; 
  // explore all nodes connected to v
    list<ll>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
  //push current vertex to the stack
    Stack.push(v); 
} 
  
void Graph::topologicalSort() 
{ 
    stack<ll> Stack; 
    // Marking each vertex unvisited
    bool *visited = new bool[V]; 
    for (ll i = 0; i < V; i++) 
        visited[i] = false; 
   
   // calling the topologicalSortUtil function which hepls in topological sorting  
    for (ll i = 0; i < V; i++) 
      if (visited[i] == false) 
        topologicalSortUtil(i, visited, Stack); 
  
    while (Stack.empty() == false) 
    { 
        if(Stack.top()>0 )
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
} 


int main()
{  
     #ifdef _DEBUG
     freopen("input.txt", "r", stdin);
     //	freopen("output.txt", "w", stdout);
     #endif
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);  

  ll n,m,x,y,i;
  cin>>n>>m;
  Graph g(n+1); 
  
  for(i=0;i<m;i++)
  {
     cin>>x>>y;
     g.addEdge(x,y);
  }
    g.topologicalSort();
} 
