---
title: "Unit 9: Probability Distributions, Expectation, Variance, Deviations"
---
# Overview

This unit is the second of two parts in our introduction to probability. Again, the ideas here are pretty fundamental when it comes to things like analysing randomised strategies or algorithms, something that is quite common in machine learning.

To tie it all up, we'll introduce probability distributions, talk about expected values and variances, and motivate them with some common bounds we commonly use in computer science.

# Introduction

Picking up from where we last left off, we focused a lot on probability spaces, events, how to compute a bunch of stuff like conditional probability, and we mostly assumed things were uniform or independent. Extending off of this, we'll first talk about random variables and probability distributions. What we will show in this unit are the staple approaches to randomised analysis. If you were ever curious how something like the [multiplicative weights update algorithm works](https://en.wikipedia.org/wiki/Multiplicative_weight_update_method), the techniques shown in this page are a must.

# Random Variables

For starters, let's talk about random variables. Think of random variables as basically values that we care about. Now this might seem pretty abstract, so before we go into an example, think of random variables as functions that **take as input** outcomes, and **outputs values**.

## An Example With Coins


### Defining Random Variables
Let's go back to using coins. Let's say we had 3 fair and independent coins. So each coin produces either heads or tails, with probability $\frac{1}{2}$, and all 3 coins' outcomes do not affect each other.

We know that we have 8 possible outcomes, so our sample space looks like the following:

$$
\{HHH, HHT, HTH, HTT, THH, THT, TTH, TTT\}
$$

So here comes the question: What if we wanted to count the number of heads?

Here's how we would do it, we would make a random variable, let's call it $C$. $C$ has to specify for each outcome, what it will output as a number. In this case, since we want to count the number of heads, we can simply wave our hands and declare "let $C$ count the number of heads."

From this, we know that this means for example, that $C(HHH) = 3$, and $C(HTH) = 2$, also $C(TTT) = 0$.

So $C$ is a random variable, that counts the number of heads.

Let's try another question: What if we wanted to **indicate** that the coins were all heads?

Here's how we would do it, we would make a random variable, this time let's call it $D$ so we don't collide our names. $D$ is going to output value $1$ on input $HHH$. I.e. $D(HHH) = 1$. On any other input outcome, $D$ will return $0$. So for example. $D(HHT) = 0$, and $D(HTH) = 0$. Also $D(TTT) = 0$.

$D$ is a special kind of random variable that we commonly call an **indicator random variable**. These modest types of random variables actually do a lot of heavy lifting in computer science. You'll see one such example later in this unit. Think of indicator random variables as **indicating when some event has occurred**.

Both $C$ and $D$ are examples of **random variables**.

### Random Variables vs. Events

Let's look at $C$ again. If we split the sample space up, we notice that we can "break up" or "partition" the sample space based on what value $C$ outputs:

1. For the event $\{TTT\}$, $C$ outputs $0$.
2. For the event $\{HTT, THT, TTH\}$, $C$ outputs $1$.
3. For the event $\{HHT, HTH, THH \}$, $C$ outputs $2$.
4. For the event $\{HHH\}$, $C$ outputs $3$.

So what is $\Pr[C = 2]$? Well it is just the probability that we either see: $HHT$, or $HTH$, or $THH$. In other words:

$$
\Pr[C = 2] = \Pr[HHT] + \Pr[HTH]  + \Pr[THH] 
$$

Since we assumed each coin is fair and independent, each outcome occurs with probability $\frac{1}{2^3}$. There are $3$ such outcomes, so $\Pr[C = 2] = \frac{3}{8}$.

What about $D$? This time around:
1. For the event $\{HHT, HTH, HTT, THH, THT, TTH, TTT\}$, $D$ outputs $0$.
2. For the event $\{HHH\}$, $D$ outputs $1$.

So what is $\Pr[C \leq 1 | D = 0]$? Recall, that:

$$
\Pr[C \leq 1 | D = 0] = \frac{\Pr[C \leq 1 \cap D = 0]}{\Pr[D = 0]}
$$

Now if we look at $\{HTT, THT, TTH, TTT\} \cap \{HHT, HTH, HTT, THH, THT, TTH, TTT\}$ we might notice that this is actually just $\{HTT, THT, TTH, TTT\}$ itself. So $\Pr[C \leq 1 \cap D = 0]$ is $\frac{4}{8}$. What about $\Pr[D = 0]$? Well by a similar argument, it is $\frac{7}{8}$.

