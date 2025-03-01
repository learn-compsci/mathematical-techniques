---
title: "Unit 4: Induction, Recurrences"
---
# Overview
In this unit we will be introducing 2 seemingly separate topics that actually have a deep connection: the induction proof technique, and recurrences.

Both of these are vital tools in computer science, and we will see some examples that demonstrate this idea. We will also be using these ideas directly in the next unit.


# Mathematical Induction

To start off, let's talk about the induction proof technique. This is the last main proof technique that we had left out from [[Unit 1]] because it really deserves that much attention. This is one of the most handy tools that we use in order to prove statements we care about.


## Revisiting An Example: The Arithmetic Series
To show you what I mean, let's re-visit an example that I had mentioned when introducing and motivating proofs in the first place: 

> Can we show that $\forall n \in \mathbb{N}$, $\sum_{i = 1}^n i = \frac{n(n + 1)}{2}$?

(Recall that $\sum_{i = 1}^n i = 1 + 2 + \cdots + n$)

You might notice, that based on the tooling we've covered so far, you might be tempted to start a proof by saying:

> Let $n \in \mathbb{N}$, arbitrarily chosen.

And after that point, you'll need to show that $\sum_{i = 1}^n i = \frac{n(n + 1)}{2}$. But even to me, this sounds difficult. If anything, perhaps we were all told this fact in high school so we can take it to be true. But what if I told you there was a way to prove it?

Here's the high-level strategy:

1. (Base Case) Firstly, we will prove that when $n = 1$, the left-hand side is the same right-hand side. I.e. $\sum_{i = 1}^1 i = \frac{1(1 + 1)}{2}$
2. (Inductive Case) Secondly, we will **assume** that for $n = j$, the left hand side is the same as the right hand side, then **prove** that for $n = j + 1$, the left hand side is the same as the right hand side.

Let me show you what I mean, then after that explain why this makes sense.

>[!example]+ Proof
>1. (Base Case) Let $n = 0$. Then $\sum_{i = 1}^0 i = 0 = 0(1) = \frac{0(0 + 1)}{2}$ \[Basic Algebra]
>2. (Inductive Case) **Assume** that for $n = j$, where $j \in \mathbb{N}$, $\sum_{i = 1}^j i = \frac{j(j + 1)}{2}$.
>	1. $\sum_{i = 1}^{j + 1} i = \left(\sum_{i = 1}^{j} i \right) + (j + 1)$ \[Basic Algebra]
>	2. $\left(\sum_{i = 1}^{j} i \right) + (j + 1) = \frac{j(j + 1)}{2} + (j + 1)$ \[By assumption on line 2]
>	3. $\frac{j(j + 1)}{2} + (j + 1) = (j + 1)\left(\frac{j}{2} + 1\right) = (j + 1)\left(\frac{j + 2}{2}\right) = \frac{(j + 1)(j + 2)}{2}$ \[Basic Algebra]
>	4. $\sum_{i = 1}^{j + 1} i = \frac{(j + 1)(j + 2)}{2}$ \[Basic algebra using lines 2.1, 2.2, 2.3]
>3. $\forall n \in \mathbb{N}\left[ \sum_{i = 1}^n i = \frac{n(n+1)}{2}\right]$ \[Principle of mathematical induction]



There are quite a few features of this proof, and let's talk about the most important one first: let's focus on what happened on line 2. 

![[induction-ap-statement.png]]

We **assumed** the equality works for $n = j$, and we need to **prove** that the equality works for $n = j + 1$.

And what the induction principle does, is the following, given a statement $P(n)$ (in our example, $P(n)$ states that $\sum_{i = 1}^n i = \frac{n(n + 1)}{2}$):

1. If you have proven the statement $P(n)$ for a base case (in our example, when $n = 0$).
2. 2. You have proven the statement $P(n)$ for the inductive case (in our example, we assumed that $P(j)$ is true, then showed that $P(j + 1)$ is true).
Then the induction principle allows you to conclude that $\forall n \in \mathbb{N}$, the statement $P(n)$ is true. In other words, the statement is true no matter the natural number we give it.

Formally:

>[!Induction-Rule]
> If we have a proven statement $P(0)$, and for some arbitrarily chosen $j \in \mathbb{N}[P(j) \to P(j + 1)]$, then we may conclude $\forall n \in \mathbb{N}[P(n)]$.

