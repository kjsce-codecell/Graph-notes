## Introduction
Graphs are one of the fundamental data structures in the world of programming that find themselves at the core of a range of various types of problems that otherwise may be tedius to solve.

They can range in difficulty from finding a path on a 2D grid from a start location to an end location, to something as hard as finding the maximum amount of water that you can route through a set of pipes, each of which has a maximum capacity.Knowing the correct data structures to use with graph problems is critical. A problem that appears intractable may prove to be a few lines with the proper data structure.

## Graph terms
Graphs can represent many different types of systems, from a two-dimensional grid,to a map of the internet that shows how long it takes data to move from computer A to computer B. We first need to define what components a graph consists of. 
In fact there are only two, nodes and edges. 
* A **node** (or vertex) is a discrete position in the graph. 
* An **edge** (or connection) is a link between two vertices that can be either directed or undirected and may have a cost associated with it. 
* An **undirected edge** means that there is no restriction on the direction you can travel along the edge. 
So for example, if there were an undirected edge from A to B you could move from A to B or from B to A. 
* A **directed edge** only allows travel in one direction, so if there were a directed edge from A to B you could travel from A to B, but not from B to A. 
An easy way to think about edges and vertices is that edges are a function of two vertices that returns a cost.
> For those that are used to the mathematical description of graphs <br>
> A graph G = {V, E} is defined as a set of vertices, V, and a collection of edges (which is not necessarily a set), E. 
> An edge can then be defined as (u, v) where u and v are elements of V.

## Representing a graph

### List based representation
A tree only allows a node to have children, and there cannot be any loops in the tree, with a more general graph we can represent many different situations. A very common example used is flight paths between cities. If there is a flight between city A and city B there is an edge between the cities. The cost of the edge can be the length of time that it takes for the flight, or perhaps the amount of fuel used.

The way that we will represent this is to have a concept of a node (or vertex) that contains links to other nodes, and the data associated with that node. So for our flight path example we might have the name of the airport as the node data, and for every flight leaving that city we have an element in neighbors that points to the destination. 
Now a basic list based represenation of graph can be done in the following schema:
```
structure node
   [list of nodes] neighbors
   [data]
end

cost(X, Y) := if (X.neighbors contains Y) return X.neighbors[Y];
           else "Not possible"

list nodes;
```
This is a very general way to represent a graph. It allows us to have multiple edges from one node to another and it is a very compact representation of a graph as well. However the downside is that it is usually more difficult to work

### Array Based representation
Representing a graph as a list of nodes is a very flexible method. But usually on topcoder we have limits on the problems that attempt to make life easier for us. Normally our graphs are relatively small, with a small number of nodes and edges. When this is the case we can use a different type of data structure that is easier to work with.

The basic concept is to have a 2 dimensional array of integers, where the element in row i, at column j represents the edge cost from node i to j. If the connection from i to j is not possible, we use some sort of sentinel value (usually a very large or small value, like -1 or the maximum integer). Another nice thing about this type of structure is that we can represent directed or undirected edges very easily.

So for example, the following connection matrix: 
```
A  B  C
A   0  1  5
B  -1  0  1
C  -1 -1  0
```
would mean that node A has a 0 weight connection to itself, a 1 weight connection to node B and 5 weight connection to node C. Node B on the other hand has no connection to node A, a 0 weight connection to itself, and a 1 weight connection to C. Node C is connected to nobody. 

This representation is very convenient for graphs that do not have multiple edges between each node, and allows us to simplify working with the graph. 
