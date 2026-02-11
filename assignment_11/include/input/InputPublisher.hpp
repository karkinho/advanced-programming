#ifndef INPUTPUBLISHER_HPP
#define INPUTPUBLISHER_HPP

#include "common/Subscriber.hpp"
#include <vector>
#include "Settings.hpp"
#include "common/Subscriber.hpp"
#include "grid/GridAdapter.hpp"

class InputPublisher
{
private:
    std::vector< Subscriber * > subscribers;
    InputPublisher();
    inline static InputPublisher * inputPublisher = nullptr;
    INPUT input;
    GridAdapter * gridAdapter;
    void Notify();
    double ticks = 0;
public:
    ~InputPublisher();
    static InputPublisher * GetInputPublisher();
    INPUT GetInput();
    void Input();
    void AddSubscriber( Subscriber * subscriber );
};

#endif