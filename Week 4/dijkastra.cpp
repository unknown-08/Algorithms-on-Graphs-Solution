#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define mod 1000000007
#define INF 10002
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
int we[10002][10002]; // store the weight of the edges 
int d[10002],n;   

void dijkastra(vector<int>vec[],int so,int de)
{

    d[so]=0;
    int v,i,j;
    bool u[10002]={false};   
    
    for(i=1;i<=n;i++)
    {
        v=-1;
        
       for(j=1;j<=n;j++)
       {
          if(!u[j] && ( v==-1 || d[j]<d[v]))  // find the vertex which has minimum distance and has not yet visited
          v=j;
       }

       if(d[v]==INF)
       break;
       u[v]=true;

       for(auto z: vec[v])
       {
          if(d[z]>d[v]+we[v][z])  // if distance of  vertex z from source node is greater than 
		                          // sum of distances of vertex v from source node and weight of the edge between v and z 
		  d[z]=d[v]+we[v][z];     // then update the distance of z 
       }
    }

     if(d[de]==INF)              //source and destination are not connected
     cout<<-1<<endl;
     else
     cout<<d[de]<<endl;            
}
int main()
{  
  
  
     #ifdef _DEBUG
	   freopen("input.txt", "r", stdin);
     //	freopen("output.txt", "w", stdout);
     #endif
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);  

     int m,x,y,w,s,de,i;
     cin>>n>>m;
     vector<int>v[n+1];
     
     for(i=1;i<=n;i++)
     d[i]=INF;
     for(i=0;i<m;i++)
     {
        cin>>x>>y>>w;
        we[x][y]=w;
        v[x].pb(y);
     }
      cin>>s>>de;
      dijkastra(v,s,de);
}

