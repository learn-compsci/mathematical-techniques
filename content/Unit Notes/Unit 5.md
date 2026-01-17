---
title: "Unit 5: Asymptotic Notation, and Algorithmic Analysis"
---
# Overview

In this unit, we'll continue building upon the motivations in [[Unit 4]] by doing three things:

1. [[#Part 1 Asymptotic Notation|Showing big O, big Omega and big Theta terminology (asymptotic notation)]]
2. Bounding recurrences and general functions
3. Showing how induction is used in the context of computer science

Think of this as a big culmination of the reason we learned logic, proofs, induction and logical statements. After this point, we will be focusing on a different branch of topics.

---
# Part 0: Motivation

Let's begin with an example. Let's say that we wrote this Python program that just counts how many even numbers there are in an array (or rather, a Python list).

```python
def count_even(arr):
	count = 0
	for x in arr:
		if x % 2 == 0:
			count += 1
	return count
```

How long does this program take?

You could perhaps plot a graph, where the $x$-axis is the size of the array and the $y$-axis is how long it takes for this program to run. We could also write similar code in C++ and Java that does something like this.

Also, let's pretend that we ran some experiments, and plotted some graphs to find out how long they take. Then maybe we'd get something like this:

![[example-plot.svg]]

Notice they all kind of look like straight lines. Like linear functions. Why? Because intuitively, no matter the programming language, the three of them would be following the same idea: start from the first item, go through each item until the last, and for each of them, we do a check to see if it's even or not. In some sense, if we had $n$ items, the `for` loop just goes through all $n$ of them.

Depending on the programming language (and even computer hardware), our total time taken might not the same, but we can expect the same linear trend between the time taken, and the array size. We want to basically say "no matter the programming language or hardware conditions, we expect to see the same linear trend".

This does not just apply to different programming languages, but even different *approaches* to solve the same computational problem.

Here's another example, let's say we wanted to sort numbers in an array. There are many ways of doing this, let's look at two possible ways:

```python
def sorter1(arr):
	for index1 in range(1, len(arr)):
		index2 = index1
		while index2 > 0 and arr[index2] < arr[index2 - 1]:
			arr[index2], arr[index2 - 1] = arr[index2 - 1], arr[index2]
			index2 -= 1

def sorter2(arr):
	for index1 in range(len(arr) - 1):
		min_index = index1
		for index2 in range(index1, len(arr)):
			if arr[min_indx] < arr[index2]:
				min_index = index2
		arr[min_index], arr[index1] = arr[min_index], arr[index1]
```

Here's an idea about how these two sorting methods work. The first one basically tries to move the $i^{th}$ element backwards until $arr[i] \geq arr[i - 1]$. After that, we rinse and repeat with the $(i + 1)^{th}$.

![[insertion-sort.svg]]

For example, let's say that we're on the $4^{\text{th}}$ element, we iterate backwards and keep swapping until the $3^{\text{rd}}$ element is greater than or equal to the element on its left, which only happens when it's the $2^{\text{nd}}$ element on the array.

How many steps does the program take? Well the inner loop takes **at most** $index_1$ many iterations, and $index_1$ ranges from $1$ to $n$. Hence, `sorter1` uses at most $1 + 2 + 3 + 4 + \cdots + (n - 1)$ iterations.

On the other hand, the second one repeatedly tries to find the minimum element before placing it in the correct location.

![[selection-sort.svg]]

How many iterations does this take now? For $index_1$, we need to check $n - index_1$ values. This means the total iterations are $n + (n - 1) + (n - 2) + \cdots + 1$.

While both methods have $1 + 2 + \dots = \frac{n(n+1)}{2}$ iterations, what they do in each iteration is not the same! The first one does some swapping, the second one does comparisons and only swaps towards the end. It would be reasonable to think that because of that, even though the number of iterations are the same, the total time taken would be different. Again, a hypothetical plot you might see if we took some experimental values might look something like this:

![[example-plot-2.svg]]

We might expect both sorters to have a **quadratic** relationship between the time taken with respect to the array size. In particular, the curves might look like $an^2 + bn + c$ for some constants $a$, $b$ and $c$.

In both scenarios we've talked about, bear in mind that what we care about is the "rough trend" of running time, as $n$ approaches infinity. In other words, as $n$ grows, what kind of curve does the running time look like? That is, how much work is done **relative** to the input size $n$? Think about this as a form of "scaling".

![[example-plot-3.svg]]

For example, let's say we had two programs, one of which whose "time taken" curve is $0.0005n^2 + 0.00000000001n + 2$, and another program whose "time taken" curve is $3000\log(n)$. Which program is more "efficient"? Typically we want to design solutions that scale well, and that means solutions that handle large scale inputs very well. For that reason, we would like to say the second program is better. But how do we communicate this fact mathematically?

---
# Part 1: Asymptotic Notation

## Big O

For that reason, it is very common for computer scientists to talk about certain functions using big O notation. To start us off, here's a formal definition of big O:

>[!info] Definition: Big O
> Let $\textcolor{red}{f(n)}$ be a function on the natural numbers. Then, the **set** $O(\textcolor{red}{f(n)})$ contains all functions $\textcolor{green}{g(n)}$ such that
> $$
> \exists n_0 \in \mathbb{N}, \exists \textcolor{blue}{c} \in \mathbb{R^+}, \forall n \geq n_0 \ \big[ \textcolor{green}{g(n)} \leq \textcolor{blue}{c} \cdot \textcolor{red}{f(n)} \big]
> $$
> where $\mathbb{R}^+$ is the set of positive real numbers, i.e., anything greater than $0$.

Also, we will only ever consider functions $\textcolor{red}{f(n)}$ that are always positive, i.e., $\forall n \in \mathbb{N}\ [\textcolor{red}{f(n)} > 0]$.

So for example, if $\textcolor{red}{f(n)} = \textcolor{red}{n}$, then the set $O(\textcolor{red}{f(n)}) = O(\textcolor{red}{n})$. And this set **contains** functions like $\textcolor{green}{g(n) = 5n}$, or functions like $\textcolor{green}{g(n) = 6 \sqrt{n}}$ and $\textcolor{green}{g(n) = 20 \log_2(n)}$. On the other hand, functions like $g(n) = n^2$ are not in the set $O(\textcolor{red}{n})$.

Why is this the case? Let's run through the examples.

For a function like $\textcolor{green}{g(n) = 5n}$, how do we argue that $\textcolor{green}{g(n)} \in O(\textcolor{red}{n})$?  We need to provide a value $\textcolor{purple}{n_0}$ and a positive constant $\textcolor{blue}{c} \in \mathbb{R}$. How about $n_0 = 1$, and $\textcolor{blue}{c = 7}$? Then, for all $n \geq n_0$, we have: 

$$
\textcolor{green}{g(n)} = \textcolor{green}{5 \cdot n} \leq \textcolor{blue}{7} \cdot \textcolor{red}{n} = \textcolor{blue}{c} \cdot \textcolor{red}{f(n)}
$$

What about something like $\textcolor{green}{g(n) = 6 \sqrt{n}}$? How do we argue that $\textcolor{green}{g(n)} \in O(\textcolor{red}{n})$?  We need to provide a value $n_0$ and a positive constant $\textcolor{blue}{c} \in \mathbb{R}$. How about $n_0 = 1$, and $\textcolor{blue}{c = 6}$? Then, for all $n \geq n_0$, we have: 

$$
\textcolor{green}{g(n)} = \textcolor{green}{6 \cdot \sqrt{n}} \leq \textcolor{blue}{6} \cdot \textcolor{red}{n} = \textcolor{blue}{c} \cdot \textcolor{red}{f(n)}
$$

Lastly, consider $\textcolor{green}{g(n) = 20 \log_2(n)}$.  We have that:

$$
\textcolor{green}{g(n)} = \textcolor{green}{20 \cdot \log_2(n)} \leq \textcolor{blue}{20} \cdot \textcolor{red}{n} = \textcolor{blue}{c} \cdot \textcolor{red}{f(n)}
$$

Then, setting $n_0 = 1$ and $\textcolor{blue}{c = 20}$ would help us justify this.

What about $\textcolor{green}{g(n) = n^2}$? Why is that function not in $O(\textcolor{red}{n})$? Remember, to **not** be in the set means the negation of the condition, i.e.,

$$
\forall n_0 \in \mathbb{N}, \forall \textcolor{blue}{c} \in \mathbb{R^+}, \exists n \geq n_0 \ [ \textcolor{green}{g(n)} > \textcolor{blue}{c} \cdot \textcolor{red}{f(n)}]
$$

So how do we do this? We need to show that no matter the starting point $n_0$ and the multiplier $\textcolor{blue}{c}$, at some point beyond $n_0$, we will find some value $n$ for which $\textcolor{green}{g(n)} > \textcolor{blue}{c} \cdot \textcolor{red}{f(n)}$. Consider any arbitrarily chosen $n_0$ and any arbitrarily chosen positive value $\textcolor{blue}{c}$. Then we can pick $n = \max(\textcolor{blue}{c}, n_0) + 1$, and claim that for this $n$, we have $\textcolor{green}{g(n)} > \textcolor{blue}{c} \cdot \textcolor{red}{f(n)}$:

$$
\begin{align*}
	\textcolor{green}{g(n)} &= \textcolor{green}{g(\max(\textcolor{blue}{c}, n_0) + 1)}\\
		 &= (\max(\textcolor{blue}{c}, n_0) + 1) \cdot (\max(\textcolor{blue}{c}, n_0) + 1)\\
		 &> \max(\textcolor{blue}{c}, n_0) \cdot (\max(\textcolor{blue}{c}, n_0) + 1))\\
		 &\geq \textcolor{blue}{c} \cdot (\max(\textcolor{blue}{c}, n_0) + 1))\\
		 &\geq \textcolor{blue}{c} \cdot \textcolor{red}{n}\\
		 &= \textcolor{blue}{c} \cdot \textcolor{red}{f(n)}
