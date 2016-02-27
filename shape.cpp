/* ----------------------------------------------------------------------------
 * Copyright &copy; 2016 YOUR_NAME <YOUR_EMAIL>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */



#include <string>
#include <iostream>
#include "buffer.h"
#include "neighborhood.h"
#include "shape.h"
#include "constants.h"

class Shape;
class Neighborhood;
class Buffer;



Shape::Shape(const std::string & type)
	:type_(type)
	{
		setType(type);
		/**
		* The constructor.
		*
		* Must initialize `type_`, and `type_art_`.
		*
		* Notes:
		* - I suggest calling `setType` in the body of the constructor, to
		*   avoid duplicating code.
	*/
	}

	Shape::~Shape() = default;
		
		
	

	std::string Shape::getType()
	{
		return type_;
	}
	

	void Shape::setType(const std::string & type)
	{
		type_ = type;

		if (type == "empty")
			type_art_ =

			"     \n"
			"     \n"
			"     \n"
			;

		else if (type == "triangle")
			type_art_ =
			"  ,  \n"
			" / \\ \n"
			"/___\\\n"
			;

		else if (type == "square")
			type_art_ =
			".---.\n"
			"|   |\n"
			"'---'\n"
			;
		else
		{
			std::cerr << "ERROR: `Shape::setType`: invalid type\n";
			exit(1);
		}

	}




	void Shape::drawToBuffer(Buffer & b, unsigned int x, unsigned int y) const
	{

		b.set(x, y, type_art_);

	}

	/**
	* Draw `type_art_` onto the `Buffer` at position `x, y`.
	*
	* Notes:
	* - This (primarily) is what
	*   ```
	*   void Buffer::set(unsigned int, unsigned int, std::string);
	*   ```
	*   is for.
	*/


	bool Shape::isHappy(const Neighborhood & n,
		unsigned int pos_x,
		unsigned int pos_y) const {

		if (n.get(pos_x, pos_y).getType() == "empty")
			return true;

		unsigned int x_min = (pos_x == 0) ? pos_x : pos_x - 1;
		unsigned int y_min = (pos_y == 0) ? pos_y : pos_y - 1;

		unsigned int x_max = (pos_x == n.size_x - 1) ? pos_x : pos_x + 1;
		unsigned int y_max = (pos_y == n.size_y - 1) ? pos_y : pos_y + 1;

		double alike = 0;
		double different = 0;

		for (int x = x_min; x <= x_max; x++) {
			for (int y = y_min; y <= y_max; y++) {
				if (x == pos_x && y == pos_y)
					continue;
				else if (n.get(x, y).getType() == "empty")
					continue;
				else if (n.get(x, y).getType() == n.get(pos_x, pos_y).getType())
					alike++;
				else
					different++;
			}
		}

		return    (different || alike)
			&& (different == 0 || alike / different >= RATIO_ALIKE_HAPPY)
			&& (alike == 0 || different / alike >= RATIO_DIFFERENT_HAPPY);
	}