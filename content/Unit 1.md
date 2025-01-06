---
title: "Unit 1: Propositions, Predicates, First Order Logic, Proofs"
---

# Overview
This unit introduces the notion of proofs, propositional and first order logic, and certain proof techniques. Along the way we will talk about proofs in the context of both discrete mathematics and computer science. The unit is split into 3 sub-parts:
1. Motivation and introduction to propositional logic, first order logic and proofs.
2. Propositional logic
3. First order logic.
4. Proof techniques (and patterns).

# Part 0: Unit Introduction

Let's begin by asking ourselves how exactly it is that people decide what "facts" are true and which are false in reality. Even this is a little philosophical, but it's a great starting point to contrast with how other fields do it:

>[!Example]
> 1. How do physicists agree that certain statements like $E = m c^2$ or $F = ma$ is true or not?
> 2. How do pharmacists decide if a certain drug $X$ is effective in treating a certain disease or not?
> 3. How does the criminal justice system decide if a certain person has committed a crime?

These are examples of _statements_ whose truth has to be ascertained. In the case of science, the answer is usually that experiments are run, and in light of the data available, one might infer with reasonable certainty that a statement is true (or otherwise). In the case of the justice system, two lawyers argue their case in front of a judge. Every party presents their interpretation of the laws in human language and the "truth" is decided by the judge (or jury) involved. In a manner of speaking, we can consider this process as giving _proofs_.

What about in mathematics? In its purest form, there are no experiments to run, and ideally we do not appoint random people as arbiters of truth in math (like judges in the legal system). Because of the nature of the statements (as you will see) we want something more robust and universal. That said, the job is pretty much the same: We want to figure out which statements are true, and which statements are not.

Formulating statements themselves is a bit of a tricky task (perhaps as compared to other fields) and in this unit we will be talking about how to express ourselves in this language that is somewhat free from human language. Besides that, we will need to talk about how do we go about determining if certain statements are indeed true or not. As it turns out, that will be the bulk of the work for this course.

Let's start being a little more concrete and a little less abstract! Say I came up to you and said something like "The sum of the numbers $1$, $2$, $3$ and so on until $n$ is exactly $\frac{(n + 1)n}{2}$." You might first of all wonder "Why do we even care?". As it turns out, even such a benign statement has uses in algorithm and program analysis. For example if we had the following for loop:

```python
for i in range(n):
	for j in range(i + 1):
		do_something()
```

How many times is `do_something()` called? Looking at this program and being able to reason about this sort of behaviour is something discrete math is about (in computer science). For example, we know that when $i = 1$, the inner loop runs $1$ time. When $i = 2$, the inner loop runs $2$ times, and so on. So the inner loop is run $1 + 2 + \cdots + n$, which is written as $\sum_{i = 1}^n i$. But how do we know that this is the same as $\frac{(n+1)n}{2}$?

Sure we could try it for $n = 1, 2, 3, 4$ and realise that the two are the same. But what if there is some magical funny number for which they are different? How do we know for a fact that it works **for all** numbers?

This is the kind of question whose _truth_ we wish to determine or ascertain in discrete math:
"Is it true that for all numbers $n$, adding numbers $1, 2, 3, \ldots$ up until $n$ is the same as $\frac{n(n+1)}{2}$?"

There's a lot of these statements that we can ask. And in due time, we will ask, and answer a lot of these. But first! We also need to learn how to speak in a new language. Why? There are a few reasons:

1. We want something that isn't 100% bound to any particular language.
2. Human language is quite ambiguous at times. And different languages are ambiguous in different ways.

We can't eliminate the use of human language completely without making our jobs entirely miserable, but hopefully as a huge plus you'll see that after we pick up this new system, it actually makes it easier to reason about statements in computer science and math.

## Why must we do this?
It is a little hard to explain the ease of use this new skillset would bring to someone who hasn't ever used it before. Perhaps the best way is to show an example and how unwieldy plain human language is for the task.

Let's say we had the following code:

```python
def find_max(list_of_numbers):
	max_value = list_of_numbers[0]
	for idx in range(1, len(list_of_numbers)):
		max_value = max(max_value, list_of_numbers[idx])
	return max_value
```

How do we argue it is correct? I know the code probably looks correct and most people would not really question it. But for the sake of example, how does one **really** look at this and convince themselves the code is correct? You might say something like:

> Well we start from the first element of the list, set that to `max_value`, then go through every element of the list, and we keep updating `max_value` to the larger so it has to be the maximum of the entire list.

Which pretty much matches our intuition. And intuition isn't a bad thing! But what happens if we start looking at more complicated programs, bigger algorithms? We might want something a little more reliable.

The other issue is that some terms here in English are often vague. For example, here's a common sign that we see in SoC: "No food and drink allowed in the computer lab."

So which of these options does it mean?
1. No (food and drink) allowed in the computer lab.
2. (No food) and drink allowed in the computer lab.
3. (No food) and (no drink) allowed in the computer lab

And another question you might ask yourself is whether option 1 and option 3 are the same. Do they mean the same thing? Some might interpret them to be the same. So what happens to the following people?

1. The one that brings both food and drink into the lab.
2. The one that brings only drink into the lab.
3. The one that brings only food into the lab.

Which ones get banned and which ones do not? This quirk in human language is something we will want to avoid.

If you've ever noticed that legal documents tend to be verbose, it has in part to do with the fact that they aim to eliminate all forms of confusion as possible. Sometimes legal arguments are about how to reasonably interpret agreed upon literature. In computer science we take a slightly different approach of having a slightly modified language where the interpretation is mostly agreed upon by everyone.

The reason for this difference is that unlike in the legal field, we are more concerned with statements and truths that are inherently mathematical in nature. For that reason, almost no amount of verbosity in English will be helpful here. Furthermore, it is far more efficient and straightforward to pick up a new way of speaking and reading. But don't worry! You will have an entire semester to practice this and I promise your journey in formal CS will be smoother because of it.

In English, the grand scheme of this unit is this: We want to be able to write proofs. To do this, there are a few things you will need to know. How to read and understand basic sentences in proofs, the rules that are applicable in proofs and how to avoid errors. And how to "say what you want to say" in proofs. The roadmap laid out for you is the following: Learning the basic sentences of proofs. Learning how to connect sentences together. Learning how to make deductions starting from assumptions and how to avoid errors when doing so. Then higher level proof strategies.

But to sum up:
# Unit Learning Outcomes
- [ ] Part 1: Understanding propositional logic
	- [ ] Knowing and forming propositions and propositional formulae
	- [ ] Knowing and using logical connectives on propositions to form propositional formulae
	- [ ] Evaluating propositional formulae
	- [ ] Understanding logical equivalences
- [ ] Part 2: Understanding first order logic
	- [ ] Understanding Predicates
	- [ ] Understanding quantifiers
	- [ ] Evaluating first order logic statements
- [ ] Part 3: Understanding basic proofs
	- [ ] Knowing what assumptions, premises, and conclusions are
	- [ ] Knowing what a proof needs to do in order to prove a statement
	- [ ] Inference/Deduction rules for proofs
	- [ ] General Proof Strategies

Just remind yourself, big picture: **we want to do proofs**.
# Part 1: Propositional logic

#### Basic Propositions
Our starting point is forming propositions. Think of this as part 1 of the grammatical system. Let's re-examine that sentence again and see how we might view this in a new light:

Instead of "No food and drink allowed in the computer lab.", let's first re-write it into "No food allowed in the computer lab and no drink allowed in the computer lab."

Now in propositional logic, we will consider "No food allowed in the computer lab" as a **proposition**. We will also consider "no drink allowed in the computer lab" to also be a **proposition**. 

Think of a proposition as a statement that is either true or false. So these are more examples of propositions:

1. (20 + 25)(20 + 25) = 2025
2. 50 - 20 = 1
3. Birds can fly.

In physics there are atoms the widely-assumed-to-be indivisible objects of this world. Here in propositional logic, propositions are the atoms (in that these are the smallest things).

Now, the first statement is true, the second is false, but what about the last one? One might think yes, of course birds can fly. But what about penguins, ostriches, and emus? So is the statement false? Is it true? Depending on who you ask, the answer might be different but thankfully, this is not the type of statement that we are concerned with in CS and math.
#### Logical Connectives
Next thing to note is that we can form bigger and bigger **formulae** from smaller ones by using the following **logical connectives**:
1. and
2. or
3. if, then
4. not

Again, using our example, we have the propositions "No food allowed in the computer lab", "No drink allowed in the computer lab", we can make the following formula:

> No food allowed in the computer lab **and** no drink allowed in the computer lab.

Likewise, we could also make the following other examples:

1. No food allowed in the computer lab **or** no drink allowed in the computer lab.
2. **If** no food allowed in the computer lab **then** no drink allowed in the computer lab.
3. Not (no food allowed in the computer lab).

Perhaps the last one is a little clunky, and over time we'll start avoiding English and these clunky issues will stop persisting.

In general, we expect to do the following with logical connectives:
1. \[Proposition 1] **and** \[Proposition 2]
2. \[Proposition 1] **or** \[Proposition 2]
3. **If** \[Proposition 1] **then** \[Proposition 2]
3. Not \[Proposition]

To be clear, here some other examples of simple propositional formulae that we might see in math and CS:
1. 1 + 1 = 3 **and** 25 + 1 = 26
2. **not** 1 + 1 = 3
3. 1 + 1 = 3 **or** 25 + 1 = 26
4. **if** 1 + 1 = 3 **then** 25 + 1 = 26

We can also chain these to make even bigger ones, like so:
1. $1 + 3 = 24$ **and** $2 \times 2 = 4$ **and** $2 + 2 = 4$
2. **if** $1 + 3 = 24$ and $1 + 2 = 5$ **then** $5 \times 5 = 25$ **or** $6^2 = 36$

>[!Rounding Up]
> 1. **Propositions** are statements that are only either **true** or **false**, and never both at the same time.
> 2. We can create even bigger formulae by connecting other propositions using either **and**, **or**, **if, then**, and **not**.

The next thing to ask is **how do we determine the truth values of the bigger propositions?** This is a key step in eliminating vagueness from our language: the wider math and CS community has agreed on these meanings and this behavior.
#### Logical symbols
One more thing before we proceed, in line with understanding conventions, let $p,q$ be propositions (substitute them with anything you like), we write the following:

| logical connective | respective symbol |
| :----------------: | :---------------: |
|    $p$ and $q$     |    $p \land q$    |
|     $p$ or $q$     |    $p \lor q$     |
|  if $p$ then $q$   |     $p \to q$     |
|      not $p$       |     $\neg p$      |

#### Behaviour of logical connectives
Let's define the behaviours of the operations now.

|  $p$  |  $q$  | $p \land q$ | $p \lor q$ | $\neg p$ | $p \to q$ |
| :---: | :---: | :---------: | :--------: | :------: | :-------: |
| true  | true  |    true     |    true    |  false   |   true    |
| true  | false |    false    |    true    |  false   |   false   |
| false | true  |    false    |    true    |   true   |   true    |
| false | false |    false    |   false    |   true   |   true    |

Okay that table might be a little overwhelming, but it's a good summary of what you need to understand in this section. Let's get into it.

Let's focus on the **and** operation, here's the table containing only those relevant columns.

|  $p$  |  $q$  | $p \land q$ |
| :---: | :---: | :---------: |
| true  | true  |    true     |
| true  | false |    false    |
| false | true  |    false    |
| false | false |    false    |

So what's going on here? If we have two propositions $p, q$, then $p \land q$ is true only when both of them are true. Otherwise, if at least one of them is false, then $p \land q$ is false. This might be the most intuitive one.

Moving on, let's talk about the **not** operation.

|  $p$  | $\neg p$ |
| :---: | :------: |
| true  |  false   |
| false |   true   |