So:

$$
\Pr[C \leq 1 | D = 0] = \frac{4/8}{7/8} = \frac{4}{7} 
$$

## Functions on Random Variables

Here's an interesting idea, can we operate on random variables? We sure can! And this idea is super useful. For example, what is $D^2$? It is a random variable that first takes as input $D$, and outputs the square of it.

So for example, we could ask something like: What is $\Pr[D^2 = 1]$?

Let's think about this a little bit. $D$ can only take two possible values: $0$ or $1$. When $D$ outputs $0$, then so does $D^2$. When $D$ outputs $1$, so does $D^2$.

So $\Pr[D^2 = 1]$ is the same as $\Pr[D = 1]$. And similarly, $\Pr[D^2 = 0]$ is the same as $\Pr[D^2 = 0]$. So $\Pr[D^2 = 1] = \frac{1}{8}$.


### Another Example:
Instead of squaring, we can also do something like adding random variables together. Here's an alternative example.

Let $D_1$, and $D_2$ be random variables for a two separate, independent and fair 6-sided die. So again, $D_1$ and $D_2$ each can take values in $\{1, 2, 3, 4, 5, 6\}$.


Then technically, even something like $D_1 + D_2$ is a random variable. And we can ask something like what is $\Pr[D_1 + D_2 = 3]$? This is basically asking what is the probability that sum of the total outcomes we have are $3$?

We know that this means either ($D_1 = 1$ and $D_2 = 2$) or ($D_1 = 2$ and $D_2 = 1$). So:

$$
\Pr[D_1 + D_2 = 3] = \Pr[D_1 = 1 \cap D_2 = 2] + \Pr[D_1 = 2 \cap D_2 = 1] = \frac{1}{6^2} + \frac{1}{6^2} = \frac{1}{18}
$$


# Probability Distributions

Now that we've talked about random variables, the next thing is to finally talk about probability itself. Think of a probability distribution as the function that assigns to each outcome of random variables a probability. Intuitively, you can think of this as a chart that basically says for each outcome what is the probability.


**Example 1:**

![[pr-dist-1.svg]]

**Example 2:**

![[pr-dist-2.svg]]
**Example 3:**

![[pr-dist-3.svg]]


Again, think of a distribution as basically saying "for this value, we assign this probability".

We will look at some very common discrete probability distributions in CS:

1. Bernoulli
2. Geometric
3. Binomial
4. Uniform

## Bernoulli Distribution

So let's begin with the Bernoulli distribution. This is the distribution for **indicator random variables**. Again, recall that since indicator random variables only take values $0$ or $1$, the Bernoulli distribution has to assign a probability $p$ for when $X = 1$, and consequently, this means $X = 0$ with probability $1 - p$. Think of $p$ as the **parameter** of the distribution. This single value determines the entire distribution.

So to be clear, an indicator random variable $X$ has a Bernoulli distribution $p$ if:

1. $\Pr[X = 1] = p$
2. $Pr[X = 0] = 1 - p$


### Example:

Let’s say we roll 1 fair die, each with 6 faces. And each face is produced with probability 1/6.

So let $X$ be the random variable that **indicates** if the dice turns up with a number that is at least 2. I.e. $X = 1$ if we see a value of $2$ or more.

Then we can say that $\Pr[X = 1] = \frac{5}{6}$. So it follows a Bernoulli distribution with parameter $p = \frac{5}{6}$.

## Geometric Distribution

Let's build off the Bernoulli distribution and make use of it for something else. Given a random variable $X$ that follows a Bernoulli distribution with parameter $p$, let $Y$ be the number of times we need to try $X$ before $X = 1$.


### Example:
As a concrete example, this is as if we are making coin flips, the coin has probability $\frac{1}{3}$ of returning heads, and we are asking: How many times do we need to flip before we see heads? And here we are going to assume that every flip of the coin is independent of its previous outcomes.

To be clear, if $Y$ is a random variable that outputs the number of times we need to try, then $Y$ follows the **geometric distribution**.

So what is the probability that $Y = 1$? Well that happens when the very first flip is heads, which happens with probability $\frac{1}{3}$. 

What about the probability that $Y = 2$? Well that happens with probability $\frac{2}{3}\times \frac{1}{3}$.

