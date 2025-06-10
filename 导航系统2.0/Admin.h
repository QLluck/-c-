#ifndef ADMIN_H
#define ADMIN_H
#include "Auth.h"
#include "Graph.h"
#include "dataManager.h"
using namespace std;

class Admin
{
public:
    static void adminMenu(AuthManager &auth, GraphManager &graphManager);    // 管理员菜单
    static void deleteUser(AuthManager &auth);                               // 删除用户
    static void modifyUser(AuthManager &auth);                               // 修改用户信息
    static bool createNewMap(GraphManager &graphManager);                    // 新建地图
    static bool deleteMap(GraphManager &graphManager);                       // 删除地图
    static void manageMapVertices(Graph &graph, GraphManager &graphManager); // 管理图顶点
    static void manageMapEdges(Graph &graph, GraphManager &graphManager);    // 管理图边
    static void exportUserInfo(AuthManager &auth);
    static void deleteAllPathsBetween(Graph &graph, int startIdx, int endIdx, GraphManager &graphManager);                                     // 删除两点间所有可达路径
    static vector<vector<int>> findAllPaths(Graph &graph, int startIdx, int endIdx);                                                           // 找出所有可达路径
    static void findPathsUtil(Graph &graph, int currentIdx, int endIdx, bool visited[], vector<int> &currentPath, vector<vector<int>> &paths); // 查找所有路径，辅助递归函数
};

#endif