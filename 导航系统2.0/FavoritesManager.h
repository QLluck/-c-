#ifndef FAVORITES_MANAGER_H
#define FAVORITES_MANAGER_H
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
        const string& end, int distance);
    void displayFavoritePaths() const;
    void clearFavorites();
    bool isPathValid(const Graph& graph) const;
private:
    string username;
    vector<FavoritePath> favoritePaths;
    string getFileName() const { return username + ".txt"; }
    void loadFavoritePaths();
    void saveFavoritePathsToFile() const;
};

#endif