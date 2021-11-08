#include <Listener.hpp>
#include <memory>
#include <optional>

void Listener::update(std::optional<void*> parameters) {
    if (parameters.has_value()){
        std::cout << "Parameters: " << (char*)parameters.value() << std::endl;
    }
    std::cout << "Listener received update!" << std::endl;
}