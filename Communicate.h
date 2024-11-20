/** @file
 * @brief Объявление класса Communicate для серверного обмена данными.
 * @version 1.0
 * @date 20.11.2024
 * @warning Это учебный пример
 */

#pragma once
#include <string>
#include <map>

class Logger;

/** @brief Обрабатывает обмен данными между сервером и клиентом.
 */
class Communicate {
public:
    /**
     * @brief Устанавливает соединение с клиентом.
     * @param port Порт сервера.
     * @param database База данных с учетными данными пользователей.
     * @param l1 Экземпляр Logger для ведения журнала.
     * @return int Код состояния.
     */
    int connection(int port, std::map<std::string, std::string> database, Logger* l1);

    /**
     * @brief Вычисляет SHA256-хэш строки.
     * @param input_str Входная строка.
     * @return std::string SHA256-хэш входной строки.
     */
    static std::string sha256(std::string input_str);

    /**
     * @brief Генерирует случайный соль.
     * @return std::string Сгенерированная соль в шестнадцатеричном формате.
     */
    static std::string generate_salt();
};
