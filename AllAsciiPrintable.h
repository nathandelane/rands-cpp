/*
 * AllAsciiPrintable.h
 *
 *  Created on: Dec 27, 2010
 *      Author: nalane
 */

#ifndef ALLASCIIPRINTABLE_H_
#define ALLASCIIPRINTABLE_H_

#include <string>
#include "ICharacterSet.h"

namespace Nathandelane
{

	class AllAsciiPrintable : public Nathandelane::ICharacterSet
	{
	private:
		unsigned int _size;
		std::string _characters;
	public:
		AllAsciiPrintable();
		std::string get_characters();
		unsigned int size();
	};

}

#endif /* ALLASCIIPRINTABLE_H__ */
