---
title: CS1231S Tutorial 11 Solutions
tags:
  - tutorial
hidden:
---
# Question 1

## Part (a)

![[Images/graph-complement.png]]

## Part (b)
Graphs with 3 vertices and 6 vertices cannot be self-complementary. Because only graphs with $n$ nodes where $n \equiv 1 (mod 4)$ or $n \equiv 0 (mod 4)$. Why? Because a self-complementary graph must have $\frac{(n-1)n}{2} \cdot \frac{1}{2} = \frac{(n - 1)n}{4}$ edges. So if both $n$ and $n - 1$ were not divisible by $4$, $G$ and $\bar{G}$ do not have the same number of edges to begin with.

This means we only have to think about $n = 4$ and $n = 5$.

For $n = 4$ we have:
![[Images/g4-self-complement.png]]

For $n = 5$ we have:
![[Images/g5-self-complement.png]]

# Question 2

![[Images/counting-mst.png]]

So here's the idea: there are $4$ choices of edges to remove in the blue box, and 3 choices of edges to remove in the green triangle to make it a tree. So there are exactly $4 \times 3$ spanning trees.

# Question 3

Let's do the first 3 first:
![[Images/1-2-3-trees.png]]

Now $n=4$ has two choices:
![[Excalidraw/tree-size-4|tree-size-4]]

## Part (b)
$n = 1$ has $1$ way.
$n = 2$ has $1$ way.
For $n = 3$, there are $3$ choices of what label to put for the center node.
for $n = 4$, in the straight line path, there are $4!$ permutations, but we cannot distinguish among the inner vertices, and we cannot distinguish among the outer vertices. E.g. a-b-c-d is the same as d-c-b-a. So $4!/2 = 12$. But we also have the other case to deal with. In that case, we have $4$ choices for what is the center node. So $12 + 4 = 16$ choices in total.

# Question 4
1. Assume that $G = (V, E)$ is connected. Thus, this means that all nodes have a path to each other.
2. This means that $G$ has a $T$ has a sub-graph that is also a spanning tree.
3. Now $T$ has $n$ nodes, and therefore it has $n - 1$ edges. Call the set of these edges as $F$.
4. Now $F \subseteq E$. Therefore $\lvert F \rvert \leq \lvert E \rvert$.

On the other hand just because we have more than $n - 1$ edges does not mean we have a connected graph. For example:

![[Images/more-edges-but-unconnected.png|400]]

# Question 6

1. Let $G$ be a tree.
2. Since $G$ is a tree, it is connected. Thus there is a path between any pair of vertices.
3. Assume of the sake of contradiction that exists $v_1, v_2$ such that there are at least two distinct paths between $v_1$ and $v_2$.
	1. Then $G$ contains a cycle.
	2. But $G$ is a tree so it has no cycles.
4. Contradiction. Therefore there is only exactly 1 path between all vertices $v_1$ and $v_2$.

 1. Let $G$ be a graph such that between any two pairs of vertices $v_1$ and $v_2$, there exists a unique path between them.
 2. Thus $G$ is connected. Therefore it suffices to show that $G$ is cycle-free.
 3. Assume for the sake of contradiction that $G$ is not cycle-free.
	 1. Then let $a, b$ be vertices in the cycle.
	 2. Then there are 2 distinct paths from $a, b$.
	 3. This contradicts line 1.
 4. Therefore $G$ is cycle-free.
 5. Thus, $G$ is a tree.

# Question 7
Here's the idea, it doesn't actually matter how we split them into piles, between some pair of stones $a, b$, you'll earn the $1$ dollar for it when it's been separated into different piles. So the game ends when each stone is in its own pile. So really, we're just counting how many different pairings there are. Which is? $\binom{n}{2} = \frac{n(n-1)}{2}$.

# Question 8
Here's the idea:

![[Images/pre-in-tree-construction.png]]

In the pre-order it tells us what we node we see first (which belongs as the root). And if we look for the corresponding in-order, it actually tells us what nodes are to our left of the root.

So here's the algorithm, take the first element of the pre-order. Make that the root of our tree. Then, we split the in-order list into a pair of lists, based on what is to the left of the current node, and what is to the right of the current node. From there, we also create another pair of lists from the pre-order lists, based on what is in the left list and the right list in the in-order. Then by wishful thinking, we can create our left and right trees.

![[Images/tree-construction-wishful-thinking.png]]

The part b answer works the same except for the fact that in post-order, you need to find the current node from the end of the list.

![[Images/post-order-tree-construction.png]]

So we get this tree:
![[Excalidraw/post-order-result|post-order-result]]


