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


#### Counting Subsets
Let's see a simple and repeated application of the [[#Rule of Product Multiplying Successive Choices|rule of product]]. Let's say we had a set $A$ such that $\lvert A \rvert = n$. How many elements are in $\mathcal{P}(A)$? I.e. how many subsets are there?

Let's lay out the $n$ elements of $A$ as $a_1, a_2, \ldots, a_n$. Notice that for each of these elements, we can make a choice of "take" or "don't take". And for any sequence of $n$ choices, this creates for us a subset of $A$.

For example, if $A = \{1, 2, 3\}$, then a sequence like "take", "don't take", "take" will create a subset $\{1, 3\}$. Whereas a sequence like "don't take", "don't take", "don't take" creates the subset $\emptyset$.

We can think of this as making a set $C = \{\text{take}, \text{don't take}\}$. And we are basically asking what is:

$$
\underbrace{\lvert  C \times C \times \cdots \times C\rvert}_{n\text{ many times}} 
$$

By the [[#Rule of Product Multiplying Successive Choices|rule of product]], we know this is:

$$
\underbrace{\lvert  C \times C \times \cdots \times C\rvert}_{n\text{ many times}} = 
\underbrace{\lvert  C \rvert \times \lvert C \rvert \times \cdots \times \lvert C\rvert}_{n\text{ many times}} 
$$

We know that  $\lvert C \rvert = 2$. So the above is basically:
$$ 
\underbrace{\lvert  C \rvert \times \lvert C \rvert \times \cdots \times \lvert C\rvert}_{n\text{ many times}} = 2^n
$$

So $\lvert \mathcal{P}(A) \rvert = 2^{\lvert A \rvert}$.
### Rule of Division

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




What we if wanted to count numbers between $[a, b]$ (inclusive) that are divisible by $d$? Now we can use the idea from [[#Subtracting Cases]]! Notice we are counting the numbers from $[0, b]$ that are divisible by $d$, then subtracting away the numbers from $[0, a - 1]$ that are divisible by $d$. Which gives us:

$$
\left \lfloor \frac{b}{d} \right \rfloor + 1 - \left( \left \lfloor \frac{a - 1}{d} \right \rfloor + 1 \right) = \left \lfloor \frac{b}{d} \right \rfloor - \left\lfloor \frac{a - 1}{d}\right\rfloor
$$



Let's test out the formula. 

>[!Example]
> For example, how many numbers are there divisible by $3$ in the range $[5, 12]$? There is $6, 9, 12$.
> $\left \lfloor \frac{12}{3} \right\rfloor - \left\lfloor \frac{5 - 1}{3} \right\rfloor = 4 - 1 = 3$.

>[!Example]
> For example, how many numbers are there divisible by $5$ in the range $[5, 36]$? There is $5, 10, 15, 20, 25, 30, 35$.
> $\left \lfloor \frac{36}{5} \right\rfloor - \left\lfloor \frac{5 - 1}{5} \right\rfloor = 7 - 0= 7$.


>[!Example]
> What about if we asked how many numbers are divisible by $2$ in the range $[0, 9]$?  There should be $5$ of them: $0, 2, 4, 6, 8$.
> 
> $\left \lfloor \frac{9}{2} \right\rfloor - \left\lfloor \frac{0 - 1}{2} \right\rfloor = 4 - (-1) = 5$.


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


This technique alone is quite useful. Here is an example that makes use of this idea.

### Example:

Here's a question: How many $1$-digit numbers are there that are divisible by $2$ or $3$? So this is simple enough that we could have manually counted this: $0, 2, 3, 4, 6, 8, 9$.

For this example we're picking 1-digit numbers because it makes it easy for us to verify that we're indeed correct. This becomes very infeasible if we wanted to do this for 3 digit numbers and so on.

But we could have made 2 sets, $A = \{ x \in \mathbb{Z} : 0 \leq x \leq 9 \land divides(2, x) \}$, and $B = \{ x \in \mathbb{Z} : 0 \leq x \leq 9 \land divides(2, x) \}$. Then asked what is $\lvert A \cup B \rvert$?


So let's compute $\lvert A \rvert$, $\lvert B\rvert$, and $\lvert A \cap B \rvert$. The first 2 numbers are computed based on [[#Counting Multiples]].

For $A$, as before:
$$
\lvert A \rvert = \left \lfloor \frac{9}{2} \right \rfloor - \left \lfloor \frac{0 - 1}{2} \right \rfloor = 4 - (-1) = 5
$$


For $B$:
$$
\lvert B \rvert = \left \lfloor \frac{9}{3} \right \rfloor - \left \lfloor \frac{0 - 1}{3} \right \rfloor = 3 - (-1) = 4
$$

And for $A \cap B$, we want the numbers that are divisible by **both** $2$ and $3$. In other words, divisible, by $6$. So:


$$
\lvert A \cap B \rvert = \left \lfloor \frac{9}{6} \right \rfloor - \left \lfloor \frac{0 - 1}{6} \right \rfloor = 1 - (-1) = 2
$$

So now, we can figure out $\lvert A \cup B\rvert = 5 + 4 - 2 = 7$


#### Follow Up 1:
What if we wanted to count the 1-digit numbers that were **not** divisible by $3$, and **not** divisible by 2? In other words, we want to see how many numbers are in $[0, 9]$ and **not in** $A \cup B$. Notice again that $A \cup B \subseteq [0, 9]$. So again, through [[#Subtracting Cases]], we really just want $\left\lvert [0, 9]\setminus (A \cup B)\right\rvert$. Which happens to be:

$$
(9 - 0 + 1) - 7 = 3
$$

#### Follow Up 2:
What if we changed the question to: how many 1-digit numbers are there that are divisible by $2$ and $4$? If we made set $A$ the numbers in the range $[0, 9]$ that are divisible by $2$, and $B$ the set of integers in the range $[0, 9]$ that are divisible by $4$.

but what should $A \cap B$ be? Should we take this to be 8? No. We want numbers that are divisible by $2$ and $4$. Which happens to be numbers that are divisible by $4$. In fact, we can check this:

$A = \{0, 2, 4, 6, 8\}$, and $B = \{0, 4, 8\}$. And of course, $A \cap B = \{0, 4, 8 \}$.


So, **in general**, how do we determine the divisibility condition for the set $A \cap B$? If set $A$ contains integers that are divisible by $x$, and set $B$ contains integers that are divisible by $y$, then for $A \cap B$, we want integers divisible by both $x$ and $y$. These are the integers that are divisible by the **lowest common multiple** of $x$ and $y$.

So if $x = 2$, $y = 3$, we want $lcm(2, 3) = 6$, since $6$ is the smallest multiple of both $2$ and $3$. On the other hand, if $x = 2$ and $y = 4$, we want $lcm(2, 4) = 4$. 

So let's try one more example:

How many integers are there in the range $[10, 30]$ that are divisible by $6$ or $10$? To test it out let's also list this manually. The integers we want are: $10, 12, 18, 20, 24, 30$.

So letting set $A$ be the integers in that range that are divisible by $6$, and letting $B$ be the integers in that range that are divisible by $10$, the lowest common multiple of $6$ and $10$ is not $60$, but $30$. So set $A \cap B$ contains numbers in that range divisible by $30$.

So finally:

$$
\begin{align*}
\lvert A \rvert + \lvert B \rvert - \lvert A \cap B \rvert &= \left( \left \lfloor \frac{30}{6} \right \rfloor - \left \lfloor \frac{10 - 1}{6} \right \rfloor \right) + \left( \left \lfloor \frac{30}{10} \right \rfloor - \left \lfloor \frac{10 - 1}{10} \right \rfloor \right) - \left( \left \lfloor \frac{30}{30} \right \rfloor - \left \lfloor \frac{10 - 1}{30} \right \rfloor \right)\\
&= (5 - 1) + (3 - 0) - (1 = 0)\\
&= 4 + 3 - 1\\
&= 6\\
\end{align*}
$$

## Extending This to 3 Sets

We can actually extend this idea for $3$ sets (actually it also works beyond 3, but the formula starts being quite unwieldy).

For $3$ sets $A, B, C$, it holds that:

$$
\lvert A \cup B \cup C \rvert = \lvert A \rvert + \lvert B \rvert + \lvert C \rvert - \lvert A \cap B \rvert - \lvert B \cap C \rvert - \lvert B \cap C \rvert + \lvert A \cap B \cap C\rvert
$$

Why is this true? Let's look at the following Venn diagram.

![[3-set-venn.svg]]

Notice that if we have $\lvert A \rvert + \lvert B \rvert + \lvert C \rvert$, we would have **double counted** the elements in $\lvert A \cap B \rvert, \lvert B \cap C \rvert, \lvert B \cap C \rvert$, and **triple counted** the elements in $\lvert A \cap B \cap C \rvert$.

So consider $\lvert A \rvert + \lvert B \rvert + \lvert C \rvert - \lvert A \cap B \rvert - \lvert B \cap C \rvert - \lvert B \cap C \rvert$. We would have removed the double counts, but elements in $A \cap B \cap C$ which were triple counted, are now not counted at all. So we have to add it back in.


 At a food popularity contest, there are 3 options being voted for by people who are surveyed. We want to know how many people in total were surveyed. The 3 options were: (A) Lor Mee, (B) Nasi Lemak, (C) Chicken Rice. Anyone who is surveyed can vote for any combination of the options. I.e. a person could choose to vote for all 3, or any of the 2 choices, or any single choice. But they must at least vote for something. I.e. everyone who surveyed voted for at least one option, and at most all 3. We know the following counts:

 1. There were 10 people voting for option A (they might have also voted for other options).
 2. There were 7 people voting for option B (they might have also voted for other options).
3.  There were 9 people voting for option C (they might have also voted for other options).
4.  There were 3 people voting for only both option A and option B.
5.  There were 5 people voting for only both option A and option C.
6.  There were 2 people voting for only both option B and option C.
7.  Only 1 person voted for exactly all 3 options.

 How many people were surveyed?

$$
\begin{align*}
\lvert A \cup B \cup C \rvert &= \lvert A \rvert + \lvert B \rvert + \lvert C \rvert - \lvert A \cap B \rvert - \lvert B \cap C \rvert - \lvert B \cap C \rvert + \lvert A \cap B \cap C\rvert\\
&= 10 + 7 + 9 - 3 - 5 - 2 + 1 = 17\\
\end{align*}
$$

So in total, $17$ people were surveyed.
# Permutations and Combinations

Let's move on and away from sets, and start talking about permutations and combinations. Some of these concepts might already be familiar ground, and we will be using it to build up to some bigger concepts.
### Permutations of Distinct Items
Let's begin with the following question: 

> Given $n$ **distinct** items, how many ways are there to order the $n$ items?

Let's try this with $n = 3$. Here are all the possible ways to order them.

![[3-perm.svg]]

There are $6$ ways.

![[n-permutation-3.svg]]

What about in general for $n$ **distinct** items? How many permutations are there? A permutation of the items, is a way to order them.

We can think of it recursively. Let $P(n)$ be the number of ways to permute $n$ distinct items. If $n = 1$, there is only 1 possible ordering: the item itself.

When $n > 1$, how do we count this?

![[n-permutation-recurrence.svg]]

So in particular:

$$
P(n) = \begin{cases}
1 &, n = 1\\
n \times P(n - 1) &, n > 1\\
\end{cases}
$$

Doesn't this look familiar? This is $n!$. Or $\prod_{i = 1}^n i$.

### Permutations With Duplicates
What happens when the items we need to permute has duplicates? For example, let's say we want to count how many permutations there are of "aab"?

Notice that the answer is not $3! = 6$, but rather $3$. In fact, here are the possible permutations:

1. "aab"
2. "aba"
3. "baa"

Let's say we had $2$ item of type $a$, $1$ item of type $b$. Then the way we obtain the count is $3! / 2! = 3$.

What about in general? Here's an idea, we can first label each duplicate. For example, to count the number of ways to permute $aaab$, we can treat it as $a_1 a_2 a_3 b$ first, permute all of them and notice that for example permutations like: $a_1 a_2 b a_3$ should be treated the same as $a_2 a_1 b a_3$.

![[n-perm-duplicate.svg]]

So, using the [[#Rule of Division]], for this example, we can argue that the total number of permutations is $\frac{4!}{3!}$.

So in general, if we had $k$ **types** of items, and we had $n_i$ many copies of the $i^{th}$ item, then the total number of items is: $\sum_{i = 1}^k n_i = n$. Then the total number of permutations is:

$$
\frac{n!}{\prod_{i = 1}^k ((n_i)!)}
$$

Here's an example. How many permutations are there of "aaabb"? There are 3 copies of a, and 2 copies of b. There are 5 items in total. So the answer is:

$$
\frac{5!}{3! \cdot 2!} = \frac{120}{6 \cdot 2} = 10
$$

### $k$-Permutations of $n$ Distinct Elements  

Now, let's go back to looking at having $n$ distinct elements, but now we only care about picking $k$ of them. How many ways are there to permute that? 

For example, let's say we had 3 elements a, b, c. Then here all the possible ways:

1. ab
2. ba
3. ac
4. ca
5. bc
6. cb

But what about for general values of $n$ and $k$? We can again, think about this recursively. When $k = 1$, we are just asking how many ways are there to pick $1$ item out of $n$ items. That happens to just be $n$ itself. On the other hand, for $1 < k \leq n$, we can think of it as having to find $1$ out of the $n$ items to put into the first slot, then there are $n - 1$ items remaining, and among which, we need to pick $k - 1$ items to permute.

![[npk-recurrence.svg]]

So the recurrence looks something like this:

$$
P(n, k) = \begin{cases}
n &, k = 1\\
n \times P(n - 1, k - 1) &, k > 1\\
\end{cases}
$$

What does this resolve to? If you expanded out the recurrence, you might notice that it looks something like this:

$$
\begin{align*}
P(n, k) &= n\times P(n - 1, k - 1)\\
		&= n\times (n - 1) \times P(n - 2, k - 2)\\
		&= n\times (n - 1) \times (n - 2) \times P(n - 3, k - 3)\\
		&= n\times (n - 1) \times (n - 2) \times \dots \times P(n - (k - 1), 1)\\
		&= n\times (n - 1) \times (n - 2) \times \dots \times (n - (k - 1))\\
\end{align*}
$$

Which is basically:

$$
\prod_{i = 0}^{k - 1} (n - i)
$$

![[npk-alt.svg]]

There is another way we can see this. Imagine we considered all $n!$ possible permutations, and then said "any 2 permutations are considered the same as long as their first $k$ elements are the same". If we fixed the first $k$ elements, then there are $(n - k)!$ possible ways to permute the remaining elements. So any permutation has $(n - k)!$ that share the same first $k$ elements. Using the [[#Rule of Division]], this means there in total:

$$
\frac{n!}{(n - k)!}
$$

ways to permute $k$ elements out of $n$ distinct elements.

In fact, you can check that:

$$
\prod_{i = 0}^{k - 1} (n - i) = \frac{n!}{(n - k)!}
$$

We write this quantity as $P(n, k)$.
### Combinations without duplicates

Let's move on to another kind of counting that we commonly do: Combinations! Let's say we had $n$ distinct items, and this time, we want to count how many ways there are to **choose** $k$ items from the $n$ items.

For example, if there are $3$ items a, b, and c. How many ways are there to choose $2$ items out of these $3$?

1. a, b
2. a, c
3. b, c


![[content/Images/combi32.svg]]

Notice, the ordering does not matter. What is the formula this time? Again, there are a few ways to prove this. But perhaps the most straightforward way is to again make use of the [[#Rule of Division]].

Let's compare choosing 2 items out of 3, versus permuting 2 items out of 3. Previously, in [[#$k$-Permutations of $n$ Distinct Elements]], notice that the cases we had were:

1. ab
2. ba
3. ac
4. ca
5. bc
6. cb

For permutations, the **ordering** matters, whereas if we simply want to choose items, it does not matter. Again, for this example, notice how we are basically saying that "ab" and "ba" are the same. Because they have the same elements, and we do not care about their ordering. Since we picked $2$ items, there are $2!$ ways to permute the items. So this is:

$$
\frac{P(n, k)}{k!} = \frac{n!}{(n - k)!k!}
$$

We write this quantity as $C(n, k)$, or also write it most commonly as $\binom{n}{k}$.

Interestingly, we can also show that $\binom{n}{k} = \binom{n}{n - k}$. This might be "obvious" if you look at the fraction alone. In fact:

$$
\binom{n}{n - k} = \frac{n!}{(n - (n - k))!(n - k)!} = \frac{n!}{n! (n - k)!} =\binom{n}{k}
$$

But there's a very nice intuition behind why this is the case. Again, falling back to our trusty example of $n = 3$ and $k = 2$:

Instead of picking $2$ items out of the $3$ distinct items a, b, c to create a set of size $2$, we can think about how to **exclude** $3 - 2 = 1$ items out of the $3$ distinct items to create a set of size $2$.

1. a, b (means we picked c to be excluded)
2. a, c (means we picked b to be excluded)
3. b, c (means we picked a to be excluded)
# Applying Combinatorics

Now that we've covered the basic quantities, let's see a few applications of the counting methods shown.

## Stars and Bars

Let's say we had $t$ variables $x_1, x_2, \ldots, x_t$. All of which need to be $\geq 0$. How many value assignments can we give each $x_i$, so that:

$$
\sum_{i = 1}^t x_i = n
$$

For example, if $n = 5$, $t = 3$, then there are $36$ ways (far too many for us to list out here). As a simpler example, if $n = 5$, and $t = 2$, there are $6$ ways.

1. $x_1 = 0$, $x_2 = 5$
2. $x_1 = 1$, $x_2 = 4$
3. $x_1 = 2$, $x_2 = 3$
4. $x_1 = 3$, $x_2 = 2$
5. $x_1 = 4$, $x_2 = 1$
6. $x_1 = 5$, $x_2 = 0$

How should we even count the number of possible ways? Even for small values of $n$ and $t$, the number of cases becomes astronomically large.

The technique is called **stars and bars**. Here's the idea, again consider $n = 5, t = 3$:

![[stars-and-bars.svg]]

Think about how if we had $n + (t - 1)$ slots, then we can pick $t - 1$ slots to be bars in order to "force" the remaining $n$ slots to be stars. If we do this, then the first grouping of stars before the first bar is the value of $x_1$. The second grouping of stars behind the second bar is the value of $x_2$, and so on. The last grouping of stars after the $(t - 1)^{th}$ bar is the value of $x_4$.

Notice the sum of the values is exactly the number of stars we have: $n$.

So to find out how many ways to assign values to the $t$ variables, is to just pick $t - 1$ bars out of $n + (t - 1)$ possible positions. In other words:

$$
\binom{n + t - 1}{t - 1}
$$

## Block Walking

Let's try another one. Given a grid of $6$ columns, and $4$ rows, where we start from the bottom left. And we are only allowed to either take one step up, or one step to the right each time. How many ways are there for us to go from the bottom left to the top right? 

In the picture below, the red and blue path are examples of paths you can take.

![[blockwalk.svg]]

So here's the idea, treat the red path as a sequence $(U, U, R, U, R, U, R, R, R, R)$. The blue path is a sequence $(R, R, U, R, R, R, R, U, U, U)$. Notice that for $4$ rows and $6$ columns, we have to take $4$ "up" steps, and $6$ "right" steps. A different sequencing of the "up" and "right" steps gives us a different path.

Again, this is similar as to stars and bars. But this time, we have $4 + 6$ slots, $4$ of which we need to pick to be "up" steps, and the remaining to be "right" steps.

In general, for $c$ columns and $r$ rows, the number of paths is given as:

$$
\binom{c + r}{r}
$$

# A Sense of Scale

## Binomial Coefficients and Nested For Loops

## Some Useful Bounds on Combinatorial Properties
