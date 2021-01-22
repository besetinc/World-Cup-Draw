#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
struct time {
	int hour, min, sec;
};
ostream& operator<<(ostream& os, const time& t) {
	return os << t.hour << ':' << t.min << ':' << t.sec;
}
bool is_vowel(char c) { return strchr("AEIOU", c); }
int main() {
	vector<int> a = { 1,2,3,4,5 }, b,c;
	copy(a.begin(), a.end(), back_inserter(b));
	string s = { "v1s1i1t2e" };
	s.erase(remove_if(begin(s), end(s), isdigit),end(s));
	transform(begin(s), end(s), begin(s),toupper);
	replace_if(s.begin(), s.end(), is_vowel, '-');
	cout << s;
	getchar();
	getchar();
}