class Calculator
{
private:
    /*data */
public:
    Calculator(/*args */) {}
    ~Calculator() {}
    int PrimeGenerator(int, int);
};
using namespace std;
#include <iostream>

int main(int argc, const char **argv)
{
    cout << "input 2 num" << endl;
    int x, y;
    cin >> x >> y;
    Calculator c; //create in stack
    c.PrimeGenerator(x, y);
    cin.ignore();
    cin.get();
    return 0;
}

int Calculator::PrimeGenerator(int x, int y)
{
    for (int i = 0; i < y; i++)
    { bool prime = true;
        /* code */
        for (int j = 0; j * i <= i; j++)
        {
           
            /* code */
            if (i % j != 0)
            {
                prime = false;
                break;
                /* code */
            }
        }
        if(prime == true){
            cout << i << " ";
        }
    }
}