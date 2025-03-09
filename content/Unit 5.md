---
title: "Unit 5: Algorithmic Analysis, Big Oh Terminology"
---
# Overview

In this unit, we'll be giving big motivations for [[Unit 4]] by doing 2 things:

1. Showing Big-Oh, Omega, Theta terminology. (Asymptotic Notation)
2. Bounding recurrences and general functions.
3. Showing how induction is used in the context of computer science.

Think of this as a big culmination of the reason we learned logic, proofs, induction, and logical statements. After this point, we will be focusing on a different branch of topics.

# Asymptotic Notation

## Some Motivating Scenarios

Let's begin with an example. Let's say that we wrote this python program that just counts how many even numbers there are.

```python
def count_even(arr):
	count = 0
	for x in arr:
		if x % 2 == 0:
			count += 1
	return count
```

How long does this program take?

You could perhaps plot a graph, where the x-axis is the size of the array. And the y-axis is how long it takes for this program to run. We could also write similar C++ and maybe even Java code that all does something like this.

And let's pretend that we ran some experiments, and plotted some graphs to find out how long they take. Then maybe we'd get something like this:

![[example-plot.svg]]

Notice they all kind of look like straight lines. Like linear functions. Why? Because intuitively, no matter the programming language the 3 of them would be following the same idea: Start from the first item, go through each item until the last, and for each of them, we do a check to see if it's even or not. In some sense, if we had $n$ items, the `for` loop just goes through all $n$ of them.

Depending on the programming language (and even computer hardware), our total time taken might not the same, but we can expect the same linear trend between the time taken, and the array size. We want a say to basically say "no matter the programming language, we expect to see the same linear trend".

This does not just apply to different programming languages, but even **different** approaches to solve the same computational problem.

Here's another example, let's say we wanted to sort numbers in an array. There are many ways of doing this, let's look at 2 possible ways:

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

Here's an idea about how these 2 sorting methods work. The first one basically tries to move the $i^{th}$ element backwards until $arr[i] > arr[i - 1]$. After that, we rinse and repeat with $i + 1$.

![[insertion-sort.svg]]

For example, let's say that we're on the 4th element, we iterate backwards and keep swapping until the $3$ element is greater than the element on its left, which only happens when it's the second element on the array.

How many steps does the program take? Well the inner loop takes **at most** $index1$ many iterations, and $index1$ ranges from $1$ to $n$. So `sorter1` uses at most $1 + 2 + 3 + 4 + \cdots + (n - 1)$ iterations at most.

The second one, on the other hand, repeatedly tries to find the minimum element, before placing it in the correct location.

![[selection-sort.svg]]

How many iterations does this take now? For `index1`, we need to check $n - index1$ values. This means the total iterations are $n + (n - 1) + (n - 2) + \cdots + 1$.

Okay, so both methods have $1 + 2 + \dots = (n)(n + 1)/2$ iterations. But what they do each iteration is not the same! The first one does some swapping, the second one does comparisons and only swaps towards the end. It would be reasonable to think that because of that, even though the number of iterations are the same, the total time taken would be different. Again, a hypothetical plot you might see if we took some experimental values might look something like this:

![[example-plot-2.svg]]

We might expect both sorters to have a **quadratic** relationship between the time taken vs. the array size. So the curves might look like $a\cdot n^2 + b\cdot n + c$ for some constants $a, b, c$.

In both scenarios we've talked about, bear in mind that what we care about is the "rough trend" of running time, as $n$ approaches infinity. In other words, as $n$ grows, what kind of curve does the running time look like?  That is, how much work is done, relative to the input size $n$. Think about this as a form of "scaling".

![[example-plot-3.svg]]

So for example, let's say we had two programs, one of which whose time taken curve is $0.0005n^2 + 0.00000000001n + 2$, and another program whose time taken curve is $3000\log(n)$. Which program is more "efficient"? Typically we want to design solutions that scale well, and that means solutions that handle large scale inputs very well. For that reason, we would like to say the second program is better. But how do we communicate this fact?
## Big $O$ notation
For that reason, it is very common for computer scientists to talk about certain functions using Big $O$ notation. (Sometimes referred to as big Oh notation.) Here's how it works, given a function $f(n)$, then the **set** $O(f(n))$ contains all functions $g(n)$ such that:

