#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "sqlite3.h"
#include "Auth.h"
#include <string>
// 用户信息结构体


class DataManager {
private:
    // 私有构造函数和析构函数
    DataManager();
    ~DataManager();

    // 禁止拷贝和赋值
    DataManager(const DataManager&) = delete;
    DataManager& operator=(const DataManager&) = delete;

    sqlite3* db;              // 数据库连接句柄
    std::string dbPath;       // 数据库文件路径
              // 数据库连接状态

    // 私有辅助函数
    int executeQuery(const std::string& sql);
    void bindUserData(sqlite3_stmt* stmt, const std::string& username, const std::string& password, int isAdmin);//绑定用户的的三个数据 绑定为stmt
    void extractUserData(sqlite3_stmt* stmt, User* user);

public:
    // 获取单例实例
    static DataManager& getInstance() {
        static DataManager instance;
        return instance;
    }
    int isConnected;

    // 数据库连接管理
    int connectDB(const std::string& dbPath);
    void closeDB();
    int isDBConnected() const { return isConnected; }

    // 用户管理（使用游标）
    int insertUser(const std::string& username, const std::string& password, int isAdmin);
    int updateUser(const std::string& username, const std::string& field, const std::string& value);
    int deleteUser(const std::string& username);
    int queryUser(const std::string& username, User* outUser);
    int getAllUsers(User* users, int maxUsers, int* actualCount);
    int getNumber();
};

#endif // DATA_MANAGER_H
