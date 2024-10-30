---
title: CS1231S Tutorial 9 Solutions
tags:
  - Tutorial
---
This page has solutions for selected questions from [this tutorial sheet](https://www.comp.nus.edu.sg/~cs1231s/tut/24s1/tut09qns.pdf).

This tutorial is on mathematical induction. Please do not use these as lecture notes. You should make an earnest attempt and pretty much solve the tutorial questions before referring to the solutions. This means I will say "you should already know this/you should already know that" without much explanation on what exactly it is in detail.

# Question 1
## Part (a)
First thing to note, the question says "with replacement". Now the "direct" way of solving this would be to literally get the probability that there is exactly 1 queen, and the probability there is exactly 2 queens, and 3 queens, and 4 queens, and 5 queens.

But that's cumbersome. The alternative is to note that since we're drawing 5 cards, it's there's either 0, 1, 2, 3, 4, or 5 queens drawn. These are **mutually exclusive** events. If we drew 5 cards with replacement, and say we know there were exactly 3 queens, then the probability there were exactly 4 queens **given the fact that there were exactly 3 queens is $0$.

I.e. Let $p_i$ be the probability that there were exactly $i$ queens of the 5 cards drawn with replacement.  Then:
$$
1 = p_0 + p_1 + p_2 + p_3 + p_4 +p_5
$$
So we want $\sum_{i = 1}^5 p_i$. This happens to just be $1 - p_0$.

And what's $p_0$? The probability no queens were drawn. Since it's with replacement, each draw has the same distribution. There are $4$ queens, and in total, $52$ cards. So there are $\frac{52 - 4}{52} = \frac{48}{52}$ possible cards that are not queens. That's also the probability any single draw is not a queen.

So the probability all 5 draws are not queens are: $(\frac{48}{52})^5$. And now the probability we draw at least one queen is $1 - (\frac{45}{52})^5$.

What if we wanted the number of sequences itself? There's two ways to get this. One is, you take the probability we got, and multiply by the number of possible sequences, which happens to be $52^5$. So we get: $52^5 - 45^5$. There happens to be another way. We can do the same idea, but with counts instead of probabilities.

There are $52^5$ possible sequences.Let $c_i$ be the number of possible 5-draws such that there are exactly $i$ queens in the 5 draws. Again, we have:

$$
52^5 = \sum_{i = 0}^5 c_i
$$

Which means:
$$
52^5 - c_0 = \sum_{i = 1}^5 c_i
$$
So let's find $c_0$. That happens to be $(52 - 4)^5 = 48^5$. Why? Because for each draw, there are $48$ possible cards we could have taken that are not the queen. Each draw must not have a queen, so for each possible draw, there aer $48$ choices, and we need to repeat this $5$ times.

So the answer is still $52^5 - 48^5$.

## Part (b)
This question works similarly. We just want to remove the case that there are no queens, and no kings. The number of sequences with no kings and no queens happens to be: $(52 - 8)^5$.

So answer is $52^5 - 44^5$.

# Question 2
Assuming the only digits that can be confused are 0, 1, 6, 8, and 9. There are 5 possible digits, and each digit can take on 5 possible values. So $5^5$.

Except, some numbers cannot be confused. E.g. $10101$ will not be confused regardless of whether it is upside down or not.

So, we want to remove the numbers whose digits only come from $\{0, 1, 6, 8, 9\}$ but are the same as themselves when they're upside down.

There are $5 \times 5 \times 3$ such numbers. The moment we choose the first digit, we have determined our last digit. If the first digit is either $0, 1, 8$, then the last digit is also the same number. If the first digit is $6$ or $9$, then the other digit is either $9$ or $6$.

So in total: $5^5 - 5 \times 5 \times 3 = 5^5 - 75$.

![[Images/mirror-number.png]]

# Question 3
We are going to use the principle of inclusion-exclusion here. Let $c_1$ be the count on the number of permutations where integer $1$ is in the correct position in the permutation. Likewise define $c_2$ and $c_3$ similarly.  Now the question wants $c_{1, 2, 3}$. 

If we let $S_1$ be the set of permutations for which $1$ is in the correct position. Define $S_2$ and $S_3$ similarly. then 

$c_{1,2,3} = \lvert S_1 \cup S_2 \cup S_3 \rvert = \lvert S_1  \rvert+ \lvert S_2\rvert + \lvert S_3 \rvert - \lvert S_1 \cap S_2 \rvert - \lvert S_1 \cap S_3 \rvert- \lvert S_2 \cap S_3 \rvert + \lvert S_1 \cap S_2 \cap S_3\rvert$

1. $\lvert S_1 \rvert = \lvert S_2 \rvert =\lvert S_3 \rvert = (n - 1)!$
2. $\lvert S_3 \rvert = \lvert S_1 \cap S_2 \rvert = \lvert S_1 \cap S_3 \rvert= \lvert S_2 \cap S_3 \rvert = (n - 2)!$
3. $\lvert S_1 \cap S_2 \cap S_3\rvert = (n - 3)!$

Thus, $c_{1, 2, 3} = 3(n - 1)! - 3(n-2)! + (n-3)!$

# Question 4
This one can sort of be done a little mechanically. Let's do it step by step:

1. There are $n$ possible white ball run lengths: $1$ through $n$.
2. Fixing a length $\ell \in [1, n]$, there are $n + 1 - \ell$ possible starting points for the white ball run.

Therefore, the total number of arrangements is:
$$
\sum_{\ell = 1}^n (n + 1 - \ell) = n^2 + n - \frac{n(n+1)}{2} = \frac{n(n+1)}{2}
$$

![[Images/white-ball-run.png]]


# Question 5
## Part (a)
To make no two girls sit together, here's the idea:
1. Fix a circular permutation of the guys.
2. Treat the slots in between the guys as "potential slots". They don't all have to be taken, but from them we need to pick 4 slots. Then we can seat the girls there.

![[Images/circular-table.png]]

So in total:
$$
\frac{8! * \binom{8}{4} * 4!}{8}
$$
>[!Question]+
> Let's try it with smaller values so I can actually draw it feasibly. Let's say there are $4$ boys, and $2$ girls instead.
> ![[Images/circular-table-other.png]]

## Part (b)
To do this, it's far easier to count the number of ways in which Eric and Freddy sit next to each other. So, pair the two of them together. So either Eric before Freddy, or Freddy before Eric.
Now we treat them as a single piece and parade them around the table.

1. Fix an arrangement of Eric and Freddy. There are 2 possible arrangements.
2. There are $5$ items (not $4$ because Eric and Freddy are now joined at the hip), and there are $5!/5$ such arrangements.

Therefore, in total: $2 \times 4!$ where Eric and Freddy are adjacent. There are $6!/6 = 5!$ ways to seat anyone without restrictions.  Thus the answer is $5! - 2\times 4! = 120 - 2 \times 24 = 72$.

### Alternative Solution:
There's an alternative solution where we seat everyone else except Freddy first first, then note that there are $(5-2)$ possible seats for Freddy. So there are $4! \times 3 = 24 \times 3 = 72$ possible solutions.

Like so:

![[Images/eric-and-freddy-2.png|center|250]]

## Part (c)
This is really similar to the guys vs girls question. You have $n - 1$ people, and you can make one more fake person called "EMPTY CHAIR".

So it's really just how would you seat $n$ people. In which case there are $n!/n = (n-1)!$ ways.

# Question 6

Fix the word "I" first. There are 3 possible relative positions for where "IT" can go. In position 2, we are not worried about whether it is arranged as "IT" or "TI".


![[Images/round-table.png|300]]

So in case 1: There are $3! \times 2! \times 2!$ ways to arrange each letter. Also, in this case, "IT" is fixed at position 2, so all that remains is to fix "CAN" and "DO" at either positions 1 and 3. There are $2$ possible ways. So in total $3! \times 2! \times 2! \times 2$.

Case 2: The other case where "IT" is either in position 1 or position 3. Then when that is chosen, the arrangement of the letters of of "IT" is fixed since it needs to arranged away from the "I". Again the "CAN" and "DO" can be freely permuted, and we can pick wherever they go.

So in total: $2 \times 3! \times 2! \times 2$, $2$ ways to pick where "IT" sits (and the permutations is fixed), $3!$ permutations of "CAN", $2!$ permutations of "DO", and $2$ possible ways to pick where "CAN" and "DO" are placed.

Except, when "I" is next to "IT", both arrangements are the same. Since the "T" is just sandwiched by "I" on both sides. So for case 2, we need to divide by 2.

This means the total count is $3! \times 2! \times 2! + 2 \times 3! \times 2! = 48 + 24 = 72$.

![[Images/same-arrangement.png]]

# Question 7
So either:
1. All 5 men
2. 4 men, 1 woman
3. 3 men, 2 women
We don't care about the ordering.

In total:
$$
\binom{7}{5} + \binom{7}{4}\binom{6}{1} + \binom{7}{3}\binom{3}{2}
$$

We already know the count for the cases we care about. We just need the total possible cases. That happens to be picking $5$ people from any of the $7 + 6 = 13$

So that is $\binom{13}{5}$.

So the probability is $\frac{\binom{7}{5} + \binom{7}{4}\binom{6}{1} + \binom{7}{3}\binom{3}{2}}{\binom{13}{5}}$.

# Question 8
This is called stars-and-bars. You can Google it to look up the technique.

![[Images/stars-and-bars.png]]


## Part (a)
You have $50000 / 1000 = 50$ stars, and you need to draw $4 - 1 = 3$ bars to split up the stars into $4$ parts. That's like saying there are $53$ possible slots. $50$ of them are stars, and $3$ of them are bars.

$$
\binom{53}{3}
$$
## Part (b)
Since you need not invest all the money, you can instead choose to draw $5 - 1 = 4$ bars, to split up the stars into $5$ parts. The first $4$ parts are for investment, and the last part remains uninvested.

$$
\binom{54}{4}
$$

# Question 9
So here's the idea: the number 51 is pretty suspicious. Why? Because it says 51, and that's 1 above, 25, which is a perfect square.

So take your unit square and divvy it up into 25 sub-squares. You can do this by picking your sub-square side length to be $\frac{1}{5}$. Then there are 25 sub-squares. By PHP there is a square with 3 points. In the "worst case", the points are at most $\sqrt{2} \cdot \frac{1}{5}$ apart (the hypothenuse). To be clear:

Now a circle with diameter $\sqrt{2} \cdot \frac{1}{5} = \sqrt{\frac{2}{25}}$ will cover the 3 points. Which means a circle with diameter $\frac{1}{2} \sqrt{\frac{2}{25}} = \sqrt{\frac{2}{4 \cdot 25}} = \sqrt{\frac{1}{50}} < \sqrt{\frac{1}{49}} = \frac{1}{7}$.

![[Images/3-dot-question.png]]
# Question 10

When you take a number and ask for the remainder mod $4$, there are only 4 possible answers: $0, 1, 2,$ or $3$. Therefore if you have $5$ numbers, at least two of them mod to the same value. This means their difference is a multiple of $4$.
# Question 11
This one is a little trippy.

Let $P_1, P_2, \ldots, P_{77}$ be the running some of the total games played up to their respective days. E.g. $P_2$ is the total number of games played in day 1 and day 2.

Now we also consider values $P_1 + 21, P_2 + 21,\ldots ,P_{77} + 21$ be another sequence of variables.

Okay so there are a few restrictions. First up: $P_1 <  P_2 <  \ldots < P_{77}$ So this first set of variables are all distinct. Similarly, $P_1 + 21, P_2 + 21,\ldots ,P_{77} + 21$ must be all distinct.

Okay each of these variables need to be assigned a value. These values can range from $1$ to $11 \times 12 + 21 = 132 + 21 = 153$. Why? Because $P_{77}$ maxes out at $11 \times 12 = 153$, so $P_{77} + 21$ maxes out at $132 + 21 = 153$. We're going to be generous and say any variable here can take any value, as long as the first set of variables take distinct values, and the second set of variables also take distinct values.

In total there are $77 \times 2 = 154$ variables, and for each we can pick one of $153$ values. By PHP, there must be two variables that take the same value. Also since $P_1, P_2, \ldots, P_{77}$ are distinct, and $P_1 + 21, P_2 + 21,\ldots ,P_{77} + 21$ are distinct. So it must be that $P_i = P_j + 21$ for some $i$ and $j$. But that means that there is a run of days for which the total games played is $21$.

