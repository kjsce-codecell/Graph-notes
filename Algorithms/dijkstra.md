# Dijkstra's Algorithm

Whenever you come across a scenario where you have to find the **shortest distance** to a set of points in a **weighted graph** from a **given starting point**,the best possible approach that can be used is **Dijkstra's Algorithm** 

<p align="center">
<img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/9e7d1e7f0beab28be5095491b4edcb51c22f9a6b.gif"/>
</p>

Dijkstra’s algorithm, published in 1959 and named after its creator Dutch computer scientist Edsger Dijkstra, can be applied on a weighted graph. The graph can either be directed or undirected. One stipulation to using the algorithm is that the graph needs to have a nonnegative weight on every edge.

## Approach

In breadth first search(bfs),when the graph is unweighted one can notice the fact that the vertices that are printed before a given vertices will always have a shorter or equal(in case of being neighbours) path length from the root node.What dijkstra does is, it deploys a similar method with tweaks such that now even weights can be considered.


There are certain steps that dijkstra's algorithm follows till it covers all the vertices,which can be abstracted in the following manner:  
* Every time that we set out to visit a new node, we will choose the node with the **smallest** known **distance/cost** to visit first.
* Once we’ve moved to the node we’re going to visit, we will **check** each of its **neighboring nodes**.
* For each neighboring node, we’ll **calculate the distance/cost for the neighboring nodes** by summing the cost of the edges that lead to the node we’re checking from the starting vertex.
* Finally, if the distance/cost to a node is less than a known distance, we’ll **update** the shortest distance that we have on file for that vertex.


These instructions are our golden rules that we will always follow, until our algorithm is done running. So, let’s get to it!

## Pseudo Code
```JAVA
function Dijkstra(Graph, source):
       dist[source]  := 0                     // Distance from source to source is set to 0
       for each vertex v in Graph:            // Initializations
           if v ≠ source
               dist[v]  := infinity           // Unknown distance function from source to each node set to infinity
           add v to Q                         // All nodes initially in Q

      while Q is not empty:                  // The main loop
          v := vertex in Q with min dist[v]  // In the first run-through, this vertex is the source node
          remove v from Q 

          for each neighbor u of v:           // where neighbor u has not yet been removed from Q.
              alt := dist[v] + length(v, u)
              if alt < dist[u]:               // A shorter path to u has been found
                  dist[u]  := alt            // Update distance of u 

      return dist[]
  end function

```

## Example
The following illustrations gives an insight to Djikstra's algorithm implementation. 

* Initialize distances according to the algorithm.

<p align="center">
<img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/8d4c706fa6f7d2d7d6c3c069ef7fd421e9cc0096.png"/>
</p>

* Pick first node and calculate distances to adjacent nodes.

<p align="center">
<img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/a76d0eeba2b890b2bdcb893aa378814fb83a25cb.png"/>
</p>

* Pick next node with minimal distance; repeat adjacent node distance calculations.

<p align="center">
<img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/05d83fbf9850ecfd560a0fcc1607e3a328ec5211.png"/>
</p>

* Final result of shortest-path tree

<p align="center">
<img src="https://ds055uzetaobb.cloudfront.net/image_optimizer/107ecc5021aebaae1967dc296be93b9bcd069403.png"/>
</p>

