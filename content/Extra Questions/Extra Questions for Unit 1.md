---
hidden: "true"
---
## Question: Contrapositivity

Given a statement/formula like $p\rightarrow q$, we call the **contrapositive** of that statement as $\neg q\rightarrow \neg p$. 
Draw and fill out a truth table to verify that the statements are logically equivalent.

|    p    |    q    | $p \to q$ | $\neg q$ | $\neg p$ | $\neg q \to \neg p$ |
| :-----: | :-----: | :-------: | :------: | :------: | :-----------------: |
| $true$  | $true$  |           |          |          |                     |
| $true$  | $false$ |           |          |          |                     |
| $false$ | $true$  |           |          |          |                     |
| $false$ | $false$ |           |          |          |                     |

## Question: Basic Quantifiers

Given the sets $A = \{0,1,4\}$ and $B = \{-2,-1,0,1,2\}$, determine which of the following statements are true.

1. $\exists a \in A \: (a^{2} \in B)$
2. $\forall a \in A \: (a^{2} \in B)$
3. $\forall b \in B, \exists a \in A \: (a = b^{2})$
4. $\exists a \in A, \forall b \in B \: (a = b^{2})$

## Question: Properties of integers

>[!Purpose]
>In this question, the goal is to practise unpacking definitions, in this case, of the integers. It is extremely common to encounter new definitions of mathematical objects, and it is useful to be able to understand what those definitions are.

The set of **integers**, denoted $\mathbb{Z}$, is a set that is frequently used, so it is important to understand some of its properties. For this question, we will be unpacking the properties of multiplication on the integers.

For each of the following properties, look through the definition of the property (written in first-order logic), and provide an example of the property. The first property has been done for you.

>[!Question 1]
>**Property 1 (Closure)**: $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \: [a \times b \in \mathbb{Z}]$
>
>**Example**: 
>Let $a=2 \in \mathbb{Z}$ and let $b=-3 \in \mathbb{Z}$. Then, $ab=2\ \times (-3) = -6$, which is also in $\mathbb{Z}$.

>[!Question 2]
>**Property 2 (Commutativity)**: $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \: [a \times b = b \times a]$

>[!Question 3]
>**Property 3 (Associativity)**: $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z}, \forall c \in \mathbb{Z} \: [a \times (b \times c) = (a \times b) \times c]$

>[!Question 4]
>**Property 4 (Existence of identity element)**: $\exists e \in \mathbb{Z}, \forall a \in \mathbb{Z}, \: [a \times e = e \times a = a]$

>[!Question 5]
>**Property 5 (Zero divisors)**: $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \: [(a \times b = 0) \to (a = 0 \lor b = 0)]$



