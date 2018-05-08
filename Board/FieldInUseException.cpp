#include <iostream>
#include <sstream>

using std::runtime_error;
using std::ostringstream;
using std::endl;

class FieldInUseException : public runtime_error {
private:
    int x_m;
    int y_m;
public:
    FieldInUseException(int x, int y) : runtime_error("Field already in use error"), x_m(x), y_m(y) {}

    virtual const char *what() const throw() {
        ostringstream res("");

        res << runtime_error::what() << ": coordinates(" << getX_m() << ", " << getY_m() << ")" << endl;

        return res.str().c_str();
    }

    int getX_m() const {
        return x_m;
    }

    int getY_m() const {
        return y_m;
    }
};
