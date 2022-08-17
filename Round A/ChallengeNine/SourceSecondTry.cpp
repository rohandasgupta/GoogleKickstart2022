#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int getCases();
void splitToStringBySpace(string str, vector<string>* vect);
void splitToIntBySpace(string str, vector<int>* vect);
void splitToChar(string str, vector<string>* vect);
void splitToInt(string str, vector<int>* vect);
int stringToInt(string str);
string MinValue(string N, int x);

int main()
{
    int cases = getCases();

    for (int i = 0; i < cases; i++) {
        string line1;
        getline(cin, line1);

        vector<int> num;

        splitToInt(line1, &num);

        int total = 0;

        for (int x : num)
        {
            total += x;
        }

        int numToAdd = 9 - (total % 9);
        bool bNumAdded = false;







        string answernum = MinValue(line1, numToAdd);


        cout << "Case #" << (i + 1) << ": " << answernum << endl;
    }
}

int getCases()
{
    string txtCases;
    getline(cin, txtCases);
    stringstream ss;
    ss << txtCases;
    int cases;
    ss >> cases;
    return cases;
}


void splitToStringBySpace(string str, vector<string>* vect)
{
    string word = "";

    for (auto c : str) {
        if (c == ' ')
        {
            vect->push_back(word);
            word = "";
        }
        else
        {
            word += c;
        }
    }
    vect->push_back(word);
}

void splitToIntBySpace(string str, vector<int>* vect)
{
    string numstr = "";
    stringstream ss;
    int number = 0;

    for (char c : str) {
        if (c == ' ')
        {
            ss << numstr;
            ss >> number;
            vect->push_back(number);
            numstr = "";
            ss.clear();
        }
        else
        {
            numstr += c;
        }
    }
    ss << numstr;
    ss >> number;
    vect->push_back(number);
}

void splitToChar(string str, vector<string>* vect)
{
    string wibblywobbly;
    stringstream ss;
    for (char c : str)
    {
        ss << c;
        ss >> wibblywobbly;
        vect->push_back(wibblywobbly);
        ss.clear();
    }
}

void splitToInt(string str, vector<int>* vect)
{
    int wibblywobbly;
    stringstream ss;
    for (char c : str)
    {
        ss << c;
        ss >> wibblywobbly;
        vect->push_back(wibblywobbly);
        ss.clear();
    }
}

int stringToInt(string str)
{
    stringstream ss;
    int num;
    ss << str;
    ss >> num;
    return num;
}

string MinValue(string N, int X)
{

    // Variable to store length
    // of string N
    int len = N.size();

    // Variable to denote the position
    // where X must be added
    int position = len;

    // If the given string N represent
    // a negative value
    if (N[0] == '-') {
        // X must be place at the last
        // index where is greater than N[i]
        for (int i = len - 1; i >= 1; i--) {
            if ((N[i] - '0') < X) {
                position = i;
            }
        }
    }
    else {
        // For positive numbers, X must be
        // placed at the last index where
        // it is smaller than N[i]
        for (int i = len - 1; i >= 0; i--) {
            if ((N[i] - '0') > X) {
                position = i;
            }
        }
    }
    // Insert X at that position
    N.insert(N.begin() + position, X + '0');

    // Return the string
    return N;
}