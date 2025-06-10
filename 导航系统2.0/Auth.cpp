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
    cout << "注册新用户\n";
    cout << "用户名: ";
    cin >> newUser.username;

    // 检查用户名是否已存在
    DataManager &db = DataManager::getInstance();
    if (db.queryUser(newUser.username, &newUser)) // 查用户
    {
        cout << "用户名已存在！\n";
        return false;
    }

    newUser.password = hashPassword(getHiddenInput("密码: "));
    newUser.isAdmin = false;
    // users.push_back(newUser);

    // saveUsersToFile();
    if (db.insertUser(newUser.username, newUser.password, newUser.isAdmin))
    {
        cout << "注册成功！\n";
        return true;
    }
    else
    {
        cout << "用户插入数据库失败\n";
        return false;
    }
}

bool AuthManager::loginUser(User &loggedInUser)
{
    string username, password;
    cout << "登录\n";
    cout << "用户名: ";
    cin >> username;
    password = getHiddenInput("密码: ");

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
            cout << "用户名或密码错误！\n";
            return false;
        }
    }
    else
    {
        cout << "查询数据失败!\n";
        return false;
    }
}

string AuthManager::hashPassword(const string &password)
{
    // 简单哈希示例（实际应使用更安全的算法如SHA-256）
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
    { // 回车键结束输入
        if (ch == '\b' && !input.empty())
        { // 处理退格键
            input.pop_back();
            cout << "\b \b";
        }
        else if (ch >= 32 && ch <= 126)
        { // 可打印字符
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
            // cout << "插入" << '\n';
            db.insertUser(user.username, user.password, user.isAdmin);
        }
        // cout << "结束\n";
    }
}
