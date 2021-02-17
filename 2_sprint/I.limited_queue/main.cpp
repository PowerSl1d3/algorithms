#include <iostream>
#include <vector>
#include <exception>
#include <string>

class MyQueueSized {
private:
    std::vector<int> queue_;
    size_t head_, tail_, current_size_, max_size_;
public:
    explicit MyQueueSized(size_t size)
    : head_(0u)
    , tail_(0u)
    , current_size_(0u)
    , max_size_(size)
    {

        queue_.reserve(size);

    }

    void push(int element);
    [[nodiscard]] int peek() const;
    int pop();
    [[nodiscard]] size_t size() const noexcept;
};

void MyQueueSized::push(int element) {
    if (current_size_ == max_size_) {
        throw std::runtime_error("error");
    }

    queue_[tail_] = element;
    tail_ = (tail_ + 1) % max_size_;
    ++current_size_;
}

int MyQueueSized::peek() const {
    if (current_size_ == 0u) {
        throw std::runtime_error("None");
    }
    return queue_[head_];
}

int MyQueueSized::pop() {
    if (current_size_ == 0u) {
        throw std::runtime_error("None");
    }

    int element = queue_[head_];
    head_ = (head_ + 1) % max_size_;
    --current_size_;

    return element;
}

size_t MyQueueSized::size() const noexcept {
    return current_size_;
}

int main() {

    size_t count, queue_size;
    std::string command;
    int element;

    std::cin >> count >> queue_size;

    MyQueueSized queue(queue_size);

    for (size_t i = 0; i < count; ++i) {

        std::cin >> command;

        try {
            if (command == "push") {

                std::cin >> element;
                queue.push(element);

            } else if (command == "pop") {

                std::cout << queue.pop() << "\n";

            } else if (command == "peek") {

                std::cout << queue.peek() << "\n";

            } else {

                std::cout << queue.size() << std::endl;

            }
        } catch (std::runtime_error& error) {
            std::cout << error.what() << "\n";
        }
    }

    return 0;
}
