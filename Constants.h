/*
 * Constants.h
 *
 *  Created on: Oct 8, 2015
 *      Author: nathanlane
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

namespace Nathandelane
{

	// Character sets or strategies
	const std::string HtmlFriendlyArgValue("htmlfriendly");
	const std::string AlphaOnlyArgValue("alphaonly");
	const std::string AlphaNumericArgValue("alphanumeric");
	const std::string AllAsciiPrintableValue("allasciiprintable");
	const std::string Custom("custom");

	// Command-line arguments, must begin with --argument
	const std::string NumberOfChars("numchars");
	const std::string NumStringsValue("numstrings");
	const std::string Strategy("strategy");
	const std::string HexArgValue("hex");
	const std::string UniqueOnlyArgValue("uniqueonly");

}

#endif /* CONSTANTS_H_ */
