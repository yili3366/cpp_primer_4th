#include "Sales_item.h"

Sales_item::Sales_item():
    units_sold(0), revenue(0.0)
{
}

Sales_item::Sales_item(const std::string &book):
    isbn(book), units_sold(0), revenue(0.0)
{
}

Sales_item::Sales_item(std::istream &is)
{
  is >> *this;
}

bool Sales_item::same_isbn(const Sales_item &rhs) const
{
  return isbn == rhs.isbn;
}

inline bool operator==(const Sales_item &lhs, const Sales_item &rhs)
{
  // must be made a friend of Sales_item
  return lhs.units_sold == rhs.units_sold &&
      lhs.revenue == rhs.revenue &&
      lhs.same_isbn(rhs);

}

inline bool operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
  return !(lhs == rhs); // != defined in terms of operator==
}

using std::istream;
using std::ostream;

// assumes that both objects refer to the same isbn
inline Sales_item& Sales_item::operator+=(const Sales_item& rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

// assumes that both objects refer to the same isbn
Sales_item operator+(const Sales_item& lhs, const Sales_item& rhs)
{
  Sales_item ret(lhs);  // copy lhs into a local object that we'll return
  ret += rhs;           // add in the contents of rhs
  return ret;           // return ret by value
}

istream& operator>>(istream& in, Sales_item& s)
{
  double price;
  in >> s.isbn >> s.units_sold >> price;
  // check that the inputs succeeded
  if (in)
    s.revenue = s.units_sold * price;
  else
    s = Sales_item();  // input failed: reset object to default state
  return in;
}

ostream& operator<<(ostream& out, const Sales_item& s)
{
  out << s.isbn << "\t" << s.units_sold << "\t"
      << s.revenue << "\t" <<  s.avg_price();
  return out;
}

inline double Sales_item::avg_price() const
{
  if (units_sold)
    return revenue/units_sold;
  else
    return 0;
}
