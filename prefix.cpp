#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix(string s) { 
	vector<int> p(s.size());
	int j=0;
	for(int i=1; i<(int)s.size(); i++) {
		while (j>0 && s[j] != s[i]) {
			j = p[j-1];
		}
		if(s[j] == s[i]){
			j++;
		}
		p[i] = j;
	} 
	return p;
}

int main() {

	string minta;
	cout << "írd be minek kell a prefixfüggvénye: ";
	cin >> minta;
	vector<int> result = prefix(minta);
	for(int i=0; i<result.size(); i++) {
		cout << i+1 << ". érték: " << result[i] << endl;
	}
	

	return 0;
}
