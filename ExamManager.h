#include "AVLTree.h"
#include <iostream>
#include <string>

 class ExamManager{
 private:
	 AVLTree* root;
 public:
	 ExamManager();
	void createExam(int exam_date);
	short assignNewExaminee(int exam_date, string name, string surname, string address, string passport_series, string email, unsigned long telephone, string date_of_birth);
	void assignWritingResult(int exam_date, int examinee_id, double writing_score);
	void assignListeningResult(int exam_date, int examinee_id, double listening_score);
	void assignSpeakingResult(int exam_date, int examinee_id, double speaking_score);
	void assignReadingResult(int exam_date, int examinee_id, double reading_score);
	void deletePassedExam(int exam_date);
	void printExamDates();
	void printExamineeInfo(int exam_date, int examinee_id);
	void printExamineeResults(int exam_date, int examinee_id);
	void printWholeExamineeList(int exam_date);
};

