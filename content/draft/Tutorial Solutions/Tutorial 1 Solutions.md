
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.
* **Official due date for submission**: 10 Feb 2026, 11:59 PM **or** during tutorial itself.

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

1. Questions 1 through 3 are related to **propositional logic**. 
2. Questions 4 through 6 are related to **first-order logic**. 
3. Questions 7 and 8 are related to **proofs**. 

After Week 2's content, you should be able to attempt questions 1 through 3. After Week 3's content, you should be able to attempt questions 4 through 6. After Week 4's content, you should be able to attempt questions 7 and 8.

**Questions 2, 4 and 7** are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1 Solutions:

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
>- "**If** *the program compiles* **but** *the input is not valid*, **then** *the output is not correct*.": ==$(p \land \neg q) \to \neg r$==

2. "The function is efficient if and only if both the algorithm terminates and the output is correct."

>[!Solution]
>$s \leftrightarrow (t \land r)$, or $\big(s \to (t \land r) \big) \lor \big( (t \land r) \to s \big)$
>
>Breaking down the sentence, we have:
>- "*The function is efficient*": $s$
>- "*The algorithm terminates*": $t$
>- "*The output is correct*": $r$
>
>Combining them using connectives, we have:
>- "Both *the algorithm terminates* **and** *the output is correct*": $t \land r$
>- "*The function is efficient* **if and only if** both *the algorithm terminates* **and** *the output is correct*.": ==$\big(s \to (t \land r) \big) \lor \big( (t \land r) \to s \big)$==
>
>>[!tip] If and only if
>> "**If and only if**" is typically written using the double-headed arrow $\leftrightarrow$.

3. "\[(The program compiles and the input is valid) or the function is efficient], and the algorithm does not terminate."

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
>- "\[(*The program compiles* **and** *the input is valid*) **or** *the function is efficient*], **and** *the algorithm does not terminate*.": ==$\big( (p \land q) \lor s \big) \land \neg t$==
>
>>[!tip] Order of operations
>>Just like in normal arithmetic, the application of logical connectives follows an order. Namely, connectives are applied in the following order: parentheses, $\neg$, $\land$, $\lor$, $\to$.
>>
>>Hence, the parentheses are necessary in this particular case. Without them, $p \land q$ and $s \land \neg t$ are evaluated first, instead of $p \land q$ followed by $(p \land q) \lor s$.

4. "If the program compiles, then either (the input is valid and the output is correct), or the algorithm does not terminate."

>[!Solution]
>$p \to \big( (q \land r) \lor \neg t \big)$

5. "The function is efficient if and only if \[(the program compiles and the input is valid), or (if the output is correct implies that the algorithm terminates)]."

>[!Solution]
>$s \leftrightarrow \big( (p \land q) \lor (r \to t) \big)$

---
# Question 2: Negating Propositional Formulae \[Graded Participation]

### Part A:

Draw two truth tables to verify that:

1. $\neg (p \to q)$ is logically equivalent to $p \land \neg q$.
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

|   $p$   |   $q$   | $p \to q$ | ==$\neg (p \to q)$== | $\neg q$ | ==$p \land \neg q$== |
| :-----: | :-----: | :-------: | :------------------: | :------: | :--------------: |
| $true$  | $true$  |  $true$   |     ==$false$==      | $false$  |     ==$false$==      |
| $true$  | $false$ |  $false$  |      ==$true$==      |  $true$  |      ==$true$==      |
| $false$ | $true$  |  $true$   |     ==$false$==      | $false$  |     ==$false$==      |
| $false$ | $false$ |  $true$   |     ==$false$==      |  $true$  |     ==$false$==      |
Hence, $\neg (p \to q)$ and $p \land \neg q$ are logically equivalent. 

