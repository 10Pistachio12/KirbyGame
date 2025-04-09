#ifndef APP_HPP
#define APP_HPP

#include "All_Include.hpp"
#include "AnimationObject.hpp"

namespace Util::Logger {
    enum class Level;
}

class App {
public:
    enum class State {
        MENU,
        MenuUpdate,
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void MENU();

    void MenuUpdate();

    void Start();

    void Update();

    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    void ValidTask();

    std::shared_ptr<AnimationObject> m_AnimatedBackground;
    std::shared_ptr<SceneManager> m_SceneManager ;
    std::shared_ptr <Util::Renderer> m_renderer;
    std::shared_ptr<SceneManager> m_level;


    State m_CurrentState = State::MENU;
    size_t level = 1;

};

#endif
