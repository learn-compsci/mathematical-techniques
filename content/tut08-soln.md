---
title: CS1231S Tutorial 8 Solutions
tags:
  - Tutorial
hidden: true
---
## Question 1
The idea is the following: we want to alternate the sign of the number first. The easiest way to do that is to use $(-1)^n$. The next thing is that we want this function to sort of center around 0, that means that we start around $n = 0$, and just slowly move around $0$, and do something like $-1$, $1$, etc.

Why $-1$ first? Because when $n = 1$, $(-1)^{1} = -1$.

So consider $$f(n) = (-1)^n \left(\frac{n}{2} + \frac{1}{4}\right) - \frac{1}{4}$$
See how it starts at $0$? 

Okay as usual, we need to prove that:
1. $f : \mathbb{N} \to \mathbb{Z}$ is surjective.
2. $f:\mathbb{N} \to \mathbb{Z}$ is injective.

> [!Lemma]
> It's going to be useful to show this first.
> **Claim: $f(n)$ is negative if and only if $n$ is odd.**
> 1. Let $n \in \mathbb{N}$ be odd. I.e. $\exists t \in\mathbb{N} = 2\cdot t + 1$.
> 2. Then $(-1)^{n} = (-1)^{2t+1} = (-1)^{2t}(-1) = (-1)$
> 3. Then $(-1)^{n}\left(\frac{n}{2} + \frac{1}{4}\right) - \frac{1}{4} = (-1)\left(\frac{2t+1}{2} + \frac{1}{4}\right) - \frac{1}{4}$
> 4. $(-1)\left(\frac{2t+1}{2} + \frac{1}{4}\right) - \frac{1}{4} = (-1)(t + \frac{3}{4}) - \frac{1}{4}$
> 5. $(-1)(t + \frac{3}{4}) - \frac{1}{4} = - t - 1$.
> 6. Since $t \in \mathbb{N}, f(n) < 0$.
> 7. Let $n \in \mathbb{N}$ be even. I.e. $\exists t \in\mathbb{N} = 2\cdot t$.
> 8. $(-1)^{2t} = 1$.
> 9. $(-1)^{n}\left(\frac{n}{2} + \frac{1}{4}\right) - \frac{1}{4} = \left(t  + \frac{1}{4}\right) - \frac{1}{4}$
> 10. $\left(t  + \frac{1}{4}\right) - \frac{1}{4} = t$
> 11. Since $t \in \mathbb{N}$, $t \geq 0$.

> [!Proof]
> **Claim: The given $f$ is surjective.**
> Remark: The tricky part about this one is that when we take an arbitrary $y$ as output of $f$, we don't yet know how to argue whether $n$ is even or odd. So we begin with this first:
> 
> Now we can try to prove surjectivity.
> 1. Let $y \in \mathbb{Z}$ be arbitrarily chosen.
> 2. Either $y \geq 0$ or $y < 0$.
> 3. Case 1: $y \geq 0$
> 	1. Then consider $n = 2y$.
> 	2. Since $f(n) = (-1)^{n}\left(\frac{n}{2} + \frac{1}{4}\right) - \frac{1}{4}$
> 	3. $(-1)^{n}\left(\frac{n}{2} + \frac{1}{4}\right) - \frac{1}{4} = \left(y + \frac{1}{4}\right) - \frac{1}{4}$
> 	4. $\left(y + \frac{1}{4}\right) - \frac{1}{4} = y$
> 	6. Also since $2y = n$, $n \in \mathbb{N}$, by closure of $\times$ on $\mathbb{N}$.
> 	7. Therefore $\exists n \in \mathbb{N} [f(n) = y]$
> 4. Case 2: $y < 0$
> 	1. Then consider $n=-2y-1$.
> 	2. $f(n) = (-1)^{n}\left(\frac{n}{2} + \frac{1}{4}\right) - \frac{1}{4}$
> 	3. $(-1)^{n}\left(\frac{n}{2} + \frac{1}{4}\right) - \frac{1}{4} = (-1)\left(\frac{-2y-1}{2} + \frac{1}{4}\right) - \frac{1}{4}$
> 	4. $(-1)\left(\frac{-2y-1}{2} + \frac{1}{4}\right) - \frac{1}{4}=(-1)(-y-\frac{1}{4}) - frac{1}{4}$
> 	5. $(-1)(-y-\frac{1}{4}) - frac{1}{4}=y$
> 	6. Also since $y < 0$, $2y < 1$, and $-2y \geq 1$, and $-2y - 1\geq 0$.
> 	7. So $n \geq 0$.
> 	8. Also by closure of multiplication and subtraction/addition, $n \in \mathbb{Z}$.
> 	9. Therefore $n \in \mathbb{N}$.
> 	10. Therefore $\exists n \in \mathbb{N} [f(n) = y]$
> 5. In all cases it is shown that $\exists n \in \mathbb{N} [f(n) = y]$.
> 6. By universal generalisation, $\forall y \in \mathbb{Z}, \exists n \in \mathbb{N} [f(n) = y]$.

