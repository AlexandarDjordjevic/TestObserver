#pragma once
#include <memory>
#include <optional>

class IListener {
public:
    virtual void update(std::optional<void*>) = 0;
};