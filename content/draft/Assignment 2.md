
This is the second of two assignments and is worth **15%** of the total grade. The assignment is due **Sunday, 5 Apr 2026, 11:59 PM**. Submit your solutions digitally on Canvas, where a submission box will be open under "Assignments > Assignment 2".

There are 4 questions for a total of 30 marks.

_Please make sure your handwriting is legible. You may scan/take a picture of handwritten solutions, you may also type your solutions. We are not particular about the symbol use if you cannot type out the symbols but please make it clear to us what symbol you were intending to use._

# How to submit:
- Submit online on Canvas. There will be a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
* **Official due date for submission**: **5 Apr 2026, 11:59 PM**

# Collaboration Policy: 
* You may discuss high-level ideas with your classmates or friends. You should list your collaborators if you do so. 
* **Do not share your solutions**.
* ChatGPT (and other LLMs) are **not allowed**. 
* Your submission **must be of your own write-up**.

# Late Policy:
* No late submissions for the assignment allowed.

---
# Question 1 (6 marks):

Let $A = \{1, 2, 3, 4, 5\}$, $B = \{ 2, 4, 6, 8 \}$ and $C = \{ x \in \mathbb{Z} : \exists k \in \mathbb{Z} \ [x = 2k] \}$.

Write the following sets in **set-roster notation**:
1. $A \cap B$
2. $A \setminus (B \setminus C)$
3. $A \cap (B \setminus C)$

---
# Question 2 (6 marks):

For this question, consider the following relation $R \subseteq \mathbb{Z} \times \mathbb{Z}$:

$$
R = \{(a, b) \in \mathbb{Z} \times \mathbb{Z} : a < 0 \land b > 0 \}
$$

### Sub-part 1 \[2 marks]

Is $R$ reflexive? If so, prove it. If not, give a value $a \in \mathbb{Z}$ such that $(a,a) \notin R$.

### Sub-part 2 \[4 marks]

Is $R$ transitive? If so, prove it. If not, give values $a, b, c \in \mathbb{Z}$ such that $(a, b) \in R \land (b, c) \in R \land (a, c) \notin R$.

---
# Question 3 (12 marks):

Consider the following predicate:

$$
divides(a, b) \equiv \exists k \in \mathbb{N}\ [a \cdot k = b]
$$


We will relate two numbers $x, y \in \mathbb{N}$, in the following way:

$$
R = \bigg\{ (x, y) \in \mathbb{N} 
\times \mathbb{N} : \exists k \in \mathbb{N}\ \big[ k \neq 1 \land divides(k, x) \land divides(k, y) \big] \bigg\}
$$

For example: $(15, 10) \in R$, because both $divides(5, 10)$ and $divides(5, 15)$ are true, and $5 \in \mathbb{N}$. Whereas $(2, 3) \notin R$, because no such natural number $k \in \mathbb{N}$ besides $1$ satisfies both $divides(k, 2)$ and $divides(k, 3)$.

### Sub-part 1 \[6 marks]

Is $R$ reflexive? In other words, is it true that 

$$
\forall x \in \mathbb{N}\ \big[ (x, x) \in R \big]
$$

If it is not true, state that it is false, and give an example value $x$ for which $(x, x) \notin R$. If it is true, prove it.

### Sub-part 2 \[6 marks]

Is $R$ anti-symmetric? In other words, is it true that 

$$
\forall x \in \mathbb{N}, \forall y \in \mathbb{N}\ \big[ (x, y) \in R \land (y, x) \in R \to x = y \big]
$$
If it is not true, state that it is false, and give an example values $x, y$ for which $(x, y) \in R$ and $(y, x) \in R$, but $x \neq y$. If it is true, prove it.

---
# Question 4 (6 marks):

Prove via mathematical induction that for all $n \geq 1$:

$$
\sum_{r = 1}^n \frac{1}{r(r + 1)} = \frac{n}{n + 1}
$$

