---
hidden: "true"
---
## Question 4

The **contrapositive** of the statement $p\rightarrow q$ is $\neg q\rightarrow \neg p$. Draw a truth table to verify that the statements are logically equivalent.

>[!Solutions]-
> |   $p$   |   $q$   | $\neg q$ | $\neg p$ | $p \rightarrow q$ | $\neg q \rightarrow \neg p$ |
| :-----: | :-----: | :------: | :------: | :---------------: | :-------------------------: |
| $true$  | $true$  | $false$  | $false$  |      $true$       |           $true$            |
| $true$  | $false$ |  $true$  | $false$  |      $false$      |           $false$          |
| $false$ | $true$  | $false$  |  $true$  |      $true$       |           $true$            |
| $false$ | $false$ |  $true$  |  $true$  |      $true$       |           $true$            |

Since the truth values of the columns $p \rightarrow q$ and $\neg q \rightarrow \neg p$ are the same in all four rows, the two statements are logically equivalent.

## Question 6

Given the sets $A = \{0,1,4\}$ and $B = \{-2,-1,0,1,2\}$, determine which of the following statements are true.

1. $\exists a \in A \: (a^{2} \in B)$
2. $\forall a \in A \: (a^{2} \in B)$
3. $\forall b \in B, \exists a \in A \: (a = b^{2})$
4. $\exists a \in A, \forall b \in B \: (a = b^{2})$

**Solution:**
1. **True**, since we can find an $a \in A$ such that $a^{2}$ is in $B$. That value of $a$ could be $0$ or $1$, since $0^{2} = 0 \in B$ and $1^{2} = 1 \in B$ as well.

2. **False**, since we can find an $a \in A$ and yet $a^{2}$ is **not** in $B$. That value of $a$ is $4$, since $4^{2} = 16$, but $16$ is not in $B$.

3. **True**, since for every single element $b$ in $B$, we can find an $a \in A$ such that $a = b^{2}$. 
	- If $b = -2$ or $2$, then $b^{2} = 4$, which is in $A$. 
	- If $b = -1$ or $1$, then $b^{2} = 1$, which is in $A$.
	- If $b = 0$, then $b^{2} = 0$, which is in $A$.

4. **False**, since we are unable to find a single element of $A$ that is simultaneously the square of any element in $B$. 
	- If $a = 0$, then taking $b = 1 \in B$, we find that $a = 0 \neq 1 = b^{2}$.
	- If $a = 1$, then taking $b = 0 \in B$, we find that $a = 1 \neq 0 = b^{2}$.
	- If $a = 4$, then taking $b = -1 \in B$, we find that $a = 4 \neq 1 = b^{2}$.