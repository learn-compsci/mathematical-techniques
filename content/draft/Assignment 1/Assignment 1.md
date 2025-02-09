
# Question 1:

Let $A = \{(0, 0), (3, 1), (-2, -4)\}$ and $B = \{(1, -1), (3, 5)\}$. Determine which of the following quantified statements are true:

1. $\exists (b_1, b_2) \in B, \forall (a_1, a_2) \in A \ [b_2 \geq a_1]$
2. $\forall (a_1, a_2) \in A, \exists (b_1, b_2) \in B \ [a_1 \leq b_1 \to a_2 \geq b_2]$
3. $\exists (a_1, a_2), (a_3, a_4) \in A \ \big[(a_1 + a_3,\ a_2 + a_4) \in A \big]$
4. $\forall (b_1, b_2), (b_3, b_4) \in B \ \big[(b_1, b_3) \in A \to (b_2, b_4) \in A \big]$

---
# Question 2:

Prove the following statement:

>[!Theorem]
>$\forall n \in \mathbb{N} \ [even(n(n+1))]$

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

---

# Question 3:

Assume every person either only tell lies (knave) or only speaks the truth (knight). A family of 4 say the following the statements:

Agnes: "Edith and Gru are of the same type"
Edith: "Margo is a knave"
Margo: "Gru is a knight"
Gru: "Agnes is lying!"

We can use predicates to encode these statements mathematically as follows:

1. $Knave(x)$ means $x$ is a knave.
2. $Knight(x)$ means $x$ is a knight.
3. "Every person is either a knight or a knave" can be written as $\forall p \in Person[ Knight(p) \lor Knave(p) ]$
4. "Every person cannot be both a knight and a knave" can be written as $\forall p \in Person[\neg( Knight(p) \land Knave(p))]$

For each character, identify whether they are a knight or knave!