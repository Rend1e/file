#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//sozdanie structury
struct id {
	string sername;
	string sport;
	string lvl;
	string club;
};
int main() {
	//zapominayushaya danniye stroka
	string str[16];

	int k = 0;

	//4 dannyukh (4 chela)
	id first;
	id second;
	id third;
	id fourth;

	//open file1 (input)
	ifstream f1;

	//ishet file1 pod nazvaniem read.txt
	f1.open("read.txt");

	//uslovie otkritiya (esli on ne otkryt to vivod "file not found", esli otkryt "file opened" i ravota s faylom)
	if (!f1.is_open()) {
		cout << "file not found" << endl;
	}
	else {
		cout << "file opened" << endl;

		
		//poka file otrit
		while (!f1.eof()) {
			
			for (int i = 0; i < 16; i++) {
				//schitivaet kazhdoe slovo
				f1 >> str[i];

				//vspomogatelnie peremennie dlya opredeleniya sleduyushego cheloveka i ego dannykh
				int x = i % 4;
				int y = i / 4;
				switch (x)
				{
				case(0):
					switch (y) {
						//zapominanie imeni
					case(0):
						first.sername = str[i];
						break;
					case(1):
						second.sername = str[i];
						break;
					case(2):
						third.sername = str[i];
						break;
					case(3):
						fourth.sername = str[i];
						break;
					default:
						break;
					}
					break;
				case(1):
					switch (y)
					{
						//zapominanie sporta kotorym on zanimaetsya
					case(0):
						first.sport = str[i];
						break;
					case(1):
						second.sport = str[i];
						break;
					case(2):
						third.sport = str[i];
						break;
					case(3):
						fourth.sport = str[i];
						break;
					default:
						break;
					}
					break;
				case(2):
					switch (y)
					{
						//zapominanie razryada
					case(0):
						first.lvl = str[i];
						break;
					case(1):
						second.lvl = str[i];
						break;
					case(2):
						third.lvl = str[i];
						break;
					case(3):
						fourth.lvl = str[i];
						break;
					default:
						break;
					}
					break;
				case(3):
					switch (y)
					{
						//zapominanie sport cluba
					case(0):
						first.club = str[i];
						break;
					case(1):
						second.club = str[i];
						break;
					case(2):
						third.club = str[i];
						break;
					case(3):
						fourth.club = str[i];
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
			}
				//esli razryad = 1
				//k - kolichestvo ludey imeyushikh 1 razryad
				if (first.lvl == "1") {
					k++;
				}
				if (second.lvl == "1") {
					k++;
				}
				if (third.lvl == "1") {
					k++;
				}
				if (fourth.lvl == "1") {
					k++;
				}
				
		}
		
	}
	//zakritie file1 (input)
	f1.close();
	cout << "razryad pervogo " << first.lvl << endl;

	//open file2 (output)
	ofstream f2;

	//nazvanie file2
	string path;

	//vvod nazvaniya file2
	cout << "input name file for output" << endl;
	getline(cin, path);

	f2.open(path + ".txt");
	f2 << "kol-vo sportsmenov imeyushikh 1 razryad: "<< k << endl;

	//zakrutie file2
	f2.close();
}