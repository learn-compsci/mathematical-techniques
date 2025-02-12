
This is the first of two assignments and is worth 15% of the total grade. The assignment is due **Sunday 02nd March 2025, 2359**. Submit your solutions digitally on Canvas, a submission box will be open under "Assignments > Assignment 1".


There are 5 questions for a total of 15 marks. There is also a **optional** bonus question that you **may** attempt, for 2 marks. The total earnable marks is 17 out of 15 marks. (Think of the bonus marks as potentially making up any minor mistakes you may have made in the other parts of this assignment.)

_Please make sure your handwriting is legible. You may scan/take a picture of handwritten solutions, you may also type your solutions. We are not particular about the symbol use if you cannot type out the symbols but please make it clear to us what symbol you were intending to use._

# How to submit:
- Submit online on Canvas. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
* **Official due date for submission** : **Sunday 02nd March 2025, 2359**

# Collaboration Policy: 
* You may discuss high-level ideas with your classmates or friends. You should list your collaborators if you do so. 
* **Do not share your solutions**.
* ChatGPT (and other LLMs) are **not allowed**. 
* Your submission **must be of your own write-up**.

# Late Policy:
* No late submissions for the assignment allowed.


---
# Question 1 (1 mark):

Is $p \land (p \to q)$ logically equivalent to $p\land q$?

| $p$     | $q$     | $p \land (p \to q)$ | $p \land q$ |
| ------- | ------- | ------------------- | ----------- |
| $true$  | $true$  |                     | $true$      |
| $true$  | $false$ |                     | $false$     |
| $false$ | $true$  |                     | $false$     |
| $false$ | $false$ |                     | $false$     |

Fill out the 4 remaining cells to check whether they are equivalent. You need not show intermediate working (but you can if you feel that it helps you).

---
# Question 2 (2 marks):

Is the following logical equivalence true?

$$
\big(p \to \neg q\big) \land \big(\neg p \to q\big) \stackrel{?}{\equiv} \big(p \lor q\big)\land \big(\neg p \lor \neg q\big)
$$

| $p$     | $q$     | $\big(p \to \neg q\big) \land \big(\neg p \to q\big)$ | $\big(p \lor q\big)\land \big(\neg p \lor \neg q\big)$ |
| ------- | ------- | ----------------------------------------------------- | ------------------------------------------------------ |
| $true$  | $true$  |                                                       |                                                        |
| $true$  | $false$ |                                                       |                                                        |
| $false$ | $true$  |                                                       |                                                        |
| $false$ | $false$ |                                                       |                                                        |

Fill out the 8 remaining cells to check whether they are equivalent. You need not show intermediate working (but you can if you feel that it helps you).

---

# Question 3 (4 marks): 

Let $A = \{0, 2, 4, 6, 8\}$ and $B = \{1, 3, 5, 7, 9\}$. Determine which of the following quantified statements are true:

1. $\exists b \in B \ [b < 1]$
2. $\exists a \in A, \forall b \in B \ [a > b]$
3. $\forall a \in A \ \big[\neg(\exists b \in B \ [odd(ab)])\big]$
4. $\exists c  \in B, \forall b \in B, \exists a \in A \ [a + b = c]$ 

You do not have to give a formal proof of the statements; you may simply state whether the statements are true or false.

---


# Question 4 (3 marks):

Prove the following statement:

>[!Theorem]
>$\forall n \in \mathbb{Z} \ \big[even\big(n(n+1)\big)\big]$

You may use the following definitions of predicates in your proof:
- $even(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k]$
- $odd(x) \equiv \exists k \in \mathbb{Z} \ [x = 2 \cdot k + 1]$

You may also use the following lemmas in your proof:

>[!Lemma-1]
>$\forall x \in \mathbb{Z} \ \big[even(x) \lor odd(x)\big]$

Hint: Use lemma 1 to say that $n$ is either even or odd. When that happens, try to prove both cases separately.

We recommend doing the proof step by step following the rules laid out in [[Unit 1#Allowable Rules of Deductions/Inferences]] in case you unsure about which steps are and not allowed. If steps are skipped, it is up to the grader's discretion as to whether to penalise or not.

---

# Question 5 (5 marks):

Let $has\_gap(x, y) \equiv \exists q \in \mathbb{Q} \ [x < q \land q < y]$ be the predicate that essentially says "We can find a rational number strictly in between values $x$ and $y$." 

We want to disprove the following statement:

$$
\forall a \in \mathbb{Z}, \forall b \in \mathbb{Z} \ [has\_gap(a, b)]
$$

i.e., we believe that it is false. Your friend has already done part of it. In particular, your friend has already negated the statement:

$$
\exists a \in \mathbb{Z}, \exists b \in \mathbb{Z} \ [\neg has\_gap(a, b)]
$$

And also started a proof. Your friend's proof has these steps, and they want you to help them fill in the remaining portions of the proof.

1. $1 \in \mathbb{Z}$
	1. Assume for the sake of contradiction that $has\_gap(1, 1)$.
	2. ...
	3. ...
	4. ...
	5. ...
	6. $\bot$
2.  $\neg has\_gap(1, 1)$ \[Proof by contradiction rule]
3. $\exists a \in \mathbb{Z}, \exists b \in \mathbb{Z} \ [\neg has\_gap(1,1)]$ \[Existential generalisation on lines 1 and 2]

Fill in the remaining portion of the proof in the middle. You may need more than 4 lines, that is okay, in which case the $\bot$ line should be shifted accordingly. For example if you used 8 lines in your proof after line 1.1, then $\bot$ should be on on line 1.10.

We recommend doing the proof step by step following the rules laid out in [[Unit 1#Allowable Rules of Deductions/Inferences]] in case you unsure about which steps are and not allowed. If steps are skipped, it is up to the grader's discretion as to whether to penalise or not.

---

# Bonus Question: (2 marks)

Assume every person either only tell lies (knave) or only speaks the truth (knight). A family of 4 say the following the statements:

Agnes: "Edith and Gru are of the same type."
Edith: "Margo is a knave."
Margo: "Gru is a knight."
Gru: "Agnes is lying!"

We can use predicates to encode these statements mathematically as follows:

1. $Knave(x)$ means $x$ is a knave.
2. $Knight(x)$ means $x$ is a knight.
3. "Every person is either a knight or a knave" can be written as $\forall p \in Person[ Knight(p) \lor Knave(p) ]$
4. "Every person cannot be both a knight and a knave" can be written as $\forall p \in Person[\neg( Knight(p) \land Knave(p))]$

For each character, identify whether they are a knight or knave!

