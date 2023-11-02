/*
Даны две строки s и t. Строка s состоит из 26 различных строчных букв латинского алфавита
и задаёт отношения порядка между буквами — буква si считается меньше буквы sj, если i < j.
Необходимо отсортировать строку t в соответствии с заданным отношением порядка.

В первой строке вводится строка s (|s|=26)
— строка, задающая отношение порядка между строчными буквами латинского алфавита.
Во второй строке вводится строка t (1≤|t|≤100)
— строка, которую необходимо отсортировать в соответствии с заданным отношением порядка.

Выведите отсортированную строку t.
 */


#include <iostream>
#include <vector>
#include <map>

std::map<char, int> sort_rules(std::string& s)
{
    std::map<char, int> alphabet;
    for (int i = 0; i < 26; i++)
        alphabet[s[i]] = i;
    return alphabet;
}

void sort_string(std::string& t, const std::map<char, int>& alphabet)
{
    std::vector<std::pair<char, int>> ans(26);
    for (char i : t)
    {
        int position = alphabet.at(i);
        ans[position].first = i;
        ans[position].second++;
    }
    t.clear();
    for (int i = 0; i < ans.size(); i++)
    {
        if(ans[i].first)
        {
            while(ans[i].second > 0)
            {
                t += ans[i].first;
                ans[i].second--;
            }
        }
    }
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    std::map<char, int> alphabet = sort_rules(s);
    sort_string(t, alphabet);
    std::cout << t;
    return 0;
}