Why does this work? Here's the intuition:

We know that the statement works when $n = 0$. We also know that **if** the statement works for $n = 0$, it also works for $n = 1$. So we can conclude we know that it also works for $n = 1$. Similarly, we know that **if** the statement works for $n = 1$, it also works for $n = 2$. Since we do know that it works for $n = 1$, we can now also happily conclude that it also works for $n = 2$. And so on and so forth.

![[induction-illus.png]]

# Proof By Induction Template

So in general, to prove some statement $\forall n \in \mathbb{N}[P(n)]$, we use the following idea:

1. Prove $P(0)$
2. Prove that if $P(n)$ is true, then $P(n + 1)$ is also true.

Or, more formally:

1. Prove $P(0)$
2. Prove that $\forall n \in \mathbb{N}[P(n) \to P(n + 1)]$.

In the very first example we gave just now, the statement $P(n)$ is defined to be $\sum_{i = 1}^n i = \frac{n(n + 1)}{2}$. 

## One more example: Bernoulli's inequality
Let's do one more example, here's an inequality we sometimes use in computer science:

>[!Theorem]
> Let $x \in \mathbb{R}$ such that $x \geq -1$. Then, for all $n \in \mathbb{N}$,
> $$(1+x)^n \geq 1+nx$$

To be clear, from a high-level overview, we want to show that:

1. The statement $(1+x)^n \geq 1+nx$ is true when $n = 0$
2. Assuming that the statement $(1+x)^n \geq 1+nx$ is true when $n = j$, then the statement $(1+x)^n \geq 1+nx$ is also true when $n = j + 1$.

Once we do these two things, we can conclude that for all $n \in \mathbb{N}$, 

$$(1+x)^n \geq 1+nx$$

>[!example]+ Proof
> 1. Let $x \in \mathbb{R}$ such that $x \geq 1$.
> 2. (Base Case) Let $n = 0$. Then $(1 + x)^n = 1 = 1 + 0\cdot x$.
> 3. (Inductive Case) **Assume** that for $j \in \mathbb{N}$, $(1 + x)^j \geq 1 + jx$
> 	1. $(1 + x)^{j + 1} = (1 + x)^j (1 + x)$ \[Basic algebra]
> 	2. $(1 + x)^j (1 + x) \geq (1 + jx)(1 + x)$ \[By assumption on line 3]
> 	3. $(1 + jx)(1 + x) = 1 + x + jx + jx^2 \geq 1 + x + jx = 1 + x(j+1)$ \[Basic algebra]
> 	4. $(1 + x)^{j + 1} \geq 1 + x(j+1)$ \[Combining lines 3.1, 3.2, 3.3]
> 4. $\forall n \in \mathbb{N}[(1 + x)^{j + 1} \geq 1 + x(j+1)]$ \[Principle of mathematical induction]

Again, pay special attention to line 3.2, we used the assumption that $(1 + x)^j \geq 1 + jx$ in order to prove that $(1 + x)^{j + 1} \geq 1 + x(j+1)$.

## What Happens If: Did Not Prove It For A Base Case
Let's talk about a common issue that happens in induction proofs. It is quite common that people forget to include base cases in their proofs, and they end up thinking some statement is true, because they thought they had a proof for it.

Here's an example, let's say we wanted to prove that:

> For all $n \in \mathbb{N}$, $n(n + 1)$ is odd.

Or a little more mathematically:

$$
\forall n \in \mathbb{N}, \exists k \in \mathbb{Z} [ n(n+1) = 2k+1 ]
$$

Consider the following faulty proof:

1. (Inductive case) Assume that for $j \in \mathbb{N}$, $\exists k \in \mathbb{Z}[j(j + 1) = 2k + 1]$.
	1.  $(j + 1)(j + 2) = j(j + 1) + 2(j + 1) = 2k + 1 + 2(j + 1) = 2(k + j + 1) + 1$
	2. $\exists t \in \mathbb{Z}[(j + 1)(j + 2) = 2t + 1]$ \[Existential Generalisation]

Have we actually proven the statement? Well, no! In fact, the exact opposite is true, for all $n \in \mathbb{N}$, $n(n + 1)$ is actually even, not odd.

So it's very important to remember to cover the base case.

## What Happens If: The Base Case Was Not 0?

At some point you might come across statements that look something like this:

