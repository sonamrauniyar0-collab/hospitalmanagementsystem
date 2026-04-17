#include <iostream>
#include <string>
using namespace std;

// ---------------- ROOM CLASS ----------------
class Room {
private:
    int roomNo;
    string type; // ICU / General
    bool isOccupied;

public:
    void setRoom(int r, string t) {
        roomNo = r;
        type = t;
        isOccupied = false;
    }

    void displayRoom() {
        cout << "\nRoom No: " << roomNo;
        cout << "\nType: " << type;
        cout << "\nStatus: " << (isOccupied ? "Occupied" : "Available") << endl;
    }

    bool checkAvailable() {
        return !isOccupied;
    }

    void assignRoom() {
        isOccupied = true;
    }

    int getRoomNo() {
        return roomNo;
    }
};

// ---------------- DOCTOR CLASS ----------------
class Doctor {
private:
    int id;
    string name;
    string specialization;
    bool available;

public:
    void addDoctor(int i, string n, string s) {
        id = i;
        name = n;
        specialization = s;
        available = true;
    }

    void displayDoctor() {
        cout << "\nDoctor ID: " << id;
        cout << "\nName: " << name;
        cout << "\nSpecialization: " << specialization;
        cout << "\nStatus: " << (available ? "Available" : "Not Available") << endl;
    }

    bool isAvailable() {
        return available;
    }

    void assignDoctor() {
        available = false;
    }
};

// ---------------- PATIENT CLASS ----------------
class Patient {
private:
    int id;
    string name;
    string disease;
    int roomNo;

public:
    void addPatient(int i, string n, string d, int r) {
        id = i;
        name = n;
        disease = d;
        roomNo = r;
    }

    void displayPatient() {
        cout << "\nPatient ID: " << id;
        cout << "\nName: " << name;
        cout << "\nDisease: " << disease;
        cout << "\nRoom No: " << roomNo << endl;
    }
};

// ---------------- MAIN ----------------
int main() {

    Room rooms[5];
    Doctor doctors[5];
    Patient patients[100];

    int pCount = 0;

    // Initialize rooms
    rooms[0].setRoom(101, "General");
    rooms[1].setRoom(102, "General");
    rooms[2].setRoom(201, "ICU");
    rooms[3].setRoom(202, "ICU");
    rooms[4].setRoom(203, "ICU");

    // Initialize doctors
    doctors[0].addDoctor(1, "Ram", "Cardiology");
    doctors[1].addDoctor(2, "Shyam", "Neurology");
    doctors[2].addDoctor(3, "Hari", "Orthopedic");

    int choice;

    do {
        cout << "\n\n===== Hospital Management System =====";
        cout << "\n1. Show Rooms";
        cout << "\n2. Show Doctors";
        cout << "\n3. Add Patient (Assign Room & Doctor)";
        cout << "\n4. Show Patients";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                cout << "\n--- Room Status ---";
                for(int i = 0; i < 5; i++) {
                    rooms[i].displayRoom();
                }
                break;
            }

            case 2: {
                cout << "\n--- Doctor Status ---";
                for(int i = 0; i < 3; i++) {
                    doctors[i].displayDoctor();
                }
                break;
            }

            case 3: {
                int id;
                string name, disease;

                cout << "Enter Patient ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Disease: ";
                cin >> disease;

                // Find available room
                int roomIndex = -1;
                for(int i = 0; i < 5; i++) {
                    if(rooms[i].checkAvailable()) {
                        roomIndex = i;
                        break;
                    }
                }

                // Find available doctor
                int doctorIndex = -1;
                for(int i = 0; i < 3; i++) {
                    if(doctors[i].isAvailable()) {
                        doctorIndex = i;
                        break;
                    }
                }

                if(roomIndex == -1) {
                    cout << "No rooms available!\n";
                }
                else if(doctorIndex == -1) {
                    cout << "No doctors available!\n";
                }
                else {
                    rooms[roomIndex].assignRoom();
                    doctors[doctorIndex].assignDoctor();

                    patients[pCount].addPatient(id, name, disease, rooms[roomIndex].getRoomNo());
                    pCount++;

                    cout << "Patient admitted successfully!\n";
                }

                break;
            }

            case 4: {
                cout << "\n--- Patient List ---";
                for(int i = 0; i < pCount; i++) {
                    patients[i].displayPatient();
                }
                break;
            }

            case 5:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 5);

    return 0;
}