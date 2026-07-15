#include <iostream>
#include <string>

using namespace std;

/*
// Default arguments are used to provide default values for function parameters. If the caller does not provide a value for a parameter with a default argument, the default value is used instead.
void printMessage(const string& message = "Hello, World!") {
    cout << message << endl;
}

class Neww {
public:
    void printMessage(const string& message = "Hello, class!") {
        cout << message << endl;
    }
};

int main() {
    printMessage(); // Call the function without an argument, using the default value.
    printMessage("Hello, C++!"); // Call the function with a custom argument.
    
    Neww obj;
    obj.printMessage(); // Call the member function without an argument, using the default value.
    obj.printMessage("Hello, object!"); // Call the member function with a custom argument.
    return 0;
}*/


///////////////////////////////////////////////////////////////////

/*

// Function overloading is a feature in C++ that allows multiple functions to have the same name but different parameter lists. The compiler determines which function to call based on the number and types of arguments passed to the function. This allows for more intuitive and flexible code, as functions can be designed to handle different types of input while maintaining a consistent name.

int add(int a, int b) {
    return a + b; // Function to add two integers.
}

double add(double a, double b) {
    return a + b; // Function to add two doubles.
}

int main() {
    int intResult = add(5, 10); // Calls the integer version of add.
    double doubleResult = add(5.5, 10.5); // Calls the double version of add.

    cout << "Integer addition result: " << intResult << endl; // Output the result of integer addition.
    cout << "Double addition result: " << doubleResult << endl; // Output the result of double addition.

    return 0;
} */

//////////////////////////////////////

/*
// constructor and destructor

class MyClass {
public:
    MyClass();  // Constructor
    MyClass(int value);  // Overloaded constructor
    MyClass(string name, int age);  // Another overloaded constructor
    ~MyClass(){
        cout << "Destructor called" << endl; // Destructor to clean up resources when an object is destroyed.
    }// Destructor
};

int main() {
    MyClass obj1; // Calls the default constructor
    MyClass obj2(42); // Calls the overloaded constructor with an integer argument
    MyClass obj3("Alice", 30); // Calls the overloaded constructor with a string and an integer argument    

    return 0;
}*/

////////////////////////////
// stack

class Stack {
    private:
        int top;
        int size;
        int *arr; // Pointer to dynamically allocated array for stack elements.
        static int counter; // Static member variable to keep track of the number of Stack instances.

    public:
        Stack(int s = 10) : size(s), top(-1) { // Constructor to initialize stack
            // here top is initialized to -1, indicating that the stack is empty. The size of the stack is set to the value passed as an argument (default is 10). The arr pointer is allocated memory for an array of integers of the specified size.
            // also I use ++top in push() to increment the top index before adding a new element to the stack. This ensures that the new element is added at the correct position in the array, and it also helps to avoid overwriting existing elements in the stack.
            counter++; // Increment the counter for each new instance of Stack created.
            arr = new int[size]; // Dynamically allocate memory for the stack array.
            cout << "Constructor called" << endl; // Output a message indicating that the constructor has been called.
        }

        ~Stack() { // Destructor to clean up resources
            counter--; // Decrement the counter for each instance of Stack destroyed.
            delete[] arr; // Deallocate the dynamically allocated array to prevent memory leaks.
            cout << "Destructor called" << endl; // Output a message indicating that the destructor has been called.
        }

        void push(int value); // Function to add an element to the stack.
        void pop(); // Function to remove the top element from the stack.
        void print() const; // Function to print the elements of the stack.
        static int getCounter() { return counter; } // Static function to get the current count of Stack instances.
};

// The main function demonstrates the usage of the Stack class. It creates a stack of size 5, pushes three elements onto it, prints the current elements, and then pops the top element from the stack. The destructor is called automatically when the stack object goes out of scope, cleaning up the allocated memory.
// :: is the scope resolution operator in C++. It is used to define member functions of a class outside the class definition. In this case, it is used to define the push, pop, and print member functions of the Stack class. The operator allows us to specify that these functions belong to the Stack class, even though they are defined outside of the class body.
void Stack::push(int value) {
    if (top >= size - 1) {
        cout << "Stack overflow" << endl; // Check for stack overflow
        return;
    }
    arr[++top] = value; // Increment top and add the value to the stack.
}

void Stack::pop() {
    if (top < 0) {
        cout << "Stack underflow" << endl; // Check for stack underflow
        return;
    }
    --top; // Decrement top to remove the top element.
}

void Stack::print() const {
    cout << "Stack elements: ";
    for (int i = 0; i <= top; ++i) {
        cout << arr[i] << " "; // Output each element in the stack.
    }
    cout << endl;
}

int Stack::counter = 0; // Define the static member variable counter outside the class definition.

int main() {
    Stack s(5); // Create a stack of size 5
    s.push(10); // Push elements onto the stack
    s.push(20);
    s.push(30);
    s.print(); // Print the current elements in the stack
    cout << "Number of Stack instances: " << Stack::getCounter() << endl;
    s.pop(); // Pop the top element from the stack
    return 0; // The destructor will be called automatically when the stack object goes out of scope.
}
