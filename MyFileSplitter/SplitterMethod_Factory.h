#include <string>
#include "Class_of_Method_Factory.h"



//具体基类及其构造工厂

class BinarySplitter : public ISplitMethod
{
public:
  virtual void Split ( std::string, int ){
    //......
  }
};
class BinarySplitterFactory: public SplitterFactory{
public:
    virtual ISplitMethod* CreateSplitter(){
        return new BinarySplitter();
    }
};



class TxtSplitter : public ISplitMethod
{
public:
  virtual void Split ( std::string, int ){
    //......
  }
};
class TxtSplitterFactory: public SplitterFactory{
public:
    virtual ISplitMethod* CreateSplitter(){
        return new TxtSplitter();
    }
};


class PictureSplitter : public ISplitMethod
{
public:
  virtual void Split ( std::string, int ){
    //......
  }
};
class PictureSplitterFactory: public SplitterFactory{
public:
    virtual ISplitMethod* CreateSplitter(){
        return new PictureSplitter();
    }
};