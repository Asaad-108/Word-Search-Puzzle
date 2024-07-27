#include <iostream>
using namespace std;
#include <fstream>
#include <windows.h>
const int rows = 12;
const int columns = 18;
int length(const char *ptr)
{
    int count = 0;
    if (ptr == nullptr)
    {
        return 0;
    }
    else
    {
        for (int i = 0; ptr[i] != '\0'; i++)
        {
            count++;
        }
        return count;
    }
}
char *copy(const char *ptr)
{
    int l = length(ptr);
    char *newPtr = new char[l + 1];
    for (int i = 0; i < l + 1; i++)
    {
        newPtr[i] = ptr[i];
    }
    return newPtr;
}
bool compare(const char *ptr1, const char *ptr2)
{
    if (length(ptr1) == length(ptr2))
    {
        for (int i = 0; i < length(ptr1); i++)
        {
            if (ptr1[i] != ptr2[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}
char **dynamic_mem(const int &_rows, const int &_cols)
{
    char **ptr = NULL;
    ptr = new char *[_rows];
    for (int i = 0; i < _rows; i++)
    {
        ptr[i] = new char[_cols];
    }
    return ptr;
}
void readPuzzle(ifstream &fin, char **&ptr)
{
    cout << "hello World" << endl;
    char c;
    if (fin.is_open())
    {
        cout << "hello World" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                fin >> c;
                ptr[i][j] = c;
            }
        }
    }
    cout << "hello World" << endl;
}
void readDictionary(ifstream &fin, char **ptr, int &numWords)
{
    int i = 0;
    while (i < numWords && !fin.eof())
    {
        fin.getline(ptr[i], 100, '\n');
        i++;
    }
}
void displayPuzzle(char **ptr, const int &rows, const int &columns)
{
    cout << "hello World" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << ptr[i][j] << "\t";
        }
        cout << endl;
    }
}
int game(int &numWords, char **&puzzle, char *&word, char **&dic, int &size)
{
    int life = 3;
    int score = 0;
    displayPuzzle(puzzle, rows, columns);
    char y;
    cout << "lifeline are:" << life << endl;
    do
    {
        bool check = false;
        cout << "Guess the word:" << endl;
        cin.getline(word, size, '\n');
        for (int i = 0; i < numWords; i++)
        {
            if (compare(word, dic[i]))
            {
                score = score + 10;
                cout << "congrats" << endl;
                check = true;
                break;
            }
        }
        if (check == false)
        {
            cout << "bad luck this time , try again:" << endl;
            life--;
            cout << "life:" << life << endl;
        }
        cout << "you want to continue  guessing the words ? if yes press Y/y if no press N/n" << endl;
        cin >> y;
        cin.ignore();
    } while (y != 'N' && y != 'n' && life > 0 && score <= 90);
    return score;
}
void resume()
{
    /*code*/
}
void highscore()
{
    /*code*/
}
void hint()
{
    /*code*/
}
void delete_2d(char **ptr, const int &rows)
{

    for (int i = 0; i < rows; i++)
    {
        delete[] ptr[i];
    }
    delete[] ptr;
}
int main()
{
    int numWords = 0;
    int size = 100;
    char **dic;
    char **puzzle;
    puzzle = dynamic_mem(rows, columns);
    ifstream fin;
    fin.open("dictionary.txt");
    if (fin.is_open())
    {
        fin >> numWords;
        dic = dynamic_mem(numWords, size);
        int i = 0;
        fin.ignore();
        readDictionary(fin, dic, numWords);
    }
    fin.close();
    cout << "	WORD PUZZLE GAME	" << endl;
    cout << "loading..." << endl;
    cout << "\xdb ";
    Sleep(1000);
    cout << "\xdb ";
    Sleep(1000);
    cout << "\xdb ";
    Sleep(1000);
    cout << "\xdb ";
    Sleep(1000);
    cout << "\xdb ";
    Sleep(1000);
    cout << "\xdb " << endl;
    Sleep(1000);
    system("cls");
    system("color 7c");
    ifstream file;
    file.open("words.txt");
    readPuzzle(file, puzzle);
    file.close();
    displayPuzzle(puzzle, rows, columns);
    int scr = 0;
    int num = 0;
    char choice;
    char *word = new char[size];
    do
    {
        system("cls");
        do
        {
            cout << "press 1: to start the new game " << endl;
            cout << "press 2: to start the resume game " << endl;
            cout << "press 3: to see the high score " << endl;
            cin >> num;
            cin.ignore();
            if (num != 1 && num != 2 && num != 3)
            {
                cout << "invalid selection,try again:" << endl;
                cin >> num;
            }
        } while (num != 1 && num != 2 && num != 3);

        if (num == 1)
        {
            system("color 5a");
            scr = game(numWords, puzzle, word, dic, size);
            if (scr == 100)
            {
                cout << "Winner" << endl;
                cout << "your score is:" << scr << endl;
            }
            else
            {
                cout << "your score is:" << scr << endl;
            }
        }
        else if (num == 2)
        {
            system("color 6c");
            cout << "hello world";
        }
        else if (num == 3)
        {
            system("color 3c");
            cout << "hello world";
        }
        cout << "if to want to continue the game press yes (y/y) if you want to exit the game press no (n/n):" << endl;
        cin >> choice;
        do
        {
            if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
            {
                cout << "invalid selection , try again:" << endl;
                cin >> choice;
            }
        } while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');

    } while (choice != 'N' && choice != 'n');
    cout << "the game is ended" << endl;
    delete[] word;
    delete_2d(dic, numWords);
    delete_2d(puzzle, rows);
    return 0;
}
