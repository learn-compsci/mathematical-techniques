
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.
* **Official due date for submission**: 31 Mar 2026, 11:59 PM **or** during tutorial itself.

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
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 6]] and [[Unit 7]]. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.

1. Questions 1 and 2 are related to combinatorics. 
2. Questions 3 through 6 are related to graph theory. 
3. Question 8 is related to the pigeonhole principle. 

After Week 9's content, you should be able to attempt questions 1 and 2. After Week 10's content, you should be able to attempt questions 2 through 7.

**Questions 1 and 5** are graded for participation.

That said, **we encourage you to try all the questions**. This way, when you come for tutorials we can make the best use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.

---
# Question 1 \[Graded for Participation]:

Let's say that we want to build a password system that only accepts: 

1. Lowercase letters ($\text{a}$-$\text{z}$); there are $26$ possible choices
2. Uppercase letters ($\text{A}$-$\text{Z}$); there are $26$ possible choices
3. Numbers ($0$-$9$); there are $10$ possible choices

We are going to try to count how many possible passwords there are, depending on different rules that the system will allow.

### Sub-part 1

Let's say the password system says:

> Any password must be of length $\geq 8$ and $\leq 32$.

If this is the only requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.

>[!note] Solution
>For passwords of length $8$, there are $26 + 26 + 10 = 62$ choices for each character, giving us $62^8$ possible passwords. Similarly, for passwords of length $n$, there are $62^n$ possible passwords of that length.
>
>Hence, there are ==$\sum_{n=8}^{32} 62^n$== passwords in total.

### Sub-part 2

Let's say the password system says:

> Any password (i) must be of length $\geq 8$ and $\leq 32$, and (ii) must be **alphanumeric** (i.e., contain at least one uppercase or lowercase letter, and at least one number).

If this is the requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.

