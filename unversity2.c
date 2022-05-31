#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <map>
#include <nlohmann/json.hpp>
#include <stdio.h>

using namespace std;

struct Person {     //Структура Людина
	string name;    //Ім'я
	string fname;   //Прізвище
	double cash;    //Гроші
	virtual void getSalary(double money) {      //Отримання зарплати
		this->cash += money;
	};

};

struct StudentBook {      //Структура заліковка
	map<string, vector<int>> book;     //Контейнер із даними (предемет - оцінки)

	StudentBook()   //Конструктор
	{
		book.insert({ "Math",vector<int>() });
		book.insert({ "Biology",vector<int>() });
		book.insert({ "Art",vector<int>() });
		book.insert({ "Physics",vector<int>() });
		book.insert({ "Sport",vector<int>() });
	}

	void setScore(string lesson, int score) {       //Поставити оцінку
		this->book[lesson].push_back(score);        //Добавляє оцінку у вектор за назвою предмета
	}

	double avarageScore(string lesson) {       //Підрахунок середнього балу
		if (book.find(lesson) != book.end()) {      //Перевірка на існуючий предмет. Якщо нема,то метод повертає -1
			if (book[lesson].size() != 0) {     //Перевірка на наявність оцінок
				double score = 0.0;     //Змінна для підрахунку
				for (auto i : book[lesson]) {		//Цикл оцінок
					score += i;     //Додавання всіх оцінок 
				}
				score /= book[lesson].size();      //Ділення на кількість оцінок для підрахунку середнього балу
				return score;       //Повернення числа
			}
			else {
				return 0;
			}
		}
		else {
			return -1;
		}
	}

	double avarageScore() {     //Підрахунок середнього балу по всіх предметах
		int score = 0.0;        //Змінна для підрахунку
		for (auto i : this->book) {     //Цикл предметів
			score += this->avarageScore(i.first);   //Підрахунок середнього балу з усіх предметів
		}
		score /= this->book.size();	    //Ділення на кількість предметів для підрахунку середнього балу
		return score;     //Повернення числа
	}

	~StudentBook()
	{

	}
};
struct Student : public Person {       //Структура Студента на основі класу Людини
	StudentBook book;       //Змінна заліковка 

	Student()       //Значення за замовчуванням
	{
		name = "noname";
		fname = "no family name";
		cash = 0.0;

	}
	Student(string name, string fname, double cash) 	//Значення введені користувачем 
	{
		this->name = name;
		this->fname = fname;
		this->cash = cash;
	}
	Student(string name, string fname, double cash, StudentBook book)    //Значення введені користувачем з урахуванням заліковки
	{
		this->name = name;
		this->fname = fname;
		this->book = book;
		this->cash = cash;
	}

	friend ostream& operator<<(ostream& os, Student& other) {         //Перегрузка оператора вивода строки на екран. cout<< 

		os << other.name << " " << other.fname << " cash: " << other.cash << " avarage score: " << other.book.avarageScore();         // виводить (ім'я, прізвище, гроші, середній бал)
		return os;
	}

	string toString() {
		return this->name + " " + this->fname + " cash: " + to_string(this->cash) + " avarage score:" + to_string(this->book.avarageScore());
	}

	void getSalary(int money) {        //Перевизначення метода для студента
		this->cash += money * this->book.avarageScore();       //Зарплата додається з урахуванням середнього балу
	}

	string ToJson() {       //Метод серіалізації данних в JSON.
		string js = "";
		nlohmann::json j{};     //Змінна серіалізації.
		j["name"] = this->name;     //Ім'я
		j["fname"] = this->fname;   //прізвище
		j["cash"] = this->cash;     //гроші
		j["book"] = this->book.book;    //заліковка

		return j.dump();    //повертає строку

	}
	void fromJson(string json) {    //Десеріалізує значення строки і присвоює значення об'єкту

		nlohmann::json j = nlohmann::json::parse(json);     //Перевод значення.
		this->name = j["name"].get<std::string>();
		this->fname = j["fname"].get<std::string>();
		this->cash = j["cash"].get<double>();
		j["book"].get_to<map<string, vector<int>>>(this->book.book);
	}

	~Student()
	{

	}
};

struct Worker : public Person {     //Структура Працівника на основі класу Людина
	int experience;     //Змінна досвіду роботи
	Worker()
	{
        
		name = "noname";
		fname = "no family name";
		cash = 0.0;
		experience = 1;

	}
	Worker(string name, string fname, int experience, double cash)      //Значення введені користувачем
	{

		this->name = name;
		this->fname = fname;
		this->cash = cash;
		this->experience = experience;

	}

