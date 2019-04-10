#define N 1000000
long long fact[N];

void getKth(long long k, vector<int> &ans) {
	vector<bool> was (ans.size(), false);
	for(int i = 0; i != N; i++) {
		fact[i] = (i == 0 ? 1 : fact[i - 1] * i);
	}
	for(int i = 0; i < ans.size(); i++) {
		long long pWas = k / fact[ans.size() - i - 1];
		k %= fact[ans.size() - i - 1];
		int curr = 0;
		for(int j = 1; j <= ans.size(); j++) {
			if(!was[j]) {
				curr++;
				if(curr == pWas + 1) {
					ans[i] = j;
					was[j] = true;
				}
			}
		}
	}
}
