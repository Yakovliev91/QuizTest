#include "Quiz final.h"
#include<fstream>



Quiz *quizes;
int countQuizes = 0;
const int countQuestioninQuiz = 5;
const string fileName = "Quizes.txt";

void insertQuiz(Quiz quiz)
{
	Quiz* temp = new Quiz[countQuizes + 1];
	for (int i = 0; i < countQuizes; i++)
	{
		temp[i] = quizes[i];
	}
	temp[countQuizes] = quiz;
	countQuizes++;
	quizes = new Quiz[countQuizes];
	for (int i = 0; i < countQuizes; i++)
	{
		quizes[i] = temp[i];
	}
	delete[]temp;
}

void passQuiz()
{
	int selectQuiz = 0;
	int score = 0;

	cout << "Enter number quiz for start pass :" << endl;
	cin >> selectQuiz;
	selectQuiz--;

	cout << endl;
	cout << "You started passing" << quizes[selectQuiz].Title << endl;
	for (int i = 0; i < countQuestioninQuiz; i++)
	{
		cout << quizes[selectQuiz].questions[i].questionText << endl;
		string tempAnswer = "";
		cout << "Yuor answer :";
		cin >> tempAnswer;
		if (quizes[selectQuiz].questions[i].trueAnswer==tempAnswer)
		{
			cout << "Its true answer!(+20 score)" << endl;
			score += 20;

		}
		else
		{
			cout << "Its false answer:(" << endl;
		}
	}
	cout << "Your result :" << score << "/100" << endl;

}


void init()
{
	ifstream fin;
	fin.open(fileName);
	bool isOpen = fin.is_open();
	if (isOpen==true)
	{
		while (!fin.eof())
		{
			Quiz getQuiz;
			fin >> getQuiz.Title;
			if (getQuiz.Title!="")
			{


				for (int i = 0; i < countQuestioninQuiz; i++)
				{
					fin >> getQuiz.questions[i].questionText;
					fin >> getQuiz.questions[i].trueAnswer;

				}
			}
			else
			{
				break;
			}
			insertQuiz(getQuiz);
		}

	}
	else
	{
		cout << "Error: application cant open file!" << endl;
	}
}

void addQuiz()
{
	ofstream fout;
	fout.open(fileName,fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{


		Quiz* temp = new Quiz[countQuizes + 1];
		for (int i = 0; i < countQuizes; i++)
		{
			temp[i] = quizes[i];
		}

		cout << "Enter quiz title :";
		cin >> temp[countQuizes].Title;


		for (int i = 0; i < countQuestioninQuiz; i++)
		{
			cout << "Enter" << i + 1 << "/5 question :";
			cin >> temp[countQuizes].questions[i].questionText;

			cout << "Enter correct answer for this question :";
			cin >> temp[countQuizes].questions[i].trueAnswer;
		}
		fout << temp[countQuizes].Title << endl;
		for (int i = 0; i < 5; i++)
		{
			fout << temp[countQuizes].questions[i].questionText << endl;
			fout << temp[countQuizes].questions[i].trueAnswer << endl;


		}


		countQuizes++;
		quizes = new Quiz[countQuizes];
		for (int i = 0; i < countQuizes; i++)
		{
			quizes[i] = temp[i];
		}
		delete[]temp;
	}
	else
	{
		cout << "Error" << endl;
	}
	
}

void showQuizes()
{
	for (int i = 0; i < countQuizes; i++)
	{
		cout << i + 1 << ". " << quizes[i].Title << endl;
	}
	cout << endl;
}


