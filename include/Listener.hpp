#pragma once

#include <IListener.hpp>
#include <iostream>
#include <memory>

class Listener : public IListener {
public:
    Listener() = default;
    ~Listener() = default;

    void update(std::optional<void*>) override;
};