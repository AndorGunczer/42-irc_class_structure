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

void Command::commandHandler(std::string inputCommand)
{
    if (inputCommand == "Join")
    {

    } else if (inputCommand == "CAP") {

    } else if (inputCommand == "PART") {

    } else if (inputCommand == "TOPIC") {

    } else if (inputCommand == "MODE") {

    } else if (inputCommand == "PRIVMSG") {

    } else if (inputCommand == "NICK") {

    } else if (inputCommand == "WHO") {

    } else if (inputCommand == "WHOIS") {

    } else if (inputCommand == "PING") {

    } else if (inputCommand == "KICK") {

    }
}

// CAP CLASS

Cap::Cap()
{

}


Cap::Cap(const std::string &userInput) : Command(userInput)
{
    
}

Cap::~Cap()
{

}

// PART CLASS

Part::Part()
{

}


Part::Part(const std::string &userInput) : Command(userInput)
{
    
}

Part::~Part()
{

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

// TOPIC CLASS

Topic::Topic()
{

}

Topic::Topic(const std::string &userInput) : Command(userInput)
{
    this->channel = this->splitInput[1];
    this->topic = this->splitInput[2];
}

Topic::~Topic()
{

}

// MODE CLASS

Mode::Mode()
{

}

Mode::Mode(const std::string &userInput) : Command(userInput)
{
    this->modeStore = Helper::collectModes(this->splitInput);
}

Mode::~Mode()
{

}

// PRIVMSG CLASS

PrivMSG::PrivMSG()
{

}


PrivMSG::PrivMSG(const std::string &userInput) : Command(userInput)
{
    
}

PrivMSG::~PrivMSG()
{

}

// NICK CLASS

Nick::Nick()
{

}


Nick::Nick(const std::string &userInput) : Command(userInput)
{
    
}

Nick::~Nick()
{

}

// WHO CLASS

Who::Who()
{

}


Who::Who(const std::string &userInput) : Command(userInput)
{
    
}

Who::~Who()
{

}

// WHOIS CLASS

WhoIs::WhoIs()
{

}


WhoIs::WhoIs(const std::string &userInput) : Command(userInput)
{
    
}

WhoIs::~WhoIs()
{

}

// PING CLASS

Ping::Ping()
{

}


Ping::Ping(const std::string &userInput) : Command(userInput)
{
    
}

Ping::~Ping()
{

}

// KICK CLASS

Kick::Kick()
{

}


Kick::Kick(const std::string &userInput) : Command(userInput)
{
    
}

Kick::~Kick()
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
