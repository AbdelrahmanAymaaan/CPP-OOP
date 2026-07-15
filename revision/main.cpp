
#include <iostream>
# include <string>

using namespace std; // This project uses the C++20 language standard version. instead of using namespace std, it is recommended to use std:: prefix for better code clarity and to avoid potential naming conflicts.


// chapter 1: basics of c++ programming
/*
int main() {

    
    cout << "Hello, World!" << endl; // end1 as endl flushes the output buffer, ensuring that the output is displayed immediately. However, it can be less efficient than using '\n' for large outputs, as it forces a flush every time it is called.
    cout << "hello" ;
    cout << "world\n";  // it will print "helloworld" without any space or newline in between. If you want to separate them, you can add a space or a newline character.

    cout << "hello" << endl; 
    cout << "world" << endl; // This will print "hello" and "world" on separate lines, as endl inserts a newline character and flushes the output buffer.

    cout << 10/3 << endl;
    cout << 10.0/3.0 << endl; // o/p is 3.33333
    //////////////////////////////////////////////////////
    int a = 10;
    int b = 3;
    cout << a++ << endl; // o/p 10
    cout << ++b << endl; // o/p 4
    cout << a << endl; // o/p 11

    if (a > b) {
        cout << "a is greater than b" << endl;
    } 
    else {
        cout << "b is greater than a" << endl;
    }
    ///////////////////////////////////////////////////////////////////
    cout << "Enter two characters from these char (a,b,c):  ";
    char x, y;
    cin >> x >> y;  // multiple i/ps
    switch (x) {
        case 'a':
            cout << "You entered a" << endl;
            break;
        case 'b':
            cout << "You entered b" << endl;
            break;
        case 'c':
            cout << "You entered c" << endl;
            break;
        default:
            cout << "Invalid input" << endl;
    }

    switch (y) {
        case 'a':
            cout << "You entered a" << endl;
            break;
        case 'b':
            cout << "You entered b" << endl;
            break;
        case 'c':
            cout << "You entered c" << endl;
            break;
        default:
            cout << "Invalid input" << endl;
    }
    //////////////////////////////////////////////////////
    for (int i = 0; i < 5; i++) {
        cout << "i: " << i << endl;
    }

    for (int i = 9; i < 15; i++) {
        if (i == 10) {
            continue; // Skip the rest of the loop body when i is 10
        }
        cout << i << " " ; // here " " is used to print a space after the number
    }

    //////////////////////////////////////////
    int j = 0;
    while (j < 5) {
        cout << j << " ";
        j++;
    }
    ////////////////////////////////////////
    int k = 0;
    do {
        cout << k << " ";
        k++;
    } while (k < 5);

    /////////////////////////////////////  
    

    //              exercise                

    int x = 5;
    cout << x++ << " " << ++x << endl;  // 5 7

    cout << 9 / 2 << endl; // o/p 4 as both are int so it will give int o/p
    cout << 9.0 / 2 << endl; // o/p 4.5 as one is double so it will give double o/p

    int a = 10;
    if ( a = 5) { // This is an assignment, not a comparison. It assigns 5 to a and evaluates to true.
        cout << "a is 5" << endl; // This will always execute because the assignment evaluates to true.
    } else {
        cout << "a is not 5" << endl;
    }
    return 0;
} */


// chapter 2: Functions + Scope + References + Pointer Basics
/*
int add(int a, int b); // Function declaration (prototype) for add function. It tells the compiler that there is a function named add that takes two integers and returns an integer. This allows you to call the function before its definition in the code.

int main() {
    cout << "please enter two numbers: ";
    int num1, num2;
    cin >> num1 >> num2;
    cout << "The sum of " << num1 << " and " << num2 << " is: " << add(num1, num2) << endl; // Function call to add with num1 and num2 as arguments. It will print the sum of the two numbers entered by the user.
    //cout << add(num1, num2) << endl; // o/p num1 + num2
    return 0;
}

int add(int a, int b) {
    return a + b;
} */
 
