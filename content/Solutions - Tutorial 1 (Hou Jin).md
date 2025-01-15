## Question 4

The **contrapositive** of the statement $p\rightarrow q$ is $\neg q\rightarrow \neg p$. Draw a truth table to verify that the statements are logically equivalent.

**Solution:**

|   $p$   |   $q$   | $\neg q$ | $\neg p$ | $p \rightarrow q$ | $\neg q \rightarrow \neg p$ |
| :-----: | :-----: | :------: | :------: | :---------------: | :-------------------------: |
| $true$  | $true$  | $false$  | $false$  |      $true$       |           $true$            |
| $true$  | $false$ |  $true$  | $false$  |      $false$      |           $false$           |
| $false$ | $true$  | $false$  |  $true$  |      $true$       |           $true$            |
| $false$ | $false$ |  $true$  |  $true$  |      $true$       |           $true$            |

Since the truth values of the columns $p \rightarrow q$ and $\neg q \rightarrow \neg p$ are the same in all four rows, the two statements are logically equivalent.

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

**Solution:**

|   $p$   |   $q$   | $\neg p$ | $\neg q$ | $p \lor q$ | $\neg (p \lor q)$ | $\neg p \land \neg q$ |
| :-----: | :-----: | :------: | :------: | :--------: | :---------------: | :-------------------: |
| $true$  | $true$  | $false$  | $false$  |   $true$   |      $false$      |        $false$        |
| $true$  | $false$ | $false$  |  $true$  |   $true$   |      $false$      |        $false$        |
| $false$ | $true$  |  $true$  | $false$  |   $true$   |      $false$      |        $false$        |
| $false$ | $false$ |  $true$  |  $true$  |  $false$   |      $true$       |        $true$         |

|   $p$   |   $q$   | $\neg p$ | $\neg q$ | $p \land q$ | $\neg (p \land q)$ | $\neg p \lor \neg q$ |
| :-----: | :-----: | :------: | :------: | :---------: | :----------------: | :------------------: |
| $true$  | $true$  | $false$  | $false$  |   $true$    |      $false$       |       $false$        |
| $true$  | $false$ | $false$  |  $true$  |   $false$   |       $true$       |        $true$        |
| $false$ | $true$  |  $true$  | $false$  |   $false$   |       $true$       |        $true$        |
| $false$ | $false$ |  $true$  |  $true$  |   $false$   |       $true$       |        $true$        |
Hence the two pairs of statements are logically equivalent.

Rewriting the 4 statements using $p$ and $q$, we get:

1. $\neg (p \lor q)$
2. $\neg p \lor \neg q$
3. $\neg p \land \neg q$
4. $\neg (p \land q)$

Using De Morgan's Laws, **statements 1 and 3 and logically equivalent**, and **statements 2 and 4 are logically equivalent**.

## Question 6

Given the sets $A = \{0,1,4\}$ and $B = \{-2,-1,0,1,2\}$, determine which of the following statements are true.

1. $\exists a \in A \: (a^{2} \in B)$
2. $\forall a \in A \: (a^{2} \in B)$
3. $\forall b \in B, \exists a \in A \: (a = b^{2})$
4. $\exists a \in A, \forall b \in B \: (a = b^{2})$

**Solution:**

1. **True**, since we can find an $a \in A$ such that $a^{2}$ is in $B$. That value of $a$ could be $0$ or $1$, since $0^{2} = 0 \in B$ and $1^{2} = 1 \in B$ as well.

2. **False**, since we can find an $a \in A$ and yet $a^{2}$ is **not** in $B$. That value of $a$ is $4$, since $4^{2} = 16$, but $16$ is not in $B$.

3. **True**, since for every single element $b$ in $B$, we can find an $a \in A$ such that $a = b^{2}$. 
	- If $b = -2$ or $2$, then $b^{2} = 4$, which is in $A$. 
	- If $b = -1$ or $1$, then $b^{2} = 1$, which is in $A$.
	- If $b = 0$, then $b^{2} = 0$, which is in $A$.

4. **False**, since we are unable to find a single element of $A$ that is simultaneously the square of any element in $B$. 
	- If $a = 0$, then taking $b = 1 \in B$, we find that $a = 0 \neq 1 = b^{2}$.
	- If $a = 1$, then taking $b = 0 \in B$, we find that $a = 1 \neq 0 = b^{2}$.
	- If $a = 4$, then taking $b = -1 \in B$, we find that $a = 4 \neq 1 = b^{2}$.

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

**Solution:**

1. **True**; let that object $u$ be the grey triangle $f$.

2. **False**; consider letting the object $u$ be the grey circle $b$. 
	- The predicate $Circle(b)$ is true.
	- The predicate $Blue(b)$ is false.
	- Thus, $Circle(b) \rightarrow Blue(b)$ evaluates to false.

3. **True**; no matter which square $s$ is picked, one can always find a triangle $t$ such that $t$ lies above $s$ in the grid: consider triangle $d$.

4. **True**; no matter which circle $r$ and which square $s$ are picked, $r$ will lie above $s$ in the grid, since all the circles lie above all the squares.

5. **False**; no matter which object $u$ is picked, one can always find a circle $r$ such that $u$ does not lie above $r$, since there is no object that lies above the circle $a$.

6. **True**; consider letting the object $r$ be the blue circle $a$ and letting the object $t$ be the black triangle $d$.
	- The predicate $Black(a)$ is false.
	- The predicate $Grey(d)$ is false, and so $\neg Grey(d)$ is true.
	- Thus, $Black(a) \lor \neg Grey(d)$ evaluates to true.
