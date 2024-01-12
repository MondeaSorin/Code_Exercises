#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>

std::string format_str(std::string str)
{
    std::string formatted_string;
    for (auto& c : str)
        if (isalpha(c))
            formatted_string += toupper(c);

    return formatted_string;
}

bool is_palindrome(const std::string& unformatted_string)
{
    std::string s = format_str(unformatted_string);
    std::deque<char> palindrome;
    for (const auto& c : s)
        palindrome.push_back(c);

    auto it = palindrome.begin();
    auto rit = palindrome.rbegin();

    while (it != palindrome.end() && rit != palindrome.rend())
    {
        if (*it != *rit)
            return false;

        it++;
        rit++;
    }

    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for (const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    std::cout << std::endl;
}