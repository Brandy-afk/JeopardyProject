/*
Your Name
Jeopardy Game Week 14
Jeopardy Game Board
Summary: 
*/
#include <iostream>	
#include <string> 
#include <iomanip> // setw
#include <cstdlib> // srand
#include <ctime> // time
#include "record.h"
#include "linklist.h"
#include "question.h"
#include "htmlfunc.h"
LinkList<Record> generateGameCategories(LinkList<Record> gameInfoFileData);
void printGameCategories(LinkList<Record> gameCategoryData);
void setupANDshowBoard(LinkList<Record> gameCategoryData);
int main(){
  srand(time(nullptr));
  LinkList<Record> gameInfoFileData;
  // Read all possible category data
  if(!gameInfoFileData.readFile("Categories/gameInfo.csv"))
    std::cout << "Error reading from file: Categories/gameInfo.csv\n";
  /*
  std::cout << "\nAll Categories\n\n";
  allCategories.printAll();
  std::cout << "\n";
  */
  LinkList<Record> gameCategoryData;
  // Generate 6 random categories
  gameCategoryData = generateGameCategories(gameInfoFileData);
  // Print the 6 Game Categories with format
  printGameCategories(gameCategoryData);
  setupANDshowBoard(gameCategoryData);
  std::cout << "\n\n";
  return 0;
}
LinkList<Record> generateGameCategories(LinkList<Record> gameInfoFileData){
  LinkList<Record> gameCategoryData;
  int categoryCount = 0;
  while(categoryCount < 6){
    Record category = gameInfoFileData.getRandomData();
    if(!gameCategoryData.findByData(category)){
      gameCategoryData.prepend(category);
      categoryCount++;
    }
  }
  return gameCategoryData;
}
void printGameCategories(LinkList<Record> gameCategoryData){
  std::cout << "\nGame Categories\n\n";
  for(int i = 1; i <= gameCategoryData.getSize(); i++){
    Record info = gameCategoryData.at(i);
    info = info.upper();
    Record* fields = info.split(',');
    Record* file = fields[2].split('.');
    std::cout << i << ". " << std::setw(20) << std::left  << file[0] << " By: ";
    std::cout << fields[1] << " " << fields[0] << "\n";
  }
}
void setupANDshowBoard(LinkList<Record> gameCategoryData){
  BinTree<Question> categoryQuestions[6]; // array of Binary Tree objects - each index is a separate tree
  LinkList<Record> boardCategories;
  for(int i = 1; i <= gameCategoryData.getSize(); i++){
    Record info = gameCategoryData.at(i);
    info = info.upper();
    Record* fields = info.split(','); // last,first,fileName.csv
    Record* file = fields[2].split('.'); // fileName.csv
    boardCategories.append(file[0]);
  }
  printHTMLindex(boardCategories); // generate the index.htm - main board page
  int numCategories = boardCategories.getSize();
  for(int i = 1; i <= numCategories; i++){
    if(!categoryQuestions[i-1].readFile("Categories/" + boardCategories.at(i).lower() + ".csv")) // read all questions and store in the binary tree
      std::cout << "Error reading from file: Categories/" + boardCategories.at(i).lower() + ".csv\n"; 
    printHTMLpages(categoryQuestions[i-1], i); // generate each catID#_questionID#00.htm - a separate html page for each question
  }
}