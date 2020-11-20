# GCD卷积 Solution

## ???

+ 样例2比较暴力。

## 记号说明

默认诸如 $n,d,i,j,k$ 的下标变量的最大值为题目中的给出的序列长度，并把序列更换为数论函数来表示。

注意本题解中的 $n$ 通常是一个变量，和题目中定义的序列长度 $n$ 不同。

另外，用 $\circ$ 代表 $\gcd$ 卷积，即
$$
h(n) = (f \circ g)(n) = \sum_{\gcd(i,j) = n} f(i) g(j)
$$
## Solution

我们按照快速傅里叶变换（FFT）、快速莫比乌斯变换（FMT）解决卷积的思路来解决该问题——构造一种变换来满足卷积定理：

$$
\hat f(n) \hat g(n) = \widehat {(f \circ g)}(n)
$$
$\hat f$ 即对函数 $f$ 进行该变换后得到的函数。

通过一些敏锐的直觉，我们能感受到 $\gcd$ 和枚举约数或者倍数有一些关系。

容易想到构造出一种变换，称之为“倍数和变换”：
$$
\hat f(n) = \sum_{n|d} f(d)
$$
并根据莫比乌斯反演得到它的逆变换
$$
f(n) = \sum_{n|d} \mu(\frac n d) \hat f(d)
$$
（这实际上是标准莫比乌斯反演的另一种形式，详见后文 [Further Thoughts](#Further Thoughts) ）

这个变换对 $\gcd$ 卷积满足卷积定理，证明如下。

首先，写出 $\gcd$ 卷积
$$
h(k) = (f \circ g)(k) = \sum_{i,j} [\gcd(i,j)=k] f(i) g(j)
$$
 左右两边做倍数和变换：
$$
\begin{aligned}
\hat h(n) &= \sum_{n|k} \sum_{i,j} [\gcd(i,j)=k] f(i) g(j) \\
&= \sum_{i,j} \left( \sum_{n|k} [\gcd(i,j)=k] \right) f(i) g(j) \quad \\
&= \sum_{i,j} [n|i][n|j] f(i) g(j) \quad \\
&= \sum_{n|i} f(i) \sum_{n|j} g(j) \quad \\
&= \hat f(n) \hat g(n)
\end{aligned}
$$
得证。上述证明的核心在于 $\sum_{n|k} [\gcd(i,j)=k] = [n|i] [n|j]$ 。

于是，先对 $f,g$ 做倍数和变换，然后直接 $O(n)$ 点值相乘，再逆变换回来，就能得到 $f \circ g$ 。

那么剩下的问题在于如何快速做倍数和变换及其逆变换。这是非常simple的，直接暴力就好了。复杂度为 $O(n H(n))$ ，其中调和级数 $H(n)= \sum_{k=1}^{n} \frac 1 k$ ，有 $\lim_{n \to \infty} H(n) = \ln(n) + c$ 。欧拉常数 $c \approx 0.57721566490153286060651209$ 。

可以称之为“快速倍数和变换”。

总时间复杂度约为 $O(n \ln n)$ 。

## Further Thoughts

本题用到的是莫比乌斯反演的一种变形
$$
g(n) = \sum_{n|d} f(n) \iff f(d) = \sum_{n|d} \mu(\frac n d) g(d)
$$
原版莫比乌斯反演长这样
$$
g(n) = \sum_{d|n} f(n) \iff f(d) = \sum_{d|n} \mu(\frac n d) g(d)
$$
若把题目改成 $\mathrm{lcm}$ 卷积，即
$$
h_k = \sum_{\mathrm{lcm}(i,j) = k} f_i g_j
$$
用到的就是原版莫比乌斯反演。相应的构造一个“约数和变换”即可解决。而约数和变换可以用“快速约数和变换”（实际上就是个埃筛）实现，有兴趣的同学可以试试。

## 后记 & 致谢

~~Idea是在语文课上摸出来的，Solution是在随后的数学课上想出来的~~

很早以前就觉得FMT和莫比乌斯反演有些说不清道不明的关系，出这道题也让笔者对其理解更加深入了。

其实早有大佬对 $\mathrm{lcm}$ / $\gcd$ 卷积展开过研究。Google一波可以发现国外数学社区有这方面的讨论，最晚2013年arXiv上就有讨论其性质的论文了（笔者驽钝，确实无力理解，感兴趣的大佬可以直接Google "GCD Convolution"了解）。只可惜如此自然而美妙的 $\gcd$ 卷积，竟然没有随着那篇集合幂级数的论文引入国内，让笔者感到有些遗憾。

总之，这道题深入的考察对FFT、FMT原理的理解以及对 $\gcd$ 、莫比乌斯反演的敏锐直觉，~~是不可多得的数论好题（~~

题面、题解、标程和数据生成器都挂在 [git@github.com:sun123zxy/gcdconv.git](https://github.com/sun123zxy/gcdconv) 上，可自行获取。

另外，对本题更深入的探讨放在了[我的博客](https://www.cnblogs.com/sun123zxy/p/14014070.html)上。

下面是战术感谢环节。

感谢keke学长为我们教授集合幂级数。

感谢TbYangZ、diong神、changruinian2020几位神仙的点拨。

And you...



<p align="right">——sun123zxy</p>

<p align="right">Sep. 2020 初稿完成</p>

<p align="right">Nov. 2020 最后更新</p>