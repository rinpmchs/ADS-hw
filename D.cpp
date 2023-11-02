/*
Палиндром — число, буквосочетание, слово или текст, одинаково читающееся в обоих направлениях.

На вход программы поступает набор больших латинских букв.
Разрешается переставлять и удалять буквы. Требуется из данных букв составить палиндром наибольшей длины.
Если таких палиндромов несколько, то выбрать первый из них в алфавитном порядке.

В первой строке входных данных содержится число N (1 <= N <= 100000).
Во второй строке задается последовательность из N больших латинских букв.
*/

#include <iostream>
#include <vector>

char keep_one_odd(std::vector<int>& freq)
{
    char odd_char = '\0';
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            if (odd_char == '\0') {
                odd_char = i + 'A';
            } else {
                freq[i]--;
            }
        }
    }
    return odd_char;
}


std::string palindrome(int n, std::string str)
{
    std::string pal;
    std::vector<int> freq(26);
    for (int i = 0; i < n; i++)
    {
        freq[str[i] - 'A']++;
    }
    char middle_char = keep_one_odd(freq);
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j <  freq[i]/2; j++)
            pal += (i + 'A');
    }
    if (middle_char)
        pal += middle_char;
    for (int i = 25; i >= 0; i--)
    {
        for (int j = 0; j <  freq[i]/2; j++)
            pal += (i + 'A');
    }
    return pal;
}


int main()
{
    int n;
    std::string str;

    std::cin >> n;
    std::cin >> str;

    std::cout << palindrome(n, str);
    return 0;
}