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


Formally, we will consider **any set** that is a subset of some cartesian product of sets to be a **relation**. Alternatively, any set of pairs is **relation**. 

Here are a few more examples:

>[!Example]
> Let's say $F$ is the set of all possible foods, and $P$ is the set of all possible people, then we can have a set $S$ that is a relation between people and the food they enjoy eating.
> $$\begin{equation}S = \{(Jane, Laksa), (Marco, Toast), (Jane, Pasta), (Sam, Toast)\}\end{equation}$$
> 
> Notice here that we can relate one person to more than one food. We can also relate more than one person to one food. In general, since $S$ is a subset of $P \times F$, it is considered a relation.

>[!Example]
> Let $D = \{(y, x) \in \mathbb{Z} \times \mathbb{Z} : \exists k \in \mathbb{Z}[x \cdot k = y]\}$.
> 
> Then $D$ relates integers $y$ to other integers that divide it. For example $(10, 2) \in D$, because $2$ divides $10$. Also $(10, 3) \notin D$, because $3$ does not divide $10$.

>[!Example]
> Let $M = \{ (a, b) \in \mathbb{Z} \times \mathbb{Z} : \exists t \in \mathbb{Z}[a- b = 3k] \}$.
> 
> Then $M$ relates integers $a$ to integers $b$ if they have the same divisor when divided by $3$. For example, $(7, 17) \in M$ because both have the remainder $1$ when divided by $3$. Similarly, $(27, 6) \in M$ because both have the remainder $0$. Whereas $(3, 11) \notin M$ because $3$ has remainder $0$, but $11$ has remainder $2$.

# Operations on Relations

Just like sets, there are a few common operations that we need to learn for relations. We will cover the two most common ones:

1. Relation inversion
2. Relation composition

## Relation Inversion
Given a relation $R = A \times B$, the **inversion** of a relation is written as $R^{-1}$, and is defined in the following way:

$$\begin{equation}
R^{-1} = \{ (b, a) \in B \times A : (a, b) \in R \}
\end{equation}$$

Basically it is just saying that a pair $(b, a)$ is in $R^{-1}$ if and only if $(a, b)$ is in $R$. Think of $R^{-1}$ as just "reversing" the pairs in $R$.

Let's see what this means for our previous 3 examples.

>[!Example]
> Let's say $F$ is the set of all possible foods, and $P$ is the set of all possible people, then we can have a set $S$ that is a relation between people and the food they enjoy eating. Previously, we gave an example of such a set.
> $$\begin{equation}S = \{(Jane, Laksa), (Marco, Toast), (Jane, Pasta), (Sam, Toast)\}\end{equation}$$
> 
> Then $$\begin{equation}S^{-1} = \{(Laksa, Jane), (Toast, Marco), (Pasta, Jane), (Toast, Sam)\}\end{equation}$$

>[!Example]
> Let $D = \{(y, x) \in \mathbb{Z} \times \mathbb{Z} : \exists k \in \mathbb{Z}[x \cdot k = y]\}$.
> 
> Recall that $(10, 2) \in D$, because $2$ divides $10$. Also $(10, 3) \notin D$, because $3$ does not divide $10$.
> 
> So for example $(2, 10) \in D^{-1}$. $(3, 10) \notin D^{-1}$.

>[!Example]
> Let $M = \{ (a, b) \in \mathbb{Z} \times \mathbb{Z} : \exists t \in \mathbb{Z}[a- b = 3k] \}$.
> 
> Since $(7, 17) \in M$, this means $(17, 7) \in M^{-1}$. For the same reason, $(6, 27) \in M^{-1}$. Also, since $(3, 11) \notin M$, then $(11, 3) \notin M$.

## Relation Composition

Next, is the relation composition operation. This one is slightly involved, so let me start with a few examples

#### Example 1
Let's say we had a set that relates locations via bus routes. Set $A$ might relate the stops of the 284 bus. We will say $(a, b) \in A$ if bus stop $a$ is directly before stop $b$. 

![[bus-284.png]]

So for example, $A$ looks something like this:

$$\begin{align}
A= \{ &\\
	&(Clementi\ INT, Bef\ Blks\ 315/318),\\
	&(Bef\ Blks\ 315/318, BLK\ 308),\\
	&(BLK\ 308, BLK\ 376)\\
	&(BLK\ 376, Clementi\ INT)\\
\}&
\end{align}$$


