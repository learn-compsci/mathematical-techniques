---
title: "Unit 8: Basic Probability"
---
# Overview

In this unit that is one of 2 parts, we will introduce probability theory. Probability theory is quite fundamental if one wants to analyse different randomised strategies we might have. This is particularly useful in certain parts of machine learning and AI. Ever wondered how [Monte Carlo simulations](https://en.wikipedia.org/wiki/Monte_Carlo_method) work? Ever wondered how chess engines explore such a large state space when figuring out optimal strategies? It turns out when the scale of problems get large enough, randomising your approach might not give you the best solution, but we can hope to maximise our chances of getting something "good enough".

To do this, we first need to talk about the basic fundamentals and rules of probability theory. We will also reason about basic probability in this unit. We will follow this up by introducing very common distributions in the subsequent unit, and finishing off with something called bounds and deviations.

1. [[#Part 0 Introduction|Introduction to probability theory]]
2. [[#Part 1 Probability Spaces, Outcomes and Events|Probability spaces, outcomes and events]]
3. [[#Part 2 Conditional Probability|Conditional probability]]
4. [[#Part 3 Independent Events|Independent events]]

---
# Part 0: Introduction

Let's begin with an example scenario called the **Monty Hall problem**:

You're at a gameshow where there are $3$ doors. One of the doors has an equal chance ($1$ in $3$) of having a car, while the other two doors have a goat behind them. The game goes like this:

1. You can choose any door you wish.
2. After that, of the $2$ remaining doors that you did not pick, the host will pick a door that has a goat, and reveal it to you.
3. The host then offers you a choice: Do you stay on the door you originally picked? Or do you switch over to other door?
4. After you decide which door you want, the host reveals the prize for you at the end of it. If you ultimately chose the door with the car, you win the car. Otherwise, you win the goat.

People have long debated as to what the best strategy is. Should we always stick with our initial door? Should we always switch? Does it even matter? Is it always a $50$/$50$ chance?

Interestingly, we can use probability theory to understand why the strategy of always switching is actually a good strategy. (We will win the car with probability $2$/$3$).

To first understand why, we should probably take a formal approach to this problem.

## Considering the Possible Outcomes

Let's look at the possible outcomes that we might have from this game. For this, let's say:

1. Call the $3$ possible doors $A$, $B$ and $C$.
2. One of the $3$ doors is chosen uniformly at random to contain the car. Let's call this **outcome door $1$**.
3. You have an equal chance of taking any of the $3$ doors uniformly at random. Let's call this **outcome door $2$**.
4. The host will consider one of the two doors you didn't pick, and he will reveal one door that has a goat. Let's call this **outcome door $3$**.
5. Then from there, we need to pick either **outcome door $1$** or **outcome door $3$**.

So let's first think about all of the possible sequence of outcomes:

![[sequence-of-outcomes.svg]]

Think of it this way: if **outcome door $1$** is the same as **outcome door $2$** (i.e., the car was behind door $A$, and we chose door $A$), then the host can reveal either doors $B$ or $C$.

So based on the tree, notice how we can have the sequence of outcomes $(A, A, B)$ or the sequence of outcomes $(A, A, C)$.

On the other hand, if **outcome door $1$** is **not** the same as **outcome door $2$** (i.e., the car was behind door $B$, and we chose door $C$), then the host has only one possible choice to reveal, which is the door that we did not choose, and does not have the car. For example, if the car was behind door $C$, and we chose door $B$, then the host must reveal door $A$.

So based on the tree, we can have a sequence of outcomes like $(C, B, A)$ or $(C, A, B)$, but never something like $(C, A, C)$ or $(C, A, A)$.

So if we listed out of all of the possible sequences of outcomes, we get this list:

$$
\begin{align*}
\{\\
&(A, A, B), (A, A, C), (A, B, C), (A, C, B), (B, A, C), (B, B, A), \\
&(B, B, C), (B, C, A), (C, A, B), (C, B, A), (C, C, A), (C, C, B)\\
\}
\end{align*}
$$

Now we know which outcomes are possible. What we care about is using this to help analyse the probability always switching wins us the car. For that, we first need to identify the **subset** of outcomes that we care about. We call this subset of outcomes **events**.

For example, if we cared about asking "What is the probability that the car is behind door C?" Then the set of outcomes that corresponds to this **event** is $\{ (C, A, B), (C, B, A), (C, C, A), (C, C, B) \}$.

In this case, let's ask ourselves, "If we always choose the option to switch, what is the probability of winning?" Let's first think about which subset events correspond to us winning if we always chose to switch. For example, if the car was behind door $A$, we chose door $B$, and the host was forced to reveal door $C$. Then of the remaining options, we either choose to stay on door $B$ or switch to door $A$, so switching to door $A$ lets us win the car.

Let's think about it a little more, every time we choose a door that is not the car, then switching wins! Either:

1. The car is behind **door $A$**, and if we picked either doors $B$ or $C$, the host will eliminate the other door, so if we switched, we will definitely go back to **door $A$**.
2. The car is behind **door $B$**, and if we picked either doors $A$ or $C$, the host will eliminate the other door, so if we switched, we will definitely go back to **door $B$**.
3. The car is behind **door $C$**, and if we picked either doors $A$ or $B$, the host will eliminate the other door, so if we switched, we will definitely go back to **door $C$**.

![[3-doors.svg]]

Okay, so this means here are the set of outcomes we care about:

$$
\begin{align*}
\{\\
&(A, B, C), (A, C, B), (B, A, C), (B, C, A), (C, A, B), (C, B, A)\\
\}
\end{align*}
$$

## Probability of an Event

Okay so carrying on from the previous part, the next thing to ask is what the probability of obtaining any of these outcomes is. Let's go back to the tree and tag it with probabilities. Recall:

1. Each door has a $1$ in $3$ chance of having the car.
2. Each door has a $1$ in $3$ chance of being picked by us.
3. The host has to pick any door that we did not pick that has a goat to reveal (with equal probability).

So the tree, if we tagged it with probabilities, looks like this:

![[tagged-with-prob.svg]]

The tree is looking a little dense, but here's the idea—what is the probability of the sequence of outcomes $(A, B, C)$? There was a $1/3$ chance of the car being behind door $A$; after that, there is a $1/3$ chance of us picking door $B$; and after that, there is a $1/1$ chance that the host has to reveal door $C$. That's why the edges of the tree look that way. Thus, the total probability is given as:

$$
\frac{1}{3} \times \frac{1}{3} \times \frac{1}{1} = \frac{1}{9}
$$

We could also ask something like "What's the chance that the sequence of outcomes is $(C, C, A)$?" Again, if you check the tree, it happens to be with probability $\frac{1}{3}$ that the car is behind door $C$. After that, there is a $\frac{1}{3}$ chance of us picking door $C$. Then there's a $\frac{1}{2}$ chance of the host picking door $A$. So the total probability is given as:

$$
\frac{1}{3} \times \frac{1}{3} \times \frac{1}{2} = \frac{1}{18}
$$

Once again, the events we care about are:

$$
\begin{align*}
\{\\
&(A, B, C), (A, C, B), (B, A, C), (B, C, A), (C, A, B), (C, B, A)\\
\}
\end{align*}
$$

Notice that if we refer to the tree, each and every of these **outcomes** has probability $\frac{1}{9}$ each. Because of that, there are $6$ of these events, the total probability is $\frac{6}{9} = \frac{2}{3}$. We are **more than likely to win if we always switch**!

---
# Part 1: Probability Spaces, Outcomes and Events

Let's start covering the basic concepts, while using the **Monty Hall problem** (in [[#Introduction]]) as an example. To model probabilistic phenomena, we have:

>[!info] Definition: Sample space, outcomes and events
>The **sample space** is the set of all possible outcomes, typically denoted with $\Omega$.
>
>Each **outcome** $x$ in the sample space is associated with a probability value, denoted $\text{Pr}[x]$. For any outcome $x$, we have that $\text{Pr}[x] \geq 0$. Moreover, the sum of the probabilities of *all* events in the sample space has to equal $1$, i.e.:
> $$
> \sum_{x \in \Omega} \ \text{Pr}[x] = 1
> $$
>
>An **event** is a subset of the sample space $\Omega$ (which is a collection of outcomes). The probability of event $E$ is denoted $\text{Pr}[E]$, and is equal to the sum of the probabilities of the outcomes:
> $$
> \text{Pr}[E] = \sum_{x \in E} \ \text{Pr}[x]
> $$


(**Sample space**) For example, in the Monty Hall problem, our sample space was given as:

$$
\begin{align*}
\{\\
&(A, A, B), (A, A, C), (A, B, C), (A, C, B), (B, A, C), (B, B, A), \\
&(B, B, C), (B, C, A), (C, A, B), (C, B, A), (C, C, A), (C, C, B)\\
\}
\end{align*}
$$

(**Probability values**) The tree that we drew, we assigned each outcome a unique probability value that was $\geq 0$. For example, we said that the probability of the outcome $(A, B, C)$ was $\frac{1}{9}$, whereas the probability of the outcome $(A, A, B)$ was $\frac{1}{18}$.

(**Events**) Lastly, we considered the strategy of always switching. Then, the event that we win is given by this subset:

$$
\begin{align*}
\{\\
&(A, B, C), (A, C, B), (B, A, C), (B, C, A), (C, A, B), (C, B, A)\\
\}
\end{align*}
$$

We noted that the probability for each outcome here was $\frac{1}{9}$, so the probability of the entire event was $\frac{6}{9} = \frac{2}{3}$ (since there are $6$ outcomes in this event, each with probability $\frac{1}{9}$).

### A few more rules about probability

Note that for probabilities to make sense, we need a few more rules, which will be helpful to us when figuring out probabilities of certain events. Here are the rules:

1. The probability of any outcome $x \in \Omega$ is $\geq 0$, i.e., $\Pr[x] \geq 0$.
2. The sum of all probabilities is exactly $1$, i.e., $\sum_{x \in \Omega}\Pr[x] = 1$.

Here are also some helpful facts. Recall from counting and set theory that:

1. If $A$ and $B$ are disjoint sets, then $|A \cup B| = |A| + |B|$.
2. If $A\subseteq B$, then $|B \setminus A| = |B| - |A|$.

We have similar rules in probability, they go like so:

1. If $A$ and $B$ are disjoint sets of outcomes (disjoint events), then: $\Pr[A \cup B] = \Pr[A] + \Pr[B]$.
2. If $\Omega$ is the event space, and $A$ is an event ($A \subseteq \Omega$), then since $A \subseteq \Omega$, we have: $\Pr[\Omega \setminus A] = 1 -\Pr[A]$.

We also write $\Pr[\Omega \setminus A]$ as $\Pr[\bar{A}]$. Let's think a little about what the event $\Omega \setminus A$ means. It's basically the "complement" event of $A$. In other words, it's the event that $A$ did not happen. 

### An example of what we have seen so far

#### Example 1: Probability of an event

Let's work through an example to talk about some of these points. Imagine we had $3$ items: $1$, $2$, and $3$. Let's say that we took any possible permutation of the $3$ items **uniformly at random**, then asked, what is the probability that the first item remained in its position?

Let's fall back to the framework that we just mentioned. This means:

1. Listing out the set of all possible outcomes
2. Identifying the event that we care about
3. Figuring out the probability of the event

Since we are sampling any possible permutation of the $3$ items, this means that there are $3!$ possible outcomes:

1. $123$
2. $132$
3. $213$
4. $231$
5. $312$
6. $321$

So our sample space $\Omega$ is the set that contains these $6$ permutations. 

Moving on, we asked: "What is the probability that the first item remained in its position?" This is the **event** that we care about. Again, this is a set of outcomes we care about. This happens to be:

$$
\{123, 132\}
$$

This is exactly the set of outcomes where the first item remained in its position.

Lastly, we need to figure out the probability of the event, which is basically asking what the sum of the probability we obtain $123$ as the permutation, plus the probability we obtain $132$ as the permutation, is.

Since we said that each permutation is taken **uniformly at random**, this means that the probability of any outcome is $\frac{1}{\lvert \Omega \rvert}$ or, $1$ divided by the number of outcomes. Since there are $6$ outcomes here, each outcome occurs with probability $\frac{1}{6}$.

Looking back our event, the probability that the first element remains in position $1$ is given as:

$$
\frac{1}{6} + \frac{1}{6} = \frac{1}{3}
$$

#### Example 2: Complement events

What about if we asked something like: "What is the probability that the first item is **not** in position $1$?" Here, the event is given as:

$$
\{213, 231, 312, 321\}
$$

Now, we could have directly computed this and said "There are $4$ outcomes in our event, so the probability is $4 \times \frac{1}{6}$." Did you notice? This set of outcomes is actually the same as:

$$
\Omega \setminus \{123, 132\} = \{123, 132, 213, 231, 312, 321\} \setminus \{ 123, 132 \}
$$

So really, we can think of the event that "the first item is **not** in position $1$" as the **complement** of the event "the first item is in position $1$". So, we could also answer this as $1 - \frac{1}{3} = \frac{2}{3}$.


#### Example 3: Disjoint events

What about answering the following question? What is the probability that the first item is in position $1$ **or** position $2$?

Then we can think of these as $2$ disjoint events:

$$
E_1 = \{123, 132\} \hspace{2em} E_2 = \{213, 312\}
$$

$E_1$ corresponds to the event that the first item is in position $1$, and $E_2$ corresponds to the event that the first item is in position $2$.

Again, notice that $E_1$ and $E_2$ are disjoint. Hence, we can compute the probability as $\text{Pr}[E_1 \cup E_2]$, we know is actually just $\Pr[E_1] + \Pr[E_2] = \frac{2}{6} + \frac{2}{6} = \frac{2}{3}$.

#### Example 4: Dice

Just to reiterate the point a little bit, imagine if we were given a fair die that gives $1$, $2$, $3$, $4$, $5$ or $6$ uniformly at random—what is the probability that the die gives us an even number?

Again, the sample space $\Omega$ is now the set $\{1, 2, 3, 4, 5, 6\}$. The event $E$ is $\{2, 4, 6\}$. Thus, $\Pr[E]$ is basically:

$$
\frac{3}{6} = \frac{1}{2}
$$

---
# Part 2: Conditional Probability

## Why Conditional Probability?

Let's move onto talk about something called conditional probability. Think about the following kinds of events:

1. **Given the event that a die rolled an even number**, what is the probability the die rolled a $4$?
2. **Given the event that after flipping $3$ coins we saw $2$ heads**, what is the probability the first coin we flipped turned up heads?

How should we analyse these? Why should we do it? Here's another example scenario that might be a little more motivating or relevant. Let's say we thought about medical testing. Medical tests (like the COVID test kit that everyone has) in real life are not perfect. There is always a small chance of error.

1. A test could report positively that you have a condition, even if you don’t. This is called a **false positive**.
2. A test could report negatively that you don’t have a condition, even if you do. This is called a **false negative**.

(Bear in mind that "positive"/"negative" here isn't referring to "good/bad" news, it's talking about affirming or rejecting the fact that you have the condition.)

Now this extends beyond medical tests. Imagine we had to write an image classifier that tells you whether it contains an apple.

1. There’s a chance the classifier reports a false positive: the image has no apple, but it says there is one.
2. There’s a chance the classifier reports a false negative: the image has an apple, but it says there is none.

So here's an example of a statement we care about: **Given that a test reports positive**, what is the probability it is a true positive? (i.e., if a test says "yes", what is the chance the answer is actually really "yes"?)

Think of the event that the **test reports positive**, as our **condition**. In general, for events $A$ and $B$, we write:

$$
\Pr[A | B]
$$

to represent the probability of event $A$ occurring, **given that** event $B$ happens. To be clear, there is no sense of time here. (There are two things called "a priori probability" and "a posteriori probability", but we will not be covering them here.) We are only promised that event $B$ happens; we do not need to insist whether it happens before or after event $A$ (either is ok).

So what is the quantity $\Pr[A | B]$? How do we compute this? Well the definition is given as:

>[!info] Definition: Conditional probability
>The **conditional probability** of $A$ given that $B$ occurs is denoted $\text{Pr}[A|B]$, where:
> $$
> \text{Pr}[A|B] = \frac{\text{Pr}[A \cap B]}{\text{Pr}[B]}
> $$

This looks a lot more doable! But just to be clear: $\Pr[A\cap B]$ can be thought of as the probability that event $A$ **and** event $B$ occurs.

## An example:

Let's revisit the following question:

> **Given the event that a die rolled an even number**, what is the probability the die rolled a $4$?

Again, this is a standard $6$-sided die, so our event space is $\{1, 2, 3, 4, 5, 6\}$. We now need to create our events $A$ and $B$. Let's say that event $B$ is the event that the die rolled an even number. This means that:

$$
B = \{2, 4, 6\}
$$

Meanwhile, $A$ is the event we rolled a $4$, so $A = \{4\}$. So what is the probability of the event $A \cap B$? Since $\{2, 4, 6\} \cap \{4\} = \{4\}$, this means:

$$
\Pr[A \cap B] = \Pr[A]
$$

And so:

$$
\Pr[A | B] = \frac{\Pr[A \cap B]}{\Pr[B]} = \frac{\Pr[A]}{\Pr[B]} = \frac{1/6}{3/6} = \frac{1}{3}
$$

## A Visual Intuition:

What is going on with conditional probability? Here's the idea:

![[a-given-b.svg]]

The probability $\Pr[B | A]$ is basically the ratio of the size of $A \cap B$ to the size of $A$. We're basically saying: if we know we're in set $A$, what's the probability we're in set $A \cap B$? In particular, we don't consider the outcomes in set $B$ that are outside of $A$. 

## Back to Testing: Another Example

Back to testing, let's go back to the example of a classifier that needs to tell you if there is an apple in the image, or if there are none.

Here are four possible questions we can ask:

1. Given that a classifier reports positive, what is the probability it is a true positive?
2. Given that a classifier reports positive, what is the probability it is a false positive?
3. Given that a classifier reports negative, what is the probability it is a true negative?
4. Given that a classifier reports negative, what is the probability it is a false negative?

Let's try looking at the first one for our example.

Let $A$ be the event that there actually is an apple, and let $B$ be the event that the test reports positive. Then again, given the classifier reports positive, how confident we are that there actually is an apple is given by $\Pr[A | B] = \frac{\Pr[A \cap B]}{\Pr[B]}$. Now, the probability $\Pr[A \cap B]$ is the probability the classifier reports true and the image was an apple, whereas $\Pr[B]$ is the probability the classifier returns positive (on all images).

Let's say we have a dataset, with $10$ pictures (we could not afford many pictures), and $6$ of them have apples, $4$ of them do not have apples.

![[apples-and-durians.svg]]

The bottom row shows what our classifier says about whether the image has an apple or not.

Now, $\Pr[A \cap B]$ is $\frac{4}{10}$, because there are exactly $4$ times when there is an apple **and** the classifier says "yes". On the other hand, $\Pr[B]$ is $\frac{6}{10}$ because the classifier says "yes" $6$ times out of $10$.

So:

$$
\Pr[A | B] = \frac{\Pr[A \cap B]}{\Pr[B]} = \frac{4/10}{6/10} = \frac{4}{6} = \frac{2}{3}
$$

## Bayes' Theorem

Is this the only way to compute $\text{Pr}[A|B]$? Not quite. There is an alternative way that is quite helpful. It turns out **Bayes' Theorem** gives us an alternative formulation:

>[!info] Definition: Bayes' Theorem
>Given two events $A$ and $B$, we have the following formula:
> $$
> \Pr[A | B] = \frac{\Pr[B | A]\cdot \Pr[A]}{\Pr[B]}
> $$

So, we could instead compute these $3$ quantities:

1. $\Pr[B]$ (the probability that the classifier says "yes"), $\frac{6}{10}$
2. $\Pr[A]$ (the probability that we have an apple), $\frac{6}{10}$
3. $\Pr[B | A]$ (the probability that among the cases where we have an apple, the classifier says "yes").

For the last one, notice that we have $6$ apples, and among the apple, the classifier says yes $4$ out of the $6$ times. So the final quantity is $\frac{4}{6} = \frac{2}{3}$. Plugging it all in:

$$
\Pr[A | B] = \frac{(6/10)(2/3)}{(6/10)} = \frac{2}{3}
$$

The values line up! But why do we even bother with this alternative formulation?

### Another example for Bayes' Theorem

Let's go back to medical testing, and let's say we were given the following $3$ pieces of information:

1. $5$% of the population have condition $C$.
2. The test administered on a positive patient has $90$% chance of reporting it as a positive.
3. Administering the test on anyone, the test reports positive with $23.5$% chance.

Now, let's say we took the test, and it was positive. What is the probability we have condition $C$? 

Let $A$ be the event we have condition $C$, and let $B$ be the event that the test said we were positive. We want $\Pr[A | B]$. Notice how we do not have information about $\Pr[A \cap B]$. But instead, line 1 gives us $\Pr[A]$, line 2 gives us $\Pr[B | A]$, and line 3 gives us $\Pr[B]$.

So plugging this all in, we get:

$$
\Pr[A | B] = \frac{\Pr[B | A] \cdot \Pr[A] }{\Pr[B]} = \frac{(0.9)(0.05)}{(0.235)}
$$

which happens to be around $0.19$, so at least based on this set-up, it seems that the test was not super informative.

### An example table

In case this has still been a little unintuitive, hopefully the next explanation makes more sense.

|                   | Test says positive | Test says negative | Total  |
| :---------------: | ------------------ | ------------------ | ------ |
| Actually positive | $45$               | $5$                | $50$   |
| Actually negative | $190$              | $760$              | $950$  |
|       Total       | $235$              | $765$              | $1000$ |

So if we made a table with $4$ possible entries, then letting $A$ be the event of actually being positive, and $B$ be the event that the test says positive, we can say:

1. $\Pr[A] = \frac{50}{1000}$, which is the total number of positive people divided by the total number of people. 
2. $\Pr[\bar{A}] = 1 - \frac{50}{1000} = \frac{950}{1000}$, which is the total number of **not positive** (i.e., negative) people divided by the total number of people. 
3. $\Pr[B] = \frac{235}{1000}$, which is the total number of people who tested positive divided by the total number of people.

Also, for conditional probability:

1. $\Pr[B | A] = \frac{45}{50}$. Why? We were promised that the people are actually positive (there are $50$ of them), and of those $50$ people, $45$ of them tested positive.
2. $\Pr[A | B] = \frac{45}{235}$. Similarly, we are promised that the people have been tested positive (there are $235$ of them), and of those $235$ people, $45$ of them tested positive.

We can also ask something like: "What's the probability that we are actually positive, given that the test returned negative?" Then this is given as:

$$
\Pr[A | \bar{B}] = \frac{\Pr[A \cap \bar{B}]}{\Pr[\bar{B}]} = \frac{5}{765}
$$

Again, this is because we were promised that $765$ people did **not** test positive (i.e., negatively), and among those $765$ people, $5$ of them were actually positive.

So to bring this back to the concept at the beginning of this section:

1. $\Pr⁡[B|A]$ is called the true positive rate.
2. $\Pr⁡[\bar{B}|A]$ is called the false negative rate.
3. $\Pr⁡[B|\bar{A}]$ is called the false positive rate.
4. $\Pr⁡[\bar{B}|\bar{A}]$ is called the true negative rate.

---
# Part 3: Independent Events

Lastly, let's round off with looking at events in a little more detail. This is actually a concept that is a lot more helpful for next week, but it's better to start this concept now before introducing it for next week instead. It starts off with the following vague intuition:

> How do we say that two events are unrelated?

For example, we could have flipped two different coins far away from each other. Intuitively we would like to think that the two outcomes should not affect each other.

>[!info] Definition: Independent events
>We say that two events $A$ and $B$ are **independent** if either $\text{Pr}[B] = 0$, or $\text{Pr}[A|B] = \text{Pr}[A]$ (or vice versa).
>
>An alternative definition of independence is if $\text{Pr}[A \cap B] = \text{Pr}[A] \cdot \text{Pr}[B]$. (Why? See below for solution)

>[!question]- Alternative definition of independence
>If $A$ and $B$ are independent, then $\text{Pr}[A|B] = \text{Pr}[A]$. Rewriting this, we have:
>
> $$
> \text{Pr}[A|B] = \frac{\text{Pr}[A \cap B]}{\text{Pr}[B]} = \text{Pr}[A]
> $$
> 
>Multiplying both sides by $\text{Pr}[B]$ produces the desired equality.

A vague intuition you can have for the definition is: "Given that $B$ has happened, the probability for event $A$ has remain unchanged." Though this is quite improper, it might be a little bit helpful.

## Example of Independent Events:

Assume we have two fair coins, $C_1$ and $C_2$ (each having a sample space of $\{H, T\}$, and the probability of each outcome is $\frac{1}{2}$). **Assume that $C_1$ and $C_2$ are independent.** That is to say, $\forall x, y \in \{H, T\}$:

$$
\Pr[C_1 = x \cap C_1 = y] = \Pr[C_1 = x]\cdot \Pr[C_2 = y]
$$

Then what is the probability that both coins produce tails? In other words, what is:
$$
\Pr[C_1 = T \cap C_2 = T] = ?
$$

Well, based on our assumption, it is the case that:

$$
\Pr[C_1 = T \cap C_2 = T] = \Pr[C_1 = T] \cdot \Pr[C_2 = T] = \frac{1}{2} \cdot \frac{1}{2} = \frac{1}{4} 
$$

To be clear, we cannot draw the same conclusion if we did not assume independence.

### An example with seemingly independent events:

Let's consider a $3$-coin example. Again, assume we have two fair coins, $C_1, C_2$ (each have a sample space $\{H, T\}$, and the probability of each outcome is $\frac{1}{2}$). **Assume that $C_1$ and $C_2$ are independent.** Now also assume a third coin $C_3$, where:

$C_3$ looks at $C_1$ and $C_2$. Then:

1. If $C_1 = C_2$, then return tails. 
2. Otherwise, return heads.

So again, if we listed out the sequence of outcomes and their probabilities with a tree, it looks like this:

![[3-coins.svg]]

Again, if we stuck to first finding the sample space, we'll find that this is our set of outcomes:

$$
\Omega = \{ (H, H, T), (H, T, H), (T, H, H), (T, T, T) \}
$$

And if we looked carefully, each outcome again, has probability $\frac{1}{2} \cdot \frac{1}{2} = \frac{1}{4}$ of occurring.

Let's look at a few events, and their probabilities. What are the following sets of outcomes that correspond to the following events?

1. The event $E_1$ that $C_1$ is heads?
2. The event $E_2$ that $C_1$ is tails and $C_2$ is heads?
3. The event $E_3$ that $C_1$ is tails, $C_2$ is heads, and $C_3$ is heads?
4. The event $E_4$ that $C_1$ is tails, $C_2$ is tails, and $C_3$ is heads?

(**Question 1**) So there are a few ways to do this, let's begin with question 1. We really just want all the outcomes where the first value is $H$. So event $E_1$ is basically the set of outcomes $\{(H, H, T), (H, T, H)\}$.

(**Question 2**) What about the second one? Well, we could manually go through each outcome and find that the only one is $(T, H, H)$. Alternatively, we could also think first about the event that $C_2$ is heads. This is the set of outcomes $\{(H, H, T), (T, H, H)\}$. Also, similar to the previous question, we know that the the event where the first coin $C_1$ is tails is the set $\{(T, H, H), (T, T, T)\}$.

So alternatively, we can think of this as the set
$$E_2  = \{(H, H, T), (T, H, H)\} \cap \{(T, H, H), (T, T, T)\} = \{(T, H, H)\}$$
Both methods work.

(**Question 3**) The third one works in a similar way, but basically the only option is $(T, H, H)$. So the event $E_3 = \{(T, H, H)\}$.

(**Question 4**) The final one, is interesting. The outcome does not exist! So $E_4 = \emptyset$.

What about their probabilities? Again, we can use the tree to figure this out. But basically if we do, you might notice that:

1. $\Pr[E_1] = \Pr[(H, H, T)] + \Pr[(H, T, H)] = \frac{1}{4} + \frac{1}{4} = \frac{1}{2}$
2. $\Pr[E_2] = \Pr[(T, H, H)] = \frac{1}{4}$
3. $\Pr[E_3] = \Pr[(T, H, H)] = \frac{1}{4}$
4. $\Pr[E_4] = \Pr[\emptyset] = 0$

Okay, what was the point of all this? Let's explore which coins are independent. Let: 

1. $D_1$ be the event that $C_1 = H$
2. $D_2$ be the event that $C_2 = H$
3. $D_3$ be the event that $C_3 = H$

So again, here are the respective sets:

1. $D_1 = \{(H, H, T), (H, T, H)\}$
2. $D_2 = \{(H, H, T), (T, H, H)\}$
3. $D_3 = \{(H, T, H), (T, H, H)\}$

And let's consider the following 2 questions:

1. Are events $D_1$ and $D_3$ independent of each other?
2. Are events $D_1, D_2$ and $D_3$ independent of each other?

You might think the answer is no to both, after all coin $C_3$ does look at coins $C_1$ and $C_2$. But it turns out, based on our definition, events $D_1$ and $D_3$ are actually independent of each other! Let's see this formally:

$$
\begin{align*}
\Pr[D_1 \cap D_3] = \Pr[\{H, T, H\}] = \frac{1}{4} = \frac{1}{2}\cdot \frac{1}{2} = \Pr[D_1] \cdot \Pr[D_3]
\end{align*}
$$

Since $\Pr[D_1 \cap D_3] = \Pr[D_1] \cdot \Pr[D_3]$, the two events are independent. This might be a little counter-intuitive but yet mathematically it checks out.


However, it is still true that events $D_1, D_2$ and $D_3$ are not independent of each other. Let's also see this formally:

$$
\begin{align*}
\Pr[D_1 \cap D_2 \cap D_3] = \Pr[\emptyset] = 0 \neq  \frac{1}{2}\cdot \frac{1}{2} = \Pr[D_1] \cdot \Pr[D_2] \cdot \Pr[D_3]
\end{align*}
$$

Since $\Pr[D_1 \cap D_2 \cap D_3] \neq \Pr[D_1] \cdot \Pr[D_2] \cdot \Pr[D_3]$, the events are not independent.