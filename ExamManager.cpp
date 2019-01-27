#include "ExamManager.h"
ExamManager::ExamManager(){ root = new AVLTree(); }
void ExamManager::createExam(int exam_date){
	root->insert(exam_date);
	root->access(exam_date)->examinees = new Examinee[255];
}

short ExamManager::assignNewExaminee(int exam_date, string name, string surname, string address, string passport_series, string email, unsigned long telephone, string date_of_birth){
		root->access(exam_date)->examinees[root->access(exam_date)->occupied_places] = Examinee(name, surname, address, passport_series, email, telephone, date_of_birth);
		
		return root->access(exam_date)->occupied_places++;
		
}

void ExamManager::printWholeExamineeList(int exam_date){
	Examinee* examinees =  root->access(exam_date)->examinees;
	
	for (int i = 0; i <root->access(exam_date)->occupied_places; i++){
		std::cout << "Examinee ID: " << i << std::endl;
		std::cout << "Name: " << examinees[i].name << std::endl;
		std::cout << "Surname:" << examinees[i].surname << std::endl;
	}
}

void ExamManager::deletePassedExam(int exam_date){
	root->erase(exam_date);
}

void ExamManager::printExamDates(){
	std::cout << "Available Dates: ";
	root->inorder(); 
	std::cout << std::endl;
}
void ExamManager::printExamineeInfo(int exam_date, int examinee_id){
	Examinee examinee =  root->access(exam_date)->examinees[examinee_id];
	std::cout << "Name: " << examinee.name << std::endl;
	std::cout << "Surname:" << examinee.surname << std::endl;
	std::cout << "Date of birth: " << examinee.date_of_birth << std::endl;
	std::cout << "Telephone: +998" << examinee.telephone << std::endl;
	std::cout << "Email: " << examinee.email << std::endl;
	std::cout << "Address: " << examinee.address << std::endl;
	std::cout << "Passport series: " << examinee.passport_series << std::endl;

}

void ExamManager::printExamineeResults(int exam_date, int examinee_id){
	Examinee examinee = root->access(exam_date)->examinees[examinee_id];
	if (examinee.writing_score == -1){ std::cout << "Writing part result is not assigned yet" << std::endl; }
	else{ std::cout << "Writing part result: " << examinee.writing_score << std::endl; }
	if (examinee.listening_score == -1){ std::cout << "Listening part result is not assigned yet" << std::endl; }
	else{ std::cout << "Listening part result: " << examinee.listening_score << std::endl; }
	if (examinee.reading_score == -1){ std::cout << "Reading part result is not assigned yet" << std::endl; }
	else{ std::cout << "Reading part result: " << examinee.reading_score << std::endl; }
	if (examinee.speaking_score == -1){ std::cout << "Speaking part result is not assigned yet" << std::endl; }
	else{ std::cout << "Speaking part result: " << examinee.speaking_score << std::endl; }
}

void ExamManager::assignWritingResult(int exam_date, int examinee_id, double writing_score){
	root->access(exam_date)->examinees[examinee_id].writing_score = writing_score;
}
void ExamManager::assignListeningResult(int exam_date, int examinee_id, double listening_score){
	root->access(exam_date)->examinees[examinee_id].listening_score = listening_score;
}
void ExamManager::assignSpeakingResult(int exam_date, int examinee_id, double speaking_score){
	root->access(exam_date)->examinees[examinee_id].speaking_score = speaking_score;
}
void ExamManager::assignReadingResult(int exam_date, int examinee_id, double reading_score){
	root->access(exam_date)->examinees[examinee_id].reading_score = reading_score;
}

