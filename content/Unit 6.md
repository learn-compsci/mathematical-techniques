---
title: Combinatorics
---
# Overview
In this unit, we will start moving onto topics that are very distinct from proofs and far closer to the traditional topics in math that are useful in computer science. To do this, we will first begin with combinatorics! Think of this as an advanced way of _counting_. The reason why this is useful is because when it comes to analysing certain mathematical constructs, or when it comes to counting how many cases our programs have to deal with, the techniques here the ones we fall back on.


# Counting Based on Sets

Let's begin by simplifying things a little bit, for now let's just count items in sets. Since we are counting, we need to talk about the size of sets. So given a set $A$, the size of a set is written as $\lvert A \rvert$.

So for example: $\lvert \{a, b, 2, 100\}\rvert = 4$ since this set has $4$ items. Also since $\emptyset$ is empty, this means that it holds no items. So $\lvert \emptyset \rvert = 0$. Also we won't consider infinitely sized sets, so we won't be talking about what $\lvert \mathbb{Z} \rvert$ is.

## Basic Counting Techniques

So let's start with the most general ideas that will be repeated for the next few weeks: adding disjoint and multiplying successive choices.
### Rule of Sum: Adding Disjoint Cases

Let's say we had two sets, $A$ and $B$ that had no common elements. That is to say, $A \cap B = \emptyset$. We  call these two sets **disjoint**.

So what is the size of $A \cup B$? In other words, if we knew three things:

1. $\lvert A\rvert = m$
2. $\lvert B\rvert = n$
3. $A \cap B = \emptyset$

What is $\lvert A \cup B \rvert$? Well, $\lvert A \cup B \rvert = m + n$.

>[!Example]
> Let $A = \{1, 2, 3, 4\}$ and $B = \{10, 11, 12\}$. Then $A \cap B = \emptyset$.
> So $\lvert A \rvert + \lvert B \rvert = 4 + 3 = 7$.

>[!Example]
> Let $A = \emptyset$ and $B = \{10, 11, 12\}$. Then $A \cap B = \emptyset$.
> So $\lvert A \rvert + \lvert B \rvert = 0 + 3 = 3$.


What about in general? What if we had 3 sets? What if we had 10 sets? What should the condition be? This is a little subtle.

Let's try this for 3 sets. Let's say we had $3$ sets $A, B, C$ for which:

1. $\lvert A\rvert = m$
2. $\lvert B\rvert = n$
3. $\lvert C\rvert = \ell$
4. $A \cap B \cap C = \emptyset$

Can we conclude that $\lvert A \cup B \cup C\rvert = m + n + \ell$? Feels very tempting for us to conclude so, after all the sets are disjoint right?

What about the following example of sets?

$A = \{2, 4, 6\}$, $B = \{3, 6\}$, $C = \{3, 5\}$. Now notice that $A \cap B \cap C = \emptyset$. Check it! There is not a single element that is in all $3$ sets!

1. $2 \notin C$
2. $3 \notin A$
3. $4 \notin B$
4. $5 \notin B$
5. $6 \notin C$

So $\lvert A \rvert = 3$, $\lvert B \rvert = \lvert C \rvert = 2$. So we expect $3 + 2 + 2 = 7$ elements. But $\lvert A \cup B \cup C\rvert = 5$. So our condition here isn't quite right. Where did we go wrong?

Let's think of it this way. We **want** to use the fact that when two sets are disjoint, we can just add their sizes together. How should we use this to work on 3 sets? Let's consider an alternative set of conditions:

1. $\lvert A\rvert = m$
2. $\lvert B\rvert = n$
3. $\lvert C\rvert = \ell$
4. $A \cap B = \emptyset$
5. $A \cap C = \emptyset$
6. $B \cap C = \emptyset$

From conditions 4, 5, and 6, we can derive the following lemma:

**Lemmas 1:**
$$
\begin{align*}
(A \cup B) \cap C &= (A \cap C) \cup (B \cap C)\\
				  &= \emptyset \cup \emptyset\\
				  &= \emptyset
\end{align*}
$$

So what does this mean? It means that the set $A \cup B$ and the set $C$ is **disjoint**! This means that $\lvert (A \cup B) \cup C\rvert = \rvert (A \cup B) \rvert + \lvert C \rvert$. 


So let's try counting again:

