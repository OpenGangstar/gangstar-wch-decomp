#ifndef WCH_AI_STATE_MACHINE_H
#define WCH_AI_STATE_MACHINE_H

#include "../core/FrameInterfaces.h"
#include "../core/StateBase.h"
#include "../core/PlacementNew.h"

struct StateStackPrefix;
// Native STLport storage helpers; their implementations remain external.
extern "C" void _ZN9stlp_priv12_Vector_baseIP9StateBaseSaIS2_EED1Ev(StateStackPrefix*) __attribute__((weak));
// Empty tag selecting the native pointer-copy specialization.
struct StatePointerCopyTag {};
extern "C" void _ZNSt6vectorIP9StateBaseSaIS1_EE18_M_insert_overflowEPS1_RKS1_RKSt11__true_typejb(
    StateStackPrefix*, StateBase**, StateBase* const&, const StatePointerCopyTag&,
    unsigned int, bool) __attribute__((weak));

// Observed STLport vector pointer triple, with cleanup delegated to its native base.
struct StateStackPrefix {
    StateBase** first;
    StateBase** last;
    StateBase** limit;
    StateStackPrefix() : first(0), last(0), limit(0) {}
    ~StateStackPrefix() { _ZN9stlp_priv12_Vector_baseIP9StateBaseSaIS2_EED1Ev(this); }
    unsigned int size() const { return last - first; }
    StateBase* back() const { return last[-1]; }
    void push_back(StateBase* const& value)
    {
        if (last != limit) {
            new (last) StateBase*(value);
            ++last;
        } else {
            _ZNSt6vectorIP9StateBaseSaIS1_EE18_M_insert_overflowEPS1_RKS1_RKSt11__true_typejb(
                this, last, value, StatePointerCopyTag(), 1, true);
        }
    }
};

class StateMachine : public IUpdatable, public IDrawable, public ISleepable {
public:
    StateMachine();
    static StateMachine* __attribute__((used)) getInstance()
    {
        static StateMachine sm;
        return &sm;
    }
    virtual ~StateMachine();
    virtual void update(double timestamp);
    virtual void draw() const;
    virtual void draw2d() const;
    virtual int getDrawingLayer() const;
    virtual void sleep();
    virtual void wakeup();
    void _trace(const char*) const;
    double getTimeStamp() const;
    bool hasStates() const { return states.size() != 0; }
    bool isDrawable();
    void recurseDraw() const;
    void popState();
    void _pushState(StateBase* value);
    void _switchState(StateBase* value);
    template<class T> T* pushState()
    {
        T* value = new T;
        _pushState(value);
        return value;
    }
    template<class T> T* switchState()
    {
        T* value = new T;
        _switchState(value);
        return value;
    }
private:
    friend class Application;
    StateStackPrefix states;
    double timestamp;
    mutable int drawIndex;
    mutable bool drawing;
};

#endif