So this one might be a little intuitive too, when a proposition is true, applying the **not** operation makes it false, and vice versa.

Let's move on to something slightly more unintuitive, the **or** operation.

|  $p$  |  $q$  | $p \lor q$ |
| :---: | :---: | :--------: |
| true  | true  |    true    |
| true  | false |    true    |
| false | true  |    true    |
| false | false |   false    |
Let's get the obvious stuff out of the way, when $p$ and $q$ are both false, $p \lor q$ has to be false. And when at least one of $p, q$ is true, then $p \lor q$ is true. But what about when **both** $p, q$ are true? By convention we have chosen to say that $p \lor q$ is also true. It might seem slightly unintuitive, in English it is common we think $p$ or $q$ means that only one of $p$ or $q$ is true but not both. But in mathematics, this is the more wieldy definition.

Lastly, the most unintuitive of the bunch. Let's spend some time on this one:

|  $p$  |  $q$  | $p \to q$ |
| :---: | :---: | :-------: |
| true  | true  |   true    |
| true  | false |   false   |
| false | true  |   true    |
| false | false |   true    |

Let's use this statement as an analogy:

> **If** "it is a cat", **then** "it has paws".

When is the statement true? What is the statement false?
As long as all cats we refer to as "it" has paws, then the statement is true. Since "it" is a cat, and "it" has paws the statement isn't lying. 

What about when "it" is a cat and it doesn't have paws? Then the statement would be lying to us, and we would consider it false. Here's the intuition in English: The statement is a commitment to cats that they must have paws. So the moment we find a pawless cat, the statement has broken its commitment, and we therefore consider that statement to be false.

Okay, so far we've been considering when "it" is a cat. What about when "it" is not a cat? Well, dogs have paws too! Let's say that "it" was actually a dog, do we want to say the statement was false? No. The statement has only made a commitment about cats, not dogs. So it doesn't matter what happens then.

So let's move back to the bigger picture, given a statement $p \to q$, here are the important things to note:

1. We call $p$ the antecedent.
2. We call $q$ the consequent.
3. When the antecedent (which is $p$ here) is true, then $q$ must be true.
4. When the antecedent (which is $p$ here) is false, then it does not matter what $q$ is, $p \to q$ is always true.
5. When the consequent (which is $q$ here) is true, then it does not matter what $p$ is,  $p \to q$ is always false.

You might wonder at this point "why is it defined this way?" and you will see the answer when we start doing mathematical proofs with them. The answer is line an onion, there's many layers to it:

1. At a beginner level, the answer is that "It is actually quite intuitive to think of it that way."
2. At an intermediate level, the answer is that "A lot of the proofs line up and things work out."
3. At an even higher level, there's nothing too special about the "if, then" connective... but it does work out nicely for what we want it to do.

Here's yet another example of how to use $\to$:

$$
(x = 1) \to (x^2 = 1)
$$

Which reads:

> If $x$ is $1$, then $x^2$ is  $1$.

What happens if $x$ is not $1$? Then can we say $x^2$ is not $1$? We can't! After all, consider when $x = -1$. Then $x = 1$ is $false$, but $x^2 = 1$ is still true.

Anyway! Don't worry too much about it, my recommended way of viewing it right now is just that these are very common logical operations we wish to perform, and therefore we have chosen to give these a name.

#### Evaluating formulae

So given a formula, for example, $(p \to q) \land (q \to s)$, a **truth value assignment** to this formula is when we set each proposition (which we can also call a variable) to either true or false. Here's an example, $p \equiv true, q \equiv false, s \equiv true$ means that: $(p \to q)$ is now $false$ because of the values of $p, q$. Furthermore, $(q \to s)$ is now $true$ because of the values of $q, s$. Now, the entire formula is basically $false \land true$, which is, as we know, $false$.

In plainer terms: we are just substituting variables for truth values then seeing what the resulting truth value is. Maybe in high school you might have seen something like $y = x + 5$, and if you substitute $x = 10$ then we know $y = 15$.

#### Truth tables, logical equivalences
At this point it might be a good thing to talk about when two formulae are the same. Let's consider these two as an example:

1. $\neg ( p \lor q )$
2. $\neg p \land \neg q$

Are these two the same? Perhaps we could work intuitively first and see what it means. When is the first formula true? When is it false? One way to figure that out is work it out by hand, and using something called a **truth table**.

|  $p$  |  $q$  | $p \lor q$ | $\neg ( p \lor q )$ |
| :---: | :---: | :--------: | :-----------------: |
| true  | true  |    true    |        false        |
| true  | false |    true    |        false        |
| false | true  |    true    |        false        |
| false | false |   false    |        true         |
In the table, we write out all possible truth value assignments (we have $p, q$ so there are 4 possible truth value assignments) and work out each intermediate step. The last column is the last one we care about. And here notice that the third column depends on the first two, and the final column depends only on the third column.

Let's do the same for the second formula:

|  $p$  |  $q$  | $\neg p$ | $\neg q$ | $\neg p \land \neg q$ |
| :---: | :---: | :------: | :------: | :-------------------: |
| true  | true  |  false   |  false   |         false         |
| true  | false |  false   |   true   |         false         |
| false | true  |   true   |  false   |         false         |
| false | false |   true   |   true   |         true          |
This time, the third column depends on the first. The fourth column depends on the second, and the final column depends on the third and fourth.

Oh look! The final column is the same. This means the two formulae are **logically equivalent**. The other way of seeing is is that no matter how we set $p, q$ in the first formula, if we also set $p, q$ the same way in the second formula, it evaluates to the same truth value.

Consider instead these 2 examples:
1. $p \to q$
2. $q \to p$

Are these equivalent? Let's try making another truth table:

|  $p$  |  $q$  | $p \to q$ | $q \to p$ |
| :---: | :---: | :-------: | :-------: |
| true  | true  |   true    |   true    |
| true  | false |   false   |   true    |
| false | true  |   true    |   false   |
| false | false |   true    |   true    |
Notice how when $p$ is set to true, and $q$ is set to false, $p \to q$ is false, but $q \to p$ is true. So these two formulae are not **logically equivalent**.

