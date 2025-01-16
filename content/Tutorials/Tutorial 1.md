---
title: "Tutorial 1: Propositions, Predicates, First Order Logic, Proofs"
hidden: "true"
---
# Overview
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular corresponds to [[Unit 1]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.


1. Questions 1 through 3 are related to **propositional logic**. 
2. Questions 4 through 5 are related to **first order logic**. 
3. Questions 6 and 7 are related to **proofs**. 

After week 2's content, you should be able to attempt questions 1 through 5. 
After week 4's content, you should be able to attempt questions 6 and 7.


## Question 2: DeMorgan's Laws
### Part a: Equivalence
Draw two truth tables to verify that:

1. $\neg (p \lor q)$ is logically equivalent to $\neg p \land \neg q$.
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

These two equivalences (known as **De Morgan's Laws**) are among some of the most useful in discrete mathematics. 

|   $p$   |   $q$   | $p \lor q$ | $\neg p$ | $\neg q$ | $\neg (p \lor q)$ | $\neg p \land \neg q$ |
| :-----: | :-----: | :--------: | :------: | :------: | :---------------: | :-------------------: |
| $true$  | $true$  |            |          |          |                   |                       |
| $true$  | $false$ |            |          |          |                   |                       |
| $false$ | $true$  |            |          |          |                   |                       |
| $false$ | $false$ |            |          |          |                   |                       |

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