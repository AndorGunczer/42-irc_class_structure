/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cap.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:25:55 by marvin            #+#    #+#             */
/*   Updated: 2024/04/04 10:25:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cap.hpp"
// #include "../includes/Server.hpp"

Cap::Cap()
{

}


Cap::Cap(const std::string &userInput) : Command(userInput)
{
    this->capSubCommand = this->splitInput[1];
}

Cap::~Cap()
{

}

// bool Cap::execute(int _clientSocket)
// {
//         std::string custom = "";
// 		clients[_clientSocket].recvMsg = "";
// 		std::string replyMsg = "";
// 		if (this->capSubCommand == "LS")
// 		{
// 			replyMsg = "CAP * LS :multi-prefix sasl\r\n";
// 			srvSend(_clientSocket, replyMsg);
// 			return (true);
// 		} 
// 		else if (this->capSubCommand == "REQ")
// 		{
// 			// substract all after "CAP REQ :"
// 			custom = this->receivedString.substr(this->capSubCommand.size() + this->capSubCommand.size() + 2, msg.size() - (capSize + this->capSubCommand.size() + 4));
// 			replyMsg = "CAP * ACK :" + this->capSubCommand + CRLF;
// 			srvSend(_clientSocket, replyMsg);
// 			return (true);
// 		}
// 		else if (this->capSubCommand == "END")
// 		{
// 			std::string incomingMsg;
// 			// wait for receiving NICK <username and USER <username> <usermode> <hostname> <clientcomment>
// 			size_t breakit = 0;
// 			while (Server::Signal == false)
// 			{
// 				char buffer[1024];
// 				ssize_t bytes_received = recv(_clientSocket, buffer, sizeof(buffer), 0);
// 				if (bytes_received < 1)
// 				{
// 					if (++breakit >= 99999999)
// 						break;
// 					continue;
// 				}

// 				buffer[bytes_received] = '\0';
// 				incomingMsg = std::string(buffer);
// 				break;
// 			}
// 			std::cout << magenta << "srvRecv: " << incomingMsg << res;
//             // 19901
// 			// create tokens, split string on each space ' '.
// 			std::vector<std::string> strTokens = Helper::splitString(incomingMsg);
// 			std::vector<std::string>::iterator itToken = strTokens.begin();

// 			bool foundPASS = false;
// 			// set <password>
// 			if (itToken != strTokens.end() && *itToken == "PASS")
// 			{
// 				if (++itToken != strTokens.end() && !itToken->empty())
// 					itToken->erase(0, 1);
// 				if (*itToken == _password)
// 				{
// 					foundPASS = true;
// 					clients[_clientSocket].Password = *itToken;
// 				}
// 				++itToken;
// 			}
// 			if (!foundPASS)
// 			{
// 				replyMsg = ERR_PASSWDMISMATCH(clients[_clientSocket].Nickname);
// 				srvSend(_clientSocket, replyMsg);
// 				clients[_clientSocket].Connected = false;
// 				return (true);
// 			}

// 			// set <nickname> and send reply to client
// 			if (itToken != strTokens.end() && *itToken == "NICK")
// 			{
// 				if (++itToken != strTokens.end())
// 					checkNICK(_clientSocket, "NICK " + *itToken + "\r\n");
// 				++itToken;
// 			}
// 			if (itToken != strTokens.end() && *itToken == "USER")
// 			{
// 				// set <username>
// 				if (++itToken != strTokens.end())
// 					clients[_clientSocket].Username = *itToken;
// 				// set <usermode>
// 				if (++itToken != strTokens.end())
// 					clients[_clientSocket].UserMode = *itToken;
// 				// set <hostname>
// 				if (++itToken != strTokens.end())
// 					clients[_clientSocket].Hostname = *itToken;
// 				// set <realname>
// 				// skip ':1,8' (kvIRC comment)
// 				if (++itToken != strTokens.end() && !itToken->empty())
// 					itToken->erase(0, 5);
// 				while (itToken != strTokens.end())
// 				{
// 					clients[_clientSocket].Realname += *itToken;
// 					if (++itToken != strTokens.end())
// 						clients[_clientSocket].Realname += " ";
// 				}
// 			}

// 			// send welcome message and login
// 			replyMsg = RPL_WELCOME(clients[_clientSocket].Nickname);
// 			srvSend(_clientSocket, replyMsg);
// 			// send message of the day
// 			replyMsg = RPL_MOTD();
// 			srvSend(_clientSocket, replyMsg);
// 			return (true);
// 		}
// 	return (true);
// }