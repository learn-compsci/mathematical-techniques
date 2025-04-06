
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

Given sets $A = \{1, 2, 3, 4, 5\}$, $B = \{ 2, 4, 6, 8 \}$, $C = \{ x \in \mathbb{Z} : \exists k \in \mathbb{Z}\ [x = 2k] \}$.


Write in **set roster notation** the following sets:
1. $A \cap B$
2. $A \setminus (B \setminus C)$
3. $A \cap (B \setminus C)$


>[!note] Solutions
>1. $A \cap B = \{2, 4\}$
>2. $A \setminus (B \setminus C) = A \setminus \emptyset = \{1, 2, 3, 4, 5\}$
>3. $A \cap (B \setminus C) = A \cap \emptyset = \emptyset$


---
# Question 2  \[6 marks]


For the following sets, state whether the equality holds or not. If they are equal stating so suffices. If they are not equal, give an example of sets to justify it.


**Example question:**
For example, given the following: $(A \setminus A) \setminus A \stackrel{?}{=} A \setminus (A \setminus A)$ 

**Example answer:**
This equality does not hold.  Consider $A = \{1\}$, then the LHS is $\emptyset$, and the RHS is $A$. Since $\emptyset \neq A$, the equality does not hold.

1. $(A \cup A) \cap (B \setminus A) \stackrel{?}{=} (B \setminus A)$
2. $\{ x \in \mathbb{Z} : x^2 \leq 4 \} \stackrel{?}{=} \{ x \in \mathbb{Z} : x \leq 2 \}$


>[!note] Solutions
>1. **False**. Consider $A = \emptyset$ and $B = \{1\}$. Then, $(A \cup A) \cap (B \setminus A) = \emptyset \cap \{1\} = \emptyset \neq \{1\} = B \setminus A$.
>2. **False**. $-3 \in \{x \in \mathbb{Z} : x \leq 2\}$ since $-3 \leq 2$, but $-3 \notin \{x \in \mathbb{Z} : x^2 \leq 4\}$ since $(-3)^2 = 9 > 4$.


---
# Question 3

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

## Sub-question 1: \[6 Marks]
Is $R$ reflexive? In other words, is it true that 

$$
\forall x \in \mathbb{N}\ \big[ (x, x) \in R \big]
$$

If it is not true, state that it is false, and give an example value $x$ for which $(x, x) \notin R$. If it is true, prove it.

## Sub-question 2: \[6 Marks]
Is $R$ anti-symmetric? In other words, is it true that 

$$
\forall x \in \mathbb{N}, \forall y \in \mathbb{N}\ \big[ (x, y) \in R \land (y, x) \in R \to x = y \big]
$$
If it is not true, state that it is false, and give an example values $x, y$ for which $(x, y) \in R$ and $(y, x) \in R$, but $x \neq y$. If it is true, prove it.


>[!note] Sub-question 1
>**No**, $R$ is not reflexive. Consider $x = 1 \in \mathbb{N}$. Now, we prove that $(1,1) \notin R$.
>
>**Proof:**
>1. Suppose, for the sake of contradiction, that $(1,1) \in R$.
>2. $\exists k \in \mathbb{N}\ [k \neq 1 \land divides(k,1) \land divides(k,1)]$ \[Definition of $R$]
>3. Let $n \in \mathbb{N}$ be such that $n \neq 1 \land divides(n,1)$. \[Existential instantiation on line 2]
>4. $divides(n,1)$ \[Specialisation on line 3]
>5. $\exists k \in \mathbb{N}\ [k \cdot n = 1]$ \[Definition of $divides$]
>6. Let $m \in \mathbb{N}$ be such that $m \cdot n = 1$. \[Existential instantiation on line 5]
>7. $n \neq 1$ \[Specialisation on line 3]
>8. $n = 0 \lor n > 1$ \[Basic algebra]
>9. Case 1: $n = 0$. Then, $m \cdot n = m \cdot 0 = 0 \neq 1$. \[Basic algebra]
>10. Case 2: $n > 1$. Then, $n \geq 2$, so $m \cdot n \geq 2m \neq 1$. \[Basic algebra]
>11. Either way, $\neg (m \cdot n = 1)$. \[Proof by cases on lines 8, 9, 10]
>12. $(m \cdot n = 1) \land \neg (m \cdot n = 1)$ \[Conjunction on lines 6, 11]
>13. $\bot$. \[Contradiction rule on line 12]
>14. $(1,1) \notin R$. \[Proof by contradiction on line 13]

>[!note] Sub-question 2
>**No**, $R$ is not anti-symmetric. Consider $x = 8 \in \mathbb{N}$ and $y = 10 \in \mathbb{N}$.
>
>**Proof:**
>1. $2 \in \mathbb{N}$. \[Basic algebra]
>2. $2 \cdot 4 = 8 \land 2 \cdot 5 = 10$. \[Basic algebra]
>3. $\big(\exists k \in \mathbb{N}\ [2 \cdot k = 8] \big) \land \big(\exists k \in \mathbb{N}\ [2 \cdot k = 10] \big)$ \[Existential generalisation on lines 1, 2]
>4. $divides(2,8) \land divides(2,10)$ \[Definition of $divides$]
>5. $2 \neq 1$. \[Basic algebra]
>6. $\exists k \in \mathbb{N}\ [k \neq 1 \land divides(k,8) \land divides(k,10)]$ \[Existential generalisation on lines 4, 5]
>7. $(8,10) \in R$. \[Definition of $R$]
>8. $divides(2,10) \land divides(2,8)$ \[Logically equivalent to line 4]
>9. $\exists k \in \mathbb{N}\ [k \neq 1 \land divides(k,10) \land divides(k,8)]$ \[Existential generalisation on lines 5, 8]
>10. $(10,8) \in R$. \[Definition of $R$]
>11. $8 \neq 10$. \[Basic algebra]
>12. $R$ is not anti-symmetric. \[Definition of anti-symmetry]

---

# Question 4: \[6 Marks]

Prove via mathematical induction that for all $n \geq 1$:

$$
\sum_{r = 1}^n \frac{1}{r(r + 1)} = \frac{n}{n + 1}
$$

>[!note] Solution
>**Proof:**
>1. (Base case) Let $n = 1$. Then, $\sum_{r=1}^{1} \frac{1}{r(r+1)} = \frac{1}{1(2)} = \frac{1}{2} = \frac{1}{1+1}$. 
>2. (Inductive step) Assume that for some $n = k$, where $k \geq 1$, we have $\sum_{r=1}^{k} \frac{1}{r(r+1)} = \frac{k}{k+1}$.
>3. $\sum_{r=1}^{k+1} \frac{1}{r(r+1)}$
>4. $= \big(\sum_{r=1}^{k} \frac{1}{r(r+1)}\big) + \frac{1}{(k+1)(k+2)}$
>5. $= \frac{k}{k+1} + \frac{1}{(k+1)(k+2)}$ \[By assumption on line 2]
>6. $= \frac{k(k+2)+1}{(k+1)(k+2)}$
>7. $= \frac{(k+1)^2}{(k+1)(k+2)}$
>8. $= \frac{k+1}{(k+1)+1}$
>9. $\forall n \geq 1\ \big[\sum_{r=1}^{n} \frac{1}{r(r+1)} = \frac{n}{n+1}\big]$ \[Principle of mathematical induction]


