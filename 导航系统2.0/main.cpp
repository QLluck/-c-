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
    string filename = "������ͼ.txt";
    graphManager.importGraph(filename);
    filename = "������ѧԺ��ͼ.txt";
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
        cin.ignore(); // ������뻺����
        switch (choice)
        {
        case 1:
        {
            if (auth.loginUser(currentUser))
            {
                cout << "\n��¼�ɹ�����ӭ " << currentUser.username << endl;
                system("pause");
                system("cls");
                // ����Ա�˵�
                if (currentUser.isAdmin)
                {
                    Admin::adminMenu(auth, graphManager);
                }
                // ��ͨ�û������˵�
                else
                {
                    FavoritesManager favoritesManager(currentUser.username);
                    int navChoice;
                    do
                    {
                        graphManager.displayNavigationMenu();
                        cin >> navChoice;
                        cin.ignore(); // ������뻺����

                        switch (navChoice)
                        {
                        case 1:
                        {
                            if (graphManager.getGraphCount() == 0)
                            {
                                cout << "û���ѵ���ĵ�ͼ��" << endl;
                                break;
                            }
                            graphManager.displayAvailableGraphs();
                            cout << "������Ҫ�л��ĵ�ͼ��ţ�";
                            int graphIndex;
                            cin >> graphIndex;
                            cin.ignore();
                            if (graphManager.switchGraph(graphIndex))
                            {
                                cout << "�л��ɹ�����ǰ��ͼΪ��"
                                     << graphManager.getCurrentGraphName() << endl;
                            }
                            else
                            {
                                cout << "�л�ʧ�ܣ����������ţ�" << endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            if (graphManager.displayCurrentGraphInfo())
                            {
                                cout << "��ʾ�ɹ���" << endl;
                            }
                            else
                            {
                                cout << "û�п��õĵ�ͼ��" << endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            if (graphManager.depthFirstTraversal())
                            {
                                cout << "������ȱ�����ɣ�" << endl;
                            }
                            else
                            {
                                cout << "û�п��õĵ�ͼ��" << endl;
                            }
                            break;
                        }
                        case 4:
                        {
                            if (graphManager.breadthFirstTraversal())
                            {
                                cout << "������ȱ�����ɣ�" << endl;
                            }
                            else
                            {
                                cout << "û�п��õĵ�ͼ��" << endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            if (!graphManager.isGraphAvailable())
                            {
                                cout << "û�п��õĵ�ͼ��" << endl;
                                break;
                            }
                            graphManager.depthFirstTraversal();
                            cout << endl;
                            string start, end;
                            cout << "������������ƣ�";
                            getline(cin, start);
                            cout << "�������յ����ƣ�";
                            getline(cin, end);

                            if (graphManager.findShortestPath(start, end))
                            {
                                cout << "�Ƿ񱣴��·��������·����(y/n)��";
                                char confirm;
                                cin >> confirm;
                                cin.ignore();
                                if (confirm == 'y' || confirm == 'Y')
                                {

                                    favoritesManager.saveFavoritePath(
                                        graphManager.getCurrentGraphName(),
                                        start, end, graphManager.shortestDistance);
                                    cout << "·���ѱ��浽����·����" << endl;
                                }
                            }
                            else
                            {
                                cout << "·������ʧ�ܣ����ܽڵ㲻���ڻ򲻿ɴ" << endl;
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
                            cout << "����·������գ�" << endl;
                            break;
                        }
                        case 8:
                        {
                            if (!graphManager.isGraphAvailable())
                            {
                                cout << "û�п��õĵ�ͼ��" << endl;
                                break;
                            }
                            string location;
                            int distance;
                            graphManager.breadthFirstTraversal();
                            
                            cout
                                << "�����뵱ǰ�ص����ƣ�";
                            getline(cin, location);
                            cout << "�������������뷶Χ���ף���";
                            cin >> distance;
                            cin.ignore();

                            graphManager.graphs[graphManager.currentIndex].graph.searchNearbyLocations(location, distance);
                            break;
                        }
                        case 0:
                            cout << "��лʹ��У԰����ϵͳ���ټ���" << endl;
                            break;
                        default:
                            cout << "��Ч��ѡ�����������룡" << endl;
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
    cout << "��лʹ��У԰����ϵͳ��" << endl;
    return 0;
}