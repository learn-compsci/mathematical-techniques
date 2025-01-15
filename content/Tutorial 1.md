---
title: "Tutorial 1: Propositions, Predicates, First Order Logic, Proofs"
hidden: "true"
---
# Overview
This tutorial gives practice questions to be discussed during the relevant tutorial in person. This particular corresponds to [[Unit 1]]. It is recommended to either watch the lectures or read the notes before attempting the tutorial sheet.

Questions 1 through 3 are related to **propositional logic**. Questions 4 through 5 are related to first order logic. Questions 6 and 7 are related to proofs. 

After week 2, you should be able to attempt questions 1 through 5. After week 4, you should be able to attempt questions 6 and 7.


## Question: DeMorgan's Laws
### Part a: Equivalence
Draw two truth tables to verify that:

1. $\neg (p \lor q)$ is logically equivalent to $\neg p \land \neg q$.
2. $\neg (p \land q)$ is logically equivalent to $\neg p \lor \neg q$.

These two equivalences (known as **De Morgan's Laws**) are among some of the most useful in discrete mathematics. 

|   $p$   |   $q$   | $p \lor q$ | $\neg p$ | $\neg q$ | $\neg (p \lor q)$ | $\neg p \land \neg q$ |
| :-----: | :-----: | :--------: | :------: | :------: | :---------------: | :-------------------: |
| $true$  | $true$  |            |          |          |                   |                       |
| $true$  | $false$ |            |          |          |                   |                       |
| $false$ | $true$  |            |          |          |                   |                       |
| $false$ | $false$ |            |          |          |                   |                       |

|   $p$   |   $q$   | $p \land q$ | $\neg p$ | $\neg q$ | $\neg (p \land q)$ | $\neg p \lor \neg q$ |
| :-----: | :-----: | :---------: | :------: | :------: | :----------------: | :------------------: |
| $true$  | $true$  |             |          |          |                    |                      |
| $true$  | $false$ |             |          |          |                    |                      |
| $false$ | $true$  |             |          |          |                    |                      |
| $false$ | $false$ |             |          |          |                    |                      |

### Part b: Translating Human Language to Logic
To see how these equivalences may be used, let $p$ be the statement "It is raining" and let $q$ be the statement "It is cold". Match each of the following statements with its logically equivalent; you might rewrite each statement using $p$ and $q$ to assist you.

1. It is not the case that it is raining or cold.
2. It is not raining or it is not cold.
3. It is not raining and it is not cold. 
4. It is not the case that it is both raining and cold.

Answer template: <br>
*Statement ___ is logically equivalent to statement ___ .*
*Statement ___ is logically equivalent to statement ___ .*





