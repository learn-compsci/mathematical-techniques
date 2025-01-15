---
hidden: "true"
---

## Question 4

The **contrapositive** of the statement $p\rightarrow q$ is $\neg q\rightarrow \neg p$. Draw a truth table to verify that the statements are logically equivalent.

## Question 5

Draw two truth tables to verify that:

1. $\neg (p \lor q)$ is logically equivalent to $\neg p \land \neg q$.
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

These two equivalences (known as **De Morgan's Laws**) are among some of the most useful in discrete mathematics. 

To see how these equivalences may be used, let $p$ be the statement "It is raining" and let $q$ be the statement "It is cold". Match each of the following statements with its logical equivalent; you might rewrite each statement using $p$ and $q$ to assist you.

1. It is not the case that it is raining or cold.
2. It is not raining or it is not cold.
3. It is not raining and it is not cold. 
4. It is not the case that it is both raining and cold.

Answers: <br>
*Statement ___ is logically equivalent to statement ___ .*
*Statement ___ is logically equivalent to statement ___ .*

## Question 6

Given the sets $A = \{0,1,4\}$ and $B = \{-2,-1,0,1,2\}$, determine which of the following statements are true.

1. $\exists a \in A \: (a^{2} \in B)$
2. $\forall a \in A \: (a^{2} \in B)$
3. $\forall b \in B, \exists a \in A \: (a = b^{2})$
4. $\exists a \in A, \forall b \in B \: (a = b^{2})$

## Question 7

In the diagram below, let:
- $R=\{a,b,c\}$ be the set of circles,
- $S=\{e,g,h,j\}$ be the set of squares,
- $T=\{d,f,i\}$ be the set of triangles, and
- $U=\{a,b,c,d,e,f,g,h,i,j\}$ be the universal set containing all the objects. 

You are also given the following predicates, which you may use freely in your answers:
- $Above(x,y)$, meaning that object $x$ is above object $y$ in the grid
- $Blue(x)$, meaning that object $x$ is blue; and the respective predicates $Black(x)$ and $Grey(x)$
- $Circle(x)$, meaning that object $x$ is a circle; and the respective predicates $Triangle(x)$ and $Square(x)$

Determine whether the following statements are true or false.
1. $\exists u \in U \: (Grey(u) \land Triangle(u))$
2. $\forall u \in U \: (Circle(u)\rightarrow Blue(u))$
3. $\forall s \in S, \exists t \in T \: (Above(t, s))$
4. $\forall r \in R, \forall s \in S \: (Above(r, s))$
5. $\exists u \in U, \forall r \in R \: (Above(u, r))$
6. $\exists r \in R, \exists t \in T \: (Black(r) \lor \neg Grey(t))$

![[Tarski's World.png]]
