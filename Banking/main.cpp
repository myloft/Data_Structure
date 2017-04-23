#include <queue>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ofstream outfile;
	outfile.open("bank.log",ios::out);
	int free_queue(int size1, int size2, int size3, int size4); //优先队列函数声明
	int customer_id = 0;
	int customer_count1 = 0, customer_count2 = 0, customer_count3 = 0, customer_count4 = 0; //办理人数记录
	int time_count1 = 0, time_count2 = 0, time_count3 = 0, time_count4 = 0; //逗留时间记录
	bool windows1 = 0, windows2 = 0, windows3 = 0, windows4 = 0; //窗口状态
	int tmp_id1 = 0, tmp_id2 = 0, tmp_id3 = 0, tmp_id4 = 0;
	int tmp_time1, tmp_time2, tmp_time3, tmp_time4;//各窗口开始办理时间
	queue<int> line1, line2, line3, line4; //窗口队列
	queue <int>::size_type line1_size, line2_size, line3_size, line4_size; //队列长度
	line1_size = line1.size();
	line2_size = line2.size();
	line3_size = line3.size();
	line4_size = line4.size();
	default_random_engine Time(time(NULL)); //随机数生成器
	uniform_int_distribution<>arrive(0, 2880000); //客户到达时间范围单位ms
	uniform_int_distribution<>handle(48000, 72000); //客户办理时间范围单位ms
	int customer_arrive[100]; //客户到达时间数组
	int customer_handle[100]; //客户处理时间数组
	for (int i=0; i <= 99; i++) {
		customer_arrive[i]= arrive(Time); //随机生成到达时间
		customer_handle[i] = handle(Time); //随机生成办理时间
	}
	sort(customer_arrive, customer_arrive + 100); //对用户到达数组升序排序
	for (int bank_time = 0; bank_time <= 2952000; bank_time++) { //初始化银行时间，初始化客户
		if (bank_time == customer_arrive[customer_id]) {
			switch (int c = free_queue(line1_size, line2_size, line3_size, line4_size)) {
			case 1:
				line1.push(customer_id);
				cout << bank_time/360000+9<<"h" <<(bank_time%360000)/6000<<"m"<< ((bank_time % 360000)%6000)/100<<"s" <<": "<< customer_id + 1 << " 号客户在 1 号窗口排队" << endl;
				outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << customer_id + 1 << " 号客户在 1 号窗口排队" << endl;
				line1_size = line1.size();
				break;
			case 2:
				line2.push(customer_id);
				cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << customer_id + 1 << " 号客户在 2 号窗口排队" << endl;
				outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << customer_id + 1 << " 号客户在 2 号窗口排队" << endl;
				line2_size = line2.size();
				break;
			case 3:
				line3.push(customer_id);
				cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << customer_id + 1 << " 号客户在 3 号窗口排队" <<  endl;
				outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << customer_id + 1 << " 号客户在 3 号窗口排队" << endl;
				line3_size = line3.size();
				break;
			case 4:
				line4.push(customer_id);
				cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << customer_id + 1 << " 号客户在 4 号窗口排队" << endl;
				outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << customer_id + 1 << " 号客户在 4 号窗口排队" << endl;
				line4_size = line4.size();
				break;
			}
			customer_id = customer_id + 1;
		}
		//cout << line1.empty();
		if (windows1 == false && line1.empty() == false && bank_time <= 2880000) {
			tmp_time1 = bank_time;
			cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << line1.front() + 1 << " 号客户在 1 号窗口开始办理" << endl;
			outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << line1.front() + 1 << " 号客户在 1 号窗口开始办理" << endl;
			tmp_id1 = line1.front();
			windows1 = true;
		}
		if (windows2 == false && line2.empty() == false && bank_time <= 2880000) {
			tmp_time2 = bank_time;
			cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << line2.front() + 1 << " 号客户在 2 号窗口开始办理" << endl;
			outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << line2.front() + 1 << " 号客户在 2 号窗口开始办理" << endl;
			tmp_id2 = line2.front();
			windows2 = true;
		}
		if (windows3 == false && line3.empty() == false && bank_time <= 2880000) {
			tmp_time3 = bank_time;
			cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << line3.front() + 1 << " 号客户在 3 号窗口开始办理" << endl;
			outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << line3.front() + 1 << " 号客户在 3 号窗口开始办理" << endl;
			tmp_id3 = line3.front();
			windows3 = true;
		}
		if (windows4 == false && line4.empty() == false && bank_time <= 2880000) {
			tmp_time4 = bank_time;
			cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << line4.front() + 1 << " 号客户在 4 号窗口开始办理" << endl;
			outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << line4.front() + 1 << " 号客户在 4 号窗口开始办理" << endl;
			tmp_id4 = line4.front();
			windows4 = true;
		}
		if (bank_time == tmp_time1 + customer_handle[tmp_id1] && line1.empty() == false) {
			cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << tmp_id1 + 1 << " 号客户在 1 号窗口办理完成" << endl;
			outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << tmp_id1 + 1 << " 号客户在 1 号窗口办理完成" << endl;
			line1.pop();
			windows1 = false;
			customer_count1++;
			time_count1 = bank_time - customer_arrive[tmp_id1] + time_count1;
		}
		if (bank_time == tmp_time2 + customer_handle[tmp_id2] && line2.empty() == false) {
			cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << tmp_id2 + 1 << " 号客户在 2 号窗口办理完成" << endl;
			outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << tmp_id2 + 1 << " 号客户在 2 号窗口办理完成" << endl;
			line2.pop();
			windows2 = false;
			customer_count2++;
			time_count2 = bank_time - customer_arrive[tmp_id2] + time_count2;
		}
		if (bank_time == tmp_time3 + customer_handle[tmp_id3] && line3.empty() == false) {
			cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << tmp_id3 + 1 << " 号客户在 3 号窗口办理完成" << endl;
			outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << tmp_id3 + 1 << " 号客户在 3 号窗口办理完成" << endl;
			line3.pop();
			windows3 = false;
			customer_count3++;
			time_count3 = bank_time - customer_arrive[tmp_id3] + time_count3;
		}
		if (bank_time == tmp_time1 + customer_handle[tmp_id4] && line4.empty() == false) {
			cout << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << tmp_id4 + 1 << " 号客户在 4 号窗口办理完成" << endl;
			outfile << bank_time / 360000 + 9 << "h" << (bank_time % 360000) / 6000 << "m" << ((bank_time % 360000) % 6000) / 100 << "s" << ": " << tmp_id4 + 1 << " 号客户在 4 号窗口办理完成" << endl;
			line4.pop();
			windows4 = false;
			customer_count4++;
			time_count4 = bank_time - customer_arrive[tmp_id4] + time_count4;
		}		
	}
	int m, s;
	int time_all = time_count1 + time_count2 + time_count3 + time_count4;
	int customer_count = customer_count1 + customer_count2 + customer_count3 + customer_count4;
	int time_average = time_all / customer_count;
	m = time_average / 6000;
	cout << "银行停止业，未开始办理的客户请离开" << endl;
	cout << "今日共办理" << customer_count << "件业务" << endl;
	cout << "1号窗口办理" << customer_count1 << "件" << endl;
	cout << "2号窗口办理" << customer_count2 << "件" << endl;
	cout << "3号窗口办理" << customer_count3 << "件" << endl;
	cout << "4号窗口办理" << customer_count4 << "件" << endl;
	cout << "客户平均逗留" << m <<"分钟"<< endl;
	outfile << "今日共办理" << customer_count << "件业务" << endl;
	outfile << "1号窗口办理" << customer_count1 << "件" << endl;
	outfile << "2号窗口办理" << customer_count2 << "件" << endl;
	outfile << "3号窗口办理" << customer_count3 << "件" << endl;
	outfile << "4号窗口办理" << customer_count4 << "件" << endl;
	outfile << "客户平均逗留" << m << "分钟" << endl;
	outfile.close();
}

int free_queue(int size1,int size2,int size3,int size4) { //优先队列判断函数
	if (size1 <= size2&&size1 <= size3&&size1 <= size4) {
		return 1;
	}
	if (size2 <= size1&&size2 <= size3&&size2 <= size4) {
		return 2;
	}
	if (size3 <= size1&&size3 <= size2&&size3 <= size4) {
		return 3;
	}
	if (size4 <= size1&&size4 <= size2&&size4 <= size3) {
		return 4;
	}
}