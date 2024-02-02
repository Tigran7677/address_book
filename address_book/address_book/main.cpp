//
//  main.cpp
//  address book
//
//  Created by Macbook Air on 16/1/24.
//

#include <iostream>
#include "book.hpp"
#include <string>
#include <fstream>


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
int user_count = 0;


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
    cin.ignore();
    cout << "write Name: ";
    getline (cin, array[user_count].name);
    cout << "write Last_name: ";
    getline (cin, array[user_count].lastname);
    cout << "write phone_number: ";
    getline (cin, array[user_count].number);
    
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
   
    int index = 0;
    
    while (index < 1 || index > user_count) {
        cout << "write number who change [1-" << user_count << "]: ";
        cin >> index;
    }
    
    string buff;
    cin.ignore();
    cout << "write new name [" << array[index - 1].name << "]: ";
    getline ( cin, buff);
    if (buff != "") {
        array[index - 1].name = buff;
    }
    cout  << "write new last_name [" << array[index - 1].lastname << "]: ";
    getline ( cin, buff);
    if (! buff.empty()) {
        array[index - 1].lastname = buff;
    }
    cout << "write new phone number [" << array[index - 1].number << "]: ";
    getline ( cin, buff);
    if (! buff.empty()) {
        array[index - 1].number = buff;
    }
}


int main(int argc, const char * argv[]) {
    
    string mytext;
    ifstream Myfile("/Users/macbookair/workspace/address_book/data.txt");
    book array[CAPACITY];

    
    while (getline (Myfile, mytext)) {
        int comma_count = 0;
        for (int i = 0; i < mytext.length(); ++i) {
            if (mytext[i] == ',') {
                ++comma_count;
                continue;
            }
            if (comma_count == 0) {
                array[user_count].name += mytext[i];
            }
            if (comma_count == 1) {
                array[user_count].lastname += mytext[i];
            }
            if (comma_count == 2) {
                array[user_count].number += mytext[i];
            }
        }
        ++user_count;
    }
    
    Myfile.close();
    
    string input;
    do {
        cout << "Type command [all, exit, search, add, delete, change]: ";
        cin >> input;
        if (input == "exit") {
            
            ofstream MyDatafile("/Users/macbookair/workspace/address_book/data.txt");
            
            for (int i = 0; i < user_count; ++i) {
                MyDatafile << array[i].name << ',' << array[i].lastname << ',' << array[i].number << endl;
            }
            MyDatafile.close();
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
