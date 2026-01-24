---
title: "More Examples: Unit 1"
---
# Overview

In this page, we will provide more examples for each notable topic. There will also be a few examples for you to try out yourself, with solutions provided in case you wish to verify them yourself.

Do post on Canvas if something is unclear or you wish for more explanations.

---
# Propositional Logic

### Propositions

Here are some more examples of propositions:

1. $5$ is greater than $2$.
2. There exists a number that is between $9$ and $20$.
3. $4$ is equal to $0$.

Recall that propositions are statements that are either true or false. For example, examples 1 and 2 are **true**, but example 3 is **false**.

Here are some **non-examples** of propositions:

1. Close the door.
2. I hope it rains today.

These statements don't have a clear "must be either true or false" property to them.

### Logical Connectives

Here are some more examples on how to use logical connectives to connect propositions:

1. $x = 5$ **and** $x = 6$
2. **if** ($x > 5$ **or** $x \neq 30$), **then** $y = 55$
3. (**not** $(x + 1 = 20)$) **or** ($55 + 1 = 70$)

In example 1, $x = 5$ and $x = 6$ are propositions, and **and** is used to connect the two propositions.

**Try it yourself!**
What about the other two lines? What are the propositions? What are the connectives?

>[!Answer]-
> In example 2, the propositions are: $x > 5$, $x \neq 30$ and $y = 55$.
> The connectives used are: **or**, **if/then**.
>
> In example 3, the propositions are: $(x + 1 = 20)$ and $55 + 1 = 70$.
> The connectives used are: **or**, **not**.

### Truth tables 

Truth tables are a handy way to help us determine if two formulae are logically equivalent. To construct a truth table, we need to:

1. Exhaustively list all combinations of truth assignments
2. Evaluate the intermediate propositions until the final formula has been attained

For instance, let's draw the truth table for the formula $(p \to \neg q) \to r$.

Step 1: List out all right combinations of $p$, $q$ and $r$.

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

| $p$     | $q$     | $r$     | $\neg q$| $p \to \neg q$ | $(p \to \neg q) \to r$ (goal) |
| ------- | ----------- | ------- | ------------ | -------------- | ----------------------------- |
| $true$  | $true$  | $true$  | $false$  |                |                              
| $true$  | $true$  | $false$ | $false$  |                |                               |
| $true$  | $false$ | $true$  | $true$   |                |                               |
| $true$  | $false$ | $false$ | $true$   |                |                               |
| $false$ | $true$  | $true$  | $false$  |                |                               |
| $false$ | $true$  | $false$ | $false$  |                |                               |
| $false$ | $false$ | $true$  | $true$   |                |                               |
| $false$ | $false$ | $false$ | $true$   |                |                               |

Then, we construct the $p \to \neg q$ column by taking the corresponding values of $p$ and $\neg q$ and performing an implication.

| $p$ | $q$ | $r$ | $\neg q$ | $p \to \neg q$ | $(p \to \neg q) \to r$ (goal) |
| ----------- | ------- | ------- | ------------ | ------------------ | ------------------------- |
| $true$ | $true$ | $true$ | $false$ | $false$ | |
| $true$ | $true$ | $false$ | $false$ | $false$ | |
| $true$ | $false$ | $true$ | $true$ | $true$ | |
| $true$ | $false$ | $false$ | $true$ | $true$ | |
| $false$ | $true$ | $true$ | $false$ | $true$ | |
| $false$ | $true$ | $false$ | $false$ | $true$ | |
| $false$ | $false$ | $true$ | $true$ | $true$ |  |
| $false$ | $false$ | $false$ | $true$ | $true$ |                           |

Lastly, we construct the $(p \to \neg q) \to r$ column by taking the corresponding values of $(p \to \neg q)$ and $r$ and performing another implication.

