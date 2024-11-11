---
title: A Note on Linearity of Expectations
tags:
  - notes
hidden: true
---
In this note, we will introduce linearity of expectation for discrete random variables, how it's used, why it's useful, and **very important subtleties**. Along the way, we'll prove a few useful things you might see in computer science.

We will assume you possess basic knowledge on what a discrete random variable is. Nothing formal here, we won't be fully using the axiomatic method here but we'll at least give a little formalism here because it will be useful to see things in this new light. Just bear in mind we won't be going 100% formal, but just a taster of how to be a little more well-founded in what we do.
# Introduction
You should think random variable $X$ as a variable that takes on potentially more than one value (it could also be just one value but that's not very random nor interesting, is it?).

So $X$ has a set of values $E$ that it can take on, think of this as the set of possible events $E$. Furthermore, for each value $e \in E$, we want to associate with it a value $p_e$. You can now see this as a function $P : e \to \mathbb{R}$. There are a few more requirements about these values.

1. $P(e) \geq 0$, $\forall e \in E$.
2. $\sum_{e \in E} P(e) = 1$

In fact, we use $\Pr[X = e]$ as notation for $P(e)$.

Did you notice we basically just called it a function? Here's the idea, we have some kind of phenomenon in real life we wish to model, but there's some degree of uncertainty we have about that phenomenon. For example, something like "Which face of a dice will be on the top?" after we roll it. We would like to assign each outcome $1,2,3,4,5,6$ individually with a number in $\mathbb{R}$. What kind of number? Well it has to satisfy the constraints laid out above. For example, if we know the dice is "fair", to model that dice using our mathematical objects we would say $\Pr[X = i] = \frac{1}{6}, \forall i \in \{1, 2, 3, 4, 5, 6\}$. If the dice was loaded and unfair instead we might assign different values to each outcome.

>[!Note]
> Now to be clear _these are not axioms of probability_, rather, these requirements actually follow from the actual axioms of probability which I will not show because it is rather complicated. But you may treat this as the foundation on which we will start. Like how it might feel to learn Python instead of C, where the low-level details have been done for you, and you're here to think about higher level details.
> 
> Anyway, there's always the abstract question of "what does it mean for a phenomenon to have some probability?". There's the whole Frequentist vs Bayesian debate (that's a whole big can of worms). So I just want you to appreciate the fact that at a very abstract level: we are just assigning numbers from our set of events $E$ to real values that satisfy the constraints that I mentioned.

Now technically speaking, there's one more thing I should mention: A random variable is not the same as its distribution. A **distribution** is basically the function $P : E \to \mathbb{R}$ that satisfies the properties I mentioned. A **random variable** needs to take a distribution. Think of a variable as an _instance_. You could have two random variables $X_1, X_2$ that are identically distributed (they have the same function $P$ but potentially different outcomes). We will say two random variables are **identically distributed** if they have the same distribution function $P$.

For example, if we had 2 perfect copies of the same fair, perfect, independent coin, then we could say there's two random variables $C_1, C_2$ that both have the same distribution where $\Pr[C_1 = head] = \Pr[C_1 = tail] = \frac{1}{2}$.

Lastly, we will call a random variable discrete, if the event set $E$ is discrete.
# Expected Value of a Random Variable
So given a discrete random variable $X$, one thing we might want to ask is "What is the expected value?". We will use $\mathbb{E}[X]$ to denote this value. First of all, the interesting thing about the expected value is that we can prove (as a separate theorem) that if we took $n$ trials of measuring $X$, you can think of this as $X_1, X_2, X_3, \ldots, X_n$ where they are all identically distributed as $X$ and all fully independent of each other, and we measured the value $\frac{\sum_{i = 1}^t X_i}{n}$ then this will converge to $\mathbb{E}[X]$ as $n \to \infty$. So here, we care about random variables $X$ that take on values in $\mathbb{R}$. i.e. the event set of $X$ are values we can add and divide.

Does this mean $X$ is most likely to take on value $\mathbb{E}[X]$? No. But nonetheless it tells us that if we are happy with many trials of $X$, the "average value" that we will see, should be close to $\mathbb{E}[X]$.

The definition of the expectation of a random variable $X$ is given as:
$$
\mathbb{E}[X] = \sum_{a \in E} a \cdot \Pr[X = a]
$$

Now, there are other possible and equivalent formulations (shown as theorems) but we'll stick with this one. Also, perhaps it's pretty intuitive why this is the right definition. For example, we expect to see value $a$, about $\Pr[X = a]$ fraction of the time.

So for example, if we let a coin $C$ be such that $Pr[C = 1] = p$, and $Pr[C = 0] = 1 - p$, then the expected value $\mathbb{E}[C] = 1 \cdot p + 0 \cdot (1 - p) = p$.

As another example, a dice $D$ with uniform probability of taking values $1, 2, 3, 4, 5, 6$ will yield $\mathbb{E}[D] = \sum_{i = 1}^6 \frac{i}{6} = \frac{6(7)}{2} \cdot \frac{1}{6} = \frac{21}{6}$.

# Conditioning Random Variables
Now if all we had to study was single random variables, this would not be so interesting. Let's consider the following scenario: We have a bag that has 5 balls with the following values: $1, 2, 2, 8, 8$.

And we want to draw two balls without replacement, and output their values. There's two ways we model this:

##### Method 1: Directly creating a single random variable.
One way is to make a single random variable $B$ that takes on $1$ of $5$ possible values: $3, 4, 9, 10, 16$, like so:

1. $\Pr[B = 3] = \frac{1 \times 2 + 2 \times 1}{5 \times 4} = \frac{4}{20} = \frac{1}{5}$. Either take the $1$-ball first, then either of the $2$-balls, or the other way around.
2. $\Pr[B = 4] = \frac{2 \times 1}{5 \times 4} = \frac{1}{10}$. You have to take both of the $2$-balls.
3. $\Pr[B = 9] = \frac{1 \times 2 + 2 \times 1}{5 \times 4} = \frac{4}{20} = \frac{1}{5}$. Either take the $1$-ball first, then either of the $8$-balls, or the other way around.
4. $\Pr[B = 10] = \frac{2 \times 2 + 2 \times 2}{5 \times 4} = \frac{8}{20} = \frac{2}{5}$. Either take one of the $2$-balls first, then either of the $8$-balls, or the other way around.
5. $\Pr[B = 16] = \frac{2 \times 1}{5 \times 4} = \frac{1}{10}$. You have to take both of the $8$-balls.

Then from this you can also do stuff like find $\mathbb{E}[B]$.

##### Method 2: Creating two random variables instead.
We can instead create two random variables $B_1$ that models the first draw, and $B_2$ that models the second. However, there are very important subtleties that crop up in linearity of expectation later on, so pay some attention here.

$B_1$'s distribution looks like this:
1. $\Pr[B_1 = 1] = \frac{1}{5}$
2. $\Pr[B_1 = 2] = \frac{2}{5}$
3. $\Pr[B_1 = 8] = \frac{2}{5}$

But what about $B_2$? To be clear we cannot just say that $B_2$'s distribution is the same as $B_1$. In some sense, because $B_2$'s outcome depends on $B_1$. To be clear, we want to figure out what $\Pr[B_2 = 1], \Pr[B_2 = 2], \Pr[B_2 = 8]$ are.

Now, $\Pr[B_2 = 1] = \Pr[B_1 = 1 \cap B_2 = 1] + \Pr[B_1 = 2 \cap B_2 = 1] + \Pr[B_1 = 8 \cap B_2 = 1]$. Think of this as saying: The probability that $B_2$ takes value $1$ is the sum of the probability of all the possible cases of what $B_1$ takes.

If that is not so convincing, you can think of it the following way:
$$
\begin{align*}
\Pr[B_2 = 1] =& \Pr[B_2 = 1 | B_1 = 1] \cdot \Pr[B_1 = 1]\\
&+ \Pr[B_2 = 1 | B_1 = 2] \cdot \Pr[B_1 = 2]\\
&+ \Pr[B_2 = 1 | B_1 = 8] \cdot \Pr[B_1 = 8]
\end{align*}
$$

Which is to say, either $B_1$ is $1$ with some probability, then **conditioned** on that probability, $B_2$ takes $1$ with some probability (accounting for the fact that the first ball drawn was $1$). So filling in these values, we get it to be:

$$
\begin{align*}
\Pr[B_2 = 1] =& 0 \cdot 1 + \frac{1}{4} \cdot \frac{2}{5} + \frac{1}{4} \cdot \frac{2}{5}\\
=& \frac{4}{4 \times 5}\\
=& \frac{1}{5}
\end{align*}
$$
Now isn't that curious? Somehow it's the same value. Indeed if you worked this out for $\Pr[B_2 = 2], \Pr[B_2 = 8]$, you get:

$$
\begin{align*}
\Pr[B_2 = 2] =& \Pr[B_2 = 2 | B_1 = 1] \cdot \Pr[B_1 = 1]\\
&+ \Pr[B_2 = 2 | B_1 = 2] \cdot \Pr[B_1 = 2]\\
&+ \Pr[B_2 = 2 | B_1 = 8] \cdot \Pr[B_1 = 8]\\
=& \frac{2}{4} \cdot \frac{1}{5}\\
&+ \frac{1}{4} \cdot \frac{2}{5}\\
&+ \frac{2}{4} \cdot \frac{2}{5}\\
=& \frac{2}{20} + \frac{2}{20} + \frac{4}{20} = \frac{8}{20} = \frac{2}{5}
\end{align*}
$$

Also, $\Pr[B_2 = 8]$ works in similar way.
Crazy isn't it? Why is $B_2$ identically distributed to $B_1$? 

> [!Question]
> **What? I don't get it. Why does $B_2$ look like this?**
> Okay, I need you to think in the following way: We drew two balls without replacement, let's call it $b_1$, $b_2$. But then we threw the first ball $b_1$ away and only looked at the second ball $b_2$. It's a little trippy but this actually has the same distribution if we drew two balls without replacement, and then threw away the second ball $b_2$ and only looked at the first ball $b_1$.

In general for any distribution here's the idea (let's just do it for 2 draws without replacement):
Let $S$ be a set of items $\{s_1, s_2, \ldots, s_n\}$, with frequencies $freq : S \to \mathbb{Z}^+$. Let $T = \sum_{s \in S} freq(s)$. $T$ is basically the total number of items.

For example, with balls $1, 2, 2, 8, 8$, then $S = \{1, 2, 8\}$, and $freq(1) = 1$,  $freq(2) = 2$, and $freq(8) = 2$. Then $T = 5$. 

Okay we first think to note: Let $X_1$ be the first draw from the set $S$ based on their frequencies.  Then $\Pr[X = i] = \frac{freq(i)}{T}$. Let's consider sets $S$ where $T \geq 2$. I.e. There are at least $2$ items to draw or else we cannot make a second draw in the first place.

The question is what is $X_2$. So in general:

$$
\begin{align}
\Pr[X_2 = i] &= \sum_{s \in S} \Pr[X_2 = i | X_1 = s] \cdot \Pr[X_1 = s]\\
			 &= \Pr[X_2 = i | X_1 = i] \cdot \Pr[X_1 = i] + \sum_{s \in S, s \neq i} \Pr[X_2 = i | X_1 = s] \cdot \Pr[X_1 = s]\\
			 &= \frac{freq(i) - 1}{T - 1} \cdot \frac{freq(i)}{T} + \sum_{s \in S, s \neq i} \frac{freq(i)}{T - 1} \cdot \frac{freq(s)}{T}\\
			 &= \frac{freq(i) - 1}{T - 1} \cdot \frac{freq(i)}{T} + \frac{freq(i)}{(T - 1)T} \sum_{s \in S, s \neq i}  freq(s)\\
			 &= \frac{freq(i) - 1}{T - 1} \cdot \frac{freq(i)}{T} + \frac{freq(i)}{(T - 1)T} (T - freq(i))\\
			 &= \frac{freq(i)}{T(T-1)}\bigg( freq(i) - 1 + \big(T - freq(i)\big)\bigg)\\
			 &= \frac{freq(i)}{T(T-1)}\bigg( T - 1 \bigg)\\
			 &= \frac{freq(i)}{T}
\end{align}
$$

That looks _suspiciously_ like $\Pr[X_1 = 1]$ innit?

>[!Explanation]-
>Line 1 follows from Bayes' theorem.
>
>Line 2 from splitting the sum based on whether $s = i$ or not. We need to treat them differently.
>
>Line 3 follows from the fact that given $X_1 = i$, there are $freq(i) - 1$ copies of $i$ remaining, and the total is reduced down to $T - 1$.
>
>Line 3 also follows from the fact that given $X_1 = i$ where $i \neq s$, there are still $freq(i) - 1$ copies of $i$ remaining, and the total is reduced down to $T - 1$.
>
>Line 4 just factors out the portions independent of $s$.
>
>Line 5 follows from the fact we're adding up all the frequencies except $freq(i)$ so this is just the total without $freq(i)$, or $T - freq(i)$.
>
>Line 6 onwards is just basic algebra.

**Now to be very clear:** $B_1$ and $B_2$ are **not** independent. Why? $\Pr[B_1 = 1 \cap B_2 = 1] = 0$ but $\Pr[B_1 = 1] \cdot \Pr[B_2 = 1] = \frac{1}{25}$. So $\Pr[B_1 = 1 \cap B_2 = 1] \neq \Pr[B_1 = 1] \cdot \Pr[B_2 = 1]$, which is enough to argue that $B_1$ and $B_2$ are not independent.

# Linearity of Expectation
Okay, given what we know from the previous section, we can now ask the following question:
What is the expected value of the sum of the values of the two balls drawn? Well if you used [[#Method 1 Directly creating a single random variable.|method 1]] from above, then you'd just have to do $3 \times \frac{1}{5} + 4 \times \frac{1}{10} + 9 \times \frac{1}{5} + 10 \times \frac{2}{5} + 16 \times \frac{1}{10}$.

Or you could use [[#Method 2 Creating two random variables instead.|method 2]], and now you know that $B_1$ and $B_2$ are identically distributed, so you really just need to find $\mathbb{E}[B_1]$. This happens to be a lot simpler: $1 \times \frac{1}{5} + 2 \times \frac{2}{5} + 8 \times \frac{2}{5}$. Then, if we believe in linearity of expectations, we know that 

$$
\mathbb{E}[B_1 + B_2] = \mathbb{E}[B_1] +  \mathbb{E}[B_2] = 2 \times \mathbb{E}[B_1] = 2 \times \left( 1 \times \frac{1}{5} + 2 \times \frac{2}{5} + 8 \times \frac{2}{5} \right)
$$

#### What if the two draws were with replacement?
Well then I hope you know that definitely $B_1$ and $B_2$ are identically distributed. And furthermore, if the draws were with replacement (and both draws were done the same way), then $B_1$ and $B_2$ are independent. So the above equation still holds!

# Proof of Linearity of Expectation
Again, we want to show something like given two random variables $X, Y$, that may or may not be independent, $\mathbb{E}[X + Y] = \mathbb{E}[X] = \mathbb{E}[Y]$.

So why does it not matter if two variables are independent or not? Let's see:
 $$
 \mathbb{E}[X + Y] = \sum_a \sum_b (a + b) \Pr[X = a, Y = b]
$$
Now because $X, Y$ are not necessarily independent, we cannot write $Pr[X = a, Y = b] = \Pr[X = a] \cdot \Pr[Y = b]$. However, let me split the sum into two summations first.

 $$
 \begin{align*}
 \mathbb{E}[X + Y] &= \sum_a \sum_b (a + b) \Pr[X = a, Y = b]\\
 &= \sum_a \sum_b  a \cdot \Pr[X = a, Y = b] + \sum_a \sum_b b \cdot \Pr[X = a, Y = b]\\
 &= \sum_a a \cdot \sum_b  \Pr[X = a, Y = b] + \sum_b b \cdot \sum_a \Pr[X = a, Y = b]\\
 \end{align*}
 $$
Now there's two parts we need to handle, but they're handled with the same idea: If we fix $a$, and said $X = a$, then summing across all $\Pr[X = a, Y = b]$, where we vary the value $b$, then the value is actually just $\Pr[X = a]$. Think of it this way, $\Pr[X = a]$ can be broken up into disjoint parts $\Pr[X = a, Y = 1], \Pr[X = a, Y = 2],\Pr[X = a, Y = 3], \ldots$ and so on. If we added them all back up, we just get $\Pr[X = a]$ again. Below is an example of this intuition with $Y$ taking on $7$ possible values:

![[Images/loe-intuition.png]]
 
So because of that:
$$
\sum_a a \cdot \sum_b  \Pr[X = a, Y = b] = \sum_a a \Pr[X = a] = \mathbb{E}[X]
$$
 
 and likewise: 
$$
\sum_b b \cdot \sum_a  \Pr[X = a, Y = b] = \sum_b b \Pr[Y = b] = = \mathbb{E}[X]
$$
which means the original two parts just becomes $\mathbb{E}[X] + \mathbb{E}[Y]$.

# Where do we use Linearity of Expectations in CS?
Many places! I will show you a few things that you might see in CS2040S, and CS3230.