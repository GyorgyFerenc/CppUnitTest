#include <assert.h>

#include <functional>
#include <iostream>
#include <vector>

class UnitTester {
   protected:
    std::vector<std::function<void()>> functionList;
    std::vector<std::string>           functionDescriptions;

    void AddTestFunction(std::string Description, std::function<void()> func) {
        this->functionList.push_back(func);
        this->functionDescriptions.push_back(Description);
    }

   public:
    virtual void Before(){};
    virtual void After(){};

    void RunAll() {
        for (size_t i = 0; i < this->functionList.size(); i++) {
            std::cout << functionDescriptions[i] << std::endl;
            this->Before();
            functionList[i]();
            this->After();
        }
    }
};
