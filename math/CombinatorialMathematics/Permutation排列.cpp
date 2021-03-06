///排列
/*排列: 从集合A={$a_1, a_2, \cdots ,a_n$}的n个元素中取r个按照一定的次序排列起来, 称为集合A的r-排列.
	记其排列数: @$$	P_n^r = \left\{	\begin{array}{l l}
			0, &n<r\\
			1, &n \geq r = 0\\
			n(n-1) \cdots (n-r+1)=\displaystyle \frac{n!}{(n-r)!},&r \leq n
			\end{array} \right.	$$@
	推论: 	当$	n \geq r \geq 2	$时, 有$P_n^r = nP_{n-1}^{r-1}$
			当$	n \geq r \geq 2 $是, 有$P_n^r = rP_{n-1}^{r-1} + P_{n-1}^{r}$

	圆排列: 从集合A={$a_1, a_2, \cdots, a_n$}的n个元素中取出r个元素按照某种顺序排成一个圆圈, 称这样的排列为圆排列.
	集合A中n个元素的r圆排列的个数为: $\displaystyle \frac{P_n^r}{r} = \frac{n!}{r(n-r)!}$.

	重排列: 从重集B={$k_1 \cdot b_1, k_2 \cdot b_2, \cdots , k_n \cdot b_n$}中选取r个元素按照一定的顺序排列起来, 称这种r-排列为重排列.
	重集B={$\infty \cdot b_1, \infty \cdot b_2, \cdots ,\infty \cdot b_n$}的r-排列的个数为$n^r$.
	重集B={$n_1 \cdot b_1, n_2 \cdot b_2, \cdots , n_k \cdot b_k$}的全排列的个数为@$$	\frac{n!}{n_1! \cdot n_2! \cdots n_k!}, n = \sum_{i=1}^{k}{n_i} $$@
	定理: n个具有标号$1, 2, \cdots, n$的顶点的树的数目是$n^{n-2}$.

	错排: $\{1,2,\cdots ,n\}$的全排列, 使得所有的i都有$a_i \neq i$, $a_1a_2\cdots a_n$是其的一个排列
	错排数@$$D_n = n!(1 - \frac{1}{1!} + \frac{1}{2!} - \frac{1}{3!} + \cdots + (-1)^n\frac{1}{n!})$$@
	递归关系式:@$$ \left\{ \begin{array}{l l} D_n = (n-1)(D_{n-1} + D_{n-2}),&n > 2\\D_0 = 1, D_1 = 0  \end{array} \right.$$@
	性质:@$$\lim_{n\to \infty}{\frac{D_n}{n!}} = e^{-1}$$@
	前17个错排值
	@\begin{tabular}{c | c c c c c c} \hline
	n & 0 & 1 & 2 & 3 & 4 & 5\\
	$D_n$& 1 & 0 & 1 & 2 & 9 & 44\\ \hline
	n &6 &7 &8 &9 &10 & 11\\
	$D_n$ &265 &1845  &14833 &133496 &1334961 &14684570\\ \hline
	n &12 &13 &14 &15 &16 &17 \\
	$D_n$ &176214841 &2290792932  &32071101049 &481066515734 &7697064251745 &130850092279664 \\ \hline
	\end{tabular}@

相对位置上有限制的排列的问题:
	求集合$\{1, 2, 3, \cdots , n\}$的不允许出现12,23,34, ... , (n-1)n的全排列数为
	@$$Q_n = n! - C_{n-1}^{1}(n-1)! + C_{n-1}^{2}(n-2)! - \cdots + (-1)^{n-1}C_{n-1}^{n-1}\cdot 1!$$@
	当$n \geq 2 $时, 有$ Q_n = D_n + D_{n-1} $
	求集合$ \{1,2,3, \cdots ,n\}$的圆排列中不出现$12, 23, 34, \cdots , (n-1)n, n1$的圆排列个数为:
	@$$	(n-1)! - C_n^1 (n-2)! + \cdots + (-1)^{n-1}C_n^{n-1}0! + (-1)^nC_n^n\cdot 1	$$@

一般限制的排列:
	棋盘: 设n是一个正整数, $n\times n$的格子去掉某些格后剩下的部分称为棋盘（可能不去掉）
	棋子问题: 在给定棋盘C中放入k个无区别的棋子, 要求每个棋子只能放一格, 且各子不同行不同列,
			求不同的放法数$ r_k(C) $
	棋子多项式: 给定棋盘C, 令$r_0(C) = 1$, n为C的格子数,则称@$$R(C) = \sum_{k=0}^{n}{r_k(C)x^k}	$$@为棋盘C的棋子多项式
	定理1: 给定棋盘C, 指定C中某格A, 令$C_i$为C中删去A所在列与行所剩的棋盘, $C_e$为C中删去格A所剩的棋盘, 则
	@$$ R(C) = xR(C_i) + R(C_e)	$$@
	设$C_1$和$C_2$是两个棋盘, 若$C_1$的所有格都不与$C_2$的所有格同行同列, 则称两个棋盘是独立的.
	定理2: 若棋盘C可分解为两个独立的棋盘$C_1$和$C_2$, 则@$$R(C) = R(C_1)R(C_2)	$$@
	n元有禁位的排列问题: 求集合$\{1,2,\cdots ,n\}$的所有满足$i(i=1,2,\cdots ,n)$不排在某些已知位的全排列数.
	n元有禁位的排列数为@$$ n! - r_1(n-1)! + r_2(n-2)! - \cdots + (-1)^nr_n	$$@其中$r_i$为将i个棋子放入禁区棋盘的方式数,$i=1, 2, \cdots, n$
*/
