---
hidden: "true"
---
## Question 4

The **contrapositive** of the statement $p\rightarrow q$ is $\neg q\rightarrow \neg p$. Draw a truth table to verify that the statements are logically equivalent.

>[!Solutions]-
> |   $p$   |   $q$   | $\neg q$ | $\neg p$ | $p \rightarrow q$ | $\neg q \rightarrow \neg p$ |
| :-----: | :-----: | :------: | :------: | :---------------: | :-------------------------: |
| $true$  | $true$  | $false$  | $false$  |      $true$       |           $true$            |
| $true$  | $false$ |  $true$  | $false$  |      $false$      |           $false$          |
| $false$ | $true$  | $false$  |  $true$  |      $true$       |           $true$            |
| $false$ | $false$ |  $true$  |  $true$  |      $true$       |           $true$            |

Since the truth values of the columns $p \rightarrow q$ and $\neg q \rightarrow \neg p$ are the same in all four rows, the two statements are logically equivalent.

## Question 6

Given the sets $A = \{0,1,4\}$ and $B = \{-2,-1,0,1,2\}$, determine which of the following statements are true.

1. $\exists a \in A \: (a^{2} \in B)$
2. $\forall a \in A \: (a^{2} \in B)$
3. $\forall b \in B, \exists a \in A \: (a = b^{2})$
4. $\exists a \in A, \forall b \in B \: (a = b^{2})$

**Solution:**
1. **True**, since we can find an $a \in A$ such that $a^{2}$ is in $B$. That value of $a$ could be $0$ or $1$, since $0^{2} = 0 \in B$ and $1^{2} = 1 \in B$ as well.

2. **False**, since we can find an $a \in A$ and yet $a^{2}$ is **not** in $B$. That value of $a$ is $4$, since $4^{2} = 16$, but $16$ is not in $B$.

3. **True**, since for every single element $b$ in $B$, we can find an $a \in A$ such that $a = b^{2}$. 
	- If $b = -2$ or $2$, then $b^{2} = 4$, which is in $A$. 
	- If $b = -1$ or $1$, then $b^{2} = 1$, which is in $A$.
	- If $b = 0$, then $b^{2} = 0$, which is in $A$.

4. **False**, since we are unable to find a single element of $A$ that is simultaneously the square of any element in $B$. 
	- If $a = 0$, then taking $b = 1 \in B$, we find that $a = 0 \neq 1 = b^{2}$.
	- If $a = 1$, then taking $b = 0 \in B$, we find that $a = 1 \neq 0 = b^{2}$.
	- If $a = 4$, then taking $b = -1 \in B$, we find that $a = 4 \neq 1 = b^{2}$.

## Question: Properties of integers

>[!Purpose]
>In this question, the goal is to practise unpacking definitions, in this case, of the integers. It is extremely common to encounter new definitions of mathematical objects, and it is useful to be able to understand what those definitions are.

The set of **integers**, denoted $\mathbb{Z}$, is a set that is frequently used, so it is important to understand some of its properties. For this question, we will be unpacking the properties of multiplication on the integers.

For each of the following properties, look through the definition of the property (written in first-order logic), and provide an example of the property. The first property has been done for you.

>[!Question 1]
>**Property 1 (Closure)**: $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \: [a \times b \in \mathbb{Z}]$
>
>**Example**: 
>Let $a=2 \in \mathbb{Z}$ and let $b=-3 \in \mathbb{Z}$.
>Then, $a \times b=2\ \times (-3) = -6$, which is also in $\mathbb{Z}$.

**Solution**:

>[!Question 2]
>**Property 2 (Commutativity)**: $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \: [a \times b = b \times a]$
>
>**Example**:
>Let $a=2 \in \mathbb{Z}$ and let $b=-3 \in \mathbb{Z}$.
>Then, $a \times b=2\ \times (-3) = -6$, and $b \times a=(-3) \times 2=-6$ as well. Hence, $a \times b=b \times a$.

>[!Question 3]
>**Property 3 (Associativity)**: $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z}, \forall c \in \mathbb{Z} \: [a \times (b \times c) = (a \times b) \times c]$
>
>**Example**: 
>Let $a=2 \in \mathbb{Z}$, let $b=-3 \in \mathbb{Z}$ and let $c=4 \in \mathbb{Z}$.
>Then, $a \times (b \times c)=2 \times (-3 \times 4) = 2 \times (-12) = -24$, and $(a \times b) \times c = [2 \times (-3)] \times 4 = (-6) \times 4 = -24$ as well. Hence, $a \times (b \times c) = (a \times b) \times c$.

>[!Question 4]
>**Property 4 (Existence of identity element)**: $\exists e \in \mathbb{Z}, \forall a \in \mathbb{Z}, \: [a \times e = e \times a = a]$
>
>**Example**:
>Let $e=1 \in \mathbb{Z}$ and let $a=397846 \in \mathbb{Z}$.
>Then, $a \times e = 397846 \times 1 = 397846$, and $e \times a = 1 \times 397846 = 397846$ as well. Hence, $a \times e = e \times a = a$.

>[!Question 5]
>**Property 5 (Zero divisors)**: $\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \: [(a \times b = 0) \to (a = 0 \lor b = 0)]$
>
>**Example**:
>Let $a=2 \in \mathbb{Z}$ and let $b=0 \in \mathbb{Z}$.
>Then, $a \times b = 2 \times 0 = 0$. Indeed, $b=0$, so it is also true that $a=0 \lor b=0$ (by generalisation). Hence, $(a \times b = 0) \to (a = 0 \lor b = 0)$.

