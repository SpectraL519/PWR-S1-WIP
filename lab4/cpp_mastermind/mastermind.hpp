#pragma once

#include <iostream>
#include <cstdint>
#include <cmath>
#include <array>
#include <vector>




namespace mastermind {

using size_t = uint16_t;

void launch_game();


// detail
namespace game {

constexpr size_t num_rounds = 8;

constexpr size_t min_color = 1;
constexpr size_t max_color = 6;
constexpr size_t num_colors = max_color - min_color + 1;

constexpr size_t code_length = 4;
const size_t num_possible_codes = (size_t)std::pow(num_colors, code_length);

using code_t = std::array<size_t, code_length>;
using code_list_t = std::vector<code_t>;

struct key_t {
    size_t red = 0;
    size_t white = 0;

    inline bool operator==(const key_t& other) const;

    inline bool is_valid() const;
    inline bool indicates_correct_guess() const;

    enum marker {
        guess = 0,
        code = 8,
    };
};


void start();

[[nodiscard]] code_list_t get_code_list();
[[nodiscard]] const key_t get_match_key_from_player(const code_t& guess);
[[nodiscard]] const key_t get_match_key(code_t code, code_t guess);

void print_code(const code_t& code);
inline void reject_code(code_list_t& code_list, size_t idx);

[[nodiscard]] inline size_t get_random_index(size_t max_value);

} // namespace game

} // namespace