$$
\forall n \geq 4 [ 2^n < n!  ]
$$

Which in English, states that:

> For all natural numbers $n$ such that $n \geq 4$, $2^n < n!$.

(To be clear, $n! = 1 \times 2 \times \dots \times n$) 

Let's test this for a few values to see when it starts being true:


| $n$ | $2^n$ | $n!$ |
| :-: | :---: | :--: |
|  1  |   2   |  1   |
|  2  |   4   |  2   |
|  3  |   8   |  6   |
|  4  |  16   |  24  |
|  5  |  32   | 120  |

Notice how $n!$ seems to overtake $2^n$ only around $n = 4$ onwards. So how do we prove this? We change the base case!

>[!example]+ Proof
> 1. (Base case) Let $n = 4$, $2^n = 16 < 24 = n!$
> 2. (Inductive Case) Let $n \geq 4$, assume that $2^n < n!$
> 	1. $2^{n + 1} = 2^n \cdot 2 < n! \cdot 2 < n! \cdot (n + 1) = (n+1)!$ \[Basic Algebra]
> 3. $\forall n \geq 4 [2^n < n!]$ \[Principle of mathematical induction]

Again, pay attention to the how the base case has changed in on line 1 in order to do our proof. Basically, we are only claiming that $2^n < n!$ only from $n \geq 4$ onwards, and not saying anything about when $n = 0, 1, 2, 3$.


# Proof By Strong Induction Template

Let's modify the "proof by induction" template a little bit more: instead of assuming for $j$ and trying to prove for $j + 1$, let's tweak this instead to the following:

**Strong Induction Template**
1. Prove $P(b)$ for some base case value $b$.
2. Prove that assuming $\forall j < k[P(j)]$ then $P(k)$ is also true.

But why would we do this? Here's an example:

## Example Using Strong Induction:

Let's say that we lived in a country, where the only denominations are the $4$-dollar and the $5$-dollar bills. Your friend, coming from Singapore, is doubtful that such a system would work. Let's convince them that _we can use 4-dollar and 5-dollar denominations to make any dollar value that is **$8$ or larger_**. 

This seems true right? For example:

8 itself uses two of the 4-dollar bills. 9 uses one 4-dollar bill, and one 5-dollar bill. 10 uses one 10-dollar bill.

Formally, we want to prove the following statement:

> $\forall n \geq 8, \exists a \in \mathbb{N}, \exists b \in \mathbb{N} [n = 4\cdot a + 5 \cdot b]$

Again, take note, we wish to prove this for $n$ from $12$ onwards, which hints to us that our base case should be from $8$ onwards. Pay special attention to the fact it is 8 onwards. This will become very important later. (Subtle foreshadowing...)

So let's look at a proof sketch:


**Proof Sketch**
1. (Base case) Let $n = 8$, then $n = 8 = 2(4) + 0(5)$
2. (Inductive case) Let $k \geq 8$, assume that $\forall j < k$, $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}$ such that $j = 4a + 5b$
	1. Since $k - 4 < k$, and we assumed that for all $j < k$, it was true that $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}$ such that $j = 4a + 5b$, then we can say that $k - 4 = 4a + 5b$
	2. Thus, $k = 4(a + 1) + 5b$
	3. $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}$ such that $k = 4a + 5b$
3. Therefore, $\forall n \geq 8$, $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}[n = 4a + 5b]$

Okay, so the proof looks reasonable. What if I said there's an issue?

---

Let's look at the first version of a proof first before 



Also take note of the new assumption we make in the proof (on line $3$, we fix $k \geq 12$, then assume that **any value less than $k$** can be broken up into 4 and 5 denominations. Then our goal becomes to prove it for $k$ itself. Let


>[!example]+ Proof
> 1. (Base case) Let $n = 12$. Then $n = 12 = 3(4) + 0(5)$.
> 2. $3 \in \mathbb{N} \land 0 \in \mathbb{N}$ \[Basic Algebra]
> 3. **Let $k \geq 12$, assume that $\forall j < k$, $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}$ such that $j = 4a + 5b$**
> 	1. Since $k - 4 < k$, by our assumption, $\exists a \in \mathbb{N}, \exists b \in \mathbb{N}[k - 4 = 4a + 5b]$.
> 	2. 


# Recurrences
Algorithm recurrences, binary search, fibonacci.
