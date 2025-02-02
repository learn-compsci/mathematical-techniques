---
hidden: "true"
---
# Question 1 Solutions:

For each of the following, write a propositional formula that accurately represents the given English statement. Use the propositions $p$, $q$, $r$, $s$ and $t$ as needed, where:
	$p$ : "The program compiles."
	$q$: "The input is valid."
	$r$ : "The output is correct."
	$s$: "The function is efficient."
	$t$ : "The algorithm terminates."


1. "If the program compiles but the input is not valid, then the output is not correct."

>[!Solution]
>$(p \land \neg q)  \to \neg r$
>1. Break down the components:
"The program compiles": $p$
"The input is not valid": $\neg q$
"The output is not correct": $\neg r$
>2. Combine using logical operators:
"The program compiles but the input is not valid" is $p \land \neg q$
"If ... then ..." translates to   $\to$  


2. "The function is efficient if and only if both the algorithm terminates and the output is correct."

>[!Solution] 
> 
> $s \leftrightarrow (t \land r)$ or $(s \to (t \land r)) \land ((t \land r) \to s)$
 > 1. Break down the components:
"The function is efficient": $s$
"The algorithm terminates": $t$
"The output is correct": $r$
"Both ... and ..." is $\land$
>1. Combine using logical operators:
"The algorithm terminates and the output is correct" is $t \land r$
"If and only if" translates to an implication in both directions, ie. $(p \to q) \land (q \to p)$


3. "The program compiles and the input is valid, or the function is efficient, but the algorithm does not terminate."

>[!Solution] 
> $((p \land q) \lor s) \land \neg t$
>1. Break down the components:
"The program compiles": $p$
"The input is valid": $q$
"The function is efficient": $s$
"The algorithm does not terminate": $\neg t$
"And": $\land$, "Or": $\lor$, "But": treated as $\land$ in context.
>1. Combine using logical operators:
"The program compiles and the input is valid" is $p \land q$
"The program compiles and the input is valid, or the function is efficient" is $(p \land q) \lor s$
 "But the algorithm does not terminate" adds $\land \neg t$
> 1. The parentheses are necessary!


4. "If the program compiles, then either the input is valid and the output is correct, or the algorithm does not terminate."

>[!Solution] 
> $p  \to  ((q \land r) \lor \neg t)$
> 1. Break down the components:
"The program compiles": $p$
 "The input is valid": $q$
"The output is correct": $r$
"The algorithm does not terminate": $\neg t$
"Either ... or ..." translates to $\lor$
>1. Combine using logical operators:
"The input is valid and the output is correct" is $q \land r$
 "Either the input is valid and the output is correct, or the algorithm does not terminate" is $(q \land r) \lor \neg t$
"If ... then ..." translates to   $\to$


5. "The function is efficient if and only if the program compiles and the input is valid, or if the output is correct implies that the algorithm terminates."

>[!Solution] 
> $s  \leftrightarrow  (p \land q) \lor (r \to  t)$
> 1. Break down the components:
"The function is efficient": $s$
"The program compiles": $p$
"The input is valid": $q$
"The output is correct": $r$
"The algorithm terminates": $t$
"If ... then ..." translates to   $\to$ , "If and only if" translates to  $\leftrightarrow$.
>1. Combine using logical operators:
"The program compiles and the input is valid" is $p \land q$
"The output is correct implies that the algorithm terminates" is $r \to  t$
"The function is efficient if and only if" translates to  $s \leftrightarrow$
>1. Combine everything: $s \leftrightarrow (p \land q) \lor (r \to t)$


---

# Question 2: Negating Propositional Formulae \[Graded Participation]

### Part A Solutions:

Draw two truth tables to verify that:

1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$.
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

|   $p$   |   $q$   | $\neg q$ | $p \to q$ | $\neg (p \to q)$ | $p \land \neg q$ |
| :-----: | :-----: | :------: | :-------: | :--------------: | :--------------: |
| $true$  | $true$  | $false$  |  $true$   |     $false$      |     $false$      |
| $true$  | $false$ |  $true$  |  $false$  |      $true$      |      $true$      |
| $false$ | $true$  | $false$  |  $true$   |     $false$      |     $false$      |
| $false$ | $false$ |  $true$  |  $true$   |     $false$      |     $false$      |

