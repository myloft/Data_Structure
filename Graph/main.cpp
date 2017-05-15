#include "grapham.h"
#include <iostream>

using namespace std;

int main() {
    GraphAM<int> gp;
	int c = 0, kind, tmp1, tmp2, a, b;
    cout << "1.建立图" << endl;
    cout << "2.清空图" << endl;
    cout << "3.插入顶点" << endl;
    cout << "4.插入边" << endl;
    cout << "5.删除顶点" << endl;
    cout << "6.删除边" << endl;
    cout << "7.修改顶点的值" << endl;
    cout << "8.DFS遍历" << endl;
    cout << "9.BFS遍历" << endl;
	cout << "10.退出" << endl;
    while (1) {
        cout << "输入选项：";
		cin >> c;
        switch (c) {
            case 1:
				cout << "请输入图类型(0无向图，1有向图，2无向网，3有向网)" << endl;
				cin >> kind;
                cout<<"最大顶点个数:";
                cin >> tmp1;
                gp.InitGraph(kind, tmp1);
                gp.CreateGraph();
                break;
            case 2:
                gp.Clear();
                break;
            case 3: {
                cout << "插入顶点的值：";
				cin >> tmp2;
                gp.InsertVex(tmp2);
            }
                break;
            case 4: {
                int w;
                cout << "请输入要插入边的端点：";
                cin >> a >> b;
                if (gp.GetKind() > 1) {
                    cout << "请输入权值：";
                    cin >> w;
                    gp.InsertEdge(a, b, w);
                } else
                    gp.InsertEdge(a, b);
            }
                break;
            case 5: {
				cout << "删除的顶点：";
                cin >> tmp2;
                gp.DeleteVex(tmp2);
            }
                break;
            case 6: {
                cout << "删除的边的端点：";
                cin >> a >> b;
                gp.DeleteEdge(a, b);
            }
                break;
            case 7: {
                cout << "原顶点值：";
                cin >> a;
                cout << "新值：";
                cin >> b;
                gp.SetElem(a, b);
            }
                break;
            case 8: {
                int s;
                cout << "开始点:";
                cin >> s;
                gp.DFS(s);
            }
                break;
            case 9: {
                int s;
                cout << "开始点:";
                cin >> s;
                gp.BFS(s);
            }
                break;
            case 10:
				exit(0);
        }
        cout << endl;
    }
}
