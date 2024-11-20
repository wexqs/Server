/** @file
 * @brief Объявление класса Calculator для векторных вычислений.
 * @version 1.0
 * @date 20.11.2024
 * @warning Это учебный пример
 */

#pragma once
#include <vector>
#include <cstdint>

/** @brief Выполняет вычисления на векторе целых чисел.
 * @details Обрабатывает массив целых чисел и вычисляет произведение.
 */
class Calculator {
    uint16_t results; /**< Результат вычисления */

public:
    /**
     * @brief Конструктор, инициализирующий вычисления с входными данными.
     * @param input_data Вектор целых чисел для вычисления.
     */
    Calculator(std::vector<uint16_t> input_data);
    
    /**
     * @brief Возвращает результат вычисления.
     * @return uint16_t Результат вычисления.
     */
    uint16_t send_res();
};