Hence, $\neg (p \to q)$ and $p \land \neg q$ are logically equivalent. 

|   $p$   |   $q$   | $\neg p$ | $\neg q$ | $p \land q$ | $\neg (p \land q)$ | $\neg p \lor \neg q$ |
| :-----: | :-----: | :------: | :------: | :---------: | :----------------: | :------------------: |
| $true$  | $true$  | $false$  | $false$  |   $true$    |      $false$       |       $false$        |
| $true$  | $false$ | $false$  |  $true$  |   $false$   |       $true$       |        $true$        |
| $false$ | $true$  |  $true$  | $false$  |   $false$   |       $true$       |        $true$        |
| $false$ | $false$ |  $true$  |  $true$  |   $false$   |       $true$       |        $true$        |

Hence, $\neg (p \land q)$ and $\neg p \lor \neg q$ are logically equivalent. 

## Part B Solutions:

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

# Question 3 Solutions:

Aiken promises Dueet that if Dueet watches anime with him, then Aiken will treat Dueet to a pizza dinner.

a. How would you write this sentence in propositional logic?

>[!Solution] 
> We let the proposition "Dueet watches anime with Aiken" to be $p$ and "Aiken treats Dueet to a pizza dinner" to be $q$.
> 
> Then we can write this sentence as $p \to q$.


b. Determine whether the promise has been broken in each of the following cases:
1. Dueet watches anime with Aiken, and Aiken treats Dueet to a pizza dinner.
2. Dueet watches anime with Aiken, but Aiken does not treat Dueet to a pizza dinner.
3. Dueet does not watch anime with Aiken, and Aiken treats Dueet to a pizza dinner.
4. Dueet does not watch anime with Aiken, and Aiken does not treat Dueet to a pizza dinner.

>[!Solution] 
> In the examples we have seen truth tables where different truth values of $p$ and $q$ lead to a different truth value of $p\to q$. To make sense of this, we can look at this example.
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
- $U=\{A, B, C, D, E, F, G, H, I\}$ be the set containing all the objects.

You are also given the following predicates, which you may use freely in your answers:
- $Above(x,y)$ is true when object $x$ is above object $y$ in the grid.
- $Blue(x)$ is true when object $x$ is blue.
- $Grey(x)$ is true when object $x$ is grey.
- $Orange(x)$ is true when the object $x$ is orange.
- $Circle(x)$ is true when the object $x$ is a circle
- $Square(x)$ is true when $x$ is a square object.
- $Triangle(x)$ is true when $x$ is a triangular object.

Determine whether the following statements are true or false for the picture:
1. $\exists u \in U \ [Orange(u) \land Triangle(u)]$
2. $\forall u \in U \ [Circle(u)\rightarrow Blue(u)]$
3. $\forall s \in S, \exists t \in T \ [Above(t, s)]$
4. $\forall r \in R, \forall s \in S \ [Above(r, s)]$
5. $\exists u \in U, \forall r \in R \ [Above(u, r)]$
6. $\exists r \in R, \exists t \in T \ [Grey(r) \lor \neg Orange(t)]$

![[tarskis-drawn.png|500]]

**Solution:**

1. $\exists u \in U \ [Orange(u) \land Triangle(u)]$
   **True**; let that object $u$ be the orange triangle $F$.

2. $\forall u \in U \ [Circle(u) \to Blue(u)]$
   **False**; consider letting the object $u$ be the orange circle $b$. 
	- The predicate $Circle(b)$ is true.
	- The predicate $Blue(b)$ is false.
	- But, $Circle(b) \rightarrow Blue(b)$ evaluates to false.
	 Since $\forall u \in U \ [Circle(u)\rightarrow Blue(u)]$ is stating that: "For every object $u$, if $u$ is a circle then $u$ is blue", and we have found a circle that is not blue, the statement is false.

