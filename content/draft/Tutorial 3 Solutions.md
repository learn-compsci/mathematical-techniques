
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.

* **Official due date for submission** : 18-Mar-2025, 23:59 **or** during tutorial itself.


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
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 4]] and Unit 5. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.


1. Questions 1 through 5 are related to induction and recurrences. 
2. Questions 6 through 8 are related to asymptotic notation.

After week 7's content, you should be able to attempt questions 1 through 5. After week 8's content, you should be able to attempt questions 6 through 8.

Questions 1, 3, 6, are graded for participation.

That said, **we encourage you to try all the questions**, this way when you come for tutorial we can best make use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1 \[Graded for Participation]

Using mathematical induction, prove that:

$$
\forall n \geq 1 \left[ \sum_{i = 1}^n i^2 =\frac{n(n+1)(2n+1)}{6} \right]
$$

**Solutions**:

>[!note] Proof
>1. (Base case) Let $n = 1$. Then, $\sum_{i=1}^{n} i^2 = 1^2 = 1 = \frac{1(1+1)(2+1)}{6}$. \[Basic algebra]
>2. (Inductive step) Assume that for $n = j$, where $j \in \mathbb{N}$, $\sum_{i=1}^{j} i^2 = \frac{j(j+1)(2j+1)}{6}$.
>3. $\sum_{i=1}^{j+1} i^2 = (\sum_{i=1}^{j} i^2) + (j+1)$ \[Basic algebra]
>4. $(\sum_{i=1}^{j} i^2) + (j+1) = \frac{j(j+1)(2j+1)}{6} + (j+1)$ \[By assumption on line 2]
>5. $\frac{j(j+1)(2j+1)}{6} + (j+1) = \frac{j(j+1)(2j+1)}{6} + \frac{6j+6}{6} = \frac{2j^3 + 3j^2 + 7j + 6}{6} = \frac{(j+1)(j+2)(2(j+1)+1)}{6}$ \[Basic algebra]
>6. $\sum_{i=1}^{j+1} i^2 = \frac{(j+1)(j+2)(2(j+1)+1)}{6}$ \[Basic algebra, from lines 3, 4, 5]
>7. $\forall n \geq 1 \left[ \sum_{i = 1}^n i^2 =\frac{n(n+1)(2n+1)}{6} \right]$ \[Principle of mathematical induction]

---
# Question 2

Using mathematical induction, prove that:

$$
\forall n \geq 1, \exists k \in \mathbb{N} \left[ 6^n - 1 = 5\cdot k \right]
$$

**Solutions**:

>[!note] Proof
>1. (Base case) Let $n = 1$. Then, $6^n - 1 = 6^1 - 1 = 5 = 5 \cdot 1$. \[Basic algebra]
>2. Since $1 \in \mathbb{N}$, $\exists k \in \mathbb{N}\ [6^n - 1 = 5 \cdot k]$. \[Existential generalisation on line 1]
>3. (Inductive step) Assume that for $n = j$, where $j \in \mathbb{N}$, $\exists k \in \mathbb{N}\ [6^j - 1 = 5 \cdot k]$.
>4. Let $m \in \mathbb{N}$ be such that $6^j - 1 = 5m$. \[Existential instantiation on line 3]
>5. $6^{j+1} - 1 = 6^j \cdot 6 - 1 = 6 \cdot (6^j - 1) + 5$. \[Basic algebra]
>6. $6 \cdot (6^j - 1) + 5 = 6 \cdot 5m + 5 = 30m + 5 = 5 \cdot (6m + 1)$. \[By assumption on line 3, 4]
>7. $6^{j+1} - 1 = 5 \cdot (6m + 1)$. \[Basic algebra, from lines 5, 6]
>8. Since $m \in \mathbb{N}$, $6m + 1 \in \mathbb{N}$. \[Basic algebra]
>9. $\exists k \in \mathbb{N}\ [6^{j+1} - 1 = 5 \cdot k]$ \[Existential generalisation on lines 7, 8]
>10. $\forall n \geq 1, \exists k \in \mathbb{N}\ [6^n - 1 = 5 \cdot k]$ \[Principle of mathematical induction]

---
# Question 3 \[Graded for Participation]

Let $A(n)$ be a recurrence defined in the following way.


$$
A(n) = \begin{cases}
1, & n = 0\\
3, & n = 1\\
2\times A(n - 1) - A(n - 2), & n \geq 2
\end{cases}
$$


## Sub-question 1
Compute the following values:

1. $A(0)$
2. $A(1)$
3. $A(2)$
4. $A(5)$


## Sub-question 2
Prove via strong induction that $\forall n\geq 0\ [A(n) = 2n + 1]$.


**Solutions**:

**Sub-question 1**:
1. $A(0) = 1$
2. $A(1) = 3$
3. $A(2) = 2 \times A(1) - A(0) = 5$
4. Since $A(3) = 2 \times A(2) - A(1) = 7$ and $A(4) = 2 \times A(3) - A(2) = 9$, we have $A(5) = 2 \times A(4) - A(3) = 11$.

**Sub-question 2**:

>[!note] Proof
>1. (Base cases) We prove the statement for $n = 0$ and $n = 1$. Clearly, $A(0) = 1 = 2(0) + 1$ and $A(1) = 3 = 2(1) + 1$.
>2. (Inductive step) Let $k \geq 2$, and assume that $\forall 0 \leq j < k\ [A(j) = 2j + 1]$.
>3. $A(k) = 2 \times A(k-1) - A(k-2)$ \[By definition of $A(n)$]
>4. Since $0 \leq k-1 < k$ and $0 \leq k-2 < k$, we have $A(k-1) = 2(k-1)+1 = 2k-1$ and $A(k-2) = 2(k-2)+1 = 2k-3$, respectively. \[By assumption on line 2]
>5. $A(k) = 2 \times (2k-1) - (2k-3) = 4k-2-2k+3 = 2k+1$ \[Basic algebra, from lines 3, 4]
>6. $\forall n \geq 0\ [A(n) = 2n + 1]$ \[Principle of mathematical induction]

---
# Question 4

Let $M(n)$ be a recurrence defined in the following way.


$$
M(n) = \begin{cases}
0 &, n = 1\\
2 &, n = 2\\
2\times M(\lfloor \frac{n}{2} \rfloor) + n &, n \geq 3\\
\end{cases}
$$

Prove via strong induction that:

$$
\forall n \geq 3 \ [M(n) \leq n\log_2(n)]
$$

You may find the following facts useful:
1. $\lfloor \frac{n}{2} \rfloor \leq \frac{n}{2}$
2. $a \leq b \to \log_2(a) \leq \log_2(b)$

You may alternatively use the substitution method to prove that this is $O(n \log n)$.


**Solutions**:
