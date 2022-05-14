#include <iostream>
#include <string.h>
#include <vector>
#include <fstream>
#include <map>
#include <nlohmann/json.hpp>
#include <stdio.h>

using namespace std;

struct Person {
	string name;
	string fname;
	double cash;
	virtual void getSalary(double money) {
		this->cash += money;
	};

};

struct StudentBook {
	map<string, vector<int>> book;

	StudentBook()
	{
		book.insert({ "Math",vector<int>() });
		book.insert({ "Biology",vector<int>() });
		book.insert({ "Art",vector<int>() });
		book.insert({ "Physics",vector<int>() });
		book.insert({ "Sport",vector<int>() });
	}

	void setScore(string lesson, int score) {
		this->book[lesson].push_back(score);
	}

	double avarageScore(string lesson) {
		if (book.find(lesson) != book.end()) {
			if (book[lesson].size() != 0) {
				double score = 0.0;
				for (auto i : book[lesson]) {
					score += i;
				}
				score /= book[lesson].size();
				return score;
			}
			else {
				return 0;
			}
		}
		else {
			return -1;
		}
	}

	double avarageScore() {
		int score = 0.0;
		for (auto i : this->book) {
			score += this->avarageScore(i.first);
		}
		score /= this->book.size();
		return score;
	}

	~StudentBook()
	{

	}
};
struct Student : public Person {
	StudentBook book;

	Student()
	{
		name = "noname";
		fname = "no family name";
		cash = 0.0;

	}
	Student(string name, string fname, double cash)
	{
		this->name = name;
		this->fname = fname;
		this->cash = cash;
	}
	Student(string name, string fname, double cash, StudentBook book)
	{
		this->name = name;
		this->fname = fname;
		this->book = book;
		this->cash = cash;
	}

	friend ostream& operator<<(ostream& os, Student& other) {

		os << other.name << " " << other.fname << " cash: " << other.cash << " avarage score: " << other.book.avarageScore();
		return os;
	}

	string toString() {
		return this->name + " " + this->fname + " cash: " + to_string(this->cash) + " avarage score:" + to_string(this->book.avarageScore());
	}

	void getSalary(int money) {
		this->cash += money * this->book.avarageScore();
	}

	string ToJson() {
		string js = "";
		nlohmann::json j{};
		j["name"] = this->name;
		j["fname"] = this->fname;
		j["cash"] = this->cash;
		j["book"] = this->book.book;

		return j.dump();

	}
	void fromJson(string json) {

		nlohmann::json j = nlohmann::json::parse(json);
		this->name = j["name"].get<std::string>();
		this->fname = j["fname"].get<std::string>();
		this->cash = j["cash"].get<double>();
		j["book"].get_to<map<string, vector<int>>>(this->book.book);
	}

	~Student()
	{

	}
};

struct Worker : public Person {
	int experience;
	Worker()
	{

		name = "noname";
		fname = "no family name";
		cash = 0.0;
		experience = 1;

	}
	Worker(string name, string fname, int experience, double cash)
	{

		this->name = name;
		this->fname = fname;
		this->cash = cash;
		this->experience = experience;

	}

	string ToJson() {
		string js = "";
		nlohmann::json j{};
		j["name"] = this->name;
		j["fname"] = this->fname;
		j["cash"] = this->cash;
		j["experience"] = this->experience;

		return j.dump();

	}
	void fromJson(string json) {

		nlohmann::json j = nlohmann::json::parse(json);
		this->name = j["name"].get<std::string>();
		this->fname = j["fname"].get<std::string>();
		this->cash = j["cash"].get<double>();
		this->experience = j["experience"].get<int>();
	}

	void getSalary(int money) {
		this->cash += money * this->experience;
	}
	string toString() {
		return this->name + " " + this->fname + " cash: " + to_string(this->cash) + " "+to_string(this->experience)+"years of working.";
	}


	~Worker()
	{

	}
};

struct Teacher : public Person {
	string lesson;

	Teacher()
	{
		lesson = "no lesson";
		name = "noname";
		fname = "no family name";
		cash = 0.0;
	}
	Teacher(string name, string fname, string lesson, double cash)
	{
		this->lesson = lesson;
		this->name = name;
		this->fname = fname;
		this->cash = cash;
	}
	void getSalary(int money) {
		this->cash += money;
	}

	string toString() {
		return this->name + " " + this->fname + " cash: " + to_string(this->cash) + " is teaching " + this->lesson;
	}



	string ToJson() {
		string js = "";
		nlohmann::json j{};
		j["name"] = this->name;
		j["fname"] = this->fname;
		j["cash"] = this->cash;

		return j.dump();

	}
	void fromJson(string json) {

		nlohmann::json j = nlohmann::json::parse(json);
		this->name = j["name"].get<std::string>();
		this->fname = j["fname"].get<std::string>();
		this->cash = j["cash"].get<double>();
	}

	~Teacher()
	{

	}
};


struct University {
	vector<Worker> workers;
	vector<Student> students;
	vector<Teacher> teachers;

	University()
	{

	}

	void giveSalaryToTeachers(int money) {
		for (int i = 0; i < teachers.size(); i++) {
			teachers[i].getSalary(money);
		}
	}
	void giveSalaryToWorkers(int money) {
		for (int i = 0; i < workers.size(); i++) {
			workers[i].getSalary(money);
		}
	}
	void  giveSalaryToStudents(int money) {
		for (int i = 0; i < students.size(); i++) {
			students[i].getSalary(money);
		}
	}

