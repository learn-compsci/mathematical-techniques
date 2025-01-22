---
hidden: "true"

title: "Unit 2: Sets, Relations"
---

This unit introduces the notion of sets and is for Week 5. The unit will introduce:
1. Basic Sets
2. Set Operations
3. Ways To Prove Set Equivalence
4. Common Sets in Discrete Math


# Part 0: Unit Introduction
Recall that in [[Unit 1#Quantifiers]] we had this spiffy diagram that explained how you should read quantified statements.

![[basic-quantifier.png]]

And throughout [[Unit 1]] itself we had slowly introduced more and more common sets that mathematicians use. Here's a nice table that summarises the ones we have seen so far:

|    Symbol    | Definition              | Explanation                                                                                                                         |
| :----------: | ----------------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| $\mathbb{N}$ | Set of natural numbers  | Set containing the numbers $0, 1, 2, 3, \ldots$                                                                                     |
| $\mathbb{Z}$ | Set of integers         | Set containing the numbers $\ldots, -3, -2, -1, 0, 1, 2, 3, \ldots$                                                                 |
| $\mathbb{Q}$ | Set of rational numbers | Set containing numbers that can be expressed as a fraction of 2 integers, eg: $0.33\bar3 = \dfrac{1}{3}$ and $-20 = \dfrac{40}{-2}$ |

In this unit, we will delve into this a little deeper. Concepts used here, and in the next Unit on relations are useful for concepts like databases, and distributed systems. In a nutshell, Sets and Relations are also part of the lingo (or vocabulary) on how we communicate. Let me show you a few examples to motivate this. At the end of this unit on sets, some of these examples should hopefully be a little more readable.

## Motivation 1:  Algorithms
For example, let's say you're reading a new book that is teaching you algorithms, and it says the following:

> An array $arr = a_0, a_1, \ldots, a_{n - 1}$ of $n$ elements from $\mathbb{Z}$ is called **sorted** if $$\forall i \in [n], \forall j \in [i], (a_j \leq a_i)$$

How do we read this? See from the previous unit, we might get _some_ idea. For example.. looking at the $\forall i \in [n]$, we probably get that this means variable $i$ was taken from some set $[n]$.. but what is set $[n]$? Similarly, variable $j$ was taken from set $[i]$. What is set $[i]$? That's one thing this unit will show you. 

## Motivation 2:  Data Structures
Later on (beyond this module) you might learn about _databases_. Databases are a tool to help you manage data. Here's an oversimplification of some of the concepts (you will get to delve deeper when you take the module):

Let's say we have two tables of data (don't worry about what a table is, you can pretend they're like Microsoft Excel spreadsheets):

Table 1:

|    Name     |         Email         |
| :---------: | :-------------------: |
|  Jon Snow   |    jsnow@gmail.com    |
| Barry Allen | the_flash@hotmail.com |
|   Pikachu   |   pika@pokemail.com   |

Table 2:

|     Name     |         Email         |
| :----------: | :-------------------: |
| Matt Murdock |    dared@gmail.com    |
| Bruce Wayne  | batman@waynemail.com  |
| Barry Allen  | the_flash@hotmail.com |

Using these 2 sheets, let's say we were told to merge them into a single table with all the data from both initial tables. So something like:

#### Resulting table

|     Name     |         Email         |
| :----------: | :-------------------: |
| Matt Murdock |    dared@gmail.com    |
| Bruce Wayne  | batman@waynemail.com  |
| Barry Allen  | the_flash@hotmail.com |
|   Jon Snow   |    jsnow@gmail.com    |
|   Pikachu    |   pika@pokemail.com   |
Notice here Barry Allen was in both tables and is a duplicate, but this table contains a combination of both original tables.

But there are other possible operations we could perform. What if our boss on the other hand wanted us to create a new table, that only has the **common** rows of the first 2 tables? Then our output table should be:

#### Resulting table
|     Name     |         Email         |
| :----------: | :-------------------: |
| Barry Allen  | the_flash@hotmail.com |
Because Barry Allen with that email is the only common entry in both tables.

These are examples of **operations** we can perform on data. And in discrete math, the starting point for learning how to do this is via **set operations**. This is also another thing we will cover in this chapter.

As we get more and more involved, we will see how we can analyse more complex set operations as well.

## Motivation 3:  ML and AI
Lastly, coming back to the theme and goal of understanding math text and exposition, it's very common that high level concepts (especially algorithms) commonly use **set notation** and concepts. To understand these in the later module, knowing how to read even more symbols is quite useful. For example, later in the semester when we talk about graphs and trees, we will be using sets.

And graphs are useful when talking about stuff like decision trees or neural nets for AI, and so on.

## In conclusion:
In conclusion, think of this as yet another part of the vocabulary that will be useful further down the road. Not to say that this isn't useful by itself. But perhaps the more application-oriented among you might want to look ahead and understand that this topic has uses down the road.




