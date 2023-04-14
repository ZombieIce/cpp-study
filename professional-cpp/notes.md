## chapter1
#### Three-Way Comparisons
```<=>``` the three-way comparison operator can be used to determine the order of two values. it returns an enumeration-like type, defined in ```<compare>``` and in the std namespace.
- if the operands are integrals types, the result is a so-called strong ordering and can be one of the following:
  - ```strong_ordering::less```: First operand less than second
  - ```strong_ordering::greater```: First operand greater than second
  - ```strong_ordering::equal```: Equal operands
- If the operands are floating-point types, the result is a partial ordering:
  - ```partial_ordering::less```: First operand less than second
  - ```partial_ordering::greater```: First operand greater than second
  - ```partial_ordering::equivalent```: Equal operands
  - ```partial_ordering::unorderd```: if one or both of the operands is not-a-number
- There is also a weak ordering, which is an additional ordering type that you can choose from to implement three-way comparisons for your own types.
  - ```weak_ordering::less```: First operand less than second
  - ```weak_ordering::greater```: First operand greater than second
  - ```weak_ordering::equivalent```: Equal operands 
- ```<compare>``` provides named comparison functions to interpret the result of an ordering. These functions are std::is_eq(), is_neq(), is_lt(), is_lteq(), is_gt(), and is_gteq() returning true if an ordering represents ==, !=, <, <=, >, or >= respectively, false otherwise.
#### std::optional
```std::optional```, defined in ```<optional>```, holds a value of a specific type, or nothing. It is introduced already in this first chapter as it is a useful type to use in some of the examples throughout the book. Basically, ```optional``` can be used for parameters of a function if you want to allow for values to be optional. It is also often used as a return type from a function if the function can either return something or not. 
#### Initializer Lists
Initializer lists are defined in ```<initializer_list>``` and make it easy to write functions that can accept a variable number of arguments. The std::initializer_list type is a class template, and so it requires you to specify the type of elements in the list between angle brackets, similar to how you specify the type of object stored in a vector.
#### Designated Initializers
- Data members that have an in-class initializer will get that value.
- Data members that do not have an in-class initializer are zero initialized.
```c++
struct Employee{
  char firstInitial;
  char lastInitial;
  int employeeNumber;
  int salary { 75000 };
};
```
Using designated initializers, this can be written as follows:
```c++
Employee anEmployee {
  .firstInitial = 'J',
  .lastInitial = 'D',
  .employeeNumber = 42,
  .salary = 8000,
}
```
A final benefit of using designated initializers is that when members are added to the data structure, existing code using designated initializers keeps working. The new data members will just be initial- ized with their default values.
####  Working with Pointer
After you are finished with your dynamically allocated memory, you need to deallocate the memory using the delete operator. To prevent the pointer from being used after having deallocated the memory it points to, it’s recommended to set it to nullptr.
To prevent memory leaks, every call to new should be paired with a call to delete, and every call to new[] should be paired with a call to delete[]. Not calling delete or delete[], or mismatching calls, results in memory leaks or worse.
#### const
Here is another easy-to-remember rule to figure out complicated variable declarations: read from right to left. For example, int* const ip reads from right to left as “ip is a const pointer to an int.” Further, int const* ip reads as “ip is a pointer to a const int,” and const int* ip reads as “ip is a pointer to an int constant.”
#### constexpr Keyword
The constexpr keyword discussed in the previous section specifies that a function could be executed at compile time, but it does not guarantee compile-time execution. 
Declaring a function as constexpr imposes quite a lot of restrictions on what the function can do because the compiler has to be able to evaluate the function at compile time. For example, a constexpr function is allowed to call other constexpr functions but is not allowed to call any non- constexpr functions.
```c++
class Rect {
public:
  constexpr Rect(size_t width, size_t height): m_width{width}, m_height{height}{}
  constexpr size_t getArea() const { return m_width * m_height;}
private:
  size_t m_width{0}, m_height{0};
}

constexpr Rect r { 8, 2};
int myArray[r.getArea()]; //ok
```
#### consteval Keyword
If you really want the guarantee that a function is always evaluated at compile time, you need to use the C++20 consteval keyword to turn a function into a so-called immediate function.
#### References
Professional C++ code, including much of the code in this book, uses references extensively. A refer- ence in C++ is an alias for another variable. All modifications to the reference change the value of the variable to which it refers. You can think of references as implicit pointers that save you the trouble of taking the address of variables and dereferencing the pointer. Alternatively, you can think of refer- ences as just another name for the original variable. You can create stand-alone reference variables, use reference data members in classes, accept references as parameters to functions and methods, and return references from functions and methods.
**A reference variable must always be initialized when it’s created.**
A reference always refers to the same variable to which it is initialized; references cannot be changed once they are created.
```c++
int x { 3 }, y { 4 }, z{ 5 };
int& xRef { x };
int& zRef { z };
xRef = y; // changes value of x to 4. Doesn't make xRef refer to y.
zRef = xRef; // assingns values, not references.
```
You cannot create a reference to an unnamed value, such as an integer literal, unless the reference is to a const value. 
```c++
int& unnameRef1 { 5 }; // Does not compile
const int& unnameRef2 { 5 }; // Works as expected
```
#### Pass-by-Reference vs. Pass-by-Value
Pass-by-reference avoids copying the arguments to the function, providing two additional benefits:
- Efficiency: Large objects could take a long time to copy. Pass-by-reference passes only a reference to the object into the function.
- Support: Not all classes allow pass-by-value
#### Copy List vs. Direct List Initialization
- Copy list initalization: T obj = { arg1, arg2, ...};
- Direct list initalization: T obj { arg1, arg2, ...};
## Chapter 9 Mastering Classes and Objects
#### Handling Moving with Semantics
In C++, an lvalue is something of which you can take an address, for example, a named variable. The name comes from the fact that lvalues can appear on the left-hand side of an assignment. An rvalue, on the other hand, is anything that is not an lvalue, such as a literal, or a temporary object or value.
The only thing ```std::move()``` does is cast an lvalue to an rvalue reference; that is, it does not do any actual moving.