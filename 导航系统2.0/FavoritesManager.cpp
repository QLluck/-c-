#include "FavoritesManager.h"
#include "Graph.h"

FavoritesManager::FavoritesManager(const string& username)
    : username(username) {
    loadFavoritePaths();
}

FavoritesManager::~FavoritesManager() {
    saveFavoritePathsToFile();
}

void FavoritesManager::loadFavoritePaths() {
    ifstream file(getFileName());
    if (!file.is_open()) return;

    FavoritePath path;
    while (file >> path.mapName >> path.start >> path.end >> path.distance) {
        favoritePaths.push_back(path);
    }
    file.close();
}

void FavoritesManager::saveFavoritePathsToFile() const {
    ofstream file(getFileName(), ios::out | ios::trunc);
    if (!file.is_open()) return;

    for (const auto& path : favoritePaths) {
        file << path.mapName << " " << path.start << " " <<
            path.end << " " << path.distance << "\n";
    }
    file.close();
}

void FavoritesManager::saveFavoritePath(const string& mapName,const string& start,const string& end, int distance) {
    //查重
    for (auto& path : favoritePaths) {
        if (path.mapName == mapName && path.start == start && path.end == end) {
            return;
        }
    }

    // 添加新路径
    FavoritePath newPath;
    newPath.mapName = mapName;
    newPath.start = start;
    newPath.end = end;
    newPath.distance = distance;
    favoritePaths.push_back(newPath);

    // 保存到文件
    saveFavoritePathsToFile();
}

void FavoritesManager::displayFavoritePaths() const {
    if (favoritePaths.empty()) {
        cout << "没有保存的常用路径！" << endl;
        return;
    }

    cout << "常用路径列表：" << endl;
    for (size_t i = 0; i < favoritePaths.size(); ++i) {
        const auto& path = favoritePaths[i];
        cout << (i + 1) << ". 地图: " << path.mapName
            << ", 起点: " << path.start
            << ", 终点: " << path.end
            << ", 距离: " << path.distance << " 米" << endl;
    }
}

void FavoritesManager::clearFavorites() {
    favoritePaths.clear();
    saveFavoritePathsToFile();
}
