/*
 * AllAsciiPrintable.cpp
 *
 *  Created on: Dec 27, 2010
 *      Author: nalane
 */

#include <string>
#include <algorithm>
#include "CustomCharacterSet.h"

namespace Nathandelane
{

	/**
	 * Creates an instance of CustomCharacterSet.
	 */
CustomCharacterSet::CustomCharacterSet(const std::string characters)
	{
		_characters = characters;
		_size = _characters.size();
	}

	/**
	 * Gets the characters associated with this CharacterSet.
	 */
	std::string CustomCharacterSet::get_characters()
	{
		random_shuffle(_characters.begin(), _characters.end());

		return _characters;
	}

	/**
	 * Gets the number of characters in this CharacterSet.
	 */
	unsigned int CustomCharacterSet::size()
	{
		return _size;
	}

}
