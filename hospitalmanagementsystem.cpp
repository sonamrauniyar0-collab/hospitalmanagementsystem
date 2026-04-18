#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Room {
public:
    int roomNo;
    string type;
    bool occupied;

    void setRoom(int r, string t) {
        roomNo = r;
        type = t;
        occupied = false;
    }
};

class Patient {
public:
    int id;
    string name;
    string disease;
    int roomNo;
    int bill;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Disease: ";
        cin >> disease;
    }

    void display() {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nDisease: " << disease
             << "\nRoom: " << roomNo
             << "\nBill: Rs." << bill << endl;
    }
};

Room rooms[5];
Patient patients[100];
int countP = 0;

void saveToFile() {
    ofstream file("patients.txt");
    for(int i = 0; i < countP; i++) {
        file << patients[i].id << " "
             << patients[i].name << " "
             << patients[i].disease << " "
             << patients[i].roomNo << " "
             << patients[i].bill << endl;
    }
    file.close();
}

void loadFromFile() {
    ifstream file("patients.txt");
    while(file >> patients[countP].id >> patients[countP].name 
          >> patients[countP].disease >> patients[countP].roomNo 
          >> patients[countP].bill) {
        countP++;
    }
    file.close();
}

int assignRoom(string type) {
    for(int i = 0; i < 5; i++) {
        if(!rooms[i].occupied && rooms[i].type == type) {
            rooms[i].occupied = true;
            return rooms[i].roomNo;
        }
    }
    return -1;
}

void dischargePatient() {
    int id;
    cout << "Enter Patient ID to discharge: ";
    cin >> id;

    for(int i = 0; i < countP; i++) {
        if(patients[i].id == id) {

            // free room
            for(int j = 0; j < 5; j++) {
                if(rooms[j].roomNo == patients[i].roomNo) {
                    rooms[j].occupied = false;
                }
            }

            cout << "\nPatient discharged!\nFinal Bill: Rs." << patients[i].bill << endl;

            
            for(int k = i; k < countP - 1; k++) {
                patients[k] = patients[k + 1];
            }
            countP--;
            return;
        }
    }

    cout << "Patient not found!\n";
}

void searchPatient() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for(int i = 0; i < countP; i++) {
        if(patients[i].id == id) {
            patients[i].display();
            return;
        }
    }

    cout << "Not found!\n";
}


int main() {

    // rooms setup
    rooms[0].setRoom(101, "General");
    rooms[1].setRoom(102, "General");
    rooms[2].setRoom(201, "ICU");
    rooms[3].setRoom(202, "ICU");
    rooms[4].setRoom(203, "ICU");

    loadFromFile();

    int choice;

    do {
        cout << "\n\n===== ADVANCED HOSPITAL SYSTEM =====";
        cout << "\n1. Add Patient";
        cout << "\n2. Show Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Discharge Patient";
        cout << "\n5. Save Data";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                Patient p;
                string type;

                p.input();

                cout << "Room Type (ICU/General): ";
                cin >> type;

                int room = assignRoom(type);

                if(room == -1) {
                    cout << "No room available!\n";
                } else {
                    p.roomNo = room;

                    // Billing
                    if(type == "ICU") p.bill = 5000;
                    else p.bill = 2000;

                    patients[countP++] = p;

                    cout << "Patient admitted! Room No: " << room << endl;
                }
                break;
            }

            case 2:
                for(int i = 0; i < countP; i++) {
                    patients[i].display();
                }
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                dischargePatient();
                break;

            case 5:
                saveToFile();
                cout << "Data saved!\n";
                break;

            case 6:
                saveToFile();
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid!\n";
        }

    } while(choice != 6);

    return 0;
}