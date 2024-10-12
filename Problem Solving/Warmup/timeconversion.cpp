#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) 
{
    string hh,ms,M;
    hh = s.substr(0, 2);
    ms = s.substr(2, 6);
    M = s.substr(8, 2);
    int tmp = stoi(hh);
    if (M == "AM")
    {
        if (tmp == 12) hh ="00";
    }
    else
    {
        if(tmp != 12) hh = to_string(tmp + 12);
    }
    return hh + ms;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
