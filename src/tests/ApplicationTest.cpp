#include "ApplicationTest.hpp"
#include "../utils/test-tools.hpp" // because of weird Clion bug
#include "../utils/test-tools.hpp"


void AppicationTestCase::main_test() {
    static Application app = Singleton<Application>::Instance();
    app.create_window("TestWindow", 100, 100, 100, 100, true, SDL_WINDOW_HIDDEN, SDL_RENDERER_ACCELERATED);
    app.create_window("TestWindow2", 800, 400, 100, 100, true, SDL_WINDOW_HIDDEN, SDL_RENDERER_ACCELERATED);
    details(app);
    assertion_test(app);

}

void AppicationTestCase::details(Application app) {
    std::cout << "Application Test Details" << std::endl;
    std::cout << "Windows count: " << app.get_windows().size() << std::endl;
}

void AppicationTestCase::assertion_test(Application app) {
    ASSERT(!app.is_running(), "Application m_running flag initilized with wrong flag");
    app.start();
    ASSERT(app.is_running(), "Application m_running flag wrong value after start");
    app.stop();
    ASSERT(!app.is_running(), "Application m_running flag wrong value after stop");
    app.show();
    SDL_Delay(1000);
    for (auto win: app.get_windows()) {
        ASSERT(win.second->is_visible(), "Checking windows visibility");
    }
    app.hide();
    for (auto win: app.get_windows()) {
        ASSERT(!win.second->is_visible(), "Checking windows visibility");
    }
    ASSERT(app.get_window("TestWindow") != nullptr, "Failed getting Window instance.");
    app.show();
    int x = 100;
    int y = 100;
    SDL_Point p1 = {500,400};
    SDL_Point p2 = {1000,800};
    for (int i = 0 ; i < 200 ; i++) {
        x++;
        y++;
        app.get_window("TestWindow")->set_x_position(x);
        app.get_window("TestWindow")->set_y_position(y);
        app.get_window("TestWindow")->set_width(x);
        app.get_window("TestWindow")->set_height(y);
        p2.x--;
        p2.y--;
        app.get_window("TestWindow2")->set_position(&p1);
        app.get_window("TestWindow2")->set_size(&p1, &p2);
        app.pause(10);
    }
    app.hide();
    app.pause(500);
    app.show();
    app.pause(500);
}
