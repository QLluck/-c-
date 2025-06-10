#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

struct User
{
    string username;
    string password;
    bool isAdmin;
};

class AuthManager
{
public:
    AuthManager();
    bool registerUser();                // ע���˺�
    bool loginUser(User &loggedInUser); // �û���¼
    void saveUsersToFile();             // �����û���Ϣ���ļ�
    void loadUsersFromFile();           // ���ļ��ж�ȡ��Ϣ

public:
    vector<User> users; // vector���������洢�û�����
    string hashPassword(const string &password);
    string getHiddenInput(const string &prompt);
};

#endif