What about the probability that $Y = i$? Do you see the pattern? We must have flipped $i - 1$ many tails in a row, then flipped a heads. So the probability is $\left(\frac{2}{3}\right)^{i - 1}\times \frac{1}{3}$.

So in general, if we had a random variable that followed geometric probability distribution with parameter $p$, then $\Pr[Y = i] = \left(1-p\right)^{i - 1}\times p$.

## Binomial Distribution

Let's build off the Bernoulli distribution again, but instead ask a different question. What if we instead had n independent copies of $X$ (each as a Bernoulli distribution with parameter $p$), and we took $n$ trials, and asked: How many copies out of the $n$ trials returned 1?

### Example:
Let's say we had 3 coins, each coin returns heads with probability $1/3$. Let's let $Y$ be the random variable that counts the number of heads. Then again, what's the probability that $Pr[Y = 2]$?

Well one way we could do this is to manually count this. So we know that there are 3 possible outcomes we need: $HHT, HTH, THH$. We know that a heads happens with probability $\frac{1}{3}$, and a tails happens with probability $\frac{2}{3}$. So:

$$
\Pr[HHT] + \Pr[HHT] + \Pr[HHT] = \left(\frac{1}{3}\right)^2\cdot \left(\frac{2}{3}\right) + \left(\frac{1}{3}\right)^2\cdot \left(\frac{2}{3}\right) + \left(\frac{1}{3}\right)^2\cdot \left(\frac{2}{3}\right) = \frac{2}{27}\times 3 = \frac{6}{27}
$$

But what about in general? What if we had more coins than $3$? Manually counting gets very cumbersome. Let's try to be smarter with how we count.

Of the $n$ coins, we choose $i$ of them to be heads, so the rest must be tails. So there are $\binom{n}{i}$ possible outcomes. For each outcome, the probability it occurs is $(p)^i(1-p)^{n - i}$.

So in general, the probability $\Pr[Y = i]$ is actually $\binom{n}{i}(p)^i(1-p)^{n - i}$

To be clear, the binomial distribution takes 2 parameters: $n$, the number of trials, and $p$ the probability of success of each independent trial.


## Uniform Distribution

The last distribution is the uniform distribution. This is the one we have been playing with the most. In general, we have a set of $n$ values, $\{1, 2, \ldots, n\}$. Each value is picked with probability $\frac{1}{n}$.

If we let $Y$ be the random variable that outputs any of the n values uniformly at random. Then $Y$ has the uniform distribution.

# Expectation

Now that we have seen random variables and distributions, here's a key question:

> If we ran an experiment where we had a random variable X, and we took $t$ many **independent** samples, then output the average value, what should we hope/expect to see?


It turns out, the answer is:

$$
\mathbb{E}[X] = \sum_{i} i \cdot Pr[X = i]
$$

Here's the intuition, this is the value we "expect" to see from the random variable.

## Example 1: A fair die

For example, if we roll a 6-sided fair die, what is $\mathbb{E}[X]$? Based on our formula, this happens to be:

$$
E[X]=1⋅\frac{1}{6}+2⋅\frac{1}{6}+ 3⋅\frac{1}{6}+4⋅\frac{1}{6}+ 5⋅\frac{1}{6}+ 6⋅\frac{1}{6}
$$

which evaluates to $7/2$.

Think of it this way, if we rolled this die many, many, many times and took the average value, it should be close to $3.5$.

## Example 2: A Bernoulli Distributed Random Variable

If we have a random variable X that has a Bernoulli distribution with parameter $p=1/5$, what is $\mathbb{E}[X]$? Again, based on our formula, this happens to be:

$$
\mathbb{E}[X] = 0 \cdot \Pr[X = 0] + 1 \cdot \Pr[X = 1] = \Pr[X = 1]
$$

This looks quite surprising, that the expected value is the probability. But this is actually a very useful fact. We use this quite often in computer science!

## Example 3: Payoff Functions

Let’s say we have a contract that with probability 1/3 will pay us 5\$, and with probability 2/3 will pay us nothing (0\$). What is the expected payoff?

Notice here that if we first let $X$ be a Bernoulli distributed indicator random variable with $p = \frac{1}{3}$ where $X = 1$ when we get paid, then our payoff is given as:

$$
5\cdot X
$$

