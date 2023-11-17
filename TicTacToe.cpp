#include <iostream>
using namespace std;

char a[3][3] = {{'1', '2', '3'} , {'4', '5', '6'}, {'7', '8', '9'}};
string b, c;
int row, column;
char token = 'X';
bool tie = false;

void main1()
{

    cout << "     |       |" << endl;
    cout << a[0][0] << "    |   " << a[0][1] << "   |  " << a[0][2] << endl;
    cout << "_____|_______|_____" << endl;
    cout << "     |       |" << endl;
    cout << a[1][0] << "    |   " << a[1][1] << "   |  " << a[1][2] << endl;
    cout << "_____|_______|_____" << endl;
    cout << "     |       |" << endl;
    cout << a[2][0] << "    |   " << a[2][1] << "   |  " << a[2][2] << endl;
    cout << "     |       |" << endl;
}

void main2()
{
    int digit;
    if (token == 'X')
    {
        cout << "Its " << b << " chance to play";
        cin >> digit;
    }
    if (token == '0')
    {
        cout << "Its " << c << " chance to play";
        cin >> digit;
    }
    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    if (digit == 2)
    {
        row = 0;
        column = 1;
    }
    if (digit == 3)
    {
        row = 0;
        column = 2;
    }
    if (digit == 4)
    {
        row = 1;
        column = 0;
    }
    if (digit == 5)
    {
        row = 1;
        column = 1;
    }
    if (digit == 6)
    {
        row = 1;
        column = 2;
    }
    if (digit == 7)
    {
        row = 2;
        column = 0;
    }
    if (digit == 8)
    {
        row = 2;
        column = 1;
    }
    if (digit == 9)
    {
        row = 2;
        column = 2;
    }
    else if (digit < 1 || digit > 9)
    {
        cout << "Invalid!!..";
    }
    if (token == 'X' && a[row][column] != '0' && a[row][column] != 'X')
    {
        a[row][column] = 'X';
        token = '0';
    }
    else if (token == '0' && a[row][column] != '0' && a[row][column] != 'X')
    {
        a[row][column] = '0';
        token = 'X';
    }
    else
    {
        cout << "There is no empty space" << endl;
        main2();
    }
}

bool main3()
{
    for (int i = 0; i < 3; i++)
    {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] || a[0][i] == a[1][i] && a[1][i] == a[2][i])
            return true;
    }

    if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
    {
        return true;
    }
    if (a[2][0] == a[1][1] && a[1][1] == a[0][2])
    {
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != 'X' && a[i][j] != '0')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

int main()
{
    cout << "Player 1:";
    cin >> b;
    cout << "Player 2:";
    cin >> c;
    cout << b << " will play first" << endl;
    cout << c << " will play second" << endl;
    while (!main3())
    {
        main1();
        main2();
        main3();
    }
    if (token == 'X' && tie == false)
    {
        cout << c << " Wins" << endl;
    }
    else if (token == '0' && tie == false)
    {
        cout << b << " Wins" << endl;
    }
    else
    {
        cout << "Game Draw";
    }
}