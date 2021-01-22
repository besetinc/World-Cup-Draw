#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <random>
#include <ctime>
#include <iterator>
using namespace std;
class team {
public:
	int id;
	string name;
	friend ostream& operator<<(ostream& os, const team& t);
public:
	team(int id=0,string name="0") : id(id),name(name){}
};
ostream& operator<<(ostream& os, const team& t) {
	os << t.name;
	return os;
}
void drawteam(vector<team>& seed,vector<team>& group,int& n) {
	team temp;
	random_device rd;// obtain a random number from hardware
	mt19937 gen(rd());// seed the generator
	uniform_int_distribution<> distr(0, n);// define the range
	int rn = distr(gen);
	rn = distr(gen);
	temp = seed.at(rn);
	group.push_back(temp);
	seed.erase(seed.begin() + rn);
	--n;
}
void print_fixtures(vector<vector<team>>& gr)  {
	std::cout << "Fixtures" << std::endl;
	int count = 0;char c = 'A'; int fixc = 1;
	while (count < 8) {
		cout << "\n" << "Group " << c << endl;
		cout << "First round: " << endl;
		cout << "Fixture " << fixc << " " << gr.at(count).at(0) << " vs " << gr.at(count).at(1) << endl; ++fixc;
		cout << "Fixture " << fixc << " " << gr.at(count).at(2) << " vs " << gr.at(count).at(3) << endl; ++fixc;
		cout << "Second round: " << endl;
		cout << "Fixture " << fixc << " " << gr.at(count).at(2) << " vs " << gr.at(count).at(0) << endl; ++fixc;
		cout << "Fixture " << fixc << " " << gr.at(count).at(3) << " vs " << gr.at(count).at(1) << endl; ++fixc;
		cout << "Third round: " << endl;
		cout << "Fixture " << fixc << " " << gr.at(count).at(0) << " vs " << gr.at(count).at(3) << endl; ++fixc;
		cout << "Fixture " << fixc << " " << gr.at(count).at(1) << " vs " << gr.at(count).at(2) << endl; ++fixc;
		++count;
		++c;
	}
}
int main() {
	int n = 7;
	srand(time(NULL));
	vector<team> s1 = { {1,"Belgium"},{2,"France"},{3,"Germany"},{4,"England"},{5,"Italy"},{ 6,"Croatia" },{ 7,"Portugal" },{ 8,"Spain" } };
	vector<team> s2 = { { 9,"Sweden" },{ 10,"Switzerland" },{ 11,"Denmark" },{ 12,"Iceland" },{ 13,"Russia" },{ 14,"Japan" },{ 15,"Australia" },{ 16,"S.Korea" } };
	vector<team> s3 = { { 17,"USA" },{ 18,"Costa Rica" },{ 19,"Chile" },{ 20,"Peru" },{ 21,"Brasil" },{ 22,"Argentina" },{ 23,"Mexico" },{ 24,"Colombia" } };
	vector<team> s4 = { { 25,"Ghana" },{ 26,"Nigeria" },{ 27,"Iran" },{ 28,"S.Arabia" },{ 29,"Egypt" },{ 30,"Morocco" },{ 31,"UAE" },{ 32,"Senegal" } };
	vector<vector<team>> s{ {s1},{s2},{s3},{s4} };
	vector<team> grA,grB,grC,grD,grE,grF,grG,grH;
	vector<vector<team>> gr{ { grA },{ grB },{ grC },{ grD },{ grE },{ grF },{ grG },{ grH } };
	ostream_iterator<team> os(std::cout, " ");
	int i = 0, count = 0; char c = 'A';
	while (count < 4) {
		for (int j = 0; j < 8; ++j) {
			drawteam(s.at(i), gr.at(j), n);
		}
		++i; ++count; n = 7;
	}
	for (int i = 0; i < 8; ++i) {
		cout << "\n" << "Group " << c << std::endl;
		copy(gr.at(i).begin(), gr.at(i).end(), os);
		++c;
	}
	print_fixtures(gr);
}
