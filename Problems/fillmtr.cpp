#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx=1e6+2;

vector <pair<ll,ll> > Opp;//a vector that holds opposite pair of vertices
vector <ll> V[mx];//array of vectors to hold all the vertices having same color as given vertex 
ll visited[mx];// visited array for dfs keeps a mark whether a node has been visited
ll color[mx];//gives color of the particular edge

void dfs(ll node,ll colr)
{
	color[node]=colr;//colors that particular node with provided color(0/1) 
	visited[node]=1;// mark the node as visited
	for(auto it:V[node])// mark its linked nodes same color
	{
		if(!visited[it])
		dfs(it,colr);
	}
}

void solve()
{
	for(auto it:Opp)
	{
		ll i=it.first;
		ll j=it.second;
		if(i==j)//if i and j are equal they refer to same element so must be same
		{
			cout<<"no\n";
			return;
		}
		if(!visited[i]&&!visited[j])//if none of them is visited mark any one of them 1 or 0
		{
			dfs(i,1);
			if(visited[j])//if it gets visited in the process then it must have had same color 
			{
				cout<<"no\n";
				return;	
			}
			dfs(j,0);
		}
		else if(visited[i]&&!visited[j])//if one is visited mark other one the opposite color
		dfs(j,1-color[i]);
		else if(visited[j]&&!visited[i])
		dfs(i,1-color[j]);
		else// if both are visited check for opp color
		{
			if(color[i]==color[j])
			{
				cout<<"no\n";
				return;
			}
		}
	}
	cout<<"yes\n";
}

int main()
{
	ll t=1;
	scanf("%lld",&t);
	while(t--)
	{
		ll n,q,i,j,diff;
		scanf("%lld%lld",&n,&q);// input no. of elements and queries
		Opp.clear();
		for(ll i=1;i<=n;i++)
		{
			visited[i]=0;//set visited to 0 that is unvisited
			color[i]=-1;
			V[i].clear();//clearing away vectors
		}
		for(ll k=0;k<q;k++)
		{
			scanf("%lld%lld%lld",&i,&j,&diff);//take the i,j and b[i][j]
			if(!diff)
			{
				V[i].push_back(j);
				V[j].push_back(i);
			}
			else
			Opp.push_back(make_pair(i,j));
		}
		solve();
	}
}
