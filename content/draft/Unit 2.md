---
hidden: "true"

title: "Unit 2: Sets, Relations"
---

This unit introduces the notion of sets and is for Week 5. The unit will introduce:
1. Basic Sets, Creating Sets
2. Set Operations
3. Ways To Prove Set Equivalence
4. Common Sets in Discrete Math


Unit Introduction
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

> An array $arr = a_1, a_2, \ldots, a_{n}$ of $n$ elements from $\mathbb{Z}$ is called **sorted** if $$\forall i \in [n], \forall j \in [i], (a_j \leq a_i)$$

How do we read this? See from the previous unit, we might get _some_ idea. For example.. looking at the $\forall i \in [n]$, we probably get that this means variable $i$ was taken from some set $[n]$.. but what is set $[n]$? Similarly, variable $j$ was taken from set $[i]$. What is set $[i]$? That's one thing this unit will show you. 

## Motivation 2:  Databases
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


# Basic Sets, Creating Sets

#### Set Roster Notation
Let's begin by talking about what is a set. A set is just a collection of objects. So for example, let's say we wanted to represent the collection of someone's favourite book authors, we could write something like:

$$
A = \{\text{Agatha Christie}, \text{Cal Newport}, \text{Michael Crichton}\}
$$

Here, we are saying set $A$ contains $3$ objects, namely: Agatha Christie, Cal Newport, Michael Crichton.

Pay attention to how we are using the "$\{$" symbol to start the set,  and the "$\}$" symbol, to end the set. We also use the "$,$" symbol to separate _elements_ of the set.

So if we want to create sets by listing out the elements one-by-one, that is what we call **set roster notation**. Here are a few more examples:

>[!Example]
> Let $B$ be the set that contains the first three prime numbers, then:
> $$
> B = \{2, 3, 5\}
> $$


>[!Example]
> Let $C$ be the set that contains the integers $1, 50, 241, 1234, 9501234$, then:
> $$
> C = \{1, 50, 241, 1234, 9501234\}
> $$

Set roster notation can be a little boring at times, we really have to hand-write all the elements.

#### Element Of

Using the same set again:

$$
A = \{\text{Agatha Christie}, \text{Cal Newport}, \text{Michael Crichton}\}
$$

We say $\text{Agatha Christie}$ is _an element_ of set $A$. You might remember, we write this as $\text{Agatha Christie} \in A$. The "$\in$" symbol here means "is an element of". Similarly, this means we can also say $\text{Cal Newport} \in A$, and also $\text{Michael Crichton} \in A$.

Let's say we had some other author: Stephen King, and notice here he's not in set $A$. We can write this in one of two ways, they're both the same:

$$
\text{Stephen King} \notin A
$$

or,

$$
\neg(\text{Stephen King} \in A)
$$


#### Subset

What happens if we have two sets, something like $A = \{1, 2, 3\}$ and $B = \{1, 2, 3, 10\}$, then we want to be able to say:

> Every object in $A$ is also an object in $B$.

Or, formally:

$$
\forall x \in A[x \in B]
$$

The symbol for this, is $\subseteq$. So using our example, we would write:

$$
A \subseteq B
$$

What about if we had a set $C = \{1, 2\}$. Can we say that everything in $A$ is also in $C$? No we can't. In particular, $3 \in A$ but $3 \notin B$. So in fact, we can say:

$$
\exists x \in A[x \notin B]
$$

which we know can be re-written:

$$
\exists x \in A[x \notin B] \equiv \exists x \in A[ \neg(x \in B)] \equiv \neg(\forall x \in A[x \in B])
$$

Which confirms $\neg(A \subseteq B)$. As a shorthand, we can also write this as $A \nsubseteq B$.

>[!Example]
> Let $A = \{ 2, 4, 6, 8 \}$, $B = \{2, 4, 6\}$. Then $A \nsubseteq B$ but $B \subseteq A$.

>[!Example]
> Let $A = \{ 1, 2, 3, 4 \}$, $B = \{2, 4, 6, 8\}$. Then $A \nsubseteq B$ and also $B \nsubseteq A$.

#### Empty Set
What about if we wanted a set that has no elements? There's two ways we can write this, though uncommon, some people might write it like so:

