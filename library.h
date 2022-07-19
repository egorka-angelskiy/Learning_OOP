#include <string>
#include <bitset>
#include "test.cpp"
#include <math.h>
#include <iomanip>

#ifndef LIBRARY
#define LIBRARY

#define ROWS 10
#define COLUMNS 20

int add(int);
void module();


bool True(std::string id)
{
	std::cout << "True" << id << '\n';
	return true;
}

bool False(std::string id)
{
	std::cout << "False" << id << '\n';
	return false;
}



void pointer()
{
	int array[4] = {1, 2, 3, 4};

	int *ptr1 = &array[0];
	int *ptr2 = ptr1 ++;
	std::cout << std::endl;
	std::cout << *ptr2 << "\t" << *ptr1 ++ << std::endl;

	int t = array[0] ++;
	std::cout << *ptr2 << "\t" << t << std::endl;
}



void bit()
{
	int a = 3;
	int b = 5;
	std::cout << "\nBitwise disjunction"<< std::endl;
	std::cout << "a = "<< a << "/" << std::bitset<8>(a) << std::endl;
	std::cout << "b = " << b << "/" << std::bitset<8>(b) << std::endl;
	a |= b;
	std::cout << std::endl;
	std::cout << a << std::endl;

	std::cout << "\nBitwise disjunction(exclusive disjunction)"<< std::endl;	
	std::cout << "a = "<< a << "/" << std::bitset<8>(a) << std::endl;
	std::cout << "b = " << b << "/" << std::bitset<8>(b) << std::endl;
	a ^= b;
	std::cout << std::endl;
	std::cout << a << std::endl;


}



int return5()
{
	return 5;
}

int return8()
{
	return 8;
}



int max(int a, int b)
{
	return (a > b ? a : b);		// до ? условие. слева от : возвращается если условие true
								// после : выполняется иначе условие false
}



void bit_shift()
{
	int a = 0b1010;
	std::cout << "Originall number : ";
	std::cout << a << " -> " << std::bitset<8>(a) << std::endl;

	a <<= 1;
	std::cout << "After left shift : ";
	std::cout << a << " -> " << std::bitset<8>(a) << std::endl;

	a >>= 2;
	std::cout << "After right shift : ";
	std::cout << a << " -> " << std::bitset<8>(a) << std::endl;
}



int *CreateArray()
{
	int cardinality = std::rand() % 100,
		*array = new int [cardinality];

	for (int i = 0; i < cardinality; ++ i) *(array + i) = std::rand() % 50;
	return array;
}


void PrintArray(int *array)
{
	std::cout << "[";
	for (int i = 0; i < sizeof(array); ++ i) std::cout << " " << *(array + i);
	std::cout << " ]" << std::endl;
}


void swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}


void QuickSort(int cardinality, int *array)		// normal function call
{
	int middle;

	int *left_stack = new int [cardinality],
		*right_stack = new int [cardinality];

	bool stack_position = true;

	*(left_stack + 1) = 0;
	*(right_stack + 1) = cardinality - 1;

	while (stack_position)
	{
		int left = *(left_stack + stack_position),
			right = *(right_stack + stack_position);
		stack_position = false;

		while (left < right)
		{
			int low = left,
				high = right;

			middle = *(array + ((left + right) / 2));

			while (low < high)
			{
				while(*(array + low) < middle) ++ low;
				while (*(array + high) > middle) -- high;

				if (low <= high)
				{
					swap(&*(array + low), &*(array + high));
					++ low;
					-- high;
				}
			}

			if (low < right)
			{
				stack_position = true;
				*(left_stack + stack_position) = low;
				*(right_stack + stack_position) = right;
			}

			right = high;
		}
	}
}




int **CreateMatrix()
{
	std::cout << std::endl;
	// int **matrix = new int* [ROWS];
	int **matrix = reinterpret_cast<int **> (new int [ROWS][COLUMNS]);
	// reinterpret_cast преобразовывать любой указатель в указатель любого другого типа. 
	// Также позволяет преобразовывать любой целочисленный тип в любой тип указателя и наоборот.
	for (int i = 0; i < ROWS; ++ i)
	{
		*(matrix + i) = new int [COLUMNS];
		for (int j = 0; j < COLUMNS; ++ j) *(*(matrix + i) + j) = std::rand() % 100 - 30;
	}

	return matrix;
}

void PrintMatrix(int **matrix)
{
	std::cout << std::endl;
	for (int i = 0; i < ROWS; ++ i)
	{
		std::cout << "[";
		for (int j = 0; j < COLUMNS; ++ j) std::cout << std::setw(4) << *(*(matrix + i) + j);
		std::cout << "  ]" << std::endl;
	}
	std::cout << std::endl;
}


