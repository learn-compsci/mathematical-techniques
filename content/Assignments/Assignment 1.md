
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

| $p$     | $q$     | $p \lor ((\neg p) \to q)$ | $p \lor q$ |
| ------- | ------- | ------------------------- | ---------- |
| $true$  | $true$  |                           | $true$     |
| $true$  | $false$ |                           | $true$     |
| $false$ | $true$  |                           | $true$     |
| $false$ | $false$ |                           | $false$    |

Fill out the 4 remaining cells to check whether they are equivalent. You need not show intermediate working (but you can if you feel that it helps you).

### Sub-part 2 \[1 mark]

Is $(p \lor q) \land (\neg p)$ logically equivalent to $q$?

| $p$     | $q$     | $(p \lor q) \land (\neg p)$ |
| ------- | ------- | --------------------------- |
| $true$  | $true$  |                             |
| $true$  | $false$ |                             |
| $false$ | $true$  |                             |
| $false$ | $false$ |                             |

Fill out the 4 remaining cells to check whether they are equivalent. You need not show intermediate working (but you can if you feel that it helps you).

---
# Question 2 (4 marks): 

Let $A = \{0, 2, 4, 6, 8\}$ and $B = \{1, 3, 5, 7, 9\}$. Also, let the predicate $odd(x)$ be defined as:

$$
odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2k + 1]
$$

Determine which of the following quantified statements are true:

1. $\exists b \in B \ [b < 1]$
2. $\exists a \in A, \forall b \in B \ [a > b]$
3. $\forall a \in A \ \big[\neg(\exists b \in B \ [odd(ab)])\big]$
4. $\exists c  \in B, \forall b \in B, \exists a \in A \ [a + b = c]$ 

You do not have to give a formal proof of the statements; you may simply state whether the statements are true or false.

---
# Question 3 (3 marks):

Given the following lemmas:

>[!info] Lemma 1
> $\forall x \in A \ [P(x) \lor Q(x)]$

>[!info] Lemma 2
> $\forall x \in A \ \bigg[P(x) \to \big (\exists y \in A \ [ R(x, y) ] \big) \bigg]$

>[!info] Lemma 3
> $\forall x \in A \ \big[Q(x) \to R(x, x) \big]$

where $P$, $Q$ and $R$ are properties about elements in $A$.

Prove that:

$$
\forall s \in A, \exists t \in A \ [R(s, t)]
$$

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

### Sub-part 2: 

Assuming $\forall x \in A, \exists y \in A [ P(y, x) ]$, is it also true that $\exists x \in A, \forall y \in A [P(x, y)]$?

