/*
author: Julie Schneider 3/2020, Updated Fall 2021
Question class implementation definition
*/

#include "question.h"

Question::Question(Record catIn, Record quest, Record ans)
{
	setCategory(catIn);
	setQuestion(quest);
	setAnswer(ans);
	resetQuestionStatus();
	setPoints(0);
}

std::string Question::toString() const
{
	return "\n*****************" + std::to_string(points) + "********************\nCategory: " + category
		 + "\nQuestion: " + question + "\n****************************************\n";
}

std::string Question::toFileString() const
{
	std::string strCSV = category + "," + question + "," + answer + "\n";
	return strCSV;
}

std::istream& operator>>(std::istream& is, Question& q)
{
	std::cout << "\n************************Question Entry: \n";
	std::cout << "*\tCategory: ";
	is >> q.category;
	std::cout << "*\tQuestion: ";
	is >> q.question;
	std::cout << "*\t  Answer: ";
	is >> q.answer;
	std::cout << "*\t   Score: ";
	is >> q.points;
	std::cout << "\n****************************************\n\n";
	q.status = false;
	return is;
}
std::ifstream& operator>>(std::ifstream& ifs, Question& q)
{
	Record record;
	ifs >> record;
  
  if(record == "")
    return ifs;
  if(record == "\n")
    return ifs;
  
  Record* fields = record.split(',');
  q.category = fields[0];
  q.question = fields[1];
  q.answer = fields[2];
  q.points = 999; //std::stoi(fields[3]);
  q.status = false;

	return ifs;
}
std::ostream& operator<<(std::ostream& os, const Question& q)
{
	os << q.toString();
	return os;
}
std::ofstream& operator<<(std::ofstream& ofs, const Question& q)
{
	ofs << "" << q.toFileString();
	return ofs;
}
bool operator==(const Question& q1, const Question& q2)
{
	// Questions must be in the same category to be compared and
	// then the points are compared.
	if (q1.category == q2.category && q1.points == q2.points
		&& q1.answer == q2.answer && q1.question == q2.question)
		return true;
	return false;
}
bool operator!=(const Question& q1, const Question& q2)
{
	return !(q1 == q2);
}
bool operator>=(const Question& q1, const Question& q2)
{
	return q1 == q2 || q1 > q2;
}
bool operator<=(const Question& q1, const Question& q2)
{
	return q1 == q2 || q1 < q2;
}
bool operator>(const Question& q1, const Question& q2)
{
	return !(q1 <= q2);
}
bool operator<(const Question& q1, const Question& q2)
{
	// Questions must be in the same category to be compared.
	if (q1.category == q2.category && q1.points < q2.points)
		return true;
	return false;
}
