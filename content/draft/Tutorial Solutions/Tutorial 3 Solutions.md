
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.
* **Official due date for submission**: 3 Mar 2026, 11:59 PM **or** during tutorial itself.

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

This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 2]] and [[Unit 3]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.

1. Questions 1 through 4 are related to set theory. 
2. Questions 5 through 8 are related to relations.

After Week 5's content, you should be able to attempt questions 1 through 4. After Week 6's content, you should be able to attempt questions 5 through 8.

**Questions 2, 4, 5 and 7** are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1:

Let $A = \{0\}$, and $B = \mathcal{P}(\{0, 1\})$. 

Find $\mathcal{P}(A)$ and $\mathcal{P}(B)$.

>[!Solution]
> $\mathcal{P}(A) = \{\emptyset, \{0\}\}$. Observe that $\mathcal{P}(A)$ has $2^{|A|} = 2^1 = 2$ elements.
>
> $\mathcal{P}(\{0,1\}) = \big\{\textcolor{green}{\emptyset}, \textcolor{blue}{\{0\}}, \textcolor{red}{\{1\}}, \textcolor{purple}{\{0,1\}}\big\}$, so:
> $$
> \begin{align*}
> \mathcal{P}(B) = \{
> \\&\emptyset, 
> \\&
> \\&\{\textcolor{green}{\emptyset}\}, \big\{\textcolor{blue}{\{0\}}\big\}, \big\{\textcolor{red}{\{1\}}\big\}, \big\{\textcolor{purple}{\{0,1\}}\big\},
> \\&
> \\&\big\{\textcolor{green}{\emptyset}, \textcolor{blue}{\{0\}}\big\}, \big\{\textcolor{green}{\emptyset}, \textcolor{red}{\{1\}}\big\}, \big\{\textcolor{green}{\emptyset}, \textcolor{purple}{\{0,1\}}\big\}, \big\{\textcolor{blue}{\{0\}}, \textcolor{red}{\{1\}}\big\}, \big\{\textcolor{blue}{\{0\}}, \textcolor{purple}{\{0,1\}}\big\}, \big\{\textcolor{red}{\{1\}}, \textcolor{purple}{\{0,1\}}\big\},
> \\&
> \\&\big\{\textcolor{green}{\emptyset}, \textcolor{blue}{\{0\}}, \textcolor{red}{\{1\}}\big\}, \big\{\textcolor{green}{\emptyset}, \textcolor{blue}{\{0\}}, \textcolor{purple}{\{0,1\}}\big\}, \big\{\textcolor{green}{\emptyset}, \textcolor{red}{\{1\}}, \textcolor{purple}{\{0,1\}}\big\}, \big\{\textcolor{blue}{\{0\}}, \textcolor{red}{\{1\}}, \textcolor{purple}{\{0,1\}}\big\},
> \\&
> \\&\big\{\textcolor{green}{\emptyset}, \textcolor{blue}{\{0\}}, \textcolor{red}{\{1\}}, \textcolor{purple}{\{0,1\}}\big\}
> \\\}
> \end{align*}
> $$

Observe that $\mathcal{P}(B)$ has $2^{|B|} = 2^4 = 16$ elements.

---
# Question 2 \[Graded for Participation]:

Consider the sets $A = \{x \in \mathbb{Z} : x^{2} \leq 16\}$ and $B = \big\{x \in \mathbb{N} : (x \geq 1) \land \big(\exists k \in \mathbb{Z} \ [x = 3k + 1]\big)\big\}$, $C = \{1, 2\}$.

Find the following sets:

1. $A \cap B$
2. $A \cup B$
3. $A \setminus C$
4. $A \times C$

Note: Some of these can be written using [[Unit 2#Set-roster notation|set-roster notation]]—these are the ones where you can list them out one by one. For the rest, you can write them using [[Unit 2#Set-builder notation|set-builder notation]].

>[!Solution]
> First, we write out $A$ in set-roster notation: $A = \{-4, -3, -2, -1, 0, 1, 2, 3, 4\}$.
> Next, set $B$ is simply all the positive natural numbers that are $1$ greater than a multiple of $3$.
>
> Then, we have the following sets:
> 1. $A \cap B = \{1, 4\}$
> 2. $A \cup B = \big\{x \in \mathbb{Z} : (x^2 \leq 16) \lor \big((x \geq 1) \land \big(\exists k \in \mathbb{Z} \ [x = 3k + 1]\big) \big) \big\}$
> 3. $A \setminus C = \{-4, -3, -2, -1, 0, 3, 4\}$
> 4.
> 
> $$
> \begin{align*}
> A \times C = \{
> \\&(-4, 1), (-3, 1), (-2, 1), (-1, 1), (0, 1), (1, 1), (2, 1), (3, 1), (4, 1),
> \\&(-4, 2), (-3, 2), (-2, 2), (-1, 2), (0, 2), (1, 2), (2, 2), (3, 2), (4, 2)
> \\&\}
> \end{align*}
> $$

---
# Question 3:

Convert the following from set-builder notation to set-roster notation:

1. $A = \{ x \in \mathbb{Z} : (x = 5) \lor (x = 10) \}$
2. $B = \{x \in \mathbb{N} :  (x > 1) \land (x < 10) \land even(x) \}$
3. $C = \big\{x \in \mathbb{Z} : \exists k \in \mathbb{Z} \ \big[(x = 7k) \land (x \geq 0) \land (x < 60) \big] \big\}$.
4. $D = \big\{x \in \mathbb{Z}: \forall a, b \in \mathbb{N} \ \big[(x < 10) \land (x > 1) \land \big((x = ab) \to (a = 1 \land b = x) \lor (a = x \land b = 1)\big)\big]\big\}$

**Hint for $D$**: It might be helpful to first think about what it's trying to do. That might speed things up for you.

>[!Solution]
> 1. $A = \{5, 10\}$
> 2. $B = \{2, 4, 6, 8\}$
> 3. $C = \{0, 7, 14, 21, 28, 35, 42, 49, 56\}$
> 4. $D = \{2, 3, 5, 7\}$, i.e., the set of prime numbers between $1$ and $10$

---
# Question 4 \[Graded for Participation]:

Prove the set equality $(A\setminus B) \setminus C =(A \setminus C) \setminus (B \cup C)$.

Prove the set equality $(A \setminus B) \cup C = (A \cup C) \setminus (B \setminus C)$.

**Hint:** [[Unit 2#Method 2 Based on logical equivalences|This section]] shows a method that might be helpful.

**Solution**:

The first problem is equivalent to the following: 

$$
(a \land \neg b) \land \neg c \equiv (a \land \neg c) \land \neg (b \lor c)
$$

Using a truth table, we see that this equivalence is true:

| $a$     | $b$     | $c$     | $\neg b$ | $\neg c$ | $a \land \neg b$ | $a \land \neg c$ | $b \lor c$ | $\neg (b \lor c)$ | $(a \land \neg b) \land \neg c$ | $(a \land \neg c) \land \neg (b \lor c)$ |
| ------- | ------- | ------- | -------- | -------- | ---------------- | ---------------- | ---------- | ----------------- | ------------------------------- | ---------------------------------------- |
| $true$  | $true$  | $true$  | $false$  | $false$  | $false$          | $false$          | $true$     | $false$           | $\textcolor{blue}{false}$       | $\textcolor{blue}{false}$                |
| $true$  | $true$  | $false$ | $false$  | $true$   | $false$          | $true$           | $true$     | $false$           | $\textcolor{blue}{false}$       | $\textcolor{blue}{false}$                |
| $true$  | $false$ | $true$  | $true$   | $false$  | $true$           | $false$          | $true$     | $false$           | $\textcolor{blue}{false}$       | $\textcolor{blue}{false}$                |
| $true$  | $false$ | $false$ | $true$   | $true$   | $true$           | $true$           | $false$    | $true$            | $\textcolor{blue}{true}$        | $\textcolor{blue}{true}$                 |
| $false$ | $true$  | $true$  | $false$  | $false$  | $false$          | $false$          | $true$     | $false$           | $\textcolor{blue}{false}$       | $\textcolor{blue}{false}$                |
| $false$ | $true$  | $false$ | $false$  | $true$   | $false$          | $false$          | $true$     | $false$           | $\textcolor{blue}{false}$       | $\textcolor{blue}{false}$                |
| $false$ | $false$ | $true$  | $true$   | $false$  | $false$          | $false$          | $true$     | $false$           | $\textcolor{blue}{false}$       | $\textcolor{blue}{false}$                |
| $false$ | $false$ | $false$ | $true$   | $true$   | $false$          | $false$          | $false$    | $true$            | $\textcolor{blue}{false}$       | $\textcolor{blue}{false}$                |

Hence, $(A\setminus B) \setminus C =(A \setminus C) \setminus (B \cup C)$.

The second problem is equivalent to the following:

$$
(a \land \neg b) \lor c \equiv (a \lor c) \land \neg (b \land \neg c)
$$

Using a truth table, we see that this equivalence is also true:

| $a$     | $b$     | $c$     | $\neg b$ | $\neg c$ | $a \land \neg b$ | $a \lor c$ | $b \land \neg c$ | $\neg (b \land \neg c)$ | $(a \land \neg b) \lor c$ | $(a \lor c) \land \neg (b \land \neg c)$ |
| ------- | ------- | ------- | -------- | -------- | ---------------- | ---------- | ---------------- | ----------------------- | ------------------------- | ---------------------------------------- |
| $true$  | $true$  | $true$  | $false$  | $false$  | $false$          | $true$     | $false$          | $true$                  | $\textcolor{blue}{true}$  | $\textcolor{blue}{true}$                 |
| $true$  | $true$  | $false$ | $false$  | $true$   | $false$          | $true$     | $true$           | $false$                 | $\textcolor{blue}{false}$ | $\textcolor{blue}{false}$                |
| $true$  | $false$ | $true$  | $true$   | $false$  | $true$           | $true$     | $false$          | $true$                  | $\textcolor{blue}{true}$  | $\textcolor{blue}{true}$                 |
| $true$  | $false$ | $false$ | $true$   | $true$   | $true$           | $true$     | $false$          | $true$                  | $\textcolor{blue}{true}$  | $\textcolor{blue}{true}$                 |
| $false$ | $true$  | $true$  | $false$  | $false$  | $false$          | $true$     | $false$          | $true$                  | $\textcolor{blue}{true}$  | $\textcolor{blue}{true}$                 |
| $false$ | $true$  | $false$ | $false$  | $true$   | $false$          | $false$    | $true$           | $false$                 | $\textcolor{blue}{false}$ | $\textcolor{blue}{false}$                |
| $false$ | $false$ | $true$  | $true$   | $false$  | $false$          | $true$     | $false$          | $true$                  | $\textcolor{blue}{true}$  | $\textcolor{blue}{true}$                 |
| $false$ | $false$ | $false$ | $true$   | $true$   | $false$          | $false$    | $false$          | $true$                  | $\textcolor{blue}{false}$ | $\textcolor{blue}{false}$                |

Hence, $(A \setminus B) \cup C = (A \cup C) \setminus (B \setminus C)$.

*For those who are interested in reading more rigorous proofs:*

>[!note]- Proof: $(A \setminus B) \setminus C = (A \setminus C) \setminus (B \cup C)$
>1. $(\subseteq)$ **Let $x \in (A \setminus B) \setminus C$ be arbitrarily chosen.**
>		1. $(x \in A \setminus B) \land (x \notin C)$ \[Definition of set difference]
>		2. $(x \in A) \land (x \notin B) \land (x \notin C)$ \[Definition of set difference]
>			1. $(x \in A)$ \[Specialisation on line 1.2]
>			2. $(x \notin B)$ \[Specialisation on line 1.2]
>			3. $(x \notin C)$ \[Specialisation on line 1.2]
>		4. $(x \in A) \land (x \notin C)$ \[Conjunction on lines 1.2.1 and 1.2.3]
>		5. $x \in A \setminus C$ \[Definition of set difference]
>		6. $(x \notin B) \land (x \notin C)$ \[Conjunction on lines 1.2.2 and 1.2.3]
>		7. $\neg \big((x \in B) \lor (x \in C)\big)$ \[Logically equivalent to line 1.5]
>		8. $\neg \big(x \in B \cup C\big)$ \[Definition of set union]
>		9. $x \notin B \cup C$ \[Equivalent to line 1.7]
>		10. $(x \in A \setminus C) \land (x \notin B \cup C)$ \[Conjunction on lines 1.4 and 1.8]
>		11. $x \in (A \setminus C) \setminus (B \cup C)$ \[Definition of set difference]
>		12. $\forall x \in (A \setminus B) \setminus C \ [x \in (A \setminus C) \setminus (B \cup C)]$ \[Universal generalisation on lines 1 and 1.10]
>		13. $(A \setminus B) \setminus C \subseteq (A \setminus C) \setminus (B \cup C)$ \[Definition of subset]
>2. $(\supseteq)$ **Let $x \in (A \setminus C) \setminus (B \cup C)$ be arbitrarily chosen.**
>		1. $(x \in A \setminus C) \land (x \notin B \cup C)$ \[Definition of set difference]
>		2. $(x \in A) \land (x \notin C) \land (x \notin B \cup C)$ \[Definition of set difference]
>		3. $(x \in A) \land (x \notin C) \land \neg (x \in B \cup C)$ \[Equivalent to line 2.2]
>		4. $(x \in A) \land (x \notin C) \land \neg \big((x \in B) \lor (x \in C)\big)$ \[Definition of set union]
>		5. $(x \in A) \land (x \notin C) \land (x \notin B) \land (x \notin C)$ \[Logically equivalent to line 2.4]
>			1. $x \in A$ \[Specialisation on line 2.5]
>			2. $x \notin B$ \[Specialisation on line 2.5]
>			3. $x \notin C$ \[Specialisation on line 2.5]
>		6. $(x \in A) \land (x \notin B)$ \[Conjunction on lines 2.5.1 and 2.5.2]
>		7. $x \in A \setminus B$ \[Definition of set difference]
>		8. $(x \in A \setminus B) \land (x \notin C)$ \[Conjunction on lines 2.7 and 2.5.3]
>		9. $x \in (A \setminus B) \setminus C$ \[Definition of set difference]
>		10. $\forall x \in (A \setminus C) \setminus (B \cup C) \ [x \in (A \setminus B) \setminus C]$ \[Universal generalisation on lines 2 and 2.9]
>		11. $(A \setminus C) \setminus (B \cup C) \subseteq (A \setminus B) \setminus C$ \[Definition of subset]
>3. $\bigg((A \setminus B) \setminus C \subseteq (A \setminus C) \setminus (B \cup C)\bigg) \land \bigg((A \setminus C) \setminus (B \cup C) \subseteq (A \setminus B) \setminus C\bigg)$ \[Conjunction on lines 1.12 and 2.11]
>4. $(A \setminus B) \setminus C = (A \setminus C) \setminus (B \cup C)$ \[Definition of set equality]

>[!note]- Proof: $(A \setminus B) \cup C = (A \cup C) \setminus (B \setminus C)$
>1. **$(\subseteq)$ Let $x \in (A \setminus B) \cup C$ be arbitrarily chosen.**
>		1. $\big((x \in A) \land (x \notin B)\big) \lor (x \in C)$. \[Definition of set difference]
>		2. Case 1: $(x \in A) \land (x \notin B)$
>			1. $x \in A$ \[Specialisation on line 1.2]
>			2. $x \notin B$ \[Specialisation on line 1.2]
>			3. $(x \in A) \lor (x \in C)$ \[Generalisation on line 1.2.1]
>			4. $x \in A \cup C$ \[Definition of set union]
>			5. $(x \notin B) \lor (x \in C)$ \[Generalisation on line 1.2.2]
>			6. $\neg \big((x \in B) \land (x \notin C)\big)$ \[Logically equivalent to line 1.2.5]
>			7. $\neg (x \in B \setminus C)$ \[Definition of set difference]
>			8. $x \notin B \setminus C$ \[Equivalent to line 1.2.7]
>			9. $(x \in A \cup C) \land (x \notin B \setminus C)$ \[Conjunction on lines 1.2.4 and 1.2.8]
>			10. $x \in (A \cup C) \setminus (B \setminus C)$ \[Definition of set difference]
>		3. Case 2: $x \in C$
>			1. $(x \in A) \lor (x \in C)$ \[Generalisation on line 1.3]
>			2. $(x \notin B) \lor (x \in C)$ \[Generalisation on line 1.3]
>			3. $\neg \big((x \in B) \land (x \notin C)\big)$ \[Logically equivalent to line 1.3.2]
>			4. $\neg (x \in B \setminus C)$ \[Definition of set difference]
>			5. $x \notin B \setminus C$ \[Equivalent to line 1.3.4]
>			6. $(x \in A \cup C) \land (x \notin B \setminus C)$ \[Conjunction on lines 1.3.1 and 1.3.5]
>			7. $x \in (A \cup C) \setminus (B \setminus C)$ \[Definition of set difference]
>		4. $x \in (A \cup C) \setminus (B \setminus C)$ \[Proof by cases on lines 1.1, 1.2.10, 1.3.7]
>		5. $\forall x \in (A \setminus B) \cup C \ [x \in (A \cup C) \setminus (B \setminus C)]$ \[Universal generalisation on lines 1 an d 1.4]
>		6. $(A \setminus B) \cup C \subseteq (A \cup C) \setminus (B \setminus C)$ \[Definition of subset]
>2. **$(\supseteq)$ Let $x \in (A \cup C) \setminus (B \setminus C)$ be arbitrarily chosen.**
>		1. $(x \in A \cup C) \land (x \notin B \setminus C)$ \[Definition of set difference]
>		2. $\big((x \in A) \lor (x \in C)\big) \land (x \notin B \setminus C)$ \[Definition of set union]
>		3. $\big((x \in A) \lor (x \in C)\big) \land \neg (x \in B \setminus C)$ \[Equivalent to line 2.2]
>		4. $\big((x \in A) \lor (x \in C)\big) \land \neg \big((x \in B) \land (x \notin C)$ \[Definition of set difference]
>		5. $\big((x \in A) \lor (x \in C)\big) \land \big((x \notin B) \lor (x \in C)$ \[Logically equivalent to line 2.4]
>		6. $(x \in C) \lor \big((x \in A) \land (x \notin B)\big)$ \[Logically equivalent to line 2.5]
>		7. Case 1: $x \in C$
>			1. $(x \in A \setminus B) \lor (x \in C)$ \[Generalisation on line 2.7]
>			2. $x \in (A \setminus B) \cup C$ \[Definition of set union]
>		8. Case 2: $(x \in A) \land (x \notin B)$
>			1. $x \in A \setminus B$ \[Definition of set difference]
>			2. $(x \in A \setminus B) \lor (x \in C)$ \[Generalisation on line 2.8]
>			3. $x \in (A \setminus B) \cup C$ \[Definition of set union]
>		9. $x \in (A \setminus B) \cup C$ \[Proof by cases on lines 2.6, 2.7.2, 2.8.3]
>		10. $\forall x \in (A \cup C) \setminus (B \setminus C) \ [x \in (A \setminus B) \cup C]$ \[Universal generalisation on lines 2 and 2.9]
>		11. $(A \cup C) \setminus (B \setminus C) \subseteq (A \setminus B) \cup C$ \[Definition of subset]
>3. $\bigg((A \setminus B) \cup C \subseteq (A \cup C) \setminus (B \setminus C)\bigg) \land \bigg((A \cup C) \setminus (B \setminus C) \subseteq (A \setminus B) \cup C\bigg)$ \[Conjunction on lines 1.6 and 2.11]
>4. $(A \setminus B) \cup C = (A \cup C) \setminus (B \setminus C)$ \[Definition of set equality]

---
# Question 5 \[Graded for Participation]:

Let $R$ be the following relation:

$$
R = \{(1, 2), (3, 3), (2, 1), (5, 6), (6, 7), (7, 8)\}
$$

Compute:
1. $R^{-1}$
2. $R; R$

It might be helpful to refer to [[Unit 3#Part 2 Operations on Relations|this section]].

>[!note] Solution
> $R^{-1} = \{(2,1), (3,3), (1,2), (6,5), (7,6), (8,7)\}$
>
> $R;R = \{(1,1), (2,2), (3,3), (5,7), (6,8)\}$

---
# Question 6:

Let $A$ be the following set: $A = \{0, 1, 2\}$. Let $R = A \times A$. 

#### Sub-part 1

Is the following statement true?

> $R$ is reflexive.

If it is true, prove it. Otherwise, prove the negation of the statement. It might be helpful to refer to [[Unit 3#Property 1 Reflexivity|this section]].

>[!note] Proof: $R$ is reflexive
>1. Let $x \in A$ be arbitrarily chosen.
>2. $(x \in A) \land (x \in A)$ \[Conjunction on line 1]
>3. $(x,x) \in A \times A$ \[Definition of cartesian product]
>4. $(x,x) \in R$ \[Definition of $R$]
>5. $\forall a \in A \ \big[(a,a) \in R \big]$ \[Universal generalisation on lines 1 and 4]
>6. $R$ is reflexive. \[Definition of reflexivity]

#### Sub-part 2

Is the following statement true?

> $R$ is symmetric.

If it is true, prove it. Otherwise, prove the negation of the statement. It might be helpful to refer to [[Unit 3#Property 2 Symmetry|this section]].

>[!note] Proof: $R$ is symmetric
>1. Let $x \in A$ and $y \in A$ be arbitrarily chosen.
>2. Suppose that $(x,y) \in R$.
>		1. $(y \in A) \land (x \in A)$ \[Conjunction on line 1]
>		2. $(y,x) \in A \times A$ \[Definition of Cartesian product, from line 2.1]
>		3. $(y,x) \in R$ \[Definition of $R$]
>3. $(x,y) \in R \to (y,x) \in R$ \[Implication introduction on lines 2 and 2.3]
>4. $\forall a \in A, b \in A \ \big[(a,b) \in R \to (b,a) \in R\big]$ \[Universal generalisation on lines 1 and 3]
>5. $R$ is symmetric. \[Definition of symmetry]

#### Sub-part 3

Is the following statement true?

> $R$ is anti-symmetric.

If it is true, prove it. Otherwise, prove the negation of the statement. It might be helpful to refer to [[Unit 3#Property 3 Anti-Symmetry|this section]].

>[!note] Proof: $R$ is not anti-symmetric
>Let's start by taking the negation of the statement for anti-symmetry. If we are be able to prove that the negation is **true**, then we prove the the original statement is **false**. 
>
>$\neg \bigg(\forall a \in A, \forall b \in A \ \big[\big((a, b)\in R \land (b, a) \in R) \to a = b \big] \bigg)$
>$\equiv \exists a \in A, \exists b \in A \ \neg \bigg[\big((a, b)\in R \land (b, a) \in R \big) \to a = b \bigg]$ \[Negating universal quantifiers]
>$\equiv \exists a \in A, \exists b \in A \ \neg \bigg[\neg \big((a, b)\in R \land (b, a) \in R \big) \lor a = b \bigg]$ \[Logically equivalent]
>$\equiv \exists a \in A, \exists b \in A \ \bigg[(a, b)\in R \land (b, a) \in R \land a \neq b \bigg]$ \[Logically equivalent]
>
>1. $0 \in A$
>2. $1 \in A$
>3. $(0, 1) \in A \times A$ \[Definition of Cartesian product, from line 1]
>4. $(0, 1) \in R$ \[Definition of $R$]
>5. $(1, 0) \in A \times A$ \[Definition of Cartesian product, from line 1]
>6. $(1, 0) \in R$ \[Definition of $R$]
>7. $(0, 1) \in R \land (1, 0) \in R$ \[Conjunction on lines 4 and 6]
>8. $0 \neq 1$ \[By basic algebra]
>9. $\big((0, 1) \in R \land (1, 0) \in R \big) \land (0 \neq 1)$ \[Conjunction on lines 7 and 8]
>10. Therefore, $\exists a \in A, b \in A \ \bigg[(a, b)\in R \land (b, a) \in R \land a \neq b \bigg]$. \[Existential generalisation on lines 1, 2, 9]
>11. Since the negation of anti-symmetry is true for $R$, therefore $R$ is not anti-symmetric. \[Definition of anti-symmetry]

#### Sub-part 4

Is the following statement true?

> $R$ is transitive.

If it is true, prove it. Otherwise, prove the negation of the statement. It might be helpful to refer to [[Unit 3#Property 4 Transitivity|this section]].

>[!note] Proof: $R$ is transitive
>1. Let $x \in A$, $y \in A$ and $z \in A$ be arbitrarily chosen.
>2. Suppose that $(x, y) \in R \land (y, z) \in R$.
>		1. Since $(x \in A) \land (z \in A)$, $(x, z) \in A \times A$. \[Definition of Cartesian product, from line 1]
>		2. $(x,z) \in R$ \[Definition of $R$]
>3. $\big((x, y) \in R \land (y, z) \in R \big) \to (x, z) \in R$ \[Implication introduction on lines 2 and 2.2]
>4. $\forall a \in A, b \in A, c \in A \ \bigg[\big((a, b) \in R \land (b, c) \in R \big) \to (a, c) \in R \bigg]$ \[Universal generalisation on lines 1 and 3]
>5. $R$ is transitive. \[Definition of transitivity]

---
# Question 7  \[Graded for Participation]:

Is the following statement true?

> Let $A$ be any set. Let $R \subseteq A \times A$. 
> 
> If $R$ is symmetric, then $R; R$ is reflexive.

If it is, prove it. If it is not, give examples of $A$ and $R$ such that the $R$ is symmetric, but $R; R$ is not reflexive.

>[!note] Solution
>**False**. 
>
>Consider the set $A = \{1, 2\}$. Then $A \times A = \{(1, 1), (2, 2), (1, 2), (2, 1)\}$. 
>Let $R = \{(1, 1)\} \subseteq A \times A$. Then $R;R = \{(1, 1)\}$.
>
>Since $(\textcolor{green}{1}, \textcolor{red}{1}) \in R$, we need $(\textcolor{red}{1}, \textcolor{green}{1}) \in R$ for $R$ to be symmetric, which is true. 
>
>However, $R;R$ is not reflexive, since $2 \in A$ but $(2, 2) \notin R;R$.

---
# Question 8:

Is the following statement true?

> Let $A$ be any set. Let $R \subseteq A \times A$. 
> 
> If $R$ is both reflexive and anti-symmetric, then $R$ is **not** symmetric.

If it is, prove it. If it is not, give examples of $A$ and $R$ such that the $R$ is both reflexive and anti-symmetric, but $R$ is also symmetric.

**Solutions**:

>[!note] Solution
>**False**.
>
>Consider $A = \{1, 2\}$. Then $A \times A = \{(1, 1), (2, 2), (1, 2), (2, 1)\}$.
>Let $R = \{(1, 1), (2, 2)\} \subseteq A \times A$.
>
>Clearly, $R$ is reflexive, since both $(1, 1)$ and $(2, 2)$ are in $R$. 
>
>Next, $R$ is also anti-symmetric. Let's examine the elements of $R$.
>1. For $(1,1)$, we have $(1,1) \in R \land (1,1) \in R$, and $1 = 1$.
>2. Similarly, for $(2,2)$, we have $(2,2) \in R \land (2,2) \in R$, and $2 = 2$.
>
>Hence, $R$ is anti-symmetric.
>
>It is easy to check that $R$ is symmetric as well.

