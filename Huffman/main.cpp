#include "node.h"
#include "encode.h"
#include "decode.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
		int c = 0;
		string testMessage, enc;
		table testTable;
		huffTable ht;
		fstream encodeio, decodeio, table, raw;
		encodeio.open("ToBeTran.txt", ios::out|ios::in);
		decodeio.open("CodeFile.txt", ios::out|ios::in);
		raw.open("TextFile.txt", ios::out);
		table.open("code.txt", ios::out);
		node* huffTree;
		while (c != 6) {
			cout << endl << "1. 输入原文";
			cout << endl << "2. 从文件读取原文";
			cout << endl << "3. 从文件读取译文";
			cout << endl << "4. 统计字符出现频率";
			cout << endl << "5. 输出编码集";
			cout << endl << "6. 输出译文";
			cout << endl << "7. 输出原文";
			cout << endl << "8. 退出";
			cout << endl << "选择功能(1~8):";
			cin >> c;
			switch (c) {
			case 1:
				cout << "输入原文:" << endl;
				cin.ignore();
				getline(cin, testMessage);
				testTable = getFrequencies(testMessage);
				cout << "输入完成" << endl;
				encodeio << testMessage << endl;
				break;
			case 2:
				getline(encodeio, testMessage);
				testTable = getFrequencies(testMessage);
				cout << "读取原文:"<< testMessage << endl;
				break;
			case 3:
				getline(decodeio, enc);
				cout << "读取译文:" << enc;
			case 4:
				printfTable(testTable);
				huffTree = buildTree(testTable);
				cout << "字符数量:" << testTable.size() << endl;
				break;
			case 5:
				generateCode(huffTree, ht);
				for (huffTable::iterator it = ht.begin(); it != ht.end(); ++it) {
					cout << it->first << "=>" << it->second << endl;
					table << it->first << "=>" << it->second << endl;
				}
				table.close();
				break;
			case 6:
				enc = encode(ht, testMessage);
				cout << "输出译文:" << enc << endl;
				decodeio << enc << endl;
				break;
			case 7:
				cout << "输出原文:" << decode_huff(huffTree, enc);
				raw << decode_huff(huffTree, enc);
			case 8:
				encodeio.close();
				decodeio.close();
				table.close();
				delete huffTree;
				exit(0);
			}
		}
}
