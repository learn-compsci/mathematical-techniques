
# Overview

In this page, we will provide more examples of proofs written using the proof system that we introduced in Unit 1. The goal of this page is to help you to get familiarised with:

1. How the different proof strategies work
2. How to justify each step of a proof

*NB: As we go along, we will introduce relevant definitions, lemmas and theorems that will be used in the upcoming proofs.* 

---
## Proof Strategy 1: Direct Proof

Proving directly is arguably one of the simplest ways of showing that a statement is true. The overarching concept is to start with a certain set of facts and work your way towards the end result: no fancy propositional logic involved, just a sequence of simple step-by-step deductions.

### Example 1.1

We will refer to the standard definitions of $even(x)$ and $odd(x)$:
- $even(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k]$
- $odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k + 1]$

>[!example] Example 1.1
>Prove that $even(4)$.

**How do I know where to start?**

Observe that we have an *existential* statement, i.e., we need to show that such a value of $k \in \mathbb{Z}$ exists that fulfils $4 = 2 \cdot k$. Working backwards, we have $k = 2$, so perhaps we could start there.

>[!example] Proof 1.1
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

We will refer to the following definition of rational numbers: $$x \in \mathbb{Q} \iff \exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ \bigg[q \neq 0 \land x = \frac{p}{q}\bigg]$$
>[!example] Example 1.2
>Prove that $\forall n \in \mathbb{Z} \ [n \in \mathbb{Q}]$.

**How do I know where to start?**

Now, we have a *universal* statement, so we need to prove the statement for every possible integer $n$. Doing so manually is clearly impossible, but we can **instantiate** an arbitrary value $n$ and show that the statement is true for this particular $x$. Finally, we **generalise** it back into a universal statement.

Regarding the statement itself, it is not hard to see why the statement should be true: for every integer $x$, we have $x = \frac{x}{1}$, and $\frac{x}{1}$ is clearly a rational number!

>[!example] Proof 1.2
>**Proof:**
>1. Let $n \in \mathbb{Z}$ be arbitrarily chosen.
>2. $1 \in \mathbb{Z}$ \[Basic algebra]
>3. $n = \frac{n}{1}$. \[Basic algebra]
>4. $1 \neq 0$ \[Basic algebra]
>5. $1 \neq 0 \land n = \frac{n}{1}$ \[Conjunction on lines 3, 4]
>6. $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ \big[q \neq 0 \land n = \frac{p}{q}\big]$ \[Existential generalisation on line 5]
>7. $n \in \mathbb{Q}$ \[Definition of $\mathbb{Q}$]
>8. $\forall n \in \mathbb{Z} \ [n \in \mathbb{Q}]$ \[Universal generalisation on lines 1, 7]

>[!faq] Why do I need to mention that $1$ is in $\mathbb{Z}$?
>This is because the *definition* of the rational numbers requires that the numerator and the denominator in our fraction have to be integers themselves ("$\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z}$"). Therefore, to fit the definition explicitly, we should state that $n$ and $1$ are also integers.

>[!tip] Try It Out!
>Prove that $\forall n \in \mathbb{Q} \ [2n \in \mathbb{Q}]$.

>[!tip]- Solution
>**Proof:**
>1. Let $n \in \mathbb{Q}$ be arbitrarily chosen.
>2. $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ [q \neg 0 \land x = \frac{p}{q}]$ \[Definition of $\mathbb{Q}$]
>3. Let $s, t \in \mathbb{Z}$ be such that $t \neq 0 \land n = \frac{s}{t}$. \[Universal instantiation on lines 1, 2]
>4. $n = \frac{s}{t}$ \[Specialisation on line 3]
>5. Since $s \in \mathbb{Z}$, $2s \in \mathbb{Z}$. \[Basic algebra]
>6. $2n = 2 \cdot \frac{s}{t} = \frac{2s}{t}$ \[Basic algebra]
>7. $t \neq 0$ \[Specialisation on line 3]
>8. $t \neq 0 \land 2n = \frac{2s}{t}$ \[Conjunction on lines 6, 7]
>9. $\exists p \in \mathbb{Z}, \exists q \in \mathbb{Z} \ [q \neq 0 \land 2n = \frac{p}{q}]$ \[Existential generalisation on line 8]
>10. $2n \in \mathbb{Q}$ \[Definition of $\mathbb{Q}$]
>11. $\forall n \in \mathbb{Q} \ [2n \in \mathbb{Q}]$ \[Universal generalisation on lines 1, 10]

