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

## Example: 
For example, let's say you're reading a new book that is teaching you algorithms, and it says the following:

> An array $arr$ of $n$ elements elements is called **sorted** if $$\forall i \in [n], \forall j < i, (arr[j] \leq arr[i])$$

How do we read this? See from the previous unit, we might get _some_ idea 