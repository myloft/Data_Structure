#include "grapham.h"
#include <iostream>
using namespace std;
int main(int argc, char const * argv[]) {
    int c = -1;
    int tmp1 = 0;
    int tmp2 = 0;
	int tmp3 = 0;
	GraphAM<int> GraphAM;
    while (c != 0) {
        cout << "1.构造图" << endl;
        cout << "2.插入顶点" << endl;
        cout << "3.插入边" << endl;
        cout << "4.删除顶点" << endl;
        cout << "5.删除边" << endl;
        cout << "6.更新顶点值" << endl;
        cout << "7.查询边是否存在" << endl;
        cout << "8.DFS遍历" << endl;
        cout << "9.BFS遍历" << endl;
        cout << "10.退出" << endl;
		cout << "请输入选项:";
        cin >> c;
        switch (c) {
        case 1:
            tmp1 = 0;
			cout << "0:无向图　1:有向图　2:无向网　3:有向网" << endl;
			cout << "图类型：";
			cin >> tmp1;
			GraphAM.InitGraph(tmp1, 100);
			GraphAM.CreateGraph();
            break;
        case 2:
            tmp1 = 0;
            cout << "插入值:";
            cin >> tmp1;
            cout << "插入成功，为第" << GraphAM.InsertVer(tmp1) << "号节点" << endl;
            break;
        case 3:
            tmp1 = tmp2 = 0;
            cout << "两顶点:";
            cin >> tmp1 >> tmp2;
            if(GraphAM.EdgeExsit(tmp1,tmp2)){
            	cout<<"已存在"<<endl;
            	break;
            }
            if (GraphAM.kind > 2) {
                cout << "请输入权值:";
                cin >> tmp3;
				GraphAM.InsertEdge(tmp1, tmp2, tmp3);
            } else {
				GraphAM.InsertEdge(tmp1, tmp2);
            }
            cout << "插入成功" << endl;
            break;
        case 4:
            tmp1 = 0;
            cout << "删除的顶点值:";
            cin >> tmp1;
			GraphAM.DeleteVer(tmp1);
            cout << "删除成功" << endl;
            break;
        case 5:
            tmp1 = tmp2 = 0;
            cout << "删除边的顶点值:";
            cin >> tmp1 >> tmp2;
			GraphAM.DeleteEdge(tmp1, tmp2);
            cout << "删除成功" << endl;
            break;
        case 6:
            tmp1 = tmp2 = 0;
            cout << "更新的顶点值:";
            cin >> tmp1;
            cout << "更新值:";
            cin >> tmp2;
			GraphAM.SetElem(tmp1, tmp2);
            cout << "更新成功" << endl;
            break;
        case 7:
            tmp1 = tmp2 = 0;
            cout << "查询边的顶点值";
            cin >> tmp1 >> tmp2;
            if (GraphAM.EdgeExsit(tmp1, tmp2)) {
                cout << "存在" << endl;
            } else {
                cout << "不存在" << endl;
            }
            break;
        case 8:
			GraphAM.TraverseDFS(0);
            break;
        case 9:
			cout << "未实现";
            break;
        }
    }
	GraphAM.Clear();
	return 0;
}