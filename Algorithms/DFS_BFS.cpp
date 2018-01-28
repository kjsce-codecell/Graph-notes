#include<bits/stdc++.h>
#define MAX 100001
using namespace std;


// intializing the graph 
vector<int> v[MAX];

// intializing the visited array
int visited[MAX]={0};

void dfs(int start){
  
  
  cout<<start<<" ";
  
  // mark the current node as visited
  visited[start]=1;
  
  for(int i=0;i<v[start].size();i++)
  {
    
    // loop through all the nodes connected to current node
    // if the node is not alreay marked visit it 
    if(!visited[v[start][i]])
    {
      
      dfs(v[start][i]);
    }
  }
}

void bfs(int start)
{
  
  
  int current;
  queue<int> q;
  
  // push the source node to the queue
  q.push(start);
  
  // loop till the queue is empty
  while(q.size()!=0)
  {
    
    // set current node to the first node in the queue
    current = q.front();
    q.pop();
    
    // if current node isn't marked already visit it
    if(!visited[current])
    {
      cout<<current<<" ";
      visited[current]=1;
    }
    
    for(int i=0;i<v[current].size();i++)
    {
      
      
   
      if(!visited[v[current][i]])
      {
        
        // push all nodes adjacent to the current node to the queue
        cout<<v[current][i]<<" ";
        visited[v[current][i]]=1;
        q.push(v[current][i]);
      }
    }
  }
}

int main()
{
  int n,i,j,k,node,start;
  cout<<"Enter no of nodes in a graph";
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cout<<"Enter no of adjacent nodes"<<endl;
    cin>>k;
    cout<<"Enter the adjacent nodes"<<endl;
    for(j=0;j<k;j++)
    {
      cin>>node;
      v[i].push_back(node);
    }
  }
  cout<<"Enter the starting node:";
  cin>>start;
  cout<<"DFS Traversal:"<<endl;
  dfs(start);
  cout<<endl;
  /* making all elements of visited array 0 */
  for(i=0;i<100001;i++)
    visited[i]=0;
  cout<<"BFS Traversal:"<<endl;
  bfs(start);
  cout<<endl;
  return 0;
}

//OUTPUT

/*

Enter no of nodes in a graph 5
Enter no of adjacent nodes
 3
Enter the adjacent nodes
 2
 3
 5
Enter no of adjacent nodes
 3
Enter the adjacent nodes
 1
 4
 5
Enter no of adjacent nodes
 1
Enter the adjacent nodes
 1
Enter no of adjacent nodes
 1
Enter the adjacent nodes
 2
Enter no of adjacent nodes
 2
Enter the adjacent nodes
 1
 2
Enter the starting node: 1
DFS Traversal:
1 2 4 5 3
BFS Traversal:
1 2 3 5 4

*/
