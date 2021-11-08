#include <Analytics.hpp>
#include <iostream>
#include <memory>
#include <optional>

Analytics::Analytics()
{
}

Analytics::~Analytics()
{
}

void Analytics::dispatch(const std::string &event, std::optional<void*> parameters){
    for (auto listener = m_listeners[event].begin(); listener != m_listeners[event].end(); ++listener){
        if (listener->expired()){
            m_listeners[event].erase(listener);
            if (!m_listeners[event].size()){
                break;
            }
            continue;
        }
        listener->lock()->update(parameters);
    }
    std::cout << "Event " << event << " dispatched" << std::endl;
}

void Analytics::subscribe(const std::string &event, std::weak_ptr<IListener> listener){
    if (m_listeners[event].empty()) {
        m_listeners[event] = std::vector<std::weak_ptr<IListener>>();
    }
    m_listeners[event].push_back(listener);
}