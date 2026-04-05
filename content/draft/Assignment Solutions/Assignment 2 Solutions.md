
This is the second of two assignments and is worth **15%** of the total grade. The assignment is due **Monday, 13 Apr 2026, 11:59 PM**. Submit your solutions digitally on Canvas, where a submission box will be open under "Assignments > Assignment 2".

There are 4 questions for a total of 30 marks.

_Please make sure your handwriting is legible. You may scan/take a picture of handwritten solutions, you may also type your solutions. We are not particular about the symbol use if you cannot type out the symbols but please make it clear to us what symbol you were intending to use._

# How to submit:
- Submit online on Canvas. There will be a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
* **Official due date for submission**: **13 Apr 2026, 11:59 PM**

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


>[!note] Solutions
>1. $A \cap B = \{2, 4\}$
>2. $A \setminus (B \setminus C) = A \setminus \emptyset = \{1, 2, 3, 4, 5\}$
>3. $A \cap (B \setminus C) = A \cap \emptyset = \emptyset$


---
# Question 2 (6 marks):

For this question, consider the following relation $R \subseteq \mathbb{Z} \times \mathbb{Z}$:

$$
R = \{(a, b) \in \mathbb{Z} \times \mathbb{Z} : a < 0 \land b > 0 \}
$$

### Sub-part 1 \[2 marks]

Is $R$ reflexive? If so, prove it. If not, give a value $a \in \mathbb{Z}$ such that $(a,a) \notin R$.


>[!note] Solution
>$R$ is **not reflexive**.
>
>Consider $a = 1$. Then, $1 < 0$ but $1 \ngtr 0$, and so $(1, 1) \notin R$.

### Sub-part 2 \[4 marks]

Is $R$ transitive? If so, prove it. If not, give values $a, b, c \in \mathbb{Z}$ such that $(a, b) \in R \land (b, c) \in R \land (a, c) \notin R$.


>[!note] Solution 1
>1. For $R$ to be transitive, we need the following to be true:
>
> $$
> \forall a, b, c \in \mathbb{Z} \ \bigg[\neg \big((a, b) \in R \land (b, c) \in R \big) \lor (a, c) \in R \bigg]
> $$
>
>2. Let $a, b, c \in \mathbb{Z}$ be arbitrarily chosen. We will now show that $\neg \big( (a, b) \in R \land (b, c) \in R \big)$.
>3. Suppose, for the sake of contradiction, that $\neg \bigg( \neg \big( (a, b) \in R \land (b, c) \in R \big) \bigg)$.
>		1. $(a, b) \in R \land (b, c) \in R$ \[Double negation rule on line 3]
>		2. $(a, b) \in R$ \[Specialisation on line 3.1]
>		3. $a < 0 \land b > 0$ \[Definition of $R$]
>		4. $b > 0$ \[Specialisation on line 3.3]
>		5. $(b, c) \in R$ \[Specialisation on line 3.1]
>		6. $b < 0 \land c > 0$ \[Definition of $R$]
>		7. $b < 0$ \[Specialisation on line 3.6]
>		8. $\neg (b > 0)$ \[By basic algebra on line 3.7]
>		9. $(b > 0) \land \neg (b > 0)$ \[Conjunction on lines 3.4 and 3.8]
>		10. $\bot$. \[Contradiction rule on line 3.9]
>		11. $\neg \big( (a, b) \in R \land (b, c) \in R \big)$ \[Proof by contradiction on line 3.10]
>4. $\neg \big((a, b) \in R \land (b, c) \in R \big) \lor (a, c) \in R$ \[Generalisation on line 3.11]
>5. $\forall a, b, c \in \mathbb{Z} \ \bigg[\neg \big((a, b) \in R \land (b, c) \in R \big) \lor (a, c) \in R \bigg]$ \[Universal generalisation on lines 2 and 4]
>6. Hence, $R$ is transitive.

