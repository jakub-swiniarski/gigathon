#ifndef APP_HPP
#define APP_HPP

namespace ani {
    class App {
        bool is_running = false;

        void run(void);
        void quit(void);

    public:
        App(void);
    };
}

#endif // APP_HPP
