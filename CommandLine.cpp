/*
 * CommandLine.cpp
 *
 *  Created on: Oct 8, 2015
 *      Author: nathanlane
 */

#include "CommandLine.h"
#include "Constants.h"
#include <iterator>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <vector>
#include <map>

namespace Nathandelane
{

	CommandLine::CommandLine(std::vector<std::string> args)
	{
		this->_parse_arguments(args);
	}

	CommandLine::~CommandLine()
	{
		_arguments.clear();
	}

	const std::string CommandLine::get_arg_value(const std::string argument) {
		const std::string value(_arguments[argument]);

		return value;
	}

	void CommandLine::_parse_arguments(std::vector<std::string> args)
	{
		const std::string argumentPattern("--");

		for (std::vector<std::string>::iterator it = args.begin(); it != args.end(); it++)
		{
			const std::string nextArg = *it;

			if (nextArg.compare(0, argumentPattern.length(), argumentPattern) == 0)
			{
				const std::string fullArgument(nextArg.substr(argumentPattern.length()));
				const std::string delimiter("=");
				const std::string name(fullArgument.substr(0, fullArgument.find(delimiter)));
				const std::string value(fullArgument.substr(fullArgument.find(delimiter) + delimiter.length()));

				_arguments[name] = value;
			}
		}
	}

} /* namespace Nathandelane */