$$
\{\}
$$

The more common notation, and one you should get used to, is this:
$$
\varnothing
$$

Another also common way of writing it is like this:
$$
\emptyset
$$


One important thing to note is that the empty set is **always a subset of any other set**. For example, $\emptyset \subseteq \{1, 2\}$. It's also a subset of itself! $\emptyset \subseteq \emptyset$.
#### Common Sets for Numbers
Let's start talking about a few well-established symbols for sets. The most common are: $\mathbb{N}, \mathbb{Z}, \mathbb{Q}, \mathbb{R}, \mathbb{C}$

|    Symbol    | Definition                       | Explanation                                                                                                                         |
| :----------: | -------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| $\mathbb{N}$ | Set of natural numbers           | Set containing the numbers $0, 1, 2, 3, \ldots$                                                                                     |
| $\mathbb{Z}$ | Set of integers                  | Set containing the numbers $\ldots, -3, -2, -1, 0, 1, 2, 3, \ldots$                                                                 |
| $\mathbb{Q}$ | Set of rational numbers          | Set containing numbers that can be expressed as a fraction of 2 integers, eg: $0.33\bar3 = \dfrac{1}{3}$ and $-20 = \dfrac{40}{-2}$ |
| $\mathbb{R}$ | Set of real numbers              | Set containing any number that is not complex.                                                                                      |
| $\mathbb{C}$ | Set of imaginary/complex numbers | For example, something like $i$, or $-i$ is complex but not real.                                                                   |

There is one more common notation that we use in computer science. It turns out for some natural number $n$, it's very convenient for us to think about the set $\{1, \ldots, n\}$. The notation for this is $[n]$.

>[!Example]
> $$
> [5] = \{1, 2, 3, 4, 5\}
> $$

>[!Example]
> $$
> [0] = \{0\}
> $$

#### Set Builder Notation
Okay, well right now we've seen a bunch of sets, not really built or made anything too big. If we wanted some kind of special, custom set, we've had to manually list out all the elements. What if we wanted the set of even numbers? We can't just write everything out one-by-one.. that would take forever!

Here's how we would do it:

$$
A = \{ x \in \mathbb{Z} : \exists k \in \mathbb{Z} [x = 2k] \}
$$

Let's read this back:

> $A$ is a set that contains any element $x$ from $\mathbb{Z}$, such that, the following statement about $x$ holds true: $$ \exists k \in \mathbb{Z} [x = 2k]$$


Let's see how this works.. consider a number like $18$. Is $18 \in A$? Well, does it satisfy the statement? $18 = 2\cdot 9$ **and** $9 \in \mathbb{Z}$. So there exists a $k \in \mathbb{Z}$ such that $18 = 2 \cdot k$. So the condition holds! This means $18 \in A$.

