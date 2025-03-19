---
title: "Tutorial 4: Combinatorics and Graphs"
---
# How to submit:
- Submit before actual tutorial time for it to be graded. There are 2 ways to do this:
	1. There is a submission box on Canvas for you to submit your document. Either .docx, .pdf, or a picture of your written solutions are acceptable as long as we can read your attempts.
	2. Submit your written attempts in-person during our tutorial.

* **Official due date for submission** : 01-Apr-2025, 23:59 **or** during tutorial itself.


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
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular tutorial sheet corresponds to [[Unit 6]] and Unit 7. It is recommended to either watch the lectures or read the notes for each respective parts before attempting the tutorial sheet.

1. Questions 1 through 2 are related to **combinatorics**. 
2. Questions 3 through 6 are related to **graph theory**. 
3. Question 8 is related to **pigeonhole principle**. 

After week 9's content, you should be able to attempt questions 1 through 2. Questions 1 is graded for participation.

After week 10's content, you should be able to attempt questions 2 through 7. Question 5 is graded for participation.

That said, **we encourage you to try all the questions**, this way when you come for tutorial we can best make use of your time since you can either verify your solutions, or understand the discussions when our tutors go through the solutions.


---

# Question 1 \[Graded for Participation]:

Let's say that we want to build a password system that only accepts: 

1. Lowercase letters (a-z); there are 26 possible choices
2. Uppercase letters (A-Z); there are 26 possible choices
3. Numbers (0-9); there are 10 possible choices

We are going to try to count how many possible password there are, depending on different rules that the system will allow.

## Sub-question 1:

Let's say the password system says:

> Any password must be of length $\geq 8$ and $\leq 32$.

If this is the only requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.

## Sub-question 2:

Let's say the password system says:

> Any password must be of length $\geq 8$ and $\leq 32$, and must be alphanumeric. I.e. At least one alphabet (either uppercase or lowercase), and at least one number.

If this is the requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.

**Hint:** Can we make use of ideas from [[Unit 6#Subtracting Cases]] somehow?

## Sub-question 3:

Let's say the password system says:

> Any password must be of length exactly $8$, and must **alternate** numbers and characters.

So a password like "a1b2c3d4" or a password like "1m9j8s7h" is allowed. But something like "aa1b3d0p" is not allowed because we have adjacent characters.

If this is the requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.


## Sub-question 4:

Let's say the password system says:

> Any password must be of length exactly $8$, and **must not** repeat any numbers and characters.

So a password like "a1b2c3d4" or a password like "1m9j8s7h" is allowed. But something like "a1b3d0pa" is not allowed because "a" has been repeated.

If this is the requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.

## Sub-question 5:

Let's say the password system says:

> Any password must be of length exactly $8$, must be alphabetical, and the password letters must be sorted, and each letter must only appear once.

So a passwords like "adgkwxyz" or "abcdefgh" are allowed, because they are sorted in alphabetical order. But something like "bajoweaz" is not allowed.

If this is the requirement, how many possible passwords are there? You need not compute the actual value, you can leave your answer in the form of a summation if need be.


# Question 2:

## Sub-question 1:
Let's say we wanted to arrange 5 people around a table. How many possible ways are there for us to arrange them? In general, how many possible ways are there for us to arrange $n$ people?

![[circ-perm.svg]]

To be clear, if we had $5$ people, then it doesn't matter where they sit, only the relative ordering matters.


## Sub-question 2:
Again let's say we wanted to arrange $5$ people around a table, but an arrangement and its anti-clockwise arrangement are considered the same. How many arrangements do we have now?

![[circ-perm-direction.svg]]



# Question 3:

Among a group of 7 people, is it possible that every person is friends with exactly only 2 other people? Is it possible that every person is friends with exactly 5 other people?


# Question 4:

Given a graph $G = (V, E)$ that has $|E| = t$ edges, how many edges does $\bar{G}$ have?


# Question 5 \[Graded for Participation]:

Given a graph $G$ that is a **full** $k$-ary tree of height $h$. How many nodes does it have? How many edges does it have? How many leaves does it have?


# Question 6:

Given a complete graph $G$ on $n$ nodes, how many cycles can we possibly make?

# Question 7:

Let's say that there was a tournament with $n$ teams. A match happens when $2$ different teams play against each other (A team cannot play against itself). This means a team can participate in any number of matches from $0$ to $n - 1$ inclusive.

Show that there will always been 2 teams that have played the exact same number of matches.
