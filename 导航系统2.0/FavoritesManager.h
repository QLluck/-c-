#ifndef FAVORITES_MANAGER_H
#define FAVORITES_MANAGER_H

//包含了收藏常用路径的功能，实现不同用户保存数据独立存储
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Graph.h"
using namespace std;

struct FavoritePath {
    string mapName;
    string start;
    string end;
    int distance;
};

class FavoritesManager {
public:
    FavoritesManager(const string& username);
    ~FavoritesManager();
    void saveFavoritePath(const string& mapName, const string& start,
        const string& end, int distance);//将收藏路径存入文件
    void displayFavoritePaths() const;//显示收藏路径
    void clearFavorites();//清空收藏的最短路径
private:
    string username;
    vector<FavoritePath> favoritePaths;
    string getFileName() const { return username + ".txt"; }//生成文件名
    void loadFavoritePaths();//读取数据
    void saveFavoritePathsToFile() const;//将vector容器中的收藏路径存入文件
};

#endif