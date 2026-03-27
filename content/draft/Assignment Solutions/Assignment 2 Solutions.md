
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

#### Sub-part 1

Is $R$ reflexive? If so, prove it. If not, give a value $a \in \mathbb{Z}$ such that $(a,a) \notin R$.


>[!note] Solution
>$R$ is **not reflexive**.
>
>Consider $a = 1$. Then, $1 < 0$ but $1 \ngtr 0$, and so $(1, 1) \notin R$.

#### Sub-part 2

Is $R$ transitive? If so, prove it. If not, give values $a, b, c \in \mathbb{Z}$ such that $(a, b) \in R \land (b, c) \in R \land (a, c) \notin R$.


>[!note] Solution
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


---
# Question 3 (6 marks):

Consider a relation $R \subseteq A \times A$, **assume that $R$ is transitive**.
Is it true that $R \subseteq R ; R$? If it is true, prove it. Otherwise, give an example for $R$ for which it is false.

>[!note] Solution
>**False**.
>
>Consider $A = \{1, 2, 3\}$, and let $R = \{(1, 2), (2, 3), (1, 3)\} \in A \times A$. Then, we have $R;R = \{(1, 3)\}$.
>
>However, since $(1, 2) \in R$ but $(1, 2) \notin R;R$, it is not true that $R \subseteq R;R$.

---
# Question 4 (6 marks):

Consider a relation $R \subseteq A \times A$, **assume that $R$ is transitive**.
Is it true that $R ; R \subseteq R$? If it is true, prove it. Otherwise, give an example for $R$ for which it is false. 

>[!note] Solution
>**True**. 
>
>1. Suppose $R \subseteq A \times A$ is transitive. Then, we have:
>
> $$
> \forall a, b, c \in A \ \big[(a,b) \in R \land (b,c) \in R \to (a,c) \in R \big]
> $$
>
>2. We want to show that $\forall (x,y) \in R;R \ [(x,y) \in R]$. \[Definition of subset]
>3. Let $(x,y) \in R;R$ be arbitrarily chosen, where $x,y \in A$.
>4. Then, $\exists z \in A \ \big[(x,z) \in R \land (z,y) \in R \big]$. \[Definition of relation composition]
>5. Let $z' \in A$ be such that $(x,z') \in R \land (z',y) \in R$. \[Existential instantiation on line 4]
>6. Since $x,z',y \in A$, we have the implication $(x,z') \in R \land (z',y) \in R \to (x,y) \in R$. \[Universal instantiation on lines 1, 3, 5]
>7. Hence, $(x,y) \in R$. \[Modus ponens on lines 5 and 6]
>8. $\forall (x,y) \in R;R \ [(x,y) \in R]$. \[Universal generalisation on lines 3 and 7]
>9. Thus, $R;R \subseteq R$.


---
# Question 5 (6 marks):

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


