#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include <string>

namespace ani {
    class UserInterface {
    public:
        std::string input_filename(void) const;
    };
}

#endif // USERINTERFACE_HPP