| $p$ | $q$ | $r$ | $\neg q$ | $p \to \neg q$ | $(p \to \neg q) \to r$ (goal) |
| ------- | ------- | ----------- | -------- | ------------------ | --------------------------------- |
| $true$ | $true$ | $true$ | $false$ | $false$ | $true$ |
| $true$ | $true$ | $false$ | $false$ | $false$ | $true$ |
| $true$ | $false$ | $true$ | $true$ | $true$ | $true$ |
| $true$ | $false$ | $false$ | $true$ | $true$ | $false$ |
| $false$ | $true$ | $true$ | $false$ | $true$ | $true$ |
| $false$ | $true$ | $false$ | $false$ | $true$ | $false$ |
| $false$ | $false$ | $true$ | $true$ | $true$ | $true$ |
| $false$ | $false$ | $false$ | $true$ | $true$ | $false$ |

And there we have our desired column!

**Try it yourself!**
Try creating the truth table for the formula:
$$(a \to b) \land (b \to a)$$

> [!Answer]-
> | $a$ |$b$  | $a \to b$     | $b \to a$ | $(a \to b) \land (b \to a)$  |
> | :--------------: | :--------------: | :-----------: | :--------: | :------------------: |
> | $true$         | $true$           | $true$   | $true$ | $true$  |
> | $true$         | $false$         | $false$  | $true$  | $false$ |
> | $false$          | $true$        | $true$  | $false$ | $false$ |
> | $false$          | $false$       | $true$ | $true$ | $true$ |

Try creating the truth table for the formula:
$$
\neg (c \to a) \lor e
$$

> [!Answer]-
> | $a$ |$c$  | $e$     | $c \to a$ | $\neg (c \to a)$ | $\neg (c \to a) \lor e$  |
> | :--------------: | :--------------: | :-----------: | :--------: | :------------------: |  :------------------: |
> | $true$  | $true$  | $true$  | $true$ |$false$ |$true$ |
> | $true$  | $true$  | $false$ |$true$ |$false$ | $false$|
> | $true$  | $false$ | $true$  |$true$ |$false$ |$true$ |
> | $true$  | $false$ | $false$ |$true$ |$false$ |$false$ |
> | $false$ | $true$  | $true$  |$false$ |$true$ |$true$ |
> | $false$ | $true$  | $false$ |$false$ |$true$ |$true$ |
> | $false$ | $false$ | $true$  |$true$ |$false$ |$true$ |
> | $false$ | $false$ | $false$ |$true$ |$false$ | $false$ |

### Evaluating Formulae

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
6. Since $\neg ((p \lor \neg q) \to r) \equiv false$ (from line 4) and $r \to p \equiv false$ (from line 5), we have $\neg ((p \lor \neg q) \to r) \land (r \to p) \equiv false$, as desired.

**Try it yourself!**
1. $(p \to q) \land (q\to p)$, with $p \equiv true, q \equiv false$.
2. $a \lor (b \to c)$, with $a \equiv true, b \equiv true, c \equiv false$
3. $(\neg(a) \land a) \lor (b \to c)$, with $a \equiv true, b \equiv true, c \equiv false$

>[!Answers]-
> For the first one, when $p \equiv true, q \equiv false$, then $(p \to q)$ is $false$, and $(q \to p)$ is $true$. $false \land true$ is $false$.
> There is a _slightly_ faster way to evaluate it. Notice that since $(p \to q)$ is $false$, and we are about to use $\land$, we don't actually care what's on the other side: since $false \land false \equiv false$, and $false \land true \equiv false$. In both cases, it is $false$.
> 
> 
> For the second one, when $a \equiv true, b \equiv true, c \equiv false$,  then $b \to c$ is $false$, and the entire formula is $true$.
> Again there is a _slightly_ faster way to evaluate it. We already know that $a$ is $true$ and $true$ used with $\lor$ anything is also $true$.
> 
> For the third and last one, $\neg a \land a$ is $false$. On the other hand $b \to c$ is also $false$. Since both sides of the $\lor$ are $false$, the entire formula is $false$.

---
# First-Order Logic

### Parsing Single Quantifiers

When we encounter a universal quantifier, say $\forall x \in A$, we might decode it as "No matter which $x$ I choose from set $A$". Correspondingly, when we encounter an existential quantifier, say $\exists y \in B$, we might decode it as "I can find a single $y$ in set $B$". 

For example, let's say we're at a company dinner, and what to say every person is attending. We want to have a _set_ that contains every person in the company. Something like:

