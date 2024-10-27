---
title: CS1231S Tutorial 9 Solutions
tags:
  - Tutorial
hidden: true
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
This question works similarly. Except there's a subtlety here: It is not correct to say that we only need to count the number of 5-draws where there is no king and there is no queen. We're missing the number of 5-draws where there is exactly one king and no queen, and also the number of 5-draws where there is exactly no king and one king.

1. The number of neither king nor queen: $(52 - 4 - 4)^5 = 44^5$
2. The number of exactly 1 king, and no queens: $(4 \cdot (52 - 4)^4) \cdot 5$
3. The number of exactly 0 kings, and 1 queen: $(4 \cdot (52 - 4)^4) \cdot 5$

To explain the count for point 2 and 3: There are $5$ possible positions that contains the single king/queen. There are 4 possible cards that is the single King/Queen. And for the remaining $4$ positions, there are $52 - 4 = 48$ possible cards to draw from.

So the total count is $52^5 - 44^5 - 2\cdot 20\cdot 48^5$.

# Question 2
Assuming the only digits that can be confused are 0, 1, 6, 8, and 9. There are 5 possible digits, and each digit can take on 5 possible values. So $5^5$.

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

1. There are $n + 1$ possible white ball run lengths: $0$ through $n$.
2. A run length of $0$ is treated specially. There is only one possible arrangement here.
3. Fixing a length $\ell \in [1, n]$, there are $n + 1 - \ell$ possible starting points for the white ball run.

Therefore, the total number of arrangements is:
$$
1 + \sum_{\ell = 1}^n (n + 1 - \ell) = 1 + n^2 + n - \frac{n(n+1)}{2} = 1 + \frac{n(n+1)}{2}
$$

# Question 5
## Part (a)
To make no two girls sit together, here's the idea:
1. Fix a permutation of the guys.
2. Treat the slots in between the guys as "potential slots". They don't all have to be taken, but from them we need to pick 4 slots. Then we can seat the girls there.
3. Then don't forget, it's circular so we need to divide by $12$.

![[Images/seating-question.png]]

So in total:
$\frac{8! * \binom{8}{4} * 4!}{12} = 5644800$.

## Part (b)
To do this, it's far easier to count the number of ways in which Eric and Freddy sit next to each other. So, pair the two of them together. So either Eric before Freddy, or Freddy before Eric.
Now we treat them as a single piece and parade them around the table.

1. Fix an arrangement of Eric and Freddy. There are 2 possible arrangements.
2. There are $5$ items (not $4$ because Eric and Freddy are now joined at the hip), and there are $5!/5$ such arrangements.

Therefore, in total: $2 \times 4!$ where Eric and Freddy are adjacent. There are $6!/6 = 5!$ ways to seat anyone without restrictions.  Thus the answer is $5! - 2\times 4!$.

## Part (c)
This is really similar to the guys vs girls question. You have $n - 1$ people, and you can make one more fake person called "EMPTY CHAIR".

So it's really just how would you seat $n$ people. In which case there are $n!/n = (n-1)!$ ways.


# Question 6

Fix the word "I" first. There are 3 possible relative positions for where "IT" can go. In position 2, we are not worried about whether it is arranged as "IT" or "TI".

So in case 1: There are $3! \times 2! \times 2!$ ways to arrange each letter. Also, in this case, "IT" is fixed at position 2, so all that remains is to fix "CAN" and "DO" at either positions 1 and 3. There are $2$ possible ways. So in total $3! \times 2! \times 2! \times 2$.

Case 2: The other case where "IT" is either in position 1 or position 3. Then when that is chosen, the arrangement of the letters of of "IT" is fixed since it needs to arranged away from the "I". Again the "CAN" and "DO" can be freely permuted, and we can pick wherever they go.

So in total: $2 \times 3! \times 2! \times 2$, $2$ ways to pick where "IT" sits (and the permutations is fixed), $3!$ permutations of "CAN", $2!$ permutations of "DO", and $2$ possible ways to pick where "CAN" and "DO" are placed.

![[Images/round-table.png]]

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

# Question 10

# Question 11

