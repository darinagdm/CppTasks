#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Person {
private:
    string name;
    unsigned byear;

public:
    Person(string _name, unsigned _byear = 1900): name(_name), byear(_byear) {}
    string& get_name() {return name;}
    unsigned get_byear() {return byear;}
    void set_byear(unsigned byear) {this->byear = byear;}
    
    virtual void input(istream& inp = cin) {
        inp >> name >> byear;
    }

    virtual void print(ostream& out = cout, bool endline = true) {
        out << name << ' ' << byear;
        if (endline) out << endl;
    }

    friend istream& operator>>(istream& inp, Person& p) {
        p.input(inp);
        return inp;
    }

    friend ostream& operator<<(ostream& out, Person& p) {
        p.print(out, false);
        return out;
    }
};

class Friend: public Person {
private:
    string phone;

public:
    Friend(string _name, unsigned _byear = 1901, string _phone = "888-88-88"):
        Person(_name, _byear), phone(_phone) {}

    string& get_phone() {return phone;}
    void set_phone(string phone) {this->phone = phone;}
    
    virtual void input(istream& inp = cin) {
        Person::input(inp);
        inp >> phone;
    }

    virtual void print(ostream& out = cout, bool endline = true) {
        Person::print(out, false);
        out << ' ' << phone;
        if (endline) out << endl;
    }
};

class PhoneBook {
private:
    string filename;

public:
    PhoneBook(string filename): filename(filename) {}
    void create() {
        ofstream f(filename);
        f.close();
    }

    void add_friend(Friend& fri) {
        ofstream f(filename, ofstream::app);
        f << fri << endl;
        f.close();
    }

    Friend find_friend(string name) {
        ifstream f(filename);
        Friend fri("FRIEND");
        while (f.good()) {
            f >> fri;
            if (f.fail())
                throw logic_error("Cannot find friend " + name);
            if (fri.get_name() == name)
                break;
        }
        f.close();
        return fri;
    }

    void change_phone(string name, string phone) {
        ifstream finp(filename);
        Friend fri("FRIEND");
        ostringstream oss;
        
        while (finp.good()) {
            finp >> fri;
            if (finp.fail())
                break;

            if (fri.get_name() == name)

                fri.set_phone(phone);

            oss << fri << endl;

        }

        finp.close();
        ofstream fout(filename);
        fout << oss.str();
        fout.close();
    }
};

int main() {
    Friend p1("Alex", 2000, "111-11-11");
    Friend p2("John", 2003, "222-22-22");
    Friend p3("Kate", 2002, "333-33-33");

    PhoneBook pb("phoneBook.txt");
    pb.create();
    pb.add_friend(p1);
    pb.add_friend(p2);
    pb.add_friend(p3);

    Friend p("FRIEND");
    p = pb.find_friend("Alex");
    cout << p << endl;
    pb.change_phone("Alex", "444-44-44");
    p = pb.find_friend("Alex");
    cout << p << endl;
    return 0;
}
