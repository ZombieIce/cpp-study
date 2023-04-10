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