3. $\forall s \in S, \exists t \in T \ [Above(t, s)]$
   **True**; no matter which square $s$ is picked, we can always find at least one triangle $t$ such that $t$ lies above $s$ in the grid: consider triangle $d$, it is above all squares.

4. $\forall r \in R, \forall s \in S \ [Above(r, s)]$ 
   **True**; no matter which circle $r$ and which square $s$ are picked from the sets of circles and squares, $r$ will lie above $s$ in the grid, since all the circles lie above all the squares.

5. $\exists u \in U, \forall r \in R \ [Above(u, r)]$
   **False**; no matter which object $u$ is picked, we can always find at least circle $r$ such that $u$ does not lie above $r$, since there is no object that lies above the circle $a$.

6. $\exists r \in R, \exists t \in T \ [Grey(r) \lor \neg Orange(t)]$
   **True**; consider letting the object $r$ be the blue circle $a$ and letting the object $t$ be the grey triangle $d$.
	- The predicate $Grey(a)$ is false.
	- The predicate $Orange(d)$ is false, and so $\neg Orange(d)$ is true.
	- Thus, $Grey(a) \lor \neg Orange(d)$ evaluates to true.


---

# Question 5 Solutions:

Consider the following first order logic statements:
	1. $∃x∈D \ [P(x) \land Q(x)]$
	2. $∀x∈D \ [P(x) \lor Q(x)]$
	3. $∀x∈D,∃y∈E \ [P(x,y) \land Q(y)]$
	4. $∃x∈D,∀y∈E \ [P(x,y) \to Q(y)]$

Write the negation for each of the statements.

#### Part 1 Solutions:

>[!Solution] 
> 1. Put a negation sign outside: $\neg \bigg(\exists x \in D \ [P(x) \land Q(x)] \bigg)$
> 2. Using **negation of an existential quantifier**: $\forall x \in D \ \bigg[\neg \big(P(x) \land Q(x) \big) \bigg]$ 
> 3. Using **De Morgan’s Law**: $\forall x \in D \ \big[\neg P(x) \lor \neg Q(x) \big]$

>[!Further Explanations] 
>Sometimes we may be confused when we see a bunch of mathematical symbols. It certainly takes time to familiarise yourselves with FOL. When it comes to negating these statements, one way to think about it is to translate it into English.
>
>Statement 1 is an existential statement. What is means, essentially, is that there exists some $x$ in set $D$ such that both $P(x)$ and $Q(x)$ is true. To negate it, think of the opposite.
>
>If there exists NO $x$ in set $D$ such that $P(x)$ and $Q(x)$ are both true, this means that for ALL $x$ in set $D$, it either does not satisfy $P(x)$, or it doesn't satisfy $Q(x)$. There is just no $x$ that satisfies both at the same time.
>
>And how would we then write this into FOL? We would write $\forall x \in D \ \big[\neg P(x) \lor \neg Q(x) \big]$.


#### Part 2 Solutions: 

>[!Solution] 
> 1. Put a negation sign outside: $\neg \bigg(\forall x \in D \ \big[P(x) \lor Q(x)\big] \bigg)$
> 2. Using **negation of an existential quantifier**: $\exists x \in D \ \bigg[\neg \big(P(x) \lor Q(x) \big) \bigg]$
> 3. Using **De Morgan’s Law**: $\exists x \in D \ \big[\neg P(x) \land \neg Q(x) \big]$

>[!Further Explanations] 
>Statement 2 is a universal statement that says: Every $x$ in set $D$ satisfies $P(x)$ or $Q(x)$ (or both), either one of them is fine. To negate it, think of the opposite.
>
>NOT every $x$ in set $D$ satisfies at least one of $P(x)$ or $Q(x)$. This means that there exists one (or more) $x$ that does not satisfy both $P(x)$ and $Q(x)$.
>
>And then we write this into FOL, $\exists x \in D \ \big[\neg P(x) \land \neg Q(x)\big]$.


#### Part 3 Solutions: 

