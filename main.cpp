/** @file
 * @author Удалов В.В.
 * @version 1.0
 * @date 20.11.2024
 * @copyright ИБСТ ПГУ
 * @warning Это учебный пример
 * @brief Главная точка входа для приложения.
 */

#include <iostream>
#include "Connector.h"
#include "Interface.h"
#include "Communicate.h"
#include "Calculator.h"
#include "Errors.h"
#include "Logger.h"

/**
 * @brief Главная функция для инициализации интерфейса и запуска процесса обмена сообщениями.
 * @param argc Количество аргументов командной строки.
 * @param argv Массив аргументов командной строки.
 * @return int Код завершения программы.
 */
int main(int argc, const char** argv) {
    Interface UI;
    UI.comm_proc(argc, argv);
    return 0;
}
