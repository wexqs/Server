#include "Connector.h"
#include "Logger.h"
#include "Errors.h"

#include <fstream>
#include <stdexcept>
#include <string>

int Connector::connect(std::string base_file, Logger* logger)
{
    std::ifstream file_read(base_file);
    if (!file_read.is_open()) {
        if (logger) {
            logger->writelog("Ошибка: файл базы данных не найден: " + base_file);
        }
        throw crit_err("invalid_base_path");
    }

    std::string line;
    while (getline(file_read, line)) {
        if (line.empty()) continue;

        std::string temp_login;
        std::string temp_pass;
        bool flag = true;
        
        for (char s : line) {
            if (s == ':') {
                flag = false;
                continue;
            }
            if (flag) {
                temp_login.push_back(s);
            } else {
                temp_pass.push_back(s);
            }
        }

        if (temp_login.empty() || temp_pass.empty()) {
            if (logger) {
                logger->writelog("Ошибка: в строке отсутствует логин или пароль: " + line);
            }
        } else {
            data_base[temp_login] = temp_pass;
        }
    }
    
    if (data_base.empty()) {
        if (logger) {
            logger->writelog("Ошибка: файл базы данных пустой: " + base_file);
        }
        throw crit_err("invalid_base_path");
    }

    if (logger) {
        logger->writelog("Успешное подключение к базе данных: " + base_file);
    }
    return 0;
}

std::map<std::string, std::string> Connector::get_data()
{
    return data_base;
}
