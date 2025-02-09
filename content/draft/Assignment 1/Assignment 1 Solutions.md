
# Question 1:

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
# Question 2:

Prove the following statement:

>[!Theorem]
>$\forall n \in \mathbb{N} \ \big[even\big(n(n+1)\big)\big]$

You may use the following predicates in your proof:
- $even(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k]$
- $odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k + 1]$

You may also use the following lemmas in your proof:

>[!Lemma-1]
>$\forall x \in \mathbb{N} \ \big[\neg \big(even(x) \land odd(x) \big)\big]$

>[!Lemma-2]
>$\forall x \in \mathbb{N} \ [\neg even(x) \to odd(x)]$

>[!Lemma-3]
>$\forall x \in \mathbb{N} \ [\neg odd(x) \to even(x)]$

**Solutions**:
1. Let $n \in \mathbb{N}$, arbitrarily chosen.
2. $\neg \big(even(n) \land odd(n)\big)$ \[Universal instantiation of Lemma 1]
3. $\neg even(n) \lor \neg odd(n)$ \[Logically equivalent to line 2]
4. Case 1: Suppose $\neg even(n)$.
	1. $\neg even(n) \to odd(n)$ \[Universal instantiation of Lemma 2]
	2. $odd(n)$ \[Modus ponens on lines 4 and 4.1]
	3. $\exists k \in \mathbb{Z} \ [n = 2k + 1]$ \[Unpacking definition of $odd$]
	4. Let $t \in \mathbb{Z}$ be such that $n = 2t + 1$. \[Existential instantiation of line 4.3]
	5. $n + 1 = 2t + 1 + 1 = 2t + 2 = 2(t + 1)$ \[Basic algebra]
	6. $n(n + 1) = 2(2t + 1)(t + 1)$ \[Basic algebra]
	7. Since $t \in \mathbb{Z}$, $(2t + 1)(t + 1) \in \mathbb{Z}$. \[Basic algebra]
	8. $\exists k \in \mathbb{Z} \ [n(n + 1) = 2k]$ \[Existential generalisation of lines 4.6 and 4.7]
	9. $even(n(n + 1))$ \[Unpacking definition of $even$]
5. Case 2: Suppose $\neg odd(n)$.
	1. $\neg odd(n) \to even(n)$ \[Universal instantiation of Lemma 3]
	2. $even(n)$ \[Modus ponens on lines 5 and 5.1]
	3. $\exists k \in \mathbb{Z} \ [n = 2k]$ \[Unpacking definition of $even$]
	4. Let $t \in \mathbb{Z}$ be such that $n = 2t$. \[Existential instantiation of line 5.3]
	5. $n(n + 1) = (2t)(2t + 1) = 2[t(t + 1)]$ \[Basic algebra]
	6. Since $t \in \mathbb{Z}$, $t(t + 1) \in \mathbb{Z}$. \[Basic algebra]
	7. $\exists k \in \mathbb{Z} \ [n(n + 1) = 2k]$ \[Existential generalisation of lines 5.5 and 5.6]
	8. $even(n(n + 1))$ \[Unpacking definition of $even$]
6. $even(n(n + 1))$ \[Proof by cases on lines 3, 4.9 and 5.8]
7. $\forall n \in \mathbb{Z} \ \big[even\big(n(n + 1)\big)\big]$ \[Universal generalisation of lines 1 and 6]

---

# Question 3:

test