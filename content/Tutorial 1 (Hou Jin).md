## Question 4

In the diagram below, let $T=\{d,f,i\}$ be the set of triangles, $C=\{a,b,c\}$ be the set of circles, $S=\{e,g,h,j\}$ be the set of squares, and let $W=\{a,b,c,d,e,f,g,h,i,j\}$ be the universal set containing all the objects. 

You are also given the following predicates, which you may use freely in your answers:
- $Above(x,y)$ means that object $x$ is above object $y$ in the grid
- $Blue(x)$ means that object $x$ is blue; and the respective predicates $Black(x)$ and $Grey(x)$
- $Circle(x)$ means that object $x$ is a circle; and the respective predicates $Triangle(x)$ and $Square(x)$

Determine whether the following statements are true or false.
1. $\exists w \in W \: (Grey(w) \land Triangle(w))$ --> True
2. $\forall w \in W \: (Circle(w)\rightarrow Blue(w))$ --> False
3. $\forall s \in S, \exists t \in T \: (Above(t, s))$ --> True
4. $\forall c \in C, \forall s \in S \: (Above(c, s))$ --> True
5. $\exists w \in W, \forall t \in T \: (Above(t, w))$ --> False
6. $\exists c \in C, \exists t \in T \: (Black(c) \lor \neg Grey(t))$ --> True

![[Tarski's World.png]]

## Question 5

The **contrapositive** of the statement $p\rightarrow q$ is $\neg q\rightarrow \neg p$. Draw a truth table to verify that the statements are logically equivalent.

## Question 6

Draw two truth tables to verify that:

1. $\neg (p \lor q)$ is logically equivalent to $\neg p \land \neg q$.
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

These two equivalences (known as **De Morgan's Laws**) are among some of the most useful in discrete mathematics. 

To see how these equivalences may be used, let $p$ be the statement "It is raining" and let $q$ be the statement "It is cold". Match each of the following statements with its logical equivalent; you might rewrite each statement using $p$ and $q$ to assist you.

1. It is not the case that it is raining or cold.
2. It is not raining or it is not cold.
3. It is not raining and it is not cold. 
4. It is not the case that it is both raining and cold.

Answers: 
*Statement ___ is logically equivalent to statement ___ .*
*Statement ___ is logically equivalent to statement ___ .*

