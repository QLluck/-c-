#ifndef ADMIN_H
#define ADMIN_H
#include "Auth.h"
#include "Graph.h"
using namespace std;

class Admin {
public:
    static void adminMenu(AuthManager& auth, GraphManager& graphManager);
    static void deleteUser(AuthManager& auth);
    static void modifyUser(AuthManager& auth);
    static bool createNewMap(GraphManager& graphManager);
    static bool deleteMap(GraphManager& graphManager);
    static void manageMapVertices(Graph& graph);
    static void manageMapEdges(Graph& graph);
};

#endif