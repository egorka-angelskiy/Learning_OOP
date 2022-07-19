#include <iostream>
#include <string>
#include "library.h"
#include <cstdlib> 
#include <Windows.h>
#include <time.h>


int ReadNumber();
void WriteAnswer(int);
char *RussianLanguage(const char *);

int global_argument = 10; 
int main(int argc, char const *argv[])
{	
	std::srand(time(NULL));

	std::cout << "hi" << std::endl;


	std::cout << add(2) << std::endl;
	std::cout << std::endl;

	bool answer;

	answer = (False("A") || (False("B") && False("C")));
	std::cout << answer << std::endl;
	answer = (True("A") || (False("B") && False("C")));
	std::cout << answer << std::endl;



	pointer();
	bit();
	std::cout << std::endl;

	return5();
	return8();

	bit_shift();

	std::cout << std::endl;
	std::cout << max(10, 5) << std::endl;

	std::cout << std::endl;
	WriteAnswer(ReadNumber() + ReadNumber());

	std::cout << std::endl << RussianLanguage("Привет") << std::endl;
	std::cout << std::endl;

	static int static_argument = 5;
	int general_argument = 7;

	std::cout << "Global argument - " << global_argument << std::endl;
	std::cout << "Static argument - " << static_argument << std::endl;
	std::cout << "General argument - " << general_argument << std::endl;
	std::cout << std::endl;

	module();
	std::cout << std::endl;
	std::cout << std::endl;

	int *array = CreateArray();
	PrintArray(array);
	QuickSort(sizeof(array), array);
	PrintArray(array);


	int **matrix = CreateMatrix();
	PrintMatrix(matrix);
	ArithmeticMean_NumberPositiveElementsInRows(matrix);

	int **rectangular_matrix = CreateRectangularMatrix();
	PrintRectangularMatrix(rectangular_matrix);
	NumberLeftMostColumnWhichOnlyPositiveElements(rectangular_matrix);
	SizeTypes();

	StringConversion();
	MoveCharacter();

	return 0;
}


void module()
{
	std::cout << (global_argument < 0 ? -global_argument : global_argument) << std::endl;
}




char RussianBuffer[CHAR_MAX];
char *RussianLanguage(const char *text)
{
	CharToOem(text, RussianBuffer);
	return RussianBuffer;
}

int add(int n)
{ 
	return n; 
}
