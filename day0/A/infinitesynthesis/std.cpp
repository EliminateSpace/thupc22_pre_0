#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3fll;
vector<int> mul[100008], fac[1000008];
vector<int>::iterator head[100008];
int vis[1000008], vmin[100008], ch[270003], pos;
long long t[270003];
void Build(int o, int l, int r){
	if (l == r) {
		ch[o] = l;
		t[o] = inf;
		return ;
	}
	int o2 = o << 1, mid = l + r >> 1;
	Build(o2, l, mid);
	Build(o2 | 1, mid + 1, r);
	if (t[o2] < t[o2 | 1]) t[o] = t[o2], ch[o] = ch[o2];
	else t[o] = t[o2 | 1], ch[o] = ch[o2 | 1];
	return ;
}
void Modify(int o, int l, int r){
	if (l == r) {
		if (vmin[l] == 0x3f3f3f3f || head[l] == mul[l].end()) t[o] = inf;
		else t[o] = 1ll * *head[l] * vmin[l] / l;
		return ;
	}
	int o2 = o << 1, mid = l + r >> 1;
	if (pos <= mid) Modify(o2, l, mid);
	else Modify(o2 | 1, mid + 1, r);
	if (t[o2] < t[o2 | 1]) t[o] = t[o2], ch[o] = ch[o2];
	else t[o] = t[o2 | 1], ch[o] = ch[o2 | 1];
	return ;
}
int main(){
	int l, r, i, j, k, len;
	long long ans = 0;
	vector<int>::iterator it;
	scanf("%d %d", &l, &r);
	if (l == r) {
		puts("0");
		return 0;
	}
	len = r - l;
	for (i = 1; i <= len; ++i) {
		for (j = (l + i - 1) / i * i; j <= r; j += i) {
			mul[i].push_back(j);
			fac[j].push_back(i);
		}
		head[i] = mul[i].begin();
	}
	Build(1, 1, len);
	memset(vmin, 63, sizeof(vmin));
	
	j = l;
	vis[l] = 1;
	for (i = l; i < r; ++i) {
		//fprintf(stderr, "Working %d\n", j);
		for (it = fac[j].begin(); it != fac[j].end(); ++it) {
			k = *it;
			if (vmin[k] > j) vmin[k] = j;
			while (head[k] != mul[k].end() && vis[*head[k]]) ++head[k];
			pos = k;
			// fprintf(stderr, "Modify %d: %d %d\n", k, *head[k], vmin[k]);
			Modify(1, 1, len);
		}
		
		//fprintf(stderr, "t = %lld, ch = %d\n", t[1], ch[1]);
		j = *head[ch[1]];
		vis[j] = 1;
		ans += t[1];
	}
	printf("%lld\n", ans);
	return 0;
}
