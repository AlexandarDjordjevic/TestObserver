#include <unordered_map>
#include <vector>
#include <memory>
#include <optional>
#include <list>
#include <IListener.hpp>

class Analytics
{
public:
    Analytics();
    Analytics(Analytics &&) = default;
    Analytics(const Analytics &) = default;
    Analytics &operator=(Analytics &&) = default;
    Analytics &operator=(const Analytics &) = default;
    ~Analytics();

    void dispatch(const std::string& event, std::optional<void*> parameters = std::nullopt);

    void subscribe(std::weak_ptr<IListener> listener, const std::string& event);
private:
    std::unordered_map<std::string, std::vector<std::weak_ptr<IListener>>> m_listeners;
};

