#include <iostream>
#include <string>

using namespace std;

// friend function 

class Student {
    private:
        string name;
        int age;

    public:
        Student(string n, int a) : name(n), age(a) {}
        friend void printStudentInfo(const Student& s);
        void printStudentInfoo(const Student& s);
};

void printStudentInfo(const Student& s) {
    cout << "Name: " << s.name << ", Age: " << s.age << endl;
}

void Student::printStudentInfoo(const Student& s) {
    cout << "Name: " << s.name << ", Age: " << s.age << endl;
}


int main() {
    Student ayman("Jose Morinho", 20);
    printStudentInfo(ayman);
    ayman.printStudentInfoo(ayman);
    return 0;
}
        