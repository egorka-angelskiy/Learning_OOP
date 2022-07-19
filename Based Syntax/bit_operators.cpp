#include <iostream>
#include <string>
#include <bitset>

void bit()
{
	int a = 3;
	int b = 5;
  
                                                                // ПОБИТОВАЯ ДИЗЪЮНКЦИЯ
  
	std::cout << "\nBitwise disjunction"<< std::endl;               
	std::cout << "a = "<< a << " -> " << std::bitset<8>(a) << std::endl;        // a = 0d00000011
	std::cout << "b = " << b << " -> " << std::bitset<8>(b) << std::endl;       // b = 0d00000101
	a |= b;
	std::cout << std::endl;
	std::cout << "After disjunction = " << a << " -> " << std::bitset<8>(a) << std::endl;     // a = 0d00000111
	std::cout << std::endl;
  
  
                                                      // ПОБИТОВАЯ ДИЗЪЮНКЦИЯ (ИСКЛЮЧАЮЩАЯ ДИЗЪЮНКЦИЯ)

	std::cout << "\nBitwise disjunction(exclusive disjunction)"<< std::endl;	
	std::cout << "a = "<< a << " -> " << std::bitset<8>(a) << std::endl;          // a = 0d00000111
	std::cout << "b = " << b << " -> " << std::bitset<8>(b) << std::endl;         // b = 0d00000101
	a ^= b;
	std::cout << std::endl;
	std::cout << "After disjunction(exclusive disjunction) = " << a << " -> " << std::bitset<8>(a) << std::endl;      //a = 0d00000010
	std::cout << std::endl;

	a = 3;
	b = 5;
  
                                                              // ПОБИТОВАЯ КОНЪЮНКЦИЯ
  
	std::cout << "\nBitwise conjunction"<< std::endl;
	std::cout << "a = "<< a << " -> " << std::bitset<8>(a) << std::endl;            // a = 0d00000011
	std::cout << "b = " << b << " -> " << std::bitset<8>(b) << std::endl;           // b = 0d00000101
	a &= b;
	std::cout << std::endl;
	std::cout << "After conjunction = " << a << " -> " << std::bitset<8>(a) << std::endl;       //a = 0d00000001
	std::cout << std::endl;


  
                                                              // ИНВЕРТИРОВАНИЕ
  
	// flip - Преобразует битовую маску в обратный код.  flip(place bit value), flip(void) инвертирует все биты
	std::cout << "\nBitwise invert(function flip)" << std::endl;
	std::bitset<8>(c) (std::string("1000101"));
	std::cout << "Originall bitwise mask -> " << c << std::endl;          // c = 0d01000101
	std::cout << "Invert first bit -> " << c.flip(0) << std::endl;        // c = 0d01000100
	std::cout << "Invert all bit -> " << c.flip() << std::endl;           // c = 0d10111011
	std::cout << std::endl;


	std::cout << "\nBitwise invert(~)" << std::endl;
	std::bitset<8>(d) (std::string("00011011"));
	std::cout << "Originall bitwise mask -> " << d << std::endl;                        // d = 0d00011011
	d = ~d;
	std::cout << "After invert: " << d << " -> " << std::bitset<8>(d) << std::endl;     // d = 0d11100100
	std::cout << std::endl;
	std::cout << std::endl;
}


void bit_shift()
{
	int a = 0b1010;
  
  
                                                        // СДВИГ НА ОПРЕДЕЛЕННОЕ КОЛ-ВО БИТ
  
	std::cout << "Originall number : ";                                 
	std::cout << a << " -> " << std::bitset<8>(a) << std::endl;       // a = 0d00001010

	a <<= 1;
	std::cout << "After left shift : ";
	std::cout << a << " -> " << std::bitset<8>(a) << std::endl;       // a = 0d00010100 

	a >>= 2;
	std::cout << "After right shift : ";
	std::cout << a << " -> " << std::bitset<8>(a) << std::endl;       // a = 0d00000101
}


int main(int argc, char const *argv[])
{
	bit();
	bit_shift();
	return 0;
}