So it boils down to asking what is $\mathbb{E}[5X]$? Since $X$ takes values either $0$ or $1$, then $5X$ takes values either $0$ or $5$. So
$$
\mathbb{E}[5X] = 0 \cdot \Pr[5X = 0] + 5 \cdot \Pr[5X = 5] = 5\cdot\frac{1}{3}
$$

## Properties About Expectation

So the last example actually was a teaser into some nice properties about expectation. We won't prove it in this course, so you can take these as fact (though they are provable).

1. $\mathbb{E}[X + Y] = \mathbb{E}[X] + \mathbb{E}[Y]$
2. If $c$ is a constant, then $\mathbb{E}[cX] = c\mathbb{E}[X]$

As a warning, we cannot generally say that $\mathbb{E}[X\cdot Y] = \mathbb{E}[X] \cdot \mathbb E[Y]$. This is true when $X$ and $Y$ are independent, but otherwise, we have to be careful.

## Example 4: Expectation of Binomial Distributions

Let's go through yet another example, this time we will be asking what is the expected value of a binomially distributed random variable $X$ with parameters $n = 10$ and $p = 1/4$.

If we faithfully followed the formula, we have that:

$$
\mathbb{E}[X] = \sum_{i = 0}^{10} i \cdot \binom{10}{i} \left(\frac{1}{4}\right)^{i}\left(\frac{3}{4}\right)^{10-i}
$$

Except, that looks awfully complicated to analyse! So we're going to pull out a very neat trick, and have our Bernoulli random variables do a lot of heavy lifting for us.

We are going to let $X_i$ be an indicator random variable with parameter $p = \frac{1}{4}$, represent whether the $i^{th}$ trial was a success or not. Then:

$$
X = \sum_{i = 1}^{10} X_i
$$

Why do we want to do this though? Here's the idea, using the property of expectations, we know that:

$$
\mathbb{E}[X] = \mathbb{E}\left[\sum_{i = 1}^{10} X_i \right] = \sum_{i = 1}^{10} \mathbb{E}[X_i] = \sum_{i = 1}^{10} \frac{1}{4} = \frac{10}{4}
$$

Remember, $\mathbb{E}[X_i] = \frac{1}{4}$ because $X_i$ is an indicator random variable with probability $\frac{1}{4}$.

What about for general values of $n$ and $p$? Well then the math becomes:

$$
\mathbb{E}[X] = \mathbb{E}\left[\sum_{i = 1}^{n} X_i \right] = \sum_{i = 1}^{n} \mathbb{E}[X_i] = \sum_{i = 1}^{n} p = np
$$

## Example 5: Expectation of Geometric Distributions

Since we've covered Bernoulli and Binomial, for the sake of completeness let's do Geometric as well. Let $X$ be a geometrically distributed random variable with parameter $p$. The math for this one is a little more involved, so let's jump straight into it. Again, by our definition of expectation, we have that:

$$
\mathbb{E}[X] = \sum_{i = 1}^{\infty} i \cdot \Pr[X = i] = \sum_{i = 1}^{\infty} i \cdot p \cdot (1-p)^{i - 1}
$$

Now this is pretty hard to resolve, so let's work through some magic, first of all:

$$
(1-p)\mathbb{E}[X] = \sum_{i = 1}^{\infty} i \cdot (1-p) Pr[X = i] = \sum_{i = 1}^{\infty} i \cdot p \cdot (1-p) \cdot (1-p)^{i - 1} = \sum_{i = 1}^{\infty} i \cdot p \cdot (1-p)^{i}
$$

So what is $\mathbb{E}[X] - (1-p)\mathbb{E}[X]$? Let me lay it out term by term:

$$
\begin{align*}
\mathbb{E}[X] - (1-p)\mathbb{E}[X] = (1p+&2p(1-p)+3p(1-p)^2+\cdots)\\
									-(&1p(1-p)+2p(1-p)^2+3p(1-p)^3+\cdots)
\end{align*}
$$

If you notice, we're grouping terms based on their power of $(1-p)$. What happens if we subtracted them this way? Then:

$$
\begin{align*}
\mathbb{E}[X] - (1-p)\mathbb{E}[X] = (1p+&2p(1-p)+3p(1-p)^2+\cdots)\\
									-(&1p(1-p)+2p(1-p)^2+3p(1-p)^3+\cdots)\\
									= (1p+&p(1-p)+p(1-p)^2+\cdots)\\
