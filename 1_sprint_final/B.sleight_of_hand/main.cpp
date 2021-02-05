#include <iostream>
#include <cstdint>
#include <string>
#include <vector>

//ID удачной посылки: 47960600

std::vector<std::string> fill_trainer_from_input() {

    std::vector<std::string> trainer(4);

    for(std::string& row : trainer) {
        std::cin >> row;
    }

    return trainer;

}

std::vector<uint8_t> count_buttons(const std::vector<std::string>& trainer) {

    std::vector<uint8_t> counter_of_buttons(9, 0);

    for(const std::string& row : trainer) {
        for (const char button : row) {
            if (button != '.') {
                counter_of_buttons[button - '0' - 1]++;
            }
        }
    }

    return counter_of_buttons;

}

uint8_t play_game(uint8_t hands, const std::vector<uint8_t>& counter_of_buttons) {

    uint8_t score = 0;

    for (const uint8_t button : counter_of_buttons) {
        if (button && button <= hands) {
            score++;
        }
    }

    return score;

}

int main() {

    uint8_t hands;

    std::cin >> hands;
    std::cin.ignore();
    hands = (hands - '0') * 2;

    const std::vector<std::string> trainer = fill_trainer_from_input();

    const std::vector<uint8_t> counter_of_buttons = count_buttons(trainer);

    const uint8_t score = play_game(hands, counter_of_buttons);

    std::cout << static_cast<uint32_t>(score);

    return 0;
}
