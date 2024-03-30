/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:49:56 by agunczer            #+#    #+#             */
/*   Updated: 2024/03/30 11:49:56 by agunczer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Command.hpp"

// COMMAND CLASS
// For "instructions" on how to use the class structure go to the end of page

/*		std::vector<std::string> splitInput;
		std::string command; */

        Command::Command(Command const &copyCommand)
        {
            *this = copyCommand;
        }

        Command const &Command::operator=(Command const &assignToThis)
        {
            this->splitInput = assignToThis.splitInput;
            this->command = assignToThis.command;

            return *this;
        }

        Command::Command()
        {

        }

        Command::~Command()
        {

        }

        Command::Command(const std::string &userInput)
        {

            this->splitInput = Helper::splitString(userInput);
            this->command = this->splitInput[0];

            for (std::vector<std::string>::iterator it = this->splitInput.begin(); it != this->splitInput.end(); it++)
                std::cout << *it << std::endl;
        }

/*
    PSEUDO CODE FOR DECISION MAKING AND CALLING EXECUTORS (Which Command function to call)

    if (command == "JOIN")
    {
        Join joinInstance = Join(command);
        executeJoin(int _clientSocket, const Join &msg);
    }
    if (command == "PART")
    {
        Part partInstance = Part(command);
        executePart(int _clientSocket, const Part &msg);
    }

    In execute* functions we execute the appropriate command
*/
