---
hidden: "true"
---
# Question 1 Solutions:

For each of the following, write a propositional formula that accurately represents the given English statement. Use the propositions ***p***, ***q***, ***r***, ***s*** and ***t*** as needed, where:
	$p$ : "The program compiles."
	$q$: "The input is valid."
	$r$ : "The output is correct."
	$s$: "The function is efficient."
	$t$ : "The algorithm terminates."


1. "If the program compiles but the input is not valid, then the output is not correct."

>[!Solutions]
>$(p∧\neg q)  ⟹  \neg r$
>1. Break down the components:
"The program compiles": $p$
"The input is not valid": $\neg q$
"The output is not correct": $\neg r$
>2. Combine using logical operators:
"The program compiles but the input is not valid" is $p∧\neg q$
"If ... then ..." translates to   $⟹$  


2. "The function is efficient if and only if both the algorithm terminates and the output is correct."

>[!Solutions] 
> 
> $s⟺(t∧r)$ or $(s⟹(t∧r)) ∧ ((t∧r)⟹s)$
 > 1. Break down the components:
"The function is efficient": $s$
"The algorithm terminates": $t$
"The output is correct": $r$
"Both ... and ..." is $∧$
>2. Combine using logical operators:
"The algorithm terminates and the output is correct" is $t∧r$
"If and only if" translates to an implication in both directions, ie. $(p⟹q)∧(q⟹p)$


3. "The program compiles and the input is valid, or the function is efficient, but the algorithm does not terminate."

>[!Solutions] 
> $((p∧q)∨s)∧-t$
>1. Break down the components:
"The program compiles": $p$
"The input is valid": $q$
"The function is efficient": $s$
"The algorithm does not terminate": $-t$
"And": $∧$, "Or": $∨$, "But": treated as ∧ in context.
>2. Combine using logical operators:
"The program compiles and the input is valid" is $p∧q$
"The program compiles and the input is valid, or the function is efficient" is $(p∧q)∨s$
 "But the algorithm does not terminate" adds $∧-t$
> 3. The parenthesis are necessary!


4. "If the program compiles, then either the input is valid and the output is correct, or the algorithm does not terminate."

>[!Solutions] 
> $p  ⟹  ((q∧r)∨¬t)$
> 1. Break down the components:
"The program compiles": $p$
 "The input is valid": $q$
"The output is correct": $r$
"The algorithm does not terminate": $¬t$
"Either ... or ..." translates to $∨$
>2. Combine using logical operators:
"The input is valid and the output is correct" is $q∧r$
 "Either the input is valid and the output is correct, or the algorithm does not terminate" is $(q∧r)∨¬t$
"If ... then ..." translates to   $⟹$


5. "The function is efficient if and only if the program compiles and the input is valid, or if the output is correct implies that the algorithm terminates."

>[!Solutions] 
> $s  ⟺  (p∧q)∨(r  ⟹  t)$
> 1. Break down the components:
"The function is efficient": $s$
"The program compiles": $p$
"The input is valid": $q$
"The output is correct": $r$
"The algorithm terminates": $t$
"If ... then ..." translates to   $⟹$ , "If and only if" translates to  ⟺.
>2. Combine using logical operators:
"The program compiles and the input is valid" is $p∧q$
"The output is correct implies that the algorithm terminates" is $r  ⟹  t$
"The function is efficient if and only if" translates to  $s$  ⟺
>3. Combine everything:


---

# Question 2 Solutions:

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


---

# Question 3 Solutions:

Aiken promises Dueet that if Dueet watches anime with him, then Aiken will treat Dueet to a pizza dinner.

a. How would you write this sentence in propositional logic?

>[!Solutions] 
> We let the proposition "Dueet watches anime with Aiken" to be $p$ and "Aiken treats Dueet to a pizza dinner" to be $q$.
> Then we can write this sentence into $p\implies q$


b. Determine whether the promise has been broken in each of the following cases:
1. Dueet watches anime with Aiken, and Aiken treats Dueet to a pizza dinner.
2. Dueet watches anime with Aiken, but Aiken does not treat Dueet to a pizza dinner.
3. Dueet does not watch anime with Aiken, and Aiken treats Dueet to a pizza dinner.
4. Dueet does not watch anime with Aiken, and Aiken does not treat Dueet to a pizza dinner.

