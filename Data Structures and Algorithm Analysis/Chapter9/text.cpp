#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct dataStru
{
	int STEP;
	int Lane;
	double COUNTS;
	double flow;
	double density;
	double speed;
	double queue_length;
};

int main()
{
	ifstream fin("test3.txt");
	string line;
	vector<dataStru> data;
	dataStru tmp;
	char ch;
	getline(fin, line);
	while (getline(fin, line)) {
		istringstream record(line);
		record >> tmp.STEP;
		record.get(ch);
		record.get(ch);
		record.get(ch);
		record.get(ch);
		record.get(ch);
		record.get(ch);
		record >> tmp.Lane;
		record.get(ch);
		record.get(ch);
		record >> tmp.COUNTS;
		record.get(ch);
		record >> tmp.flow;
		record.get(ch);
		record >> tmp.density;
		record.get(ch);
		record >> tmp.speed;
		record.get(ch);
		record >> tmp.queue_length;
		data.push_back(tmp);
	}
	ofstream fout("output.txt");
	for (auto &c : data)
		fout << c.speed << endl;
	cout << "ok";
	return 0;
}