$$
\begin{align*}
	\lvert A \cup B \cup C \rvert &= \lvert (A \cup B) \cup C \rvert\\
					&= \lvert (A \cup B) \rvert + \lvert C \rvert\\
					&= \lvert A \rvert  + \lvert B \rvert + \lvert C \rvert\\
\end{align*}
$$

Now it works! So what about between more sets? Here's the general statement:

Given $n$ sets $A_1, A_2, A_3, \ldots, A_n$, such that:

1. $\forall i \in [n]$, $\lvert A_i \rvert = s_i$                                              (the $i^{th}$ set has size $s_i$)
2. $\forall i \in [n]$, $\forall j \in [n]$, if $i \neq j$, then $A_i \neq A_j = \emptyset$     (any two distinct sets are **disjoint**)

Then, $\sum_{i = 1}^n s_i = \lvert A_1 \cup A_2 \cup A_3 \cup \dots \cup A_n\rvert$. The size of the all of the sets is just their individual sizes added up.


**Conclusion:** So what's the conclusion here? Think of it this way, when we could make either choices from set $A$ **or** choices from set $B$, where $A$ and $B$ are disjoint. Then we can just add them up.

### Rule of Product: Multiplying Successive Choices

Okay, what about considering making a sequence of choices? Given two sets $A$, $B$ (this time not necessarily disjoint), how do we count how many ways are there to make a choice from $A$ **and then** a choice from $B$?

This one is a little more straightforward. After all, we've actually made sets that actually represent this!

To make a choice from $A$ **and then** a choice from $B$ is to ask, how many pairs there are from $A$ and then $B$. I.e.
$$
\begin{align*}
A \times B
\end{align*}
$$

So we are essentially asking: what is the size of $A \times B$? And this is pretty much just $\lvert A \rvert \times \lvert B \rvert$.

>[!Example]
> Let $A = \{1, 2, 3, 4\}$ and $B = \{1, 3\}$. Then $A \times B = \{(1, 1), (1, 3), (2, 1), (2, 3), (3, 1), (3, 3), (4, 1), (4, 3)\}$.
> 
> $\lvert A \rvert = 4$, $\lvert B \rvert = 2$, and $\lvert A \times B\rvert = 4 \times 2 = 8$.


>[!Example]
> Let $A = \{1, 2, 3, 4\}$ and $B = \emptyset$. Then $A \times B = \emptyset$.
> 
> $\lvert A \rvert = 4$, $\lvert B \rvert = 0$, and $\lvert A \times B\rvert = 4 \times 0 = 0$.
> 

This one is far less involved. Here's the general statement:

Given $n$ sets $A_1, A_2, A_3, \ldots, A_n$, then:

1. $\forall i \in [n]$, $\lvert A_i \rvert = s_i$                                              (the $i^{th}$ set has size $s_i$)

Then, $\prod_{i = 1}^n s_i = \lvert A_1 \times A_2 \times A_3 \times \dots \times A_n\rvert$. The size of the all of the sets is just their individual sizes multiplied.

### Rule of Division: Shepard's Law

So while the previous two laws might be a little clearer, there's one less common one that is based on a nice trick. Let's try this with a scenario:

> Let's say it was right after the midterm, and we have just collected a bunch of exam scripts. We know each script has the same number of pages to scan, 8 pages. We put our entire stack of exam scripts in the scanner, and the scanner reports there are 104 pages scanned.
> 
> How many scripts have we scanned? Since each script had 8 pages, this means there were 104 / 8 scripts.


This might sound a little obvious, but this trick can be taken to extremes eventually in the subsequent sections.

In general, if we have $n$ items, but we are able to group $k$ of them into groups where we think they are *identical*, then we have $n/k$ groups.

### Subtracting Cases

One more useful idea is when we have two sets $A, B$ and we are promised that $B \subseteq A$. Then, we know that:

$$
\lvert A \setminus B \rvert = \lvert A \rvert - \lvert B \rvert
$$

### Counting Consecutive Numbers

The last of the basic counting facts is the following: Given a set of integers that are at least $a$, and at most $b$. I.e. 

$$
\{ x \in \mathbb{Z} : a \leq x \land x \leq b \}
$$

How many integers are there? It's very tempting to say $b - a$, but the actual answer is $b - a + 1$.

