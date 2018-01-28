#include<bits/stdc++.h>
#define INF 999
#define n 4

using namespace std;

int fwgraph(int graph[n][n]) {
	int k, shortdist[n][n],i,j;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			shortdist[i][j]=graph[i][j];
 			//we initially define the shortest distance the same as the input distances, considering no intermediate vertices
		}
	}
	
	//We now consider all intermediate vertices uptil n,
	for(k=0;k<n;k++) {
		for(i=0;i<n;i++) {
			for(j=0;j<n;j++) {
				if(shortdist[i][k]+shortdist[k][j]<shortdist[i][j]) {
					shortdist[i][j]=shortdist[i][k]+shortdist[k][j];
				}
			}
		}
	}

	print(shortdist);
}

int print(int shortdist[n][n]) {
	int i,j;
	cout<<" The following elements show the shortest distance b/w the respective vertices: "<<endl;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(shortdist[i][j]==INF) 
				cout<<" INF ";
			else 
				cout<<" "<<shortdist[i][j]<<" ";
		}
		cout<<endl;
	}

}
int main() {
	int graph[n][n]={ 
				{0 , 3 , INF , 10},
		      	{INF , 0 , 5 , INF},
		        {INF , INF , 0 , 7},
		      	{INF , INF , INF , 0}
		      	};
	fwgraph(graph);
	return 0;
}

/*The output given by this will be:
The following elements show the shortest distance b/w the respective vertices:
 0  3  8  10
 INF  0  5  12
 INF  INF  0  7
 INF  INF  INF  0*/
