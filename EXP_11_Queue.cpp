//Name : Sharvil Sunil Patil
//Roll No : 2001
//Class : SY CSE A
//Batch : S1

#include <iostream>
#include <vector>

template <typename T>
class Queue {
private:
    std::vector<T> elements;
    size_t frontIndex = 0;

public:
    void enqueue(const T& item) {
        elements.push_back(item);
    }

    void dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty! Cannot dequeue.\n";
            return;
        }
        frontIndex++;
        if (frontIndex > elements.size() / 2) {
            elements.erase(elements.begin(), elements.begin() + frontIndex);
            frontIndex = 0;
        }
    }

    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty! No front element.");
        }
        return elements[frontIndex];
    }

    bool isEmpty() const {
        return frontIndex >= elements.size();
    }

    size_t size() const {
        return elements.size() - frontIndex;
    }
};

int main() {
    Queue<int> intQueue;
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    std::cout << "Front element: " << intQueue.front() << std::endl;
    intQueue.dequeue();

    std::cout << "Front element after dequeue: " << intQueue.front() << std::endl;

    Queue<std::string> stringQueue;
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");

    std::cout << "Front string: " << stringQueue.front() << std::endl;

    return 0;
}
// OUTPUT : 
// Front element: 10
// Front element after dequeue: 20
// Front string: Hello