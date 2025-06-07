#include "Auth.h"

AuthManager::AuthManager() {
    loadUsersFromFile();
}

bool AuthManager::registerUser() {
    User newUser;
    cout << "ע�����û�\n";
    cout << "�û���: ";
    cin >> newUser.username;

    // ����û����Ƿ��Ѵ���
    for (const auto& user : users) {
        if (user.username == newUser.username) {
            cout << "�û����Ѵ��ڣ�\n";
            return false;
        }
    }

    newUser.passwordHash = hashPassword(getHiddenInput("����: "));
    newUser.isAdmin = false;
    users.push_back(newUser);
    saveUsersToFile();
    cout << "ע��ɹ���\n";
    return true;
}

bool AuthManager::loginUser(User& loggedInUser) {
    string username, password;
    cout << "��¼\n";
    cout << "�û���: ";
    cin >> username;
    password = getHiddenInput("����: ");

    for (auto& user : users) {
        if (user.username == username && user.passwordHash == hashPassword(password)) {
            loggedInUser = user;
            return true;
        }
    }
    cout << "�û������������\n";
    return false;
}

string AuthManager::hashPassword(const string& password) {
    // �򵥹�ϣʾ����ʵ��Ӧʹ�ø���ȫ���㷨��SHA-256��
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
    while ((ch = _getch()) != '\r') { // �س�����������
        if (ch == '\b' && !input.empty()) { // �����˸��
            input.pop_back();
            cout << "\b \b";
        }
        else if (ch >= 32 && ch <= 126) { // �ɴ�ӡ�ַ�
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