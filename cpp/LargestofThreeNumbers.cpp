#include<iostream.h>
#include<conio.h>

int main()
{
    float x1, x2, x3;
    cout << "Enter three numbers: ";
    cin >> x1 >> x2 >> x3;
    if (x1 >= x2 && x1 >= x3)
    {
        cout << "Largest: " << x1;
    }
    if(x2 >= x1 && x2 >= x3)
    {
        cout << "Largest: " << x2;
    }
    if(x3 >= x1 && x3 >= x2)
    {
        cout << "Largest: " << x3;
    }
    getch();
    return 0;
}
