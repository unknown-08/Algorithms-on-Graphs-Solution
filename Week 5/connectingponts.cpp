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
    template <class T1, class T2>size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

 bool sortbyth(const tuple<int, int, double>& a,const tuple<int, int, double>& b) 
{ 
    return (get<2>(a) < get<2>(b)); 
} 

struct edge{
 int a,b;
 double cost;
};

double  dis(double x1,double y1,double x2,double y2)
{
  double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  return d;
}

class DisjSet { 
    int *rank, *parent, n; 
  
public:  
    DisjSet(int n) 
    { 
        rank = new int[n]; 
        parent = new int[n]; 
        this->n = n; 
        makeSet(); 
    } 
  
    void makeSet() 
    { 
        for (int i = 0; i < n; i++) { 
            parent[i] = i; 
        } 
    } 
  
    int find(int x) 
    { 
        if (parent[x] != x) { 
  
            parent[x] = find(parent[x]); 
        } 
  
        return parent[x]; 
    } 
  
    void Union(int x, int y) 
    { 
        int xset = find(x); 
        int yset = find(y); 
  
        if (xset == yset) 
            return; 
  
        if (rank[xset] < rank[yset]) { 
            parent[xset] = yset; 
        } 
        else if (rank[xset] > rank[yset]) { 
            parent[yset] = xset; 
        } 
  
        else { 
            parent[yset] = xset; 
            rank[xset] = rank[xset] + 1; 
        } 
    } 
}; 

int main()
{
	
	 #ifdef _DEBUG
     freopen("input.txt", "r", stdin);
     //	freopen("output.txt", "w", stdout);
     #endif
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);  
   
   int n,i,j;
   cin>>n;
   double x[n],y[n];
   for(i=0;i<n;i++)  cin>>x[i]>>y[i];

   vector<tuple<int,int,double>>v; // vector tuple used to store the distance between the given points 

   DisjSet obj(n+1);
   
   for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
     {
        double d=dis(x[i],y[i],x[j],y[j]); // calculating the distance between two points
        v.pb(make_tuple(i,j,d));           // storing distance between point i and j in the  vector 
     }
   }

    sort(v.begin(),v.end(),sortbyth);     // sortng according to the distance 
    double ans=0;
    
    for(i=0;i<v.size();i++)
    {
       if(obj.find(get<0>(v[i]))!=obj.find(get<1>(v[i])))  // if i and j are not connected yet then connect them
       {
          ans+=get<2>(v[i]);
          obj.Union(get<0>(v[i]),get<1>(v[i]));    
       }
    }
    printf("%.7lf",ans);
    
	return 0;
}
