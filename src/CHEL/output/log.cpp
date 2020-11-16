#include "log.h"

namespace JS::Output {
    void Log::Push(std::string message, JS::Output::LogType logType, int line) {
        Message m = Message(message, logType, line);

        this->messages.push_back(m);
    }

    json Log::ToJson() {
        json list = json::array();

        for (Message message : messages) {
            json single = {
                    {"message", message.message},
                    {"type", GetStringLogType(message.type)}
            };

            if (message.type == LogType::ERROR) {
                single["line"] = message.line;
            }

            list.push_back(single);
        }

        return list;
    }
}