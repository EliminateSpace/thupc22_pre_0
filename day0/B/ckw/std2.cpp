#include <cstdio>
using namespace std;
#define TMAX 108
#define NMAX 108
#define MMAX 5004
#define MOD 998244353
int mi[NMAX], start[NMAX], fr[MMAX], to[MMAX];
int inv[NMAX], f[TMAX][NMAX], g[NMAX][TMAX][NMAX], h[TMAX][MMAX];
// f(t, x) = P(s_t = x)
// g(u, t, v) = P(s_{i} = v | s_{i + t} = u)
// h(t, e) = P(s_{i + 1}, \cdots, s_{i + t - 1} \ne fr[e], s_{i + t} = fr[e] | s_i = fr[e], s_{i + 1} = to[e])
int main(){
	freopen("data.in","r",stdin);
	int n, m = 0, s0, T, i, j, k, u, v, (*p)[NMAX], sum, tmp, ans = 0;
	scanf("%d %d %d", &n, &s0, &T);
	for (i = 1; i <= n; ++i) {
		start[i] = m + 1;
		scanf("%d", &mi[i]);
		for (j = 1; j <= mi[i]; ++j) {
			scanf("%d", &v);
			++m;
			fr[m] = i;
			to[m] = v;
		}
	}
	start[n + 1] = m + 1;
	
	inv[1] = 1;
	for (i = 2; i <= n; ++i) inv[i] = MOD - 1ll * (MOD / i) * inv[MOD % i] % MOD;
	
	f[0][s0] = 1;
	for (i = 0; i < T; ++i) {
		for (j = 1; j <= m; ++j) {
			u = fr[j];
			v = to[j];
			f[i + 1][v] = (f[i + 1][v] + 1ll * f[i][u] * inv[mi[u]]) % MOD;
		}
	}
	
	for (i = 1; i <= n; ++i) {
		p = &g[i][0];
		p[0][i] = 1;
		for (j = 1; j <= T; ++j) {
			for (u = 1; u <= n; ++u) {
				if (u != i) {
					tmp = 0;
					for (k = start[u]; k < start[u + 1]; ++k) {
						(tmp += p[j - 1][to[k]]) %= MOD;
					}
					p[j][u] = 1ll * inv[mi[u]] * tmp % MOD;
				}
				else {
					for (k = start[u]; k < start[u + 1]; ++k) {
						h[j][k] = p[j - 1][to[k]];
					}
				}
			}
		}
	}
	
	for (u = 1; u <= n; ++u) {
		for (i = start[u]; i < start[u + 1]; ++i) {
			if (to[i] == u) break;
		}
		if (i < start[u + 1]) {
			h[1][u] = 1;
			for (j = 2; j <= T; ++j) h[j][u] = 0;
		}
	}
	
	for (i = 1; i <= m; ++i) {
		u = fr[i];
		v = to[i];
		if (u == v) {
			tmp = 0;
			for (j = 0; j < T; ++j) {
				(tmp += f[j][u]) %= MOD;
			}
			ans = (ans + 1ll * v * inv[mi[u]] % MOD * tmp) % MOD;
		}
		else {
			tmp = 0;
			for (j = 0; j < T; ++j) {
				for (k = j + 2; k <= T; ++k) {
					tmp = (tmp + 1ll * f[j][u] * h[k - j][i]) % MOD;
				}
			}
			ans = (ans + 1ll * v * inv[mi[u]] % MOD * tmp) % MOD;
		}
	}
	printf("%d\n", ans);
	return 0;
}
