#include <iostream>
#include <limits>
#include <algorithm>
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
char ascDes;

void display()
{
    system("clear");
    cout << blue << R"( _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____
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
         << reset << endl;
}

void pressEnter()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << blue << "|  _  |\n|_____| " << yellow << "~> Press enter to continue ..." << reset;
    cin.get();
    cout << endl;
}

void displayArray()
{
    system("clear");

    cout << blue << R"( _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ 
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
| _|    |  _ \(_)___ _ __ | | __ _ _   _     / \   _ __ _ __ __ _ _   _    |_ |  
| |     | | | | / __| '_ \| |/ _` | | | |   / _ \ | '__| '__/ _` | | | |    | |  
| |     | |_| | \__ \ |_) | | (_| | |_| |  / ___ \| |  | | | (_| | |_| |    | |  
| |     |____/|_|___/ .__/|_|\__,_|\__, | /_/   \_\_|  |_|  \__,_|\__, |    | |  
|__|__ _____ _____ _|_|_ _____ ____|___/__ _____ _____ _____ _____|___/_ __|__|
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|)"
         << reset << endl;

    cout << blue << "|  _  |\n|_____| " << white << "~>" << cyan << " [Index]." << reset << purple << "element" << reset << endl;

    for (int i = 0; i < ::size; i++)
    {
        cout << blue << "|  _  |\n|_____| " << cyan << " [" << i << "]. " << purple << red << arr[i] << reset << "  " << endl;
    }

    pressEnter();
    cout << endl;
}

bool insertArray()
{
    system("clear");

    cout << blue << R"(
 _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ 
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
| _|   |_ _|_ __  ___  ___ _ __| |_     / \   _ __ _ __ __ _ _   _   |_ |   
| |     | || '_ \/ __|/ _ \ '__| __|   / _ \ | '__| '__/ _` | | | |   | |   
| |     | || | | \__ \  __/ |  | |_   / ___ \| |  | | | (_| | |_| |   | |   
| |    |___|_| |_|___/\___|_|   \__| /_/   \_\_|  |_|  \__,_|\__, |   | |   
|__|__ _____ _____ _____ _____ _____ _____ _____ _____ _____ ___/_|__|__| 
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|)"
         << reset << endl;

    cout << blue << "|  _  |\n|_____| " << white << "~>" << cyan << "[Index]." << purple << "element" << reset << endl;
    for (int i = 0; i < ::size; i++)
    {
        cout << blue << "|  _  |\n|_____| " << cyan << "[" << i << "]. " << purple << arr[i] << reset << "  " << endl;
    }

    cout << blue << "|  _  |\n|_____| " << white << "~> Enter Index to insert = ";
    cin >> pos;
    cout << blue << "|  _  |\n|_____| " << white << "~> Enter new element to insert = ";
    cin >> elementToInsert;

    if (pos < 0 || pos > ::size)
    {

        cout << blue << "|  _  |\n|_____| " << red << "~> . Invalid Index..! " << reset << endl;

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

    cout << blue << "|  _  |\n|_____| " << green << "~> Element inserted successfully..!" << reset << endl;

    if (attempts == 0)
    {
        return false;
    }
    attempts--;

    cout << blue << "|  _  |\n|_____| " << white << "~> Element can put only 30 element." << endl;

    cout << blue << "|  _  |\n|_____| " << red << "~> You have " << attempts << " attempt(s) left..!" << reset << endl;

    pressEnter();

    cout << endl;

    return false;
}

bool updateArray()
{
    system("clear");
    cout << blue << R"(
 _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______  
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|______| 
| _| | | | |_ __   __| | __ _| |_ ___     / \   _ __ _ __ __ _ _   _  |_ |
| |  | | | | '_ \ / _` |/ _` | __/ _ \   / _ \ | '__| '__/ _` | | | |  | |
| |  | |_| | |_) | (_| | (_| | ||  __/  / ___ \| |  | | | (_| | |_| |  | |
| |   \___/| .__/ \__,_|\__,_|\__\___| /_/   \_\_|  |_|  \__,_|\__, |  | |
|__|__ ____|_|____ _____ _____ _____ _____ _____ _____ _____ __|___/__|__|
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|______| )"
         << reset << endl;

    cout << blue << "|  _  |\n|_____| " << white << "~>" << cyan << " [Index]." << reset << purple << "element" << reset << endl;
    for (int i = 0; i < ::size; i++)
    {
        cout << blue << "|  _  |\n|_____| " << cyan << "[" << i << "]. " << reset << purple << arr[i] << reset << "  " << endl;
    }

    cout << blue << "|  _  |\n|_____| " << white << "~> Enter old Element to update = ";
    cin >> elementToUpdate;
    cout << blue << "|  _  |\n|_____| " << white << "~> Enter new element for update = ";
    cin >> newElement;

    bool found = false;
    for (int i = 0; i < ::size; i++)
    {
        if (arr[i] == elementToUpdate)
        {
            arr[i] = newElement;
            found = true;
            cout << blue << "|  _  |\n|_____| " << green << "~> Element updated successfully..!" << reset << endl;
            break;
        }
    }

    if (!found)
    {
        cout << blue << "|  _  |\n|_____| " << red << "~> Element not found..!" << reset << endl;
    }

    pressEnter();
}

void deleteArray()
{
    system("clear");
    cout << blue << R"(
 _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ ______  
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|______| 
| _| |  _ \  ___| | ___| |_ ___     / \   _ __ _ __ __ _ _   _  |_ |
| |  | | | |/ _ \ |/ _ \ __/ _ \   / _ \ | '__| '__/ _` | | | |  | |
| |  | |_| |  __/ |  __/ ||  __/  / ___ \| |  | | | (_| | |_| |  | |
| |  |____/ \___|_|\___|\__\___| /_/   \_\_|  |_|  \__,_|\__, |  | |
|__|__ _____ _____ _____ _____ _____ _____ _____ _____ __|___/__|__|
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|______| )"
         << reset << endl;

    cout << blue << "|  _  |\n|_____| " << white << "~>" << green << "[Index]." << reset << red << "element" << reset << endl;
    for (int i = 0; i < ::size; i++)
    {
        cout << blue << "|  _  |\n|_____| " << green << " [" << i << "]. " << reset << red << arr[i] << reset << "  " << endl;
    }

    cout << blue << "|  _  |\n|_____| " << white << "~> Enter element to delete = ";
    cin >> elementToDelete;

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
    
    bool found = false;
    for (int i = 0; i < ::size; i++)
    {
        if (arr[i] == elementToDelete)
        {
            arr[i] = newElement;
            found = false;
            cout << blue << "|  _  |\n|_____| " << red << "~> Element not found..!" << reset << endl;            
            break;
        }
    }

    if (!found)
    {
        cout << blue << "|  _  |\n|_____| " << green << "~> Element deleted successfully..!" << reset << endl;        
    }

    pressEnter();
}

void ascending() {
    sort(arr, arr + ::size);

    cout << blue << "|  _  |\n|_____| " << green << "~> Ascending successfully..!" << reset << endl;

    pressEnter();
}

bool compareDesc(int a, int b) {
    return a > b;
}

void descending() {
    sort(arr, arr + ::size, compareDesc);

    cout << blue << "|  _  |\n|_____| " << green << "~> Descending successfully..!" << reset << endl;
    
    pressEnter();
}

void sortArray()
{
    system("clear");
    cout << blue << R"( 
 _____ _____ _____ _____ _____ _____ _____ _____ _____ _______  
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______| 
| _| / ___|  ___  _ __| |_     / \   _ __ _ __ __ _ _   _  |_ |
| |  \___ \ / _ \| '__| __|   / _ \ | '__| '__/ _` | | | |  | |
| |   ___) | (_) | |  | |_   / ___ \| |  | | | (_| | |_| |  | |
| |  |____/ \___/|_|   \__| /_/   \_\_|  |_|  \__,_|\__, |  | |
|__|__ _____ _____ _____ _____ _____ _____ _____ ___|___/__|__|
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_______| )"
         << reset << endl;

    cout << blue << "|  _  |\n|_____| " << white << "~> Enter 'a' for Ascending 'd' for Descending = ";
    char sortOption;
    cin >> sortOption;

    if (sortOption != 'a' && sortOption != 'd') {
        cout << blue << "|  _  |\n|_____| " << red << "~> Invalid option..! ( Please put 'a' or 'd' ..! ) " << reset << endl;
        pressEnter();
        return;
    }

    switch (sortOption)
    {
        case 'a':
            ascending();
            break;
        case 'd':
            descending();
            break;
    }
}