> Is there a different way for us to tell if two formulae are equivalent or not?

Yes, there are a few ways, but for now this is the most reliable way. To be clear: If for all possible truth value assignments, the two formulae always evaluate to the same value, they are logically equivalent, otherwise, they are not.

>[!Rounding Up]
> 1. We can evaluate the truth value of formulae.
> 2. We can create truth tables from formulae.
> 3. We can compare to see if two formulae are **logically equivalent**.


> [!What is the point of all this?]
> In due time you'll see that this is one of the few tools we have to understand and navigate this new language. It is a little hard to see the forest for the trees right now. But trust that understanding this and getting used to it is builds a strong foundation for everything we will be doing throughout the semester.

#### A sneak peek into how we might use this: Keeping sight of the goal
We have not gone into yet but here's a rough idea of how we might expect to use this tool.

1. If Socrates is a human, then Socrates is mortal.
2. Socrates is a human.
3. Therefore, Socrates is mortal.

Think of this as a **proof** that Socrates is mortal. It consists of a few parts that we have not yet covered, and will see at the end of this unit. But for now, what you can understand is that each line is made of propositions. The propositions here are "Socrates is a human", "Socrates is mortal". Then re-writing this, we can think "Socrates is a human" as $p$, and "Socrates is mortal" as $q$.

Then instead the above **proof** looks like:

1. $p \to q$
2. $p$
3. Therefore, $q$.

For now we have not talked about how to take lines 1 and 2 and create the conclusion on line 3. But the first step is being able to build up the sentences. Perhaps one thing we can take away right now is the following: "If $p$ is true then $q$ is true. $p$ is true, therefore $q$ is true.".

Let's move onto part 2 where we want slightly more sophisticated sentences.
# Part 2: First Order Logic

Let's compare the two following proofs:

Proof 1:
1. If Socrates is a human, then Socrates is mortal.
2. Socrates is a human.
3. Therefore, Socrates is mortal.

Proof 2:
1. All humans are mortal.
2. Socrates is a human.
3. Therefore, Socrates is mortal.

The two proofs seem to have the same idea, they want to conclude that Socrates is mortal. Yet, the way that they do it is very different. Based on part 1, we can clearly mark out what the propositions are. If we tried to do the same with Proof 2, we would instead get the following: "All humans are mortal" is a proposition, "Socrates is a human" is a proposition, and "Socrates is mortal" is a proposition.

So we would end up seeing this:
1. $p$
2. $q$
3. Therefore $r$.

