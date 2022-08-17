#include <iostream>
#include <sstream>
#include <vector>
#include <string>

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

        int length = stringToInt(line1);

        string line2;
        getline(cin, line2);

        string password;
        password = line2;

        bool bhasDigit = false;


        if (password.find("1") != string::npos ||
            password.find("2") != string::npos || 
            password.find("3") != string::npos || 
            password.find("4") != string::npos || 
            password.find("5") != string::npos || 
            password.find("6") != string::npos || 
            password.find("7") != string::npos || 
            password.find("8") != string::npos || 
            password.find("9") != string::npos || 
            password.find("0") != string::npos)
        {
            bhasDigit = true;
        }

        bool bHasLowercase = false;

        if (password.find("a") != string::npos ||
            password.find("b") != string::npos ||
            password.find("c") != string::npos ||
            password.find("d") != string::npos ||
            password.find("e") != string::npos ||
            password.find("f") != string::npos ||
            password.find("g") != string::npos ||
            password.find("h") != string::npos ||
            password.find("i") != string::npos ||
            password.find("j") != string::npos ||
            password.find("k") != string::npos || 
            password.find("l") != string::npos || 
            password.find("m") != string::npos || 
            password.find("n") != string::npos || 
            password.find("o") != string::npos || 
            password.find("p") != string::npos || 
            password.find("q") != string::npos || 
            password.find("r") != string::npos || 
            password.find("s") != string::npos || 
            password.find("t") != string::npos || 
            password.find("u") != string::npos || 
            password.find("v") != string::npos || 
            password.find("w") != string::npos || 
            password.find("x") != string::npos || 
            password.find("y") != string::npos || 
            password.find("z") != string::npos)
        {
            bHasLowercase = true;
        }

        bool bHasCapital = false;

        if (password.find("A") != string::npos ||
            password.find("B") != string::npos ||
            password.find("C") != string::npos ||
            password.find("D") != string::npos ||
            password.find("E") != string::npos ||
            password.find("F") != string::npos ||
            password.find("G") != string::npos ||
            password.find("H") != string::npos ||
            password.find("I") != string::npos ||
            password.find("K") != string::npos ||
            password.find("L") != string::npos ||
            password.find("M") != string::npos ||
            password.find("N") != string::npos ||
            password.find("O") != string::npos ||
            password.find("P") != string::npos ||
            password.find("Q") != string::npos ||
            password.find("R") != string::npos ||
            password.find("S") != string::npos ||
            password.find("T") != string::npos ||
            password.find("U") != string::npos ||
            password.find("V") != string::npos ||
            password.find("W") != string::npos ||
            password.find("X") != string::npos ||
            password.find("Y") != string::npos ||
            password.find("Z") != string::npos ||
            password.find("J") != string::npos)
        {
            bHasCapital = true;
        }

        bool bHasSpecial = false;

        if (password.find("#") != string::npos ||
            password.find("*") != string::npos ||
            password.find("@") != string::npos ||
            password.find("&") != string::npos)
        {
            bHasSpecial = true;
        }

        if (!bhasDigit)
        {
            password += "1";
            length++;
        }
        if (!bHasLowercase)
        {
            password += "a";
            length++;
        }
        if (!bHasCapital)
        {
            password += "A";
            length++;
        }
        if (!bHasSpecial)
        {
            password += "@";
            length++;
        }
        if (length < 7)
        {
            for (int l = 0; l < 7 - length; l++)
            {
                password += "a";
            }
        }

        cout << "Case #" << (i + 1) << ": " << password << endl;
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

