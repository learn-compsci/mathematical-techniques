---
title: "Tutorial 1: Propositions, Predicates, First Order Logic, Proofs"
---
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.
* **Official due date for submission** : 11-Feb-2025, 6:30PM

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


1. Questions 1 through 3 are related to **propositional logic**. 
2. Questions 4 through 6 are related to **first order logic**. 
3. Questions 7 and 8 are related to **proofs**. 

After week 2's content, you should be able to attempt questions 1 through 6. Questions 2, and 4 are graded for participation.

After week 4's content, you should be able to attempt questions 7 and 8. Question 7 is graded for participation.

That said, **we encourage you to try all the questions**, this way when you come for tutorial we can best make use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

# Question 1:

>[!Purpose] 
> Practice translating English sentences into propositional formulae!

For each of the following, write a propositional formula that accurately represents the given English statement. Use the propositions $p$, $q$, $r$, $s$ and $t$ as needed, where they're defined as:

* $p$: "The program compiles."
* $q$: "The input is valid."
* $r$: "The output is correct."
* $s$: "The function is efficient."
* $t$: "The algorithm terminates."

0. "If the input is valid, then the output is correct"

1. "If the program compiles but the input is not valid, then the output is not correct."

2. "The function is efficient if and only if (both the algorithm terminates and the output is correct)." (Hint: "if and only if" means an implication in both directions. $p$ if and only if $q$ is the same as $(p \to q) \land (q \to p)$)

3. "((The program compiles and the input is valid) or the function is efficient), and the algorithm does not terminate."

4. "If the program compiles, then ((either the input is valid and the output is correct), or the algorithm does not terminate)."

5. "The function is efficient if and only if ((the program compiles and the input is valid), or (if the output is correct implies that the algorithm terminates))."

**Example:** The answer to point 0. is: "$q \to r$".

---

