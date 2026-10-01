import std;
using namespace std;

// simple Date (too simple?)
struct Date
{
    int y;    // year
    string m; // month in year
    int d;    // day of month
};

int main()
{
    Date now; // a Date variable (a named object)
    now.y = 2026;
    now.m = "September";
    now.d = 30;

    Date date_of_birth;
    date_of_birth.y = 2010;
    date_of_birth.m = "January";
    date_of_birth.d = 1;

    // Define a function that gets age

    print("Today is {}, {} {}th\n", now.y, now.m, now.d);
}


// struct X {
// int m;
// // ...
// };

// class X {
// public:
// int m;
// // ...
// };