|   $p$   |   $q$   | $p \land q$ | $\neg p$ | $\neg q$ | ==$\neg (p \land q)$== | ==$\neg p \lor \neg q$== |
| :-----: | :-----: | :---------: | :------: | :------: | :----------------: | :------------------: |
| $true$  | $true$  |   $true$    | $false$  | $false$  |      ==$false$==       |       ==$false$==        |
| $true$  | $false$ |   $false$   | $false$  |  $true$  |       ==$true$==       |        ==$true$==        |
| $false$ | $true$  |   $false$   |  $true$  | $false$  |       ==$true$==       |        ==$true$==        |
| $false$ | $false$ |   $false$   |  $true$  |  $true$  |       ==$true$==       |        ==$true$==        |
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
# Question 3:

> "Aiken promises Dueet that if Dueet watches anime with him, then Aiken will treat Dueet to a pizza dinner."

1. How would you write this sentence in propositional logic?

>[!Solution] 
> We let the proposition "Dueet watches anime with Aiken" to be $p$ and "Aiken treats Dueet to a pizza dinner" to be $q$.
> 
> Then we can write this sentence as $p \to q$.

2. Determine whether the promise has been broken in each of the following cases:
	1. Dueet watches anime with Aiken, and Aiken treats Dueet to a pizza dinner.
	2. Dueet watches anime with Aiken, but Aiken does not treat Dueet to a pizza dinner.
	3. Dueet does not watch anime with Aiken, and Aiken treats Dueet to a pizza dinner.
	4. Dueet does not watch anime with Aiken, and Aiken does not treat Dueet to a pizza dinner.

