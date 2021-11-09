#include <Listener.hpp>
#include <iostream>
#include <memory>
#include <optional>

void Listener::update(const std::string& event, std::optional<void*> parameters) {
    std::cout << "Listener received: " << event << ".";
    if (parameters.has_value()){
        std::cout << " Parameters: " << (char*)parameters.value();
    }
    std::cout << std::endl;
}