## Question 4

In the diagram below, let $T=\{d,f,i\}$ be the set of triangles, $C=\{a,b,c\}$ be the set of circles, $S=\{e,g,h,j\}$ be the set of squares, and let $W=\{a,b,c,d,e,f,g,h,i,j\}$ be the universal set containing all the objects. 

You are also given the following predicates, which you may use freely in your answers:
- $Above(x,y)$ means that object $x$ is above object $y$ in the grid
- $Blue(x)$ means that object $x$ is blue; and the respective predicates $Black(x)$ and $Grey(x)$
- $Circle(x)$ means that object $x$ is a circle; and the respective predicates $Triangle(x)$ and $Square(x)$

Determine whether the following statements are true or false.
1. $\exists w \in W \: (Grey(w) \land Triangle(w))$ --> True
2. $\forall w \in W \: (Circle(w) \implies Blue(w))$ --> False
3. $\forall s \in S, \exists t \in T \: (Above(t, s))$ --> True
4. $\forall c \in C, \forall s \in S \: (Above(c, s))$ --> True
5. $\exists w \in W, \forall t \in T \: (Above(t, w))$ --> False
6. $\exists c \in C, \exists t \in T \: (Black(c) \lor \neg Grey(t))$ --> True

![[Pasted image 20250111225847.png]]
