#include "Auth.h"
#include "dataManager.h"
#include "sqlite3.h"
AuthManager::AuthManager()
{
    loadUsersFromFile();
}

bool AuthManager::registerUser()
{
    User newUser;
    cout << "ע�����û�\n";
    cout << "�û���: ";
    cin >> newUser.username;

    // ����û����Ƿ��Ѵ���
    DataManager &db = DataManager::getInstance();
    if (db.queryUser(newUser.username, &newUser)) // ���û�
    {
        cout << "�û����Ѵ��ڣ�\n";
        return false;
    }

    newUser.password = hashPassword(getHiddenInput("����: "));
    newUser.isAdmin = false;
    // users.push_back(newUser);

    // saveUsersToFile();
    if (db.insertUser(newUser.username, newUser.password, newUser.isAdmin))
    {
        cout << "ע��ɹ���\n";
        return true;
    }
    else
    {
        cout << "�û��������ݿ�ʧ��\n";
        return false;
    }
}

bool AuthManager::loginUser(User &loggedInUser)
{
    string username, password;
    cout << "��¼\n";
    cout << "�û���: ";
    cin >> username;
    password = getHiddenInput("����: ");

    // for (auto& user : users) {
    //     if (user.username == username && user.password == hashPassword(password)) {
    //         loggedInUser = user;
    //         return true;
    //     }
    // }
    User user;
    DataManager &db = DataManager::getInstance();
    if (db.queryUser(username, &loggedInUser))
    {
        if (loggedInUser.password == hashPassword(password))
        {
            return true;
        }
        else
        {
            cout << "�û������������\n";
            return false;
        }
    }
    else
    {
        cout << "��ѯ����ʧ��!\n";
        return false;
    }
}

string AuthManager::hashPassword(const string &password)
{
    // �򵥹�ϣʾ����ʵ��Ӧʹ�ø���ȫ���㷨��SHA-256��
    size_t hash = 0;
    for (char c : password)
    {
        hash = (hash << 5) + c;
    }
    return to_string(hash);
}

string AuthManager::getHiddenInput(const string &prompt)
{
    string input;
    cout << prompt;
    char ch;
    while ((ch = _getch()) != '\r')
    { // �س�����������
        if (ch == '\b' && !input.empty())
        { // �����˸��
            input.pop_back();
            cout << "\b \b";
        }
        else if (ch >= 32 && ch <= 126)
        { // �ɴ�ӡ�ַ�
            input.push_back(ch);
            cout << '*';
        }
    }
    cout << endl;
    return input;
}

void AuthManager::saveUsersToFile()
{
    ofstream file("users.dat");

    DataManager &db = DataManager::getInstance();
    int num = db.getNumber();
    User users[num];
    int n = 0;
    db.getAllUsers(users, num, &n);
    for (const auto &user : users)
    {
        file << user.username << " " << user.password << " " << user.isAdmin << "\n";
    }
}

void AuthManager::loadUsersFromFile()
{
    ifstream file("users.dat");
    if (!file)
        return;

    User user;
    DataManager &db = DataManager::getInstance();
    while (file >> user.username >> user.password >> user.isAdmin)
    {

        // cout << user.username << ' ' << user.password << ' ' << user.isAdmin << '\n';

        if (!db.queryUser(user.username, &user))
        {
            // cout << "����" << '\n';
            db.insertUser(user.username, user.password, user.isAdmin);
        }
        // cout << "����\n";
    }
}
