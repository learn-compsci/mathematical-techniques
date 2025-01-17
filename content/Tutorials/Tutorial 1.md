---
title: "Tutorial 1: Propositions, Predicates, First Order Logic, Proofs"
hidden: "true"
---
# How to submit:
- Submit before actual tutorial time for it to be graded.

# Overview
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 1]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.


1. Questions 1 through 3 are related to **propositional logic**. 
2. Questions 4 through 6 are related to **first order logic**. 
3. Questions 7 and 8 are related to **proofs**. 

After week 2's content, you should be able to attempt questions 1 through 5. 
After week 4's content, you should be able to attempt questions 6 and 7.


# Question 1:

>[!Purpose] 
> Practice translating English sentences into propositional formulae!

For each of the following, write a propositional formula that accurately represents the given English statement. Use the propositions ***p***, ***q***, ***r***, ***s*** and ***t*** as needed, where:
	***p*** : "The program compiles."
	***q*** : "The input is valid."
	***r*** : "The output is correct."
	***s*** : "The function is efficient."
	***t*** : "The algorithm terminates."

1. "If the program compiles but the input is not valid, then the output is not correct."

2. "The function is efficient if and only if both the algorithm terminates and the output is correct." (Hint: "if and only if" means an implication in both directions)

3. "The program compiles and the input is valid, or the function is efficient, but the algorithm does not terminate."

4. "If the program compiles, then either the input is valid and the output is correct, or the algorithm does not terminate."

5. "The function is efficient if and only if the program compiles and the input is valid, or if the output is correct implies that the algorithm terminates."


---

