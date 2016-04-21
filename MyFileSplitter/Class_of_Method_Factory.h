#include <iostream>

class ISplitMethod{
public:
    virtual void Split(std::string, int)=0;
    virtual ~ISplitMethod(){}
};


class SplitterFactory{
public:
    virtual ISplitMethod* CreateSplitter()=0;
    virtual ~SplitterFactory(){}
};
