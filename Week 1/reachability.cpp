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
void dfs(vector<ll>v[],ll n,ll x,ll y)
{  
    stack<ll>s;
    s.push(x);
    ll vis[n+1]={false},f=0;      //mark all nodes unvisited
     // dfs for node x 
     while(!s.empty())
     {
         ll node=s.top();
         s.pop();
         vis[node]=true;

          for(auto z: v[node])     // pushing the nodes which is not yet visited and connected to the node which is last popped 
          {
             if(vis[z]==false)
             {
               vis[z]=true;
               s.push(z);
             }
             if(z==y)
             {
              f=1;     // if y is found during dfs of x then it is reachable from x
              break;
             }
          }
       if(f==1)
       break;

       }
    if(f==1)
    cout<<1<<endl;
    else
    cout<<0<<endl;
  
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
  vector<ll>v[n+1];
  for(i=0;i<m;i++)
  {
     cin>>x>>y;
     v[x].pb(y);
     v[y].pb(x);
  }
     cin>>x>>y;
    dfs(v,n,x,y);
} 
