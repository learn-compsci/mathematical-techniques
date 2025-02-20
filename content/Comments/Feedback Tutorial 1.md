---
title: "Feedback: Tutorial 1"
---
This page serves at the overall feedback for tutorial 1 submissions. Thing of these as feedback that summarises important points in response to what we've seen a lot of submissions do.

# Circularity in Proofs:

We have released a write-up with examples in detail on [[More Proof Examples - And Demystifying Proofs#Example 3.2|this page about this concept]] be sure to check it out. But in short, when you used an assumption like some statement $p$ (maybe implicitly) to prove the statement $p$ itself, you've made a circular argument. What has happened here is that instead of proving the statement itself, you've first had to assume it is true.

Here's a layman example:

1. Assume that cats can fly.
2. Then cats can fly.

Of course you could conclude that dogs can fly, because you already assumed it. This is however, not a proof that dogs can fly.

## Almost Circular Reasoning:
In a lot of submissions, we noted that quite a lot of submissions arrived at the line:

> $2(k - j) = 1$

And as justification for why this is a contradiction, used the fact that:

> "But this means that $1$ is even, but $1$ is an odd number. Contradiction."

Let's think about what the line above was basically using. It was implicitly using the fact that $1$ a number that is odd **and** not even. This is very close to the original statement we were setting out to prove: that there does not exists a number that is both even and odd at the same time.

In light of this, we think this a good opportunity to mention this potential (and very common) pitfall in proofs. Try to avoid circular reasoning. Although in the future we will be providing proof tasks that probably have far less potential for circular reasoning.


# Logical Equivalences

Most submissions could work out the truth tables to show the equivalence of statements like $\neg(p \land q)$ and $\neg p \lor \neg q$. Well done!

Though when it came to translating and considering statements like "it is not raining and not cold", many submissions considered it to be equivalent to "It is not the case that it is both raining and cold" instead of "It is not the case that it is raining or cold".

Please take note about how to view statements as propositional formulae and from then on using the equivalences that we mentioned.

# Negations

We noted a few submissions that were a little careless when it came to negating quantifiers. For example, some submissions considered the following:

$$
\neg(\forall x \in A, \exists y \in B [P(x, y)])
$$

to be equivalent to:

$$
\forall x \in A\  \neg(\exists y \in B [P(x, y)])
$$

which is not quite right.

Here's an example.  Let's use $P$ to denote the set of all people, and $F$ to be the set of all food. And $likes(x, y)$ to say that $x$ likes $y$.

Then:

$$
\neg(\forall x \in P, \exists y \in F [likes(x, y)])
$$

means:

> It is not true that "every person has a food that they like"

If you think about it, in the first statement, it could be the case that almost everyone has a food that they like, except one specific person, maybe Samantha doesn't like any food at all. The first statement would still be true.

Whereas the second statement:

$$
\forall x \in P\ \neg(\exists y \in F [likes(x, y)])
$$

says that:

> Every person is such that: is it not the case that there is a food that they like.

In other words, now no one likes food at all! This is a very different statement.


# Proof Rules
Many have asked during tutorial 1 in-person about whether or not they need to state the proof rules, and while we do not plan on making it mandatory, our general feedback and view of quite a few of the submitted proofs right now is that there are quite a few ad hoc steps and this is sometimes causing issues and faulty proofs.

> How do we know if our proof is correct and acceptable?

This is hard to say. **If** a proof given to us follows the system exactly, **then** we know for sure it is acceptable.

On the other hand, this means that when we are given a proof that does not, we need to manually appraise it for potential issues and whether we are convinced that the prover has conveyed the right idea.

We understand that the proofs look long and tedious, and certain steps can be skipped, we are ok with this. But it is also very hard for us to say up front what is allowed and what is not, when a proposed proof doesn't follow the system.

Think of it this way: If we had to look at some computer code for a program where the code did not follow the syntax and was not clear on what functions it used, what operations it was performing, and we were asked:

> How does this computer program behave? Does the idea work?

We can't give a straight answer because now it depends. And that's why we can't give a better, more objective guarantee than:

> If you followed the system, the proof is correct


# The positives:
Let us also mention some of the positives we the teaching team were very happy to see:

1. Almost everyone did the truth tables correctly. Yay!
2. A lot of submissions did faithfully negate quantified statements, and also the contrapositives. Nice!
3. While most proofs did not follow the system exactly, there were still quite a number of proofs whose idea was correct, and of an acceptable state for us. We were very happy to see that people could get the idea, and write a working proof by contradiction. This is by no means an easy task. Well done!
4. Quite a lot of people could interpret the nested quantified statements, which is a tall order for most newcomers to this concept. This usually takes some time to wrap your head around, and a little tedious. So well done for picking it up!

# One interesting aspect: The definition of $Above(x, y)$

I'd like to end one a very interesting aspect for discussion. We can talk about this philosophically as well on Canvas if any of you are interested. 

We noticed that there was a difference in how people interpreted $Above(x, y)$. Some people took it to mean "it has to be on the same column", whereas a few others took it to mean "it has to be any row above, not necessarily the same column", and some were unsure whether "it can be on the same row to be considered above". Officially, when we were grading we understood that there could be multiple interpretations so our official solutions might have different from your interpretation so please do not take that to mean that your answer is wrong.

Did you notice: The moment we do not have a mathematical definition for $Above(x, y)$ in the form of a first order logic statement, things were again, left to interpretation for each of us? And there were quite a few interpretations which led to different answers. This is precisely the ambiguity that we aim to avoid when we write everything mathematical statements!

