#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	srand(time(NULL));
	string filepath = "C:\\ForFun\\Test.txt"; // IMPORTANT
	string filepathForAnswers = "C:\\ForFun\\QuizResults.txt";
	
	vector<string> allQuestions;
	vector<string> userAnswers;

	string line;
	ifstream ifs(filepath);

	getline(ifs, line);
	while (getline(ifs, line)) // will iterate to the end with no issue.
	{
		allQuestions.push_back(line);
	}
	ifs.close();
	// gets 3 random qeustions, adds it to a list
	for (int i = 0; i < 3; i++) {
		int randomNum = rand() % allQuestions.size();
		string finalAnswer;
		string question = allQuestions[randomNum];
		string answer;

		cout << "Question " << i + 1 << ": " << question << " = " << "\n";
		cout << "Enter your answer: ";
		getline(cin, answer);

		userAnswers.push_back(question + " = " + answer);
		cout << "\n";
	}

	ofstream ofs(filepathForAnswers);	
	for (const string& i : userAnswers) {
		ofs << i << "\n";
	}
	cout << "\nResults saved to QuizResults.txt\n";

	(void)_getch();
	return 0;
}