
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

This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 1|Unit 1 Part 3]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.

All the questions here are related to proofs.

**Questions 1 and 5** are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1 \[Graded for Participation]:

For the following proofs, fill in the blanks with the corresponding [[Unit 1#Allowable Rules of Deductions/Inferences|rule of deduction]] used, quoting the appropriate line numbers where necessary.

#### Sub-part 1

>[!note] Proof: $\forall x, y \in \mathbb{N} \ \big[(x = 0) \lor (y = 0) \to (xy = 0) \big]$
>1. Let $x, y \in \mathbb{N}$ be arbitrarily chosen.
>2. Suppose $(x = 0) \lor (y = 0)$.
>3. Case 1: Assume $x = 0$.
>		1. $xy = 0 \cdot y = 0$. ==**\[ (a) Rule of deduction: Basic algebra ]**==
>4. Case 2: Assume $y = 0$.
>		1. $xy = x \cdot 0 = 0$. ==**\[ (b) Rule of deduction: Basic algebra ]**==
>5. In all cases, we have $xy = 0$.  ==**\[ (c) Rule of deduction: Proof by cases on lines 2, 3.1, 4.1 ]**==
>6. $(x = 0) \lor (y = 0) \to (xy = 0)$. ==**\[ (d) Rule of deduction: Implication introduction on lines 2 and 5 ]**==
>7. $\forall x, y \in \mathbb{N} \ \big[(x = 0) \lor (y = 0) \to (xy = 0) \big]$. ==**\[ (e) Rule of deduction: Universal generalisation on lines 1 and 6 ]**==

#### Sub-part 2

>[!note] Proof: $\forall n \in \mathbb{N} \ [n + 1 \neq 0]$
>1. Let $n \in \mathbb{N}$ be arbitrarily chosen.
>2. Suppose, for the sake of contradiction, that $\neg (n + 1 \neq 0)$.
>		1. $n + 1 = 0$. \[Logically equivalent to line 2]
>		2. $n = -1$. \[Basic algebra]
>		3. $\neg (n \in \mathbb{N}).$ \[Basic algebra]
>		4. $(n \in \mathbb{N}) \land \neg (n \in \mathbb{N})$. ==**\[ (f) Rule of deduction: Conjunction on lines 1 and 2.3 ]**==
>		5. $\bot$. ==**\[ (g) Rule of deduction: Contradiction rule on line 2.4 ]**==
>3. $n + 1 \neq 0$. ==**\[ (h) Rule of deduction: Proof by contradiction on line 2.5 ]**==
>4. $\forall n \in \mathbb{N} \ [n + 1 \neq 0]$. \[Universal generalisation on lines 1 and 3]

---
# Question 2:

For each of the following proofs, identify where there were incorrect/missing steps of justification, and discuss potential corrections to them.

#### Sub-part 1

>[!note] Proof: $\forall x \in \mathbb{Z}, \exists y \in \mathbb{Z} \ [y > x]$
>1. Let $y = x + 1$.
>2. Since $x + 1 > x$, $y > x$. \[Basic algebra]
>3. $\forall x \in \mathbb{Z}, \exists y \in \mathbb{Z} \ [y > x]$. \[Existential generalisation on line 2]

Missing a line introducing $x$ as a variable and not explaining which domain it draws from. Missing a universal instantiation rule. In general, the last line itself is actually packing multiple things into a single line. But it's not following what the existential generalisation rule is doing.

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

On line 1, we didn't specify which domain $x$ is drawn from. We're skipping the step of first unpacking the definition. Line 4 has done the algebra wrong, $m$ should be $2k^2$. At the end of the proof, we need to finish the proof with 2 more lines by re-introducing the implication, and then applying universal generalisation.

#### Sub-part 3

>[!note] Proof: $\forall n \in \mathbb{Z} \ [2n \neq 1]$
>1. Suppose, for the sake of contradiction, that $\exists n \in \mathbb{Z} \ [2n = 1]$.
>2. Let $n \in \mathbb{Z}$ be such that $2n = 1$. \[Universal instantiation on line 1]
>3. But multiplying any number by $2$ gives an even number and $1$ is not even, so this is impossible. \[Contradiction]
>4. $\forall n \in \mathbb{Z} \ [2n \neq 1]$. \[Proof by contradiction on line 3]

The biggest issue to focus on here is that line 3 is in English and we're not really applying the contradiction rule to obtain a contradiction here. It's not really following the proof system on how to actually obtain a contradiction. 

---
# Question 3:

Fill in the missing steps in the following proof, given the rules of deduction.

You may use the following lemma in your proof:

>[!note] Lemma
>$\forall x \in \mathbb{Z} \ \big[even(x) \lor odd(x)\big]$.

We also define the following predicate:

$$
odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2k + 1]
$$

>[!note] Proof: $\forall n \in \mathbb{Z} \ \big[even(n^2 + 3n) \big]$
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. ==$even(n) \lor odd(n)$.== \[Universal instantiation of given lemma]
>3. Case 1: $even(n)$.
>		1. ==$\exists k \in \mathbb{Z} \ [n = 2k]$.== \[Definition of $even$]
>		2. ==Let $p \in \mathbb{Z}$ be such that $n = 2p$.== \[Existential instantiation on line 3.1]
>		3. ==$n^2 + 3n = (2p)^2 + 3(2p) = 4p^2 + 6p = 2(2p^2 + 3p)$.== \[Basic algebra]
>		4. Since ==$p \in \mathbb{Z}$==, we know that ==$2p^2 + 3p \in \mathbb{Z}$==. \[Basic algebra]
>		5. ==$\exists k \in \mathbb{Z} \ [n^2 + 3n = 2k]$.== \[Existential generalisation on line 3.4]
>		6. ==$even(n^2 + 3n)$.== \[Definition of $even$]
>4. Case 2: $odd(n)$.
>		1. ==$\exists k \in \mathbb{Z} \ [n = 2k + 1]$.== \[Definition of $odd$]
>		2. ==Let $q \in \mathbb{Z}$ be such that $n = 2q + 1$.== \[Existential instantiation on line 4.1]
>		3. ==$n^2 + 3n = (2q + 1)^2 + 3(2q + 1) = 4q^2 + 4q + 1 + 6q + 3 = 2(2q^2 + 5q + 2)$.== \[Basic algebra]
>		4. Since ==$q \in \mathbb{Z}$==, we know that ==$2q^2 + 5q + 2 \in \mathbb{Z}$==. \[Basic algebra]
>		5. ==$\exists k \in \mathbb{Z} \ [n^2 + 3n = 2k]$.== \[Existential generalisation on line 4.4]
>		6. ==$even(n^2 + 3n)$.== \[Definition of $even$]
>5. ==In all cases, $even(n^2 + 3n)$.== \[Proof by cases on lines 2, 3.6, 4.6]
>6. ==$\forall n \in \mathbb{Z} \ \big[even(n^2 + 3n) \big]$.== \[Universal generalisation on lines 1 and 5]

---
# Question 4:

For this question, we refer to the following definition of **rational numbers**:

$$
x \in \mathbb{Q} \equiv \exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ \bigg[q \neq 0 \land x = \frac{p}{q}\bigg]
$$

Prove the following statement:

$$
\forall n \in \mathbb{Z} \ [n \in \mathbb{Q}]
$$

>[!Solution]
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. $\textcolor{red}{1} \in \mathbb{Z}$. \[Basic algebra]
>3. $n = \frac{\textcolor{blue}{n}}{\textcolor{red}{1}}$. \[Basic algebra]
>4. $\textcolor{red}{1} \neq 0$. \[Basic algebra]
>5. $\textcolor{red}{1} \neq 0 \land n = \frac{\textcolor{blue}{n}}{\textcolor{red}{1}}$. \[Conjunction on lines 3 and 4]
>6. $\exists \textcolor{blue}{p} \in \mathbb{Z}, \exists \textcolor{red}{q} \in \mathbb{Z} \ \big[\textcolor{red}{q} \neq 0 \land n = \frac{\textcolor{blue}{p}}{\textcolor{red}{q}}\big]$. \[Existential generalisation on line 5]
>7. $n \in \mathbb{Q}$. \[Definition of $\mathbb{Q}$]
>8. $\forall n \in \mathbb{Z} \ [n \in \mathbb{Q}]$. \[Universal generalisation on lines 1 and 7]

---
# Question 5 \[Graded for Participation]:

Prove the following statement:

$$
\forall m \in \mathbb{Z}, \forall n \in \mathbb{Z} \ \big[even(mn) \to \big(even(m) \lor even(n)\big)\big]
$$

You may use the following theorems:

>[!Theorem 1]
>$\forall x \in \mathbb{Z} \ [\neg even(x) \equiv odd(x)]$.

>[!Theorem 2]
>$\forall x \in \mathbb{Z} \ [\neg odd(x) \equiv even(x)]$.


>[!Solution]
>1. Let $m \in \mathbb{Z}$ and $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume that $\neg \big(even(m) \lor even(n)\big)$.
>		1. $\neg even(m) \land \neg even(n)$. \[Logically equivalent to line 2]
>		2.  $\neg even(m)$ \[Specialisation on line 2.1]
>		3. $\neg even(n)$ \[Specialisation on line 2.1]
>		4. $\forall x \in \mathbb{Z} \ [\neg even(x) \equiv odd(x)]$ \[Using Lemma 1]
>		5. $odd(m)$ \[Universal instantiation on line 1, 2.2]
>		6. $odd(n)$ \[Universal instantiation on line 1, 2.3]
>		7. $\exists k \in \mathbb{Z} \ [m = 2 \cdot k + 1]$. \[Definition of $odd$]
>		8. Let $s \in \mathbb{Z}$ be such that $m = 2 \cdot s + 1$. \[Existential instantiation on lines 1, 2.7]
>		9. Let $t \in \mathbb{Z}$ be such that $n = 2 \cdot t + 1$. \[Existential instantiation on line 1, 2.7]
>		10. $mn = (2s+1)(2t+1) = 4st+2s+2t+1 = 2 \cdot (2st+s+t) + 1$. \[Basic algebra, from lines 2.8 and 2.9]
>		11. Since $s, t \in \mathbb{Z}$, $2st+s+t \in \mathbb{Z}$. \[Basic algebra, from line 2.10]
>		12. $\exists k \in \mathbb{Z} \ [mn = 2 \cdot k + 1]$. \[Existential generalisation on lines 2.10 and 2.11]
>		13. $odd(mn)$. \[Definition of $odd$ on line 2.12]
>		14. Since $m \in \mathbb{Z} \land n \in \mathbb{Z}$, $mn \in \mathbb{Z}$ \[Basic algebra]
>		15. $\neg even(mn)$. \[Universal instantiation on line 2.14, 2.4]
>3. $\neg \big(even(m) \lor even(n)\big) \to \neg even(mn)$. \[Implication introduction on lines 2 and 2.13]
>4. $even(mn) \to \big(even(m) \lor even(n)\big)$. \[Logically equivalent to line 3]
>5. $\forall m \in \mathbb{Z}, \forall n \in \mathbb{Z} \ \big[even(mn) \to \big(even(m) \lor even(n)\big)\big]$, \[Universal generalisation on lines 1 and 4]

---
# Question 6:

Prove the following statement:

> [!Theorem] 
> $\forall x \in \mathbb{Z} \ [\neg (even(x) \land odd(x))]$

>[!Solution]
>**Proof:**
>1. Let $x \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume for the sake of contradiction that $\neg (\neg(even(x) \land odd(x)))$.
>		1. $(even(x) \land odd(x)$. \[Double negation on line 2]
>		2. $even(x)$. \[Specialisation on line 2.1]
>		3. $\exists k \in \mathbb{Z} \ [2k = x]$. \[Unpacking definition of $even$]
>		4. Let $s \in \mathbb{Z}$ be such that $2s = x$. \[Existential instantiation on line 2.3]
>		5. $odd(x)$. \[Specialisation on line 2.1]
>		6. $\exists j \in \mathbb{Z} \ [2j + 1 = x]$. \[Unpacking definition of $odd$]
>		7. Let $t \in \mathbb{Z}$ be such that $2t + 1 = x$. \[Existential instantiation on line 2.6]
>		8. Then, we have $2s = 2t + 1$. \[Basic algebra, from lines 2.4 and 2.7]
>		9. $2(s - t) = 1$. \[Basic algebra]
>		10. $s - t = \frac{1}{2}$. \[Basic algebra]
>		11. $\neg (s - t \in \mathbb{Z})$. \[Basic algebra, from line 2.10]
>		12. Since $s \in \mathbb{Z}$ and $t \in \mathbb{Z}$, we have $s - t \in \mathbb{Z}$. \[By basic algebra, from lines 2.4 and 2.7]
>		13. $(s - t \in \mathbb{Z}) \land \neg (s - t \in \mathbb{Z})$. \[Conjunction on lines 2.11 and 2.12]
>		14. $\bot$. \[Contradiction rule on line 2.13]
>3. $\neg \big(even(x) \land odd(x)\big)$. \[Proof by contradiction rule on line 2.14]
>4. $\forall x \in \mathbb{Z} \ \big[\neg \big(even(x) \land odd(x) \big)\big]$. \[Universal generalisation on lines 1 and 3]

**Note**: There's actually quite a few ways to do this question. But generally, the "most natural" way will probably have you deriving a contradiction somehow.

---
# Question 7 \[Bonus]:

You are tasked with building a load balancer that services $C$ clients, and has to balance them between $S$ servers. All clients will request to be serviced at the same time at the start of the day, and the load balancer must assign each client a server immediately at the start of the day.

Your boss tells you to keep costs down, that each server must service **fewer than** $\frac{C}{S}$ clients in total. Let $c_i$ be the number of clients that the $i^{th}$ server has to service, i.e., $c_1$ is the number of clients for the first server, $c_2$ is the number of clients for the second server, and so on. Since we have $S$ servers, we have quantities $c_1, c_2, \ldots, c_S$.

**Question:** Prove to yourself and your boss that this is impossible.

**Solution:**

Before we begin the proof, let's formalise what the question wants us to prove. We need to show that the following statement is true:

Given $C \in \mathbb{N}, S \in \mathbb{N}, c_{1} \in \mathbb{N}, c_{2} \in \mathbb{Z}, \dots, c_{S} \in \mathbb{N}$ such that $(C > 0) \land (\sum_{i=1}^S c_i = C)$, and the set $[S] = \{1, 2, \dots, S\}$ (refer to [[Unit 2#Common Sets for Numbers|this section]] for an explanation of this notation),

$$\neg \bigg(\forall i \in [S] \ \bigg[c_{i} < \frac{C}{S}\bigg]\bigg)$$

Essentially, that it is **impossible** (indicated by the "$\neg$" symbol) for all servers to service fewer than $\frac{C}{S}$ clients. Now that we have a concrete statement down, we can continue proving it:

>[!Solution]
>**Proof:**
>1. Let $c_{1}, c_{2}, \dots, c_{S} \in \mathbb{N}$, arbitrarily chosen, be such that $\sum_{i=1}^S c_{i} = C$.
>2. Assume for the sake of contradiction that $\forall i \in [S] \ \big[c_{i} < \frac{C}{S}\big]$.
>		1. Then, we must have that $c_{1} < \frac{C}{S}$, $c_{2} < \frac{C}{S}$, $\dots$, $c_{S} < \frac{C}{S}$. \[Universal instantiation on line 2.1]
>		2. $\sum_{i=1}^S c_{i} = c_{1} + c_{2} + \dots + c_{S} < \frac{C}{S} + \frac{C}{S} + \dots + \frac{C}{S} = S \cdot \frac{C}{S} = C$. Rewriting this (for presentation's sake), we have $\sum_{i=1}^S c_{i} < C$. \[Basic algebra]
>		3. In particular, $\neg \big(\sum_{i=1}^S c_{i} = C\big)$. \[Basic algebra]
>		4. $\big(\sum_{i=1}^S c_{i} = C\big) \land \neg \big(\sum_{i=1}^S c_{i} = C\big)$. \[Conjunction on lines 1 and 2.3]
>		5. $\bot$. \[Contradiction rule on line 2.4]
>3. $\neg \big(\forall i \in [S] \ \big[c_{i} < \frac{C}{S}\big]\big)$. \[Proof by contradiction rule on line 2.5]
>4. Therefore, $$\forall c_{1}, c_{2}, \dots, c_{S} \in \mathbb{N} \ \bigg[\neg \bigg(\forall i \in [S] \ \bigg[c_{i} < \frac{C}{S}\bigg]\bigg)\bigg]$$ \[Universal generalisation on lines 1 and 3]

Thus, such a task is impossible.