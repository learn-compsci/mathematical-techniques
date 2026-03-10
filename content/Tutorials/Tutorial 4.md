---
title: "Tutorial 4: Induction, Recurrences, Asymptotics"
---

# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.
* **Official due date for submission**: 17 Mar 2026, 11:59 PM **or** during tutorial itself.

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
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 4]] and [[Unit 5]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.

1. Questions 1 through 5 are related to induction and recurrences. 
2. Questions 6 through 8 are related to asymptotic notation.

After Week 7's content, you should be able to attempt questions 1 through 5. After Week 8's content, you should be able to attempt questions 6 through 8.

**Questions 1, 3 and 6** are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1 \[Graded for Participation]

Using mathematical induction, prove that:

$$
\forall n \geq 1\left[ \sum_{i = 1}^n i^2 =\frac{n(n+1)(2n+1)}{6} \right]
$$
---
# Question 2

Using mathematical induction, prove that:

$$
\forall n \geq 1, \exists k \in \mathbb{N} \left[ 6^n - 1 = 5\cdot k \right]
$$


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
Prove via strong induction that $\forall n\geq 0[A(n) = 2n + 1]$

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
\forall n \geq 3 [M(n) \leq n\log_2(n)]
$$

You may find the following facts useful:
1. $\lfloor \frac{n}{2} \rfloor \leq \frac{n}{2}$
2. $a \leq b \to \log_2(a) \leq \log_2(b)$

You may alternatively use the substitution method to prove that this is $O(n \log n)$.

---
# Question 5

Let $B(n)$ be a recurrence defined in the following way.


$$
B(n) = \begin{cases}
1, & n = 0\\
3\times B(n - 1), & n \geq 1
\end{cases}
$$

Prove by induction that:

$$
\forall n \in \mathbb{N}[B(n) = 3^n]
$$

---

# Question 6 \[Graded for Participation]

Let $B(n)$ be a recurrence defined in the following way.


$$
B(n) = \begin{cases}
1, & n = 0\\
3\times B(n - 1), & n \geq 1
\end{cases}
$$


## Sub-part 1
True or false? $B(n) \in O(3^n)$

(Hint: You may want to use the statement at end of question 4)

If it is true, explicitly give values $n_0$ and $c$ to justify that $B(n)$ is indeed in $O(3^n)$

## Sub-part 2
True or false? $B(n) \in \Omega(3^n)$

(Hint: You may want to use the statement at end of question 4)

If it is true, explicitly give values $n_0$ and $c$ to justify that $B(n)$ is indeed in $\Omega(3^n)$


## Sub-part 3
True or false? $B(n) \in \Theta(3^n)$

Why/why not? You do not have to give a proof.


(Hint: What is the definition of $\Theta$?)

---
# Question 7

Let $f(n), g(n)$ be functions such that $\forall n \in \mathbb{N}[f(n) \geq 0]$ and $\forall n \in \mathbb{N}[g(n) \geq 0]$. I.e. the functions are always non-negative.

Prove that:

$$
\max(f(n), g(n)) \in O(f(n) + g(n))
$$


---
# Question 8 (Challenging!)

Prove that:

$$
2^{2n} \notin O(2^n)
$$

\[Hint: Assume that $2^{2n} \in O(2^n)$. What kind of contradiction will you derive?]

