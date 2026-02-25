
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
# Question 1 \[Graded for Participation]:

Using mathematical induction, prove that:

$$
\forall n \geq 1 \left[ \sum_{i = 1}^n i^2 =\frac{n(n+1)(2n+1)}{6} \right]
$$

**Solution**:

>[!note] Proof
>1. (Base case) Let $n = 1$. Then $\sum_{i = 1}^1 i^2 =\frac{1(1+1)(2(1)+1)}{6} = 1$. \[Basic algebra]
>2. (Inductive step) Assume that for some $n = j$, where $j\in \mathbb{N}$, we have that $$\textcolor{green}{\sum_{i = 1}^j i^2 = \frac{j(j + 1)(2j + 1)}{6}}$$
>3. Then, by basic algebra, we have the following equalities:
> $$
> \begin{align*}
> \\& \textcolor{blue}{\sum_{i = 1}^{j + 1} i^2}
> \\& = \textcolor{green}{\sum_{i = 1}^{j} i^2} + (j+1)^2
> \\& = \textcolor{green}{\frac{j(j+1)(2j+1)}{6}} + (j+1)^2 \ \text{[By assumption on line 2]}
> \\& = (j+1)\left[\frac{j(2j+1)}{6} + (j+1)\right] \ \text{[Factorising out } (j+1) \text{]}
> \\& = (j+1)\left[\frac{2j^2+j+6j+6}{6}\right]
> \\& = (j+1)\left[\frac{2j^2+7j+6}{6}\right]
> \\& = (j+1)\left[\frac{(j+2)(2j+3)}{6}\right]
> \\& = \textcolor{red}{\frac{(j+1)[(j+1)+1][2(j+1)+1]}{6}}
> \\&
> \end{align*}
> $$
>4. $\forall n \in \mathbb{N}\ \left[\sum_{i=1}^{n} i^2 = \frac{(n)(n+1)(2n+1)}{6}\right]$. \[Principle of mathematical induction]


---
# Question 2:

Using mathematical induction, prove that:

$$
\forall n \geq 1, \exists k \in \mathbb{N} \left[ 6^n - 1 = 5\cdot k \right]
$$

**Solution**:

>[!note] Proof
>1. (Base case) Let $n = 1$. Then $6^n - 1 = 6^1 - 1 = 5 = 5 \cdot 1$. \[Basic algebra]
>2. Since $1 \in \mathbb{N}$, $\exists k \in \mathbb{N}\ [6^n - 1 = 5 \cdot k]$. \[Existential generalisation on line 1]<br></br>
>3. (Inductive step) Assume that for some $n = j$, where $j \in \mathbb{N}$, we have that
>  $$
> \textcolor{green}{\exists k \in \mathbb{N}\ [6^j - 1 = 5 \cdot k]}
> $$
>4. Let $m \in \mathbb{N}$ be such that $\textcolor{green}{6^j - 1 = 5m}$. \[Existential instantiation on line 3]
>5. By basic algebra, we have the following equalities:
> $$
> \begin{align*}
> \\& \textcolor{blue}{6^{j+1} - 1}
> \\& = 6 \cdot 6^j - 1
> \\& = 6 \cdot 6^j - 6 \cdot 1 + 5
> \\& = 6 \cdot \textcolor{green}{(6^j - 1)} + 5
> \\& = 6 \cdot \textcolor{green}{5m} + 5 \ \text{[By assumption on lines 3 and 4]}
> \\& = 30m + 5
> \\& = \textcolor{red}{5 \cdot (6m + 1)}
> \\&
> \end{align*}
> $$
>6. Since $m \in \mathbb{N}$, $6m + 1 \in \mathbb{N}$. \[Basic algebra]
>7. $\textcolor{red}{\exists k \in \mathbb{N} \left[6^{j+1} - 1 = 5 \cdot k \right]}$. \[Existential generalisation on lines 5 and 6]<br></br>
>8. $\forall n \geq 1, \exists k \in \mathbb{N} \left[6^n - 1 = 5 \cdot k \right]$. \[Principle of mathematical induction]


---
# Question 3 \[Graded for Participation]:

Let $A(n)$ be a recurrence defined in the following way:

