#include <Analytics.hpp>
#include <iostream>
#include <memory>
#include <optional>
#include <list>

Analytics::Analytics()
{
}

Analytics::~Analytics()
{
}

void Analytics::dispatch(const std::string& event, std::optional<void*> parameters){
    for (auto listener = m_listeners[event].begin(); listener != m_listeners[event].end();){
        if (listener->expired()){
            m_listeners[event].erase(listener);
            continue;
        }
        listener->lock()->update(event, parameters);
        listener++;
    }
}

void Analytics::subscribe(std::weak_ptr<IListener> listener, const std::string &event){
    if (m_listeners[event].empty()) {
        m_listeners[event] = std::vector<std::weak_ptr<IListener>>();
    }
    m_listeners[event].push_back(listener);
}