// pass by value vs pass by reference
/*
void change(int x)
{
    x = 100;
}

int main()
{
    int a = 10;
    change(a);
    cout << a; // o/p 10 as a is passed by value, so the original variable remains unchanged.
    return 0;
}
*/
// impoooooooooooooooooooooooortantttttttttttttttttt
/*
void change(int &x) // here we use & to indicate that x is a reference parameter. This means that any changes made to x inside the function will affect the original variable passed to it.
{
    x = 100;
}

int main()
{
    int a = 10;
    change(a);
    cout << a;  // o/p 100 as a is passed by reference, so the original variable is modified.
    return 0;
}
*/


/*
// return many values from a function using reference parameters
// when we use reference parameters? 
// Reference parameters are used when you want a function to modify the original variable passed to it, or when you want to return multiple values from a function. They allow the function to access and modify the original variable directly, rather than working with a copy of it.

void calculate(int a, int b, int &sum, int &product) // Function definition for calculate. It takes two integers a and b, and two reference parameters sum and product. It computes the sum and product of a and b and stores them in the reference parameters.
{
    // previous fn we used reference parameters to modify the original variables passed to the function. In this case, we are using reference parameters to return multiple values (sum and product) from the function. This allows us to compute both values in a single function call and have them available in the calling function.
    sum = a + b; 
    product = a * b;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int sum, product;
    calculate(num1, num2, sum, product); // Function call to calculate with num1 and num2 as arguments. It will compute the sum and product of the two numbers and store them in the reference parameters sum and product.

    cout << "Sum: " << sum << endl; // Output the sum of the two numbers.
    cout << "Product: " << product << endl; // Output the product of the two numbers.

    return 0;
}
*/

/*
// in the following if you modify the value of b, it will also modify the value of a, since b is a reference to a. This is because references in C++ are essentially aliases for the original variable, allowing you to work with the same memory location.
int a = 10;
int &b = a;
*/

/*
// pointer basics
int main() {
    int a = 10;
    int *ptr = &a; // Pointer variable ptr is declared and initialized to the address of variable a. The & operator is used to get the address of a.
    
    cout << "Value of a: " << a << endl; // Output the value of a.
    cout << "Address of a: " << &a << endl; // Output the address of a using the & operator.
    cout << "Value stored in ptr (address of a): " << ptr << endl; // Output the value stored in ptr, which is the address of a.
    cout << "Value pointed to by ptr: " << *ptr << endl; // Output the value pointed to by ptr using the dereference operator *.

    *ptr = 20; // Modify the value of a through the pointer ptr. This changes the value at the address stored in ptr, which is the same as modifying a directly.

    cout << "New value of a after modifying through pointer: " << a << endl; // Output the new value of a after modification through the pointer.

    return 0;
}*/

///////////////////////////
// chapter 3: Arrays + Strings + Struct + Enum

/*
void printArray(int arr[], int size); // Function declaration for printArray. It takes an array of integers and its size as parameters and prints the elements of the array.

int main() {
    // Array declaration and initialization
    int arr[5] = {1, 2, 3, 4, 5}; // An array of integers with 5 elements is declared and initialized.

    // Accessing array elements using a loop
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // Output each element of the array.
    }
    cout << endl;


    int arr2[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr2[i]; // Input elements into the array from the user.
    }

    cout << "Elements in arr2: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " "; // Output each element of the array.
    }
    cout << endl;

    int max = arr2[0];
    for (int i = 1; i < 5; i++) {
        if (arr2[i] > max) {
            max = arr2[i]; // Update max if the current element is greater.
        }
    }

    cout << "Maximum element in arr2: " << max << endl;
    
    printArray(arr, 5); // Function call to printArray with arr and its size as arguments. It will print the elements of the array.

    return 0;

}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " || "; // Output each element of the array.
    }
    cout << endl;
}*/

