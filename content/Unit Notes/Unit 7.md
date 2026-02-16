---
title: "Unit 7: Graph Theory"
---
# Overview

In this unit, we will introduce **graph theory**—the final novel—and perhaps an unfamiliar mathematical topic. Graph theory is super useful in modelling ideas. We use graph theory in many ways in computer science, either for re-stating problems in a way that computers can understand, or to analyse and count quantities that we care about.

The goal of this unit is to get you familiarised with basic graph terminology and basic theorems about graphs. So in this unit, there will be far less proving, and a lot more of just building mathematical vocabulary. This is mostly because graphs are quite application focused in computer science, and mostly interesting in their own right from a mathematical perspective. Thus, actually talking about anything interesting should be done from the perspective of the topics using them, like algorithms, or natural language processing, or AI.

Contents:

1. [[#Why Graph Theory?|Motivation for this unit]]
2. [[#Part 1 Basic Definitions|Basic definitions in graph theory]]
3. [[#Part 2 Theorems and Proofs in Graph Theory|Useful theorems in graph theory]]
4. [[#Part 2.1(?) Pigeonhole Principle|Bonus: The pigeonhole principle]]

---
# Part 0: Why Graph Theory?

## Modelling Problems

Have you ever wondered how Google Maps knows how to route you from point A to point B?

![[mrt-map.jpg]]

How does it take a system like the MRT map, and figure out how to get you from, say, Clementi station, to Kent Ridge station?

Or how about in video games: how do non-playing characters know how to move towards you? 
[Here's an example video showing pathfinding in action in a video game](https://www.youtube.com/watch?v=FDI_KadEbU4).

How about your network packets? How does your computer know how to send their requests to the various servers that it does? Sure, you could say "I type in 'google.com' and my computer figures it out for me". But someone had to design that solution, and it comes by first modelling a real-life problem as a graph.

Graph theory is a great way to model problems, models that computers can understand, and models that we can build solutions on.

## Analysing Data Structures

The other reason, as you will see when you come around to algorithms and data structures, is that graph theory helps us understand basic data structures too! So the combinatorial aspect of data structures is useful as well.

---
# Part 1: Basic Definitions

>[!hint] Disclaimer
>As we move away from formal logic and into the realm of graph theory, we shall be less concerned with the pedantry and precision of using formal logic in our descriptions, and focus more on the higher-level concepts and the properties of these objects.
>
>The implication is that occasionally, the descriptions we use may not be 100% rigorous, but hopefully they are *sufficient* to bring the point across. Nonetheless, if you have any questions regarding the content, please feel free to drop your question on the Canvas forum :)

## Graph

>[!info] Definition: Graphs and subgraphs
>Let $V$ be a set of **vertices**/**nodes**, and let $E$ be a set of edges connecting pairs of vertices (i.e., $E \subseteq V \times V)$.
>
>We define a **graph** $G = (V, E)$ to be a pair of sets and vertices.
>
>We also define $H = (V', E')$ to be a **subgraph** of $G$ if $V' \subseteq V$ and $E' \subseteq E$.

For example, we might have a set $V = \{A, B, C, D\}$ of four vertices. These vertices might represent locations (like MRT stations) or network nodes (like routers).

An edge is a pair, like $(A, B)$, which indicates a connection from $A$ to $B$. So here's an example edge set $E = \{(A, B), (D, A), (C, C), (A, D)\}$. Pictorially, it should look like this:

![[graph-1.svg]]



In fact, it's very common to look at graphs pictorially to get a better sense of what is going on.

## Common Types of Graphs

Graphs come in many shapes and forms, and we would like to refer to special cases of them. Let us go through some examples. But in summary, here are four types of graphs that we can have:

- **Undirected graph:** Edges have no direction
- **Directed graph (a.k.a. digraph):** Edges have a direction (represented as arrows)
- **Simple graph:** A graph without loops or multiple edges between the same vertices
- **Multigraph:** Allows multiple edges between two vertices

### Undirected graph

Undirected graphs are when the edge connections are two-way. More formally, for any pair of vertices $u, v \in V$, if both $(u, v)$ and $(v, u)$ are in $E$, then we can call $G = (V, E)$ an undirected graph.

![[graph-undirected.svg]]

For example, with $V = \{A, B, C, D\}$, we can have edges $E = \{(A, B), (B, A), (A, D), (D, A), (C, C)\}$. Here, when we draw undirected graphs, we omit the arrowheads.

### Directed graph

Directed graphs are when the edge connections are one-way. 

![[graph-directed.svg]]

For example, with $V = \{A, B, C, D\}$, we can have edges $E = \{(A, B), (A, D), (D, A), (C, C)\}$. Here, when we draw directed graphs, we include the arrowheads. Now, take note that we can still have two-way connections like between $A$ and $D$, but to do so, we need to have two edges: one from $A$ to $D$, and one from $D$ to $A$.

### Simple graph

Simple graphs are where there are: (i) no self-loops (i.e., a vertex pointing back to itself), and (ii) no duplicate edges.

![[simple-graph.svg]]

For example, with $V = \{A, B, C, D\}$, we can have edges $E = \{(A, B), (A, D), (D, A)\}$. Notice we cannot have the $C$ to $C$ edge, because that is a self-loop.

### Multigraph

Multigraphs are graphs that **can** have duplicate edges, **or** self-loops.

![[multi-graph.svg]]

So for example, with $V = \{A, B, C, D\}$, we can have edges $E = \{(A, B)_1, (A, B)_2, (A, D), (D, A), (C, C)\}$. Notice here we have duplicate edges from $A$ to $B$, and we have a self-loop $C$ to $C$.

## More Terminology in Graph Theory

### Degree

>[!info] Definition: Degree of a vertex
>The **degree** of a vertex $v$ is the number of times $v$ appears as an endpoint of some edge in $E$.

For example:

![[graph-undirected.svg]]

For undirected graphs, we *do not double-count each edge*. Hence, in the example above, we say that $A$ has a degree of $2$ (not $4$, even though the edge connecting $A$ and $B$ is technically represented as two pairs, $(A, B)$ and $(B, A)$).

Also, $B$ has degree $1$, $C$ has degree $2$, and $D$ has degree $1$. It might be a little unintuitive why node $C$ has degree $2$. But that is because $C$ appears as an endpoint twice! Even if it's on the same edge.

In a directed graph on the other hand, there is an **in-degree** and an **out-degree**.

![[graph-directed.svg]]


Node $A$ has out-degree $2$, $B$ has out-degree $0$, $C$ has out-degree $1$, and $D$ has out-degree $1$. On the other hand, every node in this example, has in-degree $1$.

### Path

>[!info] Definition: Paths
>A **path** is a sequence of *distinct* vertices (i.e., a vertex cannot appear twice) where each consecutive pair of vertices is connected by an edge.


![[terminology-example-path.svg]]


For example, a path is something like a sequence $C, D, A, B$.

### Connectivity

>[!info] Definition: Connectivity
>We say that *two vertices* $u, v \in V$ are **connected** if there exists a path between them.
>
>We say that a *graph* $G = (V, E)$ is **connected** if *all* pair of vertices $u, v \in V$ are connected.

Based on the previous example, we know that $C$ and $B$ are connected. We can similarly argue that $C$ is connected to $A$ or $D$, and so on.

### Connected components

>[!info] Definition: Connected components
>In an undirected graph $G$, a **connected component** of $G$ is a maximal set of vertices such that *all* pairs of vertices in that set are connected.
>
>Here, we say that a set of vertices $V_0 \subseteq V$ is maximal if for any $u \notin V_0$, there exists two vertices in the set $V_1 = V_0 \cup \{u \}$ that are not connected.

In an undirected graph, a **connected component** is a maximal set of vertices such that **all** pairs of vertices is connected by a path.

![[terminology-example-connected-component.svg]]

So again, using the previous example, we know that $\{A, B, C, D \}$ is a connected component. If we used any smaller set of vertices like $\{A, C \}$, then it is not maximal—we could have added even more nodes and it would still be connected. On the other hand, something like $\{A, B, C, D, E\}$ is not a connected component because there **exists** pairs of vertices that are not connected.

### Cycle

A **cycle** is a path where the starting vertex is also the ending vertex and no edges or vertices are repeated (other than the starting and ending vertex).

![[terminology-example-cycle.svg]]

So again, using the previous example, we know that $C, D, A, C$ is a cycle; only the first and last vertex in our path has repeated.

## Special Types of Graphs

Let's shift our attention to these three special kinds of graphs: **trees**, **bipartite graphs** and **complete graphs**.

### Tree

>[!info] Definition: Trees
>A graph $G = (V, E)$ is a **tree** if it is *connected* and *has no cycles* (acyclic).
>
>Alternatively, a tree is a graph where:
>- All vertices are connected to each other
>- $\lvert E \rvert = \lvert V \rvert - 1$

So here's an example:

![[tree-illustration.png]]


If you want, count the nodes and the edges—you'll realise that we have $7$ nodes, and exactly $7 - 1 = 6$ edges. Furthermore, all the nodes can reach each other.

Typically (but not always), we will also specify what the **root** of the tree is. In the drawn example above, $A$ is our **root** node. Now that we have established a root node, we can start talking about the other important names have for the special case of trees.

When heading "away" from the root, we say that we "traverse from **parents** to **children**". For example, we can head "away" from $B$ by moving from node $B$ to node $D$, so we call $B$ the **parent** of $D$. Similarly, this means that $D$ is the **child** of $B$. In our diagram, $B$ has two children: $C$ and $D$. You might want to think about how every node only has at most $1$ parent, and never $2$ or more.

Also, when we reach a node that has no children, that node is called a **leaf**. So in this tree, we have $4$ leaves: $C$, $D$, $F$ and $G$. Any node that has children is called an **internal node**. So here, $A, B, E, G$ are internal nodes.

Lastly, if **every node** in a given tree has **at most** $k$ children, we say the tree is $k$-ary. For example, a tree where each node has at most $2$ children is called a $2$-ary or binary tree. Hence, the tree in our example is a $3$-ary tree.

### Bipartite graph

A graph $G = (V, E)$ is bipartite if we can take its vertices and divide them into two disjoint sets and $X, Y \subseteq V$, such that every edge connects a vertex across the two sets $X$ and $Y$, and never within the sets themselves. So let's do an example:

![[graph-bip-4.svg]]

The graph on the left is bipartite. Why? Put nodes $A$ and $D$ in set $X$, and nodes $B$, $C$ and $E$ in set $Y$. Then the only edges are crossing between set $X$ and $Y$. To make it obvious, we can shift the nodes around a little bit so that the nodes in $X$ are on the left, and nodes in $Y$ are on the right.

Also if you're curious, could we have done $X = \{A, D, E\}$ and $Y  = \{B, C\}$ instead? The answer is yes!

What about this graph instead? Is it bipartite?

![[graph-bip-5.svg]]

You might notice no matter how hard you try to form the sets $X$ and $Y$, there's always an edge that is either within set $X$ or within set $Y$. Why can't we do it? The idea is that this an **odd length cycle**—if a graph every contains an odd length cycle, it is not bipartite. If the graph does not contain any odd length cycles (i.e. we can never make one), then it is bipartite.

## Complete graph

Lastly, let's talk about complete graphs.

>[!info] Definition: Complete graphs
>An *undirected* graph $G = (V, E)$ is **complete** if every pair of nodes has an edge between them.
>
>The complete graph with $n$ nodes is sometimes denoted $K_n$.


![[k5.svg]]

For five nodes, this is what the complete graph $K_5$ looks like. 


![[k4.svg]]

On the other hand, this is what the complete graph $K_4$ looks like.

### Complement graphs

On the topic of complete graphs, we can now talk about the **complement** of a graph.

>[!info] Definition: Complement of a graph
>Given a graph $G = (V, E)$, the **complement** of $G$ (denoted $\bar{G}$) is the graph that contains the same set of nodes $V$, but if $(u, v)$ is an edge in $G$, then it is not an edge in $\bar{G}$. Likewise, if $(u, v)$ was *not* an edge in $G$, then it *is* an edge in $\bar{G}$.

Here's an example:

![[complement.svg]]

$G$ here has $4$ nodes, and notice that since $(A, C)$ is an edge in $G$, $A$ and $C$ are not connected in $\bar{G}$. Similarly, since $A$ and $D$ are not connected in $G$, they are connected in $\bar{G}$. 

One thing you might want to take note is that if we take the union of the edge set from $G$ and the edge set from $\bar{G}$, we get back the complete graph.

---
# Part 2: Theorems and Proofs in Graph Theory

Okay, let's do a few theorems about graphs. I have chosen the three most useful ones that I know.

## Theorem 1: Handshake Lemma

>[!info] Theorem 1: Handshake Lemma
>The sum of the degrees of all vertices of an undirected graph is twice the number of edges. In other words:
>
> $$
> \sum_{v \in V} deg(v) = 2\cdot |E|
> $$

Let's see an example of this:

![[handshake.svg]]

Notice that we have $4$ edges, and $deg(A) + deg(B) +deg(C) +deg(D) = 3 + 1 + 2 + 2 = 8 = 2\cdot 4$. Wow! But why does it work? 

>[!tldr] Intuition
>Each edge $e = (u, v)$ contributes exactly $2$ to the total sum—once for adding $1$ to the degree of node $u$, then once again adding $1$ to the degree of node $v$. Thus, this process increments our sum $\sum_{v \in V} deg(v)$ twice, so each edge contributes a total of $2$ to the sum.
>
>Since each edge contributes $2$, this means the sum is $2 \cdot |E|$.

### Theorem 2: Number of Edges in a Complete Graph

>[!info] Theorem 2: Number of edges in $K_n$
>The number of edges in a complete graph $G$ with $n$ vertices is:
>
> $$
> \binom{|V|}{2} = \frac{|V|(|V| - 1)}{2}
> $$

So again you might have noticed, for example, a graph with $4$ nodes has $4 \times 3 \div 2 = 6$ edges.

![[k4.svg]]

There are two ways to prove this fact for a general graph:

>[!tldr] Intuition 1 (Using combinatorics)
>If you think about it, every pair of vertices that we can form from the set $V$ makes an edge. This means that the number of edges is the same as the number of possible pairings. This happens to be:
> 
> $$
> \binom{|V|}{2}
> $$

Short and sweet!

>[!tldr] Intuition 2 (Using the handshake lemma) 
>There is another way that actually uses what we've learned here today. Think about it this way, in a complete graph with $|V|$ vertices, every node $x \in V$ has **exactly** $|V| - 1$ other nodes that it is connected to. Because of that, every node $x \in V$ has degree **exactly** $|V| - 1$. So, via the handshake lemma:
> 
> $$
> 2|E| = \sum_{v \in V} deg(v) = \sum_{v \in V} (|V| - 1) = |V| \times (|V| - 1)
> $$
> 
>Dividing both sides by $2$, we get:
> 
> $$
> |E| = \frac{|V|(|V| - 1)}{2}
> $$

## Theorem 3: Number of Nodes in a $k$-ary Tree

Lastly, this fact is super useful (combinatorially) in computer science:

>[!info] Theorem 3: Number of nodes in a $k$-ary tree
>Given a graph $G = (V, E)$ that is a $k$-ary rooted tree of height $h$, then:
>- The minimum number of nodes in the tree is $h + 1$.
>- The maximum number of nodes in the tree is $\frac{k^{h+1} - 1}{k - 1}$.


![[k-ary.svg]]

Here's an example with a $3$-ary (or ternary) tree of height $h = 2$. At the minimum, we can have $3$ nodes. And at the maximum, we can have $1 + 3 + 9 = 13$ nodes. But what about in general? Here's the idea:

>[!tldr] Intuition
>We need $h + 1$ nodes at least to go from a root to a leaf node that is $h$ hops away. So the minimum is $h + 1$.
>
>To hit the maximum, every internal node will have all $k$ children, and every leaf node again, must have $0$ children. So the total nodes we have are:
> 
> $$
> 1 + 3 + 3^2 + \cdots + 3^h = \sum_{i = 0}^h 3^i = \frac{3^{h + 1} - 1}{3 - 1}
> $$
> 
>(This comes from the formula for the sum of the *geometric progression* with a common ratio of $r = 3$ and initial value $a = 1$.)
>
>But what about in general for a $k$-ary tree? Well just swap out the $3$ for a $k$:
>
> $$
> 1 + k + k^2 + \cdots + k^h = \sum_{i = 0}^h k^i = \frac{k^{h + 1} - 1}{k - 1}
> $$

---
# Part 2.1(?): Pigeonhole Principle

Lastly, let's talk about the pigeonhole principle. This is a little bit of an oddball topic but it's very common to also cover it during combinatorics and graphs. It would be remiss if we did not at least mention it. The pigeonhole principle feels like it's stating the obvious, but it can be used to great effect.

Simply put:

>[!info] Pigeonhole principle
>If we have $n$ pigeons, and $m$ pigeonholes, and each pigeon wants to nest in a pigeonhole, then there exists at least one pigeonhole that has at least $\lceil \frac{n}{m} \rceil$ pigeons that are nesting in it.

This sounds a little obvious, for example with $4$ pigeons and $3$ holes, there is definitely a hole with at least $2$ pigeons. But here's an example statement we could possible argue with it.

> There are at least $2$ people with the same number of strands of hair on their head in Singapore.

Why is this true? Think about it this way: there are around $6$ million people in Singapore, and the average human has around $100,000$ strands of hair on their head. Let's assume (reasonably) that it's probably impossible for a human to have a million strands of hair. 

So we make $1$ million possible pigeonholes (for each possible hair count), and we let each person be a pigeon. Then, we assign a person to the $x^{\text{th}}$ pigeonhole if they have $x$ strands of hair on their head. Since there are $6$ million people but only $1$ million pigeonholes, there must be at least $6$ people who have the same number of strands of hair on their head!
