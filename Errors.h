/** @file
 * @brief Определяет классы исключений для обработки ошибок.
 * @version 1.0
 * @date 20.11.2024
 * @warning Это учебный пример
 */

#pragma once
#include <system_error>
#include <stdexcept>
#include <string>

/** @brief Представляет критическую ошибку.
 */
class crit_err: public std::runtime_error {
public:
    /**
     * @brief Конструктор для crit_err.
     * @param s Описание ошибки.
     */
	crit_err(const std::string& s): std::runtime_error(s) {}
};

/** @brief Представляет некритическую ошибку.
 */
class no_crit_err: public std::runtime_error {
public:
    /**
     * @brief Конструктор для no_crit_err.
     * @param s Описание ошибки.
     */
	no_crit_err(const std::string s): std::runtime_error(s) {}
};