\end{align*}
$$
And the last series is actually geometric! Re-writing this, we get:

$$
\begin{align*}
\mathbb{E}[X] - (1-p)\mathbb{E}[X] &= (1p+p(1-p)+p(1-p)^2+\cdots)\\
&= \sum_{i = 0}^\infty p(1-p)^i\\
&= p\sum_{i = 0}^\infty(1-p)^i\\
&= \frac{p}{1-(1-p)}\\
&= 1\\
\end{align*}
$$

Okay, that was weird, let's also resolve the left hand side:

$$
\begin{align*}
\mathbb{E}[X] - (1-p)\mathbb{E}[X] &= 1\\
p\mathbb{E}[X] &= 1\\
\mathbb{E}[X] &= \frac{1}{p}\\
\end{align*}
$$

So that gives us our expectation, which hopefully is quite intuitive. If we have a coin that returns heads with probability $\frac{1}{3}$, we would expect to flip it 3 times before we see a heads.


# Variance
So expectation was nice and all, and it tells us what the random variable "averages" around, but it doesn’t tell us how spread apart the values are. For that, we need **variance**.

Intuitively, variance is a measure of how much the random variable can vary.

Formally, it is defined as:

$$
Var[X]=E[(X -E[X])^2]
$$
Except this form is not very helpful, so let me show you a more useful form:

$$
\begin{align*}
Var[X] &= E[(X -E[X])^2]\\
&= E[X^2 - 2XE[X] + E[X]^2]\\
&= E[X^2] - 2E[XE[X]] + E[E[X]^2]\\
&= E[X^2] - 2E[X]E[X] + E[E[X]^2]\\
&= E[X^2] - 2E[X]^2 + E[E[X]^2]\\
&= E[X^2] - 2E[X]^2 + E[X]^2\\
&= E[X^2] - E[X]^2\\
\end{align*}
$$

Again, friendly reminder that $E[X^2] = E[X \cdot X]$ and this is in general, not equal to $E[X]^2$.

## Example 1: Variance of a Bernoulli Distributed Random Variable

For example, given a Bernoulli distributed random variable $X$ with probability $p$, what is $Var[X]$? We know that $E[X] = p$, so we know that $E[X]^2 = p^2$. But what is $E[X^2]$?

So we've done this before! $X$ can only take value $1$ with probability $p$ or $0$ with probability $1 - p$. So similarly, $X^2$ can only take value $1$ with probability $p$ or $0$ with probability $1 - p$.

So again:
$$
E[X^2] = 0^2 \cdot \Pr[X = 0] + 1^2 \cdot \Pr[X = 1] = \Pr[X = 1] = p 
$$

So, putting the two together:

$$
Var[X] = E[X^2] - E[X]^2 = p - p^2 = p(1-p)
$$
## Example 2: Variance of a Binomially Distributed Random Variable


As another example, what about the variance of a binomially distributed random variable $X$ with $n$ trials, and probability $p$? Again, let's fall back to the neat trick that I mentioned, let $X_i$ be an indicator that indicates whether the $i^{th}$ was a success. In which case:

$$
X = \sum_{i = 1}^n X_i
$$

So now:

$$
\begin{align*}
X^2 = \left(\sum_{i = 1}^n X_i\right)^2 &= \left(\sum_{j = 1}^n X_i\right)\left(\sum_{i = 1}^n X_i\right)\\
&= \left(\sum_{i = j}^n X_i \cdot X_j\right) + \left(\sum_{i \neq j}^n X_i\cdot X_j\right)\\
\end{align*}
$$

If this is not obvious, think about how $(X_1 + X_2 )(X_1 + X_2)$ can be written as $(X_1)^2 + (X_2)^2+ X_1 \cdot X_2 + X_2 \cdot X_1$.

Now again, we want $\mathbb{E}[X^2]$, so:

$$
\begin{align*}
E[X^2] &= \left(\sum_{i = j}^n E[X_i \cdot X_j]\right) + \left(\sum_{i \neq j}^n E[X_i\cdot X_j]\right)\\
\end{align*}
$$

Now let's look at what's going on in each sum separately. The first sum, sums over $X_i\cdot X_j$ when $i = j$, so this is just the same as $\sum_{i = 1}^n E[(X_i)^2]$. As before, we know that since $X_i$ is an indicator random variable,  $E[(X_i)^2] = p$. So:

