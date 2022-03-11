{{ self.title() }}

作者，版权声明等

## 题目简述

给定一张图和 $s_0,n,T$，$\forall i\in[1,T],s_i$ 在 $s_{i-1}$ 的出边均匀随机。求每个数字上次出现的位置的下一位的数值（该数字第一次出现则为0）的和的期望。



## 验题人

记图的边集为 $E$，$x$ 的出度是 $d^+(x)$。

枚举每个位置 $t$，在这个位置上的数字 $s_t=x$，上一次出现的位置 $t'$，以及 $s_{t'}$ 的下一个数字 $y=s_{t'+1}$：
$$
\sum_{0\le t'<t\le T,(x,y)\in E}\left[F(t',x)\times\frac{1}{d^+(x)}\times G_x(t-t'-1,y)\right]\times y
$$
其中 $F(t,x)$ 表示 $s_t=x$ 的概率，$G_x(\Delta t,y)$ 表示从 $y$ 出发，走 $\Delta t$ 步，前 $\Delta t-1$ 步不经过 $x$ 且第 $\Delta t$ 步恰好到达 $x$ 的概率。$F,G$ 的转移显然，可以计算表明总时间复杂度为 $O\left(Tn[\sum_{x=1}^n d^+(x)]\right)$。