$$
A(n) = \begin{cases}
1, & n = 0\\
3, & n = 1\\
2\times A(n - 1) - A(n - 2), & n \geq 2
\end{cases}
$$

#### Sub-part 1

Compute the following values:

1. $A(0)$
2. $A(1)$
3. $A(2)$
4. $A(5)$

**Solution**:

>[!info] Sub-part 1
> $A(0) = \textcolor{blue}{1}$
>
> $A(1) = \textcolor{blue}{3}$
>
> $A(2) = 2 \times A(1) - A(0) = 2 \times 3 - 1 = \textcolor{blue}{5}$
>
> To calculate $A(5)$, we first calculate $A(3)$ and $A(4)$ (bottom-up):
> $$
> A(3) = 2 \times A(2) - A(1) = 2 \times 5 - 3 = 7
> $$
> 
> $$
> A(4) = 2 \times A(3) - A(2) = 2 \times 7 - 5 = 9
> $$
> 
> Finally, we have $A(5) = 2 \times A(4) - A(3) = 2 \times 9 - 7 = \textcolor{blue}{11}$.

#### Sub-part 2

Prove via strong induction that $\forall n\geq 0\ [A(n) = 2n + 1]$.

**Solution**:

>[!note] Proof
>1. (Base cases) We prove the statement for $n = 0$ and $n = 1$. Clearly, $A(0) = 1 = 2(0) + 1$ and $A(1) = 3 = 2(1) + 1$.<br></br>
>2. (Inductive step) Let $k \geq 2$, and assume that $\textcolor{green}{\forall 0 \leq \textcolor{magenta}{j} < k\ [A(\textcolor{magenta}{j}) = 2\textcolor{magenta}{j} + 1]}$.
>3. $\textcolor{blue}{A(k)} = 2 \times \textcolor{green}{A(\textcolor{magenta}{k-1})} - \textcolor{green}{A(\textcolor{magenta}{k-2})}$ \[By definition of $A(n)$]
>4. Since $0 \leq \textcolor{magenta}{k-1} < k$ and $0 \leq \textcolor{magenta}{k-2} < k$, by our assumption on line 2, we have:
>	$$
>		\textcolor{green}{A(\textcolor{magenta}{k-1}) = 2(\textcolor{magenta}{k-1})+1 = 2k-1}
>	 $$
>	$$
>		\textcolor{green}{A(\textcolor{magenta}{k-2}) = 2(\textcolor{magenta}{k-2})+1 = 2k-3}
>	 $$
>5. $\textcolor{blue}{A(k)} = 2 \times \textcolor{green}{(2k-1)} - \textcolor{green}{(2k-3)} = 4k-2-2k+3 = \textcolor{red}{2k+1}$ \[Basic algebra, from lines 3 and 4]<br></br>
>6. $\forall n \geq 0 \ [A(n) = 2n + 1]$. \[Principle of mathematical induction]


---
# Question 4:

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
\forall n \geq 3 \ \big[M(n) \leq n\log_2 n \big]
$$

You may find the following facts useful:
1. $\lfloor \frac{n}{2} \rfloor \leq \frac{n}{2}$
2. $a \leq b \to \log_2(a) \leq \log_2(b)$

You may alternatively use the substitution method to prove that this is $O(n \log n)$.

**Solution**:

>[!note] Proof
>1. (Base cases) We will prove the statement for $n=3$, $n=4$ and $n=5$.
>	- For $n=3$: $M(3) = 2 \times M(1) + 3 = 2 \times 0 + 3 = 3 \leq 3 \log_2 3$
>	- For $n=4$: $M(4) = 2 \times M(2) + 4 = 2 \times 2 + 4 = 8 \leq 4 \log_2 4$
>	- For $n=5$: $M(5) = 2 \times M(2) + 5 = 2 \times 2 + 5 = 9 \leq 5 \log_2 5$<br></br>
>2. (Inductive step) Let $k \geq 6$, and assume that $\textcolor{green}{\forall 3 \leq \textcolor{magenta}{j} < k \ \big[M(\textcolor{magenta}{j}) \leq \textcolor{magenta}{j} \log_2 \textcolor{magenta}{j} \big]}$.
>3. Since $k \geq 6$, $\textcolor{magenta}{\big\lfloor \frac{k}{2} \big\rfloor} \geq 3$, so our assumption applies to $\textcolor{magenta}{\big\lfloor \frac{k}{2} \big\rfloor}$.
>4. Then, we have the following:
> $$
> \begin{align*}
> \\& \textcolor{blue}{M(k)}
> \\& = 2 \times \textcolor{green}{M\bigg(\textcolor{magenta}{\bigg\lfloor \frac{k}{2} \bigg\rfloor} \bigg)} + k
> \\& \leq 2 \textcolor{green}{\bigg(\textcolor{magenta}{\bigg\lfloor \frac{k}{2} \bigg\rfloor} \log_2 \textcolor{magenta}{\bigg\lfloor \frac{k}{2} \bigg\rfloor} \bigg)} + k
> \\& = 2 \bigg\lfloor \frac{k}{2} \bigg\rfloor \log_2 \bigg\lfloor \frac{k}{2} \bigg\rfloor + k
> \\& \leq 2 \bigg(\frac{k}{2} \bigg)\log_2 \bigg(\frac{k}{2} \bigg) + k
> \\& = k\log_2 \bigg(\frac{k}{2} \bigg) + k
> \\& = k \log_2 k - k \log_2 2 + k
> \\& = k \log_2 k - k + k
> \\& = \textcolor{red}{k \log_2 k}
> \end{align*}	
> $$
>5. $M(k) \leq k \log_2 k$. \[From lines 4 and 6]<br></br>
>6. $\forall n \geq 3\ [M(n) \leq n \log_2(n)]$. \[Principle of mathematical induction]


---
# Question 5:

Let $B(n)$ be a recurrence defined in the following way.

$$
B(n) = \begin{cases}
1, & n = 0\\
3\times B(n - 1), & n \geq 1
\end{cases}
$$

Prove by induction that:
$$
\forall n \in \mathbb{N}\ [B(n) = 3^n]
$$

**Solution**:

>[!note] Proof
>1. (Base case) Let $n=0$. Then, $B(0) = 1 = 3^0$.
>2. (Inductive step) Assume that for some $n = j$, where $j \in \mathbb{N}$, $\textcolor{green}{B(j) = 3^j}$.
>3. $\textcolor{blue}{B(j+1)} = 3 \times \textcolor{green}{B(n)} = 3 \times \textcolor{green}{3^j} = \textcolor{red}{3^{j+1}}$. \[By assumption on line 2]
>4. $\forall n \in \mathbb{N}\ [B(n) = 3^n]$. \[Principle of mathematical induction]


---
# Question 6 \[Graded for Participation]:

Let $B(n)$ be a recurrence defined in the following way:

$$
B(n) = \begin{cases}
1, & n = 0\\
3\times B(n - 1), & n \geq 1
\end{cases}
$$

#### Sub-part 1

True or false? $B(n) \in O(3^n)$

\[Hint: You may want to use the statement at the end of question 4.]

If it is true, explicitly give values $n_0$ and $c$ to justify that $B(n)$ is indeed in $O(3^n)$.

**Solution**:

**True.** From Q5, we have that $B(n) = 3^n$.

>[!note] Proof
>1. Let $n_0 = 1 \in \mathbb{N}$ and $c = 1 \in \mathbb{R^+}$.
>2. Then, $B(n) = 3^n \leq c \cdot 3^n$, for all $n \geq n_0$. \[Basic algebra]
>3. $\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0\ [B(n) \leq c \cdot 3^n]$. \[Existential generalisation on line 1]
>4. $B(n) \in O(3^n)$. \[Definition of $O$]

#### Sub-part 2

True or false? $B(n) \in \Omega(3^n)$

\[Hint: You may want to use the statement at the end of question 4.]

If it is true, explicitly give values $n_0$ and $c$ to justify that $B(n)$ is indeed in $\Omega(3^n)$.

**Solution**:

**True**. 