$$
\begin{align*}
E[X^2] &= \left(\sum_{i = j}^n E[X_i \cdot X_j]\right) + \left(\sum_{i \neq j}^n E[X_i\cdot X_j]\right)\\
&= np + \left(\sum_{i \neq j}^n E[X_i\cdot X_j]\right)\\
\end{align*}
$$

What about $E[X_i \cdot X_j]$ when $i \neq j$? Since $X_i$ and $X_j$ both only output either $0$ or $1$. Then, $X_i \cdot X_j$ is $1$ only when both $X_i$ and $X_j$  are $1$, otherwise, it is $0$. So now:

$$
E[X_i \cdot X_j] = \Pr[X_i \cdot X_j = 1] = \Pr[X_i = 1 \cap X_j = 1]
$$

since $X_i$ and $X_j$ are independent, we know that $\Pr[X_i = 1 \cap X_j = 1] = p^2$
So putting this back into the sum:

$$
\begin{align*}
E[X^2] &=  np + \left(\sum_{i \neq j}^n E[X_i\cdot X_j]\right)\\
&=  np + \left(\sum_{i \neq j}^n p^2\right)\\
&=  np + (n)(n-1)p^2\\
\end{align*}
$$

So finally, putting this back in:

$$
Var[X] = E[X^2] - E[X]^2 = np + (n)(n-1)p^2 - (np)^2 = n(p)(1-p)
$$




## Summary:

So we have that:

1. Bernoulli distributed random variables: $p(1-p)$
2. Binomially distributed random variables: $np(1-p)$
3. Geometrically distributed random variable: $(1-p)/p^2$

We will skip the proof for geometric random variables because it involves using some amount of calculus.
## Properties of Variance:

1. $Var[cX] = c^2 Var[X]$
2. If $X$ and $Y$ are independent random variables, then $Var[X + Y] = Var[X] + Var[Y]$

# Bounds
So we've worked quite hard to figure out what the expectation and variance are for random variables. But why? What's so important about these things?

In computer science, we often have “bad” events that we want to avoid. For example, long running times in las vegas algorithms, errors in classification, hashing collisions, and so on. Anytime there is any amount of randomness, we will have to somehow argue that bad events don't happen too often. Hopefully you'll see what I mean, beyond this course when you finally use these ideas.

So to do so, we commonly use Markov and Chebyshev bounds! These bounds are great if we are happy with a good enough, one-sided upper bound on the probability. Typically we will be finding the probabilities of bad events and saying they don't occur to often. So in CS at least, these are great.
## Markov Bound:

If $X$ is a non-negative random variable, and $a > 0$, then:
$$
\Pr[X \geq a]\leq \frac{E[X]}{a}
$$

For example, if $X$ is a binomially distributed random variable with n trials and success probability $p=0.4$. We can say something like:

$$
\Pr[X \geq 20] = \sum_{i = 20}^n \binom{n}{i}(0.4)^i(0.6)^{n - i}
$$

But this hard to analyse, and is not even in a closed form. What if we could sacrifice some amount of clarity for an easier bound to work with? So if we instead applied Markov's bound, we have:

$$
\Pr[X \geq 20] \leq \frac{E[X]}{20} = \frac{n(0.4)}{20} 
$$

So for something like $n = 10$, this works out to be $\frac{1}{5}$. See how simple that was? **Sometimes** an imprecise answer is good enough.  Markov bound is one such way to get a “good enough” imprecise answer.



## Chebyshev Bound:

If $X$ is a random variable, then:
$$
\Pr[|X - E[X]| \geq a]\leq \frac{Var[X]}{a^2}
$$

For example, if $X$ is a binomially distributed random variable with $n = 100$ trials and success probability $p=0.4$. We can say something like:

$$
\Pr[|X - 40| \geq 20] = \left(\sum_{i = 0}^{19} \binom{n}{i}(0.4)^i(0.6)^{n - i} \right) + \left(\sum_{i = 61}^{100} \binom{n}{i}(0.4)^i(0.6)^{n - i} \right)
$$


But again, this is a lot simpler if we could use Chebyshev to say something like (assuming we are happy with a good enough, one-sided bound):
$$
\Pr[|X - 40| \geq 20]\leq \frac{100(0.4)(0.6)}{20}
$$





