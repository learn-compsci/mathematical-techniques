---
title: "Tutorial 1: Propositions, Predicates, First Order Logic, Proofs"
hidden: "true"
---
# How to submit:
- Submit before actual tutorial time for it to be graded.

# Overview
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 1]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.


1. Questions 1 through 3 are related to **propositional logic**. 
2. Questions 4 through 5 are related to **first order logic**. 
3. Questions 6 and 7 are related to **proofs**. 

After week 2's content, you should be able to attempt questions 1 through 5. 
After week 4's content, you should be able to attempt questions 6 and 7.


# Question 1

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

# Question 2
To do this question, make sure you have read the section on [[Unit 1#Truth tables, logical equivalences|logical equivalences]].
### Part a: Equivalence
Draw two truth tables to verify that:

1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$
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


---

# Question 3

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

Write its contrapositive, and prove that they are logically equivalent. 


### Part b: Negating FOL statements

Consider the following first order logic statements:
	1. $∃x∈D, P(x)∧Q(x)$
	2. $∀x∈D, P(x)∨Q(x)$
	3. $∀x∈D,∃y∈E, P(x,y)∧Q(y)$
	4. $∃x∈D,∀y∈E, P(x,y)⟹Q(y)$

Write the negation for each of the statements.


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