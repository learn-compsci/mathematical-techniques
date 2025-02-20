
# Overview

In this page, we will provide more examples of proofs written using the proof system that we introduced in Unit 1. The goal of this page is to help you to get familiarised with:

1. How the different proof strategies (i.e., direct proof, proof by cases, proof by contradiction, proof by contrapositive) work
2. How to justify each step of a proof

*Nota Bene: As we go along, we will introduce relevant definitions, lemmas and theorems that will be used in the upcoming proofs.* 

---
## Proof Strategy #1: Direct Proof

Proving directly is arguably one of the simplest ways of showing that a statement is true. The overarching concept is to start with a certain set of facts and work your way towards the end result: no fancy propositional logic involved, just a sequence of simple step-by-step deductions.

### Example 1.1

We will refer to the standard definitions of $even(x)$ and $odd(x)$:
- $even(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k]$
- $odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k + 1]$

>[!example] Example 1.1
>Prove that $even(4)$.

**How do I know where to start?**

Observe that we have an *existential* statement, i.e., we need to show that such a value of $k \in \mathbb{Z}$ exists that fulfils $4 = 2 \cdot k$. Working backwards, we have $k = 2$, so perhaps we could start there.

>[!example]+ Proof 1.1
>**Proof:**
>1. $4 = 2 \cdot 2$ \[Basic algebra]
>2. $2 \in \mathbb{Z}$ \[Basic algebra]
>3. $\exists k \in \mathbb{Z} \ [4 = 2 \cdot k]$ \[Existential generalisation on lines 1, 2]
>4. $even(4)$ \[Unpacking definition of $even$]

>[!tip] Try It Out!
>Prove that $odd(3)$.
>

>[!tip]- Solution
>**Proof:**
>1. $3 = 2 \cdot 1 + 1$. \[Basic algebra]
>2. $1 \in \mathbb{Z}$ \[Basic algebra]
>3. $\exists k \in \mathbb{Z} \ [3 = 2 \cdot k + 1]$ \[Existential generalisation on lines 1, 2]
>4. $odd(3)$ \[Unpacking definition of $odd$]

### Example 1.2

We will refer to the following definition for rational numbers: 
$$x \in \mathbb{Q} \equiv \exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ \bigg[q \neq 0 \land x = \frac{p}{q}\bigg]$$

>[!example] Example 1.2
>Prove that $\forall n \in \mathbb{Z} \ [n \in \mathbb{Q}]$.

**How do I know where to start?**

Now, we have a *universal* statement, so we need to prove the statement for every possible integer $n$. Doing so manually is clearly impossible, but we can **instantiate** an arbitrary value $n$ and show that the statement is true for this particular $x$. Finally, we **generalise** it back into a universal statement.

Regarding the statement itself, it is not hard to see why the statement should be true: for every integer $x$, we have $x = \frac{x}{1}$, and $\frac{x}{1}$ is clearly a rational number!

>[!example]+ Proof 1.2
>**Proof:**
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. $1 \in \mathbb{Z}$ \[Basic algebra]
>3. $n = \frac{n}{1}$. \[Basic algebra]
>4. $1 \neq 0$ \[Basic algebra]
>5. $1 \neq 0 \land n = \frac{n}{1}$ \[Conjunction on lines 3, 4]
>6. $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ \big[q \neq 0 \land n = \frac{p}{q}\big]$ \[Existential generalisation on line 5]
>7. $n \in \mathbb{Q}$ \[Definition of $\mathbb{Q}$]
>8. $\forall n \in \mathbb{Z} \ [n \in \mathbb{Q}]$ \[Universal generalisation on lines 1, 7]
>---
>**Rules of deduction/inference used:**
>- On line 5, we performed a **conjunction** because the definition of $\mathbb{Q}$ required the proposition "$q \neq 0 \land n = \frac{p}{q}$" to appear. To make this explicit, we rewrite lines 3 and 4 into a form that looks *exactly* like it.
>- On line 6, we used **existential generalisation** to rewrite line 5 *into a form that we recognise as the definition of $\mathbb{Q}$*.
>- On line 7, we "reverse engineered" the definition of $\mathbb{Q}$.
>- On line 8, we used **universal generalisation** to restore the statement to its original, universal form.
>  
>  

>[!faq] Why do I need to mention that $1$ is in $\mathbb{Z}$?
>This is because the *definition* of the rational numbers requires that the numerator and the denominator in our fraction have to be integers themselves ("$\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z}$"). Therefore, to fit the definition explicitly, we should state that $n$ and $1$ are also integers.

>[!tip] Try It Out!
>Prove that $\forall n \in \mathbb{Q} \ [2n \in \mathbb{Q}]$.

>[!tip]- Solution
>**Proof:**
>1. Let $n \in \mathbb{Q}$ be arbitrarily chosen.
>2. $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ [q \neq 0 \land x = \frac{p}{q}]$ \[Definition of $\mathbb{Q}$]
>3. Let $s, t \in \mathbb{Z}$ be such that $t \neq 0 \land n = \frac{s}{t}$. \[Universal instantiation on lines 1, 2]
>4. $n = \frac{s}{t}$ \[Specialisation on line 3]
>5. Since $s \in \mathbb{Z}$, $2s \in \mathbb{Z}$. \[Basic algebra]
>6. $2n = 2 \cdot \frac{s}{t} = \frac{2s}{t}$ \[Basic algebra]
>7. $t \neq 0$ \[Specialisation on line 3]
>8. $t \neq 0 \land 2n = \frac{2s}{t}$ \[Conjunction on lines 6, 7]
>9. $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ [q \neq 0 \land 2n = \frac{p}{q}]$ \[Existential generalisation on line 8]
>10. $2n \in \mathbb{Q}$ \[Definition of $\mathbb{Q}$]
>11. $\forall n \in \mathbb{Q} \ [2n \in \mathbb{Q}]$ \[Universal generalisation on lines 1, 10]

### Example 1.3

For this example, we introduce the concept of congruence. 
$$congruent(a,b,n) \iff \exists k \in \mathbb{Z} \ [a-b = k \cdot n]$$
If $congruent(a,b,n)$, we say that "$a$ is congruent to $b$ modulo $n$".

>[!example] Example 1.3
>Prove that $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z}, \forall n \in \mathbb{Z} \ [congruent(a,b,n) \to congruent(b,a,n)]$.

**How do I know where to start?**

Once again, there are three universal quantifiers involved, so we might instantiate each one of them. Now, our goal is to show that if $a$ is congruent to $b$ modulo $n$, then $b$ is also congruent to $a$ modulo $n$.

Let's try out some examples to get a feel of why this statement would be true. Suppose we pick $25$, $10$ and $5$. Then, $congruent(25,10,5)$ since $25-10=15$, and $15$ is a multiple of $5$. What about $congruent(10,25,5)$? Well, that's also true, because $10-25=-15$, and $-15$ is also a multiple of $5$.