void ArithmeticMean_NumberPositiveElementsInRows(int **matrix)
{
	std::cout << std::endl;
	int sum = 0, positive_elements = 0;

	for (int i = 0; i < ROWS; ++ i)
	{
		for (int j = 0; j < COLUMNS; ++ j)
		{
			sum += *(*(matrix + i) + j);
			if (*(*(matrix + i) + j) > 0) 
			{
				// std::cout << *(*(matrix + i) + j) << " ";
				positive_elements ++;
			}
		}

		std::cout << "Rows(" << i << ")" << " - " << positive_elements << std::endl;
		positive_elements = 0;
	}

	std::cout << "Arithmetic mean = " << (sum / (ROWS * COLUMNS)) << std::endl;
}




int **CreateRectangularMatrix()
{
	int const rows = 5, columns = 5;
	// int **matrix = (int **) new int [5][5];
	int **matrix = reinterpret_cast<int **> (new int [rows][columns]);
	for (int i = 0; i < rows; ++ i)
	{
		*(matrix + i) = new int [columns];
		for (int j = 0; j < columns; ++ j) *(*(matrix + i) + j) = std::rand() % 100 - 20;
	}

	return matrix;
}


void PrintRectangularMatrix(int **matrix)
{
	std::cout << std::endl;
	int const rows = 5, columns = 5;
	for (int i = 0; i < rows; ++ i)
	{
		std::cout << "[";
		for (int j = 0; j < columns; ++ j) std::cout << std::setw(4) << *(*(matrix + i) + j);
		std::cout << "  ]" << std::endl;
	}
} 


void NumberLeftMostColumnWhichOnlyPositiveElements(int **matrix)
{
	std::cout << std::endl;
	int index;
	bool all_positive_elemnts = true;
	int const rows = 5, columns = 5;
	for (int i = 0; i < rows; ++ i)
	{
		for (int j = 0; j < columns; ++ j) 
		{	
			if (*(*(matrix + j) + i) < 0) {all_positive_elemnts = false; break;}
		}
		
		if (all_positive_elemnts) {index = i; break;}
	}

	if (all_positive_elemnts != false) std::cout << "Number row - " << index << std::endl;
	else std::cout << "There is no row in this matrix with only positive elements" << "\n\n";
}


void SizeTypes()
{
	std::cout << "bool:\t\t" << sizeof(bool) << " bytes" << std::endl;
    std::cout << "char:\t\t" << sizeof(char) << " bytes" << std::endl;
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << std::endl;
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << std::endl;  
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << std::endl;    
    std::cout << "short:\t\t" << sizeof(short) << " bytes" << std::endl;
    std::cout << "int:\t\t" << sizeof(int) << " bytes" << std::endl;
    std::cout << "long:\t\t" << sizeof(long) << " bytes" << std::endl;
    std::cout << "long long:\t" << sizeof(long long) << " bytes" << std::endl;
    std::cout << "float:\t\t" << sizeof(float) << " bytes" << std::endl;
    std::cout << "double:\t\t" << sizeof(double) << " bytes" << std::endl;
    std::cout << "long double:\t" << sizeof(long double) << " bytes" << std::endl;
}


void StringConversion()
{
	std::cout << std::endl;

	char symbol = 97;
	std::cout << "Symbol type char: " << symbol << std::endl;
	int int_symbol(symbol);
	std::cout << "Symbol type int: " << int_symbol << std::endl;

	// static_cast<type>(expression) принимает значение из (expression) в качестве входных данных и 
	// конвертирует его в указанный вами <type>
	std::cout << "Symbol convert with help static_cast: " << static_cast<int>(symbol) << std::endl;  
}


void MoveCharacter()
{
	std::cout << std::endl;
	std::cout << "Alert (alert) \a Warning (beep)" << std::endl;
	std::cout << "Backspace \b Moving the cursor one position back" << std::endl;
	std::cout << "formfeed \f Moving the cursor to the next logical page" << std::endl;
	std::cout << "Newline character \n Moving the cursor to the next line" << std::endl;
	std::cout << "Carriage return \r Moving the cursor to the beginning of the line" << std::endl;
	std::cout << "Horizontal tab \t Inserting a horizontal TAB" << std::endl;
	std::cout << "Vertical tab \v Insert vertical TAB" << std::endl;
	std::cout << "Single quote Insert single quote (or apostrophe)" << std::endl;
	std::cout << "Double quote Insert double quote" << std::endl;
	std::cout << "Backslash \\ Backslash insertion" << std::endl;
	std::cout << "Question mark \?	Inserting a question mark" << std::endl;
	std::cout << "Octal number (number) Converting a number from the octal number system to the char type" << std::endl;
	std::cout << "Hexadecimal number x(number) Converting a number from the hexadecimal number system to the char type" << std::endl;
}


#endif
