---
title: "Tutorial 5: Probability"
---
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.

* **Official due date for submission** : 15-Apr-2025, 23:59 **or** during tutorial itself.

# Collaboration Policy: 
* You may discuss high-level ideas with your classmates or friends. You should list your collaborators if you do so. 
* **Do not share your solutions**.
* ChatGPT (and other LLMs) are **not allowed**. 
* Your submission **must be of your own write-up**.

# Late Policy:
* < 1 week after submission deadline: 50% penalty
* < 2 weeks after submission deadline: 75% penalty
* No submissions after 2 weeks.

# Overview
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 8]] and Unit 9. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.

1. Questions 1 through 2 are related to basic probability.
2. Questions 3 through 4 are related to distributions and bounds.

After week 11's content, you should be able to attempt questions 1 through 2. Question 1 is graded for participation.

After week 12's content, you should be able to attempt questions 3 through 4. Question 3 is graded for participation.

That said, **we encourage you to try all the questions**, this way when you come for tutorial we can best make use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

# Question 1 \[Graded for Participation]:

Let's consider a scenario where we have $2$ dice: die $1$ (call it $D_1$) is **six-sided** (with faces $1$ through $6$), and die $2$ (call it $D_2$) is **two-sided** (with faces $1$ through $2$). Here is a random process that we might consider:

1. Roll the first dice.
2. Roll the second dice.
3. Add up the two numbers and output it, call the output $S$.

**Assume that the dice are independent**, in other words, the outcome of the first dice and the outcome of the second dice do not affect each other.

## Sub-question 1:
What is the sample space of $D_1$? What is the sample space of $D_2$? What is the sample space of $D_1 \times D_2$?

## Sub-question 2:
Write down the events that correspond to the following:

1. The event $E_1$ that $S = 3$
2. The event $E_2$ that $S \leq 3$
3. The event $E_3$ that $S = 7$

## Sub-question 3:
Assume that die $D_1$ produces any of its $6$ possible values **uniformly at random**, and assume that die $D_2$ produces value $1$ with probability $\frac{1}{3}$, and value $2$ with probability $\frac{2}{3}$ (like an unfair dice).

What is the probability that:
1. $S = 3$?
2. $S \leq 3$?
3. $S = 7$?

## Sub-question 4:
Compute the following quantities:

1. $\Pr[(S \leq 3) \cup (S = 7)]$
2. $\Pr[(S < 7) \cap (S > 3)]$
3. $\Pr[S = 6 | D_1 = 5]$

# Question 2:
Let's explore the concept of Bayes' Theorem a little bit more. So recall that:

$$
\Pr[A | B] = \frac{\Pr[A \cap B]}{\Pr[B]}
$$

but under Bayes' Theorem, we also have that:

$$
\Pr[A | B] = \frac{\Pr[B | A] \cdot \Pr[A]}{\Pr[B]}
$$

We can actually take this concept further. Notice here that we can combine the two lines to say the following:

$$
\frac{\Pr[A \cap B]}{\Pr[B]} = \Pr[A | B] = \frac{\Pr[B | A] \cdot \Pr[A]}{\Pr[B]}
$$

Which means that:

$$
\Pr[A \cap B] = \Pr[B | A] \cdot \Pr[A]
$$

Also, recall that we said that if two events $D$ and $E$ are **disjoint**, then we can say that:

$$
\Pr[D \cup E] = \Pr[D] + \Pr[E]
$$



## Sub-question 1:
**Question:** With the help of the identities shown above, prove that:
$$
\Pr[A | B] = \frac{\Pr[B | A] \cdot Pr[A]}{\Pr[B | A] \cdot \Pr[A] + \Pr[B | \bar{A}] \cdot \Pr[\bar{A}]}
$$

**Hint:** What if we told you that $B \cap \bar{A}$ is disjoint from $B \cap A$? How can you use this fact? What is $(B \cap A) \cup (B \cap \bar{A})$? 

## Sub-question 2:
Let's say a disease $F$ affects $1$ out of every $1000$ people in the city. There is a testing kit that when administered on someone who is positive, will report "positive" $85$% of the time. We also know that among all people who took the test (positive or not), the test reported "positive" $10$% of the time. 


1. Let's say we took the test and the test reported "positive". What is the probability we have disease $F$?
2. What is the probability that if we administered a test on a person that we know **does not** have the disease, the test will report positive?

You will probably find the following identity helpful (for the second part):

$$
1 - \Pr[A | B] = \Pr[\bar{A} | B]
$$


# Question 3 \[Graded for Participation]: Expectation

Given $X \sim Geom(1/7)$, $Y \sim Binom(20, 1/4)$, and $Z \sim Bernoulli(1/3)$. Assume that the $3$ random variables are all independent of each other.

What is:

1. $\mathbb{E}[X + Y + Z]$?
2. $\mathbb{E}[X \cdot Z]$?
3. $\mathbb{E}[Z\cdot Z]$?
4. $\text{Var}[2X]$?
5. $\text{Var}[X + Y]$?


# Question 4: 

Let's say we were going to throw $n$ balls into $n$ bins. Each ball lands at any bin with probability $\frac{1}{n}$. Let $X$ be the number of balls that lands in the first bin. Recall we can write this as:

$$
X = \sum_{i = 1}^n X_i
$$

where $X_i$ is the random variable that is distributed as $Bernoulli(1/n)$.

Compute the following:

1. What is $\mathbb{E}[X]$?
2. What is a bound for $\Pr[X > a]$?