At this point, you might observe that the quantities $a-b$ and $b-a$ are really just the same thing, except that one is positive and the other is negative. In that case, the sign does not affect whether they are multiples of $n$, i.e., if $a-b$ is a multiple of $n$, then $b-a$ must necessarily be a multiple of $n$ as well! And therein lies the insight of the proof.

As for constructing the proof itself, we notice that there is an **implication** in the statement. In such situations, we *assume the antecedent* and try to *prove the consequent*. In other words, if we want to show that $p \to q$, then we assume $p$ and try to prove $q$ by the end.

>[!example]+ Proof 1.3
>**Proof:**
>1. Let $a \in \mathbb{Z}$, $b \in \mathbb{Z}$ and $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume $congruent(a,b,n)$.
>		1. $\exists k \in \mathbb{Z} \ [a-b = k \cdot n]$ \[Definition of $congruent$]
>		2. Let $m \in \mathbb{Z}$ be such that $a-b = m \cdot n$. \[Existential instantiation on line 2.1]
>		3. $b-a = -(a-b) = -(m \cdot n) = (-m) \cdot n$ \[Basic algebra]
>		4. Since $m \in \mathbb{Z}$, $-m \in \mathbb{Z}$. \[Basic algebra]
>		5. $\exists k \in \mathbb{Z} \ [b-a = k \cdot n]$ \[Existential generalisation on lines 2.3, 2.4]
>		6. $congruent(b,a,n)$ \[Definition of $congruent$]
>3. $congruent(a,b,n) \to congruent(b,a,n)$ \[Implication introduction on lines 2, 2.6]
>4. $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z}, \forall n \in \mathbb{Z} \ [congruent(a,b,n) \to congruent(b,a,n)]$ \[Universal generalisation on lines 1, 3]
>---
>**Rules of deduction/inference used:**
>- On line 2.1, we wanted to move from the predicate $congruent$ to an explicit quantified statement so that we can perform instantiation. This was done using **definition unpacking**.
>- On line 2.2, we used **existential instantiation** in order to refer to $m$ as a particular integer instead of working with the variable $k$.
>- On line 2.5, once we have found suitable values, we used **existential generalisation** to rewrite lines 2.3 and 2.4 *into a form that we recognise as the predicate $congruent$*.
>- On line 2.6, we "reverse engineered" the definition unpacking to obtain $congruent$ again.
>- On line 3, we used **implication introduction** so that we can explicitly obtain the statement "$congruent(a,b,n) \to congruent(b,a,n)$" from the original statement to be proved.
>- On line 4, we used **universal generalisation** to restore the statement to its original, universal form.

>[!tip] Try It Out!
>Prove that $\forall x \in \mathbb{Z} \ \big[odd(x) \to odd(x^2)\big]$.

>[!tip]- Solution
>**Proof:**
>1. Let $x \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume that $odd(x)$.
>	1. $\exists k \in \mathbb{Z} \ [x = 2 \cdot k + 1]$ \[Definition of $odd$]
>	2. Let $s \in \mathbb{Z}$ be such that $x = 2 \cdot s + 1$. \[Existential instantiation on line 2.1]
>	3. $x^2 = (2s + 1)^2 = 4s^2 + 4s + 1 = 2 \cdot (2s^2 + 2s) + 1$ \[Basic algebra]
>	4. Since $s \in \mathbb{Z}$, $2s^2 + 2s \in \mathbb{Z}$. \[Basic algebra]
>	5. $\exists k \in \mathbb{Z} \ [x^2 = 2 \cdot k + 1]$ \[Existential generalisation on lines 2.3, 2.4]
>	6. $odd(x^2)$ \[Definition of $odd$]
>3. $odd(x) \to odd(x^2)$ \[Implication introduction on lines 2, 2.6]
>4. $\forall x \in \mathbb{Z} \ \big[odd(x) \to odd(x^2)\big]$ \[Universal generalisation on lines 1, 3]
 
---
## Proof Strategy #2: Proof by Cases

Sometimes, a direct proof might not work because different instances might have different properties, so choosing arbitrarily might not be a good idea. In such situations, we can break down the statement into several cases, and prove each case separately. 

There are **two important properties** to take note when proving by cases:
1. You must consider *all possible cases*.
2. In *every single case*, the statement must hold true.

Keep these two properties in mind as you go through the following proofs!

### Example 2.1

For this example, we introduce the definition of absolute values (also known as modulus) for any real number $x$:
$$
|x|= 
\begin{cases}
x, & \text{if } x > 0 \\
0, & \text {if } x = 0 \\
-x & \text {if } x < 0  
\end{cases}
$$

We will also define the following for real numbers $x$ and $y$:
$$x \geq y \iff x > y \lor x = y$$

>[!example] Example 2.1
>Prove that $\forall x \in \mathbb{R} \ [|x| \geq 0]$.

**How do I know where to start?**

Given the definition of $|x|$, it is not difficult to see how the proof by cases would work: consider each of the three cases, and show that $|x| \geq 0$. The first two cases are trivial, and the last case is easy to show given some basic knowledge of how inequalities work.

>[!example]+ Proof 2.1
>**Proof:**
>1. Let $x \in \mathbb{R}$ be arbitrarily chosen.
>2. Since $x \in \mathbb{R}$, $x > 0 \lor x = 0 \lor x < 0$. \[Basic algebra]
>		1. Case 1: $x > 0$.
>			1. $|x| = x$ \[Definition of absolute value]
>			2. $|x| > 0$ \[Basic algebra, from line 2.1]
>			3. $|x| > 0 \lor |x| = 0$ \[Generalisation on lines 2.1.1, 2.1.2]
>			4. $|x| \geq 0$ \[Definition of $\geq$]
>		2. Case 2: $x = 0$.
>			1. $|x| = 0$ \[Definition of absolute value]
>			2. $|x| > 0 \lor |x| = 0$ \[Generalisation on line 2.2.1]
>			3. $|x| \geq 0$ \[Definition of $\geq$]
>		3. Case 3: $x < 0$.
>			1. $|x| = -x$ \[Definition of absolute value]
>			2. $-x > 0$ \[Basic algebra, from line 2.3]
>			3. $|x| > 0$ \[Basic algebra, from lines 2.3.1, 2.3.2]
>			4. $|x| > 0 \lor |x| = 0$ \[Generalisation on line 2.3.3]
>			5. $|x| \geq 0$ \[Definition of $\geq$]
>3. $|x| \geq 0$ \[Proof by cases on lines 2, 2.1.4, 2.2.3, 2.3.5]
>4. $\forall \in \mathbb{R} \ [|x| \geq 0]$ \[Universal generalisation on lines 1, 3]
>---
>**Rules of deduction/inference used:**
>- On lines 2.1, 2.2 and 2.3, we considered each of the propositions laid out in line 2. Then, in each of those cases, we used **generalisation** to arrive at the statement $|x| \geq 0$.
>- On line 3, we "summarised" the cases using the **proof by cases** rule.
>- On line 4, we used **universal generalisation** to restore the statement to its original, universal form.

