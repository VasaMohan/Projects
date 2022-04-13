#include <bits/stdc++.h>
using namespace std;    

const int MAX = 99999; 
int id[MAX],nodes,edges;    
pair <long long, pair<int, int> > p[MAX]; 

int root(int x)    
{    
    while(id[x] != x)    
    {    
        id[x] = id[id[x]];    
        x = id[x];    
    }    
    return x;    
}      

void union1(int x, int y)    
{    
    int p = root(x);    
    int q = root(y);    
    id[p] = id[q];    
}     

long long kruskal(vector<pair<long long, pair<int, int> >> p)    
{    
    int x, y;    
    long long cost, minimumCost = 0;  
    int count=0;
    
    while(count<nodes-1)  
    {    
        x = p.front().second.first;    
        y = p.front().second.second;    
        cost = p.front().first;  
        
        if(root(x) != root(y))    
        {    
            count++;
            cout<<x<<y<<count<<endl;
            minimumCost += cost;    
            union1(x, y);    
        }   
        
        pop_heap(p.begin(), p.end());
        p.pop_back();
    }    
    return -1*minimumCost;    
}     
int main()    
{    
    int x,y;    
    long long weight,cost,minimumCost;    
    
    for(int i = 0;i < MAX;++i)    
        id[i] = i;
       
    cout<<"Enter number of Nodes and edges";    
    cin>>nodes>>edges;   
    
    for(int i=0;i<edges;++i)    
    {    
        cout<<"Enter the value of X, Y and weight";    
        cin>>x>>y>>weight;    
        p[i]=make_pair(-1*weight, make_pair(x, y));    
    }   
    
    vector<pair <long long, pair<int, int> >> v;
    
    for(int i = 0;i < edges;++i)
    v.push_back(p[i]);
    
    make_heap(v.begin(),v.end());
    
    minimumCost = kruskal(v);    
    cout<<"Minimum cost is "<<minimumCost<<endl;   
    
    return 0;    
} 