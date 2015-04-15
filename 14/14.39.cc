#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}

	ifstream in_file;
	in_file.open(argv[1]);
	if (!in_file) {
		cerr << "Can't open input file!" << endl;
		return EXIT_FAILURE;
	}

	vector<string> words;
	string word;

	while (in_file >> word)
		words.push_back(word);

	sort(words.begin(), words.end());
	words.erase(unique(words.begin(), words.end()), words.end());

	vector<string>::size_type wc = 0;
	greater_equal<string::size_type> greq;
	for (vector<string>::iterator iter = words.begin();
		iter != words.end(); ++iter) {
		if (greq(iter->size(), 10)) {
			++wc;
		}
	}

	cout << wc << " " << make_plural(wc, "word", "s")
	     << " 1- characters or longer" << endl;

	return 0;
}
