/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 Ian McQueen <ianmcqueen@live.ca>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * Implements `buffer.h`.
 */

// TODO: `#include`s for system headers, if necessary

#include "buffer.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

// TODO: `#include`s for other local headers, if necessary

// ----------------------------------------------------------------------------

// TODO: implementations for all functions in `class Buffer`


Buffer::Buffer(unsigned int size_x, unsigned int size_y): size_x(size_x), size_y(size_y)
{
	data_ = new char[size_x * size_y];
	clear();

}

Buffer::~Buffer()
{


	delete[] data_;
}







char Buffer::get(unsigned int x, unsigned int y) const
{


	if (x >= size_x || y >= size_y)
	{
		cerr << "ERROR: `Buffer::get`: index out of bounds\n" << endl;
		exit(1);
	}

	else 

	return data_[y * size_x + x];

}

void Buffer::set(unsigned int x, unsigned int y, char c)
{

	if (x >= size_x || y >= size_y)
	{
		cerr << "ERROR: `Buffer::get`: index out of bounds\n" << endl;
		exit(1);
	}

	else

	data_[y * size_x + x] = c;

}

void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s) 
{

	for (int i = 0, x = pos_x, y = pos_y; i < s.length(); i++) {
		if (s[i] == '\n') {
			y++;
			x = pos_x;
		}
		else {
			set(x++, y, s[i]);
		}
	}

}

void Buffer::draw() const 
{

		for (int i = 0; i < (size_x*size_y); i++)
			cout << data_[i];
		cout << endl;
	
}


void Buffer::clear() 
{
	for (unsigned int j = 0; j < size_y; j++)
		for (unsigned int i = 0; i < (size_x); i++)
			data_[j * size_x + i] = ' ';


}
