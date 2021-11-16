**Solution**

首先，将$t_m, t_c$与$n$取min后，可以发现，所谓“Lewis的最优方案”中，Max一定出场连续的$t_m$天，Checo一定出场连续的$t_c$天。

可以反证法证明：不失一般性，假设Max的出场场次不连续，可以把任意一场中间未出场比赛中的Lewis或Valtteri换成Max，从而在不违反规则的情况下增加收益，因此一定连续；假设Max的出场场次不足$t_m$场，直接向前或者向后延长一场比赛即可在不违反规则的情况下增加收益，对于Checo同理——因此，确定了$p_m$和$p_c$，即可唯一确定一种可能的属于“Lewis的最优方案”的分配方式。

另外，我们可以证明，如果 $1 \le p_m \le n-t_m+1$ 且 $1 \le p_c \le n-t_c+1$，那么此方案一定属于“Lewis的最优方案”。

对于任意符合以上条件的$p_m, p_c$组合，注意到仅仅通过改变序列的一个位置增加总收入，等价于将一场比赛中的Lewis或Valtteri换成Max或Checo，但由因为Max和Checo的出场数已经都达到了最大可能值，因此无法实现，所以我们得到了“Lewis的最优方案”对应充要条件。

因此，我们知道，总方案数量为$ (n-t_m+1)(n-t_c+1)$，而找中位数，等价于找到收入第$\lfloor \frac{(n-t_m+1)(n-t_c+1)+1}{2} \rfloor$ 和$\lceil \frac{(n-t_m+1)(n-t_c+1)+1}{2} \rceil$的方案收入的平均值（无论对总方案数是奇数还是偶数的情况均成立），考虑化为求收入第$k$多的方案收入，然后分别令$k = \lfloor \frac{(n-t_m+1)(n-t_c+1)+1}{2} \rfloor$ 以及 $ k = \lceil \frac{(n-t_m+1)(n-t_c+1)+1}{2} \rceil$ 即可求出最终答案。



考虑二分答案，转化为对于给定的$val$, 判断有多少种方案的收入小于等于$val$。

首先，将$a,b,c$分别作前缀和（此后用$a,b,c$指代前缀和数组），对于给定的$p_m$和$p_c$，不妨设$ t_m \le t_c$，最终的收入为

1. 若 $1 \le p_m \le p_m+t_m-1 < p_c \le p_c+t_c-1 \le n$ ,  则 （不相交，短的在前）$ sum_{p_m,p_c} = a_{p_{m}-1}+(b_{p_{m}+t_m-1}-b_{p_m-1}) + (a_{p_c-1}-a_{p_m+t_m-1}) + (b_{p_c+t_c-1}-b_{p_{c}-1})+(a_{n}-a_{p_{c}+t_{c}-1})$

2. 若 $1 \le p_m < p_c \le p_m+t_m-1 <  p_c+t_c-1 \le n$ ,  则 （相交，短的在前）$ sum_{p_m,p_c} = a_{p_{m}-1}+(b_{p_c-1}-b_{p_m-1}) + (c_{p_m+t_m-1}-c_{p_c-1}) + (b_{p_c+t_c-1}-b_{p_m+t_m-1})+(a_{n}-a_{p_{c}+t_{c}-1})$

3. 若 $1 \le p_c \le p_m \le p_m+t_m-1 \le p_c+t_c-1 \le n$ ,  则（长的覆盖短的）$ sum_{p_m,p_c} = a_{p_{c}-1}+(b_{p_{m}-1}-b_{p_c-1}) + (c_{p_m+t_m-1}-c_{p_m-1}) + (b_{p_c+t_c-1}-b_{p_{m}+t_m-1})+(a_{n}-a_{p_{c}+t_{c}-1})$

4. 若$1 \le p_c < p_m \le p_c+t_c-1 < p_m+t_m-1 \le n$ ,  则（相交，长的在前）$ sum_{p_m,p_c} = a_{p_{c}-1}+(b_{p_m-1}-b_{p_c-1}) + (c_{p_c+t_c-1}-c_{p_m-1}) + (b_{p_m+t_m-1}-b_{p_c+t_c-1})+(a_{n}-a_{p_{m}+t_{m}-1})$

