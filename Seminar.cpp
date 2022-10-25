#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	const int idStudent;
	char* nume;
	char prenume[10];
	int varsta;
public:
	static int nrStudenti;
	//constructor fara parametri
	Student():idStudent(-1)
	{
		nume = new char[strlen("Anonim") + 1];
		strcpy(nume, "Anonim");
		strcpy(prenume, "Anonim");
		varsta = 0;
		nrStudenti++;
		//idStudent = -1;
	}
	//constructor cu toti parametri
	Student(int idStud, const char* numeStud, const char prenumeStud[], int varstaStud) :idStudent(idStud)
	{
		//this->idStudent = idStud;
		numeStud = new char[strlen(numeStud) + 1];
		strcpy(nume, numeStud);
		if (strlen(prenumeStud) > 10)
			throw "Prea mare prenumele";
		else strcpy(prenume, prenumeStud);
		varsta = varstaStud;
		nrStudenti++;
	}
	//constructor cu cativa parametri
	Student( const char* numeStud, int varstaStud):idStudent(nrStudenti++)
	{
		//idStudent = idStud;
		numeStud = new char[strlen(numeStud) + 1];
		strcpy(nume, numeStud);
		strcpy(prenume, "nedefinit");
		varsta = varstaStud;
		nrStudenti++;
	}
	int getVarsta()
	{
		return this->varsta;
	}
	~Student()
	{
		if (nume != nullptr)
			delete[] nume;
	}//mereu cand avem alocare dinamica, constructorul si destructorul fara parametri trebuie intotdeauna scrisi
};
// non - static = la nivel de obj
// static = la nivelul clasei
int Student::nrStudenti = 0; // operator de rezolutie
int main()
{
	//Student s;
	/*Student s1(1, "Andrei", "Ion", 23);
	cout << s1.getVarsta();*/
	Student s3("Andrei", 15);
	cout << s3.getVarsta();
	/*Student s2;
	cout << s2.getVarsta();*/
	return 0;
}