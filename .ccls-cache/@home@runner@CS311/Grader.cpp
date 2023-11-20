#include <iomanip>
#include <iostream>

int main() {
  // Constants for point distribution
  const int totalPoints = 1000;
  const int hw1Points = 60;
  const int hw2To8Points = 65;
  const int numHWs = 7;
  const int quizPoints = 10;
  const int numQuizzes = 14;
  const int midtermPoints = 150;
  const int finalPoints = 200;

  // Variables to store user input
  double targetPercentage;
  int hw1, hw2To8, quiz, midterm;

  // Input: Specify the desired percentage in the class
  std::cout << "Enter the target percentage in the class: ";
  std::cin >> targetPercentage;

  // Input: Specify the grades for each assignment with validation
  std::cout << "\nEnter the grade for HW1: ";
  std::cin >> hw1;

  // Input: Specify the grades for Homeworks 2 through 8 with validation
  for (int i = 2; i <= 8; ++i) {
    std::cout << "Enter the grade for HW" << i << ": ";
    std::cin >> hw2To8;
  }

  // Input: Specify the grades for each quiz with validation
  for (int i = 1; i <= numQuizzes; ++i) {
    std::cout << "Enter the grade for Quiz" << i << ": ";
    std::cin >> quiz;
  }

  std::cout << "\nEnter the grade for the Midterm: ";
  std::cin >> midterm;

  // Calculate total points obtained so far
  int totalObtainedPoints = hw1 + numHWs * hw2To8 + numQuizzes * quiz + midterm;

  // Calculate the minimum points needed on the final exam
  int minFinalExamPoints =
      std::max(0.0, targetPercentage - totalObtainedPoints);

  // Output the result
  std::cout << "\nTotal points obtained so far: " << totalObtainedPoints
            << std::endl;
  std::cout << "Minimum points needed on the final exam to achieve "
            << targetPercentage << "%: " << minFinalExamPoints << std::endl;

  return 0;
}
