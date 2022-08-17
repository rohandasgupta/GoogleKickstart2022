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

int main()
{
    int cases = getCases();

    for (int i = 0; i < cases; i++) {
        string line1;
        getline(cin, line1);

        vector<int> bounds;
        splitToIntBySpace(line1, &bounds);

        int interestingInts = 0;

        for (int i = bounds[0]; i <= bounds[1]; i++)
        {
            vector<int> splitI;
            splitToInt(to_string(i), &splitI);

            int sum = 0;
            int product = 1;
            for (int x : splitI)
            {
                sum += x;
                product = product * x;
            }

            if (product%sum == 0)
            {
                interestingInts++;
            }
        }

        string answer = to_string(interestingInts);

        cout << "Case #" << (i + 1) << ": " << answer << endl;
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