>[!tip] Try It Out!
>Prove that $\forall x \in \mathbb{R} \ [|x|^2 = x^2]$.

>[!tip]- Solution
>**Proof:**
>1. Let $x \in \mathbb{R}$ be arbitrarily chosen.
>2. Since $x \in \mathbb{R}$, $x > 0 \lor x = 0 \lor x < 0$. \[Basic algebra]
>	1. Case 1: $x > 0$.
>		1. $|x| = x$ \[Definition of absolute value]
>		2. $|x|^2 = x^2$ \[Basic algebra]
>	2. Case 2: $x = 0$.
>		1. $|x| = 0$ \[Definition of absolute value]
>		2. $|x|^2 = 0^2 = x^2$ \[Basic algebra]
>	3. Case 3: $x < 0$.
>		1. $|x| = -x$ \[Definition of absolute value]
>		2. $|x|^2 = (-x)^2 = x^2$ \[Basic algebra]
>3. $|x|^2 = x^2$ \[Proof by cases on lines 2, 2.1, 2.2, 2.3]
>4. $\forall x \in \mathbb{R} \ [|x|^2 = x^2]$ \[Universal generalisation on lines 1, 3]

### Example 2.2

For this example, we refer to the lemma presented in Q4 of [[Assignment 1]]:

>[!note] Lemma 1
>$\forall x \in \mathbb{Z} \ \big[even(x) \lor odd(x)\big]$.

>[!example] Example 2.2
>Prove that $\forall n \in \mathbb{Z} \ \big[even(3n^2 + n + 14)\big]$.

**How do I know where to start?**

Clearly, our proof must involve finding the value of $3n^2 + n + 14$, then showing that it fits the definition of $even$. Direct proof probably will not be useful, since instantiating $n$ just gives us $3n^2 + n + 14$, and we are back to square one. What if we try proving by cases? Which cases do we consider?

For a start, since we need to prove that something is even, we might just begin by trying even values of $n$ and seeing where that brings us. Suppose $n = 6$. Then, $$3n^2+n+14 = 3 \cdot 6^2 + 6 + 14 = \textcolor{green}{108} + \textcolor{green}{6} + 14 = 128$$
Well, that wasn't too surprising, was it? Each term of the sum is clearly even, so their sum must be even as well! Ok, what about odd numbers then? Let's try $n = 5$: $$3n^2 + n + 14 = 3 \cdot 5^2 + 5 + 14 = \textcolor{red}{75} + \textcolor{red}{5} + 14 = 94$$
Interesting! Somehow, even though the first two terms were not even, their sum ended up being even; one might say that their odd-ness "cancelled out". The question becomes: "Will this 'cancelling out' occur for all odd numbers?"

As it turns out, the answer is **yes**, and we can show this algebraically.

>[!example]+ Proof 2.2
>**Proof:**
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. $even(n) \lor odd(n)$. \[Universal instantiation of Lemma 1]
>		1. Case 1: $even(n)$.
>			1. $\exists k \in \mathbb{Z} \ [n = 2 \cdot k]$ \[Definition of $even$]
>			2. Let $s \in \mathbb{Z}$ be such that $n = 2 \cdot s$. \[Existential instantiation on line 2.1.1]
>			3. $3n^2+n+14 = 3(2s)^2+2s+14 = 12s^2+2s+14 =\dots= 2 \cdot (6s^2+s+7)$ \[Basic algebra]
>			4. Since $s \in \mathbb{Z}$, $6s^2+s+7 \in \mathbb{Z}$. \[Basic algebra]
>			5. $\exists k \in \mathbb{Z} \ [3n^2+n+14 = 2 \cdot k]$ \[Existential generalisation on lines 2.1.3, 2.1.4]
>			6. $even(3n^2+n+14)$ \[Definition of $even$]
>		2. Case 2: $odd(n)$.
>			1. $\exists k \in \mathbb{Z} \ [n = 2 \cdot k + 1]$ \[Definition of $odd$]
>			2. Let $t \in \mathbb{Z}$ be such that $n = 2 \cdot t + 1$. \[Existential instantiation on line 2.2.1]
>			3. $3n^2+n+14 = 3(2t+1)^2+(2t+1)+14 =\dots=2 \cdot (6t^2+7t+9)$ \[Basic algebra]
>			4. Since $t \in \mathbb{Z}$, $6t^2+7t+9 \in \mathbb{Z}$. \[Basic algebra]
>			5. $\exists k \in \mathbb{Z} \ [3n^2+n+14 = 2 \cdot k]$ \[Existential generalisation on lines 2.2.3, 2.2.4]
>			6. $even(3n^2+n+14)$ \[Definition of $even$]
>3. $even(3n^2+n+14)$ \[Proof by cases on lines 2, 2.1.6, 2.2.6]
>4. $\forall n \in \mathbb{Z} \ \big[even(3n^2 + n + 14)\big]$ \[Universal generalisation on lines 1, 3]

>[!tip] Try It Out!
>Prove that $\forall n \in \mathbb{Z} \ \big[odd(n^2 - 5n + 7)\big]$.

>[!tip]- Solution
>**Proof:**
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. $even(n) \lor odd(n)$. \[Universal instantiation of Lemma 1]
>	1. Case 1: $even(n)$.
>		1. $\exists k \in \mathbb{Z} \ [n = 2 \cdot k]$ \[Definition of $even$]
>		2. Let $s \in \mathbb{Z}$ be such that $n = 2 \cdot s$. \[Existential instantiation on line 2.1.1]
>		3. $n^2-5n+7 = (2s)^2-5(2s)+7 =\dots= 2 \cdot (2s^2-5s+3) + 1$ \[Basic algebra]
>		4. Since $s \in \mathbb{Z}$, $2s^2-5s+3 \in \mathbb{Z}$. \[Basic algebra]
>		5. $\exists k \in \mathbb{Z} \ [n^2-5n+7 = 2 \cdot k + 1]$ \[Existential generalisation on lines 2.1.3, 2.1.4]
>		6. $odd(n^2-5n+7)$ \[Definition of $odd$]
>	2. Case 2: $odd(n)$.
>		1. $\exists k \in \mathbb{Z} \ [n = 2 \cdot k + 1]$ \[Definition of $odd$]
>		2. Let $t \in \mathbb{Z}$ be such that $n = 2 \cdot t + 1$. \[Existential instantiation on line 2.2.1]
>		3. $n^2-5n+7 = (2t+1)^2-5(2t+1)+7 =\dots= 2 \cdot (2t^2-3t+1) + 1$ \[Basic algebra]
>		4. Since $t \in \mathbb{Z}$, $2t^2-3t+1 \in \mathbb{Z}$. \[Basic algebra]
>		5. $\exists k \in \mathbb{Z} \ [n^2-5n+7 = 2 \cdot k + 1]$ \[Existential generalisation on lines 2.2.3, 2.2.4]
>		6. $odd(n^2-5n+7)$ \[Definition of $odd$]
>3. $odd(n^2-5n+7)$ \[Proof by cases on lines 2, 2.1.6, 2.2.6]
>4. $\forall n \in \mathbb{Z} \ \big[odd(n^2 - 5n + 7)\big]$ \[Universal generalisation on lines 1, 3]

