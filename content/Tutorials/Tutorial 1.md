---
title: "Tutorial 1: Propositions, Predicates, First-Order Logic"
---
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.
* **Official due date for submission**: 27th Jan 2026, 11:59 PM **or** during tutorial itself.

# Collaboration Policy: 
* You may discuss high-level ideas with your classmates or friends. You should list your collaborators if you do so. 
* **Do not share your solutions**.
* ChatGPT (and other LLMs) are **not allowed**. 
* Your submission **must be of your own write-up**.

# Late Policy:
* < 1 week after submission deadline: 50% penalty
* < 2 weeks after submission deadline: 75% penalty
* No submissions after 2 weeks.

# Overview

This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 1]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.

1. Questions 1 through 2 are related to **propositional logic**. 
2. Questions 3 through 5 are related to **first-order logic**. 

After Week 1's content, you should be able to attempt questions 1 through 3. After Week 2's content, you should be able to attempt questions 4 through 6.

**Questions 2, 4** are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1:

>[!Purpose] 
> Practice translating English sentences into propositional formulae!

For each of the following, write a propositional formula that accurately represents the given English statement. Use the variables $p$, $q$, $r$, $s$ and $t$ as needed, where they're defined as:
* $p \equiv$ "The program compiles"
* $q \equiv$ "The input is valid"
* $r \equiv$ "The output is correct"
* $s \equiv$ "The function is efficient"
* $t \equiv$ "The algorithm terminates"

0. "If the input is valid, then the output is correct."

1. "If the program compiles and the input is not valid, then the output is not correct."

2. "\[(The program compiles and the input is valid) or the function is efficient], and the algorithm does not terminate."

3. "If the program compiles, then either (the input is valid and the output is correct), or the algorithm does not terminate."

**Example:** The answer to point 0. is: "$q \to r$".

---
# Question 2 \[Graded Participation]: Negating Propositional Formulae