**Hint:** Can we make use of ideas from [[Unit 6#Subtracting Cases|this section]] somehow?


>[!note] Solution
>Without restrictions, there are a total of $\sum_{n=8}^{32} 62^n$ passwords (from sub-question 1).
>
>Subtracting the number of passwords for the following cases leaves us with the required answer:
>- Case 1: Passwords that contain only letters and no numbers
>- Case 2: Passwords that contain only numbers and no letters
>
>For case 1, there are now only $52$ choices per character, so there are $\sum_{n=8}^{32} 52^n$ such passwords. For case 2, there are now only $10$ choices per character, so there are $\sum_{n=8}^{32} 10^n$ such passwords.
>
>Finally, subtracting these two values from the total gives us ==$\sum_{n=8}^{32} (62^n - 52^n - 10^n)$== as the answer.

### Sub-part 3

Let's say the password system says:

> Any password (i) must be of length exactly $8$, and (ii) must **alternate** numbers and letters.

Hence, passwords like "$\text{a1b2c3d4}$" or "$\text{1m9j8s7h}$" are allowed, but not "$\text{aa1b3d0p}$", because there are adjacent letters.

If this is the requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.


>[!note] Solution
>There are two cases:
>- Case 1: Starts with an alphabet
>- Case 2: Starts with a number
>
>Logically, these two values are equal since we are only swapping the order in which the alphabets and numbers appear. This means we only need to calculate the value of one of the cases.
>
>For case 1, there are $52$ choices for each of the $4$ alphabets and $10$ choices for each of the $4$ numbers, giving us a total of $52^4 \times 10^4 = 520^4$ possible passwords. Case 2 gives us the same value.
>
>Hence, the total number of possible passwords is ==$2 \times 520^4$==.

### Sub-part 4

Let's say the password system says:

> Any password (i) must be of length exactly $8$, and (ii) **must not** repeat any numbers or letters.

Hence, passwords like "$\text{a1b2c3d4}$" or "$\text{1m9j8s7h}$" are allowed, but not "$\text{a1b3d0pa}$", because the letter "$\text{a}$" has been repeated.

If this is the requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.


>[!note] Solution
>We are now choosing any set of $8$ characters from the pool of $62$ alphanumeric characters given, which ensures that we do not choose any single character twice. However, after choosing the $8$ characters, we need to permute them.
>
>Hence, there are a total of ==$P(62,8)$== possible passwords.

### Sub-part 5

Let's say the password system says:

> Any password (i) must be of length exactly $8$, (ii) must be alphabetical, (iii) the password letters must be sorted, and (iv) each letter must only appear once.

Hence, passwords like "$\text{adgkwxyz}$" or "$\text{abcdefgh}$" are allowed, but not "$\text{bajoweaz}$".

If this is the requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.


>[!note] Solution
>We choose a set of $8$ characters from the pool of $52$ alphabetical characters, which ensures that we do not choose any single letter twice. Since for any particular set, there is only one permutation in which the $8$ letters are in alphabetical order, we do not need to specially count their permutations.
>
>This gives us a total of ==$\binom{52}{8}$== possible passwords.

---
# Question 2:

### Sub-part 1

Let's say we wanted to arrange 5 people around a table. How many possible ways are there for us to arrange them? In general, how many possible ways are there for us to arrange $n$ people?

![[circ-perm.svg]]

To be clear, if we had $5$ people, then it doesn't matter where they sit; only the relative ordering matters.


>[!note] Solution
>Let's consider a simpler case of $3$ people, $\text{Alice}$, $\text{Bob}$ and $\text{Charlie}$. Writing each valid seating arrangement in a line instead of around a circle, we might have a particular seating arrangement as such:
>
> $$
> \text{Alice} \to \text{Bob} \to \text{Charlie}
> $$
> 
> where counting is done clockwise.
>
>Observe that this represents the same seating arrangement as $\text{Bob} \to \text{Charlie} \to \text{Alice}$ and $\text{Charlie} \to \text{Alice} \to \text{Bob}$. In a way, we can "shift" the people by a single position each time to generate a different way of representing the **same** seating arrangement, of which there are $3$.
>
>Hence, for $3$ people, we have $3!$ permutations (in a row), and for each actual valid seating arrangement, we have triple-counted them within these $3!$ permutations. Hence, we need to divide by $3$ to get the actual number of seating arrangements.
>
>Applying this concept for the case of $5$ people, we have $5!$ permutations (in a row), and each valid seating arrangement is counted five times, so we divide this number by $5$ to get the correct number of seating arrangements. This gives us a count of ==$\frac{5!}{5} = 4! = 24$==.
>
>More generally, for $n$ people, there are $\frac{n!}{n} = (n-1)!$ ways to seat them around a circular table.

### Sub-part 2

Again let's say we wanted to arrange $5$ people around a table, but an arrangement and its anti-clockwise arrangement are considered the same. How many arrangements do we have now?

![[circ-perm-direction.svg]]


>[!note] Solution
>Now, each of the $(n - 1)!$ arrangements from sub-part 1 is double-counted since its anti-clockwise counterpart was previously treated as a distinct seating arrangement. Hence, we now only have ==$\frac{(5-1)!}{2} = 12$== distinct seating arrangements.

---
# Question 3:

Among a group of $7$ people, is it possible that every person is friends with exactly only $2$ other people? Is it possible that every person is friends with exactly $5$ other people?


>[!note] Solution
>For the first part, it is possible for each person to be friends with exactly $2$ other people. Imagine all $7$ people form a circle, they are friends with the people that are right next to them.
>In the image below, consider if $A$ is friends with $B$ and $G$, $B$ is friends with $A$ and $C$, so on and so forth.
>
>![[circle.png]]
>
>For the second part, it is impossible for such a scenario to occur. Consider the people as vertices of a graph $G = (V, E)$, where two people have an edge between them if they are friends. If each person is friends with exactly $5$ people, then $\forall v \in V\ [deg(v) = 5]$. 
>
>From the handshake lemma, we know that $\sum_{v \in V} deg(v) = 2|E|$. Since all nodes have degree $5$, this means $\sum_{v \in V} 5 = 2 |E|$. 
>
>This means that the degree of $G$ must be $5 \times 7 = 35$, which is odd. Since the total degree of any graph must be even, this scenario cannot occur.

---
# Question 4:

Given a graph $G = (V, E)$ that has $|E| = t$ edges, how many edges does $\bar{G}$ have?


>[!note] Solution
>The maximum number of edges possible is $\binom{\lvert V \rvert}{2}$, where there exists an edge between any two vertices in $V$. 
>
>Hence, if $G$ has $t$ edges, then $\bar{G}$ must have $\binom{\lvert V \rvert}{2} - t$ edges.

---
# Question 5 \[Graded for Participation]:

Given a graph $G$ that is a **full** $k$-ary tree of height $h$. How many nodes does it have? How many edges does it have? How many leaves does it have?


>[!note] Solution
>From the lecture notes, we know that a full $k$-ary tree of height $h$ has $1$ node at level 0, $k$ nodes at level 1, $k^2$ nodes at level 2, and so on. Hence, the number of nodes in the tree is $$1 + k + k^2 + k^3 + \dots + k^h = \frac{k^{h+1}-1}{k-1}$$
>
>Observe that each node has $1$ edge to its parent, except for the root node (which has no parents). Hence, the number of edges in the tree is $$\frac{k^{h+1}-1}{k-1} - 1$$
>
>The number of leaves is simply the number of nodes at the $h^{th}$ level, which is $k^h$.

---
# Question 6:

Given a complete graph $G$ on $n$ nodes, how many cycles can we possibly make?

>[!note] Solution
> Let's think about what happens if we had $3$ nodes first. Let's call them $a, b, c$. So the only possible cycle is $a \to b \to c \to a$. Think of going forwards as the same as going backwards. This is actually, again, a circular arrangement! Just like in [[#Question 3]].
> 
> Another example, let's say we had $4$ nodes, let's call them $a, b, c, d$. Then there are actually $4!/4 = 6$ possible cycles we can make (if we didn't care about clock-wise vs anti-clock-wise): 
> 
> 1. $a \to b \to c \to d \to a$.
> 2. $a \to c \to b \to d \to a$.
> 3. $a \to b \to c \to d \to a$.
> 4. $a \to b \to d \to c \to a$.
> 5. $a \to d \to b \to c \to a$.
> 6. $a \to d \to c \to b \to a$.
> 
> Notice here for example that going from $a \to b \to c \to d \to a$ can be seen as the same as $a \to d \to c \to b \to a$.
> 
> So we can divide this by $2$ to get a total of $6 / 2 = 3$ possible cycles.
>
>Every cycle requires at least $3$ nodes, with each $k$-cycle involving exactly $k$ of the $n$ nodes. Hence, the total number of cycles that can be constructed for a graph with $n \geq 3$ nodes is $$\binom{n}{3} \frac{3!}{3\cdot2} + \binom{n}{4}\frac{4!}{4\cdot2} + \binom{n}{5}\frac{5!}{5\cdot 2} + \dots + \binom{n}{n}\frac{n!}{n\cdot 2} = \sum_{i=3}^{n} \binom{n}{i} \frac{n!}{n\cdot 2}$$
>
>For graphs with $0 \leq n < 3$ nodes, the number of cycles that can be made is $0$.

---
# Question 7:

Let's say that there was a tournament with $n$ teams. A match happens when $2$ different teams play against each other (A team cannot play against itself). This means a team can participate in any number of matches from $0$ to $n - 1$ inclusive.

Show that there will always been 2 teams that have played the exact same number of matches.


>[!note] Solution
>We use the pigeonhole principle, where the "pigeons" are the teams and the "pigeonholes" are the number of matches played.
>
>**Proof:**
>1. There are two cases: either there is a team that has played exactly $n-1$ games, or there is no such team that has played exactly $n-1$ games.
>2. Case 1: There is a team that has played exactly $n-1$ games.
>	- Since that team has played everyone else, there cannot be a team that has played exactly $0$ games.
>	- Hence, there are $n-1$ possible number of games played by each team, ranging from $1$ to $n-1$.
>	- Since there are $n$ teams and only $n-1$ possible number of games played, there must be $2$ teams that have played the same number of games. \[By pigeonhole principle]
>3. Case 2: No team has played exactly $n-1$ games.
>	- Now, there are again $n-1$ possible number of games played by each team, but this time ranging from $0$ to $n-2$.
>	- Since there are $n$ teams and still only $n-1$ possible number of games played, there must be $2$ teams that have played the same number of games. \[By pigeonhole principle]
>1. Either way, there must be $2$ teams that have played the same number of games. \[Proof by cases]



