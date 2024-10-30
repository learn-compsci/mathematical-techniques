---
title: CS1231S Tutorial 7 Solutions
hidden: true
---
This page has solutions for selected questions from [this tutorial sheet](https://www.comp.nus.edu.sg/~cs1231s/tut/24s1/tut07qns.pdf).

This tutorial is on mathematical induction. Please do not use these as lecture notes. You should make an earnest attempt and pretty much solve the tutorial questions before referring to the solutions. This means I will say "you should already know this/you should already know that" without much explanation on what exactly it is in detail.

## Question 2

Let's do the proof first, and we'll mention certain noteworthy features of the proof as we go along. 

Proof by induction:
1. Let $P(n) \equiv \sum_{i = 1}^n i^2 = \frac{1}{6}n (n + 1)(2n+1)$.
2. [Base case] Consider the case when $n = 1$:
	1. $\sum_{i = 1}^1 i^2 = 1^2 = 1 = \frac{1}{6}(1)(1 + 1)(2(1) + 1)$ [Basic Algebra]
	2. Therefore, $P(1)$ is true.
3. [Inductive step] Let $k \in \mathbb{Z}^+$, arbitrarily chosen. Furthermore, assume $P(k)$.
	1. $\sum_{i = 1}^{k + 1} i^2 = {\color{blue}{\left(\sum_{i = 1}^{k} i^2\right)}} + (k+1)^2$
	2. $= {\color{blue} \left(\frac{1}{6}(k)(k + 1)(2k+1) \right)} + (k+1)^2$ \[By assumption $P(k)$\]
	3. $=(k+1)(\frac{1}{6})( 2k^2 + k + 6k + 6 )$
	4. $=(k+1)\left(\frac{1}{6}\right)(2k + 3)(k + 2)$
	5. $=(k+1)\left(\frac{1}{6}\right)(2(k+1) + 1)((k + 1) + 1)$
	6. Therefore, $P(k+1)$ is true.
4. Therefore, for all $k \in \mathbb{Z}^+$, $[P(k) \to P(k+1)]$. \[Universal Generalisation]
5. By lines 2.2 and 4, we conclude that $\forall n \in \mathbb{Z}^+[P(n)]$.

> [!Remarks]
> So this is the usual form of induction. Again we have the 3 usual parts to it: (1) Defining the predicate $P(n)$ that is the statement we wish to prove. (2) Solving it for the base case, here that happens to be $1$, since that's the smallest value. (3) Solving it for the inductive case.
> 
> Note here that lines 2.1 and 2.2 serve to show $P(1)$.
> 
> Furthermore, lines 3, 3.1 to 3.6 allow use to conclude $k \in \mathbb{Z}^+$, $[P(k) \to P(k+1)]$.
> 
> You then take **both** those statements to conclude by induction that $\forall n \in \mathbb{Z}^+[P(n)]$. This is done on line 5.
> 
> The other thing I need you to notice is that on line 3.1, we take that blue portion and swap it out. That is exactly where we are using assumption $P(k)$. Note, $P(k)$ only says $\sum_{i=1}^k i^2 = \left(\frac{1}{6}\right)(k)(k+1)(2k+1)$. It says **nothing** about other summations. It does not say $P(k-2)$ is true, it does not say $P(k+1)$ is true. Every other line in the subproof from line 3 is by basic algebra.

> [!Warning]
> It's very common for students to say things like $P(n) = \frac{1}{6}(n)(n+1)(2n+1)$ and the likes. **This is not syntactic.** $P(n)$ is a predicate that says something about the equality between $P(n) = \frac{1}{6}(n)(n+1)(2n+1)$ and $\sum_{i=1}^n i^2$. In that sense, it can only be true or false, and the the truth value depends on what is the value of $n$ given. It turns out as long as you give it any $n \in \mathbb{Z}^+$, it evaluates to true.



## Question 3

Proof by induction.
1. Let $x \in \mathbb{R}_{\geq -1}$, arbitrarily chosen.
2. Define $P(n) \equiv (1+nx)\leq (1+x)^n$.
3. [Base Case] Consider $n = 1$.
	1. Then $1 + (1)x \leq (1 + x)^{(1)}$.
	2. Therefore $P(1)$ holds true.
4. [Inductive Step] Let $k \in \mathbb{Z}^+$ such that $P(k)$ is true.
	1. $(1+x)^{k + 1} = {\color{blue}(1+x)^k} (1+x)$
	2. $\geq {\color{blue}(1+kx)}(1+x)$ \[By assumption $P(k)$]
	3. $= 1 + (k+1)x + kx^2$
	4. $\geq 1 + (k + 1)x$ \[Since $k \geq 1$, $x^2 \geq 0$, so $kx^2 \geq 0$]
	5. Therefore $P(k+1)$ is true.
6. Therefore, $\forall k \in \mathbb{Z}^+[P(k) \to P(k+1)]$ \[Universal Generalisation]
7. Therefore, by lines 3.3, and 6, $\forall k \in \mathbb{Z}^+[P(k)]$

> [!Remarks]
> Again, I want you to pay attention to the blue portions in the subproof for 4. The substitution that we did there from 4.1 to 4.2 uses precisely the assumption $P(k)$. We aren't using $P(k+1)$ in this proof anywhere.

## Question 4

When looking at a proof question like this, sometimes I like to get a few facts out of the way in order to have a leaner proof later on. For example, there's a notion of division here. It might be handy to define it in first order logic so that we can make use of "division".

We note that $a \mid b \iff \exists t \in \mathbb{Z}[at = b]$. (Refer to [Slide 23, Lecture 4, CS1231S](https://www.comp.nus.edu.sg/~cs1231s/lect/24s1/Lecture04_Methods_of_Proof_full.pdf))
We note that integer $a\text{ is odd} \iff \exists t \in \mathbb{Z}[a = 2t + 1]$. (Refer to [Slide 23, Lecture 4, CS1231S](https://www.comp.nus.edu.sg/~cs1231s/lect/24s1/Lecture04_Methods_of_Proof_full.pdf))

Proof by induction:
1. Let $a \in \mathbb{Z}$ be odd.
2. Let $P(n) \equiv 2^{n+2} \mid (a^{2^{n}} - 1)$.
3. [Base Case] Consider $n = 1$.
	1. $a^{2^{1}} = a^2-1$ \[BBA]
	2. $a^2 = (a - 1)(a+1)$ \[BBA]
	3. $a$ is odd. Therefore $\exists t' \in \mathbb{Z}[a = 2t' + 1]$. Let $t \in \mathbb{Z}$ be such that $a = 2t + 1$. \[Existential Instantiation]
	4. $(a - 1)(a+1) = (2t)(2t+2)$ \[BBA]
	5. $(2t)(2t+2) = 4(t)(t+1)$ \[BBA]
	6. $\exists z' \in \mathbb{Z}[(t)(t+1) = 2z']$ \[Product of 2 consecutive integers is even.]. Let $z \in \mathbb{Z}$ such that $2z = (t)(t+1)$.
	7. $4(t)(t+1) = 8z$, where $z \in \mathbb{Z}$. \[Choice of $z$]
	8. Therefore $\exists z' \in \mathbb{Z} [a^{2^{1}} = 8z']$ \[Existential Generalisation]
	9. Therefore $2^{2 + 1} \mid a^{2^1} - 1$.  \[Definition of divisibility]
	10. Therefore $P(1)$ holds true.
4. [Inductive Case] Let $k \in \mathbb{Z}$, arbitrarily chosen. Assume $P(k)$.
	1. $a^{2^{k + 1}} - 1= a^{2\cdot 2^k} - 1$ \[BBA]
	2. $a^{2\cdot 2^k} - 1 = (a^{2^k})^2 - 1$ \[BBA]
	3. $(a^{2^k})^2 - 1 = {\color{blue}(a^{2^k} - 1)}(a^{2^k} + 1)$ \[BBA]
	4. $\exists t' \in \mathbb{Z}[a^{2^k} - 1 = 2^{k+2} \cdot t']$. Let $t \in \mathbb{Z}$, be such a number. \[Assumption $P(k)$, Existential Generalisation]
	5. ${\color{blue}(a^{2^k} - 1)}(a^{2^k} + 1) = {\color{blue}2^{k+2} t} (a^{2^k} + 1)$ \[Choice of $t$ on line 4]
	6. ${\color{blue}2^{k+2} t} (a^{2^k} + 1) = 2^{k+2} t ( {\color{blue} a^{2^k} - 1} + 2)$ \[BBA]
	7. $2^{k+2} t ({\color{blue} a^{2^k} - 1} + 2) = 2^{k+2} t ({\color{blue} 2^{k+2}t} + 2)$ \[Choice of $t$ on line 4]
	8. $2^{k+2} t (2^{k+2}t + 2) = 2^{k+3}t(2^{k+1}t + 1)$ \[BBA]
	9. $\exists m \in \mathbb{Z} [a^{2^{k+1}} = 2^{k+3}m]$ \[Existential Generalisation]
	10. Therefore $P(k+1)$ is true.
5. Therefore $\forall n \in \mathbb{Z}^+[P(n) \to P(n+1)]$ \[Universal Generalisation]
6. By lines 1.10 and 5, we conclude that $\forall n \in \mathbb{Z}^+[P(n)]$.

>[!Other Questions]
> **Question:** Let's go back to line 4.5. When we have $2^{k+2} t (a^{2^k} + 1)$, can we just argue $a^{2^k}$ is odd, so $(a^{2^k} + 1)$ is even. So $(a^{2^k} + 1) = 2z$ for some $z \in \mathbb{Z}$, then say $2^{k+2} t (a^{2^k} + 1) = 8z$?
> **Answer:** Yes. Just be sure you have a justification for it. I.e. you also need to prove the following statement: $\forall k' \in \mathbb{Z}^+ [a^{2^{k}} \text{ is odd}]$. You can do that either on the side first then use that as a lemma, or do it within the same proof itself. I'd suggest the former.
> In fact, proving it might be a good mini-exercise. Make sure every step is justified. 
## Question 5
> [!Remarks]
> A few things to note for this question. Our base case now starts at 8 instead. Also, for this proof, I'm going to show you how to do it via strong induction. Now because of that, let me show you a diagram of what the strategy is going to be:
> 
> ![[strong-induction-question-5|center]]
> 
> What we want to do, is take a number $k$, and say that since $k - 3$ can be written as $k - 3 = 3x + 5y$, then $k = 3(x + 1) + 5y$. Since we're starting at $8$, and we want to subtract by $3$, the very first value that can start using our base cases is actually $11$. This means we cannot handle $n = 9$ nor $n = 10$ in our inductive case. So they should be manually proven in our base cases.

Proof by induction:
1. Let $P(n) \equiv \exists x, y \in \mathbb{N}[n = 3x + 5y]$.
2. [Base cases]
	1. Consider $n = 8$. $8 = 3(1) + 5(1)$.
	2. Therefore $\exists x, y \in \mathbb{N}[8 = 3x + 5y]$. \[Existential Generalisation]
	3. Consider $n = 9$. $9 = 3(3) + 5(0)$.
	4. Therefore $\exists x, y \in \mathbb{N}[9 = 3x + 5y]$. \[Existential Generalisation]
	5. 1. Consider $n = 10$. $10 = 3(0) + 5(2)$.
	6. Therefore $\exists x, y \in \mathbb{N}[10 = 3x + 5y]$. \[Existential Generalisation]
3. [Inductive Step]
	1. Let $k \in \mathbb{Z}_{\geq 8}$, arbitrarily chosen. Assume $P(k)$ is true.
	2. Consider $k + 3$. Note: $P(k)$ holds true. \[By assumptions on line 1]
	3. Therefore $\exists x', y' \in \mathbb{N}[k = 3x' + 5y']$. \[Definition of $P(k-2)$]
	4. Let $x, y \in \mathbb{N}$ such that they satisfy $k = 3x + 5y$. \[Existential Instantiation]
	5. Then $k + 3 = 3x + 5y + 3 = 3(x+1) + 5y$ \[BBA, choice of $x, y$] 
	6. Since $x \in \mathbb{N}, x+1 \in \mathbb{N}$. \[Choice of $x$, closure of $+$ on $\mathbb{N}$]
	7. Therefore $\exists x', y' \in \mathbb{N}[k + 3 = 3x' + 5y']$ \[Existential Generalisation]
	8. Therefore $P(k+1)$ holds true. \[Definition of $P(k+1)$]
4. Therefore, $\forall n \in \mathbb{Z}_{\geq 8}[P(k) \to P(k+3)]$ \[Universal Generalisation]
5. By strong induction, $\forall n \in \mathbb{Z}_{\geq 8}[P(n)]$.

To be clear, we're using the argument of the form:

$$
\begin{align}
&P(8)\\
&P(9)\\
&P(10)\\
&\forall k \geq 8 [P(k) \to P(k + 3)]\\
\hline
\therefore &\forall k \geq 8 [P(k)]
\end{align}
$$
And this is valid. (There's a typo but you can try referring to [Page 44, slides for Lecture 8](https://www.comp.nus.edu.sg/~cs1231s/lect/24s1/Lecture08_Mathematical_Induction_full.pdf) to see what I mean. The bottom-most green box.)

# Question 6
This question is basically asking you to prove that we can write a number in base 2. Why? Because any number $n$ can be written as a sum of distinct powers of two, the distinct powers of two tell us which digits of $n$ should be $0$ or $1$.

**Example 1:** $5 = 2^2 + 2^0 = 101_2$, where $101_2$ is $5$ written out in base 2.
**Example 2:** $19 = 16 + 2 + 1 = 2^4 + 2^1 + 2^0 = 1011_2$, where $1011_2$ is $16$ written out in base 2.

Formally reading the statement: 

$$
\forall n \in \mathbb{Z}^+~\exists \ell \in \mathbb{Z}^+~ i_1, i_2, \ldots, i_\ell \in \mathbb{N} \left( i_1 < i_2 < \dots < i_\ell \land n = \sum_{t = 1}^\ell 2^{i_t} \right)
$$


1. Let $P(n) \equiv \exists \ell \in \mathbb{Z}^+~ i_1, i_2, \ldots, i_\ell \in \mathbb{N} \left( i_1 < i_2 < \dots < i_\ell \land n = \sum_{t = 1}^\ell 2^{i_t} \right)$
2. \[Base Case] $n = 1$:
	1. $1 = 2^0$.
	2. Consider $\ell = 1$, $i_1 = 0$. Now $\ell \in \mathbb{Z}^+$, $i_1 \in \mathbb{N}$.
	3. Also $1 = \sum_{t = 1}^\ell 2^{i_t}$.
	4. Therefore $P(1)$ holds.
3. \[Inductive Case] Let $k \in \mathbb{Z}^+$ be arbitrarily chosen. For $i \in \mathbb{Z}^+$ such that $1 \leq i < k$, assume $P(i)$ is true.
	1. Consider $k$. $k$ is even or odd.
		1. Assume $k$ is even. Thus, $\exists m \in \mathbb{N} [k = 2m]$. \[Definition of even]
		2. Then since $m < k$, $P(m)$ holds. \[By assumption on line 3]
		3. Therefore exists $s \in \mathbb{Z}^+, j_1, j_2, \ldots, j_s \in \mathbb{N}$ where $\left( j_1 < j_2 < \dots < j_\ell \land n = \sum_{t = 1}^s 2^{j_t} \right)$.