### Example 2.3

For this example, we will refer to the following definition of divisibility: $$divides(a,b) \iff \exists k \in \mathbb{Z} \ [b = a \cdot k]$$
To aid our proof, we will also introduce the following lemma:

>[!note] Lemma 2
>$\forall n \in \mathbb{Z} \ \big[congruent(n,0,3) \lor congruent(n,1,3) \lor congruent(n,2,3)\big]$.

>[!example] Example 2.3
>Prove that $\forall n \in \mathbb{Z} \ \big[divides\big(3,n(n-1)(n+1)\big)\big]$.

**How do I know where to start?**

As always, when it doesn't seem obvious how a statement could be true, it is good practice to try out some values to get a sense of how the proof might work.

Suppose we pick $n = 2$. Then, $n(n-1)(n+1) = 2 \cdot 1 \cdot 3 = 6$, which is divisible by $3$. How about $n = 6$? Then, $n(n-1)(n+1) = 6 \cdot 5 \cdot 7 = 210$, which is also divisible by $3$. One last one: $n = 10$. Then, $n(n-1)(n+1) = 10 \cdot 9 \cdot 11 = 990$, and that is also divisible by $3$. Ok, it seems plausible that the statement is true! Now, let's dig deeper and try to understand why.

- When $n=2$, one might observe that the result was divisible by $3$ thanks to the last number: $3$, which was the "$n+1$" factor of our product.
- When $n = 6$, the product is obviously divisible by $3$ thanks to the "$n$" factor of our product.
- When $n = 10$, the product was divisible by $3$ because of the number $9$, which was due to the "$n-1$" factor of our product.

Hmm, it seems like no matter which number we pick, there will always be a factor (either $n$, $n-1$, or $n+1$) that is divisible by $3$. How strange!

>[!example]+ Proof 2.3
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. $congruent(n,0,3) \lor congruent(n,1,3) \lor congruent(n,2,3)$. \[Universal instantiation of Lemma 2]
>		1. Case 1: $congruent(n,0,3)$.
>			1. $\exists k \in \mathbb{Z} \ [n - 0 = 3 \cdot k]$ \[Definition of $congruent$]
>			2. Let $r \in \mathbb{Z}$ be such that $n - 0 = 3 \cdot r$. \[Existential instantiation on line 2.1.1]
>			3. $n(n-1)(n+1)=(3r)(3r-1)(3r+1)=3 \cdot [r(3r-1)(3r+1)]$ \[Basic algebra]
>			4. Since $r \in \mathbb{Z}$, $r(3r-1)(3r+1) \in \mathbb{Z}$. \[Basic algebra]
>			5. $\exists k \in \mathbb{Z} \ [n(n-1)(n+1) = 3 \cdot k]$ \[Existential generalisation on lines 2.1.3, 2.1.4]
>			6. $divides\big(3, n(n-1)(n+1)\big)$ \[Definition of $divides$]
>		2. Case 2: $congruent(n,1,3)$.
>			1. $\exists k \in \mathbb{Z} \ [n - 1 = 3 \cdot k]$ \[Definition of $congruent$]
>			2. Let $s \in \mathbb{Z}$ be such that $n - 1 = 3 \cdot s$. \[Existential instantiation on line 2.2.1]
>			3. $n(n-1)(n+1)=(3s+1)(3s)(3s+2)=3 \cdot [s(3s+1)(3s+2)]$ \[Basic algebra]
>			4. Since $s \in \mathbb{Z}$, $s(3s+1)(3s+2) \in \mathbb{Z}$. \[Basic algebra]
>			5. $\exists k \in \mathbb{Z} \ [n(n-1)(n+1) = 3 \cdot k]$ \[Existential generalisation on lines 2.2.3, 2.2.4]
>			6. $divides\big(3, n(n-1)(n+1)\big)$ \[Definition of $divides$]
>		3. Case 3: $congruent(n,2,3)$.
>			1. $\exists k \in \mathbb{Z} \ [n - 2 = 3 \cdot k]$ \[Definition of $congruent$]
>			2. Let $t \in \mathbb{Z}$ be such that $n - 2 = 3 \cdot t$. \[Existential instantiation on line 2.3.1]
>			3. $n(n-1)(n+1)=(3t+2)(3t+1)(3t)=3 \cdot [t(3t+2)(3t+1)]$ \[Basic algebra]
>			4. Since $t \in \mathbb{Z}$, $t(3t+2)(3t+1) \in \mathbb{Z}$. \[Basic algebra]
>			5. $\exists k \in \mathbb{Z} \ [n(n-1)(n+1) = 3 \cdot k]$ \[Existential generalisation on lines 2.3.3, 2.3.4]
>			6. $divides\big(3, n(n-1)(n+1)\big)$ \[Definition of $divides$]
>3. $divides\big(3, n(n-1)(n+1)\big)$ \[Proof by cases on lines 2, 2.1.6, 2.2.6, 2.3.6]
>4. $\forall n \in \mathbb{Z} \ \big[divides\big(3, n(n-1)(n+1)\big)\big]$ \[Universal generalisation on lines 1, 3]

>[!tip] Try It Out!
>Prove that $\forall n \in \mathbb{Z} \ \big[congruent(n^2,0,4) \lor congruent(n^2,1,4)\big]$.
>
>*Hint: There are **two** cases to consider.*

>[!tip]- Solution
>**Proof:**
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. $even(n) \lor odd(n)$ \[Universal instantiation of Lemma 1]
>	1. Case 1: $even(n)$.
>		1. $\exists k \in \mathbb{Z} \ [n = 2 \cdot k]$ \[Definition of $even$]
>		2. Let $s \in \mathbb{Z}$ be such that $n = 2 \cdot s$. \[Existential instantiation on line 2.1.1]
>		3. $n^2  - 0 = n^2 = (2s)^2 = 4 \cdot s^2$ \[Basic algebra]
>		4. Since $s \in \mathbb{Z}$, $s^2 \in \mathbb{Z}$. \[Basic algebra]
>		5. $\exists k \in \mathbb{Z} \ [n^2 - 0 = 4 \cdot k]$ \[Existential generalisation on lines 2.1.3, 2.1.4]
>		6. $congruent(n^2,0,4)$ \[Definition of $congruent$]
>		7. $congruent(n^2,0,4) \lor congruent(n^2,1,4)$ \[Generalisation on line 2.1.6]
>	2. Case 2: $odd(n)$.
>		1. $\exists k \in \mathbb{Z} \ [n = 2 \cdot k + 1]$ \[Definition of $odd$]
>		2. Let $t \in \mathbb{Z}$ be such that $n = 2 \cdot t + 1$. \[Existential instantiation on line 2.2.1]
>		3. $n^2 - 1 = (2t+1)^2 - 1 = 4t^2 + 4t + 1 - 1 = 4t^2 + 4t = 4 \cdot (t^2+t)$ \[Basic algebra]
>		4. Since $t \in \mathbb{Z}$, $t^2 + t \in \mathbb{Z}$. \[Basic algebra]
>		5. $\exists k \in \mathbb{Z} \ [n^2 - 1 = 4 \cdot k]$ \[Existential generalisation on lines 2.2.3, 2.2.4]
>		6. $congruent(n^2,1,4)$ \[Definition of $congruent$]
>		7. $congruent(n^2,0,4) \lor congruent(n^2,1,4)$ \[Generalisation on line 2.2.6]
>3. $congruent(n^2,0,4) \lor congruent(n^2,1,4)$ \[Proof by cases on lines 2, 2.1.7, 2.2.7]
>4. $\forall n \in \mathbb{Z} \ [congruent(n^2,0,4) \lor congruent(n^2,1,4)]$ \[Universal generalisation on lines 1, 3]

