
# Overview

In this page, we will provide more examples of proofs written using the proof system that we introduced in Unit 1. The goal of this page is to help you to get familiarised with:

1. How the different proof strategies work
2. How to justify each step of a proof

*NB: As we go along, we will introduce relevant definitions, lemmas and theorems that will be used in the upcoming proofs.* 

---
## Proof Strategy 1: Direct Proof

Proving directly is arguably one of the simplest ways of showing that a statement is true. The overarching concept is to start with a certain set of facts and work your way towards the end result: no fancy propositional logic involved, just a sequence of simple step-by-step deductions.

### Example 1

>[!example] Example 1
>Prove that $even(4)$.

We will refer to the standard definitions:
- $even(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k]$
- $odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k + 1]$

Since we have an **existential** statement, we just need to find one integer $k$ such that $4 = 2 \cdot k$. Clearly, $k$ must be $2$.

Thus, we have:

>[!Proof-1]
>**Proof**:
>1. $4 = 2 \cdot 2$ \[Basic algebra]
>2. $2 \in \mathbb{Z}$ \[Basic algebra]
>3. $\exists k \in \mathbb{Z} \ [4 = 2 \cdot k]$ \[Existential generalisation on lines 1 and 2]
>4. $even(4)$ \[Unpacking definition of $even$]

>[!example] Try It Out!
>Prove that $odd(3)$.


