#include <stdexcept>

class Errors :public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class playerErrors :public Errors{
private:

public:
    explicit playerErrors(std::string& mesaj);
};

class fireErrors : public Errors{
private:

public:
    explicit fireErrors(std::string& mesaj);
};