>[!Solutions] 
> In the examples we have seen truth tables where different truth values of $p$ and $q$ lead to a different truth value of $p\implies q$. To make sense of this, we can look at this example.
> 
>Case 1 definitely doesn't break the promise. Dueet watches anime, and Aiken keeps his promise. Case 2 breaks the promise because Dueet does his part and watches anime with Aiken, but Aiken didn't buy pizza like he had promised. Up to now it's all very intuitive.
>
>Case 4 doesn't break the promise either; since Dueet didn't do his part, he gets no pizza. 
>But Case 3 doesn't break the promise either! 
>
>Why is this so? In the notes we said that in an implication, we don't really care about what happens when the antecedent is false. An implication, or Aiken's *promise*, only guarantees what happens when the antecedent is true. If we know $p$ is true, we know that $q$ will follow through. It doesn't promise us anything about what happens when the antecedent $p$ is false!
>
>Another example would be buying things from a store. You could pay for a soda, and get the soda (Case 1). Or don't pay for the soda, and leave (Case 4). Or the owner might give it to you as a free gift, and you didn't pay for the soda (Case 3). The only case that is upsetting is when you pay but you don't get the soda (Case 2).


---

# Question 4 Solutions:

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


---

# Question 5 Solutions:

### Part (a) Solutions:

Consider the following first order logic statement:

	$∀x∈D,∃y∈E,(P(x,y)  ⟹  Q(y))$

Write its contrapositive, and prove that they are logically equivalent. 

>[!Solutions] 
> 
The contrapositive of $P  ⟹  Q$  is  $¬Q  ⟹  ¬P$. 
Applying this inside the quantifiers, the contrapositive is $∀x∈D,∃y∈E,(¬Q(y)⟹¬P(x,y))$

### Part (b) Solutions:

Consider the following first order logic statements:
	1. $∃x∈D, P(x)∧Q(x)$
	2. $∀x∈D, P(x)∨Q(x)$
	3. $∀x∈D,∃y∈E, P(x,y)∧Q(y)$
	4. $∃x∈D,∀y∈E, P(x,y)⟹Q(y)$

Write the negation for each of the statements.

#### Part 1 Solutions: 

>[!Solutions] 
> 1. Put a negation sign outside: $-(∃x∈D,P(x)∧Q(x))$
> 2. Using **negation of an existential quantifier**: $∀x∈D,¬(P(x)∧Q(x))$ 
> 3. Using **De Morgan’s Law**: $∀x∈D,¬P(x)∨¬Q(x)$

>[!Further Explanations] 
>Sometimes we may be confused when we see a bunch of mathematical symbols. It certainly takes time to familiarise yourselves with FOL. When it comes to negating these statements, one way to think about it is to translate it into English.
>
>Statement 1 is an existential statement. What is means, essentially, is that there exists some $x$ in set $D$ such that both $P(x)$ and $Q(x)$ is true. To negate it, think of the opposite.
>
>If there exists NO $x$ in set $D$ such that $P(x)$ and $Q(x)$ are both true, this means that for ALL $x$ in set $D$, it either does not satisfy $P(x)$, or it doesn't satisfy $Q(x)$. There is just no $x$ that satisfies both at the same time.
>
>And how would we then write this into FOL? We would write $∀x∈D,¬P(x)∨¬Q(x)$.


#### Part 2 Solutions: 

>[!Solutions] 
> 1. Put a negation sign outside: $¬(∀x∈D,P(x)∨Q(x))$
> 2. Using **negation of an existential quantifier**: $∃x∈D,¬(P(x)∨Q(x))$
> 3. Using **De Morgan’s Law**: $∃x∈D,¬P(x)∧¬Q(x)$

>[!Further Explanations] 
>Statement 2 is a universal statement that says: Every $x$ in set $D$ satisfies $P(x)$ or $Q(x)$ (or both), either one of them is fine. To negate it, think of the opposite.
>
>NOT every $x$ in set $D$ satisfies at least one of $P(x)$ or $Q(x)$. This means that there exists one (or more) $x$ that does not satisfy both $P(x)$ and $Q(x)$.
>
>And then we write this into FOL, $∃x∈D,¬P(x)∧¬Q(x)$.