Now we move to prove $f$ is injective.

> [!Proof]
> **Claim: The given $f$ is injective.**
> 
> 1. Let $x_1, x_2 \in \mathbb{N}$ arbitrarily chosen. Further assume $f(x_1) = f(x_2)$.
> 2. Now, by the Lemma, either both $x_1, x_2$ are even, or $x_1, $x_2$ are odd.
> 3. Case 1: Both $x_1, x_2$ are even.
> 	1. Now $(-1)^{x_1} = 1 = (-1)^{x_2}$.
> 	2. By the assumption, $(-1)^{x_1}\left( \frac{x_1}{2} + \frac{1}{4} \right) - \frac{1}{4} = (-1)^{x_2}\left( \frac{x_2}{2} + \frac{1}{4} \right) - \frac{1}{4}$
> 	3. Then by line 3.1 and basic algebra: $x_1 = x_2$.
> 4. Case 2: Both $x_1, x_2$ are odd.
> 	5. Now $(-1)^{x_1} = -1 = (-1)^{x_2}$.
> 	6. By the assumption, $(-1)^{x_1}\left( \frac{x_1}{2} + \frac{1}{4} \right) - \frac{1}{4} = (-1)^{x_2}\left( \frac{x_2}{2} + \frac{1}{4} \right) - \frac{1}{4}$
> 	7. Then by line 3.1 and basic algebra: $x_1 = x_2$.
> 5. In all cases it is shown that $x_1 = x_2$.
> 6. By universal generalisation, $\forall x_1, x_2 \in \mathbb{N}[f(x_1) = f(x_2) \to x_1 = x_2]$.

## Question 2:
#### Part (a):
> Gonna be honest guys. Never have I ever used a "sequence argument" or heard about it until I looked at the tutorial closely. I don't think any of my friends in math have either. Make of this comment what you will.

1. By lemma 9.2, one may write $C$ out as $c_1, c_2, \ldots, c_n$, for some $n \in \mathbb{N}$.
2. By lemma $9.2$, one may write $B$ out as $b_1, b_2, \ldots$
3. Now consider sequence $c_1, c_2, \ldots, c_n, b_1, b_2, \ldots$
4. This is a sequence that contains all elements of $B \cup C$.
5. Therefore $B \cup C$ is countable. By Lemma 9.2.

> [!Comments]+
> Note here it doesn't extend to the union of two infinite sets.
> Unless you start writing something like:
> $$c_1, b_1, c_2, b_2, c_3, b_3, \ldots$$
> 
> If you write:
> $$c_1, c_2, \ldots, b_1, b_2, \ldots$$
> You're creating something called $\omega + \omega$. But story for another day.

#### Part(b)
I much prefer this. Now the overarching idea is the following, we want the function to map the first $n$ values to elements in $C$, then the $n+1$ values onwards to $B$. What you have is a bijection function $f_c : \mathbb{Z}_n \to C$ and a $f_b : \mathbb{N} \to B$. 

The tricky part is that they're insisting on asking for a bijection so we need to take care to remove duplicates between $B$ and $C$.

So here's the idea:
1. List the elements in $C$ that are not in $B$ first.
2. Then list the elements of $B$.


>[!Proof]
> 1. Let set $F = C \setminus B$. 
> 2. Since $C$ is finite, $F$ is also finite.
> 3. 