\end{align*}
$$

### Some visual intuition behind Big O

So what's going on here? Let's try plotting out some example graphs.

![[Images/qvl.svg]]

Here, the red curve is $0.05x^{2}+0.6x+1$, the green curve is $x+5$, the blue curve is $2x$, and the purple curve is $\frac{x}{2} + 30$. Here's the idea: no matter the gradient of a linear curve, no matter how large, there will always be a point where the quadratic curve will be larger than it after some point.

So let's look at the definition of big O again, and see how it lines up.

$$
\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0\ [ g(n) \leq c\cdot f(n)]
$$

The $n_0$ here is the point at which $c\cdot f(n)$ starts being larger. But what about the scaling factor $c$? Here's the idea, let's say I had 3 functions $f(n) = 5n$ and $g(n) = 10n$ and $h(n) = 5n + 5$. All of them actually scale the same way: they're all linearly related to $n$.

![[Images/linear-scaling.svg]]

So you're free to pick a scaling factor $c$ to say something like $g(n) \in O(h(n))$.


So you can think of $f(n) \in O(g(n))$ as basically saying "$f(n)$ as a function **at some point onwards** is going to be $\leq$ the function some positive multiple of function $g(n)$".

### Big O in the Wild

In fact, big O notation is actively used in the wild. For example, the containers provided by the standard template library by C++ come with documentation on their complexity. This is how C++ tells you how the operations/methods of their containers scale with the size of the containers itself.

