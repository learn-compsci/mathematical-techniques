---
hidden: "true"
---

## Question 2: DeMorgan's Laws

### Part a Solutions:

Draw two truth tables to verify that:

1. $\neg (p \lor q)$ is logically equivalent to $\neg p \land \neg q$.
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

These two equivalences (known as **De Morgan's Laws**) are among some of the most useful in discrete mathematics. 

|   $p$   |   $q$   | $\neg p$ | $\neg q$ | $p \lor q$ | $\neg (p \lor q)$ | $\neg p \land \neg q$ |
| :-----: | :-----: | :------: | :------: | :--------: | :---------------: | :-------------------: |
| $true$  | $true$  | $false$  | $false$  |   $true$   |      $false$      |        $false$        |
| $true$  | $false$ | $false$  |  $true$  |   $true$   |      $false$      |        $false$        |
| $false$ | $true$  |  $true$  | $false$  |   $true$   |      $false$      |        $false$        |
| $false$ | $false$ |  $true$  |  $true$  |  $false$   |      $true$       |        $true$         |
Hence, $\neg (p \lor q)$ and $\neg p \land \neg q$ are logically equivalent. 

|   $p$   |   $q$   | $\neg p$ | $\neg q$ | $p \land q$ | $\neg (p \land q)$ | $\neg p \lor \neg q$ |
| :-----: | :-----: | :------: | :------: | :---------: | :----------------: | :------------------: |
| $true$  | $true$  | $false$  | $false$  |   $true$    |      $false$       |       $false$        |
| $true$  | $false$ | $false$  |  $true$  |   $false$   |       $true$       |        $true$        |
| $false$ | $true$  |  $true$  | $false$  |   $false$   |       $true$       |        $true$        |
| $false$ | $false$ |  $true$  |  $true$  |   $false$   |       $true$       |        $true$        |

Hence, $\neg (p \land q)$ and $\neg p \lor \neg q$ are logically equivalent. 

### Part b Solutions:

To see how these equivalences may be used, let $p$ be the statement "It is raining" and let $q$ be the statement "It is cold". Match each of the following statements with its logically equivalent; you might rewrite each statement using $p$ and $q$ to assist you.

Statements: 
1. It is not the case that it is raining or cold.
2. It is not raining or it is not cold.
3. It is not raining and it is not cold. 
4. It is not the case that it is both raining and cold.

Rewriting the 4 statements using $p$ and $q$, we get:

1. $\neg (p \lor q)$
2. $\neg p \lor \neg q$
3. $\neg p \land \neg q$
4. $\neg (p \land q)$

Using De Morgan's Laws, **statements 1 and 3 and logically equivalent**, and **statements 2 and 4 are logically equivalent**.




## Question 3 Solutions:

Let:
- $R=\{A,B,C\}$ be the set of circles,
- $S=\{E,G,H,J\}$ be the set of squares,
- $T=\{D,F,I\}$ be the set of triangles, and
- $U=\{A, B, C, D, E, F, G, H, I\}$ be the set containing all the all the objects.

You are also given the following predicates, which you may use freely in your answers:
- $Above(x,y)$ is true when object $x$ is above object $y$ in the grid.
- $Blue(x)$ is true when object $x$ is blue.
- $Grey(x)$ is true when object $x$ is grey.
- $Orange(x)$ is true when the object $x$ is orange.
- $Circle(x)$ is true when the object $x$ is a circle
- $Square(x)$ is true when $x$ is a square object.
- $Triangle(x)$ is true when $x$ is a triangular object.

Determine whether the following statements are true or false for the picture:
1. $\exists u \in U \: (Orange(u) \land Triangle(u))$
2. $\forall u \in U \: (Circle(u)\rightarrow Blue(u))$
3. $\forall s \in S, \exists t \in T \: (Above(t, s))$
4. $\forall r \in R, \forall s \in S \: (Above(r, s))$
5. $\exists u \in U, \forall r \in R \: (Above(u, r))$
6. $\exists r \in R, \exists t \in T \: (Black(r) \lor \neg Orange(t))$

![[tarskis-drawn.png|500]]

**Solution:**

1. $\exists u \in U \: (Orange(u) \land Triangle(u))$
   **True**; let that object $u$ be the orange triangle $F$.

2. $\forall u \in U \: (Circle(u)\rightarrow Blue(u))$
   **False**; consider letting the object $u$ be the orange circle $b$. 
	- The predicate $Circle(b)$ is true.
	- The predicate $Blue(b)$ is false.
	- But, $Circle(b) \rightarrow Blue(b)$ evaluates to false.
	 Since $\forall u \in U \: (Circle(u)\rightarrow Blue(u))$ is stating that: "For every object $u$, if $u$ is a circle then $u$ is blue", and we have found a circle that is not blue, the statement is false.

3. $\forall s \in S, \exists t \in T \: (Above(t, s))$
   **True**; no matter which square $s$ is picked, we can always find at least one triangle $t$ such that $t$ lies above $s$ in the grid: consider triangle $d$, it is above all squares.

4. $\forall r \in R, \forall s \in S \: (Above(r, s))$ 
   **True**; no matter which circle $r$ and which square $s$ are picked from the sets of circles and squares, $r$ will lie above $s$ in the grid, since all the circles lie above all the squares.

5. $\exists u \in U, \forall r \in R \: (Above(u, r))$
   **False**; no matter which object $u$ is picked, we can always find at least circle $r$ such that $u$ does not lie above $r$, since there is no object that lies above the circle $a$.

6. $\exists r \in R, \exists t \in T \: (Black(r) \lor \neg Orange(t))$
   **True**; consider letting the object $r$ be the blue circle $a$ and letting the object $t$ be the black triangle $d$.
	- The predicate $Black(a)$ is false.
	- The predicate $Orange(d)$ is false, and so $\neg Grey(d)$ is true.
	- Thus, $Black(a) \lor \neg Grey(d)$ evaluates to true.



## Question 5 Solutions:
### Part a:
1. (True)  $\forall x \in \mathbb{N}, \exists y \in \mathbb{Z}, (x = y)$
2. (False) $\forall p, q \in \mathbb{Q}, (q = p)$
3. (False) $\forall a, b, c \in \mathbb{Z}, (a = 3b \lor a = 5c)$ 
4. (True) $\forall x \in \mathbb{Z}, \exists y, z \in \mathbb{Q}, (x = 3y \land a = 5z)$      
5. (True) $\exists p, q \in \mathbb{Z}, \forall r \in \mathbb{Z},(p + q \neq r)$
6. (False) $\forall a, b \in \mathbb{Z}, (a^2 = b^2 \implies a = b)$
### Part b:
1. (True) $\forall a, b \in \mathbb{Z}, (a^2 \neq b^2 \implies a \neq b)$
2. (True) $\forall p \in \mathbb{Z},  (p > 5 \land p \leq 26\implies p \geq 0)$
3. (True) $\forall x \in \mathbb{Z}, (\forall y \in \mathbb{N}, (x \neq y) \implies x \leq 5)$

