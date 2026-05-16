/*
    Amr Zaki Abdel-Razek 20245040 G2
    Mohamed Waleed Wagih 20245056 G2
*/
#include <iostream>
#include <string>
#include "appointment.h"

using namespace std;

int main() {
    BST hospitalBST;
    int numInitial;

    
    cout << "Enter number of appointments: ";
    cin >> numInitial;

    for (int i = 0; i < numInitial; i++) {
        string name, dept;
        int priority;
        cin.ignore(); 
        cout << "Enter patient name: ";
        getline(cin, name);
        cout << "Enter priority level: ";
        cin >> priority;
        cin.ignore();
        cout << "Enter department: ";
        getline(cin, dept);

        hospitalBST.insert(name, priority, dept);
    }

    int choice = 0;
    while (choice != 7) {
        
        cout << "\n--- Hospital Appointment System Menu ---" << endl;
        cout << "1. Schedule an appointment" << endl;
        cout << "2. Display all appointments" << endl;
        cout << "3. Search for an appointment" << endl;
        cout << "4. Cancel an appointment" << endl;
        cout << "5. Display more urgent than" << endl;
        cout << "6. Display less urgent than" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter number of option: ";
        cin >> choice;

        if (choice == 1) { 
            string name, dept;
            int priority;
            cin.ignore();
            cout << "Enter patient name: ";
            getline(cin, name);
            cout << "Enter priority level: ";
            cin >> priority;
            cin.ignore();
            cout << "Enter department: ";
            getline(cin, dept);
            hospitalBST.insert(name, priority, dept);
            cout << "Appointment scheduled." << endl;
        }
        else if (choice == 2) { 
            cout << "All appointments (In-order):" << endl;
            hospitalBST.inorder();
        }
        else if (choice == 3) { 
            int p;
            cout << "Enter the priority level: ";
            cin >> p;
            hospitalBST.search(p);
        }
        else if (choice == 4) { 
            int p;
            cout << "Enter the priority level to cancel: ";
            cin >> p;
            hospitalBST.delall(p);
            cout << "Appointments with priority " << p << " cancelled." << endl;
        }
        else if (choice == 5) { 
            int p;
            cout << "Display more urgent than: ";
            cin >> p;
            hospitalBST.displayMoreUrgent(p);
        }
        else if (choice == 6) { 
            int p;
            cout << "Display less urgent than: ";
            cin >> p;
            hospitalBST.displayLessUrgent(p);
        }
    }

    return 0;
}