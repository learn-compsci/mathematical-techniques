
This is the second of two assignments and is worth 15% of the total grade. The assignment is due **Sunday 6th April 2025, 2359**. Submit your solutions digitally on Canvas, a submission box will be open under "Assignments > Assignment 2".

There are 4 questions for a total of 30 marks.

_Please make sure your handwriting is legible. You may scan/take a picture of handwritten solutions, you may also type your solutions. We are not particular about the symbol use if you cannot type out the symbols but please make it clear to us what symbol you were intending to use._


# How to submit:
- Submit online on Canvas. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
* **Official due date for submission** : **Sunday 6th April 2025, 2359**

# Collaboration Policy: 
* You may discuss high-level ideas with your classmates or friends. You should list your collaborators if you do so. 
* **Do not share your solutions**.
* ChatGPT (and other LLMs) are **not allowed**. 
* Your submission **must be of your own write-up**.

# Late Policy:
* No late submissions for the assignment allowed.


---

# Question 1  \[6 marks]

Given sets $A = \{1, 2, 3, 4, 5\}$, $B = \{ 2, 4, 6, 8 \}$, $C = \{ x \in \mathbb{Z} : \exists k \in \mathbb{Z}[x = 2k] \}$.


Write in **set roster notation** the following sets:
1. $A \cap B$
2. $A \setminus (B \setminus C)$
3. $A \cap (B \setminus C)$

---
# Question 2  \[6 marks]


For the following sets, state whether the equality holds or not. If they are equal stating so suffices. If they are not equal, give an example of sets to justify it.


**Example question:**
For example, given the following: $(A \setminus A) \setminus A \stackrel{?}{=} A \setminus (A \setminus A)$ 

**Example answer:**
This equality does not hold.  Consider $A = \{1\}$, then the LHS is $\emptyset$, and the RHS is $A$. Since $\emptyset \neq A$, the equality does not hold.



1. $(A \cup A) \cap (B \setminus A) \stackrel{?}{=} (B \setminus A)$
2. $\{ x \in \mathbb{Z} : x^2 \leq 4 \} \stackrel{?}{=} \{ x \in \mathbb{Z} : x \leq 2 \}$

---
# Question 3

Consider the following predicate:

$$
divides(a, b) \equiv \exists k \in \mathbb{Z} [a \cdot k = b]
$$


We will relate two numbers $x, y \in \mathbb{Z}$, in the following way:

$$
R = \bigg\{ (x, y) \in \mathbb{Z} 
\times \mathbb{Z} : \exists k \in \mathbb{N} \big[ k \neq 1 \land divides(k, x) \land divides(k, y) \big] \bigg\}
$$

For example: $(15, 10) \in R$, because both $divides(5, 10)$ and $divides(5, 15)$ are true, and $5 \in \mathbb{Z}$. Whereas $(2, 3) \notin R$, because no such integer $k \in \mathbb{Z}$ besides $1$ satisfies both $divides(k, 2)$ and $divides(k, 3)$.

## Sub-question 1: \[6 Marks]
Is $R$ reflexive? In other words, is it true that 

$$
\forall x \in \mathbb{Z} \big[ (x, x) \in R \big]
$$

If it is not true, state that it is false, and give an example value $x$ for which $(x, x) \notin R$. If it is true, prove it.

## Sub-question 2: \[6 Marks]
Is $R$ anti-symmetric? In other words, is it true that 

$$
\forall x \in \mathbb{Z}, \forall y \in \mathbb{Z} \big[ (x, y) \in R \land (y, x) \in R \to x = y \big]
$$
If it is not true, state that it is false, and give an example value $x$ for which $(x, x) \notin R$. If it is true, prove it.


---

# Question 4: \[6 Marks]

Prove via mathematical induction that for all $n \geq 1$:

$$
\sum_{r = 1}^n \frac{1}{r(r + 1)} = \frac{n}{n + 1}
$$