>[!Solution] 
> In the examples we have seen truth tables where different truth values of $p$ and $q$ lead to a different truth value of $p\to q$. To make sense of this, we can look at this example.
> 
>Case 1 definitely doesn't break the promise. Dueet watches anime, and Aiken keeps his promise. Case 2 breaks the promise because Dueet does his part and watches anime with Aiken, but Aiken didn't buy pizza like he had promised. Up to now it's all very intuitive.
>
>Case 4 doesn't break the promise either; since Dueet didn't do his part, he gets no pizza. 
>But Case 3 doesn't break the promise either! 
>
>Why is this so? [[Unit 1#The Implication Connective|In the notes]] we said that in an implication, we don't really care about what happens when the antecedent is false. An implication (Aiken's *promise*), only guarantees what happens when the antecedent is true. If we know $p$ is true, we know that $q$ will follow. It doesn't promise us anything about what happens when the antecedent $p$ is false!
>
>Another example would be buying things from a store. You could pay for a soda, and get the soda (Case 1). Or don't pay for the soda, and leave (Case 4). Or the owner might give it to you as a free gift, and you didn't pay for the soda (Case 3). The only case that is upsetting is when you pay but you don't get the soda (Case 2).

---

# Question 4:

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
# Question 5:

Consider the following first order logic statements:
1. $∃x∈D \ [P(x) \land Q(x)]$
2. $∀x∈D \ [P(x) \lor Q(x)]$
3. $∀x∈D,∃y∈E \ [P(x,y) \land Q(y)]$
4. $∃x∈D,∀y∈E \ [P(x,y) \to Q(y)]$

Write the negation for each of the statements.

#### Part 1 Solutions:

>[!Solution] 
> 1. Put a negation sign outside: $\neg \bigg(\exists x \in D \ [P(x) \land Q(x)] \bigg)$
> 2. Using **negation of an existential quantifier**: $\forall x \in D \ \bigg[\neg \big(P(x) \land Q(x) \big) \bigg]$ 
> 3. Using **De Morgan’s Law**: $\forall x \in D \ \big[\neg P(x) \lor \neg Q(x) \big]$

>[!Further Explanations] 
>Sometimes we may be confused when we see a bunch of mathematical symbols. It certainly takes time to familiarise yourselves with FOL. When it comes to negating these statements, one way to think about it is to translate it into English.
>
>Statement 1 is an existential statement. What is means, essentially, is that there exists some $x$ in set $D$ such that both $P(x)$ and $Q(x)$ is true. To negate it, think of the opposite.
>
>If there exists NO $x$ in set $D$ such that $P(x)$ and $Q(x)$ are both true, this means that for ALL $x$ in set $D$, it either does not satisfy $P(x)$, or it doesn't satisfy $Q(x)$. There is just no $x$ that satisfies both at the same time.
>
>And how would we then write this into FOL? We would write $\forall x \in D \ \big[\neg P(x) \lor \neg Q(x) \big]$.


#### Part 2 Solutions: 

>[!Solution] 
> 1. Put a negation sign outside: $\neg \bigg(\forall x \in D \ \big[P(x) \lor Q(x)\big] \bigg)$
> 2. Using **negation of an existential quantifier**: $\exists x \in D \ \bigg[\neg \big(P(x) \lor Q(x) \big) \bigg]$
> 3. Using **De Morgan’s Law**: $\exists x \in D \ \big[\neg P(x) \land \neg Q(x) \big]$

>[!Further Explanations] 
>Statement 2 is a universal statement that says: Every $x$ in set $D$ satisfies $P(x)$ or $Q(x)$ (or both), either one of them is fine. To negate it, think of the opposite.
>
>NOT every $x$ in set $D$ satisfies at least one of $P(x)$ or $Q(x)$. This means that there exists one (or more) $x$ that does not satisfy both $P(x)$ and $Q(x)$.
>
>And then we write this into FOL, $\exists x \in D \ \big[\neg P(x) \land \neg Q(x)\big]$.


#### Part 3 Solutions: 

>[!Solution] 
>1. Put a negation sign outside: $\neg \bigg(\forall x \in D,\exists y \in E \ \big[P(x,y) \land Q(y) \big] \bigg)$
>2. Using **negation of a universal quantifier**: $∃x∈D,\neg \bigg(\exists y \in E \ \big[P(x,y) \land Q(y)\big] \bigg)$
>
>1. Using **negation of an existential quantifier**: $\exists x \in D,\forall y \in E \ \bigg[\neg \big(P(x,y) \land Q(y)\big) \bigg]$
>2. Using **De Morgan’s Law**: $\exists x \in D,\forall y \in E \ \big[\neg P(x,y) \lor  \neg Q(y)\big]$

>[!Further Explanations] 
>Statement 3 is a little more complex. What it means is that for every $x$ in set $D$, there exists some corresponding $y$ in set $E$, such that both $P(x,y)$ and $Q(y)$ are true. To negate this, think of the opposite. 
>
> NOT every $x$ in set $D$ has some corresponding $y$ in set $E$ such that both $P(x,y)$ and $Q(y)$ are true. This means that there should exist (at least one) $x$ in set $D$ where you CANNOT find any $y$ in set $E$ such that *both* $P(x,y)$ and $Q(y)$ are true. In other words, there exists $x$ in set $D$ where for ALL $y$ in set $E$, $P(x,y)$ and $Q(y)$ are not true at the same time (ie. *at least* one of them is not true), so either $P(x,y)$ is not true, or $Q(y)$ is not true, or both.
> 
> Now we just write this into FOL. There exists $x$ in set $D$ where for all $y$ in set $E$, either $P(x,y)$ is not true, or $Q(y)$ is not true. Thus we write $\exists x \in D, \forall y \in E \ \big[\neg P(x,y) \lor \neg Q(y)\big]$.


#### Part 4 Solutions: 

>[!Solution] 
> 1. Put a negative sign outside: $\neg \bigg(\exists x \in D,\forall y \in E \ \big[P(x,y) \to Q(y)\big]\bigg)$
>
>1. Using **negation of an existential quantifier**: $\forall x \in D,\neg \bigg(\forall y \in E \ \big[P(x,y) \to Q(y)\big]\bigg)$
>
>1. Using **negation of a universal quantifier**: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(P(x,y) \to  Q(y)\big)\bigg]$
>
>1. Using **implication law**: $P(x,y) \to Q(y) \equiv \neg P(x,y) \lor Q(y)$, we replace $P(x,y) \to Q(y)$ with $\neg P(x,y) \lor Q(y)$, thus we write: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(\neg P(x,y) \lor Q(y)\big)\bigg]$.
>
>1. Using **De Morgan’s Law**: $\forall x \in D,\exists y \in E \ \bigg[\neg \big(\neg P(x,y)\big) \land \neg Q(y)\bigg]$
>
>1. Double negation: $\neg \big(\neg P(x,y)\big) \equiv P(x,y)$, thus we get $\forall x \in D,\exists y \in E \ \big[P(x,y) \land \neg Q(y)\big]$.


