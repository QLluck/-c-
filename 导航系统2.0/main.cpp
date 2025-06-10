#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Graph.h"
#include "FavoritesManager.h"
#include "Auth.h"
#include "Admin.h"
using namespace std;

int main()
{
    AuthManager auth;
    User currentUser;
    GraphManager graphManager;
    string filename = "南阳地图.txt";
    graphManager.importGraph(filename);
    filename = "南阳理工学院地图.txt";
    graphManager.importGraph(filename);

    DataManager &db = DataManager::getInstance();
    string path = "user.db";
    db.connectDB(path);
    // cout << db.isConnected << '\n';
    auth.loadUsersFromFile();
    int choice;
    do
    {
        graphManager.displayMainMenu();
        cin >> choice;
        cin.ignore(); // 清除输入缓冲区
        switch (choice)
        {
        case 1:
        {
            if (auth.loginUser(currentUser))
            {
                cout << "\n登录成功！欢迎 " << currentUser.username << endl;
                system("pause");
                system("cls");
                // 管理员菜单
                if (currentUser.isAdmin)
                {
                    Admin::adminMenu(auth, graphManager);
                }
                // 普通用户导航菜单
                else
                {
                    FavoritesManager favoritesManager(currentUser.username);
                    int navChoice;
                    do
                    {
                        graphManager.displayNavigationMenu();
                        cin >> navChoice;
                        cin.ignore(); // 清除输入缓冲区

                        switch (navChoice)
                        {
                        case 1:
                        {
                            if (graphManager.getGraphCount() == 0)
                            {
                                cout << "没有已导入的地图！" << endl;
                                break;
                            }
                            graphManager.displayAvailableGraphs();
                            cout << "请输入要切换的地图编号：";
                            int graphIndex;
                            cin >> graphIndex;
                            cin.ignore();
                            if (graphManager.switchGraph(graphIndex))
                            {
                                cout << "切换成功！当前地图为："
                                     << graphManager.getCurrentGraphName() << endl;
                            }
                            else
                            {
                                cout << "切换失败，请检查输入编号！" << endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            if (graphManager.displayCurrentGraphInfo())
                            {
                                cout << "显示成功！" << endl;
                            }
                            else
                            {
                                cout << "没有可用的地图！" << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            if (graphManager.depthFirstTraversal())
                            {
                                cout << "深度优先遍历完成！" << endl;
                            }
                            else
                            {
                                cout << "没有可用的地图！" << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            if (graphManager.breadthFirstTraversal())
                            {
                                cout << "广度优先遍历完成！" << endl;
                            }
                            else
                            {
                                cout << "没有可用的地图！" << endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            if (!graphManager.isGraphAvailable())
                            {
                                cout << "没有可用的地图！" << endl;
                                break;
                            }
                            graphManager.depthFirstTraversal();
                            cout << endl;
                            string start, end;
                            cout << "请输入起点名称：";
                            getline(cin, start);
                            cout << "请输入终点名称：";
                            getline(cin, end);

                            if (graphManager.findShortestPath(start, end))
                            {
                                cout << "是否保存该路径到常用路径？(y/n)：";
                                char confirm;
                                cin >> confirm;
                                cin.ignore();
                                if (confirm == 'y' || confirm == 'Y')
                                {

                                    favoritesManager.saveFavoritePath(
                                        graphManager.getCurrentGraphName(),
                                        start, end, graphManager.shortestDistance);
                                    cout << "路径已保存到常用路径！" << endl;
                                }
                            }
                            else
                            {
                                cout << "路径查找失败，可能节点不存在或不可达！" << endl;
                            }
                            break;
                        }
                        case 6:
                        {
                            favoritesManager.displayFavoritePaths();
                            break;
                        }
                        case 7:
                        {
                            favoritesManager.clearFavorites();
                            cout << "常用路径已清空！" << endl;
                            break;
                        }
                        case 8:
                        {
                            if (!graphManager.isGraphAvailable())
                            {
                                cout << "没有可用的地图！" << endl;
                                break;
                            }
                            string location;
                            int distance;
                            graphManager.breadthFirstTraversal();
                            
                            cout
                                << "请输入当前地点名称：";
                            getline(cin, location);
                            cout << "请输入搜索距离范围（米）：";
                            cin >> distance;
                            cin.ignore();

                            graphManager.graphs[graphManager.currentIndex].graph.searchNearbyLocations(location, distance);
                            break;
                        }
                        case 0:
                            cout << "感谢使用校园导航系统，再见！" << endl;
                            break;
                        default:
                            cout << "无效的选择，请重新输入！" << endl;
                        }
                        cout << endl;
                        system("pause");
                        system("cls");
                    } while (navChoice != 0);
                }
            }
            break;
        }
        case 2:
        {
            auth.registerUser();
            system("pause");
            system("cls");
            break;
        }
        }
        system("pause");
        system("cls");
    } while (choice != 0);
    cout << "感谢使用校园导航系统！" << endl;
    return 0;
}