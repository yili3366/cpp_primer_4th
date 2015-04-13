/*
 * This file contains code from "C++ Primer, Fourth Edition", by Stanley B.
 * Lippman, Jose Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2005 by Objectwrite, Inc., Jose Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * Pearson Education, Inc.
 * Rights and Contracts Department
 * 75 Arlington Street, Suite 300
 * Boston, MA 02216
 * Fax: (617) 848-7047
 */

#ifndef SALESITEM_H
#define SALESITEM_H

// Definition of Sales_item class and related functions goes here

// NB: when prepare this file for the code directory on the web,
//     be sure all operations are defined as inlines within the
//     header so that user code can use the operations without
//     needing to compile and use a corresponding .cc file

#include <iostream>
#include <string>

class Sales_item {
  friend bool operator==(const Sales_item&, const Sales_item&);
  friend std::istream& operator>>(std::istream&, Sales_item&);
  friend std::ostream& operator<<(std::ostream&, const Sales_item&);
  // other members as before
public:
  // added constructors to initialize from a string or an istream
    // default constructor needed to initialize members of built-in type
  Sales_item();
  Sales_item(const std::string &book);
  Sales_item(std::istream &is);

public:
  // operations on Sales_item objects
  // member binary operator: left-hand operand bound to implicit this pointer
  Sales_item& operator+=(const Sales_item&);
  // other members as before

public:
  // operations on Sales_item objects
  double avg_price() const;
  bool same_isbn(const Sales_item &rhs) const;

  // private members as before
private:
  std::string isbn;
  unsigned units_sold;
  double revenue;
};

// nonmember binary operator: must declare a parameter for each operand
Sales_item operator+(const Sales_item&, const Sales_item&);

#endif
