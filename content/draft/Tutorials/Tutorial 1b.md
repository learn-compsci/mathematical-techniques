---
title: "Tutorial 1: Propositions, Predicates, First-Order Logic, Proofs"
---
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.
* **Official due date for submission**: 10 Feb 2026, 11:59 PM **or** during tutorial itself.

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
2. Questions 4 through 6 are related to **first-order logic**. 
3. Questions 7 and 8 are related to **proofs**. 

After Week 2's content, you should be able to attempt questions 1 through 3. After Week 3's content, you should be able to attempt questions 4 through 6. After Week 4's content, you should be able to attempt questions 7 and 8.

**Questions 2, 4 and 7** are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1:

For the following proofs, fill in the blanks with the corresponding [[Unit 1#Allowable Rules of Deductions/Inferences|rule of deduction]] used, quoting the appropriate line numbers where necessary.

#### Sub-part 1

>[!note] Proof: $\forall x, y \in \mathbb{N} \ \big[(x = 0) \lor (y = 0) \to (xy = 0) \big]$
>1. Let $x, y \in \mathbb{N}$ be arbitrarily chosen.
>2. Suppose $(x = 0) \lor (y = 0)$.
>3. Case 1: Assume $x = 0$.
>		1. $xy = 0 \cdot y = 0$. **\[ (a) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**
>4. Case 2: Assume $y = 0$.
>		1. $xy = x \cdot 0 = 0$. **\[ (b) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**
>5. In all cases, we have $xy = 0$.  **\[ (c) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**
>6. $(x = 0) \lor (y = 0) \to (xy = 0)$. **\[ (d) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**
>7. $\forall x, y \in \mathbb{N} \ \big[(x = 0) \lor (y = 0) \to (xy = 0) \big]$. **\[ (e) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**

#### Sub-part 2

>[!note] Proof: $\forall n \in \mathbb{N} \ [n + 1 \neq 0]$
>1. Let $n \in \mathbb{N}$ be arbitrarily chosen.
>2. Suppose, for the sake of contradiction, that $\neg (n + 1 \neq 0)$.
>		1. $n + 1 = 0$. **\[ (f) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**
>		2. $n = -1$. \[Basic algebra]
>		3. $\neg (n \in \mathbb{N}).$ \[Basic algebra]
>		4. $(n \in \mathbb{N}) \land \neg (n \in \mathbb{N})$. **\[ (g) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**
>		5. $\bot$. **\[ (h) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**
>3. $n + 1 \neq 0$. **\[ (i) Rule of deduction: _ _ _ _ _ _ _ _ _ _ ]**
>4. $\forall n \in \mathbb{N} \ [n + 1 \neq 0]$. \[Universal generalisation on lines 1 and 3]

---
# Question 2 \[Graded Participation]:

For each of the following proofs, identify where there were incorrect/missing steps of justification, and discuss potential corrections to them.

#### Sub-part 1

>[!note] Proof: $\forall x \in \mathbb{Z}, \exists y \in \mathbb{Z} \ [y > x]$
>1. Let $y = x + 1$.
>2. Since $x + 1 > x$, $y > x$. \[Basic algebra]
>3. $\forall x \in \mathbb{Z}, \exists y \in \mathbb{Z} \ [y > x]$. \[Existential generalisation on line 2]

#### Sub-part 2

For any integer $x$, we define the predicate $even(x)$ to be the following:

$$
even(x) \equiv \exists k \in \mathbb{Z} \ [x = 2k]
$$

>[!note] Proof: $\forall x \in \mathbb{Z} \ [even(x) \to even(x^2)]$
>1. Let $x$ be arbitrarily chosen.
>2. Suppose $even(x)$.
>3. Let $x = 2k$. \[Instantiation on line 2]
>4. Then $x^2 = 2m$, where $m = k^2$. \[Basic algebra]
>5. Therefore $even(x^2)$. \[Definition of $even$]

#### Sub-part 3

For any integer $x$, we define the predicate $odd(x)$ to be the following:

$$
odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2k + 1]
$$

>[!note] Proof: $\neg \big(\exists x \in \mathbb{Z} \ [even(x) \land odd(x)] \big)$
>1. Suppose, for the sake of contradiction, that $\exists x \in \mathbb{Z} \ [even(x) \land odd(x)]$.
>2. Let $x \in \mathbb{Z}$ be such that $even(x) \land odd(x)$. \[Universal instantiation on line 1]
>3. But $even(x) \to \neg (odd(x))$ and $odd(x) \to \neg (even(x))$, so this is impossible. \[Contradiction]
>4. $\neg \big(\exists x \in \mathbb{Z} \ [even(x) \land odd(x)] \big)$. \[Proof by contradiction on line 3]

---
# Question 3:

For this question, we refer to the following definition of **rational numbers**:

$$
x \in \mathbb{Q} \equiv \exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ \bigg[q \neq 0 \land x = \frac{p}{q}\bigg]
$$

Prove the following statement:

$$
\forall n \in \mathbb{Z} \ [n \in \mathbb{Q}]
$$

---
# Question 6 \[Graded Participation]:

Prove the following statement:

> [!Theorem] 
> $\forall x \in \mathbb{Z} \ \big[\neg \big(even(x) \land odd(x) \big) \big]$
> 
> We define the predicate $even(x)$ to be: $even(x) \equiv \exists k \in \mathbb{Z} \ [2k = x]$, 
>  and we define the predicate $odd(x)$ to be: $odd(x) \equiv \exists j \in \mathbb{Z} \ [2j + 1 = x]$.

Notice this theorem is basically saying that no integer is both odd and even at the same time.

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
> We can also create a line that says $\neg(\frac{1}{2} \in \mathbb{Z})$ by basic algebra. After all, $\frac{1}{2}$ is not an integer.

---
# Question 7:

You are tasked with building a load balancer that services $C$ clients, and has to balance them between $S$ servers. All clients will request to be serviced at the same time at the start of the day, and the load balancer must assign each client a server immediately at the start of the day.

Your boss tells you to keep costs down, that each server must service **fewer than** $\frac{C}{S}$ clients in total. Let $c_i$ be the number of clients that the $i^{th}$ server has to service, i.e., $c_1$ is the number of clients for the first server, $c_2$ is the number of clients for the second server, and so on. Since we have $S$ servers, we have quantities $c_1, c_2, \ldots, c_S$.

**Question:** Prove to yourself and your boss that this is impossible.

**Note:** This question is a little more open-ended. For example, how do we even formally state "this is impossible" in math? We need to come up with a goal statement that we can try to prove in math. This is probably an interesting point worthy of discussion with your tutorial tutor. In particular, we are normally given these situations we need to deal with in real life, and someone who incorporates discrete math thinking into their toolbox as a technique needs to learn how to do a few things:
1. Translating their scenario into a mathematical statement that they can either prove, or disprove.
2. Proving, or disproving that statement.
3. Interpreting back their result.

So this question above comes with the question of what should we even write as a statement that we should try to prove or disprove?

The clickable hint box below gives a the formal statement we should try to prove, but I would encourage you to think a little bit first about what you might write. Then, compare your attempt with what we have written in the hint box.

>[!Hint]-
> There are a few possible ways we can formalise this. Here is one:
> 
> **Formalism 1:**
> Assume $C \in \mathbb{N}, c_1 \in \mathbb{N}, c_2 \in \mathbb{N}, \ldots, c_S \in \mathbb{N}$ is such that $(C > 0) \land (\sum_{i = 1}^S c_{i} = C)$. Then, $$\exists i \in \mathbb{N} \ \bigg[ \bigg(1 \leq i \land i \leq S \land c_i \geq \frac{C}{S} \bigg) \bigg]$$
> 
> Reading this back in English: Let $C$, $c_1, c_2, \ldots, c_S$ be natural numbers. Assume that $C$ is positive, and that the total clients served is exactly $C$. Then at least one of the servers serves at least $\frac{C}{S}$.

Here's another hint on how you might approach the overall proof idea.

>[!Hint]-
> Refer to the proof done in [[Unit 1#Example 1]] and see how you might adapt it to prove the above statement instead.
