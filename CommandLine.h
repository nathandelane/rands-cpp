/*
 * CommandLine.h
 *
 *  Created on: Oct 8, 2015
 *      Author: nathanlane
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <string>
#include <cstring>
#include <vector>
#include <map>

namespace Nathandelane
{

	class CommandLine
	{
	private:
		std::map<std::string, std::string> _arguments;
		void _parse_arguments(std::vector<std::string>);
	public:
		CommandLine(std::vector<std::string>);
		virtual ~CommandLine();
		const std::string get_arg_value(std::string);
	};

}

#endif /* COMMANDLINE_H_ */
