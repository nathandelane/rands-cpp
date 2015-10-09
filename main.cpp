/*
 * main.cpp
 *
 *  Created on: Dec 21, 2010
 *  Author: nalane
 */

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include "Constants.h"
#include "CommandLine.h"
#include "RandomString.h"
#include "UniqueLengthException.h"
#include "ICharacterSet.h"
#include "DefaultCharacterSet.h"
#include "HtmlFriendlyCharacterSet.h"
#include "AllAsciiPrintable.h"
#include "AlphaCharacterSet.h"
#include "AlphaNumericCharacterSet.h"
#include "UniqueCharacterSet.h"
#include "CustomCharacterSet.h"

/**
 * Tokenizes a string.
 */
static std::vector<std::string> tokenize(const std::string & str, const std::string delimiters)
{
	std::vector<std::string> result;
	std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	std::string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (std::string::npos != pos || std::string::npos != lastPos)
	{
		result.push_back(str.substr(lastPos, pos - lastPos));

		lastPos = str.find_first_not_of(delimiters, pos);
		pos = str.find_first_of(delimiters, lastPos);
	}

	return result;
}

/**
 * Creates a map of character sets with their names as keys.
 */
static std::map<std::string, Nathandelane::ICharacterSet *> create_map()
{
	std::map<std::string, Nathandelane::ICharacterSet *> map;
	map[Nathandelane::AllAsciiPrintableValue] = (new Nathandelane::AllAsciiPrintable());
	map[Nathandelane::AlphaNumericArgValue] = (new Nathandelane::AlphaNumericCharacterSet());
	map[Nathandelane::AlphaOnlyArgValue] = (new Nathandelane::AlphaCharacterSet());
	map[Nathandelane::HtmlFriendlyArgValue] = (new Nathandelane::HtmlFriendlyCharacterSet());

	return map;
}

static int string_to_int(const std::string value, const int defaultValue) {
	int i;

	if (!value.empty())
	{
		std::stringstream str(value);

		str >> i;
	}
	else
	{
		i = defaultValue;
	}

	return i;
}

static int show_usage(const int argc, const char* argv[])
{
	std::string firstArgument(argv[0]);
	std::vector<std::string> tokens = tokenize(firstArgument, "/\\");

	std::cout << "Usage: " << tokens.back() << " "
		<< "--" << Nathandelane::NumberOfChars << "=<number-of-characters> [ "
		<< "--" << Nathandelane::NumStringsValue << "=<number-of-strings> ] [ "
		<< "--" << Nathandelane::Strategy << "=<strategy (one of "
			<< Nathandelane::AllAsciiPrintableValue << "|"
			<< Nathandelane::AlphaNumericArgValue << "|"
			<< Nathandelane::AlphaOnlyArgValue << "|"
			<< Nathandelane::HtmlFriendlyArgValue << "|"
			<< Nathandelane::Custom << ":<custom-value>|(or omit for default)"
		<< ")> ] [ "
		<< "--" << Nathandelane::HexArgValue << " ] [ "
		<< "--" << Nathandelane::UniqueOnlyArgValue << " ] ]" << std::endl << std::endl;

	return 1;
}

static void error_message(const std::string message)
{
	std::cerr << message << std::endl << std::endl;
}

static std::vector<std::string> roll_new_random_string(Nathandelane::RandomString * randomString, const int numStrings, const int length, const bool printHexString, const bool uniqueOnly)
{
	std::vector<std::string> rands;

	for (int stringCounter = 0; stringCounter < numStrings; stringCounter++)
	{
		std::string nextString = randomString->NextString();
		std::string nextRandomString;

		for (int charIndex = 0; charIndex < length; charIndex++)
		{
			const char nextChar = nextString[charIndex];

			nextRandomString += nextChar;
		}

		rands.push_back(nextRandomString);

		if (printHexString)
		{
			std::string hexString;

			for (int charIndex = 0; charIndex < length; charIndex++)
			{
				int nextChar = nextString[charIndex];

				std::stringstream ss;
				ss << std::hex << nextChar;

				hexString += ss.str();
			}

			rands.push_back(hexString);
		}
	}

	return rands;
}

int main(int argc, const char* argv[])
{
	std::map<std::string, Nathandelane::ICharacterSet *> characterSets = create_map();

	Nathandelane::ICharacterSet * characterSet = (new Nathandelane::DefaultCharacterSet());

	const std::vector<std::string> arguments(argv, argv + argc);

	Nathandelane::CommandLine * commandLine = (new Nathandelane::CommandLine(arguments));

	if (arguments.size() == 1)
	{
		return show_usage(argc, argv);
	}
	else if (arguments.size() >= 2)
	{
		const int length = string_to_int(commandLine->get_arg_value(Nathandelane::NumberOfChars), 0);
		const int numStrings = string_to_int(commandLine->get_arg_value(Nathandelane::NumStringsValue), 1);
		const bool printHexString = !commandLine->get_arg_value(Nathandelane::HexArgValue).empty();
		const bool uniqueOnly = !commandLine->get_arg_value(Nathandelane::UniqueOnlyArgValue).empty();

		if (!commandLine->get_arg_value(Nathandelane::Strategy).empty())
		{
			const std::string custom("custom");

			if (!commandLine->get_arg_value(Nathandelane::Strategy).compare(0, custom.length(), custom) == 0)
			{
				const std::map<std::string, Nathandelane::ICharacterSet *>::iterator it = characterSets.find(commandLine->get_arg_value(Nathandelane::Strategy));

				if (it != characterSets.end()) {
					characterSet = characterSets[commandLine->get_arg_value(Nathandelane::Strategy)];
				}
				else {
					error_message("ERROR: Misunderstood strategy - defaulting to default character set!");
				}
			}
			else if (commandLine->get_arg_value(Nathandelane::Strategy).compare(0, custom.length(), custom) == 0)
			{
				const std::string strategyValue = commandLine->get_arg_value(Nathandelane::Strategy);
				const std::string customCharacterSet = strategyValue.substr(strategyValue.find(":") + 1);

				characterSet = (new Nathandelane::CustomCharacterSet(customCharacterSet));
			}
		}

		if (length > 0)
		{
			Nathandelane::RandomString randomString(length, * characterSet, uniqueOnly);

			try
			{
				std::vector<std::string> strings = roll_new_random_string(&randomString, numStrings, length, printHexString, uniqueOnly);

				for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
				{
					const std::string nextString = *it;

					std::cout << nextString << std::endl;
				}
			}
			catch(Nathandelane::UniqueLengthException& ex)
			{
				std::cout << ex.what() << std::endl << std::endl;
				return 1;
			}
			catch(std::exception& ex)
			{
				const std::string what(ex.what());
				error_message("Unexpected exception occurred: " + what);
				return 1;
			}
		}
		else
		{
			error_message("Error: --" + Nathandelane::NumberOfChars + " must be greater than zero.");
		}
	}


	std::cout << std::endl << std::endl;

	return 0;
}
