//
// Created by hty on 2021/9/2.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

char toLower(char ch);
string & ToLower(string & str);
void show(const string & str);

int main()
{
    vector<string> words;
    cout << "Enter words, 'q' to quit: \n";
    string input;
    while (cin >> input && input != "q")
        words.push_back(input);

    cout << "You entered the following words: \n";
    for_each(words.begin(), words.end(), show);
    cout << endl;

    set<string> wordSet;
    transform(words.begin(), words.end(), insert_iterator< set<string> > (wordSet, wordSet.begin()), ToLower);
    cout << "Alphabetic list of words: \n";
    for_each(wordSet.begin(), wordSet.end(), show);
    cout << endl;

    map<string, int> wordMap;
    set<string>::iterator si;
    for (si = wordSet.begin(); si != wordSet.end(); si++)
        wordMap[*si] = count(words.begin(), words.end(), *si);

    cout << "Word frequency: \n";
    for (si = wordSet.begin(); si != wordSet.end(); si++)
        cout << *si << ": " << wordMap[*si] << endl;
}

char toLower(char ch) { return tolower(ch); }

string & ToLower(string & str)
{
    transform(str.begin(), str.end(), str.begin(), toLower);
    return str;
}

void show(const string & str)
{
    cout << str << " ";
}