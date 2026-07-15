# Modern C++ & Object-Oriented Programming (OOP) Handbook

> A complete roadmap for learning **Modern C++** from the ground up, covering C++ fundamentals, memory management, Object-Oriented Programming (OOP), the Standard Template Library (STL), and technical interview preparation.

---

## 📚 Table of Contents

- [About](#-about)
- [Roadmap](#-roadmap)
- [Repository Structure](#-repository-structure)
- [Important Notes](#-important-notes)
- [Coding Best Practices](#-coding-best-practices)
- [Compile & Run](#-compile--run)
- [Learning Objectives](#-learning-objectives)
- [Interview Preparation](#-interview-preparation)
- [License](#-license)

---

# 📖 About

This repository contains organized notes, examples, explanations, and coding exercises for learning **Modern C++**.

The content starts from absolute beginner topics and gradually moves toward advanced concepts such as:

- Memory Management
- Object-Oriented Programming
- Templates
- Exception Handling
- File Handling
- Standard Template Library (STL)

The goal is not only to learn the language, but also to understand **how C++ works internally**, making it easier to solve programming problems and succeed in technical interviews.

---

# 🗺️ Roadmap

## Chapter 1 — C++ Basics

- Introduction to C++
- Program Structure
- Variables
- Data Types
- Input / Output
- Arithmetic Operators
- Assignment Operators
- Comparison Operators
- Logical Operators
- Prefix & Postfix Increment
- if / else
- switch
- Loops
  - for
  - while
  - do-while

---

## Chapter 2 — Functions & References

- Functions
- Function Declaration
- Function Definition
- Return Values
- Parameters
- Pass by Value
- Pass by Reference
- Scope
- Global Variables
- Local Variables
- Default Parameters
- Function Overloading
- References
- Pointer Basics

---

## Chapter 3 — Arrays, Strings & Structures

### Arrays

- Declaration
- Initialization
- Traversing
- User Input
- Passing Arrays to Functions
- Finding Maximum & Minimum

### Strings

- C-style Strings
- std::string
- getline()
- String Functions

### Structures

- struct
- Arrays of Structures

### Enumerations

- enum

### Other Topics

- typedef
- using
- const

---

## Chapter 4 — Memory Management & Pointers

- Memory Layout
- Stack
- Heap
- Dynamic Memory Allocation
- new
- delete
- Dynamic Arrays
- Pointer Arithmetic
- Arrays & Pointers
- nullptr
- Dangling Pointer
- Double Pointer
- Pointer to const
- const Pointer
- Smart Pointers (Introduction)

---

## Chapter 5 — Object-Oriented Programming

- Classes
- Objects
- Access Specifiers
- Constructors
- Destructor
- Encapsulation
- this Pointer
- Static Members

---

## Chapter 6 — Advanced OOP

- Inheritance
- Types of Inheritance
- Polymorphism
- Virtual Functions
- Pure Virtual Functions
- Abstract Classes
- Friend Functions
- Friend Classes

---

## Chapter 7 — Advanced C++

- Operator Overloading
- Templates
- Exception Handling
- File Handling

---

## Chapter 8 — Standard Template Library (STL)

- vector
- pair
- string
- stack
- queue
- deque
- list
- set
- multiset
- map
- unordered_map
- priority_queue
- iterators
- algorithms

---

# 📂 Repository Structure

```text
Modern-CPP-Handbook/

│
├── Chapter01_Basics/
├── Chapter02_Functions/
├── Chapter03_Arrays/
├── Chapter04_Pointers/
├── Chapter05_OOP/
├── Chapter06_Advanced_OOP/
├── Chapter07_Advanced_CPP/
├── Chapter08_STL/
│
├── Exercises/
├── Interview_Questions/
├── CheatSheets/
│
└── README.md
```

---

# 💡 Important Notes

## C++ Standard

This repository uses the **C++20** standard.

Compile with:

```bash
g++ -std=c++20 main.cpp -o main
```

---

## Namespace Best Practice

Although beginners commonly write

```cpp
using namespace std;
```

professional C++ code usually prefers

```cpp
std::cout << "Hello";
std::string name;
```

Using the `std::` prefix improves readability and avoids naming conflicts.

---

## std::endl vs '\n'

```cpp
std::cout << "Hello\n";
```

Only prints a new line.

```cpp
std::cout << "Hello" << std::endl;
```

Prints a new line **and flushes the output buffer**.

For better performance, prefer `'\n'` unless flushing is required.

---

## Integer Division

```cpp
10 / 3
```

Output

```text
3
```

because both operands are integers.

```cpp
10.0 / 3
```

Output

```text
3.333333...
```

because one operand is floating-point.

---

## Prefix vs Postfix

```cpp
x++;
```

Returns the current value, then increments.

```cpp
++x;
```

Increments first, then returns the updated value.

---

## Assignment vs Comparison

Incorrect

```cpp
if (x = 5)
```

Correct

```cpp
if (x == 5)
```

`=` performs assignment.

`==` performs comparison.

---

## getline() vs cin

```cpp
cin >> name;
```

Reads only until the first whitespace.

Example

```
Abd Elrahman
```

Output

```
Abd
```

Use

```cpp
getline(cin, name);
```

to read the entire line.

If `getline()` follows `cin`, clear the input buffer first.

```cpp
cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
```

---

## Common String Functions

- length()
- size()
- append()
- insert()
- replace()
- erase()
- substr()
- find()

---

## Pass by Value vs Pass by Reference

### Pass by Value

```cpp
void func(int x);
```

A copy is passed to the function.

Changes do **not** affect the original variable.

---

### Pass by Reference

```cpp
void func(int& x);
```

The original variable is modified directly.

Use references to

- Avoid unnecessary copying
- Return multiple values
- Improve performance

---

## Returning Multiple Values

Reference parameters make returning multiple values simple.

```cpp
void calculate(int a, int b, int& sum, int& product);
```

---

## Arrays & Pointers

For arrays,

```cpp
arr
```

is equivalent to

```cpp
&arr[0]
```

Likewise,

```cpp
arr[i]
```

is equivalent to

```cpp
*(arr + i)
```

---

## Pointer Best Practices

Always initialize pointers.

Good

```cpp
int* ptr = nullptr;
```

Avoid

```cpp
int* ptr;
```

because it points to an unknown memory location.

---

## Dynamic Memory Rules

Every

```cpp
new
```

must have a matching

```cpp
delete
```

Every

```cpp
new[]
```

must have a matching

```cpp
delete[]
```

Otherwise, your application will leak memory.

---

## Dangling Pointers

After deleting memory

```cpp
delete ptr;
```

always do

```cpp
ptr = nullptr;
```

to prevent undefined behavior.

---

## const Pointers

### Pointer to Constant

```cpp
const int* ptr;
```

- Cannot modify the value
- Can change the address

### Constant Pointer

```cpp
int* const ptr;
```

- Can modify the value
- Cannot change the address

---

## Memory Layout

```text
+----------------------+
| Stack                |
+----------------------+
| Heap                 |
+----------------------+
| Global / Static      |
+----------------------+
| Code                 |
+----------------------+
```

- Stack stores local variables.
- Heap stores dynamically allocated objects.
- Stack memory is automatically managed.
- Heap memory must be managed manually.

---

## Smart Pointers

Modern C++ provides automatic memory management through smart pointers.

- std::unique_ptr
- std::shared_ptr
- std::weak_ptr

Whenever possible, prefer smart pointers over raw pointers.

---

# 🏆 Coding Best Practices

- Prefer `std::` over `using namespace std`.
- Initialize every variable.
- Initialize every pointer with `nullptr`.
- Always free dynamically allocated memory.
- Use `delete[]` for dynamically allocated arrays.
- Prefer references over unnecessary copies.
- Prefer `std::string` over C-style strings.
- Avoid unnecessary global variables.
- Write reusable functions.
- Keep functions small and focused.
- Use meaningful variable names.
- Comment complex logic instead of obvious code.
- Follow consistent naming conventions.

---

# 💻 Compile & Run

Linux / macOS

```bash
g++ -std=c++20 main.cpp -o main
./main
```

Windows (PowerShell)

```powershell
g++ -std=c++20 main.cpp -o main.exe
.\main.exe
```

---

# 🎯 Learning Objectives

After completing this repository, you should be able to:

- Write clean C++ programs.
- Understand memory management.
- Master pointers and references.
- Build applications using Object-Oriented Programming.
- Use the Standard Template Library efficiently.
- Solve programming problems confidently.
- Prepare for technical interviews.
- Build a strong foundation for Data Structures & Algorithms.

---

# 🎓 Interview Preparation

This repository includes material commonly asked in C++ interviews:

- C++ Fundamentals
- Memory Management
- References vs Pointers
- OOP Concepts
- STL
- Coding Exercises
- Common Mistakes
- Best Practices
- Frequently Asked Interview Questions

---

# 🤝 Contributing

Contributions are welcome!

If you'd like to improve explanations, add examples, optimize code, or fix mistakes, feel free to open a Pull Request.

---

# 📜 License

This repository is intended for educational purposes.

Feel free to fork, study, and improve the content.

---

# ⭐ Support

If you find this repository useful, consider giving it a ⭐ on GitHub.

Happy Coding! 🚀