>[!note] Solution 2
>1. For $R$ to be transitive, we need the following to be true:
>
> $$
> \forall a, b, c \in \mathbb{Z} \ \bigg[\neg \big((a, b) \in R \land (b, c) \in R \big) \lor (a, c) \in R \bigg]
> $$
>
>2. We will prove by cases that that is indeed true. Observe that if we pick $a, b, c \in \mathbb{Z}$ where we have $a \leq b \leq c$ (without loss of generality), then there are 4 possible cases (not considering cases where they equal $0$ by the definition of $R$):
>		1. All $a, b, c < 0$
>		2. Only $c > 0$
>		3. Both $b, c > 0$
>		4. All $a, b, c > 0$
>3. Case 1: All $a, b, c < 0$
>		1. Then, we have $a < 0$, $b < 0$ and $c < 0$.
>		2. $\neg (a < 0 \land b > 0)$ \[Basic algebra]
>		3. $\neg ((a, b) \in R)$ \[Definition of $R$]
>		4. $\neg ((a, b) \in R) \lor \neg ((b, c) \in R)$ \[Generalisation on line 3.3]
>		5. $\neg ((a, b) \in R \land (b, c) \in R)$ \[Logically equivalent to line 3.4]
>		6. $\neg ((a, b) \in R \land (b, c) \in R) \lor (a, c) \in R$ \[Generalisation on line 3.5]
>4. Case 2: Only $c > 0$
>		1. Still, we have $\neg (a < 0 \land b > 0)$, and the remaining steps are similar as in Case 1.
>5. Case 3: Both $b, c > 0$
>		1. Now, $\neg (b < 0 \land c > 0)$.
>		2. $\neg ((a, b) \in R) \lor \neg ((b, c) \in R)$ \[Generalisation on line 5.1]
>		3. The remaining steps are similar as in Case 1.
>6. Case 4: All $a, b, c > 0$
>		1. We still have $\neg (a < 0)$, and so $\neg (a < 0 \land b > 0)$.
>		2. The remaining steps are similar as in Case 1.
>7. In all cases, we have $\neg ((a, b) \in R \land (b, c) \in R) \lor (a, c) \in R$. \[Proof by cases on lines 3, 4, 5, 6]
>8. Hence, $R$ is transitive.

---
# Question 3 (12 marks):

Consider the following predicate:

$$
divides(a, b) \equiv \exists k \in \mathbb{N}\ [a \cdot k = b]
$$

We will relate two numbers $x, y \in \mathbb{N}$ in the following way:

$$
R = \bigg\{ (x, y) \in \mathbb{N} 
\times \mathbb{N} : \exists k \in \mathbb{N}\ \big[ k \neq 1 \land divides(k, x) \land divides(k, y) \big] \bigg\}
$$

For example, $(15, 10) \in R$, because both $divides(5, 10)$ and $divides(5, 15)$ are true, and $5 \in \mathbb{N}$. On the other hand, $(2, 3) \notin R$ because no such natural number $k \in \mathbb{N}$ besides $1$ satisfies both $divides(k, 2)$ and $divides(k, 3)$.

### Sub-part 1 \[6 marks]

Is $R$ reflexive? In other words, is it true that:

$$
\forall x \in \mathbb{N}\ \big[ (x, x) \in R \big]
$$

If it is not true, state that it is false, and give an example value $x$ for which $(x, x) \notin R$. If it is true, prove it.


>[!note] Solution
>**No**, $R$ is not reflexive. Consider $x = 1 \in \mathbb{N}$. Now, we prove that $(\textcolor{blue}{1}, \textcolor{red}{1}) \notin R$.
>
>**Proof:**
>1. Suppose, for the sake of contradiction, that $(\textcolor{blue}{1}, \textcolor{red}{1}) \in R$.
>2. $\exists k \in \mathbb{N}\ [k \neq 1 \land divides(k, \textcolor{blue}{1}) \land divides(k, \textcolor{red}{1})]$ \[Definition of $R$]
>3. Let $n \in \mathbb{N}$ be such that $n \neq 1 \land divides(n,1)$. \[Existential instantiation on line 2]
>4. $divides(n,1)$ \[Specialisation on line 3]
>5. $\exists k \in \mathbb{N}\ [k \cdot n = 1]$ \[Definition of $divides$]
>6. Let $m \in \mathbb{N}$ be such that $m \cdot n = 1$. \[Existential instantiation on line 5]
>7. $n \neq 1$ \[Specialisation on line 3]
>8. $n = 0 \lor n > 1$ \[Basic algebra]
>9. Case 1: $n = 0$. Then, $m \cdot n = m \cdot 0 = 0 \neq 1$. \[Basic algebra]
>10. Case 2: $n > 1$. Then, $n \geq 2$, so $m \cdot n \geq 2m \neq 1$. \[Basic algebra]
>11. Either way, $\neg (m \cdot n = 1)$. \[Proof by cases on lines 8, 9, 10]
>12. $(m \cdot n = 1) \land \neg (m \cdot n = 1)$ \[Conjunction on lines 6 and 11]
>13. $\bot$. \[Contradiction rule on line 12]
>14. $(1,1) \notin R$. \[Proof by contradiction on line 13]