$$
\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0 \left[ g(n) \leq c\cdot f(n) \right]
$$

(Think of $\mathbb{R}^+$ as the set of positive numbers. I.e. anything greater than $0$.)

Also, we will only ever consider functions $f(n)$ that are always positive. I.e. $\forall n \in \mathbb{N}[f(n) > 0]$.

So for example, if $f(n) = n$, then the set $O(f(n)) = O(n)$. And this set **contains** functions like $g(n) =5\cdot n$, or functions like $g(n) = 6\cdot \sqrt{n}$, $g(n) = 20\cdot \log(n)$. On the other hand, functions like $g(n) = n^2$ are not in the set $O(n)$.

Why is this the case? Let's run through the examples.

For a function like $g(n) = 5\cdot n$, how do we argue that $g(n) \in O(n)$?  We need to provide a value $n_0$ and a positive constant $c \in \mathbb{R}$. How about $n_0 = 1$, and $c = 5$. Then $c \geq 1$ and $g(n) \leq 5\cdot f(n)$.

What about something like $g(n) = 6\cdot \sqrt{n}$, how do we argue that $g(n) \in O(n)$?  We need to provide a value $n_0$ and a positive constant $c \in \mathbb{R}$. How about $n_0 = 1$, and $c = 6$. Then $c \geq 1$ and $g(n)  \leq g(n)^2 \leq 36\cdot f(n)$.

Lastly, consider $g(n) = 20\cdot \log_2(n)$. $20\cdot \log_2(n) \leq 20\cdot 2^{\log_2(n)} \leq 20\cdot n$. So setting $n_0 = 1$ and $c = 20$ would help us justify this.

What about $g(n) = n^2$? Why is that function not in $O(n)$? Remember, to **not** be in the set means the negation of the condition. I.e.

$$
\forall n_0 \in \mathbb{N}, \forall c \in \mathbb{R^+}, \exists n \geq n_0 \left[ g(n) > c\cdot f(n) \right]
$$

So how do we do this? We need to show that no matter the starting point $n_0$, and the multiplier $c$, at some point beyond $n_0$, we will find some value $x$ for which $g(x) > c\cdot f(x)$. Consider any $n_0$, and any positive value $c$. Then we will pick $x = max(c, n_0) + 1$, and claim that for this $x$, $g(n) > c\cdot f(n)$.

$$
\begin{align*}
	g(x) &= g(max(c, n_0)) + 1\\
		 &> g(max(c, n_0))\\
		 &= max(c, n_0)^2\\
		 &\geq c\cdot max(c, n_0)\\
		 &\geq c\cdot x\\
		 &= f(x)
\end{align*}
$$

### Some visual intuition behind Big O

So what's going on here? Let's try plotting out some example graphs.

![[qvl.svg]]

Here, the red curve is $0.05x^{2}+0.6x+1$, the green curve is $x+5$, the blue curve is $2x$, and the purple curve is $\frac{x}{2} + 30$. Here's the idea: no matter the gradient of a linear curve, no matter how large, there will always be a point where the quadratic curve will be larger than it after some point.

So let's look at the definition of big O again, and see how it lines up.

$$
\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0 \left[ g(n) \leq c\cdot f(n) \right]
$$

The $n_0$ here is the point at which $c\cdot f(n)$ starts being larger. But what about the scaling factor $c$? Here's the idea, let's say I had 3 functions $f(n) = 5n$ and $g(n) = 10n$ and $h(n) = 5n + 5$. All of them actually scale the same way: they're all linearly related to $n$.

![[linear-scaling.svg]]

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

Given a function $f(n)$, then the **set** $\Omega(f(n))$ (pronounced "Big Omega") contains all functions $g(n)$ such that:

$$
\exists n_0 \in \mathbb{N}, \exists c \in \mathbb{R^+}, \forall n \geq n_0 \left[ g(n) \geq c\cdot f(n) \right]
$$

Notice that all we have done is flipped the $\leq$ into a $\geq$. So big Omega is basically saying that a function $g(n)$ is "at least" function $f(n)$.

So along those lines, let's look at some examples:

