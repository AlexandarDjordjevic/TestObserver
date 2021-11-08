#include <Analytics.hpp>
#include <Listener.hpp>
#include <memory>
#include <optional>

int main(){
    Analytics analytic;
    auto listener_1{std::make_shared<Listener>()};
    analytic.subscribe("stop", listener_1);
    {
        auto listener_2{std::make_shared<Listener>()};
        analytic.subscribe("stop", listener_2);

        auto parameters{"This is stop event message"};

        analytic.dispatch("stop", reinterpret_cast<void*>(const_cast<char*>(parameters)));
        analytic.subscribe("play", listener_2);
    }
    analytic.dispatch("play");

    return 0;
}