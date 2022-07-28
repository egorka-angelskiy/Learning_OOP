#include <iostream>
#include <string>
#include <bitset>






void Bit()
{
	int a = 3;
	int b = 5;
  
                                                                // ПОБИТОВАЯ ДИЗЪЮНКЦИЯ
  
	std::cout << "\nBitwise disjunction"<< std::endl;               
	std::cout << "a = "<< a << " -> " << std::bitset<8>(a) << std::endl;        		// a = 0d00000011
	std::cout << "b = " << b << " -> " << std::bitset<8>(b) << std::endl;       		// b = 0d00000101
	a |= b;
	std::cout << std::endl;
	std::cout << "After disjunction = " << a << " -> " << std::bitset<8>(a) << std::endl;     // a = 0d00000111
	std::cout << std::endl;
	std::cout << std::endl;
  
  
                                                      // ПОБИТОВАЯ ДИЗЪЮНКЦИЯ (ИСКЛЮЧАЮЩАЯ ДИЗЪЮНКЦИЯ)

	std::cout << "\nBitwise disjunction(exclusive disjunction)"<< std::endl;	
	std::cout << "a = "<< a << " -> " << std::bitset<8>(a) << std::endl;          					// a = 0d00000111
	std::cout << "b = " << b << " -> " << std::bitset<8>(b) << std::endl;         					// b = 0d00000101
	a ^= b;
	std::cout << std::endl;
	std::cout << "After disjunction(exclusive disjunction) = " << a << " -> " << std::bitset<8>(a) << std::endl;      //a = 0d00000010
	std::cout << std::endl;
	std::cout << std::endl;

	a = 3;
	b = 5;
  
                                                              // ПОБИТОВАЯ КОНЪЮНКЦИЯ
  
	std::cout << "\nBitwise conjunction"<< std::endl;
	std::cout << "a = "<< a << " -> " << std::bitset<8>(a) << std::endl;                         // a = 0d00000011
	std::cout << "b = " << b << " -> " << std::bitset<8>(b) << std::endl;           	     // b = 0d00000101
	a &= b;
	std::cout << std::endl;
	std::cout << "After conjunction = " << a << " -> " << std::bitset<8>(a) << std::endl;       // a = 0d00000001
	std::cout << std::endl;
	std::cout << std::endl;


  
                                                              // ИНВЕРТИРОВАНИЕ
  
	// flip - Преобразует битовую маску в обратный код.  flip(place bit value), flip(void) инвертирует все биты
	std::cout << "\nBitwise invert(function flip)" << std::endl;
	std::bitset<8>(c) (std::string("1000101"));
	std::cout << "Originall bitwise mask = " << c.to_ulong() << " -> " << c << std::endl;          // c = 0d01000101
	std::cout << "Invert first bit = " << c.flip(0).to_ulong() << " -> " << c << std::endl;        // c = 0d01000100
	std::cout << "Invert all bit = " << c.flip().to_ulong() << " -> " << c << std::endl;           // c = 0d10111011
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "\nBitwise invert(~)" << std::endl;
	std::bitset<8>(d) (std::string("00011011"));
	std::cout << "Originall bitwise mask = " << d.to_ulong() << " -> " << d << std::endl;                   // d = 0d00011011
	d = ~d;
	std::cout << "After invert = " << d.to_ulong() << " -> " << d << std::endl;     			// d = 0d11100100
	std::cout << std::endl;
	std::cout << std::endl;
	
	
	
								// ДОБАВЛЕНИЕ БИТА
	
	// set(value place bit) - позволяет нам установить бит в 1 (она ничего не сделает, если бит уже равен 1)
	// set(void) - ставит на все позиции 1
	std::cout << "Bitwise add if the place that replacing is 0" << std::endl;
	std::bitset<8>(e) (std::string("01010101"));
	std::cout << "Originall bitwise mask = " << e.to_ulong() << " -> " << e << std::endl;			// e = 0d01010101
	e.set(1);
	std::cout << "After add = " << e.to_ulong() << " -> " << e << std::endl;				// e = 0d01010111
	std::cout << std::endl;
	std::cout << std::endl;






								// ЗАМЕНА БИТА

	// reset(value place bit) - сбрасываем бит в 0 (она ничего не сделает, если бит уже равен 0)
	// reset(void) - ставит на все позиции 0
	std::cout << "Bitwise add if the place that replacing is 1" << std::endl;
	std::cout << "Originall bitwise mask = " << e.to_ulong() << " -> " << e << std::endl;			// e = 0d01010111
	e.reset(1);
	std::cout << "After add = " << e.to_ulong() << " -> " << e << std::endl;				// e = 0d01010101
	std::cout << std::endl;
	std::cout << std::endl;
}


void BitShift()
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
	Bit();
	BitShift();
	return 0;
}
