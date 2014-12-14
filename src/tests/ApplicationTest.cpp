#include "ApplicationTest.hpp"
#include "../utils/test-tools.hpp"
#include "../utils/test-tools.hpp"


void AppicationTestCase::main_test() {
    Application app = Singleton<Application>::Instance();
    app.create_window("TestWindow", 100, 100, 100, 100, true, SDL_WINDOW_HIDDEN, SDL_RENDERER_ACCELERATED);
    app.create_window("TestWindow2", 200, 200, 100, 100, true, SDL_WINDOW_HIDDEN, SDL_RENDERER_ACCELERATED);
    details(app);
    assertion_test(app);
}

void AppicationTestCase::details(Application app) {

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
}