>[!Solution] 
>1. Put a negation sign outside: $\neg \bigg(\forall x \in D,\exists y \in E \ \big[P(x,y) \land Q(y) \big] \bigg)$
>2. Using **negation of a universal quantifier**: $∃x∈D,\neg \bigg(\exists y \in E \ \big[P(x,y) \land Q(y)\big] \bigg)$
>
>1. Using **negation of an existential quantifier**: $\exists x \in D,\forall y \in E \ \bigg[\neg \big(P(x,y) \land Q(y)\big) \bigg]$
>2. Using **De Morgan’s Law**: $\exists x \in D,\forall y \in E \ \big[\neg P(x,y) \lor  \neg Q(y)\big]$

>[!Further Explanations] 
>Statement 3 is a little more complex. What it means is that for every $x$ in set $D$, there exists some corresponding $y$ in set $E$, such that both $P(x,y)$ and $Q(y)$ are true. To negate this, think of the opposite. 
>
> NOT every $x$ in set $D$ has some corresponding $y$ in set $E$ such that both $P(x,y)$ and $Q(y)$ are true. This means that there should exist (at least one) $x$ in set $D$ where you CANNOT find any $y$ in set $E$ such that *both* $P(x,y)$ and $Q(y)$ are true. In other words, there exists $x$ in set $D$ where for ALL $y$ in set $E$, $P(x,y)$ and $Q(y)$ are not true at the same time (ie. *at least* one of them is not true), so either $P(x,y)$ is not true, or $Q(y)$ is not true, or both.
> 
> Now we just write this into FOL. There exists $x$ in set $D$ where for all $y$ in set $E$, either $P(x,y)$ is not true, or $Q(y)$ is not true. Thus we write $\exists x \in D, \forall y \in E \ \big[\neg P(x,y) \lor \neg Q(y)\big]$.


#### Part 4 Solutions: 

>[!Solution] 
> 1. Put a negative sign outside: $\neg \bigg(\exists x \in D,\forall y \in E \ \big[P(x,y) \to Q(y)\big]\bigg)$
>
>1. Using **negation of an existential quantifier**: $\forall x \in D,\neg \bigg(\forall y \in E \ \big[P(x,y) \to Q(y)\big]\bigg)$
>
>1. Using **negation of a universal quantifier**: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(P(x,y) \to  Q(y)\big)\bigg]$
>
>1. Using **implication law**: $P(x,y) \to Q(y) \equiv \neg P(x,y) \lor Q(y)$, we replace $P(x,y) \to Q(y)$ with $\neg P(x,y) \lor Q(y)$, thus we write: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(\neg P(x,y) \lor Q(y)\big)\bigg]$.
>
>1. Using **De Morgan’s Law**: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(\neg P(x,y)\big) \land \neg Q(y)\bigg]$
>
>1. Double negation: $\neg \big(\neg P(x,y)\big) \equiv P(x,y)$, thus we get $\forall x \in D,\exists y \in E \ \big[P(x,y) \land \neg Q(y)\big]$.


>[!Further Explanations] 
>After looking at the statement 3, this one should make more sense. What this statement means is that there exists some $x$ in set $D$ where for all $y$ in set $E$, $P(x,y) \to Q(y)$ is true. To negate this, think of the opposite.
>
>If there exists NO $x$ in set $D$ where for every $y$ in set $E$ satisfies $P(x,y) \to Q(y)$, it means that for every $x$ in set $D$, there has to exist some $y$ in set $E$ that doesn't satisfy $P(x,y) \to Q(y)$, which means that $P(x,y) \to Q(y)$ is false.
>
>To negate an implication, we use implication law to turn it into something we can work with. So we replace $P(x,y) \to Q(y)$ with $\neg P(x,y) \lor Q(y)$, and then negate it, which gives us $\neg \big(\neg P(x,y) \lor Q(y)\big)$. Then we use De Morgan's Law to further simplify into $P(x,y) \lor \neg Q(y)$.
>
>In other words, for every $x$ in set $D$, there exists some $y$ in set $E$, such that $P(x,y) \land \neg Q(y)$. Now we just have to translate this into FOL, and we have $\forall x \in D,\exists y \in E \ \big[P(x,y) \land \neg Q(y)\big]$.


