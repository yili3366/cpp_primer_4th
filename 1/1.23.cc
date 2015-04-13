#include <iostream>
#include "Sales_item.h"

int main()
{
  Sales_item total, trans;

  //read transactions
  std::cout << "Enter transactions:" << std::endl;

  if (std::cin >> total) {
    while (std::cin >> trans)
      if (total.same_isbn(trans))
        total = total + trans;
      else{
        std::cout << "Different ISBN." << std::endl;
        return 1;
      }
    std::cout << "The total information: " << std::endl
              << "ISBN, number of copies sold, "
              << "total revenue, and average price are:"
              << std::endl << total << std::endl;
  } else {
    std::cout << "No data?!" << std::endl;
    return -1;
  }

  return 0;
}
