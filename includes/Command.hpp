/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:51:17 by agunczer          #+#    #+#             */
/*   Updated: 2024/04/03 12:18:58 by marvin           ###   ########.fr       */
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
    private:
        Cap();
    public:
        
        Cap(const std::string &userInput);
        ~Cap();
};

class Part : public Command {
    private:
        Part();
    public:
        std::vector<std::string> channelsToLeave;

        Part(const std::string &userInput);
        ~Part();
};

class Topic : public Command {
    private:
        Topic();

    public:
        std::string channel;
        std::string topic;

        Topic(const std::string &userInput);
        ~Topic();
};

class Mode : public Command {
    private:
        Mode();

    public:
        std::vector<parsedMode> modeStore;

        Mode(const std::string &userInput);
        ~Mode();
};

class PrivMSG : public Command {
    private:
        PrivMSG();

    public:
        
        PrivMSG(const std::string &userInput);
        ~PrivMSG();
};

class Nick : public Command {
    private:
        Nick();

    public:
        Nick(const std::string &userInput);
        ~Nick();
};

class Who : public Command {
    private:
        Who();

    public:
        std::string userRegex;
        bool isOperator;

        Who(const std::string &userInput);
        ~Who();
};

class WhoIs : public Command {
    private:
        WhoIs();

    public:
        std::string serverName;
        std::string userName;

        WhoIs(const std::string &userInput);
        ~WhoIs();
};

class Ping : public Command {
    private:
        Ping();

    public:
        std::string serverName;
                
        Ping(const std::string &userInput);
        ~Ping();
};

class Kick : public Command {
    private:
        Kick();

    public:
        std::string channelName;
        std::string user;
        std::string reason;

        Kick(const std::string &userInput);
        ~Kick();
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