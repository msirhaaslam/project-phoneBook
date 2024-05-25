#include <iostream>
using namespace std;

class Telephone {
    char name[20];
    char address[20];
    int ph_no;
public:
    void get();
    void show() const;
    int getph_no() const;
};

void Telephone::get() {
    cout << "\nEnter Name: ";
    cin.ignore();
    cin.getline(name, 20);
    cout << "Enter Address: ";
    cin.getline(address, 20);
    cout << "Enter Phone Number: ";
    cin >> ph_no;
}

void Telephone::show() const {
    cout << "\nName: " << name;
    cout << "\nAddress: " << address;
    cout << "\nPhone Number: " << ph_no;
}

int Telephone::getph_no() const {
    return ph_no;
}

const int MAX_RECORDS = 100;
Telephone directory[MAX_RECORDS];
int record_count = 0;

void add_telephone() {
    cout << "\n======ADD TELEPHONE RECORD======\n";
    if (record_count < MAX_RECORDS) {
        directory[record_count].get();
        ++record_count;
        cout << "\n\nTelephone Directory Has Been Updated...";
    } else {
        cout << "\n\nDirectory is full. Cannot add more records.";
    }
    cout << "\n\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void display_all() {
    cout << "\n\n======DISPLAY ALL RECORDS======\n";
    if (record_count == 0) {
        cout << "No records found!";
    } else {
        for (int i = 0; i < record_count; ++i) {
            directory[i].show();
            cout << "\n\n==============================\n";
        }
    }
    cout << "\n\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void display_sp(int n) {
    cout << "\n\n=====SEARCH TELEPHONE RECORD=====\n";
    bool flag = false;
    for (int i = 0; i < record_count; ++i) {
        if (directory[i].getph_no() == n) {
            directory[i].show();
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "\n\nRecord does not exist";
    cout << "\n\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void modify_telephone(int n) {
    cout << "\n\n=====MODIFY TELEPHONE RECORD=====\n";
    bool found = false;
    for (int i = 0; i < record_count; ++i) {
        if (directory[i].getph_no() == n) {
            directory[i].show();
            cout << "\n\nPlease Enter The New Details" << endl;
            directory[i].get();
            cout << "\n\n\tRecord Updated";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "\n\nRecord Not Found";
    cout << "\n\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void delete_telephone(int n) {
    cout << "\n\n=====DELETE TELEPHONE RECORD=====\n";
    int index = -1;
    for (int i = 0; i < record_count; ++i) {
        if (directory[i].getph_no() == n) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < record_count - 1; ++i) {
            directory[i] = directory[i + 1];
        }
        --record_count;
        cout << "\n\n\tRecord Deleted...";
    } else {
        cout << "\n\nRecord Not Found";
    }
    cout << "\n\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

int main() {
    char ch;
    int num;
    do {
        cout << "\n";
        cout << "\n============TELEPHONE DIRECTORY MANAGEMENT SYSTEM============\n";
        cout << "\n1. Add Telephone Record";
        cout << "\n2. Show Records";
        cout << "\n3. Search Telephone Records";
        cout << "\n4. Modify Record";
        cout << "\n5. Delete Record";
        cout << "\n6. EXIT";
        cout << "\n";
        cout << "\nPlease Enter Your Choice (1-6): ";
        cin >> ch;

        switch (ch) {
        case '1': add_telephone(); break;
        case '2': display_all(); break;
        case '3': cout << "\n\n=====SEARCH TELEPHONE RECORD=====\n";
                  cout << "\nPlease Enter Phone Number: "; 
                  cin >> num; 
                  display_sp(num); 
                  break;
        case '4': cout << "\n\n=====MODIFY TELEPHONE RECORD=====\n";
                  cout << "\nPlease Enter Phone Number: "; 
                  cin >> num; 
                  modify_telephone(num); 
                  break;
        case '5': cout << "\n\n=====DELETE TELEPHONE RECORD=====\n";
                  cout << "\nPlease Enter Phone Number: "; 
                  cin >> num; 
                  delete_telephone(num); 
                  break;
        case '6': exit(0);
        default: cout << "\a";
        }
    } while (ch != '6');

    return 0;
}
