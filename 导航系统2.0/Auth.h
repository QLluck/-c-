#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h> 
using namespace std;

struct User {
    string username;
    string password;
    bool isAdmin;
};

class AuthManager {
public:
    AuthManager();
    bool registerUser();
    bool loginUser(User& loggedInUser);
    void saveUsersToFile();
    void loadUsersFromFile();

public:
    
    string hashPassword(const string& password);
    string getHiddenInput(const string& prompt);
};

#endif