/** @file
 * @brief Объявление класса Logger для ведения логов.
 * @author Удалов В.В.
 * @version 1.0
 * @date 20.11.2024
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 */

#pragma once
#include <string>

/** @brief Класс для обработки записи логов.
 * @details Позволяет записывать и управлять файлами логов.
 */
class Logger {
    /**
     * @brief Получает текущую дату и время в виде строки.
     * @param s Строка, указывающая формат (например, "now" или "date").
     * @return std::string Форматированная строка текущей даты/времени.
     */
    static std::string getCurrentDateTime(std::string s);

    std::string path_to_logfile; /**< Путь к файлу лога */

public:
    /**
     * @brief Записывает строку в лог.
     * @param s Строка для записи.
     * @return int Код состояния.
     */
    int writelog(std::string s);

    /**
     * @brief Устанавливает путь к файлу лога.
     * @param path_file Путь к файлу лога.
     * @return int Код состояния.
     */
    int set_path(std::string path_file);

    /**
     * @brief Конструктор по умолчанию.
     */
    Logger();
    
    /**
     * @brief Конструктор с указанием пути к файлу.
     * @param s Путь к файлу лога.
     */
    Logger(std::string s);
};
