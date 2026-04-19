
This is the second of two assignments and is worth **15%** of the total grade. The assignment is due **Monday, 13 Apr 2026, 11:59 PM**. Submit your solutions digitally on Canvas, where a submission box will be open under "Assignments > Assignment 2".

There are 5 questions for a total of 30 marks.

_Please make sure your handwriting is legible. You may scan/take a picture of handwritten solutions, you may also type your solutions. We are not particular about the symbol use if you cannot type out the symbols but please make it clear to us what symbol you were intending to use._

# How to submit:
- Submit online on Canvas. There will be a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.

# Collaboration Policy: 
* You may discuss high-level ideas with your classmates or friends. You should list your collaborators if you do so. 
* **Do not share your solutions**.
* ChatGPT (and other LLMs) are **not allowed**. 
* Your submission **must be of your own write-up**.

# Late Policy:
* No late submissions for the assignment allowed.

---
# Question 1 (6 marks):

Given sets $A = \{1, 2, 3, 4, 5\}$, $B = \{ 2, 4, 6, 8 \}$, $C = \{ x \in \mathbb{Z} : \exists k \in \mathbb{Z}[x = 2k] \}$.

Write in **set-roster notation** the following sets:
1. $A \cap B$
2. $A \setminus (B \setminus C)$
3. $A \cap (B \setminus C)$

>[!note] Solutions
>1. $A \cap B = \{2, 4\}$
>2. $A \setminus (B \setminus C) = A \setminus \emptyset = \{1, 2, 3, 4, 5\}$
>3. $A \cap (B \setminus C) = A \cap \emptyset = \emptyset$
---

# Question 2 (6 marks):

For this question, consider the following relation $R \subseteq \mathbb{Z} \times \mathbb{Z}$, where $R = \{(a, b) \in \mathbb{Z} \times \mathbb{Z} : a < 0 \land b > 0 \}$.

#### Sub-part 1

Is $R$ reflexive? If so, prove it. If not, give a value $a \in \mathbb{Z}$ such that $(a,a) \notin R$.

>[!note] Solution
>1. **False**. Consider $(0,0)$.
---

#### Sub-part 2

Is $R$ transitive? If so, prove it. If not, give values $a, b, c \in \mathbb{Z}$ such that $(a, b) \in R \land (b, c) \in R \land (a, c) \notin R$.

>[!note] Solution
> **True**
> 1. Let $a \in \mathbb{Z}$, arbitrarily chosen.
> 2. Let $b \in \mathbb{Z}$, arbitrarily chosen.
> 3. Let $c \in \mathbb{Z}$, arbitrarily chosen.
> 4. Assume $(a, b) \in R \land (b, c) \in R$.
> 	1. $(a, b) \in R$ \[Specialisation on line 4]
> 	2. $(b, c) \in R$ \[Specialisation on line 4]
> 	3. $a < 0 \land b > 0$ \[Definition of $R$]
> 	4. $b < 0 \land c > 0$ \[Definition of $R$]
> 	5. $a < 0$ \[Specialisation on line 4.3]
> 	6. $c > 0$ \[Specialisation on line 4.4]
> 	7. $a < 0 \land c > 0$ \[Conjunction on lines 4.5 and 4.6]
> 	8. $(a, c) \in R$ \[Definition of $R$]
> 5. $\left( (a, b)  \in R \land (b, c) \in R \right) \to (a, c)  \in R$ \[Implication introduction on lines 4 and 4.8]
> 6.  $\forall c \in \mathbb{Z}\left[ \left( (a, b)  \in R \land (b, c) \in R \right) \to (a, c)  \in R\right]$  \[Universal generalisation on lines 3, 5]
> 7. $\forall b \in \mathbb{Z}, \forall c \in \mathbb{Z}\left[ \left( (a, b)  \in R \land (b, c) \in R \right) \to (a, c)  \in R\right]$  \[Universal generalisation on lines 2, 6]
> 8. $\forall b \in \mathbb{Z}, \forall c \in \mathbb{Z}\left[ \left( (a, b)  \in R \land (b, c) \in R \right) \to (a, c)  \in R\right]$  \[Universal generalisation on lines 1, 7]
# Question 3 (6 marks):

Consider a relation $R \subseteq A \times A$, **assume that $R$ is transitive**.
Is it true that $R \subseteq R ; R$? If it is true, prove it. Otherwise, give an example for $R$ for which it is false.

>[!note] Solution
>1. **False**
>2. Consider $A = \{0, 1\}, R = \{(0, 1)\}$, then notice $R$ is transitive.
>3. Then $R ; R = \emptyset$ but $\neg (R \subseteq R ; R)$.
---

---
# Question 4 (6 marks):

Consider a relation $R \subseteq A \times A$, **assume that $R$ is transitive**.
Is it true that $R ; R \subseteq R$? If it is true, prove it. Otherwise, give an example for $R$ for which it is false. 

>[!note] Solution
>**True!**
> 1. Let $(x, z) \in R ; R$, arbitrarily chosen.
> 2. $\exists y \in A[(x, y) \in R \land (y, z) \in R]$ \[Definition of $R;R$]
> 3. Let $m \in A$ be such that  $(x, m) \in R \land (m, z) \in R$ \[Existential instantiation of line 2]
> 4. $(x, m) \in R \land (m ,z) \in R \to (x, z) \in R$ \[Universal generalisation of transitivity of $R$ ]
> 5. $(m, z) \in R$ \[Modus ponens on lines 3 and 4]
> 6. $\forall (x, z) \in R ; R [(m, z) \in R]$ \[Universal generalisation of lines 1 and 5]
> 7. $R ; R \subseteq R$  \[Definition of subset]

---
# Question 5 (6 marks):

Prove via mathematical induction that for all $n \geq 1$:

$$
\sum_{r = 1}^n \frac{1}{r(r + 1)} = \frac{n}{n + 1}
$$

>[!note] Solution
> 1. \[Base Case] Let $n = 1$.
> 	1. $\frac{1}{r(r + 1)} = \frac{1}{1(1 + 1)} = \frac{1}{2} = \frac{1}{1 + 1}$
> 2. \[Inductive Case] Let $k \geq 1$, arbitrarily chosen, and assume that $\sum_{r = 1}^n \frac{1}{r(r + 1)} = \frac{n}{n + 1}$
> 	1.  $\sum_{r = 1}^{n + 1} \frac{1}{r(r + 1)} = \big(\sum_{r = 1}^{n} \frac{1}{r(r + 1)}\big) + \frac{1}{(n+1)(n + 2)}$
> 	2. $\big(\sum_{r = 1}^{n} \frac{1}{r(r + 1)}\big) + \frac{1}{(n+1)(n + 2)} = \frac{n}{n + 1} + \frac{1}{(n+1)(n + 2)}$
> 	3. $\frac{n}{n + 1} + \frac{1}{(n + 1)(n + 2)} = \frac{n(n+2) + (n+1)^2}{(n + 1)(n+2)}$
> 	4. $\frac{n(n+2) + 1}{(n + 1)(n+2)} = \frac{n^2 + 2n + 1}{(n + 1)(n+2)}$
> 	5. $\frac{n^2 + 2n + 1}{(n + 1)(n+2)} = \frac{(n + 1)^2}{(n + 1)(n+2)} = \frac{(n+1)}{(n+2)}$
> 3. By mathematical induction $\forall n \geq 1$ $\sum_{r = 1}^n \frac{1}{r(r + 1)} = \frac{n}{n + 1}$





