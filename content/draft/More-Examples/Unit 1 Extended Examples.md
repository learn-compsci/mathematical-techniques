---
title: "More Examples: Unit 1"
hidden: "true"
---
### Propositional Logic

**Example 1: Truth tables**

Truth tables are a handy way to help us determine if two formulae are logically equivalent. To construct a truth table, we need to:

1. Exhaustively list all combinations of truth assignments
2. Evaluate the intermediate propositions until the final formula has been attained

For instance, let's draw the truth table for the formula $(p \to \neg q) \to r$.

Step 1: List out all 8 combinations of $p$, $q$ and $r$.

| $p$     | $q$     | $r$     |
| ------- | ------- | ------- |
| $true$  | $true$  | $true$  |
| $true$  | $true$  | $false$ |
| $true$  | $false$ | $true$  |
| $true$  | $false$ | $false$ |
| $false$ | $true$  | $true$  |
| $false$ | $true$  | $false$ |
| $false$ | $false$ | $true$  |
| $false$ | $false$ | $false$ |

Step 2: Evaluate the intermediate propositions. In this case, we need the intermediate steps $\neg q$, then $p \to \neg q$, and finally, $(p \to \neg q) \to r$. 

We construct the $\neg q$ column by taking all the corresponding values of $q$ and negating them.

| $p$     | ==$q$==     | $r$     | ==$\neg q$== | $p \to \neg q$ | $(p \to \neg q) \to r$ (goal) |
| ------- | ----------- | ------- | ------------ | -------------- | ----------------------------- |
| $true$  | ==$true$==  | $true$  | ==$false$==  |                |                               |
| $true$  | ==$true$==  | $false$ | ==$false$==  |                |                               |
| $true$  | ==$false$== | $true$  | ==$true$==   |                |                               |
| $true$  | ==$false$== | $false$ | ==$true$==   |                |                               |
| $false$ | ==$true$==  | $true$  | ==$false$==  |                |                               |
| $false$ | ==$true$==  | $false$ | ==$false$==  |                |                               |
| $false$ | ==$false$== | $true$  | ==$true$==   |                |                               |
| $false$ | ==$false$== | $false$ | ==$true$==   |                |                               |

Then, we construct the $p \to \neg q$ column by taking the corresponding values of $p$ and $\neg q$ and performing an implication.

| ==$p$==     | $q$     | $r$     | ==$\neg q$== | ==$p \to \neg q$== | $(p \to \neg q) \to r$ (goal) |
| ----------- | ------- | ------- | ------------ | ------------------ | ----------------------------- |
| ==$true$==  | $true$  | $true$  | ==$false$==  | ==$false$==        |                               |
| ==$true$==  | $true$  | $false$ | ==$false$==  | ==$false$==        |                               |
| ==$true$==  | $false$ | $true$  | ==$true$==   | ==$true$==         |                               |
| ==$true$==  | $false$ | $false$ | ==$true$==   | ==$true$==         |                               |
| ==$false$== | $true$  | $true$  | ==$false$==  | ==$true$==         |                               |
| ==$false$== | $true$  | $false$ | ==$false$==  | ==$true$==         |                               |
| ==$false$== | $false$ | $true$  | ==$true$==   | ==$true$==         |                               |
| ==$false$== | $false$ | $false$ | ==$true$==   | ==$true$==         |                               |

Lastly, we construct the $(p \to \neg q) \to r$ column by taking the corresponding values of $(p \to \neg q)$ and $r$ and performing another implication.

| $p$     | $q$     | ==$r$==     | $\neg q$ | ==$p \to \neg q$== | ==$(p \to \neg q) \to r$== (goal) |
| ------- | ------- | ----------- | -------- | ------------------ | --------------------------------- |
| $true$  | $true$  | ==$true$==  | $false$  | ==$false$==        | ==$true$==                        |
| $true$  | $true$  | ==$false$== | $false$  | ==$false$==        | ==$true$==                        |
| $true$  | $false$ | ==$true$==  | $true$   | ==$true$==         | ==$true$==                        |
| $true$  | $false$ | ==$false$== | $true$   | ==$true$==         | ==$false$==                       |
| $false$ | $true$  | ==$true$==  | $false$  | ==$true$==         | ==$true$==                        |
| $false$ | $true$  | ==$false$== | $false$  | ==$true$==         | ==$false$==                       |
| $false$ | $false$ | ==$true$==  | $true$   | ==$true$==         | ==$true$==                        |
| $false$ | $false$ | ==$false$== | $true$   | ==$true$==         | ==$false$==                       |

