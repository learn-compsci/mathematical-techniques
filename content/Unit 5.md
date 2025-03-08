---
title: "Unit 5: Algorithmic Analysis, Big Oh Terminology"
---
# Overview

In this unit, we'll be giving big motivations for [[Unit 4]] by doing 2 things:

1. Showing Big-Oh, Omega, Theta terminology. (Asymptotic Notation)
2. Bounding recurrences and general functions.
3. Showing how induction is used in the context of computer science.

Think of this as a big culmination of the reason we learned logic, proofs, induction, and logical statements. After this point, we will be focusing on a different branch of topics.

# Asymptotic Notation

Let's begin with an example. Let's say that we wrote this python program that just counts how many even numbers there are.

```python
def count_even(arr):
	count = 0
	for x in arr:
		if x % 2 == 0:
			count += 1
	return count
```

How long does this program take?

You could perhaps plot a graph, where the x-axis is the size of the array. And the y-axis is how long it takes for this program to run. We could also write similar C++ and maybe even Java code that all does something like this.

And let's pretend that we ran some experiments, and plotted some graphs to find out how long they take. Then maybe we'd get something like this:

![[example-plot.svg]]

Notice they all kind of look like straight lines. Like linear functions. Why? Because intuitively, no matter the programming language the 3 of them would be following the same idea: Start from the first item, go through each item until the last.