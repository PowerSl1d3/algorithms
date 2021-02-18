#include <iostream>
#include <vector>
#include <string>

//ID успешной посылки: 48524436

//Теперь тут кольцевой буфер;) (Действительно, стоило внимательней отнестись к условию задачи)

namespace DataStructure {

    class Deque {
    private:
        std::vector<int> list_;
        size_t head_, tail_, current_size_;
        const size_t max_size_;
        bool push_access() const;
        bool pop_access() const;
        size_t get_prev_iterator(const size_t) const;
        size_t get_next_iterator(const size_t) const;
    public:
        explicit Deque(size_t);
        void push_front(const int);
        void push_back(const int);
        int pop_front();
        int pop_back();

        Deque(const Deque&) = delete;
        Deque(Deque&&) = delete;
        Deque& operator=(const Deque&) = delete;
        Deque& operator=(Deque&&) = delete;
    };

    Deque::Deque(const size_t size_)
            : list_(std::vector<int>(size_))
            , head_(0)
            , tail_(1)
            , current_size_(0)
            , max_size_(size_)
    {
        if (size_ == 1) {
            tail_ = 0;
        }
    }

    bool Deque::push_access() const {

        return current_size_ < max_size_;

    }

    bool Deque::pop_access() const {

        return current_size_ != 0;

    }

    size_t Deque::get_prev_iterator(const size_t iterator) const {
        if (iterator == 0) {
            return max_size_ - 1;
        }

        return iterator - 1;
    }

    size_t Deque::get_next_iterator(const size_t iterator) const {
        return (iterator + 1) % max_size_;
    }

    void Deque::push_front(const int value) {

        if (push_access()) {
            list_[head_] = value;
            head_ = get_prev_iterator(head_);
            ++current_size_;
            return;
        }

        throw std::runtime_error("error");

    }

    void Deque::push_back(const int value) {

        if (push_access()) {
            list_[tail_] = value;
            tail_ = get_next_iterator(tail_);
            ++current_size_;
            return;
        }

        throw std::runtime_error("error");

    }

    int Deque::pop_front() {

        if (pop_access()) {
            --current_size_;
            head_ = get_next_iterator(head_);
            return list_[head_];
        }

        throw std::runtime_error("error");

    }

    int Deque::pop_back() {

        if (pop_access()) {
            --current_size_;
            tail_ = get_prev_iterator(tail_);
            return list_[tail_];
        }

        throw std::runtime_error("error");

    }
}

int main(int argc, char* argv[]) {

    size_t count, max_size;
    std::string command;
    int input_value;

    std::cin >> count >> max_size;

    DataStructure::Deque deque(max_size);

    for (size_t i = 0; i < count; i++) {

        std::cin >> command;

        try {

            if (command == "push_front") {

                std::cin >> input_value;
                deque.push_front(input_value);

            } else if (command == "push_back") {

                std::cin >> input_value;
                deque.push_back(input_value);

            } else if (command == "pop_front") {

                std::cout << deque.pop_front() << "\n";

            } else {

                std::cout << deque.pop_back() << "\n";

            }

        } catch (std::runtime_error& error) {
            std::cout << error.what() << "\n";
        }
    }

    return 0;
}
