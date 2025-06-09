#include "dataManager.h"
#include "sqlite3.h"
#include "Auth.h"
#include <stdio.h>
#include <string>

DataManager::DataManager() : db(nullptr), isConnected(0) {
}

DataManager::~DataManager() {
    closeDB();
}

//传入路径 成功数据库初始化成功
int DataManager::connectDB(const std::string& path) {
    if (isConnected) {
        closeDB();
    }

    dbPath = path;
    if (sqlite3_open(dbPath.c_str(), &db) != SQLITE_OK) {
        return 0;
    }
    isConnected = 1;

    // 创建用户表（如果不存在）
    const std::string createTableSQL = 
        "CREATE TABLE IF NOT EXISTS users ("
        "username TEXT PRIMARY KEY,"
        "password TEXT NOT NULL,"
        "isAdmin INTEGER NOT NULL"
        ");";

    return executeQuery(createTableSQL);
}

void DataManager::closeDB() {
    if (isConnected && db) {
        sqlite3_close(db);
        db = nullptr;
        isConnected = 0;
    }
}

int DataManager::executeQuery(const std::string& sql) {
    if (!isConnected) return 0;
    return (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr) == SQLITE_OK) ? 1 : 0;
}

void DataManager::bindUserData(sqlite3_stmt* stmt, const std::string& username, const std::string& password, int isAdmin) {
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, isAdmin);
}

//成功返回存储在user中
void DataManager::extractUserData(sqlite3_stmt* stmt, User* user) {
    user->username = (const char*)sqlite3_column_text(stmt, 0);
    user->password = (const char*)sqlite3_column_text(stmt, 1);
    user->isAdmin = sqlite3_column_int(stmt, 2);
}

int DataManager::insertUser(const std::string& username, const std::string& password, int isAdmin) {
    if (!isConnected) return 0;

    User user;
    if(queryUser(username, &user))
        return 0; // 插入用户失败， 用户名重复
    
    const std::string sql = "INSERT INTO users (username, password, isAdmin) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return 0;
      
    }
   
    bindUserData(stmt, username, password, isAdmin);
    int result = (sqlite3_step(stmt) == SQLITE_DONE) ? 1 : 0;
    sqlite3_finalize(stmt);
    return result;
}

int DataManager::updateUser(const std::string& username, const std::string& field, const std::string& value) {
    if (!isConnected) return 0;

    std::string sql = "UPDATE users SET " + field + " = ? WHERE username = ?;";
    
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return 0;
    }

    sqlite3_bind_text(stmt, 1, value.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, username.c_str(), -1, SQLITE_STATIC);
    int result = (sqlite3_step(stmt) == SQLITE_DONE) ? 1 : 0;
    sqlite3_finalize(stmt);
    return result;
}

int DataManager::deleteUser(const std::string& username) {
    if (!isConnected) return 0;

    const std::string sql = "DELETE FROM users WHERE username = ?;";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return 0;
    }

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    int result = (sqlite3_step(stmt) == SQLITE_DONE) ? 1 : 0;
    sqlite3_finalize(stmt);

    return result;
}

int DataManager::queryUser(const std::string& username, User* outUser) {
    
    if (!isConnected || !outUser) return 0;
   
    const std::string sql = "SELECT * FROM users WHERE username = ?;";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return 0;
    }
   

    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    int result = 0;
    
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        extractUserData(stmt, outUser);

        result = 1;
       
    }
    

    sqlite3_finalize(stmt);
    return result;
}

//user是用户数组
int DataManager:: getAllUsers(User* users, int maxUsers, int* actualCount) {
    if (!isConnected || !users || !actualCount) return 0;
    
    const std::string sql = "SELECT * FROM users;";
    sqlite3_stmt* stmt;
    *actualCount = 0;
    
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        sqlite3_finalize(stmt);
        return 0;
    }

    while (*actualCount < maxUsers && sqlite3_step(stmt) == SQLITE_ROW) {
        extractUserData(stmt, &users[*actualCount]);
        (*actualCount)++;
    }
    
    sqlite3_finalize(stmt);
    return 1;
}
int DataManager::getNumber()
{
    string sql = "SELECT COUNT(*) FROM users;";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
    {
        sqlite3_finalize(stmt);
        cout << "数据库错误" << '\n';
        return -1;
    }
      int rc = sqlite3_step(stmt);
      if(rc == SQLITE_ROW)
      {
      int  count = sqlite3_column_int(stmt, 0);
        return count; 
      }
      else
      {
         cout<<"数据库错误！\n";
         return -1;
      }
      
      
    
}
