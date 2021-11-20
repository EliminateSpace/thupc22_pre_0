{{ self.title() }}

{{ s('background') }}

听说有人嫌题面描述都太长了。

{{ s('description') }}

对于任意 $V\subset\mathbb{N}^*$，$|V|<+\infty$，构造一张无向完全图 $G=(V,E)$，其中 $(u, v)$ 的边权为 $\mathrm{lcm}(u, v)$。称 $G$ 的最小生成树为 $V$ 的最小公倍树（Lowest Common Tree）。

现在给出 $L, R$，请你求出 $V=\{L, L+1, \cdots, R\}$ 的最小公倍树 $LCT(V)$。

{{ self.input_file() }}

输入仅一行，包括两个正整数 $L, R$。

{{ s('output format') }}

{{ self.output_file() }}

输出一个正整数，表示 $LCT(V)$ 的边权和。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

这是第一组数据的样例说明。

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

对于 $100\%$ 的数据，保证 $1\le L\le R\le 10^6$，且 $R-L\le 10^5$。