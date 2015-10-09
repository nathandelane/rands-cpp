/*
 * AllAsciiPrintable.h
 *
 *  Created on: Dec 27, 2010
 *      Author: nalane
 */

#ifndef CUSTOMCHARACTERSET_H_
#define CUSTOMCHARACTERSET_H_

#include <string>
#include "ICharacterSet.h"

namespace Nathandelane
{

	class CustomCharacterSet : public Nathandelane::ICharacterSet
	{
	private:
		unsigned int _size;
		std::string _characters;
	public:
		CustomCharacterSet(std::string);
		std::string getCharacters();
		unsigned int size();
	};

}

#endif /* CUSTOMCHARACTERSET_H_ */
