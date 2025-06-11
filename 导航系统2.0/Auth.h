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
    bool registerUser();                // 注册账号
    bool loginUser(User &loggedInUser); // 用户登录
    void saveUsersToFile();             // 保存用户信息到文件
    void loadUsersFromFile();           // 从文件中读取信息

public:
    
    string hashPassword(const string &password);
    string getHiddenInput(const string &prompt);
};

#endif