	string ToJson() {       //Метод серіалізації данних в JSON.
		string js = "";
		nlohmann::json j{};
		j["name"] = this->name;
		j["fname"] = this->fname;
		j["cash"] = this->cash;
		j["experience"] = this->experience;

		return j.dump();

	}
	void fromJson(string json) {    //Десеріалізує значення строки і присвоює значення об'єкту

		nlohmann::json j = nlohmann::json::parse(json);
		this->name = j["name"].get<std::string>();
		this->fname = j["fname"].get<std::string>();
		this->cash = j["cash"].get<double>();
		this->experience = j["experience"].get<int>();
	}

	void getSalary(int money) {     //Перевизначення метода для студента
		this->cash += money * this->experience;     //Зарплата додається з урахуванням досвіду роботи.
	}
	string toString() {     //Перегрузка оператора вивода строки на экран. cout<<
		return this->name + " " + this->fname + " cash: " + to_string(this->cash) + " "+to_string(this->experience)+"years of working.";        // виводить (ім'я, прізвище, гроші, досвід роботи)
	}


	~Worker()
	{

	}
};

struct Teacher : public Person {        //Структура Викладача на основі класу Людина.
	string lesson;  //Змінна назви предмета

	Teacher()
	{
	    //Додавання стандартних предметів.
		lesson = "no lesson";
		name = "noname";
		fname = "no family name";
		cash = 0.0;
	}
	Teacher(string name, string fname, string lesson, double cash)      //значення введені користувачем.
	{
		this->lesson = lesson;
		this->name = name;
		this->fname = fname;
		this->cash = cash;
	}
	void getSalary(int money) {     //Стандартний метод отримання зарплати.
		this->cash += money;
	}

	string toString() {
		return this->name + " " + this->fname + " cash: " + to_string(this->cash) + " is teaching " + this->lesson;
	}



	string ToJson() {       //Метод серіалізації данних в JSON.
		string js = "";
		nlohmann::json j{};
		j["name"] = this->name;
		j["fname"] = this->fname;
		j["cash"] = this->cash;

		return j.dump();

	}
	void fromJson(string json) {    //Десеріалізує значення строки і присвоює значення об'єкту.

		nlohmann::json j = nlohmann::json::parse(json);
		this->name = j["name"].get<std::string>();
		this->fname = j["fname"].get<std::string>();
		this->cash = j["cash"].get<double>();
	}

	~Teacher()
	{

	}
};


struct University {                  //Структура університету
	vector<Worker> workers;          //Колекція Працівників
	vector<Student> students;        //Колекція Студентів
	vector<Teacher> teachers;

	University()         //Конструктор за замовчуванням
	{

	}

	void giveSalaryToTeachers(int money) {               //Метод для передачі зарплати всім Викладачам
		for (int i = 0; i < teachers.size(); i++) {     //Цикл проходить по всіх Викладачах у колекції
			teachers[i].getSalary(money);               //викликає метод зарплати.
		}
	}
	void giveSalaryToWorkers(int money) {                //Метод для передачі зарплати всім Працівникам.
		for (int i = 0; i < workers.size(); i++) {      //Цикл проходить по всіх Працівниках у колекції
			workers[i].getSalary(money);                //викликає метод зарплати.
		}
	}
	void  giveSalaryToStudents(int money) {             //Метод для передачі зарплати всім Студентам
		for (int i = 0; i < students.size(); i++) {     //Цикл проходить по всіх студентах в колекції.
			students[i].getSalary(money);               //викликає метод зарплати.
		}
	}

	string ToJsonTeachers() {               //Метод серіалізації данних в JSON.
		string js = "";                     //змінна для конкатенації всіх json'ів.

		for (int i = 0; i < this->teachers.size(); i++) {       //Цикл проходить по всіх Викладачах.
			js += this->teachers[i].ToJson() + " ";             //Додає їх у зімнну через пробіл.
		}

		return js;

	}
	string ToJsonStudents() {               //Метод серіалізації данних в JSON.
		string js = "";                     //змінна для конкатенації всіх json'ів.

		for (int i = 0; i < this->students.size(); i++) {       //Цикл проходить по всіх учнях.
			js += this->students[i].ToJson() + " ";             //Додає їх у змінну через пробіл.
		}

		return js;

	}
	string ToJsonWorkers() {                //Метод серіалізації данних в JSON.
		string js = "";                     //змінна для конкатенації всіх json'ів

		for (int i = 0; i < this->workers.size(); i++) {        //Цикл проходить по всіх Працівниках.
			js += this->workers[i].ToJson() + " ";              //Додає їх у змінну через пробіл.
		}

		return js;

	}



