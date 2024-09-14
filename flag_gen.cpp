#include "BigInt.h"
#include <bits/stdc++.h>
typedef BigInt bi;
using namespace std;

string nstr = "";
string flag = "PESANKU{REDACTED}";

const bi ten("10");

string conv(char inp) {
	int num = inp;
	if (num == 0) {
		return "0";
	}
	string out = "";
	while(num > 0) {
		out += '0'+(num % 10);
		num /= 10;
	}
	reverse(out.begin(), out.end());
	return out;
}

int main() {
	freopen("flag.txt", "r", stdin);
	freopen("encrypted.txt", "w", stdout);
	cin >> flag;
	unsigned long long bek = chrono::steady_clock::now().time_since_epoch().count();
	mt19937_64 rng(bek);
	cout << bek << " |\n";

	for (int i = 0; i < flag.size(); ++i) {
		flag[i] = ((flag[i]+(rng()%128)) % 128);
		if(i == 0 && flag[i] == 0) {
			bek = chrono::steady_clock::now().time_since_epoch().count();
			mt19937_64 rng(bek);
			cout << bek << " |\n";
			i--;
			continue ;
		}
		nstr += conv(flag[i]);
	}

	bi mybi(nstr);
	for (int i = 0; i < 8; ++i) {
		mybi *= mybi;
	}
	cout << mybi << "\n";
	return 0;
}