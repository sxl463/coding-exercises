#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

template <typename T, typename U>
struct CompareByMember {
    // This is a pointer-to-member, it represents a member of class T
    // The data member has type U
    U T::*field;
    CompareByMember(U T::*f) : field(f) {}
    bool operator()(const T &lhs, const T &rhs) {
        return lhs.*field < rhs.*field;
    }
};

struct Test {
    int a;
    int b;
    std::string c;
    Test(int a, int b, std::string c) : a(a), b(b), c(c) {}
};

// for convenience, this just lets us print out a Test object
std::ostream &operator<<(std::ostream &o, const Test &t) {
    return o << t.c;
}

int main() {
    std::vector<Test> vec;
    vec.push_back(Test(1, 10, "y"));
    vec.push_back(Test(2, 9, "x"));

    // sort on the string field
    std::sort(vec.begin(), vec.end(), 
        CompareByMember<Test,std::string>(&Test::c));
    std::cout << "sorted by string field, c: ";
    std::cout << vec[0] << " " << vec[1] << "\n";

    // sort on the first integer field
    std::sort(vec.begin(), vec.end(), 
        CompareByMember<Test,int>(&Test::a));
    std::cout << "sorted by integer field, a: ";
    std::cout << vec[0] << " " << vec[1] << "\n";

    // sort on the second integer field
    std::sort(vec.begin(), vec.end(), 
        CompareByMember<Test,int>(&Test::b));
    std::cout << "sorted by integer field, b: ";
    std::cout << vec[0] << " " << vec[1] << "\n";
}