>[!Further Explanations] 
>After looking at the statement 3, this one should make more sense. What this statement means is that there exists some $x$ in set $D$ where for all $y$ in set $E$, $P(x,y) \to Q(y)$ is true. To negate this, think of the opposite.
>
>If there exists NO $x$ in set $D$ where for every $y$ in set $E$ satisfies $P(x,y) \to Q(y)$, it means that for every $x$ in set $D$, there has to exist some $y$ in set $E$ that doesn't satisfy $P(x,y) \to Q(y)$, which means that $P(x,y) \to Q(y)$ is false.
>
>To negate an implication, we use implication law to turn it into something we can work with. So we replace $P(x,y) \to Q(y)$ with $\neg P(x,y) \lor Q(y)$, and then negate it, which gives us $\neg \big(\neg P(x,y) \lor Q(y)\big)$. Then we use De Morgan's Law to further simplify into $P(x,y) \lor \neg Q(y)$.
>
>In other words, for every $x$ in set $D$, there exists some $y$ in set $E$, such that $P(x,y) \land \neg Q(y)$. Now we just have to translate this into FOL, and we have $\forall x \in D,\exists y \in E \ \big[P(x,y) \land \neg Q(y)\big]$.


---

# Question 6 Solutions:
### Part A Solutions:
1. (**True**)  $\exists x \in \mathbb{N}, \forall y \in \mathbb{Z} \ [x \neq y]$

>[!Explanation:]
>This is a practice on negating multiple quantifiers in the same statement.
>1. $\neg \big(\forall x \in \mathbb{N}, \exists y \in \mathbb{Z} \ [x = y]\big)$
>2. $\equiv \exists x \in \mathbb{N}, \neg \big(\exists y \in \mathbb{Z} \ [x = y]\big)$ (Negation of universal quantifier)
>3. $\equiv \exists x \in \mathbb{N}, \forall y \in \mathbb{Z}, \big[\neg (x = y)\big]$ (Negation of existential quantifier)
>4. $\equiv \exists x \in \mathbb{N}, \forall y \in \mathbb{Z} \ [x \neq y]$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says that every natural number, is equal to some integer. We know this to be intuitively true, by the definition of the sets of $\mathbb{N}$ and $\mathbb{Z}$.

2. (**False**) $\exists p, q \in \mathbb{Q} \ [q \neq p]$

>[!Explanation:]
>This is a practice on negating multiple objects in the same quantifier.
>1. $\neg \big(\forall p, q \in \mathbb{Q} \ [q = p]\big)$
>2. $\equiv \exists p, q \in \mathbb{Q} \ \big[\neg (q = p)\big]$ (Negation of universal quantifier)
>3. $\equiv \exists p, q \in \mathbb{Q} \ [q \neq p]$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says any 2 rational numbers are equal. 
>>We know this to be  false.

3. (**False**) $\exists a, b, c \in \mathbb{Z} \ [a \neq b \land a \neq c]$ 

