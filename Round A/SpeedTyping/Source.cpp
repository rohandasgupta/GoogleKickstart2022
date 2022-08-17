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

        vector<string> idealStr;
        splitToChar(line1, &idealStr);

        string line2;
        getline(cin, line2);

        vector<string> typedString;
        splitToChar(line2, &typedString);

        int removedLetters = 0;
        string answer;
        bool bIdealDone = false;
        int n = 0;
        for (string i : typedString)
        {
            if (i == idealStr[n] && !bIdealDone)
            {
                if (n == (idealStr.size() - 1))
                {
                    bIdealDone = true;
                }
                n++;
                
            }
            else
            {
                removedLetters++;
            }
        }

        if (bIdealDone) {
            answer = to_string(removedLetters);
        }
        else {
            answer = "IMPOSSIBLE";
        }

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