### Sub-part 2 \[6 marks]

Is $R$ anti-symmetric? In other words, is it true that:

$$
\forall x \in \mathbb{N}, \forall y \in \mathbb{N}\ \big[ (x, y) \in R \land (y, x) \in R \to x = y \big]
$$

If it is not true, state that it is false, and give an example values $x, y$ for which $(x, y) \in R$ and $(y, x) \in R$, but $x \neq y$. If it is true, prove it.


>[!note] Solution
>**No**, $R$ is not anti-symmetric. Consider $x = 8 \in \mathbb{N}$ and $y = 10 \in \mathbb{N}$.
>
>**Proof:**
>1. $2, 4, 5 \in \mathbb{N}$. \[Basic algebra]
>2. $(2 \cdot 4 = 8) \land (2 \cdot 5 = 10)$ \[Basic algebra]
>3. $\big(\exists k \in \mathbb{N}\ [2 \cdot k = 8] \big) \land \big(\exists k \in \mathbb{N}\ [2 \cdot k = 10] \big)$ \[Existential generalisation on lines 1 and 2]
>4. $divides(2,8) \land divides(2,10)$ \[Definition of $divides$]
>5. $2 \neq 1$. \[Basic algebra]
>6. $\exists k \in \mathbb{N}\ [k \neq 1 \land divides(k,8) \land divides(k,10)]$ \[Existential generalisation on lines 4 and 5]
>7. $(8,10) \in R$. \[Definition of $R$]
>8. $divides(2,10) \land divides(2,8)$ \[Logically equivalent to line 4]
>9. $\exists k \in \mathbb{N}\ [k \neq 1 \land divides(k,10) \land divides(k,8)]$ \[Existential generalisation on lines 5 and 8]
>10. $(10,8) \in R$. \[Definition of $R$]
>11. $8 \neq 10$. \[Basic algebra]
>12. $R$ is not anti-symmetric. \[Definition of anti-symmetry, from lines 7, 10, 11]


---
# Question 4 (6 marks):

Prove via mathematical induction that for all $n \geq 1$:

$$
\sum_{r = 1}^n \frac{1}{r(r + 1)} = \frac{n}{n + 1}
$$

>[!note] Solution
>**Proof:**
>1. (Base case) Let $n = 1$. Then, $\sum_{r=1}^{1} \frac{1}{r(r+1)} = \frac{1}{1(2)} = \frac{1}{2} = \frac{1}{1+1}$. 
>2. (Inductive step) Assume that for some $n = k$, where $k \geq 1$, we have $\textcolor{green}{\sum_{r=1}^{k} \frac{1}{r(r+1)} = \frac{k}{k+1}}$.
>3. $\textcolor{blue}{\sum_{r=1}^{k+1} \frac{1}{r(r+1)}}$
>4. $= \big(\textcolor{green}{\sum_{r=1}^{k} \frac{1}{r(r+1)}}\big) + \frac{1}{(k+1)(k+2)}$
>5. $= \textcolor{green}{\frac{k}{k+1}} + \frac{1}{(k+1)(k+2)}$ \[By assumption on line 2]
>6. $= \frac{k(k+2)+1}{(k+1)(k+2)}$
>7. $= \frac{(k+1)^2}{(k+1)(k+2)}$
>8. $= \textcolor{red}{\frac{k+1}{(k+1)+1}}$
>9. $\forall n \geq 1\ \big[\sum_{r=1}^{n} \frac{1}{r(r+1)} = \frac{n}{n+1}\big]$ \[Principle of mathematical induction]


