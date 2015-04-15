#include <iostream>
#include <vector>
#include <algorithm>

class GT_cls {
 public:
  GT_cls(int);
  bool operator() (const int &ival);
 private:
  int bound;
};

GT_cls::GT_cls(int val = 0): bound(val)
{
}

bool GT_cls::operator()(const int &ival)
{
  return ival > bound;
}

int main()
{
  std::vector<int> ivec;

  int ival;
  std::cout << "Enter numbers(Ctrl+D to end): " << std::endl;

  while (std::cin >> ival)
    ivec.push_back(ival);

  std::cin.clear();

  int spval;
  std::cout << "Enter a specified value: " << std::endl;
  std::cin >> spval;

  std::vector<int>::iterator iter;
  iter = find_if(ivec.begin(), ivec.end(), GT_cls(spval));

  if (iter != ivec.end())
    std::cout << "the first element that is larger than "
              << spval << " : "
              << *iter << std::endl;
  else
    std::cout << "no element that is larger than "
              << spval << std::endl;

  return 0;
}
