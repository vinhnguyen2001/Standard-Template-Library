#include<iostream>
using namespace std;
struct Car
{
	char owner[100];
	char brand[100];
	char color[100];
	int weight;
	
};
struct Student
{
	char ID[20];
	char name[100];
	int age;
	float mark;
	char address[100];
	Car car;
};
void showInfo(Student* s)
{
	cout << " ---------Student Info-------\n";
	cout << "  name: " << s->name << endl;
	cout << "  address :" << s->address << endl;
	cout << " age " << s->age << endl;
	cout << " mark " << s->mark << endl;
	cout << " car " << s->car.color << endl;
	cout << "-----------------------------\n" << endl;


}
void getInfo(Student* s)
{
	cout << " ---------Student Info-------\n";
	cout << "Name: " << endl;
	cin.getline(s->name, 200);
	cout<<"Address :"<< endl;
	cin.getline(s->address, 200);
	cout << "  age " << endl;
	cin >> s->age;
	cout << "  mark " << endl;
	cin >> s->mark;
	cout << "  car " << endl;
	cin >> s->car.color;
	

}
int main()
{
	Student s;
	Student* sPtr ;
	sPtr = &s;
	getInfo(sPtr);
	showInfo(sPtr);
}

//struct sinhvien
//{
//    char hoten[50];
//    char ngaysinh[20];
//    float cannang;
//};
//
//void Xuat1SV(sinhvien x)
//{
//    cout << "Ten Sinh Vien: " << x.hoten << endl;
//    cout << "Ngay sinh: " << x.ngaysinh << endl;
//}
//void Nhap1SV(sinhvien& x)
//{
//
//    float cn;
//    cout << "Ten Sinh Vien: ";
//    cin.getline(x.hoten, 50);
//
//    cout << "Ngay sinh: ";
//    cin.getline(x.ngaysinh, 20);
//
//    cout << "Can nang: ";
//    cin >> cn;
//    x.cannang = cn;
//    cin.ignore();
//
//
//
//}
//
//
//void main()
//{
//    sinhvien dssv[3];
//    int i = 0;
//    //-------Nhap SV
//    for (i = 0; i < 3; i++)
//    {
//
//        cout << "Nhap sinh vien thu " << i + 1 << endl << "---------------------------" << endl;
//        Nhap1SV(dssv[i]);
//        cout << endl;
//    }
