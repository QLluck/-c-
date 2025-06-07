#include "Auth.h"

AuthManager::AuthManager() {
    loadUsersFromFile();
}

bool AuthManager::registerUser() {
    User newUser;
    cout << "注册新用户\n";
    cout << "用户名: ";
    cin >> newUser.username;

    // 检查用户名是否已存在
    for (const auto& user : users) {
        if (user.username == newUser.username) {
            cout << "用户名已存在！\n";
            return false;
        }
    }

    newUser.passwordHash = hashPassword(getHiddenInput("密码: "));
    newUser.isAdmin = false;
    users.push_back(newUser);
    saveUsersToFile();
    cout << "注册成功！\n";
    return true;
}

bool AuthManager::loginUser(User& loggedInUser) {
    string username, password;
    cout << "登录\n";
    cout << "用户名: ";
    cin >> username;
    password = getHiddenInput("密码: ");

    for (auto& user : users) {
        if (user.username == username && user.passwordHash == hashPassword(password)) {
            loggedInUser = user;
            return true;
        }
    }
    cout << "用户名或密码错误！\n";
    return false;
}

string AuthManager::hashPassword(const string& password) {
    // 简单哈希示例（实际应使用更安全的算法如SHA-256）
    size_t hash = 0;
    for (char c : password) {
        hash = (hash << 5) + c;
    }
    return to_string(hash);
}

string AuthManager::getHiddenInput(const string& prompt) {
    string input;
    cout << prompt;
    char ch;
    while ((ch = _getch()) != '\r') { // 回车键结束输入
        if (ch == '\b' && !input.empty()) { // 处理退格键
            input.pop_back();
            cout << "\b \b";
        }
        else if (ch >= 32 && ch <= 126) { // 可打印字符
            input.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return input;
}

void AuthManager::saveUsersToFile() {
    ofstream file("users.dat");
    for (const auto& user : users) {
        file << user.username << " " << user.passwordHash << " " << user.isAdmin << "\n";
    }
}

void AuthManager::loadUsersFromFile() {
    ifstream file("users.dat");
    if (!file) return;

    User user;
    while (file >> user.username >> user.passwordHash >> user.isAdmin) {
        users.push_back(user);
    }
}