---
## Proof Strategy #3: Proof by Contradiction

Often, proving directly (be it using direct proof or proving by cases) is infeasible or downright impossible. In such cases, we have two options: proving by contradiction, or proving by contrapositive. However, when there isn't an implication in the statement, it might be difficult to prove by contrapositive; here's where proofs by contradiction can be useful!

Throughout the examples in this section, pay attention to the following:

1. The "conjunction-contradiction-proof by contradiction" trio at the end of each proof
2. How the contradictions were derived without circular reasoning

### Example 3.1

>[!example] Example 3.1
>Prove that $\forall n \in \mathbb{Z} \ [3n \neq 1]$.

**How do I know where to start?**

Clearly, the statement is true, since $3n$ must be a multiple of $3$, which $1$ is evidently not. If we proceeded to prove the statement directly as per usual, we quickly run into a problem:

**Attempt**:
1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
2. $\dots \ ?$

There is no property about an arbitrary integer $n$ that tells us $3n$ cannot be $1$, as painfully obvious as it might seem! In times like these, we can try a proof by contradiction instead.

The contradiction arises when we suppose that there *is indeed* a number $n$ where $3n = 1$, namely that $n = \frac{1}{3}$ is not possible since we already assumed that $n$ is an integer.

>[!example] Proof 3.1
>**Proof:**
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume, for the sake of contradiction, that $\neg (3n \neq 1)$.
>		1. $3n = 1$ \[Logically equivalent to line 2]
>		2. $n = \frac{1}{3}$ \[Basic algebra]
>		3. $\neg \big(\frac{1}{3} \in \mathbb{Z}\big)$ \[Basic algebra]
>		4. Since $n \in \mathbb{Z}$ and $n = \frac{1}{3}$, $\frac{1}{3} \in \mathbb{Z}$. \[Basic algebra, from line 1, 2.2]
>		5. $\big(\frac{1}{3} \in \mathbb{Z}\big) \land \neg \big(\frac{1}{3} \in \mathbb{Z}\big)$ \[Conjunction on lines 2.3, 2.4]
>		6. $\bot$. \[Contradiction rule on line 2.5]
>3. $3n \neq 1$ \[Proof by contradiction rule on lines 2, 2.6]
>4. $\forall n \in \mathbb{Z} \ [3n \neq 1]$ \[Universal generalisation on lines 1, 3]

>[!tip] Try It Out!
>Prove that $\forall a \in \mathbb{N}, \forall b \in \mathbb{N}\ [10a + 15b \neq 5]$.

>[!tip]- Solution
>**Proof:**
>1. Let $a \in \mathbb{Z}$ and $b \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume, for the sake of contradiction, that $\neg (10a + 15b \neq 5)$.
>	1. $10a + 15b = 1$. \[Logically equivalent to line 2]
>	2. $2a + 3b = \frac{1}{5}$ \[Basic algebra]
>	3. $\neg \big(\frac{1}{5} \in \mathbb{Z}\big)$ \[Basic algebra]
>	4. Since $a, b \in \mathbb{Z}$, $2a + 3b \in \mathbb{Z}$, so $\frac{1}{5} \in \mathbb{Z}$. \[Basic algebra, from lines 1, 2.2]
>	5. $\big(\frac{1}{5} \in \mathbb{Z}\big) \land \neg \big(\frac{1}{5} \in \mathbb{Z}\big)$ \[Conjunction on lines 2.3, 2.4]
>	6. $\bot$. \[Contradiction rule on line 2.5]
>3. $10a + 15b \neq 5$ \[Proof by contradiction rule on lines 2, 2.6]
>4. $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \ [10a + 15b \neq 1]$ \[Universal generalisation on lines 1, 3]

### Example 3.2

For this example, we denote the set of positive rational numbers as $\mathbb{Q^+}$. That is: $$x \in \mathbb{Q^+} \iff x \in \mathbb{Q} \land x > 0$$
>[!example] Example 3.2
>Prove that **there is no smallest positive rational number**, i.e., prove that: $$\forall x \in \mathbb{Q^+}, \exists y \in \mathbb{Q^+}\ [y < x]$$

**How do I know where to start?**

First, we might try to figure out if the statement is even true. What about $x = \frac{1}{2}$? Then we can just let $y = \frac{1}{3}$, for example, and we see that $y < x$ since $\frac{1}{3} < \frac{1}{2}$. What about $x = \frac{4}{7654321}$? Well, we can let $y = \frac{2}{7654321}$ and again find that $y < x$! 

Let's think about this more abstractly. What does a "smallest positive rational number" $x$ that breaks this rule look like? If $x$ were indeed the smallest positive rational number, that means that every other positive rational number is somehow equal to or greater than it. However, as we've seen, that is clearly impossible since we can just halve $x$ to get a smaller rational number!

Therefore, we assume that the original statement is false (i.e., there *is indeed* a smallest positive rational number), and then somehow conjure the aforementioned contradiction.

