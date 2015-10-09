/*
 * DefaultCharacterSet.h
 *
 *  Created on: Dec 27, 2010
 *      Author: nalane
 */

#ifndef DEFAULTCHARACTERSET_H_
#define DEFAULTCHARACTERSET_H_

#include <string>
#include "ICharacterSet.h"

namespace Nathandelane
{

	class DefaultCharacterSet : public Nathandelane::ICharacterSet
	{
	private:
		unsigned int _size;
		std::string _characters;
	public:
		DefaultCharacterSet();
		std::string get_characters();
		unsigned int size();
	};

}

#endif /* DEFAULTCHARACTERSET_H_ */
