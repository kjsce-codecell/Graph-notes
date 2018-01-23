//  Author : chaitya_62
#include<bits/stdc++.h>

vector< pair<uii,uii> > G[SIZE];
vector< pair<uii,uii> > ::iterator it;
uii dist[SIZE][SIZE];
void addEdge(uii a, uii b, uii w){
	G[a].push_back(make_pair(w,b));
	G[b].push_back(make_pair(w,a));
	return;
}
void addDirectedEdge(uii a, uii b, uii w){
	G[a].push_back(make_pair(w,b));
	return;
}
void printGraph(uii N){
	vector< pair<uii,uii> > ::iterator it;
	for(uii i = 1;i<=N;i++){
		for(it= G[i].begin();it!=G[i].end();it++){
			cout<<i<<" ---> "<<it->second<<" W: "<<it->first<<endl;
		}
	}
	return;

}
void floyd_warshall(uii N){
	for(uii i = 1;i<=N;i++){
		for(uii j = 1;j<=N;j++){
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	for(uii i = 1;i<=N;i++){
		for(it = G[i].begin();it!=G[i].end();it++){
			dist[i][it->second] = it->first;
		}
	}
	for(uii i = 1;i<=N;i++){
		for(uii j = 1;j<=N;j++){
			for(uii k = 1;k<=N;k++){
				if(dist[j][i]!= INF && dist[i][k]!=INF)
				dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
			}

		}
	}

}
int main(){
     	/*Simple test */
	addEdge(1,2,10);
	addEdge(2,3,10);
	addEdge(1,4,2);
	addEdge(2,4,1);
	printGraph(4);
	floyd_warshall(4);
   	cout<<"distances"<<endl;
	for(uii i = 1;i<=4;i++){
		for(uii j = 1;j<=4;j++){
			cout<<i<<" ---> "<<j<<"  : "<<dist[i][j]<<endl;
		}
	}




	return 0;
}
