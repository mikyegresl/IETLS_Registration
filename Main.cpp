#include <iostream>
#include <conio.h>
#include "ExamManager.h"

using namespace std;

int main()
{
	ExamManager manager = ExamManager();
	int choice = -1;
	string name, surname, email, date_of_birth, address, passport_series;
	int exam_date, examinee_id;
	unsigned long telephone;
	double score;

	while (choice != 0){
		choice = -1;
		cout << "*************************************************************************" << endl;
		cout << "*************************************************************************" << endl;
		cout << "1.Create new exam " << endl;
		cout << "2.Show exam dates" << endl;
		cout << "3.Register new examinee" << endl;
		cout << "4.Show whole examinee list" << endl;
		cout << "5.Show examinee info" << endl;
		cout << "6. Show examinee results" << endl;
		cout << "7.Assign result of Speaking part" << endl;
		cout << "8.Assign result of Reading part" << endl;
		cout << "9.Assign result of Writing part" << endl;
		cout << "10.Assign result of Listening part " << endl;
		cout << "11.Delete passed exam" << endl;
		cout << "0. to exit" << endl;
		cout << "*************************************************************************" << endl;
		cout << "*************************************************************************" << endl;
		cout << "Your choice: ";
		cin>> choice;
		
		switch (choice){
		case 1:
			cout << "Enter the exam date (year,month,day): ";
			cin >> exam_date; cout << endl;
			manager.createExam(exam_date);
			system("cls");
			break;

		case 2:
			manager.printExamDates();
			break;

		case 3:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date; cout << endl;
			cout << "Name: "; cin >> name; cout << endl;
			cout << "Surname: "; cin >> surname; cout << endl;
			cout << "Date of birth: "; cin >> date_of_birth; cout << endl;
			cout << "Telephone: +998"; cin >> telephone; cout << endl;
			cout << "Email: "; cin >> email; cout << endl;
			cout << "Address: "; cin >> address; cout << endl;
			cout << "Passport series: "; cin >> passport_series; cout << endl;
			system("cls");
			cout << "Examinee id is: " << manager.assignNewExaminee(exam_date, name, surname, address, passport_series, email, telephone, date_of_birth);
			_getch();
			system("cls");
			break;

		case 4:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date; cout << endl;
			manager.printWholeExamineeList(exam_date);
			_getch();
			system("cls");
			break;

		case 5:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date;
			cout << "Enter examinee id: "; cin >> examinee_id;
			cout << endl;
			manager.printExamineeInfo(exam_date, examinee_id);
			_getch();
			system("cls");
			break;

		case 6:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date;
			cout << "Enter examinee id: "; cin >> examinee_id;
			cout << endl;
			manager.printExamineeResults(exam_date, examinee_id);
			_getch();
			system("cls");
			break;

		case 7:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date;
			cout << "Enter examinee id: "; cin >> examinee_id;
			cout << "Enter Speaking part score: "; cin >> score;
			cout << endl;
			manager.assignSpeakingResult(exam_date, examinee_id, score);
			system("cls");
			break;

		case 8:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date;
			cout << "Enter examinee id: "; cin >> examinee_id;
			cout << "Enter Reading part score: "; cin >> score;
			cout << endl;
			manager.assignReadingResult(exam_date, examinee_id, score);
			system("cls");
			break;

		case 9:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date;
			cout << "Enter examinee id: "; cin >> examinee_id;
			cout << "Enter Writing part score: "; cin >> score;
			cout << endl;
			manager.assignWritingResult(exam_date, examinee_id, score);
			system("cls");
			break;

		case 10:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date;
			cout << "Enter examinee id: "; cin >> examinee_id;
			cout << "Enter Listening part score: "; cin >> score;
			cout << endl;
			manager.assignListeningResult(exam_date, examinee_id, score);
			system("cls");
			break;

		case 11:
			cout << "Enter exam date(year,month,day): "; cin >> exam_date; cout << endl;
			manager.deletePassedExam(exam_date);
			system("cls");
			break;

		default:
			break;
		}
		
	}

	cout << endl << endl << "Press any key to exit. . . ";
	_getch();
	return 0;
}