We can say something like $5n \in \Omega(20n)$, we can also say something like $n^2 \in \Omega(\sqrt{n})$. On the other hand, we cannot say something like $1000n \in \Omega\left(\frac{n^2}{1000}\right)$.

## Big Theta

Lastly, given a function $f(n)$, the set $\Theta(f(n))$ is defined to be the set of all functions $g(n)$ such that $g(n) \in O(f(n))$ and $g(n) \in \Omega(f(n))$. In particular:

$$
\Theta(f(n)) = O(f(n)) \cap \Omega(f(n))
$$
## Some properties about asymptotic notation

Now that we have these sets that talk about functions, let's cover some useful properties about them.

Let's start with a function like $0.75n^3 - 10n^2 + 5n + 3000$. Can we say this is $O(n^3)$? After all, intuitively, for large enough $n$, the **dominant** term is $n^3$ here, and the smaller terms like $-10n^2$ and $5n$ start to become insignificant in comparison.

So given a polynomial like the one above, we can find the most dominant term (the one with the highest power), and then drop any constant factors that it comes with, then conclude it is big O of that function. Like in our example above, we identify the $0.75n^3$, and drop the constant factor, thereby concluding the function is in $O(n^3)$.

> [!Claim]
>  Given a degree $k$ polynomial $f(n) = \sum_{i = 0}^k a_i \cdot n^i$ where $a_k > 0$, then $f(n) = O(n^k)$. 

Why is this true? Here's a sketch of the math behind it, we are going to show that $n$ from $n_0$ onwards, $f(n) \leq c\cdot n^k$ for some constant $c$.

**Proof:**
1. Consider a degree $k$ polynomial: $$f(n) = \sum_{i = 0}^k a_i \cdot n^i$$
2. $$
   \begin{align*}
		f(n) &=  \sum_{i = 0}^k a_i \cdot n^i\\
		&\leq  \sum_{i = 0}^k a_i \cdot n^k\\
		&\leq  n^k \cdot \left(\sum_{i = 0}^k a_i \right)\\
		&\leq  n^k \cdot \left(\sum_{i = 0}^k a_i \right)\\
		&\leq  n^k \cdot \max\left(1, \left(\sum_{i = 0}^k a_i \right)\right)\\
   \end{align*}
   $$
   3. So setting $n_0 = 1$ and $c = \max\left(1, \left(\sum_{i = 0}^k a_i \right)\right)$, we are guaranteed that $f(n) \leq c\cdot n^k$. Therefore, $f(n) \in O(n^k)$


In fact, perhaps a little unintuitively, we can also say the following:

> [!Claim]
>  Given a degree $k$ polynomial $f(n) = \sum_{i = 0}^k a_i \cdot n^i$ where $a_k > 0$, then $f(n) = \Omega(n^k)$. 

Why is this true? We are now saying that the function $f(n)$ grows at least as the rate of its highest term. Which intuitively still makes sense, since as $n$ tends to $\infty$, the function is still dominated by the $n^k$ term. But how do we prove this? It may be tempting to prove this in the following way:

**Faulty Proof:**
1. Consider a degree $k$ polynomial:  $$f(n) = \sum_{i = 0}^k a_i \cdot n^i$$
2. $$
   \begin{align*}
		f(n) &=  \sum_{i = 0}^k a_i \cdot n^i\\
		&\geq  a_k \cdot n^k\\
   \end{align*}
   $$
   3. Let $n_0 = 1$, $c = a_k$, then $\forall n \geq n_0 [f(n) \geq c \cdot n^k]$ 

Where did we go wrong? Why is this faulty? Hint: Is line 2 correct?

>[!Answer]-
> For example, consider $f(n) = 10n^2 - 5n$. Can we really say $f(n) \geq 10n^2$ for $n \geq 1$? No we can't!

So instead, we're going to prove a useful lemma first before proving the original statement properly.

**Lemma:**
Let $f(n) = \frac{1}{b}\cdot n^k - an^t$ where $0 \leq t < k$, and $a, b > 0$. Then for all $n \geq a\cdot b$, $f(n) \geq 0$. In other words, $\frac{1}{b}(n^k)$ is greater than or equals to $an^t$.

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

# Bounding Recurrences with Big O

# Program Correctness
