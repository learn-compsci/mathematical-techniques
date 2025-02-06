---
title: "Unit 3: Relations"
---
This unit introduces the notion of relations and is for Week 6. The unit will introduce:
1. Basic Relations, Creating Relations
2. Relation Composition, Relation Inversion
3. Transitivity, Symmetry, Anti-Symmetry, Reflexivity
4. Equivalence Classes, Partial Orders

# Unit Introduction
In this unit, we'll move on and extend [[Unit 2]] on sets and talk about a special type of sets, called **relations**.

As mentioned, one of the biggest reasons for knowing set operations and relations has to do with databases. It is not the only motivation, but in my opinion it is one of the the most immediately motivating topics for why study set theory and relations for computer science students. Another deeper reason presents itself in distributed systems, and a lot of the language about relations is very useful there as well.

That said, relations are interesting for other reasons in their own right for discrete mathematics as well. This unit will talk about relations, cover basic terminology and concepts, and show you how they are useful for databases and distributed systems. Again, the unit will start with terminology, and basic concepts, and end on proofs about such concepts.


# Motivating Relations
Our starting point is to talk about what a relation is. And there are **2 separate ways** to motivate this. Let's talk about both ways:

## Databases
Let's say that you had to represent some data. We've already seen some examples of this at the start and end of [[Unit 2]] on sets. But let's try to motivate why data is organised that way. (While TCX1004 is not a course on databases, I think all the same it is great to talk about the relational data model here. You won't learn about databases until TCX2003, but seeing this in advance won't hurt)

Let's say we collected some data about people and their email addresses, perhaps via survey or something. So here's the example table we had again:

|    Name     |         Email         |
| :---------: | :-------------------: |
|  Jon Snow   |    jsnow@gmail.com    |
| Barry Allen | the_flash@hotmail.com |
|   Pikachu   |   pika@pokemail.com   |

One way to see this is that we actually have 3 pairs from a set that looks something like this:

$$
Data = Name \times Email
$$

Where $Data$ is a set that is the [[Unit 2#Cartesian Product|cartesian product]] of two sets $Name$, and $Email$. Here, let's pretend that $Name$ contains all the possible names in the world, and $Email$ also contains all the possible email addresses we have in the world.

So based on this terminology, we can say something like $(Jon\ Snow, jsnow@gmail.com) \in Data$. Similarly, we can say $(Barry\ Allen, the\_flash@hotmail.com) \in Data$.

Here in set theory terminology, something like $(Jon\ Snow, jsnow@gmail.com)$ is called a **pair**. It is also called a **2-tuple**.

Importantly, can call this a **relation**. Why? We are **relating the names to emails**. We are establishing an association, or a relation between someone's name and their email.

This way of representing data is called the [**relational model**](https://en.wikipedia.org/wiki/Relational_model) by people who study and use databases. The concept was coined by [Dr. Edgar F. Codd](https://en.wikipedia.org/wiki/Edgar_F._Codd). In some sense, he took the concept of [relations](https://en.wikipedia.org/wiki/Relation_(mathematics)) in mathematics and decided to use it to represent data. You will see why the model is useful in a class on databases. We are just using this real-life example as a motivation on why understand relations. [[Unit 3|In the previous unit]], we talked about set operations, and those are very much applicable in a database setting. Since to (union / intersect / set minus) your data is a very common form of data manipulation. (See [[Unit 2#Bonus: Google Sheets|the bonus section at the end of unit 2]])


## How to Represent Orderings

Putting the cart before the horse for a little bit, (showing you how and why it's used before showing you the concept) one big application from a mathematical perspective is the ability to talk about orderings among objects. There is probably one you're quite familiar with: ordering numbers from sets like $\mathbb{N}, \mathbb{Z},$ or $\mathbb{R}$ using $\leq$. Perhaps that seems quite uninteresting. But understanding how to "order" or how to "sort" objects is actually quite a huge area of study, and has in the last 1-2 decades found its way into computer science as well.

If you ever find yourself studying memory models for concurrency based applications, or designing a distributed systems algorithm, chances are you will have to know a little bit about partial orders (as special type of relation). The vague idea is that when you need to start saying things like "this memory event **happened before** the other memory event", that is also a kind of ordering.



# Definition of a Relation
Let's think a little bit about how to "relate" two objects. Again, using the example from earlier and from the previous unit, perhaps we want to relate people to their emails, then we can think of creating **pairs** to do this. For example, we might represent our data like this:

|    Name     |         Email         |
| :---------: | :-------------------: |
|  Jon Snow   |    jsnow@gmail.com    |
| Barry Allen | the_flash@hotmail.com |
|   Pikachu   |   pika@pokemail.com   |
Mathematically, we will see this our table (let's call it $T$) as a set of 3 pairs:

$$
\begin{align*}
T = \{\\&(Jon\ Snow, jsnow@gmail.com),\\&(Barry\ Allen, the\_flash@hotmail.com),\\& (Pikachu, pika@pokemail.com)\\\}
\end{align*}
$$


Notice here that if we let $E$ be the set of all possible emails, and $N$ be the set of all possible names, then $T \subseteq N \times E$. Note that it is not necessarily the case that $T = N \times E$. $T$ here only contains certain pairs from $N \times E$, not all of them!

$T$ here is a **relation** that relates elements from $N$ to elements in $E$. A relation is really just a set that tells us how objects and $N$ and $E$ are associated.


Here's another example, we could have had a table of student data that includes:
1. Their name
2. Their year of enrolment
3. Their degree

Perhaps something like this:

|  Name  | Year of Enrolment | Degree  |
| :----: | :---------------: | ------- |
| Simon  |       2023        | CS      |
| Janice |       2020        | Philo   |
|  Meg   |       2015        | CS      |
|  Sam   |       2016        | Science |

Then we could have represented this using a set $S$ like so:

$$
\begin{align*}
S = \{\\
&(Simon, 2023, CS),\\
&(Janice, 2020, Philo),\\
&(Meg, 2015, CS)\\
&(Sam, 2016, Science)\\
\}
\end{align*}
$$

Like a set of triples. But what if we wanted two sets $A$, $B$ that represented the following relations?

1. Set $A$ relates the student names to the year of enrollments.
2. Set $B$ relates the student names to the degree programmes.

Try for yourself to write down what those sets look like, and what are they a subset of? Check it with yourself in the hidden-away spoiler tag. We can let $M$ be the set of all possible names, and we can let $P = \{CS, Philo, CS, Science, Eng, Biz\}$.

>[!Answer]-
> $A$ can be a subset of something like $M \times \mathbb{N}$. Based on our data, it can also be a subset of something like $M \times \{2015, 2016, 2020, 2023\}$. Both answers are viable.
> 
> $A = \{(Simon, 2023), (Janice, 2020), (Meg, 2015), (Sam, 2016)\}$

>[!Answer]-
> $B$ can be a subset of something like $M \times P$.
> 
> $B = \{(Simon, CS), (Janice, Philo), (Meg, CS), (Sam, Science)\}$


Formally, we will consider **any set** that is a subset of some cartesian product of sets to be a relation.

>[!Example]
> $$
> \begin{align*}
T = \{\\&(Jon\ Snow, jsnow@gmail.com),\\&(Barry\ Allen, the\_flash@hotmail.com),\\& (Pikachu, pika@pokemail.com)\\\}
\end{align*}
> $$