# Question 2: Negating Propositional Formulae \[Graded Participation]
To do this question, make sure you have read the section on [[Unit 1#Truth tables, logical equivalences|logical equivalences]]. In that section, we showed that $\neg (p \lor q)$ is logically equivalent to $\neg p \land \neg q$. In this tutorial question, we will look at now the negation connective works in the other cases.
### Part A: Equivalences
Draw two truth tables to verify that:

1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$.
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

**Key takeaway from this tutorial question and the notes:**
1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$
3. $\neg(\neg(p))$ is logically equivalent to $p$ (From the notes)
4. $\neg(p \lor q)$ is logically equivalent to $\neg p \land \neg q$ (From the notes)

**Sneak peek:** These negations are super useful because later on when we talk about considering proof by contradictions knowing how to negate statements comes in handy. (Relevant content in Week 4's chapter [[Unit 1#Proof Strategies|Unit 1: Proof Strategies]])

## Part B: Translating Human Language to Logic
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
> This question aims to help you make sense of implications. There's really *nothing* deep behind implications. It is just a logical connective that has a certain behaviour.
> 
> To this end, try to consider the following statement below and how we can write it as an implication statement.


Aiken promises Dueet that if Dueet watches anime with him, then Aiken will treat Dueet to a pizza dinner.

## Part A:
How would you write this sentence in propositional logic? Do this by trying to identify sentences that you should call $p$, and sentences you should call $q$, and so on. (You can look at how [[#Question 1|Question 1]] of this tutorial has identified their sentences.)

## Part B
Determine whether the promise has been broken in each of the following cases:
1. Dueet watches anime with Aiken, and Aiken treats Dueet to a pizza dinner.
2. Dueet watches anime with Aiken, but Aiken does not treat Dueet to a pizza dinner.
3. Dueet does not watch anime with Aiken, and Aiken treats Dueet to a pizza dinner.
4. Dueet does not watch anime with Aiken, and Aiken does not treat Dueet to a pizza dinner.


---

# Question 4: \[Graded Participation]

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
- $U=\{A, B, C, D, E, F, G, H, I\}$ be the set containing all the objects.

You are also given the following predicates, which you may use freely in your answers:
- $Above(x,y)$ is true when object $x$ is above object $y$ in the grid.
- $Blue(x)$ is true when object $x$ is blue.
- $Grey(x)$ is true when object $x$ is grey.
- $Orange(x)$ is true when the object $x$ is orange.
- $Circle(x)$ is true when the object $x$ is a circle
- $Square(x)$ is true when $x$ is a square object.
- $Triangle(x)$ is true when $x$ is a triangular object.

Determine whether the following statements are true or false for the below picture:
1. $\exists u \in U \ [Orange(u) \land Triangle(u)]$
2. $\forall u \in U \ [Circle(u)\rightarrow Blue(u)]$
3. $\forall s \in S, \exists t \in T \ [Above(t, s)]$
4. $\forall r \in R, \forall s \in S \ [Above(r, s)]$
5. $\exists u \in U, \forall r \in R \ [Above(u, r)]$
6. $\exists r \in R, \exists t \in T \ [Black(r) \lor \neg Grey(t)]$

Take note of which set each variable comes from. E.g. in the first statement, which set does variable $u$ come from? What possible values can it take?

![[tarskis-drawn.png|500]]


---

# Question 5: Negating FOL statements

>[!Purpose] 
> Play around with FOL statements! It's important to know how to manipulate them for writing proofs (later on).


Consider the following first order logic statements:

1. $\exists x \in D \ [P(x) \land Q(x)]$
2. $\forall x \in D \ [P(x)\lor Q(x)]$
3. $\forall x\in D,\exists y\in E \ [P(x,y)\land Q(y)]$
4. $\exists x \in D,\forall y \in E [P(x,y) \to Q(y)]$

Write the negation for each of the statements. You may refer to [[Unit 1#Negating Quantifiers]] on this.


---

# Question 6:

>[!Purpose] 
> In this next question, we will apply the understanding of first order logic to more commonly encountered sets and practice manipulating statements. It's a chance to get more familiar with and fluent in reading and manipulating set notation, as well as practicing some tools commonly used to aid in proofs.

## Useful notation for sets of numbers for easy reference:

|    Symbol    | Definition              | Explanation                                                                                                                         |
| :----------: | ----------------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| $\mathbb{N}$ | Set of natural numbers  | Set containing the numbers $0, 1, 2, 3, \ldots$                                                                                     |
| $\mathbb{Z}$ | Set of integers         | Set containing the numbers $\ldots, -3, -2, -1, 0, 1, 2, 3, \ldots$                                                                 |
| $\mathbb{Q}$ | Set of rational numbers | Set containing numbers that can be expressed as a fraction of 2 integers, eg: $0.33\bar3 = \dfrac{1}{3}$ and $-20 = \dfrac{40}{-2}$ |
## Part A: Negating statements

>[!Purpose] 
> Sometimes when attempting to prove a statement, as you will see in the [[Unit 1#Part 3 Proofs in First Order Logic|second half of Unit 1]], rather than attempting to prove/disprove something directly, it may be easier or more intuitive to disprove/prove its [[Unit 1#Negating Quantifiers|negation]]. For some of the questions, notice how it is sometimes easier to determine if the negation is true rather than the original statement.

For each of the following statements, write out the negation of the statement, and determine if the original statement is true or false.

1. $\forall x \in \mathbb{N}, \exists y \in \mathbb{Z} \ [x = y]$
2. $\forall p, q \in \mathbb{Q} \ [q = p]$
3. $\forall a, b, c \in \mathbb{Z} \ [a = b \lor a = c]$ 
4. $\forall x \in \mathbb{Z}, \exists y, z \in \mathbb{Q} \ [x = 3y \land x = 5z]$      
5. $\exists p, q \in \mathbb{Z}, \forall r \in \mathbb{Z} \ [p + q \neq r]$
6. $\forall a, b \in \mathbb{Z} \ [a^2 = b^2 \to a = b]$

## Part B: Contrapositive statements

>[!Purpose] 
>Similar to part a, when attempting to prove implication statements, instead of trying to prove/disprove an implication directly, we can consider the [[Unit 1#Contrapositivity|contrapositive]]. Again, in some cases, the contrapositive may be more intuitive or easier to digest than the original statement.

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
2. $\forall p \in \mathbb{Z} \ \big[p < 0 \to (p \leq 5 \lor p > 26)\big]$
3. $\forall x \in \mathbb{Z} \ \big(\forall y \in \mathbb{N} \ [x \neq y)] \to x \leq 5\big)$

---
# Question 7 \[Graded Participation]:
Prove the following statement:

> [!Theorem] 
> $\forall x \in \mathbb{Z} \ [\neg (even(x) \land odd(x))]$
> 
> Where we define the predicate $even(x)$ to be: $even(x) \equiv \exists k \in \mathbb{Z} \ [2k = x]$, 
>  and we define the predicate $odd(x)$ to be: $odd(x) \equiv \exists j \in \mathbb{Z} \ [2j + 1 = x]$

Notice this theorem is basically say no integer is both odd and even at the same time.

To get you started, we have filled in a few lines of the proof for you, you should try to make sure that the proof is complete:

**Partial solution:**
1. Let $x$ be arbitrarily chosen from $\mathbb{Z}$.
2. Assume for the sake of contradiction that $(even(x) \land odd(x))$
	1. (Your proof here...)
3.  Contradiction

The clickable hint box below gives a hint on how to approach this proof.

>[!Hint]-
> Based on our assumption for contradiction, can we somehow argue something like $\frac{1}{2} \in \mathbb{Z}$?
> 
> We can also create a line that says $\neg(\frac{1}{2} \in \mathbb{Z})$ due to Basic Algebra. After all, $\frac{1}{2}$ is not an integer.


# Question 8:
You are tasked with building a load balancer that services $C$ clients, and has to balance them between $S$ servers. All clients will request to be serviced at the same time at the start of the day, and the load balancer must assign each client a server immediately at the start of the day.

Your boss tells you to keep costs down, that each server must service **less than** $\frac{C}{S}$ clients in total. Let $c_i$ be the number of clients that the $i^{th}$ server has to service, e.g., $c_1$ is the number of clients for the first server, $c_2$ is the number of clients for the second server, and so on. Since we have $S$ servers, we have quantities $c_1, c_2, \ldots, c_S$.

**Question:** Prove to yourself and your boss that this is impossible.

**Note:** This question is a little more open-ended. For example, how do we even formally state "this is impossible" in math? We need to come up with a goal statement that we can try to prove in math. This is probably an interesting point worthy of discussion with your tutorial tutor. In particular, we are normally given these situations we need to deal with in real life. And someone who incorporates discrete math thinking into their toolbox as a technique needs to learn how to do a few things:

1. Translating their scenario into a mathematical statement that they can either prove, or disprove.
2. Proving, or disproving that statement.
3. Interpreting back their result.

So this question above comes with the question of what should we even write as a statement that we should try to prove or disprove?

The clickable hint box below gives a the formal statement we should try to prove. But I encourage you to think a little bit first about what you might write. Then, compare your attempt with what we have written in the hint box.

>[!Hint]-
> There are a few possible ways we can formalise this. Here is one:
> 
> **Formalism 1:**
> Assume $C \in \mathbb{N}, c_1 \in \mathbb{N}, c_2 \in \mathbb{N}, \ldots, c_S \in \mathbb{N}$ is such that $(C > 0) \land (\sum_{i = 1}^S c_{i} = C)$. Then, $$\exists i \in \mathbb{N} \ \bigg[(1 \leq i \land i \leq S \land c_i \geq \frac{C}{S}) \bigg]$$
> 
> Reading this back in English: Let $C$, $c_1, c_2, \ldots, c_S$ be natural numbers. Assume that $C$ is positive, and that the total clients served is exactly $C$. Then at least one of the servers serves at least $\frac{C}{S}$.

Here's another hint on how you might approach the overall proof idea.

>[!Hint]-
> Refer to the proof done in [[Unit 1#Example 1]] and see how you might adapt it to prove the above statement instead.
