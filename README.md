# MPC-in-DAG
Minimum Path Cover in Directed Acyclic Graphs.

The minimum path cover of a directed graph is a path cover containing the fewest possible paths joining the vertices of the graph. These paths can link any two vertices with any length size (>= 0).

Let, DAG G= (V, A) whose 'n' vertices are named V={1,..,n} Construct a bipartite graph G= (VUV , E) withV={1,.,n} - where{v, w} belongs to E iff (v, w) belongs to A. 
With G so constructed, call the maximal-matching procedure on G to find a maximal matching M* ≤ E for G.Suppose this matching has |M*|=m* edges. Now grow a set of paths P in G, as mentioned in algorithm.

1. Every vertex output is connected at least once with the input of other vertex 
2. There are no unnecessary path joints in the graph.
3. The initial integrity of the directed graph is not compromised.


Minimum path cover can only be used in dag, otherwise it would be considered as shortest path cover problem 


Refrences:http://mradwan.github.io/algorithms/2014/05/02/flows-cuts-and-matchings/
https://www.coursehero.com/file/p1i9k5b/Problem-7-Finding-a-minimum-path-cover-in-a-DAG-A-path-cover-of-a-directed/
