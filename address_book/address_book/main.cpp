//
//  main.cpp
//  address book
//
//  Created by Macbook Air on 16/1/24.
//

#include <iostream>
#include "book.hpp"
#include <string>

using namespace std;

struct book {
    string name;
    string lastname;
    string number;
};

bool starts_with(const string str, const string prefix) {
    return str.find(prefix) == 0;
}

int main(int argc, const char * argv[]) {
    
    book array[5];
    array[0] = {"Valod", "Valodyan", "+374 - 94 - 94 - 94 - 94" };
    array[1] = {"Karen", "Karenyan", "+374 - 77 - 77 - 77 - 77" };
    array[2] = {"Vardan", "Vardanyan", "+374 - 98 - 15 - 14 - 14" };
    array[3] = {"Gagik", "Gagikyan", "+374 - 94 - 22 - 14 - 13" };
    array[4] = {"Ashot", "Ashotyan", "+374 - 99 - 13 - 14 - 22" };
    
    string input;

    do {
        cout << "Type command [all, exit, search]: ";
        cin >> input;
        if (input == "exit") {
            break;
        } else if (input == "all") {
            for (int i = 0; i < 5; ++i) {
                cout << array[i].name << " " << array[i].lastname << " " << array[i].number << endl;
            }
        } else if (input == "search") {
            cout << "write name  ";
            cin >> input;
            
            for (int i = 0; i < 5; ++i) {
                if (starts_with(array[i].name, input) || starts_with(array[i].lastname, input)) {
                    cout << array[i].name << " " << array[i].lastname << " " << array[i].number << endl;
                }
            }
        } else {
            cout << "Wrong command. Try again." << endl;
        }
        
    }  while (true);
    
    return 0;
}