## Question 2: Negating Propositional Formulae
To do this question, make sure you have read the section on [[Unit 1#Truth tables, logical equivalences|logical equivalences]]. In that section, we showed that $\neg (p \lor q)$ is logically equivalent to $\neg p \land \neg q$. In this tutorial question, we will look at now the negation connective works in the other cases.
### Part a: Equivalences
Draw two truth tables to verify that:

1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

|   $p$   |   $q$   | $p \to q$ | $\neg(p \to q)$ | $\neg q$ | $p \land \neg q$ |
| :-----: | :-----: | :-------: | :-------------: | :------: | :--------------: |
| $true$  | $true$  |           |                 |          |                  |
| $true$  | $false$ |           |                 |          |                  |
| $false$ | $true$  |           |                 |          |                  |
| $false$ | $false$ |           |                 |          |                  |

|   $p$   |   $q$   | $p \land q$ | $\neg p$ | $\neg q$ | $\neg (p \land q)$ | $\neg p \lor \neg q$ |
| :-----: | :-----: | :---------: | :------: | :------: | :----------------: | :------------------: |
| $true$  | $true$  |             |          |          |                    |                      |
| $true$  | $false$ |             |          |          |                    |                      |
| $false$ | $true$  |             |          |          |                    |                      |
| $false$ | $false$ |             |          |          |                    |                      |

### Part b: Translating Human Language to Logic
To see how these equivalences may be used, let $p$ be the statement "It is raining" and let $q$ be the statement "It is cold". Match each of the following statements with its logically equivalent; you might rewrite each statement using $p$ and $q$ to assist you.

1. It is not the case that it is raining or cold.
2. It is not raining or it is not cold.
3. It is not raining and it is not cold. 
4. It is not the case that it is both raining and cold.

Answer template: <br>
*Statement ___ is logically equivalent to statement ___ .*
*Statement ___ is logically equivalent to statement ___ .*


---

# Question 3:

>[!Purpose] 
> This question aims to help you make sense of implications. There's really *nothing* deep behind implications.

Aiken promises Dueet that if Dueet watches anime with him, then Aiken will treat Dueet to a pizza dinner.

a. How would you write this sentence in propositional logic?

b. Determine whether the promise has been broken in each of the following cases:
1. Dueet watches anime with Aiken, and Aiken treats Dueet to a pizza dinner.
2. Dueet watches anime with Aiken, but Aiken does not treat Dueet to a pizza dinner.
3. Dueet does not watch anime with Aiken, and Aiken treats Dueet to a pizza dinner.
4. Dueet does not watch anime with Aiken, and Aiken does not treat Dueet to a pizza dinner.


---

# Question 4:

>[!Purpose] 
> In this tutorial question, we will try to reinforce the concept of reading the notation for first order logic. This comes in a few parts: We will try to get you used to basic set notation, the quantifiers, as well as the predicates.

Recall we mentioned in the chapter [[Unit 1#Quantifiers|Unit 1: Quantifiers]] that the basic format for quantified statement looks something like this:

![[basic-quantifier.png|450]]


And furthermore as an example, a set can be specified like this: $Human = \{John, Sam\}$. Here, $Human$ is the set, and we are saying that that set **contains two elements**, namely: $John$ and $Sam$.

> "What if I want to make a set with the name $S$ that contains elements $1, 5, 20, 560, 1000$?" 

Good question! Then you could just write $S = \{1, 5, 20, 560, 1000\}$. So $S$ is a set that contains elements $1, 5, 20, 560, 1000$.

With that in mind, we have made some sets here for you, we also have listed some predicates. We will specify their behaviours for you.

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

Determine whether the following statements are true or false for the below picture:
1. $\exists u \in U \: (Orange(u) \land Triangle(u))$
2. $\forall u \in U \: (Circle(u)\rightarrow Blue(u))$
3. $\forall s \in S, \exists t \in T \: (Above(t, s))$
4. $\forall r \in R, \forall s \in S \: (Above(r, s))$
5. $\exists u \in U, \forall r \in R \: (Above(u, r))$
6. $\exists r \in R, \exists t \in T \: (Black(r) \lor \neg Grey(t))$

Take note of which set each variable comes from. E.g. in the first statement, which set does variable $u$ come from? What possible values can it take?

![[tarskis-drawn.png|500]]


---

# Question 5

>[!Purpose] 
> Play around with FOL statements! It's important to know how to manipulate them for writing proofs.

### Part a: Contrapositive

Consider the following first order logic statement:

	$∀x∈D,∃y∈E,(P(x,y)  ⟹  Q(y))$

Write its contrapositive. 

### Part b: Negating FOL statements

Consider the following first order logic statements:
	1. $∃x∈D, P(x)∧Q(x)$
	2. $∀x∈D, P(x)∨Q(x)$
	3. $∀x∈D,∃y∈E, P(x,y)∧Q(y)$
	4. $∃x∈D,∀y∈E, P(x,y)⟹Q(y)$

Write the negation for each of the statements.


---

# Question 6:

>[!Purpose] 
> In this next question, we will apply the understanding of first order logic to more commonly encountered sets and practice manipulating statements. It's a chance to get more familiar with and fluent in reading and manipulating set notation, as well as practicing some tools commonly used to aid in proofs.

## Useful notation for sets of numbers for easy reference:

|    Symbol    | Definition              | Explanation                                                                                                                         |
| :----------: | ----------------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| $\mathbb{N}$ | Set of natural numbers  | Set containing the numbers 0, 1, 2, 3...                                                                                            |
| $\mathbb{Z}$ | Set of integers         | Set containing the numbers ... , -3, -2, -1, 0, 1, 2, 3, ...                                                                        |
| $\mathbb{Q}$ | Set of rational numbers | Set containing numbers that can be expressed as a fraction of 2 integers, eg: $0.33\bar3 = \dfrac{1}{3}$ and $-20 = \dfrac{40}{-2}$ |
## Part A: Negating statements

>[!Why?] 
> Sometimes when attempting to prove a statement, as you will see in the [[Unit 1#Part 3 Proofs in First Order Logic|second half of Unit 1]], rather than attempting to prove/disprove something directly, it may be easier or more intuitive to disprove/prove its [[Unit 1#Negating Quantifiers|negation]]. For some of the questions, notice how it is sometimes easier to determine if the negation is true rather than the original statement.

For each of the following statements, write out the negation of the statement, and determine if the original statement is true or false.

1. $\forall x \in \mathbb{N}, \exists y \in \mathbb{Z}, (x = y)$
2. $\forall p, q \in \mathbb{Q}, (q = p)$
3. $\forall a, b, c \in \mathbb{Z}, (a = b \lor a = c)$ 
4. $\forall x \in \mathbb{Z}, \exists y, z \in \mathbb{Q}, (x = 3y \land x = 5z)$      
5. $\exists p, q \in \mathbb{Z}, \forall r \in \mathbb{Z},(p + q \neq r)$
6. $\forall a, b \in \mathbb{Z}, (a^2 = b^2 \implies a = b)$

## Part B: Contrapositive statements

>[!Why?] 
>Similar to part a, when attempting to prove implication statements, instead of trying to prove/disprove an implication directly, we can consider the [[Unit 1#Contrapositivity|contrapositive]]. Again, in some cases, the contrapositive may be more intuitive or easier to digest than the original statement.

For each of the following implication statements, write its contrapositive, and determine if the statement is true or false.

1. $\forall a, b \in \mathbb{Z}, (a^2 \neq b^2 \implies a \neq b)$
2. $\forall p \in \mathbb{Z},  (p < 0 \implies p \leq 5 \lor p > 26)$
3. $\forall x \in \mathbb{Z}, (\forall y \in \mathbb{N}, (x \neq y) \implies x \leq 5)$

---
# Question 8:
Prove the following statement:

> [!Theorem] 
> $\forall x \in \mathbb{Z}[\neg (even(x) \land odd(x))]$
> 
> Where we define the predicate even to be: $even(x) \equiv \exists k \in \mathbb{Z}[2k = x]$, 
>  and we define the predicate odd to be: $odd(x) \equiv \exists j \in \mathbb{Z}[2j + 1 = x]$

Notice this theorem is basically say no integer is both odd and even at the same time.

To get you started, we have filled in a few lines of the proof for you, you should try to make sure that the proof is complete:

**Partial solution:**
1. Let $x$ be arbitrarily chosen from $\mathbb{Z}$.
2. Assume for the sake of contradiction that $(even(x) \land odd(x))$
	2.1 (Your proof here...)
3.  Contradiction

# Question 7:
You are tasked with building a load balancer that services $C$ clients, and has to balance them between $S$ servers. All clients will request to be serviced at the same time at the start of the day, and the load balancer must assign each client a server immediately at the start of the day.

Your boss tells you to keep costs down, that each server must service **less than** $\frac{C}{S}$ clients in total.

Prove to yourself and your boss that this is impossible.

**Note:** This question is a little more open-ended. For example, how do we even formally state "this is impossible" in math? We need to come up with a goal statement that we can try to prove in math.