What if we wanted to say that we wanted to take the 284 bus for **exactly** two stops? Well then we could write this as the **composition of $A$ with $A$, denoted by** $A{;}A$. And it is such that:

$$\begin{align}
A ; A= \{ &\\
	&(Clementi\ INT, BLK\ 308),\\
	&(Bef\ Blks\ 315/318, BLK\ 376),\\
	&(BLK\ 308, Clementi\ INT)\\
\}&
\end{align}$$


Notice how the reason why $(Clementi\ INT, BLK\ 308) \in A ; A$ was because there was **some** value $x$, such that $(Clementi\ INT, x) \in A$ and also $(x, BLK\ 308) \in A$. (Namely, $x = Bef\ Blks\ 315/318$.)


#### Example 2
Let's try another example, this time around let's make a set $E$ that relates any two MRT stations that are connected via the East-West line. So, this means for example, $(City\ Hall, Clementi) \in E$. (even if they are not directly next to each other)

Let's also make another set $N$ that relates any two MRT stations that are connected via the North-South line. So for example, $(Toa\ Payoh, City\ Hall) \in N$.

Okay, so this time around, we have two different relations. Think a little bit about what the relation $E; N$ represents.

$E; N$ relates two MRT stations $(s_1, s_2)$ if we can start from a station $s_1$ that is on the North-South line, and $s_2$ is a station that is on the East-West line. 

So for example, $(Yishun, Bedok) \in E; N$. But something like $(Redhill, Yew\ Tee)\notin E ; N$. Also, something like $(City\ Hall, Raffles\ Place) \in E; N$. Can you see why?


Pictorially, here's what's going on:

![[Images/mrt-composition.png]]

We can say something like $(Dhoby\ Ghaut, Tanjong\ Pagar)$, because we know $(Dhoby\ Ghaut, City\ Hall)$ is in $N$ and $(City\ Hall, Tanjong\ Pagar)$ is in $E$.

![[Images/relations-middle-man.png]]


### In General:
In general, the definition of a composition of relations $R, S$ is the following. Let $R \subseteq A \times B$, let $S \subseteq B \times C$, then:

$$\begin{equation}
R ; S = \{ (a, c) \in A \times C : \exists b \in B[(a, b) \in R \land (b, c) \in S] \} 
\end{equation}$$


In English, this is basically just saying:

> $a$ and $c$ are related by $(R; S)$ if we can find a $b \in B$ such that $a$ is related to this $b$ using relation $R$, and the same $b$ is related to $c$ using relation $S$.
> 
> If no such $b$ exists, then $a$ and $c$ are **not** related by $(R, S)$.

You can mentally picture this as "Taking one step using $R$, and then taking one step using $S$."

So let's go back through the examples we had, and see what happens.

>[!Example]
> Let's say $F$ is the set of all possible foods, and $P$ is the set of all possible people, then we can have a set $S$ that is a relation between people and the food they enjoy eating. Previously, we gave an example of such a set.
> $$\begin{equation}S = \{(Jane, Laksa), (Marco, Toast), (Jane, Pasta), (Sam, Toast)\}\end{equation}$$
> 
> Then $$\begin{equation}S; S = \emptyset \end{equation}$$
> 

>[!Example]
> Let $D = \{(y, x) \in \mathbb{Z} \times \mathbb{Z} : \exists k \in \mathbb{Z}[x \cdot k = y]\}$.
> 
> For example, since $(5, 10) \in D$, and $(10, 200) \in D$, then $(5, 200) \in D; D$.
> 
> Do you notice something interesting? In general we can actually notice that if $x$ divides $y$, and $y$ divides $z$, then $x$ divides $z$ (this can be proven). So we can actually argue that if $(a, b) \in D$ then $(a, b) \in D; D$. Or in other words, $D \subseteq D; D$.

>[!Example]
> Let $M = \{ (a, b) \in \mathbb{Z} \times \mathbb{Z} : \exists t \in \mathbb{Z}[a- b = 3k] \}$.
> 
> Since $(3, 27) \in M$ and $(27, 51) \in M$, we can say $(3, 51) \in M; M$.


>[!Example]
> Let $D = \{(y, x) \in \mathbb{Z} \times \mathbb{Z} : \exists k \in \mathbb{Z}[x \cdot k = y]\}$, and $M = \{ (a, b) \in \mathbb{Z} \times \mathbb{Z} : \exists t \in \mathbb{Z}[a- b = 3k] \}$.
> 
> Then $(2, 8) \in D$ and $(8, 14) \in M$, so $(2, 14) \in D; M$.

