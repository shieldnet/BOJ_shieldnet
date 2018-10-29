//Code from 
//http://blog.myungwoo.kr/121

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 5003
#define pb push_back

int N;
int ans;
int dptable[MAXN][MAXN], edge[MAXN][MAXN];
vector <int> con[MAXN];
void computeLPSArray(char* pat, int M, int* lps);

#define MAX_SIZE 200001

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	ans = 0;
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int* lps = (int*)malloc(sizeof(int)*M);

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			ans = 1;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

				// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void DFS(int n, int from)
{
	vector <int> sumofvalue(N + 1, 0);
	// Pre-compute
	for (int t : con[n]) if (t != from) {
		DFS(t, n);
		for (int i = 0; i <= N; i++) {
			sumofvalue[i] += edge[t][i];
		}
	}

	// Initialize
	for (int i = 0; i <= N; i++) dptable[n][i] = edge[n][i] = N;

	// Calculation
	for (int t : con[n]) if (t != from) {
		for (int i = 1; i <= N; i++) dptable[n][i - 1] = min(dptable[n][i - 1], dptable[t][i] + (sumofvalue[i - 1] - edge[t][i - 1]));
	}
	for (int i = 1; i <= N; i++) edge[n][i] = min(edge[n][i], sumofvalue[i - 1]);
	for (int i = 1; i <= N; i++) dptable[n][i] = min(dptable[n][i], sumofvalue[i] + i);

	// Monotonize
	for (int i = N; i--;) dptable[n][i] = min(dptable[n][i], dptable[n][i + 1]);
	edge[n][0] = dptable[n][0];
	for (int i = 1; i <= N; i++) edge[n][i] = min(edge[n][i], edge[n][i - 1]);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i<N; i++) {
		int a, b; scanf("%d %d", &a, &b);
		con[a].pb(b); con[b].pb(a);
	}
	DFS(1, 0);
	printf("%d", dptable[1][0]);

	return 0;
}