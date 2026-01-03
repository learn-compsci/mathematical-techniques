---
title: "Tutorial 2: Set Theory and Relations"
---

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

Questions 2, 4, 5, 7 are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1

Let $A = \{0\}$, and $B = \mathcal{P}(\{0, 1\})$. 

Find $\mathcal{P}(A)$ and $\mathcal{P}(B)$.

---
# Question 2 \[Graded for Participation]

Consider the sets $A = \{x \in \mathbb{Z} : x^{2} \leq 16\}$ and $B = \big\{x \in \mathbb{N} : (x \geq 1) \land \big(\exists k \in \mathbb{Z} \ [x = 3k + 1]\big)\big\}$, $C = \{1, 2\}$.

Find the following sets:

1. $A \cap B$
2. $A \cup B$
3. $A \setminus C$
4. $A \times C$

Note: Some of these can be written using [[Unit 2#Set Roster Notation]], these are the ones where you can list them out one by one. For the rest, you can write them using [[Unit 2#Set Builder Notation|set builder notation]].

---
# Question 3

Convert the following from set builder notation to set roster notation:
1. $A = \{ x \in \mathbb{Z} : x = 5 \lor x = 10 \}$
2. $B = \{x \in \mathbb{N} :  (x > 1) \land (x < 10) \land even(x) \}$
3. $C = \{x \in \mathbb{Z} : \exists k \in \mathbb{Z} \ [(x = 7k) \land (x \geq 0) \land (x < 60) \}$.
4. $D = \big\{x \in \mathbb{Z}: \forall a, b \in \mathbb{N} \ \big[(x < 10) \land (x > 1) \land \big((x = ab) \to (a = 1 \land b = x) \lor (a = x \land b = 1)\big)\big]\big\}$


**Hint for $D$**: It might be helpful to first think about what it's trying to do. That might speed things up for you.


---
# Question 4 \[Graded for Participation]

Prove the set equality $(A\setminus B) \setminus C =(A \setminus C) \setminus (B \cup C)$.

Prove the set equality $(A \setminus B) \cup C = (A \cup C) \setminus (B \setminus C)$.

**Hint:** [[Unit 2#Based on logical equivalences]] shows a method that is helpful.

---

# Question 5 \[Graded for Participation]

Let $R$ be the following relation:

$$
R = \{(1, 2), (3, 3), (2, 1), (5, 6), (6, 7), (7, 8)\}
$$

Compute $R^{-1}$. Compute $R; R$.

It might be helpful to refer to [[Unit 3#Operations on Relations]].

---

# Question 6

Let $A$ be the following set: $A = \{0, 1, 2\}$. Let $R = A \times A$. 

#### Sub-part 1
Is the following statement true?

> $R$ is reflexive.

If it is true, prove it. Otherwise, prove the negation of the statement. It might be helpful to refer to [[Unit 3#Reflexivity]].

#### Sub-part 2
Is the following statement true?

> $R$ is symmetric.

If it is true, prove it. Otherwise, prove the negation of the statement. It might be helpful to refer to [[Unit 3#Symmetry]].

#### Sub-part 3
Is the following statement true?

> $R$ is anti-symmetric.

If it is true, prove it. Otherwise, prove the negation of the statement. It might be helpful to refer to [[Unit 3#Anti-Symmetry]].

#### Sub-part 4
Is the following statement true?

> $R$ is transitive.

If it is true, prove it. Otherwise, prove the negation of the statement. It might be helpful to refer to [[Unit 3#Transitivity]].

---

# Question 7  \[Graded for Participation]

Is the following statement true?

> Let $A$ be any set. Let $R \subseteq A \times A$. 
> 
> If $R$ is symmetric, then $R; R$ is reflexive.

If it is, prove it. 

If it is not, give examples of $A$ and $R$ such that $R$ is symmetric, but $R; R$ is not reflexive.

---

# Question 8

Is the following statement true?

> Let $A$ be any set. Let $R \subseteq A \times A$. 
> 
> If $R$ is both reflexive and anti-symmetric, then $R$ is **not** symmetric.

~~If it is, prove it. If it is not, give examples of $A$, and $R$ such that the $R$ is both reflexive and anti-symmetric, but $R$ is not symmetric.~~

**Correction**: 

If it is, prove it. 

If it is not, give examples of $A$ and $R$ such that $R$ is both reflexive and anti-symmetric, but $R$ is also symmetric.