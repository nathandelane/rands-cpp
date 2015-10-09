/*
 * DefaultCharacterSet.cpp
 *
 *  Created on: Dec 27, 2010
 *      Author: nalane
 */

#include <string>
#include <algorithm>
#include "DefaultCharacterSet.h"

namespace Nathandelane
{

	/**
	 * Creates an instance of DefaultCharacterSet.
	 */
	DefaultCharacterSet::DefaultCharacterSet()
	{
		_characters = "0123456789abcdefghijklmnopqrstuvwxyz";
		_size = _characters.size();
	}

	/**
	 * Gets the characters associated with this CharacterSet.
	 */
	std::string DefaultCharacterSet::get_characters()
	{
		random_shuffle(_characters.begin(), _characters.end());

		return _characters;
	}

	/**
	 * Gets the number of characters in this CharacterSet.
	 */
	unsigned int DefaultCharacterSet::size()
	{
		return _size;
	}

}
