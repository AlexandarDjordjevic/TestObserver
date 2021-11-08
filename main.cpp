#include <Analytics.hpp>
#include <Listener.hpp>
#include <memory>
#include <optional>

int main(){
    Analytics analytic;
    {
        auto listener{std::make_shared<Listener>()};
        analytic.subscribe("stop", listener);

        auto parameters{"This is stop event message"};

        analytic.dispatch("stop", reinterpret_cast<void*>(const_cast<char*>(parameters)));
        analytic.subscribe("play", listener);
    }
    analytic.dispatch("play");

    return 0;
}