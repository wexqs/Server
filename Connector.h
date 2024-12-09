/** @file
 * @brief Объявление класса Connector для управления подключениями к базе данных.
 * @version 1.0
 * @date 20.11.2024
 * @warning Это учебный пример
 */

#pragma once
#include <map>
#include <string>
#include "Errors.h"

/** @brief Управляет подключениями к базе данных.
 * @details Загружает данные пользователей из файла и хранит их в словаре.
 */
class Logger;

class Connector {
private:
    std::map<std::string, std::string> data_base; /**< Словарь для хранения данных базы */

public:
    /**
     * @brief Подключается к базе данных.
     * @param base_file Путь к файлу базы данных.
     * @return int Код состояния.
     */
    int connect(std::string base_file = "/etc/vcalc.conf", Logger* logger = nullptr);

    /**
     * @brief Получает данные из базы данных.
     * @return std::map<std::string, std::string> Словарь записей в базе данных.
     */
    std::map<std::string, std::string> get_data();
};
