

# Question 1:

By drawing a truth table, show that $p \land (p \to q) \equiv p \land q$.

---

# Question 2:

Let $A = \{(0, 0), (3, 1), (-2, -4)\}$ and $B = \{(1, -1), (3, 5)\}$. Determine which of the following quantified statements are true:

1. $\exists (b_1, b_2) \in B, \forall (a_1, a_2) \in A \ [b_2 \geq a_1]$
2. $\forall (a_1, a_2) \in A, \exists (b_1, b_2) \in B \ [a_1 \leq b_1 \to a_2 \geq b_2]$
3. $\exists (a_1, a_2), (a_3, a_4) \in A \ \big[(a_1 + a_3,\ a_2 + a_4) \in A \big]$
4. $\forall (b_1, b_2), (b_3, b_4) \in B \ \big[(b_1, b_3) \in A \to (b_2, b_4) \in A \big]$

---

# Question 3:

Assume every person either only tell lies (knave) or only speaks the truth (knight). A family of 4 say the following the statements:

Agnes: "Edith and Gru are of the same type"
Edith: "Margo is a knave"
Margo: "Gru is a knight"
Gru: "Agnes is lying!"

For each character, identify whether they are a knight or knave!

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