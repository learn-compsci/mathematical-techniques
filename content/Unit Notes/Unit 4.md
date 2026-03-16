---
title: "Unit 4: Induction, Recurrences"
---
# Overview

In this unit, we will be introducing two seemingly separate topics that actually have a deep connection:

- [[#Part 1 Mathematical Induction|Mathematical induction]]
- [[#Part 2 Recurrences|Recurrences]]

Both of these are vital tools in computer science, and we will see some examples that demonstrate this idea. We will also be using these ideas directly in the next unit.

---
# Part 1: Mathematical Induction

To start off, let's talk about the induction proof technique. This is the last main proof technique that we had left out from [[Unit 1]] because it really deserves that much attention. This is one of the most handy tools that we use in order to prove statements we care about, and in this section we will present two variants of this technique:

1. [[#Revisiting An Example The Arithmetic Series|(Normal/Weak) mathematical induction]]
2. [[#Proof By Strong Induction Template|Strong mathematical induction]]

## Revisiting An Example: The Arithmetic Series

To show you what I mean, let's revisit an example that I had mentioned when introducing and motivating proofs in the first place: 

> Can we show that $\forall n \in \mathbb{N}$ $\left[\sum_{i = 1}^n i = \frac{n(n + 1)}{2}\right]$?

(Recall that $\sum_{i = 1}^n i = 1 + 2 + \cdots + n$.)

You might notice that based on the tools we've covered so far, you might be tempted to start a proof by saying:

> Let $n \in \mathbb{N}$ be arbitrarily chosen.

And after that point, you'll need to show that $\sum_{i = 1}^n i = \frac{n(n + 1)}{2}$. But even to me, this sounds difficult. If anything, perhaps we were all told this fact in high school so we can take it to be true. But what if I told you there was a way to prove it?

Here's the high-level strategy:

1. (Base case) Firstly, we will prove that when $n = 1$, the left-hand side is the same right-hand side, i.e., $\sum_{i = 1}^1 i = \frac{1(1 + 1)}{2}$.
2. (Inductive case) Secondly, we will **assume** that for some $n = j$, the left-hand side is the same as the right-hand side, then **prove** that for $n = j + 1$, the left-hand side is still the same as the right-hand side.

Let me show you what I mean, then after that explain why this makes sense.

>[!example]+ Proof
>1. (Base case) Let $n = 0$. Then $\sum_{i = 1}^0 i = 0 = 0(1) = \frac{0(0 + 1)}{2}$. \[Basic algebra]
>2. (Inductive case) **Assume** that for some $n = j$, where $j \in \mathbb{N}$, we have $\textcolor{green}{\sum_{i = 1}^j i = \frac{j(j + 1)}{2}}$.
>		1. $\textcolor{blue}{\sum_{i = 1}^{j + 1} i} = \left(\sum_{i = 1}^{j} i \right) + (j + 1)$ \[Basic algebra]
>		2. $\textcolor{green}{\left(\sum_{i = 1}^{j} i \right)} + (j + 1) = \textcolor{green}{\frac{j(j + 1)}{2}} + (j + 1)$ \[By assumption on line 2]
>		3. $\frac{j(j + 1)}{2} + (j + 1) = (j + 1)\left(\frac{j}{2} + 1\right) = (j + 1)\left(\frac{j + 2}{2}\right) = \textcolor{red}{\frac{(j + 1)[(j + 1) + 1]}{2}}$ \[Basic algebra]
>		4. $\textcolor{blue}{\sum_{i = 1}^{j + 1} i} = \textcolor{red}{\frac{(j + 1)[(j + 1) + 1]}{2}}$ \[Basic algebra, from lines 2.1, 2.2, 2.3]
>3. $\forall n \in \mathbb{N} \ \left[ \sum_{i = 1}^n i = \frac{n(n+1)}{2}\right]$ \[Principle of mathematical induction]

There are quite a few features of this proof, and let's talk about the most important one first: let's focus on what happened on line 2.

![[induction-ap-statement.png]]

We **assumed** the equality works for some $n = j$, and we need to **prove** that the equality works for $n = j + 1$.

What the induction principle does is the following: given a statement $P(n)$ (in our example, $P(n)$ states that $\sum_{i = 1}^n i = \frac{n(n + 1)}{2}$):

1. If you have proven the statement $P(n)$ for a *base* case (in our example, when $n = 0$), and
2. You have proven the statement $P(n)$ for the *inductive* case (in our example, we assumed that $P(j)$ is true, then showed that $P(j + 1)$ is true),

Then the induction principle allows you to conclude that $\forall n \in \mathbb{N}$, the statement $P(n)$ is true. In other words, the statement is true no matter the natural number we give it.

Formally:

>[!info] Definition: Induction rule
> Let $P(n)$ be a statement about some $n \in \mathbb{N}$.
> 
> Suppose that we have proven that $P(0)$ is true. Also, suppose that we have proven the implication that for some $j \in \mathbb{N}$, $P(j) \to P(j + 1)$. (This second statement is also sometimes known as the **inductive hypothesis**.)
> 
> Then, we may conclude that $\forall n \in \mathbb{N} \ [P(n)]$.

Why does this work? Here's the intuition:

We know that the statement works when $n = 0$. We also know that **if** the statement works for $n = 0$, it also works for $n = 1$. So we can conclude that it also works for $n = 1$ (by modus ponens on the inductive hypothesis). Similarly, we know that **if** the statement works for $n = 1$, it also works for $n = 2$. Since we do know that it works for $n = 1$, we can now also happily conclude that it also works for $n = 2$. And so on and so forth.

![[induction-illus.png]]

## Proof By Induction Template

In general, to prove some statement $\forall n \in \mathbb{N}\ [P(n)]$, we use the following idea:

1. Prove $P(0)$.
2. Prove that if $P(n)$ is true, then $P(n + 1)$ is also true.

Or, more formally:

1. Prove $P(0)$.
2. Prove that $\forall n \in \mathbb{N}\ [P(n) \to P(n + 1)]$.

In the very first example we gave just now, the statement $P(n)$ was defined to be $\sum_{i = 1}^n i = \frac{n(n + 1)}{2}$. 

## One more example: Bernoulli's inequality

Let's do one more example, here's an inequality we sometimes use in computer science:

>[!Theorem]
> Let $x \in \mathbb{R}$ such that $x \geq -1$. Then, for all $n \in \mathbb{N}$,
> $$
> (1+x)^n \geq 1 + nx
> $$

To be clear, from a high-level overview, we want to show that:

1. The statement $(1+x)^n \geq 1+nx$ is true when $n = 0$.
2. Assuming that the statement $(1+x)^n \geq 1+nx$ is true when $n = j$, then the statement $(1+x)^n \geq 1+nx$ is also true when $n = j + 1$.

Once we do these two things, we can conclude that for all $n \in \mathbb{N}$, 

$$(1+x)^n \geq 1+nx$$

>[!example]+ Proof
> 1. Let $x \in \mathbb{R}$ such that $x \geq 1$.
> 2. (Base case) Let $n = 0$. Then $(1 + x)^n = 1^n = 1 \geq (1 + 0\cdot x)$. \[Basic algebra]
> 3. (Inductive case) **Assume** that for some $n = j$, where $j \in \mathbb{N}$, we have $\textcolor{green}{(1 + x)^j \geq 1 + jx}$.
> 		1. $\textcolor{blue}{(1 + x)^{j + 1}} = (1 + x)^j (1 + x)$ \[Basic algebra]
> 		2. $\textcolor{green}{(1 + x)^j} (1 + x) \geq \textcolor{green}{(1 + jx)}(1 + x)$ \[By assumption on line 3]
> 		3. $(1 + jx)(1 + x) = 1 + x + jx + jx^2 \geq 1 + x + jx = \textcolor{red}{1 + (j+1)x}$ \[Basic algebra]
> 		4. $\textcolor{blue}{(1 + x)^{j + 1}} \geq \textcolor{red}{1 + (j+1)x}$ \[Combining lines 3.1, 3.2, 3.3]
> 4. $\forall n \in \mathbb{N}\ [(1 + x)^n \geq 1 + nx]$ \[Principle of mathematical induction]

Again, pay special attention to line 3.2, we used the inductive hypothesis that $(1 + x)^j \geq 1 + jx$ in order to prove that:

$$(1 + x)^{j + 1} \geq 1 + (j+1)x$$

### What happens: Base case not proven

Let's talk about a common issue that happens in induction proofs. It is quite common that people forget to include base cases in their proofs, and they end up thinking some statement is true, because they thought they had a proof for it.

Here's an example, let's say we wanted to prove that:

> For all $n \in \mathbb{N}$, $n(n + 1)$ is odd.

Or a little more mathematically:

$$
\forall n \in \mathbb{N}, \exists k \in \mathbb{Z}\ [ n(n+1) = 2k+1 ]
$$

Consider the following faulty proof:

>[!warning] Faulty Proof
>1. (Inductive case) Assume that for some $n = j$, where $j \in \mathbb{N}$, we have $\textcolor{green}{\exists k \in \mathbb{Z}\ [j(j + 1) = 2k + 1]}$.
>		1.  $\textcolor{blue}{(j + 1)(j + 2)} = j(j + 1) + 2(j + 1)$ \[Basic algebra]
>		2. $\textcolor{green}{j(j + 1)} + 2(j + 1) = \textcolor{green}{2k + 1} + 2(j + 1)$, for some $k \in \mathbb{Z}$ \[By assumption on line 1, and existential instantiation of line 1]
>		3. $2k + 1 + 2(j + 1) = \textcolor{red}{2(k + j + 1) + 1}$ \[Basic algebra]
>		4. $\textcolor{blue}{(j + 1)(j + 2)} = \textcolor{red}{2(k + j + 1) + 1}$ \[Combining lines 1.1, 1.2, 1.3]
>		5. $\exists t \in \mathbb{Z}\ [(j + 1)(j + 2) = 2t + 1]$ \[Existential generalisation on line 1.4]

Have we actually proven the statement? Well, no! In fact, the exact opposite is true: for all $n \in \mathbb{N}$, $n(n + 1)$ is actually even, not odd.

Hence, it's very important to remember to cover the base case.

### What happens: Base case is not 0

At some point you might come across statements that look something like this:

$$
\forall n \geq 4\ [2^n < n!]
$$

In English, this states that:

> For all natural numbers $n$ such that $n \geq 4$, $2^n < n!$.

(To be clear, $n! = 1 \times 2 \times \dots \times n$.) 

Let's test this for a few values to see when it starts being true:

| $n$ | $2^n$ | $n!$ |
| :-: | :---: | :--: |
|  1  |   2   |  1   |
|  2  |   4   |  2   |
|  3  |   8   |  6   |
|  4  |  16   |  24  |
|  5  |  32   | 120  |

Notice how $n!$ seems to overtake $2^n$ only around $n = 4$ onwards. So how do we prove this? We change the base case!

>[!example]+ Proof Attempt
> 1. (Base case) Let $n = 4$. Then, $2^n = 16 < 24 = n!$.
> 2. (Inductive case) Assume that for some $n = j$, where $j \geq 4$, we have $\textcolor{green}{2^j < j!}$.
> 		1. $\textcolor{blue}{2^{j + 1}} = 2^j \cdot 2$ \[Basic algebra]
> 		2. $\textcolor{green}{2^j} \cdot 2 < \textcolor{green}{j!} \cdot 2$ \[By assumption on line 2]
> 		3. $j! \cdot 2 < j! \cdot (j + 1) = \textcolor{red}{(j + 1)!}$ \[Basic algebra, since $2 < 5 \leq j + 1$ when $j \geq 4$]
> 		4. $\textcolor{blue}{2^{j + 1}} < \textcolor{red}{(j + 1)!}$ \[Combining lines 2.1, 2.2, 2.3]
> 3. $\forall n \geq 4\ [2^n < n!]$ \[Principle of mathematical induction]

Again, pay attention to the how the base case has changed on line 1 in order to do our proof. Basically, we are claiming that $2^n < n!$ only from $n \geq 4$ onwards, and not saying anything about when $n = 0, 1, 2, 3$.

# Proof By Strong Induction Template

Let's modify the "proof by induction" template a little bit more: instead of assuming for just a single $j$ and trying to prove the statement for $j + 1$, let's tweak this instead to the following:

**Strong Induction Template**

1. Prove $P(b)$ for some base case value $b$.
2. Prove that assuming $\forall b \leq j < k\ [P(j)]$, then $P(k)$ is also true.

But why would we do this? Here's an example:

## Example Using Strong Induction:

Let's say that we lived in a country, where the only denominations are the $\textcolor{blue}{4}$-dollar and the $\textcolor{red}{5}$-dollar bills. Your friend, coming from Singapore, is doubtful that such a system would work. Let's convince them that we can use $\textcolor{blue}{4}$-dollar and $\textcolor{red}{5}$-dollar denominations to make any dollar value that is \$$8$ or larger. 

This seems true right? For example:
- \$$8$ itself uses two of the $\textcolor{blue}{4}$-dollar bills (i.e., $8 = 2(\textcolor{blue}{4}) + 0(\textcolor{red}{5})$)
- \$$9$ uses one $\textcolor{blue}{4}$-dollar bill and one $\textcolor{red}{5}$-dollar bill (i.e., $9 = 1(\textcolor{blue}{4}) + 1(\textcolor{red}{5})$)
- \$$10$ uses two $\textcolor{red}{5}$-dollar bills (i.e., $10 = 0(\textcolor{blue}{4}) + 2(\textcolor{red}{5})$)

Formally, we want to prove the following statement:

> $\forall n \geq 8, \exists a \in \mathbb{N}, \exists b \in \mathbb{N}\ [n = \textcolor{blue}{4}a + \textcolor{red}{5}b]$

Again, take note that we wish to prove this for $n$ from $12$ onwards, which hints to us that our base case should start from $8$. Pay special attention to the fact it is $8$ **onwards** (i.e., not necessarily just $8$ itself). This will become very important later. (Subtle foreshadowing...)

So let's look at a proof sketch:

>[!note] Proof Sketch
>1. (Base case) Let $n = 8$. Then, $n = 8 = 2(\textcolor{blue}{4}) + 0(\textcolor{red}{5})$.
>2. (Inductive case) Let $k \geq 8$, and assume that $\forall \textcolor{magenta}{j} < k$, we have that $\textcolor{green}{\exists a \in \mathbb{N}, \exists b \in \mathbb{N}\ [\textcolor{magenta}{j} = \textcolor{blue}{4}a + \textcolor{red}{5}b]}$.
>		1. Since $\textcolor{magenta}{k - 4} < k$, and we assumed that for all $\textcolor{magenta}{j} < k$, it was true that $\textcolor{green}{\exists a \in \mathbb{N}, \exists b \in \mathbb{N} [\textcolor{magenta}{j} = \textcolor{blue}{4}a + \textcolor{red}{5}b]}$, then we can say that $\textcolor{green}{\exists a \in \mathbb{Z}, \exists b \in \mathbb{Z}\ [\textcolor{magenta}{k - 4} = \textcolor{blue}{4}a + \textcolor{red}{5}b]}$. \[By assumption on line 2]
>		2. Let $a, b \in \mathbb{N}$ be such that $k - 4 = \textcolor{blue}{4}a + \textcolor{red}{5}b$. \[Existential instantiation on line 2.1]
>		3. Then, $k = \textcolor{blue}{4}(a + 1) + \textcolor{red}{5}b$. \[Basic algebra]
>		4. $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}\ [k = \textcolor{blue}{4}a + \textcolor{red}{5}b]$ \[Existential generalisation on line 2.3]
>3. Therefore, $\forall n \geq 8$, $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}\ [n = \textcolor{blue}{4}a + \textcolor{red}{5}b]$. \[Principle of mathematical induction]

Okay, so the proof looks reasonable. What if I said there's an issue?

Let's think about $11$—can we actually use only $\textcolor{blue}{4}$-dollar notes and $\textcolor{red}{5}$-dollar notes to make the dollar amount of \$$11$? We actually can't!

So where did we go wrong in our proof? It was our assumption. We assumed that for all values $\textcolor{magenta}{j} < k$, we can express $j$ using $\textcolor{blue}{4}$-dollar and $\textcolor{red}{5}$-dollar notes. So in our proof that it was possible for $11$, we had to assume that it was true for $\textcolor{magenta}{11 - 4} = 7$. Did we prove this? No we didn't, and that was the issue.

So let's look back at our proof and see how we can fix this. To prove it for $k$, we needed to assume it for $\textcolor{magenta}{k - 4}$. Since in our base case, we only proved it for $8$, this means we can only know for sure that values like $12$, $16$, $20$, $24$, $...$ and so on can be expressed using $\textcolor{blue}{4}$-dollar and $\textcolor{red}{5}$-dollar denominations.

So how do we prove this for all numbers? Notice that **if** (emphasis on **if**) in our base cases, we also proved it for starting values $8$, $9$, $10$ and $11$, then we can prove it for **all** numbers, because: 
- If we know it works for $8$, we know it works for $12$. 
- If we know it works for $9$, then it works for $13$. 
- If it works for $10$, it works for $14$. 
- If it works for $11$, then it works for $15$.

And we can keep repeating this to prove it for all the numbers from $8$ onwards. Pictorially speaking, it looks like this:

![[strong-induction-illus.png]]

Then why are we convinced that the statements for $16$, $17$, $18$ and $19$ are true? Similarly, because **if** we know it's true for $12$, $13$, $14$ and $15$, then we can say that for $16$, $17$, $18$ and $19$ as well.

Okay, let's take a step back. We just said that we cannot do this for $11$. This means that we actually cannot say "All dollar values from $8$ onwards can be made using $\textcolor{blue}{4}$-dollar and $\textcolor{red}{5}$-dollar denominations."

Okay, but what if I said that we could actually do this for dollar values $12$ onwards? Let's see the proof of this. This time the proof is correct. We have also shortened the proof a little bit, so all the important parts remain, but it is less verbose than in the previous weeks.

>[!example]+ Proof
> 1. (Base cases) We need to prove the statement for $n = 12$, $n = 13$, $n = 14$ and $n = 15$.
> 	- $12 = 3(\textcolor{blue}{4}) + 0(\textcolor{red}{5})$
> 	- $13 = 2(\textcolor{blue}{4}) + 1(\textcolor{red}{5})$
> 	- $14 = 1(\textcolor{blue}{4}) + 2(\textcolor{red}{5})$
> 	- $15 = 0(\textcolor{blue}{4}) + 3(\textcolor{red}{5})$
> 2. (Inductive case) Let $k \geq 16$, assume that for $12 \leq \textcolor{magenta}{j} < k$, $\textcolor{green}{\exists a \in \mathbb{N}, \textcolor{green}{\exists b \in \mathbb{N}\ [\textcolor{magenta}{j} = \textcolor{blue}{4}a + \textcolor{red}{5}b]}}$.
> 		1. Since $\textcolor{magenta}{k - 4} < k$ and $\textcolor{magenta}{k - 4} \geq 12$, $\textcolor{green}{\exists a \in \mathbb{N}, \exists b \in \mathbb{N}\ [\textcolor{magenta}{k - 4} = \textcolor{blue}{4}a + \textcolor{red}{5}b]}$.
> 		2. Let $r \in \mathbb{N}$, $s \in \mathbb{N}$ be such that $k - 4 = \textcolor{blue}{4}r + \textcolor{red}{5}b$. \[Existential instantiation on line 2]
> 		3. $k = \textcolor{blue}{4}(r + 1) + \textcolor{red}{5}s$ \[Basic algebra]
> 		4. Since $r \in \mathbb{N}$, $r + 1 \in \mathbb{N}$. \[Basic algebra]
> 		5. $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}\ [k = \textcolor{blue}{4}a + \textcolor{red}{5}b]$ \[Existential generalisation on lines 2.2, 2.3, 2.4]
> 3. $\forall n \geq 12, \exists a \in \mathbb{N}, \exists b \in \mathbb{N}\ [k = \textcolor{blue}{4}a + \textcolor{red}{5}b]$ \[Principle of mathematical induction]

Pay special attention to the following:

1. There are now **$4$** base cases, because in the inductive proof, we are taking **exactly** **$4$** steps back.
2. In our inductive case, we start from $16$, which is $4$ above the base case.
3. We also, for induction, assume that the statement we wish to prove holds true for values from $12$ up until $n - 1$.

Before we round off this section, let's provide a more formal definition of strong induction:

>[!info] Definition: Strong induction rule
> Let $P(n)$ be a statement about some $n \in \mathbb{N}$.
> 
> Suppose that we have proven that $P(b)$ is true for all $b_1 \leq b < b_2$.
> 
> Also, suppose that we have proven the implication that for some $k \geq b_2$,
> $$
> \bigg(\forall b_1 \leq j < k \ \big[P(j) \big] \bigg) \to P(k)
> $$
> 
> Then, we may conclude that $\forall n \in \mathbb{N} \ [P(n)]$.

Strong induction is especially handy when it comes to analysing recurrences. We will see more examples after the second topic on [[#Recurrences|recurrences]] in this unit, and next week.

---
# Part 2: Recurrences

Let's talk about another concept that is commonly used in computer science: recurrences. 

## A Motivating Example: Binary Search

Let's start with a motivating example. You might have seen this snippet of code before for an algorithm called [binary search](https://en.wikipedia.org/wiki/Binary_search) that looks for a particular `key` in an array of $n$ elements:

```python
def binary_search(arr, left, right, key):
	if left + 1 === right:
		return arr[left] === key

	mid = (right + left) // 2
	if arr[mid] <= key:
		return binary_search(arr, mid, right, key)
	else:
		return binary_search(arr, low, mid, key)
```

How do we analyse the running time of such an algorithm? While this is an advanced topic that we will not cover too comprehensively in this module, I think it serves as a good example of why we need to know about recurrences and the proof by induction—it help us analyse and understand recursive algorithms (among many other concepts in computer science).

## Recurrence Relations

Put simply, a **recurrence relation** is a way to describe a sequence of numbers *recursively*.

### Example 1: A simple recurrence

For example, we say $T(n)$ is a recurrence defined as:

$$
T(n) = \begin{cases}
T(n - 1) + 1, & n \geq 2\\
1, & n = 1\\
\end{cases}
$$

Notice that $T(1) = 1$. But what about $T(2)$? Well $T(2) = T(1) + 1$. Since we also know that $T(1) = 1$, this means that $T(2) = 1 + 1 = 2$.

Perhaps you have spotted the pattern—$T(n)$ is actually just $n$, as long as $n$ is a natural number that is at least $1$. Perhaps this is obvious, but even something like this can be proven by induction! In fact, this baby example is the perfect practice question!

Try proving the following:

>[!Theorem]
> Let $T(n)$ be defined as above. Then $\forall n \geq 1\ [T(n) = n]$.

Admittedly, our very first example of a recurrence was probably not very exciting. But I think it is a simple example to point at some features of recurrences. Pay attention to how this example of recurrence defines $T(n)$ using 2 cases:

1. When $n = 1$, $T(n)$ is defined to be $1$. This is our **base case**. It does not refer to any other values of $T(n)$.
2. When $n > 1$, $T(n)$ is defined to be $T(n - 1) + 1$. This is our **inductive case**. Notice how $T(n)$ refers to $T(n - 1)$.

For a recurrence to make sense, it needs to have at least one base case, and the inductive cases have to eventually reach the base case(s). For example, to compute $T(3)$, we need to know what $T(2)$ is. To know what $T(2)$ is, we need to know what $T(1)$ is. $T(1)$ is a base case, so we definitely know what it is. Then, we know what $T(2)$ is, and in turn, what $T(3)$ is. 

Let's look at more advanced examples of recurrences to show you more interesting concepts we can solve.

### Example 2: Factorials

Recall that $n!$ (pronounced "$n$ factorial") is defined to be:

$$
\prod_{i = 1}^n i
$$

For example:
- $1! = 1$
- $2! = 2 \times 1 = 2$
- $3! = 3 \times 2 \times 1 = 6$
- $4! = 4 \times 3 \times 2 \times 1 = 24$

Can we make a recurrence $F(n)$ such that $\forall n \geq 1\ [F(n) = n!]$? It's yet another good example you might want to think about before reading how to define it. Think about what the base case should be, and what the inductive case should be.

Anyway, here's the recurrence!

>[!Solution]-
>
> $$
> F(n) = \begin{cases}
> F(n - 1) \times n, & n \geq 2\\
> 1, & n = 1\\
> \end{cases}
> $$

Let's run through an example:

$$
\begin{align*}
\\& F(5)
\\& = F(4) \times 5
\\& = F(3) \times 4 \times 5
\\& = F(2) \times 3 \times 4 \times 5
\\& = F(1) \times 2 \times 3 \times 4 \times 5
\\& = 1 \times 2 \times 3 \times 4 \times 5
\\& = 120
\end{align*}
$$

Also, here's a proof that the recurrence matches what we want.

>[!Theorem]
> $\forall n \geq 1 \left[F(n) = \prod_{i = 1}^n i \right]$

As expected, we are going to do this by induction.

>[!example]+ Proof
> 1. (Base case) Let $n = 1$. Then $F(n) = F(1) = 1 =  \prod_{i = 1}^n i$. \[By definition of the recurrence]
> 2. (Inductive case) Assume that for some $n = j \geq 1$, we have $\textcolor{green}{F(j) = \prod_{i = 1}^j i}$.
> 		1. $\textcolor{blue}{F(j + 1)} = F(j) \times (j + 1)$ \[Definition of $F$]
> 		2. $\textcolor{green}{F(j)} \times (j + 1) = \textcolor{green}{\big(\prod_{i = 1}^j i \big)} \times (j + 1)$ \[By assumption on line 2]
> 		3. $\prod_{i = 1}^j i \times (j + 1) = \textcolor{red}{\prod_{i = 1}^{j + 1} i}$ \[Basic algebra]
> 		4. $\textcolor{blue}{F(j + 1)} = \textcolor{red}{\prod_{i = 1}^{j + 1} i}$ \[Combining lines 2.1, 2.2, 2.3]
> 3. $\forall n \geq 1\left[F(n) = \prod_{i = 1}^{n} i \right]$ \[Principle of mathematical induction]

### Example 3: Climbing stairs

Let's say that there are a flight a flight of stairs with $n \geq 2$ steps. We want to reach the top of the stairs, but we can only either take $1$ step or $2$ steps at a time. How many possible ways are there to reach the top?

![[stair-climbing.png]]

For example, if we had $n = 3$ steps, then the number of ways would be $3$, because:

![[stair-climbing-eg-1.png]]

1. Either we only take single steps.
2. We take a single step, then a double step.
3. We take a double step, and then a single step.

More generally, what is a recurrence $S(n)$ such that $S(n)$ tells us how many ways there are to climb stairs with $n$ steps? To solve this, we should think about a few base cases first.

For $n = 1$, there is only one way: take a single step. For $n = 2$, there are two ways: take $2$ single steps, or take $1$ double step.

What about some general $n$? Think about it this way: to reach the $n^{th}$ step, we just need to count the number of ways to reach the $(n - 1)^{th}$ step, and then take a single step after that to reach the $n^{th}$ step. Alternatively, we could count the number of ways to reach the $(n - 2)^{th}$ step, and then take a double step after that to reach the $n^{th}$ step.

So the recurrence looks like this:

$$
S(n) = \begin{cases}
S(n - 1)  + S(n - 2), & n > 2\\
2, & n = 2\\
1, & n = 1\\
\end{cases}
$$

Pay attention to how this time around, we have two base cases: $n = 1$ and $n = 2$. What happens if we only had a single base case of $n = 1$? Are there any issues with this? 

>[!Answer]-
> If we didn't have a base case for $n = 2$, then $S(2)$ is not defined, i.e., we cannot compute the value of $S(2)$.

Think about it: how many ways are there to climb $5$ steps? Well, that's simply (the number of ways you reach the $3^{rd}$ step) plus (the number of ways you reach the $4^{th}$ step). Why? Because for each way you reach the third step, you can take a double step at the end. For each way you reach the $4^{th}$ step, you can take a single step at the end.

![[stair-climbing-eg-5-double-single.png]]

Notice that in the left box, that is essentially $S(3)$ (the number of ways to reach the $3^{rd}$ step), and in the right box, that is actually $S(4)$ (the number of ways to reach the $4^{th}$ step). Notice that we need to take a double step after the reaching the $3^{rd}$ step, and we need to take a single step after reaching the $4^{th}$ step.

Therefore, $S(5)$ is really just the addition of those two counts!

You can even write a python program that does this for you:

```python
def stair_climbing(n):
	if n === 1:
		return 1
	if n === 2:
		return 2
	return stair_climbing(n - 1) + stair_climbing(n - 2)
```

You might notice that for large enough values of $n$, the program is substantially slow. This is something we will talk about in the tutorial and the [[Unit 5|next unit]]!

### Example 4: Binary search

Let's end by tying recurrences back to the motivating example of binary search. In the grand scheme of things, recurrences are a tool used in program/algorithm analysis, among many things. So how about we ask ourselves, how many array accesses does the binary search program make?

Let's look at the code again:

```python
def binary_search(arr, left, right, key):
	if left === right:
		return arr[left] === key

	mid = (right + left) // 2
	if arr[mid] <= key:
		return binary_search(arr, mid + 1, right, key)
	else:
		return binary_search(arr, low, mid, key)


binary_search(arr, 0, len(arr) - 1, key)
```

How do we begin? Well let's look at the base case of our algorithm, it's basically saying when the sub-array that we care about has only one element left, then we access `arr[left]` and compare it against our `key`. So when our sub-array is of size $1$, only one array access is made.

What about in general? Well then our array $arr[left...right]$ is split into two sub-arrays:
$arr\left[left \dots \frac{(left + right)}{2} - 1 \right]$, and $arr\left[\frac{(left + right)}{2} \dots right\right]$.

In either case, if we started with an array of length $n$, we are going to recurse on an array of length **at most** $\lceil \frac{n}{2} \rceil$.

So if we let $C(n)$ be the number of array accesses our binary search makes on an array of length $n$, we can then say that:

$$
C(n) = \begin{cases}
C( \lceil \frac{n}{2} \rceil ) + 1, & n > 1 \\
1, & n = 1 
\end{cases}
$$

How do we analyse this recurrence? This is something we will study in detail in the next unit. But for now, can we get a sense of its long-term behaviour?

We want to say this algorithm does not need to access "too many" elements in the array—only _about_ $\log_2(n)$ elements. How do we do this?

Let's prove that $\forall n \geq 2\ \big[C(n) \leq \log_2(n - 1) + 2 \big]$.

>[!Example] Proof
> 1. (Base case) Let $n = 2$. Then $C(2) = C(1) + 1 = 2 \leq \log_2(1) + 2$.
> 2. (Inductive case) Let $k \geq 3$, and assume that for all $2 \leq \textcolor{magenta}{j} < k$, we have $\textcolor{green}{C(\textcolor{magenta}{j}) \leq \log_2(\textcolor{magenta}{j} - 1) + 2}$.
> 		1. Since $k > 2$, then $2 \leq \textcolor{magenta}{\lceil \frac{k}{2} \rceil} < k$. Therefore, our assumption applies to $\textcolor{magenta}{\lceil \frac{k}{2} \rceil}$. \[Basic algebra]
> 		2. Then, we have the following inequality:
> 		   $$
>			\begin{align*}
>			\\& C(k)
>			\\& = \textcolor{green}{C \bigg(\textcolor{magenta}{\bigg\lceil \frac{k}{2} \bigg\rceil} \bigg)} + 1
>			\\& \textcolor{green}{\leq \log_2 \bigg(\textcolor{magenta}{\bigg\lceil \frac{k}{2} \bigg\rceil} - 1 \bigg) + 2} + 1
>			\\& \leq \log_2 \bigg(\frac{k + 1}{2} - 1 \bigg) + 2 + 
>			\\& = \log_2 \bigg(\frac{k - 1}{2} \bigg) + 2 + 1
>			\\& = \log_2(k - 1) - \log_2(2) + 2 + 1
>			\\& = \log_2(k - 1) - 1 + 2 + 1
>			\\& = \log_2(k - 1) + 2
>			\end{align*}
>			$$
>			
> 1. $\forall n \geq 2\ \big[C(n) \leq \log_2(n - 1) + 2 \big]$ \[Principle of mathematical induction]

So what does this mean? This means that we know for arrays of size $2$ onwards, then the function $C(n)$ is upper bounded by some $\log_2(n)$ curve. This is a hint to us that we are not using many array accesses, and thus the program is actually efficient!

