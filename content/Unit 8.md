---
title: "Unit 8: Basic Probability"
---
# Overview
In this unit that is one of 2 parts, we will introduce probability theory. Probability theory is quite fundamental if one wants to analyse different randomised strategies we might have. This is particularly useful in certain parts of machine learning, and AI. Ever wondered how monte carlo works? Ever wondered how chess engines explore such a large state space when figuring out optimal strategies? It turns out when the scale of problems get large enough, randomising your approach might not give you the best solution, but we can hope to maximise our chances of getting something "good enough".


To do this, we first need to talk about the basic fundamentals and rules of probability theory. We will also reason about basic probability in this unit. We will follow this up by introducing very common distributions in the subsequent unit, and finishing off with something called bounds and deviations.

# Introduction
Let's begin with an example scenario:

You're at a gameshow, there are 3 doors. One of the doors has an equal chance (1 in 3) of having a car, the other two doors have a goat behind them. The game goes like this:

1. You can choose any door you wish. 
2. After that, of the 2 remaining doors that you did not pick, the host will pick a door that has a goat, and reveal it to you.
3. The host then offers you a choice: Do you stay on the door you originally picked? Or do you switch over to other door?
4. After you decide which door you want, the host reveals the prize for you at the end of it. If you ultimately chose the door with the car, you win the car. Otherwise, you win the goat.

People have long debated as to what the best strategy is. Should we always stick? Should we always switch? Does it even matter? Is it always a 50 50 chance?

Interestingly, we can use probability theory to understand why the strategy of always switching is actually a good strategy. (We will win the car with probability 2/3).

To first understand why, we should probably take a formal approach to this problem.

## Considering the Possible Outcomes

Let's look at the possible outcomes that we might have from this game. For this, let's say:
1. Call the 3 possible doors A, B, and C.
2. One of the 3 doors is chosen uniformly at random to contain the car. Let's call this **outcome door 1**.
3. You have an equal chance of taking any of the 3 doors uniformly at random. Let's call this **outcome door 2**.
4. The host will consider one of the two doors you didn't pick, and he will reveal one door that has a goat. Let's call this **outcome door 3**.
5. Then from there, we need to pick either **outcome door 1** or **outcome door 3**.

So let's first think about all of the possible sequence of outcomes:

![[sequence-of-outcomes.svg]]

Think of it this way, if **outcome 1** is the same as **outcome 2** (e.g. the car was behind door A, and we chose door A), then the host can reveal either doors B or C.

So based on the tree, notice how we can have a sequence of outcomes (A, A, B) or sequence of outcomes (A, A, C). 

On the other hand, if **outcome 1** is **not** the same as **outcome 2** (e.g. the car was behind door B, and we chose door C), then the host has only one possible choice to reveal, the door that we did not choose, and does not have the car. For example, if the car was behind door C, and we chose door B, then the host must reveal door A.

So based on the tree, we can have a sequence of outcomes like (C, B, A) or (C, A, B). But never something like (C, A, C) or (C, A, A).

So if we listed out of all of the possible sequences of outcomes, we get this list:

$$
\begin{align*}
\{\\
&(A, A, B), (A, A, C), (A, B, C), (A, C, B), (B, A, C), (B, B, A), \\
&(B, B, C), (B, C, A), (C, A, B), (C, B, A), (C, C, A), (C, C, B)\\
\}
\end{align*}
$$

Okay, so we know which outcomes are possible. What we care about is using this to help analyse the probability always switching wins us the car. For that, we first need to identify the **subset** of outcomes that we care about. We call these subset of outcomes as **events**.

For example, if we cared about asking "what is the probability that the car is behind door B?". Then the set of outcomes that correspond to this **event**, is ${ (C, A, B), (C, B, A), (C, C, A), (C, C, B) }$.

In this case, let's ask ourselves, "If we always choose the option to switch, what is the probability of winning?". Let's first think about which subset events correspond to us winning if we always chose to switch. For example, if the car was behind door A, we chose door B, and the host was forced to reveal door C. Then of the remaining options, we either choose to stay on door B, or switch to door A, so switching to door A lets us win.



