# GCD卷积 (gcdconv.cpp/.in/.out) (1s,512MB)

## Description

定义一种新的卷积 —— GCD卷积，其接受两个长度为 $n$ 的序列 $f,g$ ，依据下式生成长度为 $n$ 的序列 $h$ ：
$$
h_k = \sum_{\gcd(i,j) = k} f_i g_j
$$
现给定序列 $f,g$ ，求各 $h_i$ 对 $998244353$ 取模后的值。

## Input

第一行输入一个正整数 $n$ ，表示 $f,g$ 的长度。

第二行输入 $n$ 个整数 $f_i$ 。

第三行输入 $n$ 个整数 $g_i$ 。

## Output

为减少输出量，只需输出1个整数，表示各 $h_i$ 对 $998244353$ 取模后的异或和。

## Sample 1

### Sample 1 Input

```
3
5 1 4
2 3 3
```

### Sample 1 Output

```
78
```

### Sample 1 Explanation

$$
\begin{aligned}
h_1 &= f_1 ( g_1 + g_2 + g_3 ) + g_1 (f_2 + f_3) + f_2 g_3 + f_3 g_2 = 65 \\
h_2 &= f_2 g_2 = 3 \\
h_3 &= f_3 g_3 = 12
\end{aligned}
$$

$$
65 \oplus 3 \oplus 12 = 78
$$

## Sample 2

### Sample 2 Input

```
4
7 1 8 0
6 2 9 1
```

### Sample 2 Output

```
158
```

### Sample 2 Explanation

$$
\begin{aligned}
h_1 &= 213 \\
h_2 &= 3 \\
h_3 &= 72 \\
h_4 &= 0
\end{aligned}
$$

$$
213 \oplus 3 \oplus 72 \oplus 0 = 158
$$

## Sample 3

见 `sample` 目录下 `gcdconv3.in/.ans` 。

## Constraints

对20%的数据，$1 \le n \le 2000$ 。

对100%的数据， $1 \le n \le 4 \times 10^5$ ， $0 \le f_i, g_i \le 998244352$ 。

## Hints

时限在std的1.5倍左右。std没有卡常，数据有一定梯度，请放心食用。

## Source

sun123zxy