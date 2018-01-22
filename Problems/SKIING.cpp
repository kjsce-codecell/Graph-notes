/*
 Problem Link : https://www.codechef.com/problems/SKIING
 */

#include "bits/stdc++.h"
using namespace std ;

#define MOD 1e9 + 7
#define debug {cerr<<"\nWorks fine till line : "<<__LINE__<<"\n";}
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ull unsigned long long int 
#define ll long long int 

ll visited[1005][1005], mat[1005][1005] , n , m;

void solve(ll r, ll c){
	visited[r][c] = 1; 
	if((r+1)<n and mat[r+1][c]<=mat[r][c] and !visited[r+1][c])
		solve(r+1,c);
	if((c+1)<m and mat[r][c+1]<=mat[r][c] and !visited[r][c+1])
		solve(r,c+1);
	if((r-1)>=0 and mat[r-1][c]<=mat[r][c] and !visited[r-1][c])
		solve(r-1,c);
	if((c-1)>=0 and mat[r][c-1]<=mat[r][c] and !visited[r][c-1])
		solve(r,c-1);
}

int main(){
        ll t , i ;
        scanf(" %lli",&t);
       	while(t--){
			ll j;
			memset(visited,0,sizeof(visited));
			scanf(" %lli %lli",&n,&m);
			priority_queue< pair<ll,pair<ll,ll > > > pq ;
        	for(i=0;i<n;++i){
        		for(j=0;j<m;++j){
        			scanf(" %lli",&mat[i][j]);	
        			pq.push(make_pair(mat[i][j],make_pair(i,j)));
        		}
        	}	
        	ll ans = 0  , r , c;
        	while(!pq.empty()){
        		r = pq.top().second.first;
        		c = pq.top().second.second;
        		pq.pop();
        		if(!visited[r][c]){
        			solve(r,c);
        			ans++;	
        		}
        	}
        	printf("%lli\n",ans);
        }
        return 0;
}