	string ToJsonTeachers() {
		string js = "";

		for (int i = 0; i < this->teachers.size(); i++) {
			js += this->teachers[i].ToJson() + " ";
		}

		return js;

	}
	string ToJsonStudents() {
		string js = "";

		for (int i = 0; i < this->students.size(); i++) {
			js += this->students[i].ToJson() + " ";
		}

		return js;

	}
	string ToJsonWorkers() {
		string js = "";

		for (int i = 0; i < this->workers.size(); i++) {
			js += this->workers[i].ToJson() + " ";
		}

		return js;

	}



	void fromJsonTeachers(string json) {
		//nlohmann::json j = nlohmann::json::parse(json);
		vector<string> vec = split(json, ' ');
		if (vec[0] != "") {
			for (auto i : vec) {
				this->teachers.push_back(Teacher());
				this->teachers[this->teachers.size() - 1].fromJson(i);
			}
		}
	}

	void fromJsonStudents(string json) {
		//nlohmann::json j = nlohmann::json::parse(json);
		vector<string> vec = split(json, ' ');
		if (vec[0] != "") {
			for (auto i : vec) {
				this->students.push_back(Student());
				this->students[this->students.size() - 1].fromJson(i);
			}
		}
	}
	void fromJsonWorkers(string json) {
		//nlohmann::json j = nlohmann::json::parse(json);
		vector<string> vec = split(json, ' ');
		if (vec[0] != "") {
			for (auto i : vec) {
				this->workers.push_back(Worker());
				this->workers[this->workers.size() - 1].fromJson(i);
			}
		}
	}



	std::vector<std::string> split(std::string str, char breakOn) {

		std::vector<std::string> sVec;
		std::string statement = "";


		for (unsigned int i = 0; i < str.size(); i++) {

			if (str[i] != breakOn) {

				statement += str.at(i);
			}

			else if (str[i] == breakOn) {

				sVec.push_back(string(statement));

				statement = "";
			}
		}
		sVec.push_back(string(statement));
		return sVec;
	}

	~University()
	{

	}
};


void menu(University& university) {

	while (true)
	{
		printf("1.Add Student\n");
		printf("2.Add Teacher\n");
		printf("3.Add Worker\n");
		printf("---------------\n");
		printf("4.Show All Teachers\n");
		printf("5.Show All Students\n");
		printf("6.Show All Workers\n");
		printf("---------------\n");

		printf( "7.Give Salary\n");
		printf( "8.Rate student\n");
		printf( "---------------\n");

		printf("9.Load\n");
		printf("0.Save\n");

		int pick = 0;
		cin >> pick;
		switch (pick)
		{
		case 1: {

			string name = "";
			string fname;
			double cash;
			printf("Enter name: ");
			cin >> name;
			printf("Enter famaly name: ");
			cin >> fname;
			printf("Enter cash: ");
			cin >> cash;

			university.students.push_back(Student(name, fname, cash));
			system("cls");
			break;
		}
		case 2: {

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

			university.teachers.push_back(Teacher(name, fname, lesson, cash));

			system("cls");
			break;
		}
		case 3: {

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

			university.workers.push_back(Worker(name, fname, exp, cash));
			system("cls");
			break;
		}
		case 4:
			system("cls");
			for (auto i : university.teachers) {
				printf( (i.toString() +"\n").c_str());
			}
			break;
		case 5:
			system("cls");
			for (auto i : university.students) {
				printf((i.toString()+"\n").c_str());
			}
			break;
		case 6:
			system("cls");
			for (auto i : university.workers) {
				printf((i.toString() + "\n").c_str());
			}
			break;
		case 7:
			double cash;
			cin >> cash;
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

			printf( "Enter name: ");
			cin >> name;
			printf( "Enter famaly name: ");
			cin >> fname;
			printf( "Enter lesson: ");
			cin >> lesson;
			printf( "Enter mark: ");
			cin >> mark;

			for (int i = 0; i < university.students.size(); i++) {
				if (university.students[i].book.book.find(lesson) != university.students[i].book.book.end()) {
					if (university.students[i].name == name && university.students[i].fname == fname) {
						university.students[i].book.book[lesson].push_back(mark);
					}
				}
			}


			break;
		}
		case 9:
		{

			ifstream fileW("workers.txt");
			if (fileW.is_open()) {
				string lineW;
				while (getline(fileW, lineW))
				{
				}
				university.fromJsonWorkers(lineW);

				fileW.close();
			}


			ifstream fileS("students.txt");
			if (fileS.is_open()) {
				string lineS;
				while (getline(fileS, lineS))
				{
				}
				university.fromJsonStudents(lineS);

				fileS.close();
			}

			ifstream fileT("teachers.txt");
			if (fileT.is_open()) {
				string lineT;
				while (getline(fileT, lineT))
				{
				}
				university.fromJsonTeachers(lineT);

				fileT.close();
			}



			system("cls");
			break;
		}
		case 0:
		{
			std::ofstream outW("workers.txt");
			outW << university.ToJsonWorkers().c_str();
			outW.close();

			std::ofstream outT("teachers.txt");
			outT << university.ToJsonTeachers().c_str();
			outT.close();

			std::ofstream outS("students.txt");
			outS << university.ToJsonStudents().c_str();
			outS.close();
			system("cls");
			break;
		}
		default:
			system("cls");
			printf( "Error!\n");
			break;
		}


	}



}


int main() {
	University university;
	menu(university);


	return 0;
}