/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:57:09 by slippert          #+#    #+#             */
/*   Updated: 2024/04/07 20:05:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Command.hpp"
#include "../includes/Server.hpp"
#include "../includes/Cap.hpp"
#include "../includes/Helper.hpp"

bool checkPort(char *_port, int *port)
{
	*port = static_cast<int>(std::atoi(_port));
	if (*port >= 1024 && *port <= 49151)
		return (true);
	else
		return (false);
}

int main(int argc, char **argv)
{
	int port = 0;
	if (argc != 3 || (argc == 3 && !checkPort(argv[1], &port)))
		return (std::cerr << "usage ./ircserv <port> <password>\n", 1);

	std::string password(argv[2]);
	Server server(port, password);
	try
	{
		server.start();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}


// int main() {
//     // test 1: Command Class
//     {
    
//         // std::string userInput = "JOIN #wedogreat +o 12345";

//         // Command newCommand = Command(userInput);
//     }
//     // test 2: Helper::splitStringOnComma()
//     {
//         // std::string const &multipleChannels = "#wedogreat";
//         // std::vector<std::string> channels = Helper::splitStringOnComma(multipleChannels);

//         // for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it){
//         //     std::cout << *it << std::endl;
//         // }
//     }
//     // test 3: Join Class
//     {
//         // Command testClassCommand("JOIN #wedogreat,#foo,&bar 12345,thisissuper");
//         // Join testClass("JOIN #wedogreat,#foo,&bar 12345,thisissuper");

//         // for (std::vector<std::string>::iterator it = testClass.channelsToJoin.begin(); it != testClass.channelsToJoin.end(); ++it){
//         //     std::cout << *it << std::endl;
//         // }

//         // for (std::vector<std::string>::iterator it = testClass.passwordStore.begin(); it != testClass.passwordStore.end(); ++it){
//         //     std::cout << *it << std::endl;
//         // }
//     }
//     // test 4: Mode Parsing
//         // Test 4.1
//     {
//         std::vector<std::string> testVector;
//         testVector.push_back("#wedogreat");
//         testVector.push_back("+oeia");
//         testVector.push_back("spiritusz");
//         testVector.push_back("-oavk");
//         testVector.push_back("buszbaaszas");

//         std::vector<parsedMode> testMode = Helper::collectModes(testVector);

//         for (std::vector<parsedMode>::iterator it = testMode.begin(); it < testMode.end(); ++it) {
//             std::cout << (*it).channel << std::endl;
//             std::cout << (*it).modes << std::endl;
//             std::cout << (*it).user << std::endl;
//         }

//     }
//         // Test 4.2
//     {
//         std::vector<std::string> testVector;
//         testVector.push_back("#wedogreat");
//         testVector.push_back("+oeia");
//         // testVector.push_back("");
//         testVector.push_back("-oavk");
//         testVector.push_back("buszbaaszas");

//         std::vector<parsedMode> testMode = Helper::collectModes(testVector);

//         std::cout << "Test 4.2: " << std::endl;

//         for (std::vector<parsedMode>::iterator it = testMode.begin(); it < testMode.end(); ++it) {
//             std::cout << "called" << std::endl;
//             std::cout << (*it).channel << std::endl;
//             std::cout << (*it).modes << std::endl;
//             std::cout << (*it).user << std::endl;
//         }

//     }
// }