>[!example]+ Proof 3.2
>**Proof:**
>1. Let $x \in \mathbb{Q^+}$ be arbitrarily chosen.
>2. Assume, for the sake of contradiction, that $\neg \big(\exists y \in \mathbb{Q^+} \ [y < x]\big)$.
>		1. $\forall y \in \mathbb{Q^+} \ [y \geq x]$ \[Logically equivalent to line 2]
>		2. Consider $\frac{x}{2}$. 
>			1. Since $x \in \mathbb{Q^+}$, $\frac{x}{2} \in \mathbb{Q^+}$. \[Basic algebra]
>			2. Since $x > 0$, then $\frac{x}{2} > 0$. \[Basic algebra]
>			3. $x - \frac{x}{2} = \frac{x}{2} > 0$. \[Basic algebra, from line 2.2.2]
>			4. $\frac{x}{2} < x$ \[Basic algebra, from line 2.2.3]
>			5. $\exists y \in \mathbb{Q^+} \ [y < x]$ \[Existential generalisation on lines 2.2.1, 2.2.4]
>			6. $\neg \big(\forall y \in \mathbb{Q^+} \ [y \geq x]\big)$ \[Logically equivalent to line 2.2.5]
>		3. $\big(\forall y \in \mathbb{Q^+} \ [y \geq x]\big) \land \neg \big(\forall y \in \mathbb{Q^+} \ [y \geq x]\big)$ \[Conjunction on lines 2.1, 2.2.6]
>		4. $\bot$. \[Contradiction rule on line 2.3]
>3. $\exists y \in \mathbb{Q^+} \ [y < x]$ \[Proof by contradiction rule on lines 2, 2.4]
>4. $\forall x \in \mathbb{Q^+}, \exists y \in \mathbb{Q^+} \ [y < x]$ \[Universal generalisation on lines 1, 3]
>---
>**Rules of deduction/inference used:**
>- On line 2, we **assume the negation of our original statement**. From here on, *there is no new information used*, only a sequence of logically deductions to derive the contradiction on line 2.2.4.
>- On line 2.1, we produce the first half of our contradiction.
>- On line 2.2, we construct a concrete number (in this case, $\frac{x}{2}$) so that by line 2.2.6 we are able to produce the second half of our contradiction.
>- On line 2.3, we used **conjunction** to link the two halves (lines 2.1 and 2.2.6).
>- On line 2.4, we used the **contradiction rule** to create the "$\bot$" statement.
>- On line 3, we used the **proof by contradiction rule** to conclude that our initial assumption (line 2) was faulty, thereby proving our original statement.


>[!faq] Can I do the following?
>**(Bad, Informal) Proof:**
>1. Assume, for the sake of contradiction, that there exists a smallest positive rational number.
>2. Let $r \in \mathbb{Z}$ be the smallest positive number. \[Existential instantiation on line 1]
>3. However, since there is no smallest positive rational number, $r$ cannot exist.
>4. $\bot$. \[Contradiction rule on line 3]
>5. Hence, there is no smallest positive rational number. \[Proof by contradiction rule on line 4]
>---
>**No, you cannot!**
>
>This is a classic example of *circular reasoning*: using the original statement as a justification for a proof of that same statement is not allowed. In essence, the proof does the following:
>6. We are trying to prove that a smallest positive rational number, $r$, does not exist.
>7. If we claim that $r$ exists, then we are wrong, because $r$ doesn't exist.
>
>**So how should it be done?**
>
>Instead, one should try to refute the statement that results from our (incorrect) assumption, **without referring to the original statement**, and relying on other facts instead, e.g., basic algebraic facts/axioms, or other intermediate conclusions that resulted due to our initial assumption.

>[!tip] Try It Out!
>Prove that **there is no largest integer**, i.e., prove that: $$\forall x \in \mathbb{Z}, \exists y \in \mathbb{Z} \ [y > x]$$

>[!tip]- Solution
>8. Let $x \in \mathbb{Z}$ be arbitrarily chosen.
>9. Assume, for the sake of contradiction, that $\neg \big(\exists y \in \mathbb{Z} \ [y > x]\big)$.
>	1. $\forall y \in \mathbb{Z} \ [x \geq y]$ \[Logically equivalent to line 2]
>	2. Consider $x + 1$.
>		1. Since $x \in \mathbb{Z}$, $x + 1 \in \mathbb{Z}$. \[Basic algebra]
>		2. $x < x + 1$ \[Basic algebra]
>		3. $\exists y \in \mathbb{Z} \ [x < y]$ \[Existential generalisation on lines 2.2.1, 2.2.2]
>		4. $\neg \big(\forall y \in \mathbb{Z} \ [x \geq y]\big)$ \[Logically equivalent to line 2.2.3]
>	3. $\big(\forall y \in \mathbb{Z} \ [x \geq y]\big) \land \neg \big(\forall y \in \mathbb{Z} \ [x \geq y]\big)$ \[Conjunction on lines 2.1, 2.2.4]
>	4. $\bot$. \[Contradiction rule on line 2.3]
>10. $\exists y \in \mathbb{Z} \ [y > x]$ \[Proof by contradiction rule on lines 2, 2.4]
>11. $\forall x \in \mathbb{Z}, \exists y \in \mathbb{Z} \ [y > x]$ \[Universal generalisation on lines 1, 3]

### Example 3.3

>[!note] Definition of irrational numbers
>A real number $x$ is said to be **irrational** if and only if $x \notin \mathbb{Q}$.

>[!example] Example 3.3
>Prove that the sum of any irrational number and any rational number is itself irrational, i.e., prove that $$\forall x \in \mathbb{R} \setminus \mathbb{Q}, \forall y \in \mathbb{Q} \ [x + y \notin \mathbb{Q}]$$

Here, the set $\mathbb{R} \setminus \mathbb{Q}$ refers to the set of real irrational numbers.

**How do I know where to start?**

Since irrational numbers do not have an explicit form of construction (unlike the rational numbers, which can be expressed as $\frac{p}{q}$ for some integers $p$ and $q$, with $q$ being non-zero), it is difficult to prove this directly. We can no longer instantiate an irrational number based on a quantified statement. Hence, it might be a good idea to try a proof by contradiction instead.

Suppose instead that the sum $s$ of some irrational $x$ and rational $y$ does turn out to be rational; we want to show that leads us to a contradiction. An obvious contradiction we can attempt to show is that $y$ ends up being rational, i.e., we want to express $y$ in a way such that $y$ is some fraction of integers. Clearly, $y = s - x$, and the right-hand side is rational thanks to $s$ and $x$ — hmm, looks promising!

