/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:51:17 by agunczer          #+#    #+#             */
/*   Updated: 2024/03/27 13:02:49 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

// Objective:
//      1. Take Command, after calling the constructor we should be able to determine the callable function
//      2. Determine Function to be Called if (statement)
//      3. constructor of subclass
//      4. call Function (_socket, class)
//      5. function implementation (Steven)

class Command
{
	public:
        int socket;
		std::vector<std::string> splitInput;
		std::string command;
};

class Join : public Command {
    public:
        std::vector<std::string> channelsToJoin;
        std::vector<std::string> passwordStore;
        bool removeAll = false;
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