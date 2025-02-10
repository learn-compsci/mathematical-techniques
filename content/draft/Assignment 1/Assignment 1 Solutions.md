
# Question 1:

By drawing a truth table, show that $p \land (p \to q) \equiv p \land q$.

**Solutions**:

| $p$     | $q$     | $p \to q$ | $p \land (p \to q)$ | $p \land q$ |
| ------- | ------- | --------- | ------------------- | ----------- |
| $true$  | $true$  | $true$    | $true$              | $true$      |
| $true$  | $false$ | $false$   | $false$             | $false$     |
| $false$ | $true$  | $true$    | $false$             | $false$     |
| $false$ | $false$ | $true$    | $false$             | $false$     |

---
# Question 2:

Let $A = \{(0, 0), (3, 1), (-2, -4)\}$ and $B = \{(1, -1), (3, 5)\}$. Determine which of the following quantified statements are true:

1. $\exists (b_1, b_2) \in B, \forall (a_1, a_2) \in A \ [b_2 \geq a_1]$
2. $\forall (a_1, a_2) \in A, \exists (b_1, b_2) \in B \ [a_1 \leq b_1 \to a_2 \geq b_2]$
3. $\exists (a_1, a_2), (a_3, a_4) \in A \ \big[(a_1 + a_3,\ a_2 + a_4) \in A \big]$
4. $\forall (b_1, b_2), (b_3, b_4) \in B \ \big[(b_1, b_3) \in A \to (b_2, b_4) \in A \big]$

**Solutions**:

1. **True**; consider $(b_1, b_2) = (3, 5) \in B$.
2. **False**; consider $(a_1, a_2) = (-2, -4) \in A$. Then:
	- $-2 \leq 1$, but $-4 \ngeq -1$.
	- $-2 \leq 3$, but $-4 \ngeq 5$.
3. **True**; consider $(a_1, a_2) = (a_3, a_4) = (0, 0) \in A$. 
4. **False**; consider $(b_1, b_2) = (3, 5) \in B$ and $(b_3, b_4) = (1, -1) \in B$. Then, $(3, 1) \in A$ but $(5, -1) \notin A$.

---

# Question 3:



---
# Question 4:

Prove the following statement:

>[!Theorem]
>$\forall n \in \mathbb{Z} \ \big[even\big(n(n+1)\big)\big]$

You may use the following predicates in your proof:
- $even(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k]$
- $odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k + 1]$

You may also use the following lemmas in your proof:

>[!Lemma-1]
>$\forall x \in \mathbb{Z} \ \big[even(x) \lor odd(x)\big]$

>[!Lemma-2]
>$\forall x \in \mathbb{Z} \ [ odd(x) \to even(x + 1)]$


**Solutions**:

**Proof**:
1. Let $n \in \mathbb{Z}$, arbitrarily chosen.
2. $\forall x \in \mathbb{Z} \ \big[even(x) \lor odd(x)\big]$ \[Lemma 1]
3. $even(n) \lor odd(n)$ \[Universal instantiation on lines 1 and 2]
4. Case 1: $even(n)$
	1. $\exists k \in \mathbb{Z} \ [n = 2\cdot k]$ \[Definition of $even$]
	2. Let $t \in \mathbb{Z}$ be such that $n = 2 \cdot t$. \[Existential instantiation on line 4.1]
	3. $(n)(n+1) = (2\cdot t)\cdot (n + 1) = 2 \cdot (t(n+1))$ \[Basic algebra]
	4. $(t(n + 1)) \in \mathbb{Z}$ \[Basic algebra]
	5. $\exists k \in \mathbb{Z} \ [ (n)(n + 1) = 2\cdot k ]$ \[Existential generalisation on lines 4.3 and 4.4]
	6. $even(n(n+1))$ \[Definition of $even$]
5. Case 2: $odd(n)$
	1. $\exists k \in \mathbb{Z} \ [n = 2\cdot k + 1]$ \[ Definition of $odd$]
	2. Let $t \in \mathbb{Z}$, be such that $n = 2\cdot t + 1$. \[Existential instantiation of line 5.1]
	3. $(n)(n + 1) = (n)(2\cdot t + 2) = 2(n)(t+1)$ \[Basic algebra]
	4. $(n)(t+1) \in \mathbb{Z}$ \[Basic algebra]
	5. $\exists k \in \mathbb{Z} \ [(n)(n+1) = 2k]$ \[Existential generalisation on lines 5.3 and 5.4]
	6. $even(n(n+1))$ \[Definition of $even$]
6. $even(n(n+1))$ \[Proof by cases on lines 3, 4.6 and 5.6]
7. $\forall n \in \mathbb{Z} \ [ even(n(n+1)) ]$ \[Universal generalisation on lines 1 and 6]

---

# Question 5 (?):

For this question, we define the following predicates for all real numbers $x$:

>[!Definition-1]
>$$small(x) \equiv \exists n_0 \in \mathbb{N}, \forall n \in \mathbb{N} \ \bigg[(n \geq n_0) \to \bigg(x - \frac{1}{n} < 1\bigg)\bigg]$$

>[!Definition-2]
>$$tiny(x) \equiv \forall n \in \mathbb{N}, \exists n_0 \in \mathbb{N} \ \bigg[(n \geq n_0) \to \bigg(x - \frac{1}{n} < 1\bigg)\bigg]$$

1. Is $small(1)$ true? What about $small(1.1)$?

2. We define $big(x) \equiv \neg small(x)$. Write the definition of $big(x)$ in first-order logic (**without simply adding a "$\neg$" to the front of the definition above**).

3. Write the contrapositive of the definition of $small(x)$.

4. Let $A = \{x \in \mathbb{R} : small(x)\}$ and $B = \{x \in \mathbb{R} : tiny(x)\}$. State one element in $B \setminus A$.

**Solutions**:

1. $small(1) \equiv true$, but $small(1.1) \equiv false$.
2. $big(x) \equiv \forall n_0 \in \mathbb{N}, \exists n \in \mathbb{N} \ \big[(n \geq n_0) \land \big(x - \frac{1}{n} \geq 1\big)\big]$
3. $small(x) \equiv \exists n_0 \in \mathbb{N}, \forall n \in \mathbb{N} \ \big[\big(x - \frac{1}{n} \geq 1\big) \to (n < n_0)\big]$
4. Any number in the set $\{x \in \mathbb{R} : x \geq 1\}$.