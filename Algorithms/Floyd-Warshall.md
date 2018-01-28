### Floyd-Warshall

Floyd warshall’s algorithm is used to find the shortest path between two vertices of a graph. It is mostly used for weighted, directed graphs.
Suppose we have a weighted directed graph:

<p align = "center">
<img src ="https://i0.wp.com/www.techiedelight.com/wp-content/uploads/Floyd-Warshall-Algorithm.png?resize=190%2C193">
</p>

Here, we make a 2-d array storing the distance of a particular vertex from all other vertices. The distance of a vertex from itself is 0, and we assume the distance of a vertex from another vertex which is not joined to it directly as infinite(basically a large number).

So, our 2-d array looks like this:
```cpp
	graph[][]={
                {0 , INF , -2 , INF},
                {4 , 0 , 3 , INF},	   //1 to 0 is INF because the graph is directed from 0 to 1 and not 1 to 0
                {INF , INF , 0 , 2},
                {INF , -1 , INF , 0}
             }
```

The algorithm states that, for graph[i][j], there are two possibilities:
- There is an intermediate point k, such that distance of graph[i][k]+graph[k][j] is less than graph[i][j], then the shortest distance between points i and j is the distance from i to k plus distance from k to j. Given that if we are considering k, then all intermediate points {1,2,3…k-1} have been already considered.

- The distance for i to j is less than i to k plus k to j. In that case we do not update the answer matrix
