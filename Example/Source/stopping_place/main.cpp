// 文件路径名:stopping_place\main.cpp
#include "utility.h"					// 实用程序软件包
#include "stopping_place.h"				// 停车场类的头文件

int main(void)
{
	int maxNum;							// 停车道停止车辆的最大数
	int rate;							// 停单位时间的收费值
	VehicleType ve;						// 车辆信息
	StoppingPlace *pStopingSpace;		// 停车场指针
	int select = 0;						// 功能选择

	cout << "输入停车道停止车辆的最大数与停单位时间的收费值:";
	cin >> maxNum >> rate;				// 输入停车道停止车辆的最大数与停单位时间的收费值
	pStopingSpace = new StoppingPlace(maxNum, rate);// 生成停车场对象	

	while (select != 4)
	{	// 循环处理车辆
		cout << "1. 车辆到达" << endl;
		cout << "2. 车辆离开" << endl;
		cout << "3. 显示状态" << endl;
		cout << "4. 结束" << endl;
		cout << "选择功能:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "输入车辆编号与到达时间:";
			cin >> ve.num >> ve.time;	// 输入车辆编号与到达时间	
			pStopingSpace->Arrive(ve);	// 车辆到达处理
			break;
		case 2:
			cout << "输入车辆编号与离开时间:";
			cin >> ve.num >> ve.time;	// 输入车辆编号与到达时间	
			pStopingSpace->Leave(ve);	// 车辆离开处理
			break;
		case 3:
			pStopingSpace->DisplayStatus();	// 显示停车场与便道中车辆状态
			break;
		}
	}

	delete pStopingSpace;				// 释放停车场对象

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}