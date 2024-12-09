#include "Logger.h"
#include "Errors.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <ctime>

Logger::Logger(std::string s) : path_to_logfile(s) {}
Logger::Logger() : path_to_logfile("") {}

int Logger::set_path(std::string path_file) {
    if (path_file.find('.') == std::string::npos) {
        throw std::invalid_argument("file without extension");
    }
    std::ofstream filelog(path_file, std::ios_base::out | std::ios_base::app);
    if (!filelog.is_open()) {
        throw crit_err("path to log not exist");
    }
    path_to_logfile = path_file;
    return 0;
}

std::string Logger::getCurrentDateTime(std::string s) {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    if (s == "now") {
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    } else if (s == "date") {
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    }
    return std::string(buf);
}

int Logger::writelog(std::string s) {
    std::ofstream filelog(path_to_logfile, std::ios_base::out | std::ios_base::app);

    // Если не удалось открыть лог-файл в указанном месте, пробуем использовать резервный путь
    if (!filelog.is_open()) {
        std::cerr << "Ошибка: не удалось создать лог в " << path_to_logfile
                  << ". Переключение на /tmp/log/vcalc.log" << std::endl;
        path_to_logfile = "/tmp/log/vcalc.log";
        filelog.open(path_to_logfile, std::ios_base::out | std::ios_base::app);

        // Если резервный путь также не удается открыть, бросаем исключение
        if (!filelog.is_open()) {
            throw crit_err("Не удалось создать лог-файл: " + path_to_logfile);
        }
    }

    std::string time = getCurrentDateTime("now");
    filelog << time << ' ' << s << std::endl;
    return 0;
}
