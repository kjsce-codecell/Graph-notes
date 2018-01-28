/*
 Problem Link : https://www.codechef.com/problems/CLIQUED
 */

#include<iostream>
#include<vector>
#include<set>
#define pi pair< long long int, long long int >
#define llu long long int
#define INF 1e18
using namespace std;

int main()
{
	llu t,n,k,x,m,s,i,j,a,b,c,curr;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>x>>m>>s;s--;
		vector <pi> roads[n+1];
		vector <pi>::iterator it;
		
		for(i=0;i<k;i++)
		{
			roads[i].push_back(make_pair(x,n));
			roads[n].push_back(make_pair(x,i));
		}
		
		for(i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			a--;b--;
			
			roads[a].push_back(make_pair(2*c,b));
			roads[b].push_back(make_pair(2*c,a));
		}
		
		llu dist[n+1];
		bool visited[n+1];
		for(i=0;i<=n;i++)
		{
			dist[i]=INF;
			visited[i] = false;
		}
		dist[s]=0;
		set <pi> spt;
		spt.insert(make_pair(0,s));
		
		while(!spt.empty())
		{
			curr = spt.begin()->second;
			spt.erase(spt.begin());
			
			if(visited[curr] == false)
			{
				for(it=roads[curr].begin();it!=roads[curr].end();it++)
				{
					if(dist[curr]+it->first < dist[it->second])
					{
						spt.erase(make_pair(dist[it->second],it->second));
						dist[it->second]=dist[curr]+it->first;
						spt.insert(make_pair(dist[it->second],it->second));
					}
				}
			}
		}
		
		for(i=0;i<n;i++) cout<<dist[i]/2<<" ";
		cout<<endl;
	}
	return 0;
}
		
		
