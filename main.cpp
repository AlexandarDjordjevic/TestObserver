#include <Analytics.hpp>
#include <Listener.hpp>
#include <memory>
#include <optional>

using namespace std::string_literals;

int main(){
    Analytics analytic;
    auto listener_1{std::make_shared<Listener>()};
    analytic.subscribe(listener_1, {"stop"});
    analytic.subscribe(listener_1, {"play"});
    analytic.subscribe(listener_1, {"pause"});
    {
        auto listener_2{std::make_shared<Listener>()};
        analytic.subscribe(listener_2, {"stop"});

        auto parameters{"This is the event message"};

        analytic.dispatch("stop", reinterpret_cast<void*>(const_cast<char*>(parameters)));
        analytic.subscribe(listener_2, "play");
    }
    analytic.dispatch("play");
    analytic.dispatch("pause");

    return 0;
}