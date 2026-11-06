#ifndef WCH_MISSIONS_IMISSION_CONDITION_H
#define WCH_MISSIONS_IMISSION_CONDITION_H

class IMissionCondition {
public:
    virtual ~IMissionCondition();
    virtual bool evaluate(int elapsed) = 0;
    virtual void draw() = 0;
    virtual int cause() const;
};

#endif
