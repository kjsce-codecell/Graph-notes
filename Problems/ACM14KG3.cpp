/*
Problem Link : https://www.codechef.com/problems/ACM14KG3

SOLUTION 1 : Using DFS
SOLUTION 2 : Using Floyd Warshall
*/
#include "bits/stdc++.h"
using namespace std ;

#define ll long long int

/*

 1 - Possible
 -1 - Impossible
 0 - not visited
 */

int main(){
        ll t , i ;
        scanf(" %lli",&t);
       	while(t--){
       		int arr[27][27] = {0};
			string a,  b  , tp , ans = "NO\n";
        	cin>>a ;
        	cin>>b ;
        	ll m , n ;
        	scanf(" %lli",&m);
        	vector<char> graph[27];
        	for(i=0;i<m;i++){
        		cin>>tp ;
				graph[tp[0]-97].push_back(tp[3]);
        		arr[tp[0]-97][tp[3]-97]  = 1 ;
        	}

        	n = a.length();
        	m = b.length();

        	if(!(n-m)){
        		ll flag = 1;

				for(i=0;i<n;i++){
					if(a[i]!=b[i]){
						ll source , dest ;
						source = a[i]-97 ;
						dest = b[i]-97 ;
						ll get =  0 ;
						if(!arr[source][dest]){
							// dfs
							int visited[27] = {0};
							visited[a[i]-97] = 1;
							stack<ll> stk ;
							stk.push(source);
							int top ;
							while(!stk.empty()){
								top = stk.top();
								stk.pop();
								vector<char>::iterator c ;
								for(c = graph[top].begin();c!=graph[top].end();c++){
									arr[source][*c-97] = 1;
									if((*c-97) == dest or arr[*c-97][dest]){
										get = 1;
										goto found;
									}
									if(!visited[*c-97]){
										visited[*c-97] =  1;
										stk.push((*c-97));
									}
								}
							}

							if(!get){
								flag = 0 ;
								break;
							}
							found:
								true;
						}
					}
				}
				if(flag)
					ans = "YES\n";
			}
			cout<<ans;
        }
        return 0;
}
