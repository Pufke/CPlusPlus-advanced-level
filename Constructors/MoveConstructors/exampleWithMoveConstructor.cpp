#include <iostream>
#include <vector>
using namespace std;

class A{
  int *ptr;
public:
  A(){
    // Default constructor
    cout << "Calling Default constructor\n";
    ptr = new int ;
  }

  A( const A & obj){
    // Copy Constructor
    // copy of object is created
    this->ptr = new int;
    // Deep copying
    cout << "Calling Copy constructor\n";
  }

  A ( A && obj){
    // Move constructor
    // It will simply shift the resources,
    // without creating a copy.
     cout << "Calling Move constructor\n";
    this->ptr = obj.ptr;
    obj.ptr = NULL;
  }

  ~A(){
    // Destructor
    cout << "Calling Destructor\n";
    delete ptr;
  }

};

int main() {

  vector <A> vec;
  vec.push_back(A());

  return 0;

}
/*
When the above code is executed, the move constructor is called instead of the copy constructor.
With the move constructor, the copy of the temporary object of A is avoided. For a large number
of push_back statements, using the move constructor is an efficient choice.
*/
