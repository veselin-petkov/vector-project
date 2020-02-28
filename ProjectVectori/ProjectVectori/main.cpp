#include "Triangle.h"
#include "Tetrahedron.h"
#include <fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Bulgarian");
	/*Vector a(3, 4, 5);

	Point b(7, 8, 9);
	Point c(3, 4, 4);
	Point d(4, 4, 4);

	if (b == c)
	{
		cout << 1<<endl;
	}
	else cout << 0<<endl;
	Vector f(b, c);

	Point opa1(6, 9, 8);
	Point opa2(15, 4, 7);
	Point opa3(19, 8, 10);
	Triangle aa( opa1, opa2,opa3 );

	aa.triangleType();
	cout << aa.medicenter() << endl;
	cout << aa.area() << endl;
		
	cout << "are de pls"<< endl;
	Line bbb(b, a);
	Line aaa(Point(25, 8, 14), Vector(4, 3, 9));
	Line ccc(Point(12, 1, 5), Vector(1, 2, 3));
	cout<<bbb.getDirection()<<endl;
	cout<<aaa.getAngle(ccc)<<endl;

	cout << "are de pls" << endl;

	b + bbb;

	//Point opa4;
	//cin >> opa4;
	//cout << opa4;
	*/
	ofstream file("result.txt", ios::out);

	Vector b;
	Vector obj1,obj2,obj3;
	Vector normal1;
	Point Obj1, Obj2;
	Line line1;
	Line line2(Obj1, Obj2);
	Triangle triangle1;
	Segment seg;
	Tetrahedron tet;
	unsigned menu,menu1,menu2;
	char end ='y';
	char end1 = 'y';
	double n;
	do
	{
		cout << "1 – Точка" << endl << "2 – Вектор" << endl << "3 – Линия" << endl << "4 – Отсечка" << endl << "5 – Триъгълник" << endl << "6 – Тетраедър" << endl << "0 - Изход" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
			cin >> Obj1;
			cout << "Моля изберете операция за обекта:" << endl;
			cout << "1 - проверка за съвпадане на две точки" << endl;
			cin >> Obj2;
			cout << boolalpha << (Obj1==Obj2) << noboolalpha << endl;

			break;
		case 2:
			cin >> obj1;
			do
			{
			cout << "Моля изберете операция за обекта:" << endl;
			cout << "1 - изчисляване на дължина на вектор" << endl << "2 - изчисляване на посока на вектор" << endl << "3 - проекция на вектор върху друг вектор" << endl
				<< "4 - проверка за нулев вектор" << endl << "5 - проверка за успоредност на два вектора" << endl <<  "6 - проверка за перпендикулярност на два вектора" << endl
				<< "7 - събиране на два вектора" << endl << "8 - умножение на вектор с реално число" << endl << "9 - скаларно произведение на два вектора" << endl
				<< "10 - векторно произведение на два вектора" << endl << "11 - смесено произведение на три вектора" << endl;
			cin >> menu1;
			switch (menu1)
			{
			case 1:cout << obj1.length() << endl;
				file << "Дължина на вектор:" << obj1 << " - " << obj1.length() << endl;
				break;

			case 2:cout << obj1.direction() << endl;
				file << "Посока на вектор:" << obj1.direction() << endl;
				break;
			case 3:
				cin >> obj2;
				cout << obj1.projection(obj2) << endl; 
				file << "Проекция на вектор върху друг вектор:" << obj1 << " и " << obj2 << " - " << obj1.projection(obj2) << endl;
				break;
			case 4:cout << boolalpha << obj1.zeroVector() << noboolalpha << endl;
				file << "Проверка за нулев вектор:" << obj1 << " - " << boolalpha << obj1.zeroVector() << noboolalpha << endl;

				break;
			case 5:
				cin >> obj2;
				cout << boolalpha << obj1.parallelism(obj2) << noboolalpha << endl;
				file << "Проверка за успоредност на два вектора:" << obj1 << " и " << obj2 << " - " << boolalpha << obj1.parallelism(obj2) << noboolalpha << endl;
				break;
			case 6:
				cin >> obj2;
				cout << boolalpha << obj1.perpendicular(obj2) << noboolalpha << endl; 
				file << "Проверка за перпендикулярност на два вектора:" << obj1 << " и " << obj2 << " - " << boolalpha << obj1.perpendicular(obj2) << noboolalpha << endl;
				break;
			case 7:
				cin >> obj2;
				cout << obj1 << " + " << obj2 << " = " << obj1 + obj2 << endl;
				file << "Сбор от два вектора:" << obj1<<" и " << obj2 << " = " << obj1 + obj2 << endl;
				break;
			case 8:
				cout << "Въведете реално число:";
				cin >> n;
				cout << obj1 << " * " << n << " = ";
				file << "Умножение на вектор с реално число:" << obj1 << " и " << n << " = ";
				obj1 *n;
				cout << obj1 << endl;
				file << obj1 << endl;
				break;
			case 9:
				cin >> obj2;
				cout << obj1 << " * " << obj2 << " = " << obj1 * obj2 << endl;
				file << "Скаларно произведение на два вектора:" << obj1 << " и " << obj2 << " = " << obj1 * obj2 << endl;
				break;
			case 10:
				cin >> obj2;
				cout << obj1 << " ^ " << obj2 << " = ";
				normal1 = obj1 ^ obj2;
				cout << normal1 << endl;
				file << "Векторно произведение на два вектора:" << obj1 << " и " << obj2 << " = " << normal1 << endl;
				break;
			case 11:
				cin >> obj2;
				cin >> obj3;
				cout << "(" << obj1 << " * " << obj2 << ")" << " * " << obj3 << " = "<< obj1(obj2,obj3) << endl;
				file << "Смесено произведение на три вектора:" << "(" << obj1 << " * " << obj2 << ")" << " * " << obj3 << " = " << obj1(obj2, obj3) << endl;
				break;
			default:
				break;
			}
			cout << "Желаете ли да изберете нова операция (y/n)?";
			cin >> end1;
			} while (end1 !='n');
			cout << "Желаете ли да изберете нов геометричен обект(y/n)?";
			cin >> end;
		break;
		case 3:
			cin >> line1;
			do
			{
			//line1.setLinePV(Obj1,obj1);
				cout << "Моля изберете операция за обекта:" << endl;
				cout << "1 - намиране на посока на правата" << endl << "2 - намиране на нормален вектор" << endl << "3 - намиране на ъгъл между две прави" << endl
					<< "4 - проверка дали точка лежи на права" << endl << "5 - проверка дали правата е успоредна на друга права" << endl;
				cin >> menu2;
				switch (menu2)
				{
				case 1:cout << line1.getDirection() << endl; 
				file << "Посока на правата:" << line1 << " - " << line1.getDirection() << endl;
				break;
				case 2:cout << line1.getNormalVector() << endl;
				file << "Намиране на нормален вектор:" << line1 << " - " << line1.getNormalVector() << endl;
				break;
				case 3:
					cin >> line2;
					cout << line1.getAngle(line2) << endl; 
					file << "Намиране на нормален вектор:" << line1 << " и " << line2 << " - " << line1.getAngle(line2) << endl; break;
				case 4:
				case 5:
				default:
					break;
				}
				cout << "Желаете ли да изберете нова операция (y/n)?";
				cin >> end1;
		} while (end1 != 'n');
		cout << "Желаете ли да изберете нов геометричен обект(y/n)?";
		cin >> end;
				break;
		case 4:
			do
			{
			cin >> seg;
			cout << "Моля изберете операция за обекта:" << endl;
			cout << "1 - намиране на дължина на отсечка" << endl << "2 - намиране на среда на отсечка" << endl << "3 - проверка дали точка лежи на отсечка" << endl;
			cin >> menu1;
			switch (menu1)
			{
			case 1:cout << seg.segmentLength() << endl;
				file << "Дължина на отсечка:" << seg << " - " << seg.segmentLength() << endl;
				break;
			case 2:cout << seg.segmentMiddle() << endl; 
				file << "Намира среда на отсечка:" << seg << " - " << seg.segmentMiddle() << endl;
				break;
			case 3:
			default:
				break;
			}
			cout << "Желаете ли да изберете нова операция (y/n)?";
			cin >> end1;
			} while (end1 != 'n');
			cout << "Желаете ли да изберете нов геометричен обект(y/n)?";
			cin >> end;
			break;
		case 5:
			cin >> triangle1;
			do
			{
			cout << "Моля изберете операция за обекта:" << endl;
			cout << "1 - определяне вида на триъгълника" << endl << "2 - намиране лицето на триъгълника" << endl << "3 - намиране периметъра на триъгълника" << endl
				<< "4 - намиране медицентъра на триъгълника" << endl;
			cin >> menu1;
			switch (menu1)
			{
			case 1:triangle1.triangleType(); 
				//char * buffer = new char[50];
			//	file.read(buffer, 50);
				//file << "Вида на триъгълника:" << triangle1 << " - " << triangle1.triangleType() << endl;
				break;
			case 2:cout<<triangle1.area()<<endl; 
				file << "Лице на триъгълника:" << triangle1 << " - " << triangle1.area() << endl;
				break;
			case 3:cout << triangle1.perimeter() << endl;
				file << "Периметър на триъгълника:" << triangle1 << " - " << triangle1.perimeter() << endl;
				break;
			case 4:cout << triangle1.medicenter() << endl;
				file << "Медицентър на триъгълника:" << triangle1 << " - " << triangle1.medicenter() << endl;
				break;
			default: break;
			}
			cout << "Желаете ли да изберете нова операция (y/n)?";
			cin >> end1;
		} while (end1 != 'n');
		cout << "Желаете ли да изберете нов геометричен обект(y/n)?";
		cin >> end;
		break;
		case 6:
			cin >> tet;
			do
			{
			cout << "Моля изберете операция за обекта:" << endl;
			cout << "1 - проверка за правилен тетраедър" << endl << "2 - проверка за ортогоналност" << endl << "3 - намиране околна повърхнина" << endl;
			cin >> menu1;
			switch (menu1)
			{
			case 1:
				cout << boolalpha << tet.regural() << noboolalpha << endl;
				file << "Проверка за правилен тетраедър:" << tet << " - " << boolalpha << tet.regural() << noboolalpha << endl;
				break;
			case 2: break;
			case 3:
				cout << tet.surroundingArea()<<endl;
				file << "Намиране околна повърхнина на тетраедър:" << tet << " - " << tet.surroundingArea() << endl;

			default:break;
			}
			cout << "Желаете ли да изберете нова операция (y/n)?";
			cin >> end1;
		} while (end1 != 'n');
		cout << "Желаете ли да изберете нов геометричен обект(y/n)?";
		cin >> end;
		break;

		default:
			break;
		}
		if (end == 'n')break;
	} while (menu!= 0 || (menu > 0 && menu < 6));
	char fileChar = 'y';
	cout << "Желаете ли да запишете да запишете всички данни във файл(y/n)?";
	cin >> fileChar;
	if (fileChar == 'n')
	{
		file.clear();
	}
	file.close();
	return 0;
}