
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.
* **Official due date for submission**: 27 Jan 2026, 11:59 PM **or** during tutorial itself.

# Collaboration Policy:
* You may discuss high-level ideas with your classmates or friends. You should list your collaborators if you do so. 
* **Do not share your solutions**.
* ChatGPT (and other LLMs) are **not allowed**. 
* Your submission **must be of your own write-up**.

# Late Policy:
* < 1 week after submission deadline: 50% penalty
* < 2 weeks after submission deadline: 75% penalty
* No submissions after 2 weeks.

# Overview

This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 1]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.

1. Questions 1 and 2 are related to **propositional logic**. 
2. Questions 3 through 5 are related to **first-order logic**. 

After Week 1's content, you should be able to attempt questions 1 and 2. After Week 2's content, you should be able to attempt questions 3 through 5.

**Questions 2 and 3** are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1:

For each of the following, write a propositional formula that accurately represents the given English statement. Use the variables $p$, $q$, $r$, $s$ and $t$ as needed, where they're defined as:
* $p \equiv$ "The program compiles"
* $q \equiv$ "The input is valid"
* $r \equiv$ "The output is correct"
* $s \equiv$ "The function is efficient"
* $t \equiv$ "The algorithm terminates"

1. "If the program compiles but the input is not valid, then the output is not correct."

>[!Solution]
>$(p \land \neg q) \to \neg r$
>
>Breaking down the sentence, we have:
>- "*The program compiles*": $p$
>- "*The input is not valid*": $\neg q$
>- "*The output is **not** correct*": $\neg r$
>
>Combining them using connectives, we have:
>- "*The program compiles* **but** *the input is not valid*": $p \land \neg q$
>- "**If** *the program compiles* **but** *the input is not valid*, **then** *the output is not correct*.": $(p \land \neg q) \to \neg r$

2. "\[(The program compiles and the input is valid) or the function is efficient], and the algorithm does not terminate."

>[!Solution]
>$\big( (p \land q) \lor s \big) \land \neg t$
>
>Breaking down the sentence, we have:
>- "*The program compiles*": $p$
>- "*The input is valid*": $q$
>- "*The function is efficient*": $s$
>- "*The algorithm **does not** terminate*": $\neg t$
>
>Combining these using connectives, we have:
>- "*The program compiles* **and** *the input is valid*": $p \land q$
>- "(*The program compiles* **and** *the input is valid*) **or** *the function is efficient*": $(p \land q) \lor s$
>- "\[(*The program compiles* **and** *the input is valid*) **or** *the function is efficient*], **and** *the algorithm does not terminate*.": $\big( (p \land q) \lor s \big) \land \neg t$
>
>>[!tip] Order of operations
>>Just like in normal arithmetic, the application of logical connectives follows an order. Namely, connectives are applied in the following order: parentheses, $\neg$, $\land$, $\lor$, $\to$.
>>
>>Hence, the parentheses are necessary in this particular case. Without them, $p \land q$ and $s \land \neg t$ are evaluated first, instead of $p \land q$ followed by $(p \land q) \lor s$.

3. "If the program compiles, then \[either (the input is valid and the output is correct), or the algorithm does not terminate]."

>[!Solution]
>$p \to \big( (q \land r) \lor \neg t \big)$

---
# Question 2 \[Graded Participation]:

### Part A:

Draw two truth tables to verify that:

1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$.
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

|   $p$   |   $q$   | $p \to q$ | $\textcolor{red}{\neg (p \to q)}$ | $\neg q$ | $\textcolor{blue}{p \land \neg q}$ |
| :-----: | :-----: | :-------: | :-------------------------------: | :------: | :--------------------------------: |
| $true$  | $true$  |  $true$   |     $\textcolor{red}{false}$      | $false$  |     $\textcolor{blue}{false}$      |
| $true$  | $false$ |  $false$  |      $\textcolor{red}{true}$      |  $true$  |      $\textcolor{blue}{true}$      |
| $false$ | $true$  |  $true$   |     $\textcolor{red}{false}$      | $false$  |     $\textcolor{blue}{false}$      |
| $false$ | $false$ |  $true$   |     $\textcolor{red}{false}$      |  $true$  |     $\textcolor{blue}{false}$      |
Hence, $\neg (p \to q)$ and $p \land \neg q$ are logically equivalent. 

