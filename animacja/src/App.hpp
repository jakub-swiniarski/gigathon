#ifndef APP_HPP
#define APP_HPP

namespace ani {
    class App {
        void        run(void);
        static void quit(int signum);

    public:
        App(void);
    };
}

#endif // APP_HPP
