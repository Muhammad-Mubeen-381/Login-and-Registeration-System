#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class UserSystem
{
public:
    void registerUser()
    {
        string username, password;

        cout << "Enter username (Without Spaces): ";
        cin >> username;
        cout << "Enter password (Without Spaces): ";
        cin >> password;

        // Check if username already exists
        ifstream readFile(username + ".txt");
        if (readFile)
        {
            cout << "Username already exists. Try another one." << endl;
            return;
        }

        // Save credentials in file
        ofstream file(username + ".txt");
        file << username << endl;
        file << password << endl;
        file.close();

        cout << "Registration successful!" << endl;
    }

    void loginUser()
    {
        string username, password, storedUser, storedPass;

        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ifstream file(username + ".txt");
        if (!file)
        {
            cout << "User not found. Please register first." << endl;
            return;
        }

        getline(file, storedUser);
        getline(file, storedPass);

        if (storedUser == username && storedPass == password)
        {
            cout << "Login successful!" << endl;
        }
        else
        {
            cout << "Invalid username or password." << endl;
        }
    }
};

int main()
{
    UserSystem system;
    int choice;

    while (true)
    {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            system.registerUser();
        else if (choice == 2)
            system.loginUser();
        else if (choice == 3)
            break;
        else
            cout << "Invalid choice. Try again." << endl;
    }

    return 0;
}
