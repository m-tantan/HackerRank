/**
 * Question:
 * Given a time in -hour AM/PM format, convert it to military (24-hour) time.
 *
 *   Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a
 *   24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.
 *
 *   Input Format
 *
 *   A single string  containing a time in -hour clock format (i.e.:  or ),
 *   where  and .
 *
 *   Output Format
 *
 *   Convert and print the given time in -hour format, where .
 *
 *   Sample Input
 *
 *   07:05:45PM
 *   Sample Output
 *
 *   19:05:45*/


#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>

using std::cout ;
using std::endl ;
using std::string;
using std::cin;

using std::to_string;
using std::ofstream;


string timeConversion(string s) {
    string h = "", m = "", sc = "";
    string frontZero = "0";

    int nColons = 0;
    bool pastNoon = false;
    for (char* c = &s[0]; *c != '\0'; ++c)
    {

        if (*c == 'P')
        {
            pastNoon = true;
            break;
        }
        if(*c == 'A') {
            break;
        }
        if (*c == ':')
        {
            ++nColons;
            continue;
        }
        if (nColons == 0)
        {
            h += *c;
        }
        if (nColons == 1)
        {
            m += *c;
        }
        if (nColons == 2)
        {
            sc += *c;
        }

    }

    int hours = stoi(h);
    if (pastNoon)
    {
        if (hours != 12)
            hours += 12;

        if (hours == 36)
        {
            hours = 0;
        }

    }
    else {
        if (hours == 12) {
            hours = 0;
        }
    }
    if (hours == 0)
    {
        h = to_string(0) + to_string(0);
    }
    else {
        h = to_string(hours);
    }
    if (h.length() == 1)
        h = to_string(0) + h;


    return h + ":" + m + ":" + sc;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout<<  result << "\n";

    fout.close();

    return 0;
}