|   $p$   |   $q$   | $p \land q$ | $\neg p$ | $\neg q$ | $\textcolor{red}{\neg (p \land q)}$ | $\textcolor{blue}{\neg p \lor \neg q}$ |
| :-----: | :-----: | :---------: | :------: | :------: | :---------------------------------: | :------------------------------------: |
| $true$  | $true$  |   $true$    | $false$  | $false$  |      $\textcolor{red}{false}$       |       $\textcolor{blue}{false}$        |
| $true$  | $false$ |   $false$   | $false$  |  $true$  |       $\textcolor{red}{true}$       |        $\textcolor{blue}{true}$        |
| $false$ | $true$  |   $false$   |  $true$  | $false$  |       $\textcolor{red}{true}$       |        $\textcolor{blue}{true}$        |
| $false$ | $false$ |   $false$   |  $true$  |  $true$  |       $\textcolor{red}{true}$       |        $\textcolor{blue}{true}$        |
Hence, $\neg (p \land q)$ and $\neg p \lor \neg q$ are logically equivalent. 

## Part B:

To see how these equivalences may be used, let $p$ be the statement "It is raining" and let $q$ be the statement "It is cold". Match each of the following statements with its logically equivalent; you might rewrite each statement using $p$ and $q$ to assist you.

Statements: 
1. It is not the case that it is raining or cold.
2. It is not raining or it is not cold.
3. It is not raining and it is not cold. 
4. It is not the case that it is both raining and cold.

Rewriting the 4 statements using $p$ and $q$, we get:

1. $\neg (p \lor q)$
2. $\neg p \lor \neg q$
3. $\neg p \land \neg q$
4. $\neg (p \land q)$

