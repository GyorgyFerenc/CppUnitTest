#include <assert.h>

#include <functional>
#include <iostream>
#include <vector>

class UnitTest {
   private:
    std::vector<std::function<void()>> functionList;
    std::vector<std::string>           functionDescriptions;
    std::string                        Title = "Title Placeholder";

   protected:
    void AddTestFunction(std::string Description, std::function<void()> func) {
        this->functionList.push_back(func);
        this->functionDescriptions.push_back(Description);
    }

    void SetTitle(const std::string Title) {
        this->Title = Title;
    }

    virtual void Before(){};
    virtual void After(){};

   public:
    void RunAll() {
        std::cout << "Running tests for " << this->Title << ":" << std::endl;

        for (size_t i = 0; i < this->functionList.size(); i++) {
            std::cout << "\t" << functionDescriptions[i];
            this->Before();
            functionList[i]();
            this->After();
            std::cout << " -> Passed" << std::endl;
        }
    }
};