#### Part 3 Solutions: 

>[!Solutions] 
>1. Put a negation sign outside: $¬(∀x∈D,∃y∈E,P(x,y)∧Q(y))$
>2. Using **negation of a universal quantifier**: $∃x∈D,¬(∃y∈E,P(x,y)∧Q(y)$
>
>3. Using **negation of an existential quantifier**: $∃x∈D,∀y∈E,¬(P(x,y)∧Q(y))$
>4. Using **De Morgan’s Law**: $∃x∈D,∀y∈E,¬P(x,y)∨¬Q(y)$

>[!Further Explanations] 
>Statement 3 is a little more complex. What it means is that for every $x$ in set $D$, there exists some corresponding $y$ in set $E$, such that both $P(x,y)$ and $Q(y)$ are true. To negate this, think of the opposite. 
>
> NOT every $x$ in set $D$ has some corresponding $y$ in set $E$ such that both $P(x,y)$ and $Q(y)$ are true. This means that there should exist (at least one) $x$ in set $D$ where you CANNOT find any $y$ in set $E$ such that *both* $P(x,y)$ and $Q(y)$ are true. In other words, there exists $x$ in set $D$ where for ALL $y$ in set $E$, $P(x,y)$ and $Q(y)$ are not true at the same time (ie. *at least* one of them is not true), so either $P(x,y)$ is not true, or $Q(y)$ is not true, or both.
> 
> Now we just write this into FOL. There exists $x$ in set $D$ where for all $y$ in set $E$, either $P(x,y)$ is not true, or $Q(y)$ is not true. Thus we write $∃x∈D,∀y∈E,¬P(x,y)∨¬Q(y)$.


#### Part 4 Solutions: 

>[!Solutions] 
> 1. Put a negative sign outside: $¬(∃x∈D,∀y∈E,P(x,y)⟹Q(y))$
>
>2. Using **negation of an existential quantifier**: $∀x∈D,¬(∀y∈E,P(x,y)⟹Q(y))$
>
>3. Using **negation of a universal quantifier**: $∀x∈D,∃y∈E,¬(P(x,y)  ⟹  Q(y))$
>
>4. Using **implication law**: $P(x,y)⟹Q(y)≡¬P(x,y)∨Q(y)$, we replace $P(x,y)⟹Q(y)$ with $¬P(x,y)∨Q(y)$, thus we write: $∀x∈D,∃y∈E,¬(¬P(x,y)∨Q(y))$
>
>5. Using **De Morgan’s Law**: $∀x∈D,∃y∈E,¬(¬P(x,y))∧¬Q(y)$
>
>6. Double negation: $¬(¬P(x,y))≡P(x,y)$ thus we get $∀x∈D,∃y∈E,P(x,y)∧¬Q(y)$


>[!Further Explanations] 
>After looking at the statement 3, this one should make more sense. What this statement means is that there exists some $x$ in set $D$ where for all $y$ in set $E$, $P(x,y)\implies Q(y)$ is true. To negate this, think of the opposite.
>
>If there exists NO $x$ in set $D$ where for every $y$ in set $E$ satisfies $P(x,y)\implies Q(y)$, it means that for every $x$ in set $D$, there has to exist some $y$ in set $E$ that doesn't satisfy $P(x,y)\implies Q(y)$, which means that $P(x,y)\implies Q(y)$ is false.
>
>To negate an implication, we use implication law to turn it into something we can work with. So we replace $P(x,y)\implies Q(y)$ with $¬P(x,y)∨Q(y)$, and then negate it, which gives us $¬(¬P(x,y)∨Q(y))$. Then we use De Morgan's Law to further simplify into $P(x,y)∧¬Q(y)$
>
>In other words, for every $x$ in set $D$, there exists some $y$ in set $E$, such that $P(x,y)∧¬Q(y)$. Now we just have to translate this into FOL, and we have $∃x∈D,∀y∈E,P(x,y)⟹Q(y)$.

