//1. 格雷码: (相邻码之间二进制只有一位不同), 构造方法: $a_i = i \ xor \ (i>>1)(a_i$为求第i个格雷码)
/*2. 多边形数: 可以排成正多边形的整数
	第n个s边形数的公式是: $\frac{n[(s-2)n - (s-4)]}{2}$
	费马多边形定理:每一个正整数最多可以表示成n个n-边形数之和
*/
//3. 四平方和定理: 每个正整数均可表示为4个整数的平方和. 它是费马多边形数定理和华林问题的特例.
//4. 即对任意奇素数 p, 同余方程$x^2+y^2+1 \equiv 0\pmod p $必有一组整数解x, y满足$0 \leq x < \frac{p}{2},0 \leq y < \frac{p}{2}$
///勾股数
/*
勾股数: 对正整数a, b, c, 如果有$a^2 + b^2 = c^2$, 称(a, b, c)为勾股数
性质: a, b中一个为奇数, 一个为偶数, c一定为奇数.
本原勾股数: 满足$\gcd{(a, b,c)} = 1$的勾股数
本原勾股数定理: 如果对奇数$s > t \geq 1$, 且$\gcd(s,t)=1$, 则有: $a = s \times t, b = \frac{s^2 - t^2}{2}, c = \frac{s^2 + t^2}{2}$, (a, b, c)是本原勾股数
*/
/*数组映射循环同构
	对于一个数组, 我们假设不关心它的每个数值得大小, 只关心它们是否相同, 而且它是循环的, 即从任意位置都可以看做是数组的起点. You are given a set of N vectors, each vector consists of K integers. Vector X is equivalent to Y (denoted $X \equiv Y$). if there exist a bijection $f : Z \to Z$ and an integer r, such that X[i] = f(Y [(i + r) mod K]) for each i in the range [0..K − 1]. For example, $(1, 2, 2, 3) \equiv (22, 3, 4, 22)$, with r = 2 and f(22) = 2, f(3) = 3 and f(4) = 1. But (22, 3, 22, 4) is not equivalent to (1, 2, 2, 3).
	我们将对于每个位置, 我们找出下一个相同数字的位置, 用它们的位置差表示该数组, 然后用最小表示法, 即可唯一的表示出该等价关系.
	例: 对(22, 3, 4, 22), 用位置差代替该数字, 得: (3, 4, 4, 1), 最小表示法得: (1, 3, 4, 4)这样所有等价的数组有且仅有这么一种表示方法.
*/

/*关于浮点运算
1. 精度问题: 精度相差过大的运算会带来较大的精度误差
2. 比较: 不能直接比较, 用EPS修正精度误差
3. 越界: 在sqrt(), asin(), acos()等处注意有精度误差带来的越界, 如a = 0, 但是可能表示为-1e-12, 那样sqrt, asin, acos等会RE, $a = 1$时, asin, acos也可能出错.
4. 四舍五入: 三种常见的方法:
	printf("%.3lf”, a);  //保留a的三位小数, 按照第四位四舍五入
	(int)a;  //将a靠进0取整
	ceil(a); floor(a);   //顾名思义, 向上取证, 向下取整. 需要注意的是, 这两个函数都返回double, 而非int
	由于精度误差, 可能四舍五入后与正确答案有差异. 如:  题目要求输出保留两位小数. 正确答案的精确值是0.005, 按理应该输出0.01, 但你的结果可能是0.005000000001(恭喜), 也有可能是0.004999999999(悲剧), 如果按照printf("%.2lf”, a)输出, 那你的遭遇将和括号里的字相同.
	解决办法是, 如果a为正, 则输出a+eps, 否则输出a-eps
5. 输出 -0.000: 解决: 先判断最后结果是否为0, 如果是0, 直接输出0.000.
6. 关于set<double>: 由于精度误差, 本来相等的两个数判为不等; 解决办法: 将double封装, 然后重载小于符:
	bool operator < (const Date &b) const {return val < d.val - EPS;}
7. EPS的取值: 选取适合的EPS值, 一般取EPS = 1e-8
8. 容易产生较大浮点误差的函数有asin, acos. 欢迎尽量使用atan2().
9. 尽量不使用浮点数: 如果数据明确说明是整数, 而且范围不大的话, 使用int或者long long代替double都是极佳选择, 这样就不存在浮点误差了.
10. 当相加减乘的两个浮点数相差过大时, 可以略去这些计算, 从而减少计算量, 甚至降低复杂度. 反之, 为避免由此带来的精度误差, 尽量使相运算的两个浮点数的相差尽量小.
11. 在对浮点数进行二分查找, 三分查找时, 固定查找次数, 而不是比较两个左右区间. 一般查找次数为50, 保险为70~80, 也可以为100
*/
int sgn(double a) {return a < -EPS ? -1 : a < EPS ? 0 : 1;}
int mysqrt(double a) {return sqrt(max(0.0, a));}
//注意改精度
char buf[100];
void Out(double a)
{
    sprintf(buf, "%.2f", a);
    if(strcmp(buf, "-0.00") == 0) printf("0.00");
    else printf("%s", buf);
}

/*多项式$x^n - 1$的因式分解(正系数)
	$\phi(1) = x - 1$
	$\displaystyle \phi(n) = \frac{x^n - 1}{\prod_{d|n, d < n}{\phi(d)}} (n > 1)$
	$\displaystyle x^n-1 = \prod_{d|n}{\phi(d)}$
*/
