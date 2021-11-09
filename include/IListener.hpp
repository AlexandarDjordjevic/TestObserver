#pragma once
#include <memory>
#include <optional>

class IListener {
public:
    virtual void update(const std::string& event, std::optional<void*>) = 0;
};