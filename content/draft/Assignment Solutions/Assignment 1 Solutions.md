
This is the first of two assignments and is worth **15%** of the total grade. Submit your solutions digitally on Canvas, where a submission box will be open under "Assignments > Assignment 1".

There are 3 questions for a total of 15 marks.

_Please make sure your handwriting is legible (Illegible solutions may make it very hard for us to grade). You may scan/take a picture of handwritten solutions, you may also type your solutions. We are not particular about the symbol use if you cannot type out the symbols but please make it clear to us what symbol you were intending to use._

# How to submit:
- Submit online on Canvas. There will be a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
* **Official due date for submission**: **Sunday, 8 Mar 2026, 11:59 PM**

# Collaboration Policy: 
* You may discuss high-level ideas with your classmates or friends. **You should list your collaborators if you do so**.
* **Do not share your solutions**.
* ChatGPT (and other LLMs) are **not allowed**. 
* Your submission **must be of your own write-up**. No copying from your classmates / friends.

# Late Policy:
* No late submissions for the assignment allowed.

# Other notes:
* Penalising for missing steps in the proof are up to the discretion of the grader. We may give partial marks where applicable.
* We recommend doing the proof step by step following the rules laid out in [[Unit 1#Allowable Rules of Deductions/Inferences]] in case you unsure about which steps are and not allowed. If steps are skipped, it is up to the grader's discretion as to whether to penalise or not.

---
# Question 1 (2 marks):

### Sub-part 1 \[1 mark]

Is $p \lor ((\neg p) \to q)$ logically equivalent to $p \lor q$?

Fill out the 4 remaining cells to check whether they are equivalent. You need not show intermediate working (but you can if you feel that it helps you).

**Solution**:

>[!note] Truth table for $p \lor ((\neg p) \to q)$
>**Yes**, the two formulae are logically equivalent.
>
> | $p$     | $q$     | $p \lor ((\neg p) \to q)$ | $p \lor q$ |
> | ------- | ------- | ------------------------- | ---------- |
> | $true$  | $true$  | $true$                    | $true$     |
> | $true$  | $false$ | $true$                    | $true$     |
> | $false$ | $true$  | $true$                    | $true$     |
> | $false$ | $false$ | $false$                   | $false$    |

### Sub-part 2 \[1 mark]

Is $(p \lor q) \land (\neg p)$ logically equivalent to $q$?

Fill out the 4 remaining cells to check whether they are equivalent. You need not show intermediate working (but you can if you feel that it helps you).

**Solution**:

>[!note] Truth table for $(p \lor q) \land (\neg p)$
>**No**, the two formulae are not logically equivalent.
>
> | $p$     | $q$     | $p \lor ((\neg p) \to q)$ |
> | ------- | ------- | ------------------------- |
> | $true$  | $\textcolor{blue}{true}$  | $\textcolor{red}{false}$  |
> | $true$  | $false$ | $false$  |
> | $false$ | $true$  | $true$  |
> | $false$ | $false$ | $false$  |


---
# Question 2 (4 marks): 

Let $A = \{0, 2, 4, 6, 8\}$ and $B = \{1, 3, 5, 7, 9\}$. And let the predicate $odd(x)$ be defined as $\exists k \in \mathbb{Z}[x = 2k + 1]$. Determine which of the following quantified statements are true:

1. $\exists b \in B \ [b < 1]$ **False**
2. $\exists a \in A, \forall b \in B \ [a > b]$ **False**
3. $\forall a \in A \ \big[\neg(\exists b \in B \ [odd(ab)])\big]$ **True**
4. $\exists c  \in B, \forall b \in B, \exists a \in A \ [a + b = c]$  **True, consider c = 9**

You do not have to give a formal proof of the statements; you may simply state whether the statements are true or false.

---
# Question 4 (3 marks):

Given the following lemmas:

>[!Lemma]
> $\forall x \in A \ [P(x) \lor Q(x)]$

>[!Lemma]
> $\forall x \in A \ \bigg[P(x) \to \big (\exists y \in A \ [ R(x, y) ] \big) \bigg]$

>[!Lemma]
> $\forall x \in A \ \big[Q(x) \to R(x, x) \big]$

Prove that:

$$
\forall s \in A, \exists t \in A [R(s, t)]
$$

1. Let $a \in A$, arbitrarily chosen.
2. $\forall x \in A \ [P(x) \lor Q(x)]$ \[Using lemma]
3. $P(a) \lor Q(a)$ \[Universal instantiation on line 1, 2]
4. Case 1: Assume $P(a)$
	1. $\forall x \in A \ \bigg[P(x) \to \big (\exists y \in A \ [ R(x, y) ] \big) \bigg]$ \[Using lemma]
	2. $P(a) \to \exists y \in A [R(a, y)]$ \[Universal instantiation on line 1, 4.1]
	3. $\exists y \in A[R(a, y)]$ \[Modus ponens on lines 4, 4.2]
5. Case 2: Assume $Q(a)$
	1. $\forall x \in A \ \big[Q(x) \to R(x, x) \big]$ \[Using lemma]
	2. $Q(a) \to R(a, a)$ \[Universal instantiation on line 1, 5.1]
	3. $R(a, a)$ \[Modus ponens on lines 5, 5.2]
	4. $\exists y \in A[R(a, y)]$ \[Existential generalisation on lines 1, 5.3]
6. $\exists y \in A[R(a, y)]$ \[Proof by cases on lines 3, 4.3, 6.4]
7. $\forall s \in A, \exists t \in A [R(a, y)]$ \[Universal generalisation on lines 1, 6]

---

# Question 4 (6 marks):

In this question let's explore some more properties about quantified statements. We will ask if assuming a certain quantified statement, we are able to prove another. If the answer is true, give a proof based on the format we've laid out on how to do proofs. If the answer is false, give possible definitions for the sets, and predicates to **disprove** the statement. Two examples are given below to show you what we mean.


>[!Example]
> **Question:** Assuming $\exists x \in A, \forall y \in A [P(x, y)]$, is it also true that $\forall x \in A, \exists y \in A [ P(y, x) ]$?
> 
> **Answer:** True.
> >[!Proof]
> > 1. Assume $\exists x \in A, \forall y \in A [P(x, y)]$.
> > 2. Let $c \in A$ be such that $\forall y \in A [P(c, y)]$. \[Existential instantiation on line 1]
> > 3. Let $b \in A$, arbitrarily chosen.
> > 4. Consider $c \in A$.
> > 5. $P(c, b)$ \[Universal Instantiation on lines 2, 3]
> > 6. $\exists y \in A[P(y, b)]$ \[Existential generalisation on lines 4, 5]
> > 7. $\forall x \in A, \exists y \in A[P(y, x)]$ \[Universal generalisation on lines 3, 6]


>[!Example]
> **Question:** Assuming $\forall x \in A [ P(x) \lor Q(x)]$, is it also true that $\forall x \in A [ P(x) ]$?
> **Answer:** False
> >[!Proof]
> > 
> > Consider $A = \{1, 2\}$. And $P(x) \equiv x = 1$ and $Q(x) \equiv x = 2$.
> > Then $\forall x \in A [ P(x) \lor Q(x)]$ is true but  $\forall x \in A [ P(x) ]$ is false.


### Sub-part 1: 

Assuming $\exists x \in A [ P(x) \land Q(x) ]$, is it also true that $\exists z \in A[P(z)]$?

True.

1. Assume $\exists x \in A [ P(x) \land Q(x) ]$
2. Let $c \in A$ be such that $P(c) \land Q(c)$ \[Existential instantiation on line 1]
3. P$(c)$ \[Specialisation on line 2]
4. $\exists x \in A[P(x)]$ \[Existential generalisation on lines 1, 3]
### Sub-part 2: 

Assuming $\forall x \in A, \exists y \in A [ P(y, x) ]$, is it also true that $\exists x \in A, \forall y \in A [P(x, y)]$?

False.  Consider $A = \mathbb{Z}$, and $P(a, b) \equiv a > b$.

Then $\forall x \in A, \exists y \in A [ P(y, x) ]$ is true, since we can always find larger integers.
But $\exists x \in A, \forall y \in A [P(x, y)]$ is false, since it's only true if there is a "largest" integer in the set of integers.