To do this question, make sure you have read the section on [[Unit 1#Truth tables, logical equivalences|logical equivalences]]. In that section, we showed that $\neg (p \lor q)$ is logically equivalent to $\neg p \land \neg q$. In this tutorial question, we will look at now the negation connective works in the other cases.

### Part A: Equivalences

Draw two truth tables to verify that:

1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$.

|   $p$   |   $q$   | $p \to q$ | $\neg(p \to q)$ | $\neg q$ | $p \land \neg q$ |
| :-----: | :-----: | :-------: | :-------------: | :------: | :--------------: |
| $true$  | $true$  |           |                 |          |                  |
| $true$  | $false$ |           |                 |          |                  |
| $false$ | $true$  |           |                 |          |                  |
| $false$ | $false$ |           |                 |          |                  |

2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

|   $p$   |   $q$   | $p \land q$ | $\neg p$ | $\neg q$ | $\neg (p \land q)$ | $\neg p \lor \neg q$ |
| :-----: | :-----: | :---------: | :------: | :------: | :----------------: | :------------------: |
| $true$  | $true$  |             |          |          |                    |                      |
| $true$  | $false$ |             |          |          |                    |                      |
| $false$ | $true$  |             |          |          |                    |                      |
| $false$ | $false$ |             |          |          |                    |                      |

**Key takeaways from this tutorial question and the notes:**
1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$
3. $\neg(\neg p)$ is logically equivalent to $p$ (From the notes)
4. $\neg(p \lor q)$ is logically equivalent to $\neg p \land \neg q$ (From the notes)

**Sneak peek:** Equivalences 2 and 4 are collectively known as [De Morgan's Laws](https://en.wikipedia.org/wiki/De_Morgan%27s_laws#Boolean_algebra). These negations are super useful because later on when we talk about proofs by contradiction, knowing how to negate complex statements comes in handy. (Relevant content in Week 4's section on [[Unit 1#Proof Strategies|proof strategies]].)

## Part B: Translating human language to propositional logic

To see how these equivalences may be used, let $p$ be the statement "It is raining" and let $q$ be the statement "It is cold". Match each of the following statements with its logically equivalent; you might rewrite each statement using $p$ and $q$ to assist you.

1. It is not the case that it is raining or cold.
2. It is not raining or it is not cold.
3. It is not raining and it is not cold. 
4. It is not the case that it is both raining and cold.

Answer template: <br>
*Statement ___ is logically equivalent to statement ___ .*
*Statement ___ is logically equivalent to statement ___ .*

---
# Question 3 \[Graded Participation]: Tarski's World 

>[!Purpose] 
> In this tutorial question, we will try to reinforce the concept of reading the notation for first-order logic. This comes in a few parts: we will try to get you used to basic set notation, the quantifiers, as well as the predicates.

Recall we mentioned in the section on [[Unit 1#Quantifiers|quantifiers]] that the basic format for quantified statement looks something like this:

![[basic-quantifier.png|450]]


And furthermore as an example, a set can be specified like this: $Humans = \{John, Sam\}$. Here, $Humans$ is the set, and we are saying that that set **contains two elements**, namely: $John$ and $Sam$.

> "What if I want to make a set with the name $S$ that contains elements $1, 5, 20, 560, 1000$?" 

Good question! Then you could just write $S = \{1, 5, 20, 560, 1000\}$. So $S$ is a set that contains elements $1, 5, 20, 560, 1000$.

With that in mind, we have made some sets here for you, we also have listed some predicates. We will specify their behaviours for you.

Let:
- $C=\{C_1,C_2,C_3\}$ be the set of circles,
- $S=\{S_1,S_2,S_3,S_4\}$ be the set of squares,
- $D=\{D_1,D_2,D_3\}$ be the set of diamonds, and
- $U=\{C_1, C_2, C_3, S_1, S_2, S_3, S_4, D_1, D_2, D_3\}$ be the set containing all the objects.

You are also given the following predicates, which you may use freely in your answers:
- $Above(x,y)$ is true when object $x$ is in anywhere in a row that is **strictly** above object $y$. For example, we consider $Above(D_1, D_2) \equiv true$ and $Above(S_1, D_2) \equiv false$. (Does not have to be the same column.)
- $Blue(x)$ is true when object $x$ is blue.
- $Grey(x)$ is true when object $x$ is grey.
- $Orange(x)$ is true when the object $x$ is orange.
- $Circle(x)$ is true when the object $x$ is a circle.
- $Square(x)$ is true when $x$ is a square.
- $Diamond(x)$ is true when $x$ is a diamond.

Determine whether the following statements are true or false for the below picture:
1. $\exists u \in U \ \big[Orange(u) \land Diamond(u) \big]$
2. $\forall u \in U \ \big[Circle(u)\rightarrow Blue(u) \big]$
3. $\forall s \in S, \exists d \in D \ \big[Above(d, s) \big]$
4. $\forall c \in C, \forall s \in S \ \big[Above(c, s) \big]$
5. $\exists u \in U, \forall c \in C \ \big[Above(u, c) \big]$
6. $\exists c \in C, \exists d \in D \ \big[Grey(c) \lor \neg Orange(d) \big]$

Take note of which set each variable comes from, e.g., in the first statement, which set does variable $u$ come from? What possible values can it take?
![[tarski.png]]

---
# Question 4: Negating FOL Statements

>[!Purpose] 
> Play around with FOL statements! It's important to know how to manipulate them for writing proofs (later on).

Consider the following first-order logic statements:
1. $\forall x \in D, \exists y \in E \ \big[P(x,y) \land Q(y) \big]$
2. $\exists x \in D, \forall y \in E \ \big[P(x,y) \to Q(y) \big]$

Write the negation of each of the statements. You may refer to the section on [[Unit 1#Negating Quantifiers|negating quantifiers]] for this.

---
# Question 5:

>[!Purpose] 
> In this next question, we will apply the understanding of first-order logic to more commonly encountered sets and practice manipulating statements. It's a chance to get more familiar with and fluent in reading and manipulating set notation, as well as practicing some tools commonly used to aid in proofs.

## Useful notation for sets of numbers for easy reference:

|    Symbol    | Definition              | Explanation                                                                                                                             |
| :----------: | ----------------------- | --------------------------------------------------------------------------------------------------------------------------------------- |
| $\mathbb{N}$ | Set of natural numbers  | Set containing the numbers $0, 1, 2, 3, \ldots$                                                                                         |
| $\mathbb{Z}$ | Set of integers         | Set containing the numbers $\ldots, -3, -2, -1, 0, 1, 2, 3, \ldots$                                                                     |
| $\mathbb{Q}$ | Set of rational numbers | Set containing numbers that can be expressed as a fraction of two integers, e.g., $0.33\bar3 = \dfrac{1}{3}$ and $-20 = \dfrac{40}{-2}$ |
## Part A: Negating statements

>[!Purpose] 
> Sometimes when attempting to prove a statement, as you will see in the [[Unit 1#Part 3 Proofs in First Order Logic|second half of Unit 1]], rather than attempting to prove/disprove something directly, it may be easier or more intuitive to disprove/prove its [[Unit 1#Negating Quantifiers|negation]]. For some of the questions, notice how it is sometimes easier to determine if the negation is true rather than the original statement.

For each of the following statements, write out the negation of the statement, and determine if the original statement is true or false.

1. $\forall x \in \mathbb{N}, \exists y \in \mathbb{Z} \ [x = y]$
2. $\forall p, q \in \mathbb{Q} \ [q = p]$
3. $\forall x \in \mathbb{Z}, \exists y, z \in \mathbb{Q} \ [x = 3y \land x = 5z]$     
4. $\forall a, b \in \mathbb{Z} \ [a^2 = b^2 \to a = b]$

## Part B: Contrapositive statements

>[!Purpose] 
>Similar to Part A, when attempting to prove implication statements, instead of trying to prove/disprove an implication directly, we can consider the [[Unit 1#Contrapositivity|contrapositive]]. Again, in some cases, the contrapositive may be more intuitive or easier to digest than the original statement.

For each of the following implication statements:
1. Write its contrapositive.
2. Determine if the statement is true or false.

As an example, when given a statement like:

$$
\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \ \big[(a > b) \to (a > b - 234)\big]
$$

Then the contrapositive is:
$$
\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \ \big[\neg (a > b -234) \to \neg(a > b)\big]
$$
Basically, take the inner implication statement, and re-write it in its contrapositive form.

Statements:
1. $\forall a \in \mathbb{Z}, b \in \mathbb{Z} \ [a^2 \neq b^2 \to a \neq b]$
2. $\forall x \in \mathbb{Z} \ \big[\big(\forall y \in \mathbb{N} \ [x \neq y]\big) \to x \leq 5 \big]$
