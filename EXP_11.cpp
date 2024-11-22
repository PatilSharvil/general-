//Name : Sharvil Sunil Patil
//Roll No : 2001
//Class : SY CSE A
//Batch : S1

#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& item) {
        elements.push_back(item);
    }

    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty! Cannot pop.\n";
            return;
        }
        elements.pop_back();
    }

    T TOS() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty! No top element.");
        }
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Top element: " << intStack.TOS() << std::endl;
    intStack.pop();

    std::cout << "Top element after pop: " << intStack.TOS() << std::endl;

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    std::cout << "Top string: " << stringStack.TOS() << std::endl;

    return 0;
}
// OUTPUT : 
// Top element: 30
// Top element after pop: 20
// Top string: World