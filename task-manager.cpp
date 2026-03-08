#include <iostream>
#include <fstream> // Required for file handling
#include <string>

using namespace std;

int main() {
    string task;
    int choice;

    cout << "=== Persistent Task Manager ===" << endl;

    while (true) {
        cout << "\n1. Add Task\n2. View Saved Tasks\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 3) break; // Exit the loop and close the program

        if (choice == 1) {
            // Open file in Append mode (ios::app) to add data without deleting old content
            ofstream outFile("tasks.txt", ios::app); 
            cout << "Enter your task: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, task);
            
            outFile << task << endl; // Write the task into the text file
            outFile.close(); // Always close the file after writing
            cout << "Task saved to file!" << endl;
        } 
        else if (choice == 2) {
            // Open file in Read mode
            ifstream inFile("tasks.txt"); 
            string line;
            cout << "\n--- Your Saved Tasks ---" << endl;
            
            if (inFile.is_open()) {
                // Read the file line by line until the end
                while (getline(inFile, line)) {
                    cout << "- " << line << endl;
                }
                inFile.close(); // Close the file after reading
            } else {
                cout << "No tasks found! The file might not exist yet." << endl;
            }
        }
    }
    return 0;
}
