#include <iostream>
#include <limits>
using namespace std;

// ===== Define 9 Colors =====
#define reset "\033[0m"
#define black "\033[30m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define blue "\033[34m"
#define purple "\033[35m"
#define cyan "\033[36m"
#define white "\033[37m"

const int MAX_SIZE = 13;
int arr[MAX_SIZE] = {
    10,
    11,
    17,
    19,
    24,
    30,
    34,
    42,
    56,
    71};

int size = 10;
int newArr[MAX_SIZE];
int pos, elementInsert, option, insertArr;
int attempts;

void display()
{
    system("clear");
    cout << R"( _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
|  _|                 _                                    ___                       _   _               |_ | 
| |           __     / \   _ __ _ __ __ _ _   _           / _ \ _ __   ___ _ __ __ _| |_(_) ___  _ __     | | 
| |      _____\ \   / _ \ | '__| '__/ _` | | | |         | | | | '_ \ / _ \ '__/ _` | __| |/ _ \| '_ \    | | 
| |     |_____/ /  / ___ \| |  | | | (_| | |_| |   ____  | |_| | |_) |  __/ | | (_| | |_| | (_) | | | |   | | 
| |          /_/  /_/   \_\_|  |_|  \__,_|\__, |  |____|  \___/| .__/ \___|_|  \__,_|\__|_|\___/|_| |_|   | | 
| |_                                       __| |               | |                                       _| |
|___|_ _____ _____ _____ _____ _____ _____|___/_ _____ _____ __|_| _____ _____ _____ _____ _____ _____ _|___| 
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
|     |                                                                                               |  |  |)"
         << endl;
    cout << "| 1 ~ | . Display array.                                                                              |  ~  | " << endl;
    cout << "| 2 ~ | . Insert element to array.                                                                    |  ~  | " << endl;
    cout << "| 3 ~ | . Update element inside array.                                                                |  ~  | " << endl;
    cout << "| 4 ~ | . Delete element from array.                                                                  |  ~  | " << endl;
    cout << "| 5 ~ | . Sort array ( ascending / descending ) .                                                     |  ~  | " << endl;
    cout << "| 6 ~ | . Resverse to array.                                                                          |  ~  | " << endl;
    cout << "| 0 ~ | . Exit.                                                                                       |  ~  | " << endl;
    cout << R"(|_____|_____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____|__|__|
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|)"
         << endl;
}

void pressEnter()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << R"(|  _  |
|_____| ~> Press enter to continue ...)";
    cin.get();
    cout << endl;
}

void displayArray()
{
    system("clear");

    cout << R"( _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ 
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
| _|    |  _ \(_)___ _ __ | | __ _ _   _     / \   _ __ _ __ __ _ _   _    |_ |  
| |     | | | | / __| '_ \| |/ _` | | | |   / _ \ | '__| '__/ _` | | | |    | |  
| |     | |_| | \__ \ |_) | | (_| | |_| |  / ___ \| |  | | | (_| | |_| |    | |  
| |     |____/|_|___/ .__/|_|\__,_|\__, | /_/   \_\_|  |_|  \__,_|\__, |    | |  
|__|__ _____ _____ _|_|_ _____ ____|___/__ _____ _____ _____ _____|___/_ __|__|
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|)"
         << endl;
    cout << "|     |     |     |" << endl;
    cout << "|   " << red << "Index" << reset << "   |  =  |";
    for (int i = 0; i < ::size; i++)
    {
        cout << green << " [" << i << "]>" <<arr[i] << reset << "  ";
    }
    cout << endl;
    cout << "|_____|_____|_____|___________________________________________________________" << endl;
    cout << "|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|" << endl;
    
    pressEnter();
    cout << endl;
}

void insertArray()
{
    system("clear");
    do
    {

    cout << R"(|  _  |
|_____| ~> Enter position = )";
    cin >> pos;
    cout << R"(|  _  |
|_____| ~> Enter element to insert = )";
    cin >> elementInsert;

    if (pos < 0 || pos > ::size) {

        cout << R"(|  _  |
|_____| )" << red << "~> . Invalid position! "<< reset << endl;

        pressEnter();
        return;
    }

    for (int i = 0; i < pos; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[pos] = elementInsert;
    for (int i = pos; i < ::size; i++)
    {
        newArr[i + 1] = arr[i];
    }

    for (int i = 0; i < ::size + 1; i++)
    {
        arr[i] = newArr[i];
    }
    ::size++;

    cout << R"(|  _  |
|_____| )" << green << "~> . Element inserted successfully!" << reset << endl;

    cout << "You have " << attempts << " attemp(s) left" << endl;
        if (attempts == 0)
        {
            return;
        }

    attempts--;
    
    pressEnter();

    }while(true);

    
    cout << endl;
}

void updateArray(){

}

void deleteArray(){}

void sortArray(){}

void reverseArray(){}

int main()
{

    system("clear");

    while (true)
    {
        display();

        cout << R"(|  _  |
|_____| ~> Enter your choice = )";
        cin >> option;

        if (option == 0)
        {
            cout << R"(|  _  |
|_____| )" << green
                 << "~> Exit program. " << reset << endl;
            cout<<endl;
            return 0.0;
        }

        switch (option)
        {

        case 1:
        {
            displayArray();
            break;
        }

        case 2:{
            insertArray();
            break;
        }

        case 3:

        case 4:

        case 5:

        case 6:

        default:
            break;
        }
    }

    return 0;
}