/*
// strings in c++

int main() {
    string name; // Declare a string variable named name.
    name = "Alice ay"; // Initialize the string variable.
    cout << "Hello, " << name << "!" << endl; // Output a greeting message using the string variable.

    cout << "Enter your name: ";
    // in the following if you type Abd Elrahman it will see only Abd as it will stop reading at the first whitespace. If you want to read the full name including spaces, you can use getline(cin, name) instead of cin >> name.
    cin >> name; // Input a string from the user and store it in the variable name.
    cout << "Hello, " << name << "!" << endl; // Output a greeting message using the user-provided name.


    // it will read the full name including spaces. The cin.ignore() function is used to ignore any leftover newline character in the input buffer before reading the full line of text.
    cout << "Enter your full name: ";
    string name2; // Declare variable to hold full name
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, name2); // Input a full line of text (including spaces) from the user and store it in the variable name.
    cout << "Hello, " << name2 << "!" << endl; // Output a greeting message using the user-provided full name.

    cout << "Length of your full name: " << name2.length() << endl; // Output the length of the full name using the length() method of the string class.
    cout << "size of your full name: " << name2.size() << endl; // Output the size of the full name using the size() method of the string class. Note that length() and size() are equivalent for strings in C++.
    name2.append(" is a good boy"); // Append the string
    //name2.insert(0, "Mr. "); // Insert the string at the beginning
    //name2.replace(0, 3, "Dr. "); // Replace the first 3 characters with "Dr. "
    //name2.erase(0, 4); // Erase the first 4 characters from the string

    // if your name is abdu ayman lotfy it will erase "du a" from the string as it will start from index 2 and erase 3 characters. So the modified string will be "abyman lotfy is a good boy"
    name2.erase(2, 3); // Erase 3 characters starting from index 2 
    cout << "Modified full name: " << name2 << endl; // Output the modified full name after appending and inserting strings.
    
    
    for (char c : name2) { // Range-based for loop to iterate over each character in the string name2.
        cout << c << " "; // Output each character followed by a space.
    }

    return 0;
}
*/

// struct in c++
/*
struct Person {
    string name; // Member variable to hold the person's name.
    int age; // Member variable to hold the person's age.
};

int main() {
    Person person1; // Create an instance of the Person struct named person1.
    person1.name = "Alice";
    person1.age = 30;
    cout << "Name: " << person1.name << ", Age: " << person1.age << endl;

    // array of structs
    Person people[3]; // Declare an array of 3 Person structs named people.
    people[0].name = "Alice";
    people[0].age = 30;
    people[1].name = "Bob";
    people[1].age = 25;
    people[2].name = "Charlie";
    people[2].age = 35;
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << people[i].name << ", Age: " << people[i].age << endl;
    }

    return 0;
}*/

/*
// enum in c++

enum day { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday }; // Define an enumeration named day with values representing the days of the week.

int main() {
    day today = Wednesday; // Declare a variable today of type day and initialize it to Wednesday.
    cout << "Today is: " << today << endl; // Output the integer value corresponding to Wednesday (which is 2, as enums start from 0 by default).

    if (today == Saturday || today == Sunday) { // Check if today is Saturday or Sunday.
        cout << "It's the weekend!" << endl; // Output a message indicating it's the weekend.
    } else {
        cout << "It's a weekday." << endl; // Output a message indicating it's a weekday.
    }

    return 0;
}*/

// chapter 4: Memory Management + Dynamic Memory Allocation + Smart Pointers