![[cppref-screenshot.png|]]
(Screenshot taken from [cppreference](https://en.cppreference.com/w/cpp/container/set/insert))

Even wiki pages that discuss algorithms and data structures use this notation.
![[wiki-big-O.png]]

## Big Omega

As previously mentioned, think of $f(n) \in O(g(n))$ as our way of saying a function $f(n)$ is "at most" function $g(n)$. There are a few other notations that are less common, but still worth mentioning.

Given a function $f(n)$, then the **set** $\Omega(f(n))$ (pronounced "big omega") contains all functions $g(n)$ such that:

$$
\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0\ [ g(n) \geq c\cdot f(n)]
$$

Notice that all we have done is flipped the $\leq$ into a $\geq$. So big omega is basically saying that a function $g(n)$ is "at least" function $f(n)$.

So along those lines, let's look at some examples. We can say something like $5n \in \Omega(20n)$, we can also say something like $n^2 \in \Omega(\sqrt{n})$. On the other hand, we cannot say something like $1000n \in \Omega\left(\frac{n^2}{1000}\right)$.

## Big Theta

Lastly, given a function $f(n)$, the set $\Theta(f(n))$ is defined to be the set of all functions $g(n)$ such that $g(n) \in O(f(n))$ and $g(n) \in \Omega(f(n))$. In particular:

$$
\Theta(f(n)) = O(f(n)) \cap \Omega(f(n))
$$
## Some properties about asymptotic notation

#### The asymptotics of polynomials
Now that we have these sets that talk about functions, let's cover some useful properties about them.

Let's start with a function like $0.75n^3 - 10n^2 + 5n + 3000$. Can we say this is $O(n^3)$? After all, intuitively, for large enough $n$, the **dominant** term is $n^3$ here, and the smaller terms like $-10n^2$ and $5n$ start to become insignificant in comparison.

So given a polynomial like the one above, we can find the most dominant term (the one with the highest power), and then drop any constant factors that it comes with, then conclude it is big O of that function. Like in our example above, we identify the $0.75n^3$, and drop the constant factor, thereby concluding the function is in $O(n^3)$.

> [!Claim]
>  Given a degree-$k$ polynomial $f(n) = \sum_{i = 0}^k a_i \cdot n^i$ where $a_k > 0$, then $f(n) = O(n^k)$. 

Why is this true? Here's a sketch of the math behind it, we are going to show that $n$ from $n_0$ onwards, $f(n) \leq c\cdot n^k$ for some constant $c$.

**Proof:**
1. Consider a degree-$k$ polynomial: $$f(n) = \sum_{i = 0}^k a_i \cdot n^i$$
2. $$
   \begin{align*}
		f(n) &=  \sum_{i = 0}^k a_i \cdot n^i\\
		&\leq  \sum_{i = 0}^k \lvert a_i \rvert \cdot n^k\\
		&\leq  n^k \cdot \left(\sum_{i = 0}^k \lvert a_i \rvert \right)\\
   \end{align*}
   $$
   3. So setting $n_0 = 1$ and $c=  \left(\sum_{i = 0}^k \lvert a_i \rvert \right)$, we are guaranteed that $f(n) \leq c\cdot n^k$. Therefore, $f(n) \in O(n^k)$.


In fact, perhaps a little unintuitively, we can also say the following:

> [!Claim]
>  Given a degree-$k$ polynomial $f(n) = \sum_{i = 0}^k a_i \cdot n^i$ where $a_k > 0$, then $f(n) = \Omega(n^k)$. 

Why is this true? We are now saying that the function $f(n)$ grows at least as the rate of its highest term. Which intuitively still makes sense, since as $n$ tends to $\infty$, the function is still dominated by the $n^k$ term. But how do we prove this? It may be tempting to prove this in the following way:

**Faulty Proof:**
1. Consider a degree-$k$ polynomial:  $$f(n) = \sum_{i = 0}^k a_i \cdot n^i$$
2. $$
   \begin{align*}
		f(n) &=  \sum_{i = 0}^k a_i \cdot n^i\\
		&\geq  a_k \cdot n^k\\
   \end{align*}
   $$
   3. Let $n_0 = 1$ and $c = a_k$. Then $\forall n \geq n_0\ [f(n) \geq c \cdot n^k]$.

Where did we go wrong? Why is this faulty? Hint: Is line 2 correct?

>[!Answer]-
> For example, consider $f(n) = 10n^2 - 5n$. Can we really say $f(n) \geq 10n^2$ for $n \geq 1$? No we can't!

So instead, we're going to prove a useful lemma first before proving the original statement properly.

**Lemma:**
Let $f(n) = \frac{1}{b}\cdot n^k - an^t$ where $0 \leq t < k$, and $a, b > 0$. Then for all $n \geq a\cdot b$, $f(n) \geq 0$. In other words, $\frac{1}{b}(n^k)$ is greater than or equal to $an^t$.

$$
\begin{align*}
\frac{1}{b}\cdot n^k &\geq \frac{1}{b}n^k\\
					 &\geq \frac{1}{b}(a\cdot b)^k\\
					 &\geq \frac{b}{b}(a^k)(b^{k - 1})\\
					 &\geq (a^{t+1})(b^{t})\\
					 &\geq a \cdot (a^t)(b^t)\\
					 &\geq a \cdot (a\cdot b)^t\\
					 &= a \cdot n^t\\
\end{align*}
$$

So what does this mean? Let's try working out an example being seeing the general idea:

Consider a polynomial like $n^2 - 5n - 10$. We want to say that there is some $n_0$ and some positive $c$ such that $n^2 - 5n - 10 \geq cn^2$ for $n \geq n_0$. So how do we do this? We'll split $n^2$ into three parts $\frac{n^2}{3}$ and rearrange the sum:

$$
\begin{align*}
n^2 - 5n - 10 &= \left(\frac{n^2}{3} + \frac{n^2}{3} + \frac{n^2}{3}\right) - 5n - 10\\
			  &= \frac{n^2}{3} + \left(\frac{n^2}{3} - 5n\right) + \left(\frac{n^2}{3} - 10\right)\\
\end{align*}
$$

Now we know that from the previous part, as long as $n$ is large enough, we know that $\frac{n^2}{3} - 5n\geq 0$, and $\frac{n^2}{3} - 10\geq 0$.  In particular, the previous lemma proved that as long as $n \geq \max(3 \cdot 5, 3 \cdot 10)$, then we can say that:

$$
\begin{align*}
\frac{n^2}{3} + \left(\frac{n^2}{3} - 5n\right) + \left(\frac{n^2}{3} - 10\right)
&\geq \frac{n^2}{3} + 0 + 0\\
&\geq \frac{n^2}{3}\\
\end{align*}
$$

So what about in general when we have a degree-$k$ polynomial?

**Proof:**
1. Let $f(n) = \sum_{i = 0}^k a_i \cdot n^i$ be a degree-$k$ polynomial with $a_k > 0$.
2. $$
	\begin{align*}
	\sum_{i = 0}^k a_i \cdot n^i &= \left(\frac{a_k}{k + 1}\right)n^k + \sum_{i = 0}^{k - 1} \left(\frac{n^k}{k + 1} - a_i n^i\right)\\
	\end{align*}
   $$
3. Then by setting $n = \max\{ a_0, a_1, \ldots, a_{k - 1} \}\cdot \left(\frac{k + 1}{a_k}\right)$, we know that $\left(\frac{a_k}{k + 1}\right)n^k + \sum_{i = 0}^{k - 1} \left(\frac{n^k}{k + 1} - a_i n^i\right)$ is non-negative, so: $$
	\begin{align*}
	\sum_{i = 0}^k a_i \cdot n^i &= \left(\frac{a_k}{k + 1}\right)n^k + \sum_{i = 0}^{k - 1} \left(\frac{n^k}{k + 1} - a_i n^i\right)\\
	&\geq \left(\frac{a_k}{k + 1}\right)n^k
	\end{align*}
	$$
4. Since $a_k > 0$ and $k + 1 > 0$, we have that $\left(\frac{a_k}{k + 1}\right) > 0$. So setting $c = \left(\frac{a_k}{k + 1}\right)$ and $n_0 \geq n = \max\{ a_0, a_1, \ldots, a_{k - 1} \}\cdot \left(\frac{k + 1}{a_k}\right)$, we are able to conclude that $\forall n \geq n_0\ [f(n) \geq c\cdot n^k]$.


Now from the previous 2 parts, we know that $f(n) \in O(n^k)$ and $f(n) \in \Omega(n^k)$. So we can conclude that $f(n) = \Theta(n)$.

> [!Claim]
>  Given a degree-$k$ polynomial $f(n) = \sum_{i = 0}^k a_i \cdot n^i$ where $a_k > 0$, then $f(n) = \Theta(n^k)$. 

#### The transitivity of Big O
Let's say that we relate function $f(n)$ to function $g(n)$ if $f(n) \in O(g(n))$. Then this relationship is transitive.

**Proof:**
1. Let $f(n), g(n), h(n)$ be functions.
2. Assume that $f(n) \in O(g(n))$ and $g(n) \in O(h(n))$.
	1. Since $f(n) \in O(g(n))$, $\exists c > 0, n_0 \geq 0, \forall n \geq n_0 \ [f(n) \leq c\cdot g(n)]$. \[Definition of big O]
	2. Since $g(n) \in O(h(n))$, $\exists d > 0, m_0 \geq 0, \forall n \geq m_0\ [g(n) \leq d\cdot h(n)]$. \[Definition of big O]
	3. Consider $s = \max(n_0, m_0)$, and $t = c\cdot d$.
		1. Since $c > 0$ and $d > 0$, therefore $t > 0$.
		2. Consider any $n \geq s$. Then $n \geq n_0$ and $n \geq m_0$.
		3. $f(n) \leq c\cdot g(n) \leq c\cdot d\cdot h(n) = t\cdot h(n)$
	4. $\exists s \geq 0, t > 0, \forall n \geq s\ [f(n) \geq t\cdot h(n)]$.
	5. $f(n) \in O(h(n))$
3. If $f(n) \in O(g(n))$ and $g(n) \in O(h(n))$, then $f(n) \in O(h(n))$.

#### The asymptotics of other functions
Now that we have established transitivity, we can start comparing functions quite easily. In fact, this means we can start placing functions down in some kind of "ordering". Let's show how some common functions are ordered among each other. From "smaller" to "larger" functions, we have that:

$$
\begin{equation}
\sqrt{\log(n)} \ll \log(n) \ll \log^2(n) \ll \sqrt{n}  \ll n \ll n^2 \ll 2^{\sqrt{n}} \ll 2^\frac{n}{2} \ll 2^n \ll 2^{n^2}
\end{equation}
$$


Okay, that's a very long list. We aren't going to prove all of this, but it's hopefully most of these are very intuitive. However, let's take a closer look at the following:

>[!Claim]
> $2^{(\frac{n}{2})} \in O(2^n)$ but $2^n \notin O(2^{\frac{n}{2}})$.

This might look a little unintuitive at first. After all, isn't $n \in O(\frac{n}{2})$? 

Let's prove the first part first.

**Proof:**
1. Consider $n_0 = 2$, and $c = 1$. Consider any $n \geq n_0$.
2. $2^{\frac{n}{2}} \leq \left(2^{\frac{n}{2}}\right)^2 \leq 1\cdot 2^n$
3. Thus, $2^{\frac{n}{2}} \in O(2^n)$.

Well that was pretty straightforward. But what about the other direction? We'll show no matter the $n_0$ and $c$ someone picks, we can find a value $t \geq n_0$ for which $2^t > c\cdot 2^{\frac{t}{2}}$. No matter the multiplier, the function $2^t$ will overtake $c\cdot 2^{\frac{t}{2}}$ at some point.

**Proof:**
1. Let $n_0 \geq 0$ and $c > 0$ be arbitrarily chosen.
2. Set $t > \max(2\log_2(c), 1)$.
3. Then $2^t = 2^{\frac{t}{2}}\cdot 2^{\frac{t}{2}} > 2^{\frac{2\log_2(c)}{2}}\cdot 2^{\frac{t}{2}} = c\cdot 2^{t}$.


#### Big O vs Big Omega

One last thing for us to think about: If $f(n) \in O(g(n))$, can we also say $g(n) \in \Omega(f(n))$? In fact, we can!

> [!Claim]
> If $f(n) \in O(g(n))$, then $g(n) \in \Omega(f(n))$.

**Proof:**
1. Assume $f(n) \in O(g(n))$.
2. Then $\exists n_0 \geq 0, \exists c \in \mathbb{R^+}, \forall n \geq n_0\ [f(n) \leq c\cdot g(n)]$. \[Definition of big O]
3. Since $c > 0$, $\frac{1}{c} > 0$.
4. Thus, $\forall n \geq n_0 \ [g(n) \geq \frac{1}{c} f(n)]$.
5. So $\exists n_0 \geq 0, d \in \mathbb{R^+}, \forall n \geq n_0 \ [g(n) \geq d\cdot f(n)]$. \[Existential generalisation on lines 3, 4]
6. Thus, $g(n) \in \Omega(f(n))$. \[Definition of big omega]


# Recurrences and Big O: The Substitution Method

Now that we've talked about big O, let's try relating it back to program analysis. There are quite recurrences that we might encounter when writing recursive programs. For example, here's a recursive program that computes $n!$ :

```python
def factorial(n):
	if n == 1:
		return 1
	return n * factorial(n - 1)
```

For example, we want to say that this program has a linear running time with respect to $n$. How do we even do that? 

If we ever want to analyse this, there are 2 parts to it:
1. We need to look at the program and derive the recurrence that corresponds to the program.
2. We need to **bound** the recurrence.

While we won't do much of part 1 here, we will be talking more about part 2. But for this example specifically, when $n = 1$, there is $O(1)$ work being done: the comparison, returning a value. When $n > 1$, the total work done is $T(n - 1) + O(1)$ work being done. Why? Because we need to do $T(n - 1)$ amount of work to solve $T(n - 1)$, and an additional $O(1)$ amount of work to multiply the answer by $n$, and return it.

So, we obtain this recurrence:
$$
T(n) = \begin{cases}
T(n - 1) + O(1), & n > 1\\
O(1), & n = 1\\
\end{cases}
$$

Okay, now we need to **bound** it. In this case we will prove that $T(n) \in O(n)$. How do we do this? This is done via the **substitution method**.

Let's look at the proof before pointing out the features it has. To prove that $T(n) \in O(n)$, we need to show that $T(n) \leq c\cdot n$ for some constant $c > 0$. 

**Proof**:
Let $c = 1$, and **assume that** $\forall m < n$, $T(m) \leq c\cdot m = m$. Then:
$$
\begin{align*}
T(n) &= T(n - 1) + 1\\
	&\leq (n - 1) + 1\\
	&= 1\cdot n
\end{align*}
$$

This proof probably looks very different from the ones we have done so far. Here are the important steps:

1. We first take the $O(1)$ in the definition of $T(n)$, and just re-write this as $1$. This is very informal, but this is a simplification that just makes it easier for us to do the proof. This is why you see it written as $T(n-1) + 1$ in the first line.
2. We typically have to make use of our assumption to replace any recurrent terms. For example, $T(n - 1)$ is replaced by $n - 1$ due to our assumption.
3. Since we wanted to show that $T(n) \in O(n)$, the assumption made was that $T(m) \leq c\cdot m$.
4. Lastly, we need to conclude for $T(n)$ the exact same statement as our assumption: We assumed $T(m) \leq c\cdot m$, so we have to conclude that $T(n) \leq c\cdot n$.

Notice here that while this looks like a proof of induction, we don't have a base case, and there is a reason for this: We are just trying to prove that $T(n) \in O(n)$. Since this means we only care about showing that $T(n) \leq c\cdot n$ for some $n \geq n_0$ onwards (where $c$ and $n_0$ are of our choosing), this technically means we can set what we want to be our base case, and artificially choose constants for which the base case is always true. So there's really no point in covering the base case for the substitution method. This makes it a very quick and easy tool to bound recurrences.


## A negative example of the method
Now, before showing you a few more positive examples, let's go through a negative example of the substitution method.

Let's say we were given the following recurrence:

$$
T(n) = \begin{cases}
T(\lfloor n / 2\rfloor) + T(\lceil n / 2\rceil) + 1, & n > 1\\
1, & n = 1\\
\end{cases}
$$

Let's say we suspect that $T(n) \in O(n)$. Given that, again, we are going to let $c = 1$ and assume that for all $m < n$, $T(m) \leq c\cdot m = m$.

Then:
**Faulty Proof:**
Let $c = 1$, **assume that** $\forall m < n$, $T(m) \leq c\cdot m = m$. Then:
$$
\begin{align*}
	T(n) &= T(\lfloor n / 2\rfloor) + T(\lceil n / 2\rceil) + 1\\
		 &\leq \lfloor n / 2\rfloor + \lceil n / 2\rceil + 1\\
		 &= n + 1\\
\end{align*}
$$

Okay, this proof looks harmless enough. Where did we go wrong?

>[!Hint]-
> Does the conclusion look right to you?

>[!Tip]- Answer
> We have to conclude that $T(n) \leq n$, not conclude that $T(n) \leq n + 1$.

Remember, we made an assumption that $T(m) \leq m$ for all $m < n$. To fulfil our end of the deal, we need to prove that $T(n) \leq n$. If we had instead shown that $T(n) \leq n + 1$, we are falling shy of that goal.

How do we fix this proof? Here's an idea, instead of assuming $T(m) \leq m$, we are going to assume that $T(m) \leq m - 1$, for all $m < n$. This might seem counter-intuitive, but it works. After all, if we can conclude that for all $n$, $T(n) \leq n - 1$, then it holds that $T(n) \leq n$, which then means that $T(n) \in O(n)$.

**Proof:**
Let $c = 1$, **assume that** $\forall m < n$, $T(m) \leq c\cdot m - 1 = m - 1$. Then:
$$
\begin{align*}
	T(n) &= T(\lfloor n / 2\rfloor) + T(\lceil n / 2\rceil) + 1\\
		 &\leq \lfloor n / 2\rfloor - 1 + \lceil n / 2\rceil - 1 + 1\\
		 &= n - 1\\
\end{align*}
$$

Et voilà! We are done. Again, notice how we assumed $T(m) \leq m - 1$, so our conclusion has to be $T(n) \leq n - 1$.

## A few more involved examples

Let's do 2 more examples demonstrating this method.

#### Example 1:

Let $T(n)$ be a function such that:

$$
T(n) = \begin{cases}
2 \cdot T(\lfloor \frac{n}{4} \rfloor) + 5, & n > 4\\
1, & n \leq 4\\
\end{cases}
$$

Then to show that $T(n) \in O(\sqrt{n})$:

**Proof:**
Let $c = 1$. For all $m < n$, assume that $T(m) \leq c \cdot \sqrt{n} - 5 = \sqrt{n} - 5$. Then:

$$
\begin{align*}
T(n) &= 2\cdot T(\lfloor \frac{n}{4} \rfloor) + 5\\
&= 2\cdot \left(\sqrt{\lfloor \frac{n}{4}\rfloor} - 5 \right) + 5\\
&= 2\cdot \sqrt{\lfloor \frac{n}{4}\rfloor} - 5\\
&\leq 2\cdot \sqrt{\frac{n}{4}} - 5\\
&\leq \frac{2}{\sqrt{4}}\sqrt{n} - 5\\
&\leq \sqrt{n} - 5\\
\end{align*}
$$

#### Example 2:
$$
T(n) = \begin{cases}
2 \cdot T(\lfloor \frac{n}{2} \rfloor) + 2n\log_2(n), & n > 2\\
1, & n \leq 2\\
\end{cases}
$$

Then to show that $T(n) \in O(n \log^2(n))$:

**Proof:**
Let $c = 2$. For all $m < n$, assume that $T(m) \leq c \cdot m\log_2(m) = 2\cdot m\log^2(m)$. Then:
$$
\begin{align*}
T(n) &= 2 \cdot T\left(\lfloor \frac{n}{2} \rfloor \right) + 2n\log_2(n)\\
&\leq 2\left( 2\cdot \frac{n}{2} \log^2\left(\frac{n}{2}\right)\right) + 2n\log_2(n)\\
&\leq 2\cdot n \log^2\left(\frac{n}{2}\right) + 2n\log(n)\\
&\leq 2\cdot n \left(\log(n) - \log_2(2)\right)^2 + 2n\log(n)\\
&\leq 2\cdot n \left(\log^2(n) - 2\log(n) + 1\right) + 2n\log(n)\\
&\leq 2\cdot n \log^2(n) - 4n\log(n) + 2n + 2n\log(n)\\
&\leq 2\cdot n \log^2(n) - 4n\log(n) + 4n\log(n)\\
&\leq  2\cdot n \log^2(n)
\end{align*}
$$

# Program Correctness Via Induction

We will end this unit on a technique for proving that programs are correct via induction. We will not go through very complicated programs, but it would be great to cover some to demonstrate this idea. The section is really a combination of both programming and math, which really is what computer science is all about sometimes.

Let's look at this python program that adds up all the elements in an array.

```python
def adder(arr):
	total = 0
	for i in range(len(arr)):
		total += arr[i]
	return total 
```

Why is this correct? I mean perhaps it's obvious, we're just adding up everything in an array. But we're going to use this simple example so show you how we can actually prove programs are correct via induction. Of course, no sane programmer actually does this for simple programs, but if we were to use an actually complicated program right now, this might be too difficult.

Here's the idea, we want to say that:

1. The program is correct before the $0^{th}$ iteration.
2. For $i$ from $0$ onwards, if before the $i^{th}$ iteration the program was "correct", then after the $i^{th}$ iteration it is also correct.

Does this look familiar? It does look like our induction base case and inductive cases! And again, we are going to look at proof formats that closely mimic this.

We wish to claim the following:

> At the start of the $i^{th}$ iteration (where $i$ starts from $0$), `total` is the sum of elements in the subarray $arr[0\ldots (i - 1)]$, i.e., `total` is equal to $\sum_{j = 0}^{i - 1}arr[j]$.

![[invariant.svg]]

As an example with an array that holds $[5, 6, 11]$, think about how before the iteration where $i = 0$, `total` is $0$ (because the subarray $arr[0\ldots -1]$ is empty). 
- Before the iteration where $i = 1$, `total` is $5$, which is the sum of elements in the subarray $arr[0\ldots 0]$. 
- Before the iteration where $i = 2$, `total` is $5 + 6 = 11$, which is the sum of elements in the subarray $arr[0\ldots 1]$. 
- Before the iteration where $i = 3$, `total` is $5 + 6 + 11 = 22$, which is the sum of elements in the subarray $arr[0\ldots 2]$. 
This also means that when $i = 3$, our program has effectively computed the sum of the entire array!

We call this statement that is always true throughout the run of the program as the **invariant**. So how do we justify the statement?

Here's an inductive proof that does that.

1. (**Initialisation**) When $i = 0$, the subarray $arr[0\ldots -1]$ is empty. There are no elements, and thus the sum of an empty array is $0$. Since $total$ is $0$, so the invariant is true before the iteration where $i = 0$.

2. (**Maintenance**) Assume that at the start of the $i^{th}$ iteration (where $i$ starts from $0$), $total$ is the sum of elements in the subarray $arr[0\ldots (i - 1)]$, or $\sum_{j = 0}^{i - 1} arr[j]$.
   
   Then, during the $i^{th}$ iteration, $total$ is updated to $total + arr[i]$. Thus, by our assumption, the new updated value of $total$ is $\sum_{j = 0}^{i - 1} arr[j] + arr[i] = \sum_{j = 0}^{i} arr[j]$.

3. (**Termination**) The loop terminates when $i = len(arr)$. Thus, $total = \sum_{j = 0}^{len(arr) - 1} arr[j]$, which is the sum of the entire array.

Here's the intuition behind why this proof works: We're saying that assuming it maintained our invariant before the $i^{th}$ iteration, we just need to maintain the invariant so that it is still true after the $i^{th}$ iteration. Since when the loop ends, $i = len(arr)$, the invariant helps us argue that `total` is the sum of the entire array.


Let's do two other examples to demonstrate this idea.

#### Example 1: Finding Minimum in an Array

Let's say we wanted to tell if a value is an array, we could also write it like this:

```python
def find_min(arr):
	value = arr[0]
	for i in range(1, len(arr)):
		 value = min(arr[i], value)
	return value
```

Then, to prove this is correct, we will use the following invariant:

> At the start of the $i^{th}$ iteration, `value` is the smallest of elements in the sub-array $arr[0\ldots (i - 1)]$.

1. (**Initialisation**) When $i = 1$, the subarray $arr[0\ldots 0]$ has a single element. Since `value` is set to $arr[0]$, the invariant is true.

2. (**Maintenance**) Assume that at the start of the $i^{th}$ iteration (where $i$ starts from $1$), `value` is the smallest of elements in the sub-array $arr[0\ldots (i - 1)]$.
   
   Then, during the $i^{th}$ iteration, `value` is updated to $\min(value, arr[i])$. Thus, by our assumption, the new updated value of `value` is $\min(arr[0\ldots(i - 1)], arr[i]) = \min(arr[0\ldots i])$.

3. (**Termination**) The loop terminates when $i = len(arr)$. Thus, `value` is set to $\min(arr[0\ldots len(arr) - 1])$, which is the minimum of the entire array.

Pictorially, here's how the maintenance is done.
![[find-min-inv.svg]]





#### Example 2: Selection Sort

Let's try something a little more involved, let's re-visit the sorting program at the beginning, and prove that it actually does correctly sort.


```python
def find_min_index(arr, starting_idx):
	min_index = starting_idx
	for index2 in range(starting_idx + 1, len(arr)):
		if arr[min_indx] < arr[index2]:
			min_index = index2
	return min_index

def sorter2(arr):
	for index1 in range(len(arr) - 1):
		min_index = find_min_index(arr, index1)
		arr[min_index], arr[index1] = arr[min_index], arr[index1]
```

Let's assume that `find_min_index` correctly finds the index of the minimum element in the subarray $arr[starting\_idx \ldots len(arr) - 1]$. Then we just want to prove that `sorter2` is correct as a sorter.

So what should our invariant be? 

![[selection-inv.svg]]

So the idea is that since $arr[0\ldots(i-1)]$ is sorted, we should try to find the item that belongs in the $i^{th}$ slot, which happens to be the smallest element in the subarray $arr[i\ldots(len(arr) - 1)]$.

> At the start of the $i^{th}$ iteration, the subarray $arr[0\ldots(i-1)]$ is sorted and contains the $i$ smallest elements of the entire array $arr[0\ldots (len(i) - 1)]$.

So let's look at the proof:

1. (**Initialisation**) When $i = 0$, the subarray $arr[0\ldots -1]$ is empty. Therefore, it is "trivially" sorted and contains the $0$ smallest elements of the entire array.

2. (**Maintenance**) Assume that at the start of the $i^{th}$ iteration, the subarray $arr[0\ldots(i-1)]$ is sorted and contains the $i$ smallest elements of the entire array $arr[0\ldots (len(arr) - 1)]$.
   
   Then at the $i^{th}$ iteration, let the smallest element of $arr[i\ldots (len(arr) - 1)]$ be called $x$. Now, by our assumption:
   
   (1) Since $arr[0\ldots (i - 1)]$ has the $i$ smallest elements of the array. We can say that $arr[0\ldots(i-1)] \leq x$. So if we put $x$ in the $i^{th}$ position, $arr[0\ldots i]$ is sorted.
   
   (2) Furthermore, since $x$ is the smallest element of $arr[i\ldots (len(arr) - 1)]$, if we put $x$ in the $i^{th}$ position, $arr[0\ldots i]$ now contains the smallest $i + 1$ elements in the array. 

3. (**Termination**) The loop terminates when $i = len(arr)$. Thus, by our invariant, $arr[0\ldots (len(arr) - 1)]$ is sorted.