5. 若$1 \le p_c \le p_c+t_c-1 < p_m \le p_m+t_m-1 \le n$ ,  则（不相交，长的在前）$ sum_{p_m,p_c} = a_{p_{c}-1}+(b_{p_{c}+t_c-1}-b_{p_c-1}) + (a_{p_m-1}-a_{p_c+t_c-1}) + (b_{p_m+t_m-1}-b_{p_{m}-1})+(a_{n}-a_{p_{m}+t_{m}-1})$

   

接下来，对于这些情况，可以将$p_m,p_c$分离变量如下（以第一种情况为例）:

$ sum_{p_m,p_c} = (b_{p_{m}+t_m-1} -a_{p_m+t_m-1}+a_{p_{m}-1}-b_{p_m-1}) + (a_{p_c-1} -b_{p_c-1}+ b_{p_c+t_c-1}-a_{p_{c}+t_{c}-1})+a_n \sim x_{p_{m}} + y_{p_{c}} +a_n $

枚举$p_m$,   化为：求满足 $y_{p_{c}}$ 不超过给定阈值$val-a_n-x_{p_m}$ 且 $p_c \in [p_m+t_m, n-t_c+1]$ 的 $p_c$数量 

相似的，可以得到——

对于第2种情况，

$ sum_{p_m,p_c} = (c_{p_m+t_m-1}-b_{p_m+t_m-1}+a_{p_{m}-1}-b_{p_m-1})+(b_{p_c-1} -c_{p_c-1}+b_{p_c+t_c-1}-a_{p_{c}+t_{c}-1}) + a_n \sim x_{p_{m}} + y_{p_{c}} +a_n $

枚举$p_m$,   化为：求满足 $y_{p_{c}}$ 不超过给定阈值$val-a_n-x_{p_m}$ 且 $p_c \in [p_m+1,  min(p_m+t_m-1, n-t_c+1)]$ 的 $p_c$数量 

对于第3种情况，

$ sum_{p_m,p_c} =  (c_{p_m+t_m-1}-b_{p_m+t_m-1}+b_{p_m-1}-c_{p_m-1}) + (a_{p_{c}-1}-b_{p_c-1}+ b_{p_c+t_c-1}-a_{p_{c}+t_{c}-1}) +a_n \sim x_{p_m}+y_{p_c}+a_n$

枚举$p_m$,   化为：求满足 $y_{p_{c}}$ 不超过给定阈值$val-a_n-x_{p_m}$ 且 $p_c \in [max(1,p_m+t_m-t_c),min(p_m,n-t_c+1)]$ 的 $p_c$数量 

对于第4种情况，

$ sum_{p_m,p_c} =  (b_{p_m+t_m-1}-a_{p_m+t_m-1}+b_{p_m-1}-c_{p_m-1}) + (a_{p_{c}-1}-b_{p_c-1}+ c_{p_c+t_c-1}-b_{p_{c}+t_{c}-1}) +a_n \sim x_{p_m}+y_{p_c}+a_n$

枚举$p_m$,   化为：求满足 $y_{p_{c}}$ 不超过给定阈值$val-a_n-x_{p_m}$ 且 $p_c \in [max(0,p_m-t_c)+1, p_m+t_m-t_c-1]$ 的 $p_c$数量 

对于第5种情况，

$ sum_{p_m,p_c} =  (b_{p_m+t_m-1}-a_{p_m+t_m-1}+a_{p_m-1}-b_{p_m-1}) + (a_{p_{c}-1}-b_{p_c-1}+ b_{p_c+t_c-1}-a_{p_{c}+t_{c}-1}) +a_n \sim x_{p_m}+y_{p_c}+a_n$

枚举$p_m$,   化为：求满足 $y_{p_{c}}$ 不超过给定阈值$val-a_n-x_{p_m}$ 且 $p_c \in [1,p_m-t_c]$ 的 $p_c$数量



离散化+树状数组即可解决，总体时间复杂度2个log。

