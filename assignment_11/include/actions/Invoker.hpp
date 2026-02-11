#ifndef INVOKER_HPP
#define INVOKER_HPP

#include "actions/Command.hpp"
#include <deque>
#include "grid/GridAdapter.hpp"
#include "common/Subscriber.hpp"

class Invoker : Subscriber
{
private:
    Invoker();
    inline static Invoker * invoker = nullptr;
    std::deque< Command * > actionList;
    GridAdapter * gridAdapter;
public:
    ~Invoker();
    static Invoker * GetInvoker();
    void Input();
    void Notification() override;
};

#endif