void reverseArray()
{
    system("clear");
    cout << blue << R"(
 _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ 
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
| _| |  _ \ _____   _____ _ __ ___  ___     / \   _ __ _ __ __ _ _   _     |_ |   
| |  | |_) / _ \ \ / / _ \ '__/ __|/ _ \   / _ \ | '__| '__/ _` | | | |     | |   
| |  |  _ <  __/\ V /  __/ |  \__ \  __/  / ___ \| |  | | | (_| | |_| |     | |   
| |  |_| \_\___| \_/ \___|_|  |___/\___| /_/   \_\_|  |_|  \__,_|\__, |     | |   
|__|__ _____ _____ _____ _____ _____ _____ _____ _____ _____ ____|___/__ __|__|
|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|)"
         << reset << endl;
    
    int start = 0;
    int end = ::size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    cout << blue << "|  _  |\n|_____| " << green << "~> Reverse arrays successfully..!" << reset << endl;
    pressEnter();
    
}

int main()
{

    system("clear");

    while (true)
    {
        display();

        cout << blue << "|  _  |\n|_____| " << white << "~> Enter your choice = ";
        cin >> option;

        if (option == 0)
        {
            cout << blue << "|  _  |\n|_____| " << green << "~> Exit program. " << reset << endl;
            cout << endl;
            return 0.0;
        }

        // if (cin.fail()) {
        //     cin.clear();
        //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
        //     cout << blue << "|  _  |\n|_____| " << red << "~> Invalid input..!" << reset << endl;
        //     cout << blue << "|  _  |\n|_____| " << red << "~> Please enter an integer option ( 0 - 6 )." << reset << endl;
        //     pressEnter();
        //     continue;
        // }

        if (option < 0 || option > 6)
        {
            cout << blue << "|  _  |\n|_____| " << red << "~> Invalid options put 0 - 6 " << reset << endl;
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