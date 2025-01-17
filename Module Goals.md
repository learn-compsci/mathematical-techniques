---
title: Module Goals
---
This module aims to:

1. The ability to perform proofs, at both a rigorous, foundational level, and proofs at a higher, more intuitive level.
2. Equip you with the mathematical tools needed for various fields in computer science, including
	a. Data Structures and Algorithms
	b. The foundational math behind sets, and relations (useful for Databases)
	c. Some of the foundational math behind Machine Learning and AI

To accomplish this, the module covers the following topics:
1. Propositional logic, first order logic
2. Set theory and relations
3. Induction, Recurrences, and Algorithmic Analysis
4. Combinatorics, Graphs and Trees
5. Basic Probability

# A note on proofs, and discrete mathematics
Doing proofs, and understanding mathematical logic may be a radically novel concept to most people. It is also a little difficult to explain to newcomers to computer science why this concept is so useful. There are a few reasons. But here is the biggest one (in my opinion):

### It is the lingua franca of expressing ideas
In computer science, very often the objects and concepts we deal with are mathematical in nature. Knowing how to understand and speak the same language as other computer scientists is helpful. This way, you can pick up newer concepts yourself when you inevitably have to Google something. 

For example, here's an example provable statement:
> Let $M$ be the random variable denoting the number of mistakes of the learner, and $B$ be the the number of mistakes of the best expert, and $N$ be the number of rounds, then:
> $$\mathbb{E}[M] \in O(B) + O(\ln(N))$$
> - An excerpt adapted from [[https://en.wikipedia.org/wiki/Multiplicative_weight_update_method#Randomized_weighted_majority_algorithm|this wiki page on a well-known machine learning algorithm]].

Learning how be able to read this statement, as well as what these symbols mean, is an end-goal of this module.

It also is very important in getting you to figure out how to structure your thoughts and approaches to the rest of the topics in computer science.
## How one should do proofs, and how this module aims to teach it
There are roughly two ways that computer scientists do proofs: rigorously, and informally. This module will do both. Why?

At times when we wish to be careful, and make sure we are not making errors, we will want to rely on systematic method to help derive our truths and statements for us. Computer scientists are trained on this also because it is good to have the option to be able to do it, rather than not.

On the other hand, rigorous proofs are also tedious (as you will see), and it is sometimes very cumbersome to express basic, intuitive facts that we would be happy to otherwise take for granted. However, once one has gotten an idea of how to be rigorous, steps may eventually be skipped and omitted, and we can appreciate higher level ideas and approaches. You will notice in the semester that while it is easy to rigorously argue about sets and relations, it is much harder to do so for the remaining topics in the second half of this module. There, we will switch over back to English, but with a newfound sense of rigour that we have obtained from the first half of the module. 

You can draw a similarity between rigorous proving vs "higher-level proving" like between C and Python. There are reasons why one should, and why one ought not to use them. C has amazing compiler optimisations and allows programmers to manage their own memory for themselves. Many, if not most, performant programs are written in C or C-like languages. However, it is programming at such a low level where many details need to be filled in, almost sometimes to a point of tedium. Python on the other hand, is a lot more convenient. One does not need to worry about aspects like memory management, pointers, addresses, and so on. Perhaps we do not need to worry about performance, and perhaps we as the programmer would prefer to quickly whip up a prototype. In which case, Python would be preferable. The right tool, for the right task.

I end this section with a quote from [Terrence Tao's blog post, titled There’s more to mathematics than rigour and proofs](https://terrytao.wordpress.com/career-advice/theres-more-to-mathematics-than-rigour-and-proofs/):

> One can roughly divide mathematical education into three stages:
> 
> 1. The “pre-rigorous” stage, in which mathematics is taught in an informal, intuitive manner, based on examples, fuzzy notions, and hand-waving. (For instance, calculus is usually first introduced in terms of slopes, areas, rates of change, and so forth.) The emphasis is more on computation than on theory. This stage generally lasts until the early undergraduate years.
> 2. The “rigorous” stage, in which one is now taught that in order to do maths “properly”, one needs to work and think in a much more precise and formal manner (e.g. re-doing calculus by using epsilons and deltas all over the place). The emphasis is now primarily on theory; and one is expected to be able to comfortably manipulate abstract mathematical objects without focusing too much on what such objects actually “mean”. This stage usually occupies the later undergraduate and early graduate years.
> 3. The “post-rigorous” stage, in which one has grown comfortable with all the rigorous foundations of one’s chosen field, and is now ready to revisit and refine one’s pre-rigorous intuition on the subject, but this time with the intuition solidly buttressed by rigorous theory. (For instance, in this stage one would be able to quickly and accurately perform computations in vector calculus by using analogies with scalar calculus, or informal and semi-rigorous use of infinitesimals, big-O notation, and so forth, and be able to convert all such calculations into a rigorous argument whenever required.) The emphasis is now on applications, intuition, and the “big picture”. This stage usually occupies the late graduate years and beyond.
>
> The transition from the first stage to the second is well known to be rather traumatic, with the dreaded “proof-type questions” being the bane of many a maths undergraduate. (See also “[There’s more to maths than grades and exams and methods](https://terrytao.wordpress.com/career-advice/theres-more-to-mathematics-than-grades-and-exams-and-methods/)“.) But the transition from the second to the third is equally important, and should not be forgotten.

# Will I ever use this in my job?
This is the trickiest question to answer, because the short answer is almost no. I would be willing to make an uneducated guess that almost 90% of working software engineers do not actually use proofs for their jobs. Most of them do not need to understand logic. Most of them do not need to prove their programs are correct. And this might be a reason why one might choose to ignore half of this module's content. (Noting that knowing graphs, combinatorics and probability are still useful for a lot of engineers)

The longer answer is that not knowing the concepts (especially the first half) will almost definitely be to your detriment for the higher level topics. Especially algorithms, databases, and so on. In terms of the long term benefits when it comes to picking up other concepts in computer science, this is where it all begins.