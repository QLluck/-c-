#ifndef ADMIN_H
#define ADMIN_H
#include "Auth.h"
#include "Graph.h"
#include "dataManager.h"
using namespace std;

class Admin
{
public:
    static void adminMenu(AuthManager &auth, GraphManager &graphManager);    // ����Ա�˵�
    static void deleteUser(AuthManager &auth);                               // ɾ���û�
    static void modifyUser(AuthManager &auth);                               // �޸��û���Ϣ
    static bool createNewMap(GraphManager &graphManager);                    // �½���ͼ
    static bool deleteMap(GraphManager &graphManager);                       // ɾ����ͼ
    static void manageMapVertices(Graph &graph, GraphManager &graphManager); // ����ͼ����
    static void manageMapEdges(Graph &graph, GraphManager &graphManager);    // ����ͼ��
    static void exportUserInfo(AuthManager &auth);
    static void deleteAllPathsBetween(Graph &graph, int startIdx, int endIdx, GraphManager &graphManager);                                     // ɾ����������пɴ�·��
    static vector<vector<int>> findAllPaths(Graph &graph, int startIdx, int endIdx);                                                           // �ҳ����пɴ�·��
    static void findPathsUtil(Graph &graph, int currentIdx, int endIdx, bool visited[], vector<int> &currentPath, vector<vector<int>> &paths); // ��������·���������ݹ麯��
};

#endif