$$
People = \{James, Jane, Keith, Kara\}
$$

(I guess this company only has $4$ people.)

Let's also make a predicate that represents the fact that a person is attending: $is\_attending(\cdot)$. 

For example, if:

$$
is\_attending(James)
$$

is $true$, then we know $James$ is attending the dinner. 

On the other hand, if 

$$
is\_attending(Keith)
$$

is $false$, we know $Keith$ is not attending.

So to say:

> "Every person in the company is attending"

We would write:
$$
\forall x \in People \ [\ is\_attending(x)\ ]
$$

If we wanted to say:

> "Someone in the company is attending"

We would write:

$$
\exists x \in People \ [\ is\_attending(x) \ ]
$$

If we wanted to say:

> "No one is attending the company dinner".

We could write:

$$
\forall x \in People \: [\neg \ is\_attending(x) \ ]
$$

There actually is a different way:

$$
\neg \big(\exists x \in People \: [\ is\_attending(x) \ ]\big)
$$

You could also think of this as saying "There is not a single person that is attending."

Okay, let's add one more predicate. $free(z)$ means person $z$ is free. What happens if $Jason$ says "if I am free, I will attend the dinner?" We can write:

$$
free(Jason) \to is\_attending(Jason)
$$

**Try it yourself!**
Based on the above example, what if we wanted to say:

> Anyone who is free at the company will attend the dinner.

Write your answer as a statement in first-order logic.

>[!Answer]-
> $$
>   \forall p \in People \ [free(p) \to is\_attending(p)]
> $$

What if we wanted to say: 

> If everyone is free, then everyone will attend the dinner.

Write your answer as a statement in first-order logic.

>[!Answer]-
> $$
>   \big(\forall p \in People \: [free(p)] \big) \to \big(\forall p \in People \: [is\_attending(p)] \big)
>   $$

Compare the two statements, what is the difference?

>[!Answer]-
> For example, in the first statement, it could be the case that $Jason$ and $Kara$ are free, but $Jane$ and $Keith$ are not. This means $Jason$ and $Kara$ will attend.
> 
> But in the second statement, since $Jason$ and $Kara$ are not free. We don't know if everyone will attend the dinner or not. It could be possible that no one goes. (It could actually still be possible that _some_ people go. Why is that? Hint: How does the $\to$ logical connective work?)

What if we wanted to say:

> All natural numbers are greater than $5$.

Recall that the set of natural numbers is $\mathbb{N}$. The statement is clearly false, but how should we write it in first-order logic?

>[!Answer]-
> $$
> \forall x \in \mathbb{N} \: [ x > 5 ]
> $$

What about:

> All integers are greater than or equal to $0$ when squared.

Recall that the set of natural numbers is $\mathbb{Z}$. How should we write it in first-order logic?

>[!Answer]-
> $$
> \forall x \in \mathbb{Z} \: [ x^2 \geq 0 ]
> $$

### Parsing Nested Quantifiers

#### Example 1

Nested quantifiers can be difficult to understand at first glance because of the different quantifiers regarding each variable, and the relationships between the variables. Let's look at a few more examples:

Let's re-visit the same English sentence we had in the notes:

> Statement 1: "There exists a planet that every person lives on."

Also compare it with the following statement:

> Statement 2: "Every person is such that, there exists a planet that person lives on."

Again, let's make two sets, $People$ (is the set of people), and $Planets$ (is the set of planets). And another predicate like $lives\_on(x, y)$. This time, the predicate takes two values as input, and it means "$x$ lives on $y$".

So for example if $lives\_on(James, Mars)$ is true, it would mean $James$ lives on $Mars$.

It also actually means **if we said** $lives\_on(Neptune, Chandler)$ is true, then we would be saying $Neptune$ lives on $Chandler$, as nonsensical as that sounds. 

**Try it yourself!**
Try to write statement 1 and statement 2 using the sets and the predicate provided.

>[!Answer]-
> Statement 1:
> $$
>   \exists x \in Planets, \forall y \in People \: [ lives\_on(y, x) ]
> $$
> 
> Statement 2:
> $$
>   \forall y \in People, \exists x \in Planets \: [ lives\_on(y, x) ]
>  $$