---

# Question 6 Solutions:
### Part A Solutions:
1. (**True**)  $\exists x \in \mathbb{N}, \forall y \in \mathbb{Z} \ [x \neq y]$

>[!Explanation:]
>This is a practice on negating multiple quantifiers in the same statement.
>1. $\neg \big(\forall x \in \mathbb{N}, \exists y \in \mathbb{Z} \ [x = y]\big)$
>2. $\equiv \exists x \in \mathbb{N}, \neg \big(\exists y \in \mathbb{Z} \ [x = y]\big)$ (Negation of universal quantifier)
>3. $\equiv \exists x \in \mathbb{N}, \forall y \in \mathbb{Z}, \big[\neg (x = y)\big]$ (Negation of existential quantifier)
>4. $\equiv \exists x \in \mathbb{N}, \forall y \in \mathbb{Z} \ [x \neq y]$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says that every natural number, is equal to some integer. We know this to be intuitively true, by the definition of the sets of $\mathbb{N}$ and $\mathbb{Z}$.

2. (**False**) $\exists p, q \in \mathbb{Q} \ [q \neq p]$

>[!Explanation:]
>This is a practice on negating multiple objects in the same quantifier.
>1. $\neg \big(\forall p, q \in \mathbb{Q} \ [q = p]\big)$
>2. $\equiv \exists p, q \in \mathbb{Q} \ \big[\neg (q = p)\big]$ (Negation of universal quantifier)
>3. $\equiv \exists p, q \in \mathbb{Q} \ [q \neq p]$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says any 2 rational numbers are equal. 
>>We know this to be  false.

3. (**False**) $\exists a, b, c \in \mathbb{Z} \ [a \neq b \land a \neq c]$ 

