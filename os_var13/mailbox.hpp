#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class Mailbox {
public:
    Mailbox(size_t _maxSize = 2) : maxSize(_maxSize) {}
    ~Mailbox() = default;
    void send(const T &mes) {
        std::unique_lock<std::mutex> lock(mutexMail);
        conditionSend.wait(lock, [this]() {
            return messages.size() < maxSize;
                              });
        messages.push(mes);
        conditionReceive.notify_one();
    }
    T receive() {
        std::unique_lock<std::mutex> lock(mutexMail);
        conditionReceive.wait(lock, [this]() {
            return !messages.empty(); 
                           });
        T message = messages.front();
        messages.pop();
        conditionSend.notify_one();
        return message;
    }
private:
    std::queue<T> messages;
    std::mutex mutexMail;
    std::condition_variable conditionReceive;
    std::condition_variable conditionSend;
    size_t maxSize = 0;
};
