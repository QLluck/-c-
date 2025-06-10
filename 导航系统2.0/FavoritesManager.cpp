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
    //����
    for (auto& path : favoritePaths) {
        if (path.mapName == mapName && path.start == start && path.end == end) {
            return;
        }
    }

    // �����·��
    FavoritePath newPath;
    newPath.mapName = mapName;
    newPath.start = start;
    newPath.end = end;
    newPath.distance = distance;
    favoritePaths.push_back(newPath);

    // ���浽�ļ�
    saveFavoritePathsToFile();
}

void FavoritesManager::displayFavoritePaths() const {
    if (favoritePaths.empty()) {
        cout << "û�б���ĳ���·����" << endl;
        return;
    }

    cout << "����·���б�" << endl;
    for (size_t i = 0; i < favoritePaths.size(); ++i) {
        const auto& path = favoritePaths[i];
        cout << (i + 1) << ". ��ͼ: " << path.mapName
            << ", ���: " << path.start
            << ", �յ�: " << path.end
            << ", ����: " << path.distance << " ��" << endl;
    }
}

void FavoritesManager::clearFavorites() {
    favoritePaths.clear();
    saveFavoritePathsToFile();
}