And there we have our desired column!

**Example 2: Evaluating truth values**

Given a propositional formula such as $\neg ((p \lor \neg q) \to r) \land (r \to p)$, and given the truth values of the starting propositions, we can evaluate the truth value of the original formula. This is done by evaluating the "inner" formulae, then gradually working outwards to reach the final statement.

Suppose we had the following truth assignments for the propositions $p$, $q$ and $r$:
- $p \equiv false$
- $q \equiv false$
- $r \equiv true$

Then, we can begin evaluating $\neg ((p \lor \neg q) \to r) \land (r \to p)$ by looking at the innermost formulae and working outwards: 

1. Since $q \equiv false$, we have $\neg q \equiv true$.
2. Since $p \equiv false$ and $\neg q \equiv true$ (from line 1), we have $p \lor \neg q \equiv true$.
3. Since $p \lor \neg q \equiv true$ (from line 2) and $r \equiv true$, we have $(p \lor \neg q) \to r \equiv true$.
4. Since $(p \lor \neg q) \to r \equiv true$ (from line 3), we have $\neg ((p \lor \neg q) \to r) \equiv false$.
5. Since $r \equiv true$ and $p \equiv false$, we have $r \to p \equiv false$.
6. Since $\neg ((p \to \neg q) \to r) \equiv false$ (from line 4) and $r \to p \equiv false$ (from line 5), we have $\neg ((p \lor \neg q) \to r) \land (r \to p) \equiv true$, as desired.

### First-Order Logic

**Example 1: Parsing Nested Quantifiers**

Nested quantifiers can be difficult to understand at first glance because of the different quantifiers regarding each variable, and the relationships between the variables. One way to understand them more easily is to use English to decode these statements. A tip here is to use concrete examples to help you follow the train of logic so that you don't lose track of where you are in the statement.

When we encounter a universal quantifier, say $\forall x \in A$, we might decode it as "No matter which $x$ I choose from $A$". Correspondingly, when we encounter an existential quantifier, say $\exists y \in B$, we might decode it as "I can find a single $y$ in $B$". 

For reference, the definition of rational numbers is as follows:

>[!Definition]
>A number $x$ is **rational** if and only if there is an integer $a$ and a non-zero integer $b$, such that $x = \frac{a}{b}$.
>
>In other words, $x \in \mathbb{Q} \iff \exists a \in \mathbb{Z}, b \in \mathbb{Z} \: [x = \frac{a}{b} \land b \neq 0]$.

Let's see how this technique can be used to parse nested quantifiers.

>[!Example 1]
>**Statement:** $\forall x \in \mathbb{Z}, \forall y \in \mathbb{Z} \: [\frac{x}{y} \in \mathbb{Q}]$. Is this statement true? 

>[!Solution 1]+
>**Translation**: "No matter which integers $x$ and $y$ I choose, $\frac{x}{y}$ must be rational."
>
>**Discussion:**
>One might start choosing random integers $x$ and $y$, say $2$ and $5$, and checking whether $\frac{x}{y}$ is rational. In this case, $\frac{2}{5}$ is indeed rational. How about $10$ and $-2$? Well, $\frac{10}{-2} = -5 = \frac{-5}{1}$, so it is also rational!
>
>But what about $4$ and $0$? After all, the statement does say that **any** $x$ and **any** $y$ I choose must satisfy the condition! However, we see that $\frac{4}{0}$ is not even defined, and so it can't be rational. This means that Statement 1 is **false**; as long as we have a *single* counterexample, we have our conclusion.

>[!Example 2]
>**Statement:** $\exists x \in \mathbb{Z}, \exists y \in \mathbb{Q} \: [x = y]$. Is this statement true? 

