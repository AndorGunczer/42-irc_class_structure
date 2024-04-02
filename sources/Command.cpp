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

            // test

            for (std::vector<std::string>::iterator it = this->splitInput.begin(); it != this->splitInput.end(); it++)
                std::cout << *it << std::endl;

            if (command == "JOIN")
                std::cout << 1 << std::endl;
            else
                std::cout << 0 << std::endl;
        }

// JOIN CLASS

/*        std::vector<std::string> channelsToJoin;
        std::vector<std::string> passwordStore;
        bool removeAll = false; */

Join::Join()
{

}

Join::Join(const std::string &userInput) : Command(userInput)
{
    // this->splitInput = command.splitInput;
    // this->command = command.command;

    // split on ,;
    this->channelsToJoin = Helper::splitStringOnComma(this->splitInput[1]);
    this->passwordStore = Helper::splitStringOnComma(this->splitInput[2]);
    if (this->channelsToJoin[0] == "0")
        this->removeAll = true;
}

Join::~Join()
{

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
