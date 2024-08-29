

#include <iostream>
#include <string>
#include <algorithm> // For std::remove
#include <sstream>   // For std::stringstream

std::string remove_duplicates(const std::string& input_string) {
    std::string output_string = input_string;
    output_string.erase(std::remove(output_string.begin(), output_string.end(), '|'), output_string.end());
    return output_string;
}

std::string process_input(const std::string& input_string) {
    std::string output_string = "";
    size_t cursor_position = 0;

    for (char ch : input_string) {
        if (ch == '<') {
            if (cursor_position > 0) {
                output_string.erase(cursor_position - 1, 1);
                --cursor_position;
            }
        } else if (ch == '[') {
            cursor_position = 0;
        } else if (ch == ']') {
            cursor_position = output_string.size();
        } else {
            output_string.insert(cursor_position, 1, ch);
            ++cursor_position;
        }
    }

    return remove_duplicates(output_string);
}
std::string process_input(const std::string &input_string) {
    std::string output_string = "";
    size_t cursor_position = 0;

    for (char ch : input_string) {
        if (ch == '<') {
            if (cursor_position > 0) {
                output_string.erase(cursor_position - 1, 1);
                --cursor_position;
            }
        } else if (ch == '[') {
            cursor_position = 0;
        } else if (ch == ']') {
            cursor_position = output_string.size();
        } else {
            output_string.insert(cursor_position, 1, ch);
            ++cursor_position;
        }
    }

    return output_string;
}

int main() {
    int T;
    std::cin >> T;
    std::cin.ignore(); // Ignore the newline after the integer input

    for (int i = 0; i < T; ++i) {
        std::string input_string;
        std::getline(std::cin, input_string);

        std::string output_string = process_input(input_string);

        std::cout << output_string << std::endl;
    }

    return 0;
}
