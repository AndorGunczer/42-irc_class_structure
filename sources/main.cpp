/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:57:09 by slippert          #+#    #+#             */
/*   Updated: 2024/04/02 12:30:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Command.hpp"

int main() {
    // test 1: Command Class
    {
    
        // std::string userInput = "JOIN #wedogreat +o 12345";

        // Command newCommand = Command(userInput);
    }
    // test 2: Helper::splitStringOnComma()
    {
        // std::string const &multipleChannels = "#wedogreat";
        // std::vector<std::string> channels = Helper::splitStringOnComma(multipleChannels);

        // for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); ++it){
        //     std::cout << *it << std::endl;
        // }
    }
    // test 3: Join Class
    {
        // Command testClassCommand("JOIN #wedogreat,#foo,&bar 12345,thisissuper");
        // Join testClass("JOIN #wedogreat,#foo,&bar 12345,thisissuper");

        // for (std::vector<std::string>::iterator it = testClass.channelsToJoin.begin(); it != testClass.channelsToJoin.end(); ++it){
        //     std::cout << *it << std::endl;
        // }

        // for (std::vector<std::string>::iterator it = testClass.passwordStore.begin(); it != testClass.passwordStore.end(); ++it){
        //     std::cout << *it << std::endl;
        // }
    }
    // test 4: Mode Parsing
        // Test 4.1
    {
        std::vector<std::string> testVector;
        testVector.push_back("#wedogreat");
        testVector.push_back("+oeia");
        testVector.push_back("spiritusz");
        testVector.push_back("-oavk");
        testVector.push_back("buszbaaszas");

        std::vector<parsedMode> testMode = Helper::collectModes(testVector);

        for (std::vector<parsedMode>::iterator it = testMode.begin(); it < testMode.end(); ++it) {
            std::cout << (*it).channel << std::endl;
            std::cout << (*it).modes << std::endl;
            std::cout << (*it).user << std::endl;
        }

    }
        // Test 4.2
    {
        std::vector<std::string> testVector;
        testVector.push_back("#wedogreat");
        testVector.push_back("+oeia");
        // testVector.push_back("");
        testVector.push_back("-oavk");
        testVector.push_back("buszbaaszas");

        std::vector<parsedMode> testMode = Helper::collectModes(testVector);

        std::cout << "Test 4.2: " << std::endl;

        for (std::vector<parsedMode>::iterator it = testMode.begin(); it < testMode.end(); ++it) {
            std::cout << "called" << std::endl;
            std::cout << (*it).channel << std::endl;
            std::cout << (*it).modes << std::endl;
            std::cout << (*it).user << std::endl;
        }

    }
}