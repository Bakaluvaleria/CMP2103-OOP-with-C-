import std;
using namespace std;

class X
{

// private:
//     int f;
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
    cout << x.mf(2) << '\n'; //10
    cout << x.m << "\n"; //2
}

// Student
// name
// age
// program
// Specialization

