#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Person
{
public:
	virtual ~Person() {}
	virtual string Action() const = 0;
};

class Professor : public Person
{
public:
	Professor(string fn, string ln, string pn, string c):
		firstName(fn), lastName(ln), phonNumber(pn), career(c)
	{}
	string Action() const override
	{
		return "Я профессор Политеха\n";
	}
	friend ostream& operator<< (ostream&, const Professor&);
	
private:
	string firstName;
	string lastName;
	string phonNumber;
	string career;
};

class Abiturient : public Person
{
public:
	Abiturient(string fn, string ln, string pn, string c) :
		firstName(fn), lastName(ln), phonNumber(pn), career(c)
	{}
	string Action() const override
	{
		return "Я абитуриент\n";
	}
	friend ostream& operator<< (ostream&, const Abiturient&);

private:
	string firstName;
	string lastName;
	string phonNumber;
	string career;
};

class Dekan : public Person
{
public:
	Dekan(Dekan& other) = delete;
	void operator=(const Dekan&) = delete;
	string Action() const override
	{
		return "Я декан Политеха\n";
	}
	friend ostream& operator<< (ostream&, const Dekan&);
	static Dekan* GetInstance(string fn, string ln, string pn, string c);
protected:
	Dekan(string fn, string ln, string pn, string c) : 
		firstName(fn), lastName(ln), phonNumber(pn), career(c) {}
	static Dekan* dekan_;
private:
	string firstName;
	string lastName;
	string phonNumber;
	string career;
};

Dekan* Dekan::dekan_ = nullptr;
Dekan* Dekan::GetInstance(string fn, string ln, string pn, string c)
{
	if (dekan_ == nullptr) {
		dekan_ = new Dekan(fn, ln, pn, c);
	}
	return dekan_;
}

class Decorator : public Person
protected:
	Person* person_;

public:
	Decorator(Person* person) : person_(person)
	{ 	}
	string Action() const override
	{
		return this->person_->Action();
	}
};

class StudentA : public Decorator
{
public:
	StudentA(Person* person) : Decorator(person)
	{ 	}
	string Action() const override
	{
		return "Я учусь очно в Политехе. " + Decorator::Action();
	}
private:
	string firstName;
	string lastName;
	string phonNamber;
	string career;
};

class StudentB : public Decorator
{
public:
	StudentB(Person* person) : Decorator(person)
	{ 	}
	string Action() const override
	{
		return "Я учусь заочно в РАНХиГСе. " + Decorator::Action();
	}
private:
	string firstName;
	string lastName;
	string phonNamber;
	string career;
};

ostream& operator<< (ostream& out, const Professor& prof)
{
	out << prof.firstName << " " << prof.lastName
		<< " " << prof.phonNumber << " " << prof.career << "\n"<< endl;
		return out;
}

ostream& operator<< (ostream& out, const Abiturient& ab)
{
	out << ab.firstName << " " << ab.lastName
		<< " " << ab.phonNumber << " " << ab.career << "\n" << endl;
	return out;
}

ostream& operator<< (ostream& out, const Dekan& d)
{
	out << d.firstName << " " << d.lastName
		<< " " << d.phonNumber << " " << d.career << "\n" << endl;
	return out;
}

void ClientCode(Person* person)
{
	std::cout << "Что делаю: " << person->Action();
}

int main()
{
	system("chcp 1251");
	Person* professor = new Professor("Mikhai;", "Semenov", "99999999999", "professor");
	Person* professor1 = new Professor("jo", "Hromakeev", "11111111111", "professor");
	ClientCode(professor);
	ClientCode(professor1);

	
	Person* dekan = Dekan::GetInstance("Maksim", "Rakov", "66666666666", "dekan"); 
	
	ClientCode(dekan);

	Person* Abiturient = new Abiturient("Victor", "Maluskov", "33333333333", "Abiturient");
	ClientCode(Abiturient);
	Person* studentA = new StudentA(Abiturient); 
	ClientCode(studentA);
	Person* studentB = new StudentB(studentA);  
	ClientCode(studentB);

	string fileName = "testTask.txt";
	ofstream book(fileName);
	book << "The address book:\n" << endl;
	vector<Professor> v;
	v.push_back(Professor("Mikhai;", "Semenov", "99999999999", "professor"));
	v.push_back(Professor("jo", "Hromakeev", "11111111111" "professor"));
	for (auto& professor : v)
		
		book << professor;
	vector<Abiturient> v1;
	v1.push_back(Abiturient("Victor", "Maluskov", "33333333333", "Abiturient"));
	for (auto& Abiturient : v1)
		
		book << Abiturient;
	book.close();
	delete professor;
	delete professor1;
	delete dekan;
	delete Abiturient;
	delete studentA;
	delete studentB;
	return 0;
}