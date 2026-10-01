import std;
using namespace std;

// Ckass
// private
// public
// memebers
// access

// int g;

class X
{

private:
    int f; // private

    string mf_string()
    {
        string v = "hello there";
        return v;
    }

public:
    int m;    // public data member
    void mf() // 2
              // function member

    {
        // int old = m; // 10
        // f = 5;
        // m = v - f;  // m = 2
        // return old; // return 10
        cout << mf_string() << "\n";
        // return mf_string;
    }
};

int main()
{
    X x; // class instabce of class X
    // x.m = 10;
    // x.f = 3; // return error because because priovcare
    // cout << x.mf(2) << '\n'; //10
    // cout << x.m << "\n"; // 2
    x.mf();
    // cout << x.m();
}

// Student
// name
// age
// program
// Specialization
