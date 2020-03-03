#include<iostream>
#include<vector>
#include<string>
using namespace std;
void showInfo(vector<int> v)
{
	for (auto i = v.begin(); i != v.end(); i++)
	{
		cout << *i << endl;
	}
} 
int main()
{

	//string name;
	//string fullname;
	//cout << " enter your full name" << endl;
	//getline(cin, fullname);//nhap tu ban phim 
	//cout << fullname << endl;
	//name = "ngoc vinh";
	//name.push_back('a');
	//cout << name;
	/*
	insert(position, value);
	clear();
	erase(position); or erase(from,to);//xoa nhieu phan tu;
	assign(size,value) gan lai gia tri cho vecto
	at(position) front(), back() truy cap den vi tri phan tu cho truoc
	*/
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(80);
	v1.push_back(50);
	v1.push_back(40);
	cout << " size " << v1.size() << endl;
	/*for( int i=0;i< v1.size()-1; i++)
		for (int j = i + 1; j < v1.size(); j++)
		{
			int k=v1->at(i).size()
		}*/
	/*cout << " First element " << v1.front() << endl;
	cout << " last element " << v1.back() << endl;
	cout << "  element at positive " << v1.at(2) << endl;
	showInfo(v1);
	v1.insert(v1.begin()+2, '41');
	cout << " -------" << endl;
	showInfo(v1);*/

	
}