>[!Solution 2]+
>**Translation**: "I can find an integer $x$ and a rational number $y$ such that $x = y$".
>
>**Discussion:**
>This one is perhaps more obvious: you only need to find a *single* integer $x$ and a *single* rational number $y$ that are equal to each other. For instance, one might even pick $x = 0$ and $y = \frac{0}{1}$, and it's immediately clear that we have our $x$ and $y$ as desired. Hence, the original statement is **true**.
>
>*Note: Although there are (infinitely) many such $y$ regardless of the chosen $x$, the statement is not concerned with how many examples there are, but more so with the fact that **they exist**.* 

Examples 3 and 4 deal with alternating quantifiers, which may be more difficult to grasp.

>[!Example 3]
>**Statement:** $\forall x \in \mathbb{Z}, \exists y \in \mathbb{Z} \: [\frac{x}{y} = 2]$. Is this statement true?

>[!Solution 3]+
>**Translation:** "No matter which integer $x$ I choose, it is guaranteed that I can find an integer $y$ such that $\frac{x}{y}$ is $2$."
>
>**Discussion:**
>One might begin by picking any integer $x$, say $6$, and checking if it is possible to find an integer $y$ where $\frac{6}{y} = 2$. Indeed, there is such a $y$, namely $3$. What about if $x = -6$? Yes, you can still let $y = -3$ and you get $\frac{-6}{-3} = 2$. 
>
>But what about $x = 1$? Is it possible to find a $y$ such that $\frac{1}{y} = 2$? Basic algebra says: no! If there *were* such a $y$, algebra tells us that $y$ would have to be $\frac{1}{2}$. However, $\frac{1}{2}$ is not an integer in the first place, as specified in the original statement with "$y \in \mathbb{Z}$". As a result, we can conclude that the original statement is **false**.

Take a moment to digest this last example before reading the solution!

>[!Example 4]
>**Statement:** $\exists a \in \mathbb{Z}, \exists b \in \mathbb{Z}, \forall x \in \mathbb{Q} \: [(a \leq x \leq b) \to (a \leq x^{2} \leq b)]$. Is this statement true?

>[!Solution 4.1]+
>**Translation:** "I can find (fixed) integers $a$ and $b$, such that no matter which rational number $x$ I choose, the following claim applies: 'If $x$ is between $a$ and $b$, then $x^{2}$ will still be between $a$ and $b$'." (For convenience's sake, let's call this secondary statement Claim 0.)
>
>**Discussion:**
>Fortunately/Unfortunately, many of the quantified statements that you will come across in computer science or mathematics involve significant nesting of quantifiers, such as this one. Let's analyse this statement step by step.
>
>Our task is to find the two integers $a$ and $b$, **not** the rational number(s) $x$! For a start, let's pick $a = 1$ and $b = 2$ to get a feel of what the statement is trying to say. Now, we pick any rational number $x$, say $\frac{1}{2}$, and try to evaluate the statement in square brackets: if $x = \frac{1}{2}$, we find that it does not even fulfil the antecedent $a \leq x \leq b$! Therefore, the implication $(a \leq x \leq b) \to (a \leq x^{2} \leq b)$ is true by default, but it's a rather meaningless test.
>
>Instead, let's pick a rational number $x$ such that the antecedent is true, say $x = \frac{3}{2}$. Then, $x^{2} = \frac{9}{4} = 2.25$, and here we run into a problem: now, the consequent $a \leq x^{2} \leq b$ is false! Hence, we have found an $x$ where Claim 0 (see above) is false, and so the $a$ and $b$ that we chose earlier (namely $1$ and $2$) are not the correct $a$ and $b$.
>
>Hopefully, after the "trial" above, you would've had a taste of what the statement is trying to say. Keep playing around with the values $a$ and $b$ to see if you can find the correct ones that prove the original statement is true. See Solution 4.2 below for the answers.

>[!Solution 4.2]-
>Choosing $a = 0$ and $b = 1$ will make the original statement true.  By basic algebra, for any rational number $x$, if $0 \leq x \leq 1$, then $0 \leq x^{2} \leq 1$ as well. 


**Example 2: Negating Nested Quantifiers**

**smth else??**