#include "mastermind.hpp"

#include <random>
#include <chrono>

namespace {

static std::mt19937 gen32;
static std::uniform_int_distribution<mastermind::size_t>
    uniform{0, mastermind::game::num_possible_codes - 1};

} // namespace



// namespace mastermind
void mastermind::launch_game() {
    std::cout << "Welcome to Mastermin!\n";
    std::cout << "If you wish to play, think of a code with 4 digits in range [1, 6] and enter `y`, otherwise enter `n`" << std::endl;
    while (true) {
        std::cout << "[y/n]: ";
        char start;
        std::cin >> start;

        if (start == 'y') {
            std::cout << "\nWell...let's get rollin'\n\n";
            game::start();
            std::cout << "\nThank you for the game!\nI hope you will come to play with me again soon!\n";
            break;
        }
        else if (start == 'n') {
            std::cout << std::endl << "It's a pity you didn't want to play with me!"
                      << std::endl << "Maby next time!" << std::endl;
            break;
        }
        else {
            std::cout << "Sorry. I don't understand." << std::endl
                      << "Please type y/n" << std::endl;
        }
    }
}



// namesapce mastermind::game
void mastermind::game::start() {
    auto code_list = get_code_list();

    for (size_t round = 0; round < num_rounds; round++) {
        if (code_list.empty()) {
            std::cout << "You are cheating!\n";
            break;
        }

        std::cout << "Round: " << round + 1 << std::endl;

        auto guess_idx = get_random_index(code_list.size());
        auto guess = code_list[guess_idx];
        reject_code(code_list, guess_idx);

        auto player_key = get_match_key_from_player(guess);
        if (not player_key.is_valid()) {
            std::cout << "You're dumb!\n";
            break;
        }

        if (player_key.indicates_correct_guess()) {
            std::cout << "I win!" << std::endl << "Your code was: ";
            print_code(guess);
            std::cout << std::endl;
            break;
        }

        if (code_list.empty() or round == num_rounds) {
            std::cout << "You're cheating!\n";
            break;
        }

        size_t idx = 0;
        while (idx != code_list.size()) {
            auto key = get_match_key(code_list[idx], guess);

            if (key == player_key) {
                idx++;
                continue;
            }
            reject_code(code_list, idx);
        }
        std::cout << std::endl;
    }
}


mastermind::game::code_list_t mastermind::game::get_code_list() {
    code_list_t code_list;
    code_list.reserve(num_possible_codes);
    code_t code_gen = {min_color, min_color, min_color, min_color};

    for (size_t i = 0; i < num_possible_codes; i++) {
        code_list.push_back(code_gen);

        size_t k = code_length - 1;
        code_gen[k]++;
        while (code_gen[k] > max_color) {
            code_gen[k] = min_color;
            if (k > 0) {
                k--;
                code_gen[k]++;
            }
        }
    }

    return code_list;
}

const mastermind::game::key_t mastermind::game::get_match_key_from_player(const code_t& guess) {
    std::cout << "Is the code: ";
    print_code(guess);
    std::cout << "?" << std::endl;

    key_t key;
    std::cout << "red: ";
    std::cin >> key.red;
    std::cout << "white: ";
    std::cin >> key.white;

    return key;
}

const mastermind::game::key_t mastermind::game::get_match_key(code_t code, code_t guess) {
    key_t key;

    for (size_t i = 0; i < code_length; i++) {
        if (guess[i] == code[i]) {
            key.red++;
            guess[i] = key_t::marker::guess;
            code[i] = key_t::marker::code;
        }
    }

    for (size_t i = 0; i < code_length; i++) {
        if (guess[i] == key_t::marker::guess)
            continue;

        for (size_t j = 0; j < code_length; j++) {
            if (guess[i] == code[j]) {
                key.white++;
                code[j] = key_t::marker::code;
                break;
            }
        }
    }

    return key;
}



void mastermind::game::print_code(const code_t& code) {
    for (const auto& color : code)
        std::cout << "[" << color << "] ";
}

void mastermind::game::reject_code(code_list_t& code_list, size_t idx) {
    code_list.erase(std::next(code_list.begin(), idx));
}


mastermind::size_t mastermind::game::get_random_index(size_t max_value) {
    return uniform(gen32) % max_value;
}



// mastermind::game::key_t methods
bool mastermind::game::key_t::operator==(const key_t& other) const {
    return red == other.red and white == other.white;
}

bool mastermind::game::key_t::is_valid() const {
    return not ((red + white > code_length) or (red == code_length - 1 and white == 1));
}

bool mastermind::game::key_t::indicates_correct_guess() const {
    return this->is_valid() and red == code_length;
}
