## Proof Technique: Goal Statements vs. Steps in Proofs
Okay we've seen quite a few proofs and perhaps at some point you might have started asking yourself "ok but how do we know what to do in each step? I don't even know how to begin the proof."

Okay, there are a few general features of proofs that I can start showing you. These might be a little helpful. (Full disclaimer, this stuff does take a while to get used to. Don't rush it, but I will encourage you to try out different proofs through either the extra questions or the tutorials. Just like how best way to learn programming is to write them yourself. The best way to learn proofs is to do them yourself, and have our tutors vet them for you.)
### A certain way to look at proofs:
Let's re-visit the proofs we did in the previous sections, and I want to show you certain techniques I use to figure out what I need to do.

There are a few key aspects to this:
1. Knowing what the goal statement is.
2. Based on what the goal statement is, what steps need to be made in the proof.
3. How do steps change what the goal statement is.

**To be clear: knowing these alone will not create the entire proof for you**. But it helps keep you focused on what you need to do next.

Okay, let me use an initial example to show you what I mean.

Let's say we had the following statement again:

>[!Theorem]
> $\forall x \in \mathbb{Z}[ even(x) \to even(x^2) ]$, where $even(x) \equiv \exists k \in \mathbb{Z}[x = 2k]$.

Reading this back, it's saying that "For every integer $x$, if $x$ is even, then $x^2$ is even. And a number $x$ is considered 'even' means we can find an integer $k$ such that $x = 2k$.".

Right now at the very beginning, our goal statement, is really just $\forall x \in \mathbb{Z}[ even(x) \to even(x^2) ]$. This is the statement we want to prove. We haven't written any lines of proof yet. Also, we on the side, we have the definition that $even(x) \equiv \exists k \in \mathbb{Z}[x = 2k]$.

So think of it this way, at the very beginning, 