---
title: "Unit 3: Relations"
---
This unit introduces the notion of relations and is for Week 6. The unit will introduce:
1. Basic Relations, Creating Relations
2. Relation Composition
3. Transitivity, Symmetry, Anti-Symmetry, Reflexivity

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

One way to see this is that we actually have a set that looks something like this:

$$
Data = Name \times Email
$$

Where $Data$ is a set that is the [[Unit 2#Cartesian Product|cartesian product]] of two sets $Name$, and $Email$. Here, let's pretend that $Name$ contains all the possible names in the world, and $Email$ also contains all the possible email addresses we have in the world.

So based on this terminology, we can say something like $(Jon\ Snow, jsnow@gmail.com) \in Data$. Similarly, we can say $(Barry\ Allen, the\_flash@hotmail.com) \in Data$. We can also say something like $(Tony\ Stark, ironman@starkmail.com)\notin Data$.

Here in set theory terminology, something like $(Jon\ Snow, jsnow@gmail.com)$ is called a **pair**. It is also called a **2-tuple**.

Importantly, can call this a **relation**. Why? We are **relating the names to emails**. We are establishing an association, or a relation between someone's name and their email.

This way of representing data is called the [**relational model**](https://en.wikipedia.org/wiki/Relational_model) by people who study and use databases. The concept was coined by [Dr. Edgar F. Codd](https://en.wikipedia.org/wiki/Edgar_F._Codd). In some sense, he took the concept of [relations](https://en.wikipedia.org/wiki/Relation_(mathematics)) in mathematics and decided to use it to represent data. You will see why the model is useful in a class on databases. We are just using this real-life example as a motivation on why understand relations. [[Unit 3|In the previous unit]], we talked about set operations, and those are very much applicable in a database setting. Since to (union / intersect / set minus) your data is a very common form of data manipulation. (See [[Unit 2#Bonus: Google Sheets|the bonus section at the end of unit 2]])


