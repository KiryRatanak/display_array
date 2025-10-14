#include <iostream>
#include <limits>
using namespace std;

#define reset "\033[1;0m"
#define black "\033[1;30m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define yellow "\033[1;33m"
#define blue "\033[1;34m"
#define purple "\033[1;35m"
#define cyan "\033[1;36m"
#define white "\033[1;37m"

const int MAX_SIZE = 30;
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
int pos, option, insertArr, newElement;
int elementToInsert, elementToUpdate, elementToDelete;
int attempts = 20;

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

    cout << R"(|  _  |
|_____| )"
         << green << "~> [Index]." << reset << red << "element" << reset << endl;
    for (int i = 0; i < ::size; i++)
    {
        cout << R"(|  _  |
|_____|)" << green
             << " [" << i << "]. " << reset << red << arr[i] << reset << "  " << endl;
    }
    pressEnter();
    cout << endl;
}

bool insertArray()
{
    system("clear");

    cout << R"(
 _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ 
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
| _|   |_ _|_ __  ___  ___ _ __| |_     / \   _ __ _ __ __ _ _   _   |_ |   
| |     | || '_ \/ __|/ _ \ '__| __|   / _ \ | '__| '__/ _` | | | |   | |   
| |     | || | | \__ \  __/ |  | |_   / ___ \| |  | | | (_| | |_| |   | |   
| |    |___|_| |_|___/\___|_|   \__| /_/   \_\_|  |_|  \__,_|\__, |   | |   
|__|__ _____ _____ _____ _____ _____ _____ _____ _____ _____ ___/_|__|__| 
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|)"
         << endl;

    cout << R"(|  _  |
|_____| )"
         << green << "~> [Index]." << reset << red << "element" << reset << endl;
    for (int i = 0; i < ::size; i++)
    {
        cout << R"(|  _  |
|_____|)" << green
             << " [" << i << "]. " << reset << red << arr[i] << reset << "  " << endl;
    }
    cout << R"(|  _  |
|_____| ~> Enter Index to insert = )";
    cin >> pos;
    cout << R"(|  _  |
|_____| ~> Enter new element to insert = )";
    cin >> elementToInsert;

    if (pos < 0 || pos > ::size)
    {

        cout << R"(|  _  |
|_____| )" << red
             << "~> . Invalid position! " << reset << endl;

        pressEnter();
        return false;
    }

    for (int i = 0; i < pos; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[pos] = elementToInsert;

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
|_____| )"
         << green << "~> Element inserted successfully!" << reset << endl;

    if (attempts == 0)
    {
        return false;
    }
    attempts--;

    cout << R"(|  _  |
|_____| )"
         << "~> Element can put only 30 element." << endl;

    cout << R"(|  _  |
|_____| )"
         << red << "~> You have " << attempts << " attempt(s) left !!!" << reset << endl;

    pressEnter();

    cout << endl;

    return false;
}

void updateArray()
{
    cout << R"(|  _  |
|_____| ~> Enter element to update = )";
    cin >> elementToUpdate;
    cout << R"(|  _  |
|_____| ~> Enter new element = )";
    cin >> newElement;

    for (int i = 0; i < ::size; i++)
    {
        if (arr[i] == elementToUpdate)
        {
            arr[i] = newElement;
            pressEnter();
            break;
        }
    }
}

void deleteArray()
{
    cout << R"(|  _  |
|_____| ~> Enter element to update = )";
    cin >> newElement;
    cout << R"(|  _  |
|_____| ~> Enter new element = )";
    cin >> elementToUpdate;
    cout << R"(|  _  |
|_____| )"
         << green << "~> [Index]." << reset << red << "element" << reset << endl;
    for (int i = 0; i < ::size; i++)
    {
        cout << R"(|  _  |
|_____|)" << green
             << " [" << i << "]. " << reset << red << arr[i] << reset << "  " << endl;
    }

    for (int i = 0; i < ::size; i++)
    {
        if (arr[i] == elementToDelete)
        {
            for (int j = i; j < ::size; j++)
            {
                arr[j] = arr[j + 1];
            }
            ::size--;
        }
    }

    for (int i = 0; i < ::size; i++)
    {
        cout << arr[i] << " ";
    }
}

void sortArray() {}

void reverseArray() {}

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
            cout << endl;
            return 0.0;
        }

        if (option < 0 || option > 6)
        {
            cout << R"(|  _  |
|_____| )" << red << "~> Invalid options put 0 - 6 "
                 << reset << endl;
            pressEnter();
        }

        switch (option)
        {
        case 1:
            displayArray();
            break;

        case 2:
            insertArray();
            break;

        case 3:
            updateArray();
            break;

        case 4:
            deleteArray();
            break;

        case 5:
            sortArray();
            break;

        case 6:
            reverseArray();
            break;

        default:
            break;
        }
    }

    return 0;
}