#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Graph.h"
#include "FavoritesManager.h"
#include "Auth.h"
#include "Admin.h"
using namespace std;

void displayMainMenu()
{
    cout << "********** У԰����ϵͳ **********" << endl;
    cout << "            1. ��¼" << endl;
    cout << "            2. ע��" << endl;
    cout << "            0. �˳�" << endl;
    cout << "**********************************" << endl;
    cout << "��ѡ�������";
}

void displayNavigationMenu()
{
    cout << "********** У԰����ϵͳ�û����� **********" << endl;
    cout << "          1. �л���ǰ��ͼ" << endl;
    cout << "          2. ��ʾ��ͼ��Ϣ" << endl;
    cout << "          3. ������ȱ���" << endl;
    cout << "          4. ������ȱ���" << endl;
    cout << "          5. ·�ߵ���" << endl;
    cout << "          6. �鿴����·��" << endl;
    cout << "          7. ��ճ���·��" << endl;
    cout << "          8. �����ܱߵص�" << endl;
    cout << "          0. �˳�ϵͳ" << endl;
    cout << "******************************************" << endl;
    cout << "��ѡ�������";
}

int main()
{
    AuthManager auth;
    User currentUser;
    GraphManager graphManager;
    DataManager &db = DataManager::getInstance();
    string path = "user.db";
    db.connectDB(path);
   // cout << db.isConnected << '\n';
    auth.loadUsersFromFile();

    int choice;
    do
    {
        displayMainMenu();
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
                        displayNavigationMenu();
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
                            string start,
                                end;
                            cout << "������������ƣ�";
                            getline(cin, start);
                            cout << "�������յ����ƣ�";
                            getline(cin, end);

                            if (graphManager.findShortestPath(start, end))
                            {
                                // ��ȡ��̾��루��Ҫ��Graph���л�ȡ������findShortestPath�Ѽ�¼���룩
                                // ����򻯴�������ͨ��GraphManager��ȡ���루ʵ�����޸�Graph�෵�ؾ��룩
                                cout << "�Ƿ񱣴��·��������·����(y/n)��";
                                char confirm;
                                cin >> confirm;
                                cin.ignore();
                                if (confirm == 'y' || confirm == 'Y')
                                {
                                    // ������Ҫ��ȡʵ�ʾ��룬������Graph�м����洢
                                    // ��ʱʹ��0���棬�����ʵ���޸�
                                    favoritesManager.saveFavoritePath(
                                        graphManager.getCurrentGraphName(),
                                        start, end, 0 // ʵ��Ӧ�滻Ϊ��ʵ����
                                    );
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
                            cout << "�����뵱ǰ�ص����ƣ�";
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
    } while (choice != 0);

    cout << "��лʹ��У԰����ϵͳ��" << endl;
    return 0;
}