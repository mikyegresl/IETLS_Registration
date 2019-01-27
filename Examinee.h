#include <string>
using namespace std;
class Examinee{
public:
	string name;
	string surname;
	string address;
	string passport_series;
	string email;
	unsigned long telephone;
	string date_of_birth;
	double writing_score = -1;
	double reading_score = -1;
	double listening_score = -1;
	double speaking_score = -1;
	Examinee(){};
	Examinee(string name, string surname, string address, string passport_series, string email, unsigned long telephone, string date_of_birth){
		this->name = name;
		this->surname = surname;
		this->address = address;
		this->passport_series = passport_series;
		this->email = email;
		this->telephone = telephone;
		this->date_of_birth = date_of_birth;
	}
};