/*
// we have stack memory and heap memory. Stack memory is used for static memory allocation, while heap memory is used for dynamic memory allocation. Stack memory is automatically managed, while heap memory requires manual management (allocation and deallocation). Smart pointers are a feature in C++ that help manage dynamic memory automatically, reducing the risk of memory leaks and dangling pointers. They are part of the C++ Standard Library and provide automatic memory management through reference counting or ownership semantics.
int main() {
    // Dynamic memory allocation using new and delete
    int *ptr = new int; // Dynamically allocate memory for an integer on the heap and store its address in ptr.
    *ptr = 42; // Assign the value 42 to the allocated memory.
    cout << "Value: " << *ptr << endl; // Output the value stored at the allocated memory.
    delete ptr; // Deallocate the memory to prevent memory leaks.

    int *arr = new int[5]; // Dynamically allocate an array of 5 integers on the heap.
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1; // Assign values to the dynamically allocated array.
    }
    cout << "Array elements: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // Output the elements of the dynamically allocated array.
    }
    cout << endl;

    int *ptr2 = arr; // Assign the address of the dynamically allocated array to ptr2.
    cout << "Value pointed to by ptr2: " << *ptr2 << endl; // Output the value pointed to by ptr2 (which is the first element of the array).
    cout << " value pointed to by (ptr2 + 1): " << *(ptr2 + 1) << endl; // Output the value of the second element of the array using pointer arithmetic.
    delete[] arr; // Deallocate the memory for the array to prevent memory leaks.

    return 0;
} */


/*
// more pointers
void pointer_demo(); // Function declaration for pointer_demo. It demonstrates the use of null pointers, dangling pointers, and double pointers in C++.
void printArray(int *arr, int size) { // Function definition for printArray. It takes a pointer to an integer (representing the array) and its size as parameters and prints the elements of the array.
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Output each element of the array using pointer arithmetic.
    }
    cout << endl;
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize an array of integers with 5 elements.
    printArray(arr, 5); // Function call to printArray with arr and its size as arguments. It will print the elements of the array.

    pointer_demo();

    return 0;
}

// null pointer means a pointer that does not point to any valid memory location. It is often used to indicate that the pointer is not currently assigned to any object or data. In C++, a null pointer can be represented using the literal `nullptr` (introduced in C++11) or the integer value `0`. Using null pointers helps prevent dereferencing invalid memory addresses, which can lead to undefined behavior and program crashes.
void pointer_demo() {
    int *ptr = nullptr; // Declare a null pointer of type int. It does not point to any valid memory location.

    // dangling pointer means a pointer that points to a memory location that has been deallocated or freed. Accessing a dangling pointer can lead to undefined behavior, as the memory it points to may no longer be valid or may have been reallocated for other purposes. To avoid dangling pointers, it's important to set pointers to nullptr after deleting the memory they point to, and to ensure that pointers are not used after the memory they reference has been freed.
    int *danglingPtr = new int(42); // Dynamically allocate memory for an integer and assign its address to danglingPtr.
    delete danglingPtr; // Deallocate the memory pointed to by danglingPtr, making it a dangling
    danglingPtr = nullptr; // Set the dangling pointer to nullptr to avoid undefined behavior.

    // double pointer means a pointer that points to another pointer. It is used when you need to work with pointers to pointers, such as when dealing with dynamic arrays of pointers or when you want to modify the value of a pointer in a function. A double pointer is declared using two asterisks (**). For example, `int **ptr` declares a double pointer to an integer.
    int a = 10;
    int *p = &a; // Declare a pointer to an integer and initialize it with the address of variable a.
    int **doublePtr = &p; // Declare a double pointer to an integer. It can point to a pointer that points to an integer. Double pointers are often used in scenarios where you need to modify the address stored in a pointer or when working with arrays of pointers.

    cout << "Value of a: " << a << endl; // Output the value of a.
    cout << "Value pointed to by p: " << *p << endl; // Output the value pointed to by p (which is the value of a).
    cout << "Value pointed to by doublePtr: " << **doublePtr << endl; // Output the value pointed to by doublePtr (which is the value of a, accessed through two levels of indirection).

    /////////////////////////////***************     
    const int *ptr1 = &a; // Pointer to a constant integer. You cannot modify the value pointed to by ptr1, but you can change the pointer itself to point to another integer.
    int *const ptr2 = &a; // Constant pointer to an integer. You can modify the value pointed to by ptr2, but you cannot change the pointer itself to point to another integer.

}*/



