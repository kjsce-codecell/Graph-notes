#include<bits/stdc++.h>
using namespace std;

int d[1000000];
vector<pair<int,int> > graph[100];

void dijkstra(int root) {
    set<pair<int,int> > s;
    set<pair<int,int> > ::iterator it;
    int u,v,wt;
    vector<pair<int,int> > :: iterator i;
    d[root]=0;
    s.insert(pair<int,int>(0,root));
    while(s.size()!=0){
        it=s.begin();
        u=it->second;
        s.erase(it);
        for(i=graph[u].begin(); i!=graph[u].end(); i++){
            v=i->first;
            wt=i->second;
            if(d[v]>d[u]+wt){
                if(d[v]!=1e8){
                    s.erase(s.find(pair<int,int>(d[v],v)));
                }
                d[v]=d[u]+wt;
                s.insert(pair<int,int>(d[v],v));
            }
        }
    }
}

void addedge(int a,int b,int wt) {
    pair<int,int> x;
    x.first=b;
    x.second=wt;
    graph[a].push_back(x);
    x.first=a;
    x.second=wt;
    graph[b].push_back(x);
}

int main() {
    int i;
    int v,e,a,b,wt;
    cin>>v>>e;
    for(i=0; i<=v; i++){
        d[i]=1e8;
    }
    for(i=0; i<e; i++){
        cin>>a>>b>>wt;
        addedge(a,b,wt);
    }
    dijkstra(0);
    for(int i =0;i<v;i++){
    cout<<d[i]<<endl;
    }
return 0;
}
