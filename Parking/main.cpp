#include <stack>  
#include <vector>  
//#include <deque>  
#include <queue>
#include <iostream>
using namespace std;
int main() {
	stack<int> park; //创建停车场栈park
	stack<int> tmp; //创建临时栈tmp
	queue<int> road; //创建队列road
	stack <int>::size_type i; //栈的长度
	queue <int>::size_type j; //队列长度
	int c = 0;
	int id = 0; //汽车id
	int size = 0; //停车场容量
	while (c != 5) {
		cout << endl << "1.创建停车场";
		cout << endl << "2.汽车入场";
		cout << endl << "3.汽车出场";
		cout << endl << "4.状况查询";
		cout << endl << "5.退出";
		cout << endl << "选择功能(1~5):";
		cin >> c;
		switch (c) {
		case 1:
			cout << "输入停车场容量:";
			cin >> size;
			break;
		case 2:
			cout << "请输入车号:";
			cin >> id;
			i = park.size();
			if (i < size) {
				park.push(id);
				i = park.size();
				cout <<id<< "号驶入停车场" << " 剩余车位" << size - i<<endl;
				break;
			}
			road.push(id);
			j = road.size();
			cout << id << "号驶入便道" << " 共有" << j << "辆等待"<<endl;
			break;
		case 3:
			cout << "请输入车号:";
			cin >> id;
			while(id != park.top()) {
				tmp.push(park.top());
				cout << park.top() << "号 ";
				park.pop();
			}
			cout << "驶出大门" << endl;
			cout << park.top() << "号 驶出停车场"<<endl;
			park.pop();
			while (false == tmp.empty()) {
				park.push(tmp.top());
				cout << tmp.top() << "号 ";
				tmp.pop();
			}
			cout << "重新驶入停车场"<<endl;
			if (false == road.empty()) {
				park.push(road.front());
				cout << road.front() << "号 从便道驶入停车场" << endl;
				road.pop();
			}
			break;
		case 4:
			i = park.size();
			cout << "剩余车位" << size - i << endl;
			j = road.size();
			cout << "共有" << j << "辆等待" << endl;
			break;
		case 5:
			exit(0);
		}
	}
}