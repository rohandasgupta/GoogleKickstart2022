#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int getCases();
void splitToStringBySpace(string str, vector<string>* vect);
void splitToIntBySpace(string str, vector<int>* vect);
void splitToChar(string str, vector<string>* vect);
void splitToInt(string str, vector<int>* vect);
int stringToInt(string str);
float findMedian(vector<int> a, int n);

int main()
{
    int cases = getCases();

    for (int i = 0; i < cases; i++) {
        string line1;
        getline(cin, line1);
        vector<int> line1arrint;
        splitToIntBySpace(line1, &line1arrint);
        string line2;
        getline(cin, line2);
        vector<int> participants;
        splitToIntBySpace(line2, &participants);

        int regions = line1arrint[0];

        int categories = line1arrint[1];

        sort(participants.begin(), participants.end());

        float total = 0;

        for (int i = 0; i < categories-1; i++)
        {
            total += participants[participants.size()-1];
            participants.pop_back();
        }

        total += findMedian(participants, participants.size());

        cout << "Case #" << (i + 1) << ": " << total << endl;
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

float findMedian(vector<int> a, int n)
{

    // If size of the arr[] is even
    if (n % 2 == 0) {

        float x = a[n/2];
        float y = a[(n / 2) - 1];
        float z = (x + y) / 2;
        return z;
    }

    // If size of the arr[] is odd
    else {
        float z = a[(n - 1) / 2];
        return z;
    }
}