For example, there are $6 - 2 + 1 = 5$ integers in the set $\{2, 3, 4, 5, 6\}$.
### Counting Multiples

What about if we wanted to count numbers divisible by some number $d$ within some range $[a, b]$?

This is a little tricky. Let's try a simpler idea:

Given a positive number $a$, how many numbers in the range $[1, a]$ are there that are divisible by $d$? Well, there are $a$ numbers in that range, so that would be:

$$
\left \lfloor \frac{a}{d} \right \rfloor 
$$

If we instead wanted the numbers in the range $[0, a]$ that are divisible by $d$, then this becomes:

$$
\left \lfloor \frac{a}{d} \right \rfloor + 1
$$

because $0$ is divisible by any number (including $d$).







The formula for doing this is a little strange:

$$
\left \lfloor \frac{b + 1}{d} \right\rfloor - \left\lceil \frac{a - 1}{d} \right\rceil + 1
$$




Let's test out the formula. 

>[!Example]
> For example, how many numbers are there divisible by $3$ in the range $[5, 12]$? There is $6, 9, 12$.
> $\left \lfloor \frac{12 + 1}{3} \right\rfloor - \left\lceil \frac{5 - 1}{3} \right\rceil + 1 = 4 - 2 + 1 = 3$.

>[!Example]
> For example, how many numbers are there divisible by $5$ in the range $[5, 36]$? There is $5, 10, 15, 20, 25, 30, 35$.
> $\left \lfloor \frac{36 + 1}{5} \right\rfloor - \left\lceil \frac{5 - 1}{5} \right\rceil + 1 = 7 - 1 + 1 = 7$.

But wait! What about if we asked how many numbers are divisible by $2$ in the range $[0, 9]$?  There should be $5$ of them: $0, 2, 4, 6, 8$.

But the formula evaluates to:


# Principle of Inclusion Exclusion

Sticking to the topic of counting sets for now, can we be a little more precise in counting $\lvert A \cup B\rvert$? There actually is a formula for this!

$$
\lvert A \cup B \rvert = \lvert A \rvert + \lvert B \rvert - \lvert A \cap B\rvert
$$


>[!Example]
> Let $A = \{2, 4, 6\}$, $B = \{3, 6\}$. Then $A \cap B = \{ 6 \}$.
> 
> Then $\lvert A \rvert = 3$, $\lvert B \rvert = 2$, and $\lvert A \cap B \rvert = 1$. Then $\lvert A \cup B\rvert = 3 + 2 - 1 = 4$.

Why does this work? Because the idea is that if we just add $\lvert A \rvert$ and $\lvert B \rvert$, we're double counting the elements in $\lvert A \cap B \rvert$, since they will be added once due to $\lvert A\rvert$, then added once again in $\lvert B \rvert$.

![[pie.svg]]

In fact, this tells us why the additive rule works when $A$ and $B$ are disjoint. Because in that case, $\lvert A \cap B \rvert = 0$.


This technique alone is quite useful. Here are 2 examples that make use of this idea.

### Example 1:

Here's a question: How many $1$-digit numbers are there that are divisible by $2$ or $3$? So this is simple enough that we could have manually counted this: $0, 2, 3, 4, 6, 8, 9$.

For this example we're picking 1-digit numbers because it makes it easy for us to verify that we're indeed correct. This becomes very infeasible if we wanted to do this for 3 digit numbers and so on.

But we could have made 2 sets, $A = \{ x \in \mathbb{Z} : 0 \leq x \leq 9 \land divides(2, x) \}$, and $B = \{ x \in \mathbb{Z} : 0 \leq x \leq 9 \land divides(2, x) \}$. Then asked what is $\lvert A \cup B \rvert$?


So let's compute $\lvert A \rvert$, $\lvert B\rvert$, and $\lvert A \cap B \rvert$. The first 2 numbers are computed based on [[#Counting Multiples]].

So $\lvert A \rvert = \left \lfloor \frac{9 + 1}{2} \right\rfloor - \left\lceil \frac{0 - 1}{2} \right\rceil + 1 = 5 - 0 + 1 = $

## Generalised Principle of Inclusion Exclusion

# Permutations and Combinations

## Recursive Definition of Combinations and Pascal's Triangle



# Applying Combinatorics

## Stars and Bars

## Block Walking

