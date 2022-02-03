#include <vector>
#include <iostream>
#include <limits>
#include <string.h>

// Везде, где нужно вводить данные в консоли (исключение - сортировки, числа можно вводить любые), ожидается ввод только одного символа. Очистки потока ввода нет, ждем только символы. Идея именно в механике и алгоритме.
// Wherever any data needs to be entered into the console (exception - sort examples, any number is welcome), only one character is expected. There is no cleanup of the input stream, we are only waiting for SINGLE characters.The idea is in mechanics and algorithm.

bool subFuncOver = false;
using namespace std;

// Вспомогательные функции / Assistant functions

void ArrCout(vector<char> &arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if ((i + 1) != arr.size()) {
            cout << ",";
        }
    }
};
void ArrCout(vector<int>& arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if ((i + 1) != arr.size()) {
            cout << ",";
        }
    }
}

vector <int> stringToIntArr(string & inputNumbers)
{
    vector <int> Arr;
    char* stringToSplit = NULL;
    char* token = NULL;
    char* next_token = NULL;

    stringToSplit = new char[inputNumbers.size()];
    *stringToSplit = NULL;

    for (int i = 0; i < inputNumbers.size(); i++)
    {
        stringToSplit[i] = inputNumbers[i];
    }

    token = strtok_s(stringToSplit, ",", &next_token);
    Arr.push_back(atoi(token));
    while (token != NULL)
    {
        if (token != NULL)
        {
            token = strtok_s(NULL, ",", &next_token);
            if (token != NULL) {
                Arr.push_back(atoi(token));
            }
        }
    }
    delete[] stringToSplit;
    return Arr;
}