>[!note] Proof
>1. Let $n_0 = 1 \in \mathbb{N}$ and $c = 1 \in \mathbb{R^+}$.
>2. Then, $B(n) = 3^n \geq c \cdot 3^n$, for all $n \geq n_0$. \[Basic algebra]
>3. $\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0\ [B(n) \geq c \cdot 3^n]$. \[Existential generalisation on line 1]
>4. $B(n) \in \Omega(3^n)$. \[Definition of $\Omega$]

#### Sub-part 3

True or false? $B(n) \in \Theta(3^n)$

Why/why not? You do not have to give a proof.

\[Hint: What is the definition of $\Theta$?]

**Solution**:

**True**. Since $B(n) \in O(3^n) \land B(n) \in \Omega(3^n)$, we have that $B(n) \in O(3^n) \cap \Omega(3^n)$, which means that $B(n) \in \Theta(3^n)$.

---
# Question 7:

Let $f(n), g(n)$ be functions such that $\forall n \in \mathbb{N} \ [f(n) \geq 0]$ and $\forall n \in \mathbb{N} \ [g(n) \geq 0]$ (i.e., the functions are always non-negative).

Prove that:

$$
\max(f(n), g(n)) \in O(f(n) + g(n))
$$

**Solution**:

We refer to the following definition:

$$
\max(a,b) = \begin{cases}
a, & a \geq b\\
b, & b > a
\end{cases}
$$

>[!note] Proof
>1. Let $f(n)$ and $g(n)$ be arbitrarily chosen functions.
>2. Observe that $\max(f(n),g(n)) \leq f(n) + g(n)$ since both functions are always non-negative. \[Basic algebra]
>3. Then, $\max(f(n),g(n)) \leq f(n)+g(n) = 1 \cdot (f(n)+g(n))$, for all $n \geq 0$. \[Basic algebra]
>4. Letting $n_0=0 \in \mathbb{N}$, $c=1 \in \mathbb{R^+}$, we see that $\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0 \ \left[\max\left(f(n),g(n)\right) \leq c \cdot (f(n)+g(n))\right]$. \[Existential generalisation on line 3]
>5. $\max(f(n),g(n)) \in O(f(n)+g(n))$. \[Definition of $O$]

---
# Question 8 (Challenging!):

Prove that:

$$
2^{2n} \notin O(2^n)
$$

\[Hint: Assume that $2^{2n} \in O(2^n)$. What kind of contradiction will you derive?]

>[!note] Proof
>1. Assume for the sake of contradiction that $2^{2n} \in O(2^n)$.
>2. $\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0 \ [2^{2n} \leq c \cdot 2^n]$ \[Unpacking definition of O]
>3. Let $m \in \mathbb{N}, k \in \mathbb{R^+}$ such that $\forall n \geq m\ [2^{2n} \leq k \cdot 2^n]$ \[Existential instantiation on line 2]
>4. $\forall n \geq m\ \big[\frac{2^{2n}}{2^n} \leq k\big]$ \[Basic algebra]
>5. $\forall n \geq m\ [2^n \leq k]$ \[Basic algebra]
>6. As $n$ approaches infinity, $2^n > k$. \[Basic algebra; see below for a more rigorous proof]
>7. $\therefore \exists n \geq m\ [2^n > k]$ \[Existential generalization on line 6]
>8. $\neg (\forall n \geq m\ [2^n \leq k])$  \[Logically equivalent to line 7]
>9. $\neg (\forall n \geq m\ [2^n \leq k]) \land (\forall n \geq m\ [2^n \leq k])$ \[Conjunction on lines 5 and 8]
>10. $\therefore \bot$ \[Contradiction rule on line 9]
>11. $\therefore 2^{2n} \notin O(2^n)$ \[Proof by contradiction on line 10]

To prove the idea that one can always find a value of $n$ such that $2^n > k$, we can do the following:

**Sub-Proof**:
1. Consider $n = \max(1 + \log_2 k, m)$.
2. Then, $n > \log_2 k$. \[Basic algebra]
3. $2^n > 2^{\log_2 k} = k$. \[Basic algebra]
4. Also, $n \geq m$. \[Basic algebra, from line 2]
5. $\exists n \geq m\ [2^n > k]$. \[Existential generalisation on line 3, 4]
