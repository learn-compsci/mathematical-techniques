
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
>		1. $xy = 0 \cdot y = 0$. **\[ (a) Rule of deduction: ==Basic algebra== ]**
>4. Case 2: Assume $y = 0$.
>		1. $xy = x \cdot 0 = 0$. **\[ (b) Rule of deduction: ==Basic algebra== ]**
>5. In all cases, we have $xy = 0$.  **\[ (c) Rule of deduction: ==Proof by cases on lines 2, 3.1, 4.1== ]**
>6. $(x = 0) \lor (y = 0) \to (xy = 0)$. **\[ (d) Rule of deduction: ==Implication introduction on lines 2 and 5== ]**
>7. $\forall x, y \in \mathbb{N} \ \big[(x = 0) \lor (y = 0) \to (xy = 0) \big]$. **\[ (e) Rule of deduction: ==Universal generalisation on lines 1 and 6== ]**

#### Sub-part 2

>[!note] Proof: $\forall n \in \mathbb{N} \ [n + 1 \neq 0]$
>1. Let $n \in \mathbb{N}$ be arbitrarily chosen.
>2. Suppose, for the sake of contradiction, that $\neg (n + 1 \neq 0)$.
>3. $n + 1 = 0$. **\[ (f) Rule of deduction: ==Logically equivalent to line 2== ]**
>4. $n = -1$. \[Basic algebra]
>5. $\neg (n \in \mathbb{N}).$ \[Basic algebra]
>6. $(n \in \mathbb{N}) \land \neg (n \in \mathbb{N})$. **\[ (g) Rule of deduction: ==Conjunction on lines 1 and 5== ]**
>7. $\bot$. **\[ (h) Rule of deduction: ==Contradiction rule on line 6== ]**
>8. $n + 1 \neq 0$. **\[ (i) Rule of deduction: ==Proof by contradiction on line 7== ]**
>9. $\forall n \in \mathbb{N} \ [n + 1 \neq 0]$. \[Universal generalisation on lines 1 and 8]

---
# Question 7 \[Graded Participation]:

Prove the following statement:

> [!Theorem] 
> $\forall x \in \mathbb{Z} \ [\neg (even(x) \land odd(x))]$
> 
> We define the predicate $even(x)$ to be: $even(x) \equiv \exists k \in \mathbb{Z} \ [2k = x]$, 
>  and we define the predicate $odd(x)$ to be: $odd(x) \equiv \exists j \in \mathbb{Z} \ [2j + 1 = x]$.

>[!Solution]
>**Proof:**
>1. Let $x \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume for the sake of contradiction that $even(x) \land odd(x)$.
>		1. $even(x)$. \[Specialisation on line 2]
>		2. $\exists k \in \mathbb{Z} \ [2k = x]$. \[Unpacking definition of $even$]
>		3. Let $s \in \mathbb{Z}$ be such that $2s = x$. \[Existential instantiation on line 2.2]
>		4. $odd(x)$. \[Specialisation on line 2]
>		5. $\exists j \in \mathbb{Z} \ [2j + 1 = x]$. \[Unpacking definition of $odd$]
>		6. Let $t \in \mathbb{Z}$ be such that $2t + 1 = x$. \[Existential instantiation on line 2.5]
>		7. Then, we have $2s = 2t + 1$. \[Basic algebra, from lines 2.3 and 2.6]
>		8. $2(s - t) = 1$. \[Basic algebra]
>		9. $s - t = \frac{1}{2}$. \[Basic algebra]
>		10. $\neg (s - t \in \mathbb{Z})$. \[Basic algebra, from line 2.9]
>		11. Since $s \in \mathbb{Z}$ and $t \in \mathbb{Z}$, we have $s - t \in \mathbb{Z}$. \[By basic algebra, from lines 2.3 and 2.6]
>		12. $(s - t \in \mathbb{Z}) \land \neg (s - t \in \mathbb{Z})$. \[Conjunction on lines 2.10 and 2.11]
>		13. $\bot$. \[Contradiction rule on line 2.12]
>3. $\neg \big(even(x) \land odd(x)\big)$. \[Proof by contradiction rule on line 2.13]
>4. $\forall x \in \mathbb{Z} \ \big[\neg \big(even(x) \land odd(x) \big)\big]$. \[Universal generalisation on lines 1 and 3]

---
# Question 8:

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