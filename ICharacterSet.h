/*
 * ICharacterSet.h
 *
 *  Created on: Dec 27, 2010
 *      Author: nalane
 */

#ifndef ICHARACTERSET_H_
#define ICHARACTERSET_H_

#include <string>

namespace Nathandelane
{

	class ICharacterSet
	{
	public:
		virtual std::string getCharacters() = 0;
		virtual unsigned int size() = 0;
	};

}

#endif /* ICHARACTERSET_H_ */
