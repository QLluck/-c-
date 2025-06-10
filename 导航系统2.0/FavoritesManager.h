#ifndef FAVORITES_MANAGER_H
#define FAVORITES_MANAGER_H

//�������ղس���·���Ĺ��ܣ�ʵ�ֲ�ͬ�û��������ݶ����洢
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
        const string& end, int distance);//���ղ�·�������ļ�
    void displayFavoritePaths() const;//��ʾ�ղ�·��
    void clearFavorites();//����ղص����·��
private:
    string username;
    vector<FavoritePath> favoritePaths;
    string getFileName() const { return username + ".txt"; }//�����ļ���
    void loadFavoritePaths();//��ȡ����
    void saveFavoritePathsToFile() const;//��vector�����е��ղ�·�������ļ�
};

#endif