// Stack expample
void stack() {
    subFuncOver = false;
    int cmd;
    char val;
    vector<char> Arr;
    
    cout << "Hello! We got an empty stack. Remember controls:\n1. push\n2. clear\n3. pop\nEnter 0 to quit";
    while (!subFuncOver) {
        cout << "\nEnter command: ";
        cin >> cmd;
        switch (cmd) {
        case 1:
            cout << "Enter value to Push: ";
            cin >> val;
            Arr.push_back(val);
            cout << "Successful push! Stack is now: [";
            ArrCout(Arr);
            cout << "]";
            break;
        case 2:
            Arr.clear();
            cout << "Successful clear! Stack is now empty: [";
            ArrCout(Arr);
            cout << "]";
            break;
        case 3:
            if (Arr.size() < 1) {
                cout << "Error. Stack is empty. Cannot execute 'Pop'";
            }
            else {
                Arr.erase(Arr.end()-1, Arr.end());
                cout << "Successful pop! Stack is now: [";
                ArrCout(Arr);
                cout << "]";
            }
            break;
        case 0:
            subFuncOver = true;
            break;
        }
    }

};
// Stack realisation that checks bracket array
void stackCorrectBrackets() {
    vector<char> Arr;
    string inputStringBrackets;
    subFuncOver = false;

    while (!subFuncOver) {
        cout << "\nEnter string of brackets for check (Only '(', '{', '[', ')', '}', ']' available (Enter 0 to Exit: ";
        cin >> inputStringBrackets;

        if (inputStringBrackets == "0") {
            subFuncOver = true;
            break;
        }

        for (unsigned int i = 0; i < inputStringBrackets.size(); i++) {
            Arr.push_back(inputStringBrackets[i]);
            if (Arr.size() > 1 && ((Arr[Arr.size() - 2] == '(' && Arr[Arr.size() - 1] == ')') || (Arr[Arr.size() - 2] == '{' && Arr[Arr.size() - 1] == '}') || (Arr[Arr.size() - 2] == '[' && Arr[Arr.size() - 1] == ']'))) {
                Arr.pop_back();
                Arr.pop_back();
            }
        }
        if (Arr.size() == 0) {
            cout << "Your string is correct";
        } 
        else {
            cout <<  "String contains ERROR!!!";
        }

        Arr.clear();
    }
};
// Queue example (with 2 stacks)
void stackQueue() {
    subFuncOver = false;
    int cmd;
    char val;
    vector<char> Arr1, Arr2;

    cout << "Hello! We got an empty queue. Use one of the following commands:\n1. Push\n2. Pop First\n3. Front (show first queue member)\n4. Size\n5. Clear\nEnter 0 to Exit";

    while (!subFuncOver) {

        cout << "\nEnter command: ";
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            cout << "Enter val to push: ";
            cin >> val;
            cin.clear();
            Arr1.push_back(val);
            cout << "Successful push!";
            break;
        case 2:
            if (Arr1.size() != 0)
            {
                for (int i = Arr1.size() - 1; i > -1; i--)
                {
                    Arr2.push_back(Arr1[i]);
                }
                Arr2.erase(Arr2.end() - 1, Arr2.end());
                Arr1.clear();
                for (int i = Arr2.size() - 1; i > -1; i--)
                {
                    Arr1.push_back(Arr2[i]);
                }
                Arr2.clear();
                cout << "First queue member deleted successfully. Actual queue:\n[";
                ArrCout(Arr1);
                cout << "]";
            }
            else {
                cout << "ERROR. Queue is empty!";
            }
            break;
        case 3:
            for (int i = Arr1.size() - 1; i > -1; i--)
            {
                Arr2.push_back(Arr1[i]);
                if (i == 0) {
                    cout << "First queue member is: [" << Arr2[Arr1.size() - 1] << "]";
                }
            }
            Arr2.clear();
            cout << ". Actual queue:\n[";
            ArrCout(Arr1);
            cout << "]";
            break;
        case 4:
            cout << "Total queue size is: " << Arr1.size() + Arr2.size();
            break;
        case 5:
            Arr1.clear();
            Arr2.clear();
            cout << "Successful clear! Queue is now empty";
            break;
        case 0:
            subFuncOver = true;
            break;
        }
    }
};
// "Selection" sort example
void sortSelection() {
    subFuncOver = false;

    int sPoint = 0, notSortedMax = 0, tempVal = 0;
    
    vector <int> Arr;

    string inputNumbers;

    while (!subFuncOver)
    {
        cout << "\nEnter your numbers, split them with ',' (enter '0' to Exit): ";
        cin >> inputNumbers;

        if (inputNumbers == "0") {
            subFuncOver = true;
            break;
        }

        Arr = stringToIntArr(inputNumbers);

        cout << "Source Array: \n[";
        ArrCout(Arr);
        cout << "]";

        sPoint = Arr.size() - 1;

        while (sPoint > 0) {
            notSortedMax = 0;
            for (int i = 1; i < sPoint + 1; i++)
            {
                if (Arr[i] > Arr[notSortedMax])
                {
                    notSortedMax = i;
                }
            }
            tempVal = Arr[sPoint];
            Arr[sPoint] = Arr[notSortedMax];
            Arr[notSortedMax] = tempVal;
            sPoint--;
        }

        cout << "\nSorted Array: \n[";
        ArrCout(Arr);
        cout << "]";
    }
};
// "Bubble" sort example
void sortBubble() {
    subFuncOver = false;

    int sPoint = 0, notSortedMax = 0, tempVal = 0;

    vector <int> Arr;

    string inputNumbers;

    while (!subFuncOver)
    {
        cout << "\nEnter your numbers, split them with ',' (enter '0' to Exit): ";
        cin >> inputNumbers;

        if (inputNumbers == "0") {
            subFuncOver = true;
            break;
        }

        Arr = stringToIntArr(inputNumbers);

        cout << "Source Array: \n[";
        ArrCout(Arr);
        cout << "]";
        

        for (int i = 0; i < Arr.size(); i++)
        {
            for (int j = 0; j < Arr.size() - i - 1; j++)
            {
                if (Arr[j] > Arr[j + 1])
                {
                    tempVal = Arr[j];
                    Arr[j] = Arr[j + 1];
                    Arr[j+1] = tempVal;
                }
            }
        }

        cout << "\nSorted Array: \n[";
        ArrCout(Arr);
        cout << "]";
    }
}
// "Insert" sort example
void sortInsert() {
    subFuncOver = false;

    int sPoint = 0, tempVal = 0;

    vector <int> Arr;

    string inputNumbers;

    while (!subFuncOver)
    {
        cout << "\nEnter your numbers, split them with ',' (enter '0' to Exit): ";
        cin >> inputNumbers;

        if (inputNumbers == "0") {
            subFuncOver = true;
            break;
        }

        Arr = stringToIntArr(inputNumbers);

        cout << "Source Array: \n[";
        ArrCout(Arr);
        cout << "]";
        
        for (int i = 1; i < Arr.size(); i++)
        {
            sPoint = i;
            while (sPoint > 0 && Arr[sPoint - 1] > Arr[sPoint])
            {
                tempVal = Arr[sPoint];
                Arr[sPoint] = Arr[sPoint - 1];
                Arr[sPoint - 1] = tempVal;
                sPoint--;
            }
        }

        cout << "\nSorted Array: \n[";
        ArrCout(Arr);
        cout << "]";
    }
};

int main()
{
    bool quit = false;
    int choice;
    while (!quit) {
        cout << "Menu:\n1. basic (Stack)\n2. correctBrackets (Stack)\n3. queue (Stack)\n4. selection (Sort)\n5. bubble (Sort)\n6. insert (Sort)\n*Enter 0 to quit\nChoose point you want to watch at: ";
        cin >> choice;
        
        switch (choice) {
        case 1:
            stack();
            break;
        case 2:
            stackCorrectBrackets();
            break;
        case 3:
            stackQueue();
            break;
        case 4:
            sortSelection();
            break;
        case 5:
            sortBubble();
            break;
        case 6:
            sortInsert();
            break;
        case 0:
            cout << "Ok. Bye *";
            quit = true;
            break;
        }
    }
    
}
