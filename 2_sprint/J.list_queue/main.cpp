#include <iostream>
#include <exception>
#include <memory>
#include <string>

class Queue {
private:
    struct Node {
        Node(int, std::shared_ptr<Node>);
        Node(int);

        int value_;
        std::shared_ptr<Node> next_;
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;
    size_t size_;
public:
    explicit Queue();
    void push(int);
    int pop();
    size_t size() const noexcept;
};

Queue::Node::Node(int value, std::shared_ptr<Node> next)
        : value_(value)
        , next_(next)
{}

Queue::Node::Node(int value)
: value_(value)
, next_(nullptr)
{}

Queue::Queue()
:head_(nullptr)
,tail_(nullptr)
,size_(0u)
{}

void Queue::push(int value) {

    std::shared_ptr<Node> new_end = std::make_shared<Node>(value);

    if (tail_ != nullptr) {
        tail_->next_ = new_end;
    }
    tail_ = new_end;

    if (head_ == nullptr) {
        head_ = tail_;
    }

    ++size_;

}

int Queue::pop() {
    if (head_ == nullptr) {
        throw std::runtime_error("error");
    }

    int value = head_->value_;
    head_ = head_->next_;

    if (head_ == nullptr) {
        tail_ = nullptr;
    }

    --size_;

    return value;
}

size_t Queue::size() const noexcept {
    return size_;
}

int main() {

    Queue queue;
    size_t count;
    std::string command;
    int element;

    std::cin >> count;

    for (size_t i = 0; i < count; ++i) {

        std::cin >> command;

        try {

            if (command == "put") {

                std::cin >> element;
                queue.push(element);

            } else if (command == "get") {

                std::cout << queue.pop() << "\n";

            } else {

                std::cout << queue.size() << "\n";

            }

        } catch (std::runtime_error& error) {

            std::cout << error.what() << "\n";

        }
    }

    return 0;
}