Using [De Morgan's Laws](https://en.wikipedia.org/wiki/De_Morgan%27s_laws#Boolean_algebra), **statements 1 and 3 and logically equivalent**, and **statements 2 and 4 are logically equivalent**.

---
# Question 3 \[Graded Participation]:

Let:
- $C=\{C_1,C_2,C_3\}$ be the set of circles,
- $S=\{S_1,S_2,S_3,S_4\}$ be the set of squares,
- $D=\{D_1,D_2,D_3\}$ be the set of diamonds, and
- $U=\{C_1, C_2, C_3, S_1, S_2, S_3, S_4, D_1, D_2, D_3\}$ be the set containing all the objects.

You are also given the following predicates, which you may use freely in your answers:
- $Above(x,y)$ is true when object $x$ is in anywhere in a row that is strictly above object $y$. For example, we consider $Above(D_1, D_2) \equiv true$ and $Above(S_1, D_2) \equiv false$.
- $Blue(x)$ is true when object $x$ is blue.
- $Grey(x)$ is true when object $x$ is grey.
- $Orange(x)$ is true when the object $x$ is orange.
- $Circle(x)$ is true when the object $x$ is a circle.
- $Square(x)$ is true when $x$ is a square.
- $Diamond(x)$ is true when $x$ is a diamond.

Determine whether the following statements are true or false for the below picture:
1. $\exists u \in U \ \big[Orange(u) \land Diamond(u) \big]$
2. $\forall u \in U \ \big[Circle(u)\rightarrow Blue(u) \big]$
3. $\forall s \in S, \exists d \in D \ \big[Above(d, s) \big]$
4. $\forall c \in C, \forall s \in S \ \big[Above(c, s) \big]$
5. $\exists u \in U, \forall c \in C \ \big[Above(u, c) \big]$
6. $\exists c \in C, \exists d \in D \ \big[Grey(c) \lor \neg Orange(d) \big]$
![[tarski.png]]
>[!Solution]
>1. $\exists u \in U \ \big[Orange(u) \land Diamond(u) \big]$
>	 **True**: Consider $u = D_2$.
>>
>2. $\forall u \in U \ \big[Circle(u) \to Blue(u) \big]$
>	**False**: Consider $u = C_2$. Then, $Circle(C_2) \equiv true$, but $Blue(C_2) \equiv false$, and hence $Circle(C_2) \to Blue(C_2) \equiv false$.
>> 
>3. $\forall s \in S, \exists d \in D \ \big[Above(d, s) \big]$
>	**True**: No matter which square $s$ is chosen, we can always find at least one diamond $d$ such that $d$ lies above $s$ in the grid. For example, for all the squares, we can let $d = D_1$.
>	\[Note that **this does not mean that the $d$ chosen has to be the same one for every $s$**! In this case, this choice of $d$ *happens* to work for all the squares.]
>> 
>4. $\forall c \in C, \forall s \in S \ \big[Above(c, s) \big]$
>	**True**: No matter which circle $c$ and which square $s$ are chosen, the circle will lie above the square.
>> 
>5. $\exists u \in U, \forall c \in C \ \big[Above(u, c) \big]$
>	**False**: There does not exist a single object $u$ that lies above all the circles, because the topmost object is itself a circle (i.e., $C_1$), and therefore $Above(u, C_1) \equiv false$ no matter the choice of $u$.
>> 
>6. $\exists c \in C, \exists d \in D \ \big[Grey(c) \lor \neg Orange(d) \big]$
>	**True**: Consider $c = C_1, d = D_1$. Then, $\neg Orange(D_1) \equiv true$. By generalisation, $Grey(C_1) \lor \neg Orange(D_1) \equiv true$.

---
# Question 4:

Consider the following first-order logic statements:
1. $\forall x \in D, \exists y \in E \ \big[P(x,y) \land Q(y) \big]$
2. $\exists x \in D, \forall y \in E \ \big[P(x,y) \to Q(y) \big]$

Write the negation of each of the statements.

**Solutions:**

1. $\forall x \in D, \exists y \in E \ \big[P(x,y) \land Q(y) \big]$

>[!Solution] 
>1. Put a negation sign outside: $\neg \bigg(\forall x \in D,\exists y \in E \ \big[P(x,y) \land Q(y) \big] \bigg)$
>2. Using **negation of a universal quantifier**: $∃x∈D,\neg \bigg(\exists y \in E \ \big[P(x,y) \land Q(y)\big] \bigg)$
>
>3. Using **negation of an existential quantifier**: $\exists x \in D,\forall y \in E \ \bigg[\neg \big(P(x,y) \land Q(y)\big) \bigg]$
>4. Using **De Morgan’s Law**: $\exists x \in D,\forall y \in E \ \big[\neg P(x,y) \lor  \neg Q(y)\big]$

>[!Further Explanations] 
>Statement 3 is a little more complex. What it means is that for every $x$ in set $D$, there exists some corresponding $y$ in set $E$, such that both $P(x,y)$ and $Q(y)$ are true. To negate this, think of the opposite. 
>
> NOT every $x$ in set $D$ has some corresponding $y$ in set $E$ such that both $P(x,y)$ and $Q(y)$ are true. This means that there should exist (at least one) $x$ in set $D$ where you CANNOT find any $y$ in set $E$ such that *both* $P(x,y)$ and $Q(y)$ are true. In other words, there exists $x$ in set $D$ where for ALL $y$ in set $E$, $P(x,y)$ and $Q(y)$ are not true at the same time (i.e., *at least* one of them is not true), so either $P(x,y)$ is not true, or $Q(y)$ is not true, or both.
> 
> Now we just write this using FOL: there exists $x$ in set $D$ where for all $y$ in set $E$, either $P(x,y)$ is not true, or $Q(y)$ is not true. Thus we write $\exists x \in D, \forall y \in E \ \big[\neg P(x,y) \lor \neg Q(y)\big]$.

2. $\exists x \in D, \forall y \in E \ \big[P(x,y) \to Q(y) \big]$

>[!Solution] 
> 5. Put a negative sign outside: $\neg \bigg(\exists x \in D,\forall y \in E \ \big[P(x,y) \to Q(y)\big]\bigg)$
>
>6. Using **negation of an existential quantifier**: $\forall x \in D,\neg \bigg(\forall y \in E \ \big[P(x,y) \to Q(y)\big]\bigg)$
>
>7. Using **negation of a universal quantifier**: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(P(x,y) \to  Q(y)\big)\bigg]$
>
>8. Using **implication law**: $P(x,y) \to Q(y) \equiv \neg P(x,y) \lor Q(y)$, we replace $P(x,y) \to Q(y)$ with $\neg P(x,y) \lor Q(y)$, thus we write: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(\neg P(x,y) \lor Q(y)\big)\bigg]$.
>
>9. Using **De Morgan’s Law**: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(\neg P(x,y)\big) \land \neg Q(y)\bigg]$
>
>10. Double negation: $\neg \big(\neg P(x,y)\big) \equiv P(x,y)$, thus we get $\forall x \in D,\exists y \in E \ \big[P(x,y) \land \neg Q(y)\big]$.

>[!Further Explanations] 
>After looking at the statement 3, this one should make more sense. What this statement means is that there exists some $x$ in set $D$ where for all $y$ in set $E$, $P(x,y) \to Q(y)$ is true. To negate this, think of the opposite.
>
>If there exists NO $x$ in set $D$ where for every $y$ in set $E$ satisfies $P(x,y) \to Q(y)$, it means that for every $x$ in set $D$, there has to exist some $y$ in set $E$ that doesn't satisfy $P(x,y) \to Q(y)$, which means that $P(x,y) \to Q(y)$ is false.
>
>To negate an implication, we use implication law to turn it into something we can work with. So we replace $P(x,y) \to Q(y)$ with $\neg P(x,y) \lor Q(y)$, and then negate it, which gives us $\neg \big(\neg P(x,y) \lor Q(y)\big)$. Then we use De Morgan's Law to further simplify into $P(x,y) \lor \neg Q(y)$.
>
>In other words, for every $x$ in set $D$, there exists some $y$ in set $E$, such that $P(x,y) \land \neg Q(y)$. Now we just have to translate this into FOL, and we have $\forall x \in D,\exists y \in E \ \big[P(x,y) \land \neg Q(y)\big]$.

