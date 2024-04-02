/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:51:17 by agunczer          #+#    #+#             */
/*   Updated: 2024/04/01 15:06:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>
#include "../includes/Helper.hpp"

// Objective:
//      1. Take Command, after calling the constructor we should be able to determine the callable function
//      2. Determine Function to be Called if (statement)
//      3. constructor of subclass
//      4. call Function (_socket, class)
//      5. function implementation (Steven)

class Command
{
    private:
        Command(Command const &copyCommand);
        Command const &operator=(Command const &assignToThis);

	public:
		std::vector<std::string> splitInput;
		std::string command;

        Command();
        ~Command();
        Command(const std::string &userInput);
};

class Join : public Command {
    private:
        Join();

    public:
        std::vector<std::string> channelsToJoin;
        std::vector<std::string> passwordStore;
        bool removeAll = false;

        Join(const std::string &userInput);
        ~Join();
};

class Cap : public Command {
    public:
        
};

class Part : public Command {
    public:
        std::vector<std::string> channelsToLeave;
};

class Topic : public Command {
    
};

class Mode : public Command {
    public:
        std::string channelName;
		std::vector<std::string> negativeModeParams;	
		std::vector<std::string> positiveModeParams;
};

class PrivMSG : public Command {

};

class Nick : public Command {

};

class Who : public Command {

};

class WhoIs : public Command {

};

class Ping : public Command {

};

/*

	void checkCommand(int _clientSocket);
	bool checkCAP(int _clientSocket, const std::string &msg);
	bool checkJOIN(int _clientSocket, const std::string &msg);
	bool checkPART(int _clientSocket, const std::string &msg);
	bool checkPRIVMSG(int _clientSocket, const std::string &msg);
	bool checkNICK(int _clientSocket, const std::string &msg);
	bool checkWHO(int _clientSocket, const std::string &msg);
	bool checkWHOIS(int _clientSocket, const std::string &msg);
	bool checkMODE(int _clientSocket, const std::string &msg);
	bool checkPING(int _clientSocket, const std::string &msg);
	bool checkQUIT(int _clientSocket, const std::string &msg);
	bool unknownCMD(int _clientS

*/