At this level, the 3 lines of proof 2 look unrelated to each other. And that seems to be an issue. After all, we would be very happy to accept something like Proof 2. It does look quite reasonable. So what are we missing? Remember that when talking about [[#Basic Propositions |basic propositions]], we said that propositions were like "atoms", indivisible and we were not allowed to pick apart the internals or the meanings of it. The other thing that will be useful will be to say "everything" or "something". So to do this, we have 2 new concepts to introduce to our "sentences": Predicates, and Quantifiers.

#### Predicates
The first thing to do, is to create a new kind of "word" in our sentences, called predicates. In proof 2, we want to create a predicate called $human(x)$. You can think of $human$ like a function that takes objects, and outputs either true or false. So based on this, instead of saying "Socrates is a human.", we will instead say "$human(Socrates)$ is true". Here, $Socrates$ is an object, and the predicate $human()$ evaluates to true when given $Socrates$ as input. Perhaps $Car$ is another kind of object, and $human(Car)$ evaluates to false.

Very similarly, instead of "Socrates is mortal", we will instead write $mortal(Socrates)$.

With that, we have changed lines 2, and 3 of Proof 2. But what about line 1?

#### Quantifiers
The second thing to do, is to introduce quantifiers. We want to be able to say "every human is mortal". In order to do so, we will write the following:

$$
\forall x \left( human(x) \to mortal(x) \right)
$$

Okay, maybe a little intimidating. How do we read this? Let's begin with "$\forall x$". This means "for every possible object that we will call $x$". The second part is probably a little more readable: "if $x$ is human, then $x$ is mortal.". So putting that together, we have:

$$
\text{For every possible object that we will call $x$, if $x$ is human, then $x$ is mortal.}
$$

This is what we call the **universal quantifier**. Think of this as a quantifier that says something about the entire universe.

There is another quantifier we have not mentioned, the **existential quantifier**. What if we instead wanted to say "some humans are mortal"? We write the following:

$$
\exists x( human(x) \land mortal(x))
$$
How do we read this? Now the $\exists x$ means "there exists is some object that we will call $x$". And the second part says that "$x$ is human and $x$ is mortal.". In English:

$$
\text{There exists an object that we will call $x$, $x$ is human, and $x$ is mortal.}
$$

Coming back to Proof 2, here is how we will write it:

1. $\forall x \left( human(x) \to mortal(x) \right)$
2. $human(Socrates)$
3. Therefore $mortal(Socrates)$

Again, we have not talked about how to tell this proof is good (or even what is a proof), but the goal of this part is to make sure you are able to at least read back each line to yourself in English and be convinced of its meaning.

##### Another example: Expressing Even Numbers
How should we say a number is even? In English we might say something like "A number is even if it is divisible by 2." What does it mean here to be "divisible by 2"? After all, we **can** divide $3$ by $2$, we just get $1.5$. Perhaps what we mean to say is that a whole number $x$ is even when $\frac{x}{2}$ is also a whole number. In discrete math, we say say that $x$ is an even number if:

$$
\exists k \in \mathbb{Z} [2\cdot k = x]
$$

Let's read this back in English, and see what it means:

> There exists a value from the set called $\mathbb{Z}$ that we will call $k$. For this value $k$, $2$ times $k$ is equal to $x$.


Here, think of set $\mathbb{Z}$ as the special symbol for the set of whole numbers, and when we write $\exists k \in \mathbb{Z}$, this means $k$ is in the set of whole numbers. That is to say: $k$ is a whole number. (It can be negative, it can be $0$, it can be positive, but it is a whole number). We call $\mathbb{Z}$ _the set of integers_.


>[!Rounding Up]
> 1. We have seen uses of predicates.
> 2. We have seen uses of existential and universal quantifiers.


For now, perhaps when and how we can make predicates is a little vague but the best way to understand them is via seeing them in action in Part 3 (and the rest of the semester). For now, take them to be the way we give "properties" to objects, like how we can say "Socrates" (as an object) has both the property of being human, and also mortal.

#### Certain manipulations and properties about quantifiers

There is an interesting aspect about quantifiers we need two talk about: What happens if we have more than a few of them? Let's consider the set of all positive integers, i.e. the set that contains $1, 2, 3, \ldots$ and so on. We will use the $\leq$ symbol to mean "smaller than or equals to", and $\geq$ to mean "greater than or equals to". What if we wanted to write the following mathematically?

1. There exists an integer that is smaller than or equals to all integers.
2. It is not the case that there exists an integer that is greater than or equals to all integers.

Let's begin with the first one, this is a prime example in nesting quantifiers. That is to say, using more than one.

$$
	\exists x, \forall y \big( x \leq y \big)
$$

Very succinct right? Reading it back, here's how we should parse it:

> There exists an object that we will call $x$, fix this $x$. For this $x$, for all $y$, $x$ is less than or equals to $y$.

One thing to take note of here is that $x$ is chosen before considering all values of $y$. Do we believe this statement to be true? To prove that this statement is true, we need to pick a value for $x$. What should the value be? It should be $1$!

Let's look at the second statement.

$$
\neg \big( \exists x, \forall y (x \geq y) \big)
$$
Notice that we have surrounded the entire statement with a "$\neg$". This is done to say that we want the negation of the inner statement. What is the inner statement saying? It is saying "there exists an object that we will call $x$. Fix this $x$, for this $x$, for every value $y$, $x$ is greater than or equals to $y$". Since we want the opposite of that statement, we added the negation on the outside.

#### Alternating Quantifiers
The first question we might want to ask is: Do the order of the quantifiers matter? For example, for the first statement, what if we had instead written:

$$
\forall y, \exists x \big( x \leq y \big)
$$
Reading this back, this now says:

> For every possible value, call it $y$, we can find at least one $x$ for which $x$ is smaller than or equals to $y$.

Do they mean the same thing? The original is saying we can find a value that is smaller than or equals to all other values. The latter is saying that no matter the value we pick, we can always find something smaller than or equals to it. These do not mean the same thing!

#### Negating Quantifiers
Let's also take a look at what it means to negate a statement that has quantifiers in it. Here's the second statement again:

$$
\neg \big( \exists x, \forall y (x \geq y) \big)
$$

Can we think of a way to write this where we do not have a negation on the outside? We're trying to say "It is not the case that there is a single value that is greater than or equals to all values". Why is this the case? We can think of this statement equivalently in the following way:

> For every value $x$, it is not the case that $x$ is greater than or equal to all values.

Mathematically:

$$
 \forall x, \neg \big(\forall y (x \geq y) \big)
$$
Take a while sitting on this and reading it to convince yourself it makes sense.

We can go a little further, and say:

> For every value $x$, we can find a value $y$, for which is it not the case that $x$ is greater than or equals to $y$.

Mathematically:

$$
 \forall x, \forall y \big( \neg ( x \geq y) \big)
$$

Again, take a while to sit on this and convince yourself that they are the same.

In general: We can move a $\neg$ further to the right past a quantifer by changing it from a $\forall$ to a $\exists$, and vice versa.

So for example, all of the following are equivalent:

1. $\neg \big( \exists x, \forall y, \exists z (P(x, y, z)) \big)$
2. $\forall x, \neg \big(\forall y, \exists z (P(x, y, z)) \big)$
3. $\forall x, \exists y, \neg \big( \exists z (P(x, y, z)) \big)$
4. $\forall x, \exists y,  \forall z, \neg \big( (P(x, y, z)) \big)$

# Part 3: Proofs in First Order Logic

Okay! We are finally in place to start making **proofs**! Now that we know what the words and sentences look like, the next and final step in this unit is how we are to go about deducing statements that we want. For us to do this, we need to recognise the form a proof, what it is, what are steps that we can take in proofs. 

#### First example of a proof:
Let's re-visit the example we had just now:

1. $\forall x \left( human(x) \to mortal(x) \right)$ \[Premise 1]
2. $human(Socrates)$ \[Premise 2]
3. Therefore $mortal(Socrates)$ \[Conclusion, Derived from Premises 1, 2]

I understand it takes a little getting used to reading symbols, but the more you do it, the sooner you get used to it. The first feature of a proof are what we call the **premises**. In the above proof, lines $1$ and $2$ are **premises**. Think of **premises** as statements that we _assume to be true_. After all, we do believe every human is mortal, and we do believe the Socrates was a human.

What about line $3$? Line $3$ is the **conclusion** of the proof. This is the final statement that we wish to conclude. To be clear, **we are not assuming that Socrates is mortal, we want to be able to conclude it**. To do so, we must **deduce** line $3$ using lines $1$ and $2$. 

In order to do so, we will use rules of deductions. We will exhaustively list them out later. But for this current introductory example, we are using a rule called **universal modus ponens**.

It's a very fancy name, but what it means is that if you see any line that looks like:

$$
\forall x(P(x) \to Q(x))
$$

and you **also** see a line like:

$$
P(c)
$$

then the rule modus ponens allows you to **deduce** that $Q(c)$ is true in your proof.

Okay this is a little abstract, what does **universal modus ponens** mean in English? Let's take a step back and try to think about it. If we have a line that says:

$$
\forall x(P(x) \to Q(x))
$$
we are essentially saying "For every possible object $x$, if $x$ satisfies $P(x)$, then it also satisfies $Q(x)$." Furthermore, the line 

$$
P(c)
$$

is saying that $c$ is an object that satisfies predicate $P(\cdot)$. (Alternatively, that $P(x)$ is true when $x = c$).

So since we know $c$ satisfies $P(\cdot)$, and that anything that satisfies $P(\cdot)$ must also satisfy $Q(\cdot)$, we can happily conclude that "A-ha! $c$ satisfies $Q(\cdot)$ as well!".

Notice here that the rule doesn't care about what we said about humanity or mortality. As long as it matches the pattern, it will be allowed. That means we can also write something like this:

1. $cat(Tabby)$
2. $\forall x \left( cat(x) \to has\_paws(x) \right)$
3. Therefore $has\_paws(Tabby)$

The first line is saying that Tabby is a cat. The second line effectively is saying all cats have paws, and the last line is saying Tabby has paws.

So let's re-cap a little at this point what has gone on. Lines $1, 2$ are **premises** (notice we didn't prove lines 1 and 2, we are assuming they are true on good faith). Line $3$ is a **deduced line** using lines $1, 2$, and the deduction rule used **modus ponens**.

Now, very importantly, **what have we done here**? We have written a proof that effectively has **proven the following statement**:

> "Assuming that Tabby is a cat and assuming that all cats have paws, then we conclude that Tabby has paws"

Formally, we will write the **proven statement** in the following way:

$$
\bigg( cat(Tabby) \land \big(\forall x \left( cat(x) \to has\_paws(x) \right) \big)\bigg) \to has\_paws(Tabby)
$$

What is the above **proven statement**? The above statement says that if $cat(Tabby)$ is true, and $\big(\forall x \left( cat(x) \to has\_paws(x) \right) \big)$ is true, then $has\_paws(Tabby)$ is true. See how this matches what we have in quotes? Take some time to appreciate the similarities between what we have in English, and what we have written out here in the formula.

Okay, that was an example, to do more involved things, we need to first look at some rules of inference. In the later parts, we will show examples of proofs that we want to do. Focus on the following:

1. What the premises are
2. How we obtain the intermediate steps using rules of inferences
3. What is the conclusion

#### Correspondence between proofs and statements
Bear in mind that **very importantly, if we have given a proof that starts with premises $P_1, P_2, \ldots, P_n$, and we derive statement $C$ as our conclusion, then we have the following proven statement**.

> Assume $P_1 \land P_2 \land \ldots \land P_n$, then it follows that $C$.

Look at the example again the two things: (1) the proof that Tabby has paws, and also (2) the proven statement that we obtained **due to the proof**. Look at how it corresponds.

>[!An Aside]
> Take some time to appreciate that what we are doing is actually making formal, rigorous arguments using **first order logic**.
> 
> Why do we do this? The idea is that we want a systematic approach in telling us what is true and what is not. In some sense, in the future when we are concerned with whether our algorithms/programs are correct, whether we can apply our concurrency guarantees, whether our database schemas are doing what we want, we want something better than having an arbitrary human be the arbiter of truth.
> 
>  In other words, whether an algorithms works should not be based on gut feeling, or based on our subjective moods. Having an intuition and being convinced that something works is important, yes. But the tools that we are about to present to you are say that you may derive truth in a more objective manner.
## Allowable Rules of Deductions

In this section, we will show very short and simple proofs, each using more and more rules of inferences to list out all the rules you can use. Here's a few quick remarks before we talk about each rule in detail:

1. The reason we want to have these rules is that they try to mirror what we believe is intuitively true.
2. Rules 1 through 5 are a little more straightforward.
3. Rules 6 through 9 are more to do with quantifiers.

Try not to get lost in the weeds here, we will go through a short example demonstrating each deduction rule, and also explain what it means intuitively, before talking about the rule formally.  For rules 6 through 9, there will be a little more exposition.

#### Rule 0: Definition Unpacking
Throughout discrete math, we like giving common and important concepts names. Again, a formal way of saying $x$ is even is to write:

$$
\exists k \in \mathbb{Z} [2 \cdot k = x]
$$

Formally, we can say:

> **The predicate $even(x)$ is defined to be $\exists k \in \mathbb{Z} [2 \cdot k = x]$**.

It is hard to demonstrate this rule in isolation so we will see it being used later on in the subsequent rules.
#### Rule 1: Basic Algebra

Example usage:
>[!Theorem]
> Assuming $x + 5 = 12$, then $x = 7$.

>[!Proof]
> 1. Assume that $x + 5 = 12$.
> 2. Then $x = 12 - 5$ \[By Basic Algebra from line $1$]
> 3. Then $x = 75$ \[By Basic Algebra from line $2$]

Here, line $1$ is our premise. Line $3$ is our conclusion. And the justifications are laid out in square brackets. Basic algebra is something we are happy for you to use (for free)! You can think of line $2$ as an intermediate step. It is neither a premise nor a conclusion, but we can write line $2$ because it is a derivation from line $1$. Similarly, line $3$ is derived from line $2$.

One other thing to take note of is the theorem statement vs the proof. The statement starts with "Assuming "$x + 5 = 12$". This must be the very first line of our proof. Secondly, the proof ends with "then $x = 7$". This is the conclusion we must prove. So this must be the very last line of our proof. Every other intermediate line must be justified.

Don't worry too much about how much algebra you need to know. If you know how to add, multiply, divide, square root, exponentiate, and logarithms, that is all the algebra you need to know.
#### Rule 2: Specialisation
Example usage:
>[!Theorem]
> Assume ($x < 10 \land x > 0$), then $x < 10$.


>[!Proof]
> 1. Assume that ($x < 10 \land x > 0$).
> 2. Then $x < 10$. \[By Specialisation on line $1$]

Again, line $1$ is our premise, line $2$ is our conclusion. How did we derive our conclusion? We used the rule of **specialisation** on line $1$. What is specialisation? In English, it takes a statement like $p \land q$, and says that you are allowed to conclude $p$. Let's think about what it means. Intuitively, if you are convince that both $p$ and $q$ are both true. We should be able to say that $p$ is true.

>[!Rule: Specialisation]
> Given statement $p \land q$, we are able to derive statement $p$.
> Furthermore, given statement $p \land q$, we are able to derive statement $q$.


Remember: each line that is not a premise must be derived from previous lines.
#### Rule 3: Generalisation
Example usage:
>[!Theorem]
> Assume $x < 10$, then $x < 10 \lor x = 10$.

>[!Proof]
> 1. Assume that $x < 10$.
> 2. Then $x < 10 \lor x = 10$. \[By Generalisation on line $1$]

This looks a little different. Let's think about what this means intuitively in English: "If we are convinced that statement $p$ is true, then we are convinced that statement $p \lor q$ is true.".

>[!Rule: Generalisation]
> Given statement $p$, we are able to derive statement $p \lor q$.
> Furthermore, given statement $p$, we are able to derive statement $q \lor p$.

#### Rule 4: Modus Ponens
Example usage:

> [!Theorem]
> Assume that $(\text{it is raining} \to \text{I will bring an umbrella})$, and further assume $\text{it is raining}$. Therefore $\text{I will bring an umbrella}$.


 > [!Proof]
 >  1. Assume $(\text{it is raining} \to \text{I will bring an umbrella})$.
 >  2. Assume $\text{it is raining}$.
 >  3. Therefore $\text{I will bring an umbrella}$ \[By Modus Ponens on lines $1, 2$]

This example is a demonstration of a classic rule of inferences. It takes 2 lines:
1. If we believe in $p$, we must also believe $q$ is true.
2. We believe in $p$

And makes the following conclusion:
1. We believe in $q$.

>[!Rule: Modus Ponens]
> Given statements $p \to q$, and $p$, we are able to derive statement $q$.

#### Rule 5: Modus Tollens
To make things a little simpler in our proof system, and a little more flexibility: let's also think (intuitively first, before formally) about what else we could say. What if instead we were given the following?

1. If it is raining, then I will bring an umbrella.
2. It is not the case that I will bring an umbrella.

Can we say something about whether it is raining? Well we were promised if it was raining, we would have brought an umbrella. Considering how we are not bringing an umbrella, it cannot be raining. So we can actually also do the following:

> [!Theorem]
> Assume that $(\text{it is raining}) \to (\text{I will bring an umbrella})$, and further assume $\neg(\text{I will bring an umbrella})$. Therefore $\neg(\text{it is raining})$.

 > [!Proof]
 >  1. Assume $(\text{it is raining} \to \text{I will bring an umbrella})$.
 >  2. Assume $\neg(\text{I will bring an umbrella})$.
 >  3. Therefore $\neg(\text{it is raining})$ \[By Modus Tollens on lines $1, 2$]

In general, here is the rule:
>[!Rule: Modus Tollens]
> Given statements $p \to q$, and $\neg q$, we are able to derive statement $\neg p$.

#### Rule 6: Implication Introduction
So far, in the previous rules, we have been using implication statements in one way or another. What if we wanted to **create** implication statements? Here's an example statement we can try to prove:

> [!Theorem]
> $(p \land q) \to p$

Okay this might look a little intimidating. Let's read it back in English, what is it saying? The statement here is that "If we believe $p \land q$ is true, we believe $p$ is true". Hold on a minute, this looks very familiar! Doesn't this look like the Specialisation rule? Yes! Except now the statement has an implication $(\to)$ instead of "Assume $p \land q$, therefore $q$".

Here's the proof and how we use the deductive rule.

> [!Proof]
> 1. Assume $(p \land q)$.
> 	1.1 $p$ \[By Specialisation on line $1$].
> 2. $(p \land q) \to p$ \[By Implication Introduction on lines $1$, and $1.1$]

So what is going on here? 

1. On line $1$ we have made it very explicit that we are making an assumption that $p \land q$ is true. 
2. We derived line 1.1 using the Specialisation rule on line $1$.
3. We derived our concluding line $2$ by using the Implication Introduction rule on lines $1$ and $1.1$.

What's the idea? Intuitively, our proof system makes an assumption that $(p \land q)$ is true, so since we assumed it to be true, we can now start deriving other lines from it as well. In fact, line 1.1 is such a line. Line 1.1 is also the sub-conclusion from line 1. 

Since we assumed $(p \land q)$ and we concluded $p$ from it, the Implication Introduction rule **takes the assumption, and also the sub-conclusion, to create the final line**. In this case line $2$. It takes on the form $\text{assumption} \to \text{sub-conclusion}$. So in our example, we obtain line $(p \land q) \to p$.

In general, here is the rule:
>[!Rule: Implication Introduction]
> Assuming statement $a$, if statement $b$ is derived as a sub-conclusion, then the Implication Introduction rule derives statement $a \to b$.

#### Rules 7,8,9,10: (Existential/Universal) (Generalisation/Instantiation)
For the sake of exposition, it is a lot more natural to consider all these 4 rules together at the same time for this section.


Let's begin with a smaller example that demonstrates the use of existential instantiation. Let's see that in action by proving this theorem formally:

>[!Theorem]
> Assuming $\forall x \in \mathbb{Z}[x^2 \geq 0]$, then $(-5)^2 \geq 0$.

What is this theorem saying? It is saying that if we believe that any integer squared is non-negative, then  $-5$ squared is non-negative. How do we prove this? Let's see this in action:

>[!Proof]
> 1. Assume $\forall x \in \mathbb{Z}[x^2 \geq 0]$.
> 2. $-5 \in \mathbb{Z}$ \[Definition of Integers]
> 3. $(-5)^2 \geq 0$ \[Universal instantiation on line $1$, $2$].


What has happened here? Let's explain the idea of the proof in English. Line 1 is our premise, it is assuming that all integers are such that if you square them, they are non-negative. Line $2$ is bringing up the fact that $-5$ is an integer. And line $3$ is basically stating the following:

> Since all integers are such that if you square them, they are non-negative. It is also true for any specific integer. We are convinced on line $2$ that $-5$ is an integer. Therefore, we are convinced by combining lines $1$ and $2$ that $(-5)^2$ is also non-negative.

For the final proof of this section, let's think about how to **prove the following statement**:

>[!Theorem]
> $\forall x \in \mathbb{Z} [ even(x) \to even(x + 2) ]$.

Let us read the statement we wish to prove in English, it is basically saying, "Take any integer $x$, if it is even, then $x + 2$ is even as well". Intuitive right? Let's see how a mathematician does it.

Why is this true? Here's the high level idea, we know that if $x$ is an even integer, we can re-write $x$ as $2\cdot k$. Then we also know that $x + 2 = 2\cdot k + 2 = 2\cdot (k + 1)$. Since $k$ is an integer, $k+1$ is also an integer. So that means we can write $x + 2$ can be written as $2 \cdot s$ where $s$ is **some** integer.

Okay that's the idea, but how do we do it formally? Again, we will want to use some rules to help us make the deduction. Let's see them in action:

> [!Proof]
> 1. Let $x$ be arbitrarily chosen from $\mathbb{Z}$. 
> 	1.1 Assume that $even(x)$.
> 	1.2 $\exists k \in \mathbb{Z}[x = 2\cdot k]$ \[Unpacking definition of $even(x)$]
> 	1.3 Let $t \in \mathbb{Z}$ be such that $x = 2\cdot t$ \[Existential Instantiation on line $1.2$]
> 	 1.4 $x + 2 = 2 \cdot t + 2$ \[Basic Algebra]
> 	 1.5 $x + 2 = 2 \cdot (t + 1)$ \[Basic Algebra]
> 	 1.6 Since $t \in \mathbb{Z}$, $t + 1 \in \mathbb{Z}$ \[Basic Algebra]
> 	 1.7 $\exists z \in \mathbb{Z} [x + 2 = 2 \cdot z]$ \[Existential Generalisation on line $1.5$, $1.6$]
> 	 1.8 $even(x + 2)$ \[Unpacking definition of $even(x + 2)$]
> 	 1.9 $even(x) \to even(x + 2)$ \[Implication Introduction on lines $1.1$, and $1.8$]
> 2. $\forall x \in \mathbb{Z}[even(x) \to even(x + 2)]$. \[Universal Generalisation on lines $1$, and $1.9$]

Okay! This is a lot of text, let's go through this slowly, it re-uses some old rules you were already shown, and it uses $3$ new rules here. What is going on?

The proof starts off by taking $x$ to be an integer value (i.e. from $\mathbb{Z}$). So the subsequent lines (1.1 through 1.9) are allowed to treat $x$ as any arbitrarily chosen integer from $\mathbb{Z}$. It may be $5$, it may be $47142$, who knows. Then line 1.1 assumes that we consider only values $x$ that are even. This means that if we were given a value like $5$ for $x$, our proof is not applicable anymore. But that's okay! We don't want to say anything about odd numbers anyway.

Next up, we unpack the definition of $even(x)$. Remember that an integer is even if we can write it as $2\cdot k$ for some value $k \in \mathbb{Z}$. Line $1.2$ is just reminding us of the definition of being an even value.

What about line 1.3? This is the first new rule we have encountered. Intuitively in English, what is being done here is the following:

> On line 1.2 we are saying "$x$ is equals to $2$ times an integer."
> Therefore, we are able to deduce line 1.3 which states "Let call that integer $t$.".

This might feel pedantic, but imagine how in English there is a subtle difference between:

> "Something is cold" vs "Call the cold thing $x$".

The former sentence has not given the "cold thing" a name. The latter sentence has given it a name. Then deduction rule is basically trying to say "Since we know a cold thing exists, we can give it a name. Let's call it $x$". Similarly, in our proof above, the deduction rule is basically trying to say "Since we know $x$ is _some_ value times $2$, we can give such a value a name, call it $t$." In doing so, notice that the new line has effectively **removed** the $\exists$ symbol.

Let's keep going. Now that we've given that value a name $t$, we can start referring to it, and manipulating it. So lines $1.4$ through $1.6$ are all just basic algebra. 

What about line $1.7$? What is it doing? In some sense it is actually doing the opposite of line $1.3$.

> On line $1.5$ we said that $x + 2 = 2(t + 1)$. On line $1.6$ argue that $t + 1$ is also in $\mathbb{Z}$. Since we know a specific value $z$ from $\mathbb{Z}$ for which $x + 2 = 2\cdot z$, we know __some__ value from $\mathbb{Z}$ exists for which $x + 2 = 2 \cdot z$. Therefore, $\exists z \in \mathbb{Z} [x + 2 = 2\cdot z]$.

Again, this might feel weird but it's basically doing the reverse of what we had explained earlier:

> "We know ice is a cold thing" vs "Exists something that is cold".

The deduction rule here basically takes the former sentence and deduces the latter.

Okay! Let's keep chugging on. $1.8$ is more definition unpacking, and line $1.9$ re-uses the previous deduction rule of creating an implication statement.

Finally, what's going on on line $2$? It's saying the following:

> Since we took $x$ arbitrarily from $\mathbb{Z}$, and we were able to create the sub-conclusion $even(x) \to even(x + 2)$, we are able to write $\forall x \in \mathbb{Z}[even(x) \to even(x + 2)$.

And if you read back the concluding line, it makes sense! It's saying:

> For every possible value taken from $\mathbb{Z}$ that we shall call $x$, if $x$ is even, then $x + 2$ is even.

Why is this reasonable? We took $x$ arbitrarily. What about the assumption we made? We used the implication introduction rule to turn that back into $even(x) \to even(x + 2)$, so you could technically say we made no assumptions about $x$ and did take it arbitrarily.


TODO:
1. Add the formal inference rule boxes for the quantifier related rules.
### Proof Strategies
1. Direct Proof
2. Proof by contraposition
3. Proof by contradiction
4. Proof by cases
5. 


