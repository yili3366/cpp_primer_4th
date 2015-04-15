#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

class BET_cls {
public:
	BET_cls(string::size_type len1, string::size_type len2)
	{
		if (len1 < len2) {
			minLength = len1;
			maxLength = len2;
		} else {
			minLength = len2;
			maxLength = len1;
		}
	}

	bool operator() (const string &s)
	{
		return s.size() >= minLength && s.size() <= maxLength;
	}
private:
	string::size_type minLength;
	string::size_type maxLength;
};

class GT_cls {
public:
	GT_cls(size_t val = 0) : bound(val)
	{
	}

	bool operator() (const string &s)
	{
		return s.size() >= bound;
	}
private:
	std::string::size_type bound;
};

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

	vector<string>::size_type wc = count_if(words.begin(), 
			words.end(), BET_cls(1, 9));
	cout << wc << " " << make_plural(wc, "word", "s")
	     << " are of size 1 through 10 inclusive" << endl;

	wc = count_if(words.begin(), 
			words.end(), GT_cls(10));
	cout << wc << " " << make_plural(wc, "word", "s")
	     << " 10 characters or longer" << endl;

	return 0;
}