What about something like $3$? Recall from [[Unit 1#Example 2 Delving a little deeper]], we proved that $\neg even(3)$, or in other words, $\neg(\exists k \in \mathbb{Z} [3 = 2k])$. So that means that $3$ does not fulfill the condition. So we can conclude that $3 \notin A$.

Here are a few more examples:

>[!Example]
> The set $A$ of real numbers between $5$ and $6$ (inclusive) can be written as:
> $$
> A = \{ x \in \mathbb{R} : 5 \leq x \land x \leq 6 \}
> $$
> 
> So for example, $5 \in A$, $6 \in A$, $5.5 \in A$, and so on. But $5.1 \notin A$.

>[!Example]
> The set $C$ of real numbers between $1$ and $3$ (exclusive) can be written as:
> $$
> C = \{ x \in \mathbb{R} : 1 < x \land x < 3 \}
> $$
> 
> So for example, $1 \notin C$, $3 \notin C$. But $2 \in C$, and since $\sqrt{2} \approx 1.414$, $\sqrt{2} \in C$.

>[!Example]
> The set of prime numbers can be written as:
> $$
 B = \bigg\{ x \in \mathbb{N} : x \geq 2 \land \big( \forall d \in \mathbb{N}[ divides(d, x) \to (d = 1 \lor d = x) ] \big) \bigg\}$$
> where the predicate $divides(d, x)$  is defined as $\exists k \in \mathbb{Z}[d\cdot k = x]$.
> 
> Again, for example, is $7 \in B$? We know $7$ only has 2 divisors: $1$ and $7$ itself. So let's check: $7$ is greater than or equals to $2$, take any $d \in \mathbb{N}$, if $d$ does in fact divide $7$, we know it has to be either $1$ or $7$. So we can conclude that $7$ is indeed in $B$.
> 
> On the other hand, something like $10$, has divisors $1$, $2$, $5$, $10$. $10$ is indeed greater than or equals to $2$. But what about the second half of the condition? Let's see. Consider value $5$. $5$ is in $\mathbb{N}$, and $divides(5, 10)$ is $true$. But $5$ is neither $1$ nor $10$. So $(5 = 1 \lor 5 = 10)$ is $false$. This means the condition $\big( \forall d \in \mathbb{N}[ divides(d, 10) \to (d = 1 \lor d = 10) ] \big)$ is $false$. So $10$ fails the condition. Which means $10 \notin B$

 Set builder notation is pretty handy, so let's talk about the general format now:

![[public/Images/set-builder.png]]

So again, we go through elements from some set $S$, and if it fulfills the conditions laid out by $P(x)$, we will admit element $x$. 

>[!Example]
> Let's try one more example, let's say we want the even integers between $1$ and $10$ inclusive. We could also write this:
>
> $$
\{ x \in [10] : \exists(k \in \mathbb{Z}[x = 2k]) \}
> $$
>
> Pay special attention to how this time around we used $x \in [10]$, instead of $x \in \mathbb{Z}$ as before. There is an alternative way to write this:
>
> $$
\{ x \in \mathbb{Z} : x \geq 1 \land x \leq 10 \land \exists(k \in \mathbb{Z}[x = 2k]) \}
$$

# Set Operations
Okay, the next thing to do is to talk about the set operations. These are ways that we can build bigger sets from the ones we currently have. These are super handy and go part in parcel with database operations, and also they somewhat correspond to our logical operations, as we will see. 

As a summary, there are almost all the set operations:
1. Set Union
2. Set Intersection
3. Set Difference
4. Powerset
5. Cartesian Product

## Set Union
Given two sets $A, B$, we can create a new set $C = A \cup B$, which is the **union of $A$ and $B$**. The set $C$ contains elements that are either in $A$ or in $B$. Formally $C$ contains all the elements $x$ where: 

$$
x \in A \lor x \in B
$$

>[!Example]
> $$
> \{1, 2, 3, 4, 5, 7, 8, 9, 10\} = \{1, 2, 3, 4, 5, 10\} \cup \{1, 7, 8, 9, 10\}
> $$

>[!Example]
> For example, we want to make a set $C$ that contains both positive odd numbers, and all negative numbers. Then we can do it in the following way:
> 
> $$
> C = \{ x \in \mathbb{N} : \exists k \in \mathbb{Z} [x = 2k+1] \} \cup \{ x \in \mathbb{Z} : x \leq -1 \}
> $$

>[!Example]
> For example, we want to make a set $C$ that contains both non-negative odd numbers, and also non-negative even numbers:
> 
> $$
> C = \{ x \in \mathbb{N} : \exists k \in \mathbb{Z} [x = 2k+1] \} \cup \{ x \in \mathbb{N} : \exists k \in \mathbb{Z} [x = 2k] \}
> $$
> 
> > Wait a minute, isn't this just $\mathbb{N}$?
> 
> Yes. Yes it is!

## Set Intersection
Given two sets $A, B$, we can create a new set $C = A \cap B$ which is the **intersection of $A$ and $B$**. The set $C$ contains elements that are both in $A$ and in $B$. Formally $C$ contains all the elements $x$ where: 

$$
x \in A \land x \in B
$$


>[!Example]
> $$
> \{1, 3, 10\} = \{1, 2, 3, 4, 5, 10\} \cap \{1, 7, 8, 9, 10\}
> $$

>[!Example]
> For example, we want to make a set $C$ that contains even numbers that are only negative. We could do so in the following way:
> 
> $$
> C = \{ x \in \mathbb{Z} : \exists k \in \mathbb{Z} [x = 2k] \} \cap \{ x \in \mathbb{Z} : x \leq -1 \}
> $$

## Set Difference

Given two sets $A, B$, we can create a new set $C = A \setminus B$, which we call the set **$A$ minus $B$**. The set $C$ contains elements that are from in $A$ that is not also in $B$. Formally $C$ contains all the elements $x$ where: 

$$
x \in A \land x \notin B
$$

>[!Example]
> Let $A =\{1, 2, 3, 4, 5, 10\}$, and $B = \{1, 7, 8, 9, 10\}$.
> 
> $$
> \{2, 3, 4, 5\} = \{1, 2, 3, 4, 5, 10\} \setminus \{1, 7, 8, 9, 10\}
> $$
> 
> Notice that elements $1$ and $10$ is from $A$ but also in $B$, so it is not in $C = A \setminus B$. On the other hand, elements $2, 3, 4, 5$ are in $A$ but not in $B$, so they are in $C$.

>[!Example]
> For example, we want to make a set $C$ that contains any non-negative number that is not prime. Then we can do the following:
> 
> Let $$B = \bigg\{ x \in \mathbb{N} : x \geq 2 \land \big( \forall d \in \mathbb{N}[ divides(d, x) \to (d = 1 \lor d = x) ] \big) \bigg\}$$
> where the predicate $divides(d, x)$  is defined as $\exists k \in \mathbb{Z}[d\cdot k = x]$.
> 
> Then $C = \mathbb{N} \setminus B$.
> 
> Notice here $C$ contains any element from $\mathbb{N}$ that is not in set $B$ (which is the set of primes).

## Powerset
The powerset operation is a little unorthodox, it does not look like a logical operation like the ones we have seen. Given a set $A$, the powerset of $A$ is denoted by $\mathcal{P}(A)$ is the set that contains all subsets of $A$. Formally:

$$
X \subseteq A \to X \in \mathcal{P}(A)
$$

>[!Example]
> $$\mathcal{P}(\{0, 1\}) = \{ \emptyset, \{0 \}, \{1\}, \{0, 1\} \}$$
> 
> Notice here that: $\emptyset \subseteq \emptyset$, so $\emptyset \in \mathcal{P}(\emptyset)$.
> 
> Similarly, a set like $\{0 \} \subseteq \{0, 1\}$ so $\{0 \} \in \mathcal{P}(\{0, 1\})$.


>[!Example]
> $$\mathcal{P}(\emptyset) = \{ \emptyset \}$$
> 
> Remember, $\emptyset \subseteq \emptyset$, so $\emptyset \in \mathcal{P}(\emptyset)$.

## Cartesian Product

Given a sets $A$, and $B$. The set $C = A \times B$ is the **cartesian product between sets $A$ and $B$**. This creates **pairs**. If $x \in A$ and $y \in B$, then the pair $(x, y) \in C$. 

**Note:** This operation is one of the most important in how we start creating almost other concepts later on. (Relations, Graphs, etc)

>[!Example]
> Let $A =\{1, 2, 3\}$, and $B = \{1, 2\}$.
> 
> $$
> A \times B = \{ (1, 1), (1, 2), (2, 1), (2, 2), (3, 1), (3, 2) \}
> $$
> 
> Pictorially, you can see how we got the elements.
> ![[content/Images/cross-product.png]]

Notice here the pairs are **ordered**. So $(1, 2) \in A \times B$, and $(2, 1) \in A \times B$. But $(1, 2) \neq (2, 1)$.

>[!Example]
> $\mathbb{Z} \times \mathbb{Z}$ is the set that contains any pair of integers. For example, $(-1, 25) \in \mathbb{Z} \times \mathbb{Z}$. But $(\frac{1}{2}, 21) \notin \mathbb{Z}$.


# Ways To Prove Set Equivalence

So up until this point, we have been showing how to manipulate and create all kinds of sets. And you might have noticed, that sometimes there's more than one way to create a set. Also, knowing when two sets are equivalent is pretty helpful for something like databases (for those who are curious and would like a sneak peek, you might look want to take a peek at the concepts [relational algebra](https://en.wikipedia.org/wiki/Relational_algebra), and [relational calculus](https://en.wikipedia.org/wiki/Relational_calculus) for databases).

There's broadly two categories for how to show two sets are equivalent. We will be showing both ways.