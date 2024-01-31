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

void print_user(book user, int index) {
    cout << index << " " << user.name << " " << user.lastname << " " << user.number << endl;
}


const int CAPACITY = 100;
int user_count = 5;


void delete_user(book (&array)[CAPACITY]) {
    cout << "record number to delete: ";
    int num;
    cin >> num;
    
    for (int i = num - 1; i < user_count - 1; ++i) {
        array[i] = array[i + 1];
    }
    user_count--;
}

void add_user(book (&array)[CAPACITY]) {
    cout << "write Name: " << endl;
    cin >> array[user_count].name;
    cout << "write Last_name: " << endl;
    cin >> array[user_count].lastname;
    cout << "write phone_number: " << endl;
    cin >> array[user_count].number;
    
    user_count++;
}

void user_search(book (&array)[CAPACITY], string input) {
    cout << "write name  ";
    cin >> input;
    
    for (int i = 0; i < user_count; ++i) {
        if (starts_with(array[i].name, input) || starts_with(array[i].lastname, input)) {
            print_user(array[i], i+1);
        }
    }
}

void all_user (book (&array) [CAPACITY]) {
    for (int i = 0; i < user_count; ++i) {
        print_user(array[i], i+1);
    }
}

void change_user (book (&array) [CAPACITY]) {
    cout << "write number who change: ";
    int index;
    cin >> index;
    
    cout << "write new name: ";
    cin >> array[index].name;
    cout  << "write new last_name: ";
    cin >> array[index].lastname;
    cout << "write new phone number: ";
    cin >> array[index].number;
}


int main(int argc, const char * argv[]) {
    
    book array[CAPACITY];
    array[0] = {"Valod", "Valodyan", "+374 - 94 - 94 - 94 - 94" };
    array[1] = {"Karen", "Karenyan", "+374 - 77 - 77 - 77 - 77" };
    array[2] = {"Vardan", "Vardanyan", "+374 - 98 - 15 - 14 - 14" };
    array[3] = {"Gagik", "Gagikyan", "+374 - 94 - 22 - 14 - 13" };
    array[4] = {"Ashot", "Ashotyan", "+374 - 99 - 13 - 14 - 22" };
    
    string input;

    do {
        cout << "Type command [all, exit, search, add, delete, change]: ";
        cin >> input;
        if (input == "exit") {
            break;
        } else if (input == "all") {
            all_user(array);
        } else if (input == "search") {
            user_search(array, input);
        } else if (input == "add") {
            add_user(array);
        } else if (input == "delete") {
            delete_user(array);
        } else if (input == "change") {
            change_user(array);
        }
        else {
            cout << "Wrong command. Try again." << endl;
        }
    }  while (true);
    
    return 0;
}
