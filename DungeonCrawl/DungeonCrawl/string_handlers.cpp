
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>


const std::string WS = " \n\r\t\f\v";

std::string left_trim(const std::string& input)
{
    size_t start = input.find_first_not_of(WS);
    return (start == std::string::npos) ? "" : input.substr(start);
}

std::string right_trim(const std::string& input)
{
    size_t end = input.find_last_not_of(WS);
    return (end == std::string::npos) ? "" : input.substr(0, end + 1);
}

std::string trim(const std::string& input)
{
    return right_trim(left_trim(input));
}

std::vector<std::string> split(std::string command)
{
    std::vector<std::string> words;
    std::istringstream iss(command);
    std::copy(std::istream_iterator<std::string>(iss), 
        std::istream_iterator<std::string>(), 
        std::back_inserter(words)
    );
    return words;
}

