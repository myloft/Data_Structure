#include "grapham.h"
#include <iostream>

using namespace std;

int
main(int argc, char const * argv[]) {
    int c = -1;
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    GraphAM<int> g;
    while (c != 0) {
        cout << "1.交互式构造图" << endl;
        cout << "2.插入顶点" << endl;
        cout << "3.插入边" << endl;
        cout << "4.删除顶点" << endl;
        cout << "5.删除边" << endl;
        cout << "6.更新顶点值" << endl;
        cout << "7.查询边是否存在" << endl;
        cout << "8.DFS遍历" << endl;
        cout << "9.BFS遍历" << endl;
        cout << "0.exit" << endl;
        cin >> c;
        switch (c) {
        case 1:
            temp1 = 0;
            cout << "请输入图的类型　0无向图　1有向图　2无向网　3有向网：";
            cin >> temp1;
            g.InitGraph(temp1, 100);
            g.CreateGraph();
            break;
        case 2:
            temp1 = 0;
            cout << "请输入要插入的顶点值:";
            cin >> temp1;
            cout << "插入成功，为第" << g.InsertVer(temp1) << "号节点" << endl;
            break;
        case 3:
            temp1 = temp2 = 0;
            cout << "请输入边的两顶点:";
            cin >> temp1 >> temp2;
            if (g.kind > 2) {
                cout << "请输入权值:";
                cin >> temp3;
                g.InsertEdge(temp1, temp2, temp3);
            } else {
                g.InsertEdge(temp1, temp2);
            }
            cout << "插入成功" << endl;
            break;
        case 4:
            temp1 = 0;
            cout << "请输入要删除的顶点值:";
            cin >> temp1;
            g.DeleteVer(temp1);
            cout << "删除成功" << endl;
            break;
        case 5:
            temp1 = temp2 = 0;
            cout << "请输入要删除的边的顶点值:";
            cin >> temp1 >> temp2;
            g.DeleteEdge(temp1, temp2);
            cout << "删除成功" << endl;
            break;
        case 6:
            temp1 = temp2 = 0;
            cout << "请输入要更新的顶点值:";
            cin >> temp1;
            cout << "请输入要更新为的值:";
            cin >> temp2;
            g.SetElem(temp1, temp2);
            cout << "更新成功" << endl;
            break;
        case 7:
            temp1 = temp2 = 0;
            cout << "请输入要查询的边的顶点值";
            cin >> temp1 >> temp2;
            if (g.EdgeExsit(temp1, temp2)) {
                cout << "有" << endl;
            } else {
                cout << "没找到" << endl;
            }
            break;
        case 8:
            g.TraverseDFS(0);
            break;
        case 9:
            break;
        }
    }
    return 0;
}