---
# Question 5:

### Part A:

1. (**True**) $\exists x \in \mathbb{N}, \forall y \in \mathbb{Z} \ [x \neq y]$

>[!Explanation]
>This is a practice on negating multiple quantifiers in the same statement.
>1. $\neg \big(\forall x \in \mathbb{N}, \exists y \in \mathbb{Z} \ [x = y]\big)$
>2. $\equiv \exists x \in \mathbb{N}, \neg \big(\exists y \in \mathbb{Z} \ [x = y]\big)$ (Negation of universal quantifier)
>3. $\equiv \exists x \in \mathbb{N}, \forall y \in \mathbb{Z}, \big[\neg (x = y)\big]$ (Negation of existential quantifier)
>4. $\equiv \exists x \in \mathbb{N}, \forall y \in \mathbb{Z} \ [x \neq y]$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says that every natural number, is equal to some integer. We know this to be intuitively true, by the definition of the sets of $\mathbb{N}$ and $\mathbb{Z}$.

2. (**False**) $\exists p, q \in \mathbb{Q} \ [q \neq p]$

>[!Explanation]
>This is a practice on negating multiple objects in the same quantifier.
>1. $\neg \big(\forall p, q \in \mathbb{Q} \ [q = p]\big)$
>2. $\equiv \exists p, q \in \mathbb{Q} \ \big[\neg (q = p)\big]$ (Negation of universal quantifier)
>3. $\equiv \exists p, q \in \mathbb{Q} \ [q \neq p]$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says any two rational numbers are equal, which we know to be false.

3. (**False**) $\exists a, b \in \mathbb{Z} \ [a^2 = b^2 \land a \neq b]$

>[!Explanation]
>This is a practice on negating implication statements.
>1. $\neg \big(\forall a, b \in \mathbb{Z} \ [a^2 = b^2 \to a = b]\big)$
>2. $\equiv \exists a, b \in \mathbb{Z} \ \big[\neg (a^2 = b^2 \to a = b)\big]$ (Negation of universal quantifier)
>3. $\equiv \exists a, b \in \mathbb{Z} \ [a^2 = b^2 \land a \neq b]$ (Substitute with a [[Tutorial 1 Solutions#Part a Solutions|logically equivalent proposition]])
>>**Deciphering the statement:**
>>This statement says if the squares of two integers are equal, the two integers are also equal. 
>>
>>This is false as the square of a number and its negative counterpart are equal. 
>>
>>It is important to note the use of a commonly used logical equivalence to substitute away the implication connective, as that is the easiest way to negate them.

### Part B:

1. (**True**) $\forall a, b \in \mathbb{Z} \ [a = b \to a^2 = b^2]$

>[!Explanation]
>This is a practice on finding the contrapositive of a simple implication statement.
>1. $\forall a, b \in \mathbb{Z} \ [a^2 \neq b^2 \to a \neq b]$
>2. $\equiv \forall a, b \in \mathbb{Z} \ [a = b \to a^2 = b^2]$ (Substitution of contrapositive form)
>>**Deciphering the statement:**
>>This statement says if the squares of two integers are not equal, the two integers are also not equal. This might be tricky to justify, so let's consider the contrapositive. 
>>
>>The contrapositive says that if two integers are equal, the squares of the two integers are also equal. This is significantly easier to justify and imagine.
>>
>>The contrapositive is thus true, making the original statement true.

2. (**True**) $\forall x \in \mathbb{Z} \ \big(x > 5  \to \exists y \in \mathbb{N} \ [x = y]\big)$

>[!Explanation]
>This is a practice on finding the contrapositive of an implication statement with quantifiers.
>1. $\forall x \in \mathbb{Z} \ \big(\forall y \in \mathbb{N} \ [x \neq y] \to x \leq 5\big)$
>2. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \neg (\forall y \in \mathbb{N} \ [x \neq y])\big)$ (Substitution of contrapositive form)
>3. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \exists y \in \mathbb{N} \ [\neg (x \neq y)]\big)$ (Negation of universal quantifier)
>4. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \exists y \in \mathbb{N} \ [x = y]\big)$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says that any integer and any natural number, if the numbers are not equal, the integer is less than or equal to $5$. This statement is quite confusing to even approach from this angle, so let's consider the contrapositive.
>>
>>The contrapositive says that any integer greater than $5$ has a natural number equal to it. Again, this is significantly easier to justify and digest.
>>
>>The contrapositive is thus true, making the original statement true.


