>[!example] Proof 3.3
>**Proof:**
>1. Let $a \in \mathbb{R} \setminus \mathbb{Q}$ and $b \in \mathbb{Q}$ be arbitrarily chosen.
>2. Since $b \in \mathbb{Q}$, $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z}\ \big[q \neq 0 \land b = \frac{p}{q}\big]$ \[Definition of $\mathbb{Q}$]
>3. Let $p_1 \in \mathbb{Z}$ and $q_1 \in \mathbb{Z}$ be such that $q_1 \neq 0 \land b = \frac{p_1}{q_1}$. \[Existential instantiation on line 2]
<<<<<<< HEAD
>4. Assume, for the sake of contradiction, that $a + b \in \mathbb{Q}$.
>	1. Since $a + b \in \mathbb{Q}$, $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z}\ \big[q \neq 0 \land \big(a + b = \frac{p}{q}\big)\big]$ \[Definition of $\mathbb{Q}$]
>	2. Let $p_2 \in \mathbb{Z}$ and $q_2 \in \mathbb{Z}$ be such that $q_2 \neq 0 \land \big(a + b = \frac{p_2}{q_2}\big)$. \[Existential instantiation on line 4.1]
>	3. $a = (a + b) - b = \frac{p_2}{q_2} - \frac{p_1}{q_1} = \frac{p_2q_1 - p_1q_2}{q_1q_2}$ \[Basic algebra]
>	4. $q_1 \neq 0$ \[Specialisation on line 3]
>	5. $q_2 \neq 0$ \[Specialisation on line 4.2]
>	6. Since $q_1 \neq 0$ and $q_2 \neq 0$, $q_1q_2 \neq 0$. \[Basic algebra, from lines 4.4, 4.5]
>	7. Since $p_1, q_1, p_2, q_2 \in \mathbb{Z}$, $p_2q_1 - p_1q_2 \in \mathbb{Z}$. \[Basic algebra, from lines 3, 4.2]
>	8. $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ \big[q \neq 0 \land a = \frac{p}{q}\big]$ \[Existential generalisation on lines 4.3, 4.6, 4.7]
>	9. $a \in \mathbb{Q}$ \[Definition of $\mathbb{Q}$]
>	10. $a \in \mathbb{R} \setminus \mathbb{Q}$ \[From line 1]
>	11. $a \in \mathbb{R} \land \neg (a \in \mathbb{Q})$ \[Definition of [[Unit 2#Set Difference|set difference]]]
>	12. $\neg (a \in \mathbb{Q})$ \[Specialisation on line 4.11]
>	13. $(a \in \mathbb{Q}) \land \neg (a \in \mathbb{Q})$ \[Conjunction on lines 4.9, 4.12]
>	14. $\bot$. \[Contradiction rule on line 4.13]
=======
>1. Assume, for the sake of contradiction, that $a + b \in \mathbb{Q}$.
>		1. Since $a + b \in \mathbb{Q}$, $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z}\ \big[q \neq 0 \land \big(a + b = \frac{p}{q}\big)\big]$ \[Definition of $\mathbb{Q}$]
>		2. Let $p_2 \in \mathbb{Z}$ and $q_2 \in \mathbb{Z}$ be such that $q_2 \neq 0 \land \big(a + b = \frac{p_2}{q_2}\big)$. \[Existential instantiation on line 4.1]
>		3. $a = (a + b) - b = \frac{p_2}{q_2} - \frac{p_1}{q_1} = \frac{p_2q_1 - p_1q_2}{q_1q_2}$ \[Basic algebra]
>		4. $q_1 \neq 0$ \[Specialisation on line 3]
>		5. $q_2 \neq 0$ \[Specialisation on line 4.2]
>		6. Since $q_1 \neq 0$ and $q_2 \neq 0$, $q_1q_2 \neq 0$. \[Basic algebra, from lines 4.4, 4.5]
>		7. Since $p_1, q_1, p_2, q_2 \in \mathbb{Z}$, $p_2q_1 - p_1q_2 \in \mathbb{Z}$. \[Basic algebra, from lines 3, 4.2]
>		8. $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ \big[q \neq 0 \land a = \frac{p}{q}\big]$ \[Existential generalisation on lines 4.3, 4.6, 4.7]
>		9. $a \in \mathbb{Q}$ \[Definition of $\mathbb{Q}$]
>		10. $a \in \mathbb{R} \setminus \mathbb{Q}$ \[From line 1]
>		11. $a \in \mathbb{R} \land \neg (a \in \mathbb{Q})$ \[Definition of [[Unit 2#Set Difference|set difference]]]
>		12. $\neg (a \in \mathbb{Q})$ \[Specialisation on line 4.11]
>		13. $(a \in \mathbb{Q}) \land \neg (a \in \mathbb{Q})$ \[Conjunction on lines 4.9, 4.12]
>		14. $\bot$. \[Contradiction rule on line 4.13]
>>>>>>> d48c8172cd6106f2c41daf51ab287f0e63f51053
>5. $a + b \notin \mathbb{Q}$. \[Proof by contradiction rule on lines 4, 4.14]
>6. $\forall x \in \mathbb{R} \setminus \mathbb{Q}, \forall y \in \mathbb{Q} \ [x + y \notin \mathbb{Q}]$ \[Universal generalisation on lines 1, 5]

---

## Proof Strategy #4: Proof by Contrapositive


Finally, we have proofs by contrapositive. This strategy is useful when there is an implication $p \to q$ in the statement we are trying to prove, and proving $q$ from $p$ directly is difficult. Instead, we suppose $\neg p$ and try to show $\neg q$. This gives us $\neg q \to \neg p$, which is [[Unit 1#Contrapositivity|logically equivalent]] to $p \to q$. 

### Example 4.1

>[!example] Example 4.1
>Prove that $\forall x \in \mathbb{R} \ [x^2 \leq 0 \to x = 0]$.

**How do I know where to start?**

If we begin by assuming that $x^2 \leq 0$, we might have to break it up into two cases: $x^2 < 0$ or $x^2 = 0$. In the first case, we would need to say that $x^2$ is always non-negative and *somehow* mention that no real number $x$ falls under that case. This is getting messy.

Instead, if we look at the contrapositive, all we need to do is show that if $x \neq 0$, then $x^2 > 0$, which is simple algebra!

>[!example] Proof 4.1
>**Proof:**
>1. Let $x \in \mathbb{R}$ be arbitrarily chosen.
>2. Assume that $x \neq 0$.
>		1. $x > 0 \lor x < 0$ \[Basic algebra]
>		2. Case 1: $x > 0$.
>			1. $x^2 > 0$ \[Basic algebra]
>		3. Case 2: $x < 0$.
>			1. $x^2 > 0$ \[Basic algebra]
>		4. $x^2 > 0$ \[Proof by cases on lines 2.1, 2.2.1, 2.2.2]
>3. $x \neq 0 \to x^2 > 0$ \[Implication introduction on lines 2, 2.4]
>4. $x^2 \leq 0 \to x = 0$ \[Logically equivalent to line 3]
>5. $\forall x \in \mathbb{R} \ [x^2 \leq 0 \to x = 0]$ \[Universal generalisation on lines 1, 4]
>---
>**Rules of deduction/inference used:**
>- On line 2, we assumed the negation of the consequent (i.e., our $\neg q$).
>- Through a series of algebraic deductions, line 2.4 concludes the negation of the antecedent (i.e., our $\neg p$).
>- On line 3, we used **implication introduction** to connect our $\neg q$ with our $\neg p$, giving us $\neg q \to \neg p$.
>- On line 4, we used the equivalence of contrapositive statements to recover our original statement $p \to q$.

>[!tip] Try It Out!
>Prove that $\forall n \in \mathbb{Z} \ \big[\neg divides(32, n^5) \to odd(n)\big]$.

>[!tip]- Solution
>**Proof:**
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume that $\neg odd(n)$.
>	1. $even(n)$ \[Basic algebra]
>	2. $\exists k \in \mathbb{Z} \ [n = 2 \cdot k]$ \[Definition of $even$]
>	3. Let $t \in \mathbb{Z}$ be such that $n = 2 \cdot t$. \[Existential instantiation on line 2.2]
>	4. $n^5 = (2t)^5 = 32 \cdot t^5$ \[Basic algebra]
>	5. Since $t \in \mathbb{Z}$, $t^5 \in \mathbb{Z}$. \[Basic algebra]
>	6. $\exists k \in \mathbb{Z} \ [n^5 = 32 \cdot k]$ \[Existential instantiation on lines 2.4, 2.5]
>	7. $divides(32, n^5)$ \[Definition of $divides$]
>3. $\neg odd(n) \to divides(32, n^5)$ \[Implication introduction on lines 2, 2.7]
>4. $\neg divides(32, n^5) \to odd(n)$ \[Logically equivalent to line 3]
>5. $\forall n \in \mathbb{Z} \ \big[\neg divides(32, n^5) \to odd(n)\big]$ \[Universal generalisation on lines 1, 4]

### Example 4.2

>[!example] Example 4.2
>Prove that $\forall m \in \mathbb{Z}, \forall n \in \mathbb{Z} \ \big[even(mn) \to \big(even(m) \lor even(n)\big)\big]$.

**How do I know where to start?**

Let's try the direct proof: Suppose that $mn = 2 \cdot k$ for some integer $k$, and we need to somehow show that either $m$ is even or $n$ is even. Hmm... looks like we're stuck, because we have no way of "splitting" the product $mn$ into anything meaningful! 

Let's try the contrapositive instead: $$\forall m \in \mathbb{Z}, \forall n \in \mathbb{Z} \ \big[\big(odd(m) \land odd(n)\big) \to odd(mn)\big]$$
Ok, this looks much more promising! Now, we have both $odd(m)$ **and** $odd(n)$ to work with, and all we need to do is to show that $mn = 2 \cdot k + 1$ for some integer $k$. This is much simpler to show!

>[!example] Proof 4.2
>**Proof:**
>1. Let $m \in \mathbb{Z}$ and $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume that $\neg \big(even(m) \lor even(n)\big)$.
>		1. $odd(m) \land odd(n)$ \[Logically equivalent to line 2, using basic algebra]
>		2. $odd(m)$ \[Specialisation on line 2.1]
>		3. $\exists k \in \mathbb{Z} \ [m = 2 \cdot k + 1]$ \[Definition of $odd$]
>		4. Let $s \in \mathbb{Z}$ be such that $m = 2 \cdot s + 1$. \[Existential instantiation on line 2.3]
>		5. $odd(m)$ \[Specialisation on line 2.1]
>		6. $\exists k \in \mathbb{Z} \ [n = 2 \cdot k + 1]$ \[Definition of $odd$]
>		7. Let $t \in \mathbb{Z}$ be such that $n = 2 \cdot t + 1$. \[Existential instantiation on line 2.6]
>		8. $mn = (2s+1)(2t+1) = 4st+2s+2t+1 = 2 \cdot (2st+s+t) + 1$ \[Basic algebra]
>		9. Since $s, t \in \mathbb{Z}$, $2st+s+t \in \mathbb{Z}$. \[Basic algebra]
>		10. $\exists k \in \mathbb{Z} \ [mn = 2 \cdot k + 1]$ \[Existential generalisation on lines 2.8, 2.9]
>		11. $odd(mn)$ \[Definition of $odd$]
>		12. $\neg even(mn)$ \[Basic algebra]
>3. $\neg \big(even(m) \lor even(n)\big) \to \neg even(mn)$ \[Implication introduction on lines 2, 2.12]
>4. $even(mn) \to \big(even(m) \lor even(n)\big)$ \[Logically equivalent to line 3, and by basic algebra]
>5. $\forall m \in \mathbb{Z}, \forall n \in \mathbb{Z} \ \big[even(mn) \to \big(even(m) \lor even(n)\big)\big]$ \[Universal generalisation on lines 1, 4]

>[!faq] Why the "basic algebra" on lines 2.1 and 2.12?
>For the sake of illustrating the concept of proving by contrapositive, the nitty-gritty of $$\forall n \in \mathbb{Z} \ [\neg even(n) \to odd(n)]$$ and $$\forall n \in \mathbb{Z} \ [\neg odd(n) \to even(n)]$$ has been left as an exercise for the reader. However, you should still provide the full proof if these lemmas have not yet been established!

>[!tip] Try It Out!
>Prove that $\forall m \in \mathbb{Z}, \forall n \in \mathbb{Z} \ \big[\neg divides(3,mn) \to \neg \big(divides(3,m) \lor divides(3,n)\big)\big]$.

>[!tip]- Solution
>**Proof:**
>1. Let $m \in \mathbb{Z}$ and $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. Assume that $divides(3,m) \lor divides(3,n)$.
>	1. Case 1: $divides(3,m)$.
>		1. $\exists k \in \mathbb{Z} \ [m = 3 \cdot k]$ \[Definition of $divides$]
>		2. Let $s \in \mathbb{Z}$ be such that $m = 3 \cdot s$. \[Existential instantiation on line 2.1.1]
>		3. $mn = (3s)n = 3 \cdot (sn)$ \[Basic algebra]
>		4. Since $s \in \mathbb{Z}$ and $n \in \mathbb{Z}$, $sn \in \mathbb{Z}$. \[Basic algebra]
>		5. $\exists k \in \mathbb{Z} \ [mn = 3 \cdot k]$ \[Existential generalisation on lines 2.1.3, 2.1.4]
>		6. $divides(3, mn)$ \[Definition of $divides$]
>	2. Case 2: $divides(3,n)$.
>		1. $\exists k \in \mathbb{Z} \ [n = 3 \cdot k]$ \[Definition of $divides$]
>		2. Let $t \in \mathbb{Z}$ be such that $n = 3 \cdot t$. \[Existential instantiation on line 2.2.1]
>		3. $mn = m(3t) = 3 \cdot (mt)$ \[Basic algebra]
>		4. Since $m \in \mathbb{Z}$ and $t \in \mathbb{Z}$, $mt \in \mathbb{Z}$. \[Basic algebra]
>		5. $\exists k \in \mathbb{Z} \ [mn = 3 \cdot k]$ \[Existential generalisation on lines 2.2.3, 2.2.4]
>		6. $divides(3,mn)$ \[Definition of $divides$]
>	3. $divides(3,mn)$ \[Proof by cases on lines 2, 2.1.6, 2.2.6]
>3. $\big(divides(3,m) \lor divides(3,n)\big) \to divides(3,mn)$ \[Implication introduction on lines 2, 2.3]
>4. $\neg divides(3,mn) \to \neg \big(divides(3,m) \lor divides(3,n)\big)$ \[Logically equivalent to line 3]
>5. $\forall m \in \mathbb{Z}, \forall n \in \mathbb{Z} \ \big[\neg divides(3,mn) \to \neg \big(divides(3,m) \lor divides(3,n)\big)\big]$ \[Universal generalisation on lines 1, 4]