>[!Explanation:]
>This is a practice on applying De Morgan's Law.
>1. $\neg \big(\forall a, b, c \in \mathbb{Z} \ [a = b \lor a = c]\big)$
>2. $\equiv \exists a, b, c \in \mathbb{Z} \ \big[\neg (a = b \lor a = c)\big]$ (Negation of universal quantifier)
>3. $\equiv \exists a, b, c \in \mathbb{Z} \ [a \neq b \land a \neq c]$ (De Morgan's Law and negation of equals)
>>**Deciphering the statement:**
>>This statement says when you pick any 3 integers, one of the integers you picked will be equal to one of the other 2 integers. 
>>
>>This is false.

4. (**True**) $\exists x \in \mathbb{Z}, \forall y, z \in \mathbb{Q} \ [x \neq 3y \lor x \neq 5z]$

>[!Explanation:]
>This is another practice on applying De Morgan's Law, but with a little more complexity.
>1. $\neg \big(\forall x \in \mathbb{Z}, \exists y, z \in \mathbb{Q} \ [x = 3y \land x = 5z]\big)$
>2. $\equiv \exists x \in \mathbb{Z}, \neg \big(\exists y, z \in \mathbb{Q} \ [x = 3y \land x = 5z]\big)$ (Negation of universal quantifier)
>3. $\equiv \exists x \in \mathbb{Z}, \forall y, z \in \mathbb{Q} \ \big[\neg (x = 3y \land x = 5z)\big]$ (Negation of existential quantifier)
>4. $\equiv \exists x \in \mathbb{Z}, \forall y, z \in \mathbb{Q} \ [x \neq 3y \lor x \neq 5z]$ (De Morgan's Law and negation of equals)
>>**Deciphering the statement:**
>>This statement is a little tricker to unpack. It says that every integer, is 3 times of some rational number, and 5 times of another rational number.
>>
>>This is true, as for any integer $x$, $3 \cdot \frac{x}{3} = x$ and $5 \cdot \frac{x}{5} = x$, and we know that $\frac{x}{3}$ and $\frac{x}{5}$ are rational numbers.

5. (**False**) $\forall p, q \in \mathbb{Z}, \exists r \in \mathbb{Z} \ [p + q = r]$

>[!Explanation:]
>This is an example of when negating a statement can make it easier to understand.
>1. $\neg \big(\exists p, q \in \mathbb{Z}, \forall r \in \mathbb{Z} \ [p + q \neq r]\big)$
>2. $\equiv \forall p, q \in \mathbb{Z}, \neg \big(\forall r \in \mathbb{Z} \ [p + q \neq r]\big)$ (Negation of existential quantifier)
>3. $\equiv \forall p, q \in \mathbb{Z}, \exists r \in \mathbb{Z} \ \big[\neg (p + q \neq r)\big]$ (Negation of universal quantifier)
>4. $\equiv \forall p, q \in \mathbb{Z}, \exists r \in \mathbb{Z} \ [p + q = r]$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement is not so easy to intuitively determine if it is true just by looking at the original statement, so we will instead consider the negation. 
>>
>>The negation says, any 2 integers added together is equal to another integer.
>>
>>We know this to be true. 
>>Therefore, the original statement must be false.
>>
>>In contrast, the original says, there are 2 integers that are not equal to any integer when added together. Not that it is impossible to tell this is false, but consider how much easier negating the statement made it to digest the statement.

6. (**False**) $\exists a, b \in \mathbb{Z} \ [a^2 = b^2 \land a \neq b]$

>[!Explanation:]
>This is a practice on negating implication statements.
>1. $\neg \big(\forall a, b \in \mathbb{Z} \ [a^2 = b^2 \to a = b]\big)$
>2. $\equiv \exists a, b \in \mathbb{Z} \ \big[\neg (a^2 = b^2 \to a = b)\big]$ (Negation of universal quantifier)
>3. $\equiv \exists a, b \in \mathbb{Z} \ [a^2 = b^2 \land a \neq b]$ (Substitute with a [[Tutorial 1 Solutions#Part a Solutions|logically equivalent proposition]])
>>**Deciphering the statement:**
>>This statement says if the squares of 2 integers are equal, the 2 integers are also equal. 
>>
>>This is false as the square of a number and its negative counterpart are equal. 
>>
>>Important to note is the use of a commonly used logical equivalence to substitute away the implication connective, as that is the easiest way to negate them.


### Part B Solutions:
1. (**True**) $\forall a, b \in \mathbb{Z} \ [a = b \to a^2 = b^2]$

>[!Explanation:]
>This is a practice on finding the contrapositive of a simple implication statement.
>1. $\forall a, b \in \mathbb{Z} \ [a^2 \neq b^2 \to a \neq b]$
>2. $\equiv \forall a, b \in \mathbb{Z} \ [a = b \to a^2 = b^2]$ (Substitution of contrapositive form)
>>**Deciphering the statement:**
>>This statement says if the squares of 2 integers are not equal, the 2 integers are also not equal. 
>>
>>This might be tricky to justify, so let's consider the contrapositive. 
>>
>>The contrapositive says that if 2 integers are equal, the squares of the 2 integers are also equal.
>>
>>Ah, this is significantly easier to justify and imagine.
>>
>>The contrapositive is thus true, making the original statement true.

2. (**True**) $\forall p \in \mathbb{Z} \ \big[(p > 5 \land p \leq 26) \to p \geq 0\big]$

>[!Explanation:]
>This is a practice on finding the contrapositive of an implication statement with connectives.
>1. $\forall p \in \mathbb{Z} \ \big[p < 0 \to (p \leq 5 \lor p > 26)\big]$
>2. $\equiv \forall p \in \mathbb{Z} \ \big[\neg(p \leq 5 \lor p > 26) \to p \geq 0\big]$ (Substitution of contrapositive form)
>3. $\equiv \forall p \in \mathbb{Z} \ \big[(p > 5 \land p \leq 26) \to p \geq 0\big]$ (De Morgan's Law)
>>**Deciphering the statement:**
>>This statement says that any integer more than 5 and less than equal to 26 must be more than equal to 0.
>>
>>This statement is true.
>>
>>Technique of note in this question is the use of De Morgan's Law even when finding a contrapositive. 

3. (**True**) $\forall x \in \mathbb{Z} \ \big(x > 5  \to \exists y \in \mathbb{N} \ [x = y]\big)$

>[!Explanation:]
>This is a practice on finding the contrapositive of an implication statement with quantifiers.
>1. $\forall x \in \mathbb{Z} \ \big(\forall y \in \mathbb{N} \ [x \neq y] \to x \leq 5\big)$
>2. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \neg (\forall y \in \mathbb{N} \ [x \neq y])\big)$ (Substitution of contrapositive form)
>3. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \exists y \in \mathbb{N} \ [\neg (x \neq y)]\big)$ (Negation of universal quantifier)
>4. $\equiv \forall x \in \mathbb{Z} \ \big(x > 5 \to \exists y \in \mathbb{N} \ [x = y]\big)$ (Negation of equals)
>>**Deciphering the statement:**
>>This statement says that any integer and any natural number, if the numbers are not equal, the integer is less than or equal to 5. 
>>
>>This statement is quite confusing to even approach from this angle, so let's consider the contrapositive.
>>
>>The contrapositive says that any integer greater than 5 has a natural number equal to it.
>>
>>Again, this is significantly easier to justify and digest.
>>
>>The contrapositive is thus true, making the original statement true.


---

# Question 7 Solutions \[Graded Participation]:

Prove the following statement:

> [!Theorem] 
> $\forall x \in \mathbb{Z} \ [\neg (even(x) \land odd(x))]$
> 
> Where we define the predicate $even(x)$ to be: $even(x) \equiv \exists k \in \mathbb{Z} \ [2k = x]$, 
>  and we define the predicate $odd(x)$ to be: $odd(x) \equiv \exists j \in \mathbb{Z} \ [2j + 1 = x]$

>[!Solution]
>**Proof:**
>1. Let $x \in \mathbb{Z}$, arbitrarily chosen.
>2. Assume for the sake of contradiction that $even(x) \land odd(x)$.
>	1. $even(x)$. \[Specialisation on line 2]
>	2. $\exists k \in \mathbb{Z} \ [2k = x]$. \[Unpacking definition of $even(x)$]
>	3. Let $s \in \mathbb{Z}$ be such that $2s = x$. \[Existential instantiation on line 2.2]
>	4. $odd(x)$. \[Specialisation on line 2]
>	5. $\exists j \in \mathbb{Z} \ [2j + 1 = x]$. \[Unpacking definition of $odd(x)$]
>	6. Let $t \in \mathbb{Z}$ be such that $2t + 1 = x$. \[Existential instantiation on line 2.5]
>	7. Then, we have $2s = 2t + 1$. \[Basic algebra, from lines 2.3 and 2.6]
>	8. $2(s - t) = 1$. \[Basic algebra]
>	9. $s - t = \frac{1}{2}$. \[Basic algebra]
>	10. $\neg (s - t \in \mathbb{Z})$. \[Basic algebra, from line 2.9]
>	11. Since $s \in \mathbb{Z}$ and $t \in \mathbb{Z}$, we have $s - t \in \mathbb{Z}$. \[Basic algebra, from lines 2.3 and 2.6]
>	12. $(s - t \in \mathbb{Z}) \land \neg (s - t \in \mathbb{Z})$. \[Conjunction on lines 2.10 and 2.11]
>	13. $\bot$. \[Contradiction rule on line 2.12]
>3. $\neg \big(even(x) \land odd(x)\big)$. \[Proof by contradiction rule on line 2.13]
>4. $\forall x \in \mathbb{Z} \ \big[\neg (even(x) \land odd(x))\big]$. \[Universal generalisation on lines 1 and 3]

---
# Question 8:
You are tasked with building a load balancer that services $C$ clients, and has to balance them between $S$ servers. All clients will request to be serviced at the same time at the start of the day, and the load balancer must assign each client a server immediately at the start of the day.

Your boss tells you to keep costs down, that each server must service **less than** $\frac{C}{S}$ clients in total. Let $c_i$ be the number of clients that the $i^{th}$ server has to service. e.g., $c_1$ is the number of clients for the first server, $c_2$ is the number of clients for the second server, and so on. Since we have $S$ servers, we have quantities $c_1, c_2, \ldots, c_S$.

**Question:** Prove to yourself and your boss that this is impossible.

**Solution:**

Before we begin the proof, let's formalise what the question wants us to prove. We need to show that the following statement is true: 

Given $C \in \mathbb{N}, S \in \mathbb{N}, c_{1} \in \mathbb{N}, c_{2} \in \mathbb{Z}, \dots, c_{S} \in \mathbb{N}$ such that $(C > 0) \land (\sum_{i=1}^S c_i = C)$, and the set $[S] = \{1, 2, \dots, S\}$ (refer to [[Unit 2#Common Sets for Numbers]] for an explanation of this notation),

$$\neg \bigg(\forall i \in [S] \ \bigg[c_{i} < \frac{C}{S}\bigg]\bigg)$$

Essentially, that it is **impossible** (indicated by the "$\neg$" symbol) for all servers to service fewer than $\frac{C}{S}$ clients. Now that we have a concrete statement down, we can continue proving it:

>[!Solution]
>**Proof:**
>1. Let $c_{1}, c_{2}, \dots, c_{S} \in \mathbb{N}$, arbitrarily chosen, be such that $\sum_{i=1}^S c_{i} = C$.
>2. Assume for the sake of contradiction that $\forall i \in [S] \ \big[c_{i} < \frac{C}{S}\big]$.
>	1. Then, we must have that $c_{1} < \frac{C}{S}$, $c_{2} < \frac{C}{S}$, $\dots$, $c_{S} < \frac{C}{S}$. \[Universal instantiation on line 2.1]
>	2. $\sum_{i=1}^S c_{i} = c_{1} + c_{2} + \dots + c_{S} < \frac{C}{S} + \frac{C}{S} + \dots + \frac{C}{S} = S \cdot \frac{C}{S} = C$. Rewriting this (for presentation's sake), we have $\sum_{i=1}^S c_{i} < C$. \[Basic algebra]
>	3. In particular, $\neg \big(\sum_{i=1}^S c_{i} = C\big)$. \[Basic algebra]
>	4. $\big(\sum_{i=1}^S c_{i} = C\big) \land \neg \big(\sum_{i=1}^S c_{i} = C\big)$. \[Conjunction on lines 1 and 2.3]
>	5. $\bot$. \[Contradiction rule on line 2.4]
>3. $\neg \big(\forall i \in [S] \ \big[c_{i} < \frac{C}{S}\big]\big)$. \[Proof by contradiction rule on line 2.5]
>4. Therefore, $$\forall c_{1}, c_{2}, \dots, c_{S} \in \mathbb{N} \ \bigg[\neg \bigg(\forall i \in [S] \ \bigg[c_{i} < \frac{C}{S}\bigg]\bigg)\bigg]$$ \[Universal generalisation on lines 1 and 3]

Thus, such a task is impossible.

































