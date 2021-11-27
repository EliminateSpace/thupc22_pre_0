#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

FILE *inFile;
FILE *outFile;
FILE *ansFile;
FILE *scoreFile;
FILE *infoFile;
double score;
bool swap_flag;

void registerTestlib()
{
	__testlib_ensuresPreconditions();

	testlibMode = _checker;
	__testlib_set_binary(stdin);

	inf.init(inFile, _input);
	ouf.init(outFile, _output);
	ans.init(ansFile, _answer);
}

void ret(double result, const char *info)
{
	if (swap_flag)
		fprintf(infoFile, "%s\n", info); //Arbiter only allow to read EXACTLY one line info, no less and no more, and must BEFORE score
	fprintf(scoreFile, "%.6f\n", result * score);
	if (!swap_flag)
		fprintf(infoFile, "%s\n", info);

	// for testlib
	if (result == 0)
		quit(_wa, info);
	else
		quit(_ok, info);
}
int nn,n,m,a[1000010];
bool vis[5][1000010];
int main(int argc, char **argv)
{
	//You'd better not change this swith block
	switch (argc)
	{
	case 0: //LOJ
		inFile = fopen("input", "r");
		outFile = fopen("user_out", "r");
		ansFile = fopen("answer", "r");
		scoreFile = stdout;
		infoFile = stderr;
		score = 100;
		break;
	case 4: //Arbiter
		inFile = fopen(argv[1], "r");
		outFile = fopen(argv[2], "r");
		ansFile = fopen(argv[3], "r");
		scoreFile = infoFile = fopen("/tmp/_eval.score", "w");
		score = 10;
		swap_flag = true;
		break;
	case 5:
		if (strcmp(argv[4], "THUOJ") == 0)
		{ //Tsinghua OJ(OJ for DSA course)
			inFile = fopen(argv[1], "r");
			outFile = fopen(argv[3], "r");
			ansFile = fopen(argv[2], "r");
			scoreFile = stdout;
			infoFile = stdout;
			score = 100;
		}
		else
		{ //Tsinsen OJ
			inFile = fopen(argv[1], "r");
			outFile = fopen(argv[2], "r");
			ansFile = fopen(argv[3], "r");
			scoreFile = fopen(argv[4], "w");
			infoFile = fopen("tmp", "w"); //Tsinsen doesn't use this file
			score = 1;
		}
		break;
	case 7: //Lemon and TUOJ
		inFile = fopen(argv[1], "r");
		outFile = fopen(argv[2], "r");
		ansFile = fopen(argv[3], "r");
		FILE *fs = fopen(argv[4], "r");
		if (fs)
			fscanf(fs, "%lf", &score); //Current TUOJ
		else
			sscanf(argv[4], "%lf", &score); //Lemon and future TUOJ
		scoreFile = fopen(argv[5], "w");
		infoFile = fopen(argv[6], "w");
		break;
	}

	registerTestlib();
	
	int an = ans.readInt(); 
	int ou = ouf.readInt();
	if(an != ou)
		ret(0, "Wrong answer of m.");
	n = inf.readInt();
	for(int i = 1;i <= n;++i) a[i] = inf.readInt();
	nn = n + an;
	for(int i = n + 1;i <= nn;++i) a[i] = i;
	m = ouf.readInt();
	if(m < 0 || m > 1000000)
		ret(0, "Invalid value of k.");
	for(int i = 1;i <= m;++i){
		int x = ouf.readInt();
		int y = ouf.readInt();
		if(x > y) swap(x,y);
		if(x <= 0 || x > nn || y <= 0 || y > nn)
			ret(0, "Invalid operation.");
		if(x <= n && y <= n)
			ret(0, "Invalid operation.");
		if(vis[y - n][x])
			ret(0, "Invalid operation.");
		vis[y - n][x] = 1;
		swap(a[x],a[y]);
	}
	for(int i = 1;i <= nn;++i) if(a[i] != i)
		ret(0, "Wrong answer of operations.");
	ret(1, "Correct.");
	return 0;
}
