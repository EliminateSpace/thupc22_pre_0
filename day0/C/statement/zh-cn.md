{{ self.title() }}

{{ s('description') }}

Lewis热爱打拳，因此他组建了一家拳击俱乐部，希望通过举办表演赛卖票以筹集自己训练的资金，但是，很遗憾，Lewis人缘并不好，因此这个俱乐部只有两个成员——Lewis和他的好基友Valtteri，而观众们很快就厌倦了每晚都是他们两人出场的表演赛，票卖不出去了，拳击俱乐部濒临倒闭。穷则思变，Lewis决定通过请外援的方式，尝试拯救自己的俱乐部。

通过支票攻势，Lewis很快就请到了两个拳坛明星——Max和Checo，他们将作为飞行嘉宾加入Lewis的俱乐部。在接下来的一个赛季里，Lewis总共会安排$n$ $(1 \le n \le 2*10^5)$ 场比赛，每场比赛会从现有的4个成员中选出2人比赛，对于第$i$ $(1 \le i \le n)$场比赛，如果是Lewis和Valtteri的比赛，只能卖出$a_{i}$元的门票，如果是他们中一人和一个明星的比赛，能卖出$b_i$元的门票，如果是两个明星Max和Checo之间的比赛，能卖出$c_i$元的门票。观众们喜欢看明星之间的高水平比赛，而不是Lewis和Valtteri的菜鸡互啄，因此有$1 \le a_{i} < b_{i} < c_{i} \le 10^9$ 。除此之外，安排比赛时还有如下要求——

1.  因为明星都是日理万机的，他们只同意分别在Lewis的俱乐部停留最多$t_m, t_c$场比赛的时间。设Max出席的第一场比赛是第$p_m$场，最后一场是$q_{m}$场，Checo出席的第一场比赛是第$p_c$场，最后一场是$q_c$场，则需要满足$q_m - p_m +1 \le t_m$ 且 $q_c - p_c +1 \le t_c$；
3. Lewis深知自己不会是两个明星的对手，他不会愿意自己被打得鼻青脸肿直接KO，因此，他不会安排自己与两位明星的比赛（言下之意，挨打的工作就被Lewis偷偷安排给了自己的好基友Valterri，让我们为可怜的工具人Valterri默哀）；

同时，Lewis希望最大化自己的总收入，但是，他不太聪明，因此，如果一种方案满足以下条件，他就认为此方案满足”收入最大“——

 定义 (“Lewis的最优方案”)：对于一种方案，可以看作一个长度为$2n$的序列，序列的第$(2i-1)$和$2i$项为第$i$场比赛的对阵双方，如果通过修改序列的任意**1**个位置，都无法得到一个收入严格大于当前收入的合法方案，则称此方案为“Lewis的最优方案”。

聪明的你很快就发现了，“Lewis的最优方案”不一定能最大化总收入且可能不唯一。已知Lewis会从所有“Lewis的最优方案”（两个方案相同，当且仅当每一天的对阵均相同，注意，Max vs Valtteri 和 Checo vs Valtteri虽然卖出门票相当，但视为两种不同的方案）等概率随机选一个方案执行，那么，请问在Lewis可能最终选择的所有方案中，门票收入的中位数是多少呢？（答案保留一位小数输出）



{{ s('input format') }}

{{ self.input_file() }}

第 $1$ 行：3个正整数$n,t_m, t_c$，意义见题面；

接下来 $n$ 行：每行3个正整数$ a_i, b_i, c_i $ 表示三种情况下卖出的门票价格。

{{ s('output format') }}

{{ self.output_file() }}

一行一个正整数表示在Lewis最终选择的所有方案中，门票收入的中位数。



{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

Lewis的“收入最大方案”总共有以下4种：

1. Max vs Checo, Lewis vs Valtteri，门票收入为100+1=101
2. Valtteri vs Max, Valtteri vs Checo，门票收入为10+2=12
3. Valtteri vs Checo, Valtteri vs Max，门票收入为10+2=12
4. Lewis vs Valterri, Max vs Checo，门票收入为1+3=4

中位数为(12+12)/2 = 12



{{ s('sample', 2) }}

{{ self.sample_text() }}



{{ s('subtasks') }}

数据范围：$1 \le n, t_m, t_c \le 2*10^5$ ,  $1 \le a_{i} < b_{i} < c_{i} \le 10^9$

