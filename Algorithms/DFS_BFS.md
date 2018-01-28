## Graph traversals

Graph traversal means visiting every vertex and edge exactly once in a well-defined order. While using certain graph algorithms, you must ensure that each vertex of the graph is visited exactly once.

During a traversal, it is important that you track which vertices have been visited. The most common way of tracking vertices is to mark them , most commonly done by mainting a `boolean array` .

|Nodes| A   |      B      |  C | D   |      E      |  F |
|----------|:-------------:|------:|----------|:-------------:|------:|-----:|
| Array | 0 | 1 | 1 | 0 | 0 | 0 |

>  `BFS` and `DFS` are the two most commonly used graph traversal approach .

### Breadth First Search (BFS) 

>As the name BFS suggests, you are required to traverse the graph breadthwise .

BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph `layerwise` (i.e breadthwise) thus exploring the neighbour nodes (nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes.

1. First move horizontally and visit all the nodes of the
2. current layer and then Move to the next layer .

In this case , we use `queue` data structure to maintain the order of traversal of nodes so as to traverse breadthwise we add it's `unvisited` neighbours(vertices that are directly connected to it) to the queue and move on to the next node in the current layer (i.e breadth) .

```cpp
BFS (G, s)                   //Where G is the graph and s is the source node
      let Q be queue.
      Q.enqueue( s ) //Inserting s in queue until all its neighbour vertices are marked.

      mark s as visited.
      while ( Q is not empty)
           //Removing that vertex from queue,whose neighbour will be visited now
           v  =  Q.dequeue( )

          //processing all the neighbours of v  
          for all neighbours w of v in Graph G
               if w is not visited
                        Q.enqueue( w )             //Stores w in Q to further visit its neighbour
                        mark w as visited.
```

### Depth First Search (DFS) 

> DEPTH first search , as the name suggests ; we explore a particular node untill it's depth and then it's breadthwise neighbours .

The DFS algorithm is a recursive algorithm that uses the idea of backtracking. It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.

Here, the word backtrack means that when you are moving forward and there are no more nodes along the current path, you move backwards on the same path to find nodes to traverse. All the nodes will be visited on the current path till all the unvisited nodes have been traversed after which the next path will be selected.

This recursive nature of DFS can be implemented using stacks. The basic idea is as follows:
Pick a starting node and push all its adjacent nodes into a stack.
Pop a node from stack to select the next node to visit and push all its adjacent nodes into a stack.
Repeat this process until the stack is empty. However, ensure that the nodes that are visited are marked. This will prevent you from visiting the same node more than once. If you do not mark the nodes that are visited and you visit the same node more than once, you may end up in an infinite loop.

```cpp
DFS-iterative (G, s):                                   //Where G is graph and s is source vertex
  let S be stack
  S.push( s )            //Inserting s in stack
  mark s as visited.
  while ( S is not empty):
      //Pop a vertex from stack to visit next
      v  =  S.top( )
     S.pop( )
     //Push all the neighbours of v in stack that are not visited   
    for all neighbours w of v in Graph G:
        if w is not visited :
                 S.push( w )         
                mark w as visited
```

[DFS BFS Algorithm](./DFS_BFS.cpp)

<p align="center">
<img src = "http://www.stoimen.com/blog/wp-content/uploads/2012/09/1.-DFS-vs.-BFS.png">
</p>

[FOOTNOTES](https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/)