>[!Explanation:]
>This is a practice on applying De Morgan's Law.
>1. $\neg \big(\forall a, b, c \in \mathbb{Z} \ [a = b \lor a = c]\big)$
>2. $\equiv \exists a, b, c \in \mathbb{Z} \ \big[\neg (a = b \lor a = c)\big]$ (Negation of universal quantifier)
>3. $\equiv \exists a, b, c \in \mathbb{Z} \ [a \neq b \land a \neq c]$ (De Morgan's Law and negation of equals)
>>**Deciphering the statement:**
>>This statement says when you pick any 3 integers, one of the integers you picked will be equal to one of the other 2 integers. 
>>
>>This is false.

4. (**True**) $\exists x \in \mathbb{Z}, \forall y, z \in \mathbb{Q} \ [x \neq 3y \lor x \neq 5z]$

>[!Explanation:]
>This is another practice on applying De Morgan's Law, but with a little more complexity.
>1. $\neg \big(\forall x \in \mathbb{Z}, \exists y, z \in \mathbb{Q} \ [x = 3y \land x = 5z]\big)$
>2. $\equiv \exists x \in \mathbb{Z}, \neg \big(\exists y, z \in \mathbb{Q} \ [x = 3y \land x = 5z]\big)$ (Negation of universal quantifier)
>3. $\equiv \exists x \in \mathbb{Z}, \forall y, z \in \mathbb{Q} \ \big[\neg (x = 3y \land x = 5z)\big]$ (Negation of existential quantifier)
>4. $\equiv \exists x \in \mathbb{Z}, \forall y, z \in \mathbb{Q} \ [x \neq 3y \lor x \neq 5z]$ (De Morgan's Law and negation of equals)
>>**Deciphering the statement:**
>>This statement is a little tricker to unpack. It says that every integer, is 3 times of some rational number, and 5 times of another rational number.
>>
>>This is true, as for any integer $x$, $3 \cdot \frac{x}{3} = x$ and $5 \cdot \frac{x}{5} = x$, and we know that $\frac{x}{3}$ and $\frac{x}{5}$ are rational numbers.

5. (**False**) $\forall p, q \in \mathbb{Z}, \exists r \in \mathbb{Z} \ [p + q = r]$

>[!Explanation:]
>This is an example of when negating a statement can make it easier to understand.
>1. $\neg \big(\exists p, q \in \mathbb{Z}, \forall r \in \mathbb{Z} \ [p + q \neq r]\big)$
>2. $\equiv \forall p, q \in \mathbb{Z}, \neg \big(\forall r \in \mathbb{Z} \ [p + q \neq r]\big)$ (Negation of existential quantifier)
>3. $\equiv \forall p, q \in \mathbb{Z}, \exists r \in \mathbb{Z} \ \big[\neg (p + q \neq r)\big]$ (Negation of universal quantifier)
>4. $\equiv \forall p, q \in \mathbb{Z}, \exists r \in \mathbb{Z} \ [p + q = r]$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement is not so easy to intuitively determine if it is true just by looking at the original statement, so we will instead consider the negation. 
>>
>>The negation says, any 2 integers added together is equal to another integer.
>>
>>We know this to be true. 
>>Therefore, the original statement must be false.
>>
>>In contrast, the original says, there are 2 integers that are not equal to any integer when added together. Not that it is impossible to tell this is false, but consider how much easier negating the statement made it to digest the statement.

6. (**False**) $\exists a, b \in \mathbb{Z} \ [a^2 = b^2 \land a \neq b]$

>[!Explanation:]
>This is a practice on negating implication statements.
>1. $\neg \big(\forall a, b \in \mathbb{Z} \ [a^2 = b^2 \to a = b]\big)$
>2. $\equiv \exists a, b \in \mathbb{Z} \ \big[\neg (a^2 = b^2 \to a = b)\big]$ (Negation of universal quantifier)
>3. $\equiv \exists a, b \in \mathbb{Z} \ [a^2 = b^2 \land a \neq b]$ (Substitute with a [[Tutorial 1 Solutions#Part a Solutions|logically equivalent proposition]])
>>**Deciphering the statement:**
>>This statement says if the squares of 2 integers are equal, the 2 integers are also equal. 
>>
>>This is false as the square of a number and its negative counterpart are equal. 
>>
>>Important to note is the use of a commonly used logical equivalence to substitute away the implication connective, as that is the easiest way to negate them.


### Part B Solutions:
1. (**True**) $\forall a, b \in \mathbb{Z} \ [a = b \to a^2 = b^2]$

>[!Explanation:]
>This is a practice on finding the contrapositive of a simple implication statement.
>1. $\forall a, b \in \mathbb{Z} \ [a^2 \neq b^2 \to a \neq b]$
>2. $\equiv \forall a, b \in \mathbb{Z} \ [a = b \to a^2 = b^2]$ (Substitution of contrapositive form)
>>**Deciphering the statement:**
>>This statement says if the squares of 2 integers are not equal, the 2 integers are also not equal. 
>>
>>This might be tricky to justify, so let's consider the contrapositive. 
>>
>>The contrapositive says that if 2 integers are equal, the squares of the 2 integers are also equal.
>>
>>Ah, this is significantly easier to justify and imagine.
>>
>>The contrapositive is thus true, making the original statement true.

2. (**True**) $\forall p \in \mathbb{Z} \ \big[(p > 5 \land p \leq 26) \to p \geq 0\big]$

>[!Explanation:]
>This is a practice on finding the contrapositive of an implication statement with connectives.
>1. $\forall p \in \mathbb{Z} \ \big[p < 0 \to (p \leq 5 \lor p > 26)\big]$
>2. $\equiv \forall p \in \mathbb{Z} \ \big[\neg(p \leq 5 \lor p > 26) \to p \geq 0\big]$ (Substitution of contrapositive form)
>3. $\equiv \forall p \in \mathbb{Z} \ \big[(p > 5 \land p \leq 26) \to p \geq 0\big]$ (De Morgan's Law)
>>**Deciphering the statement:**
>>This statement says that any integer more than 5 and less than equal to 26 must be more than equal to 0.
>>
>>This statement is true.
>>
>>Technique of note in this question is the use of De Morgan's Law even when finding a contrapositive. 

3. (**True**) $\forall x \in \mathbb{Z} \ \big(x > 5  \to \exists y \in \mathbb{N} \ [x = y]\big)$

>[!Explanation:]
>This is a practice on finding the contrapositive of an implication statement with quantifiers.
>1. $\forall x \in \mathbb{Z} \ \big(\forall y \in \mathbb{N} \ [x \neq y] \to x \leq 5\big)$
>2. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \neg (\forall y \in \mathbb{N} \ [x \neq y])\big)$ (Substitution of contrapositive form)
>3. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \exists y \in \mathbb{N} \ [\neg (x \neq y)]\big)$ (Negation of universal quantifier)
>4. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \exists y \in \mathbb{N} \ [x = y]\big)$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says that any integer and any natural number, if the numbers are not equal, the integer is less than or equal to 5. 
>>
>>This statement is quite confusing to even approach from this angle, so let's consider the contrapositive.
>>
>>The contrapositive says that any integer greater than 5 has a natural number equal to it.
>>
>>Again, this is significantly easier to justify and digest.
>>
>>The contrapositive is thus true, making the original statement true.


---

# Question 7 Solutions \[Graded Participation]:

Prove the following statement:

> [!Theorem] 
> $\forall x \in \mathbb{Z} \ [\neg (even(x) \land odd(x))]$
> 
> Where we define the predicate $even(x)$ to be: $even(x) \equiv \exists k \in \mathbb{Z} \ [2k = x]$, 
>  and we define the predicate $odd(x)$ to be: $odd(x) \equiv \exists j \in \mathbb{Z} \ [2j + 1 = x]$

>[!Solution]
>1. Let $x \in \mathbb{Z}$, arbitrarily chosen.
>2. Assume for the sake of contradiction that $even(x) \land odd(x)$.
>	1. $even(x)$. \[Specialisation on line 2]
>	2. $\exists k \in \mathbb{Z} \ [2k = x]$. \[Unpacking definition of $even(x)$]
>	3. Let $s \in \mathbb{Z}$ be such that $2s = x$. \[Existential instantiation on line 2.2]
>	4. $odd(x)$. \[Specialisation on line 2]
>	5. $\exists j \in \mathbb{Z} \ [2j + 1 = x]$. \[Unpacking definition of $odd(x)$]
>	6. Let $t \in \mathbb{Z}$ be such that $2t + 1 = x$. \[Existential instantiation on line 2.5]
>	7. Then, we have $2s = 2t + 1$. \[Basic algebra, from lines 2.3 and 2.6]
>	8. $2(s - t) = 1$. \[Basic algebra]
>	9. $s - t = \frac{1}{2}$. \[Basic algebra]
>	10. $\neg (s - t \in \mathbb{Z})$. \[Basic algebra, from line 2.9]
>	11. Since $s \in \mathbb{Z}$ and $t \in \mathbb{Z}$, we have $s - t \in \mathbb{Z}$. \[Basic algebra, from lines 2.3 and 2.6]
>	12. $(s - t \in \mathbb{Z}) \land \neg (s - t \in \mathbb{Z})$. \[Conjunction on lines 2.10 and 2.11]
>	13. $\bot$. \[Contradiction rule on line 2.12]
>3. $\neg \big[even(x) \land odd(x)\big]$. \[Proof by contradiction rule on line 2.13]
>4. $\forall x \in \mathbb{Z} \ \big[\neg (even(x) \land odd(x))\big]$. \[Universal generalisation on lines 1 and 3]

---
# Question 8:
You are tasked with building a load balancer that services $C$ clients, and has to balance them between $S$ servers. All clients will request to be serviced at the same time at the start of the day, and the load balancer must assign each client a server immediately at the start of the day.

Your boss tells you to keep costs down, that each server must service **less than** $\frac{C}{S}$ clients in total. Let $c_i$ be the number of clients that the $i^{th}$ server has to service. E.g. $c_1$ is the number of clients for the first server, $c_2$ is the number of clients for the second server. And so on. Since we have $S$ servers, we have quantities $c_1, c_2, \ldots, c_S$.

**Question:** Prove to yourself and your boss that this is impossible.