	void fromJsonTeachers(string json) {                    //Десеріалізує json з данними про Викладачів у колекцію.
		//nlohmann::json j = nlohmann::json::parse(json);
		vector<string> vec = split(json, ' ');              //змінна для розбивання данних на колекцію.
		if (vec[0] != "") {                                 //перевірка на наявність значень у колекції.
			for (auto i : vec) {                            //Цикл проходить по кожному json'у.
				this->teachers.push_back(Teacher());        //Додає елемент у вектор.
				this->teachers[this->teachers.size() - 1].fromJson(i);      //Десеріалізує.
			}
		}
	}

	void fromJsonStudents(string json) {                    //Десеріалізує json з данними про Студентів у колекцію.
		//nlohmann::json j = nlohmann::json::parse(json);
		vector<string> vec = split(json, ' ');              //змінна для розбивання данних на колекцію.
		if (vec[0] != "") {                                 //перевірка на наявність значень у колекції.
			for (auto i : vec) {                            //Цикл проходить по кожному json'у.
				this->students.push_back(Student());        //Додає елемент у вектор.
				this->students[this->students.size() - 1].fromJson(i);      //Десеріалізує.
			}
		}
	}
	void fromJsonWorkers(string json) {                     //Десеріалізує json з данними про Працівників у колекцію.
		//nlohmann::json j = nlohmann::json::parse(json);
		vector<string> vec = split(json, ' ');              //змінна для розбивання данних на колекцію.
		if (vec[0] != "") {                                 //перевірка на наявність значень у колекції.
			for (auto i : vec) {                            //Цикл проходить по кожному json'у.
				this->workers.push_back(Worker());          //Додає елемент у вектор.
				this->workers[this->workers.size() - 1].fromJson(i);      //Десеріалізує.
			}
		}
	}



	std::vector<std::string> split(std::string str, char breakOn) {         //Метод розбивання json'a на колекцію.

		std::vector<std::string> sVec;              //змінна результату.
		std::string statement = "";                 //тимчасова змінна.


		for (unsigned int i = 0; i < str.size(); i++) {				//Цикл проходить по кожному символу в строці.

			if (str[i] != breakOn) {							    //якщо символ не відповідає символу розділення, тоді додає його в тимчасову змінну.

				statement += str.at(i);                             //Додавання.
			}

			else if (str[i] == breakOn) {				  			//якщо рівний, то додає тимчасову змінну в колекцію.

				sVec.push_back(string(statement));

				statement = "";                                     //і оновлює тимчасову змінну.
			}
		}
		sVec.push_back(string(statement));
		return sVec;                                                //повертає колекцію.
	}

	~University()
	{

	}
};