What is the difference between the two statements? Are they the same? Can we think of a (potentially fictitious) scenario where statement 1 is $false$. but statement 2 is $true$?

>[!Answer]-
> Let's say $Jason$ is a person (i.e. $Jason \in People$). And $lives\_on(Jason, Saturn)$ is $true$ (in other words, $Jason$ actually lives on $Saturn$. On the other hand, every other person who is not $Jason$ lives on $Neptune$.
>  
>  Then can we say there is a planet that every person lives on? No. Because we will need to **fix** a single planet. For that one planet, every person has to live on it. So Statement 1 is false.
>  
>  On the other hand, statement $2$ is true, because everyone lives on a planet. In our example, it's either $Saturn$ or $Neptune$.

#### Example 2

Let's try one more, but a little more mathematical this time.

$$
\exists a \in \mathbb{Z}, \exists b \in \mathbb{Z}, \forall x \in \mathbb{Q} \ [(a \leq x \leq b) \to (a \leq x^{2} \leq b)]
$$

Is this statement true?

>[!Solution-Part-1]-
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

>[!Solution-Part-2]-
>Choosing $a = 0$ and $b = 1$ will make the original statement true.  By basic algebra, for any rational number $x$, if $0 \leq x \leq 1$, then $0 \leq x^{2} \leq 1$ as well. 
>
>Remember, since it's $\exists a \in \mathbb{Z}, \exists b \in \mathbb{Z}$, we only need to find one value for $a$, one value for $b$.

### Negating Quantifiers

Here's another example, let's go back to the dinner. Let's say there are four people at the dinner. And let's think about the following statement:

> There is a dish that everyone likes

If we used the sets $Dishes$, $People$, and the predicate $likes(x, y)$ to mean "$x$ likes $y$". And also let's say one of the dishes was $Kailan$.

We can write "Every person likes $Kailan$" as:

$$
\forall x \in People \ [ likes(x, Kailan) ]
$$

What if we wrote:

$$
\neg \big( \forall x \in People \ [ likes(x, Kailan) ] \big)
$$

This means 

> It is not true that everyone likes $Kailan$.

Why was that? It's because **at least** one person does not like $Kailan$. 

That means we can also write it as:

$$
  \exists x \in People \: [ \neg \big(likes(x, Kailan)\big) ] 
$$

Similarly, if we instead want to say "no one likes $Kailan$" instead, there are two possible ways:

$$
\forall x \in People \: [ \neg \big(likes(x, Kailan)\big) ] 
$$

or:

$$
\neg \big(\exists x \in People \: [likes(x, Kailan) ] \big)
$$

The first statement is basically saying "Everyone does not like $Kailan$". The second statement is saying "It is not the case that there exists a person that likes $Kailan$." Like we mentioned in the notes, to move a $\neg$ symbol through a quantifier, we simply flip what the quantifier is.

**Try it yourself!**
What is the negation of the following?

$$
\forall x \in People \: [\big(likes(x, Shrimps)\big)] 
$$

>[!Answer]-
> The negation of the statement is
> $$
>   \neg \big(\forall x \in People \: [ \big(likes(x, Shrimps)\big) ] \big)
> $$ 
> which is also:
> $$
>    \exists x \in People \: [ \neg \big(likes(x, Shrimps)\big) ]
> $$

What if we wanted to say, "There exists a dish that everyone does not like"? 

What if we wanted to say the negation of that statement? What does the negation mean?

>[!Answer]-
> The first statement is written as
> $$
>   \exists d \in Dishes, \forall p \in People \: [ \neg likes(p, d)] 
> $$ 
> ------------
> To negate it, we can do the following:
> 
> $$
>  \neg \big( \exists d \in Dishes, \forall p \in People \: [ \neg likes(p, d)] \big)
> $$ 
> 
> Which we can simplify to:
> $$
>  \forall d \in Dishes, \exists p \in People \: [ \neg (\neg likes(p, d))]
> $$ 
> 
> which is also just:
> $$
>  \forall d \in Dishes, \exists p \in People \: [likes(p, d))]
> $$ 
> 
> The negation of the first statement means "Every dish is liked by at least one person."

