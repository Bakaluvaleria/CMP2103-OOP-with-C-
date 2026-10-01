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


public:
    int m; // data member
    int mf(int v) //2
    // function member
    {
        int old = m; //10
        m = v; //m = 2
        return old; // return 10
    }
};


int main (){
    X x; // class instabce of class X
    x.m = 10;
    x.f = 3; // because priovcare
    // cout << x.mf(2) << '\n'; //10
    // cout << x.m << "\n"; //2
    cout << x.f << "\n"

}

// Student
// name
// age
// program
// Specialization

