#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define n 100001
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
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

vector<ll>v[n+1];       // vector array in which each vertex storing its adjacent vertices
bool vis[n+1]={false};  // marking all vertex unvisited
void bfs(ll x,ll y)
{
    char col[n+1];
    queue<ll>q;
    q.push(x);
    col[x]='R';        // marking node x with color red
    vis[x]=true;       
    ll f=1;
    
    while(!q.empty())
    {
         ll node=q.front();
         vis[node]=true;    
         q.pop();
          for(auto z: v[node])
          {
              if(vis[z]==false)
              {
                q.push(z);
                vis[z]=true;
              
                if(col[node]=='R')  // marking adjacent node with different color
                col[z]='B';
                else
                col[z]='R';
              }
              else if(col[node]==col[z]) // if we find two adjacent node with same color then it is not bipartite
              { 
                f=0;
                break;
              } 
          }
    }
    cout<<f<<endl;    
}

int main()
{
    #ifdef _DEBUG
     freopen("input.txt", "r", stdin);
     //	freopen("output.txt", "w", stdout);
     #endif
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);  
   

  ll n1,m,i,x,y;
  cin>>n1>>m;
  for(i=0;i<m;i++)
  {
    cin>>x>>y;
    v[x].pb(y);
    v[y].pb(x);
  }
  
  //cin>>x>>y;
  bfs(x,y);
}