void menu(University& university) {             //Метод інтерфейсу.

	while (true)
	{
	    //Можливості.
		printf("1.Add Student\n");              //додає студента.
		printf("2.Add Teacher\n");              //додає викладача.
		printf("3.Add Worker\n");               //додає працівника.
		printf("---------------\n");
		printf("4.Show All Teachers\n");        //вивести список всіх Викладачів.
		printf("5.Show All Students\n");        //Вивести список всіх Студентів.
		printf("6.Show All Workers\n");         //Вивести список всіх Працівників.
		printf("---------------\n");

		printf( "7.Give Salary\n");             //видати зарплату.
		printf( "8.Rate student\n");            //оцінити студента.
		printf( "---------------\n");

		printf("9.Load\n");                     //Загрузити збережені данні.
		printf("0.Save\n");                     //зберегти данні в JSON формате.

		int pick = 0;                           //змінна для меню.
		cin >> pick;                            //Ввод опції.
		switch (pick)
		{
		case 1: {
            
            //Заповнює значення Студента.
			string name = "";
			string fname;
			double cash;
			printf("Enter name: ");
			cin >> name;
			printf("Enter famaly name: ");
			cin >> fname;
			printf("Enter cash: ");
			cin >> cash;

			university.students.push_back(Student(name, fname, cash));      //додає студента.
			system("cls");      //очищення консолі.
			break;
		}
		case 2: {

            //заповнює значення Викладача.
			string name;
			string fname;
			string lesson;
			double cash;
			printf("Enter name: ");
			cin >> name;
			printf("Enter famaly name: ");
			cin >> fname;
			printf("Enter lesson: ");
			cin >> lesson;
			printf("Enter cash: ");
			cin >> cash;

			university.teachers.push_back(Teacher(name, fname, lesson, cash));      //додає Викладача.

			system("cls");		//очищення консолі.
			break;
		}
		case 3: {

            //заповнює значення працівника.
			string name;
			string fname;
			int exp;
			double cash;
			printf( "Enter name: ");
			cin >> name;
			printf( "Enter famaly name: ");
			cin >> fname;
			printf( "Enter work experience: ");
			cin >> exp;
			printf( "Enter cash: ");
			cin >> cash;

			university.workers.push_back(Worker(name, fname, exp, cash));       //додає працівника.
			system("cls");      //очищення консолі.
			break;
		}
		case 4:
			system("cls");      //очищення консолі.
			for (auto i : university.teachers) {        //Проходить по колекції Викладачів і виводить кожного в консоль.
				printf( (i.toString() +"\n").c_str());
			}
			break;
		case 5:
			system("cls");
			for (auto i : university.students) {        //Проходить по колекції студентів і виводить кожного в консоль.
				printf((i.toString()+"\n").c_str());
			}
			break;
		case 6:
			system("cls");
			for (auto i : university.workers) {         //Проходить по колекції працівників і виводить кожного в консоль.
				printf((i.toString() + "\n").c_str());
			}
			break;
		case 7:
			double cash;        //змінна для грошей.
			cin >> cash;        //Ввод кількості.
			university.giveSalaryToStudents(cash);
			university.giveSalaryToTeachers(cash);
			university.giveSalaryToWorkers(cash);
			system("cls");
			break;
		case 8: {
			string name;
			string fname;
			string lesson;
			int mark;
            
            //вказування ім'я, прізвища студента, предмет і оцінка.
			printf( "Enter name: ");
			cin >> name;
			printf( "Enter famaly name: ");
			cin >> fname;
			printf( "Enter lesson: ");
			cin >> lesson;
			printf( "Enter mark: ");
			cin >> mark;

			for (int i = 0; i < university.students.size(); i++) {              //Цикл проходить по всіх студентах.
				if (university.students[i].book.book.find(lesson) != university.students[i].book.book.end()) {          //чи є в заліковці студента такий предмет.
					if (university.students[i].name == name && university.students[i].fname == fname) {                 //чи співпадають прізвище студента з введеними даними.
						university.students[i].book.book[lesson].push_back(mark);                                       //Додавання оцінки.
					}
				}
			}


			break;
		}
		case 9:
		{

			ifstream fileW("workers.txt");              //відкриває файл працівників.
			if (fileW.is_open()) {                      //перевірка на його наявність.
				string lineW;                           //тимчасова змінна для вивода данних.
				while (getline(fileW, lineW))           //зчитує данні.
				{
				}
				university.fromJsonWorkers(lineW);      //Десеріалізує данні json в колекцію працівників.

				fileW.close();                          //Закриває файл для читання.
			}


			ifstream fileS("students.txt");             //відкриває файл студентів.
			if (fileS.is_open()) {                      //перевірка на його наявність.
				string lineS;                           //тимчасова змінна для вивода данних.
				while (getline(fileS, lineS))           //зчитує данні.
				{
				}
				university.fromJsonStudents(lineS);     //Десеріалізує данні json в колекцію студентів.

				fileS.close();                          //Закриває файл для читання
			}

			ifstream fileT("teachers.txt");             //відкриває файл Викладачів.
			if (fileT.is_open()) {                      //перевірка на його наявність.
				string lineT;                           //тимчасова змінна для вивода данних.
				while (getline(fileT, lineT))           //зчитує данні.
				{
				}
				university.fromJsonTeachers(lineT);     //Десеріалізує данні json в колекцію Викладачів.

				fileT.close();                          //Закриває файл для читання.
			}



			system("cls");
			break;
		}
		case 0:                                                 
		{
			std::ofstream outW("workers.txt");                  //відкриває файл працівників 
			outW << university.ToJsonWorkers().c_str();         //записує в нього json працівників
			outW.close();                                       //Закриває файл.

			std::ofstream outT("teachers.txt");                 //відкриває файл Викладачів.
			outT << university.ToJsonTeachers().c_str();        //записує в нього json Викладачів.
			outT.close();                                       //Закриває файл

			std::ofstream outS("students.txt");                 //відкриває файл студентів.
			outS << university.ToJsonStudents().c_str();        //записує в нього json студентів.
			outS.close();                                       //Закриває файл
			system("cls");
			break;
		}
		default:
		    //У випадку недійсності опції вивести помилку в консоль.
			system("cls");
			printf( "Error!\n");
			break;
		}


	}



}


int main() {
	University university;      //Створення об'єкту університету.
	menu(university);           //Запуск меню.


	return 0;
}
