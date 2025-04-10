#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "StillObject.hpp"
#include "iostream"

void App::MENU() {
    LOG_TRACE("MENU");
    m_renderer = std::make_shared<Util::Renderer>();
    m_AnimatedBackground = std::make_shared<AnimationObject>(210, RESOURCE_DIR "/image/Background/Menu/frame_", 4);
    m_AnimatedBackground->SetPosition({0,0});
    m_AnimatedBackground->SetZIndex(60);
    m_AnimatedBackground->SetSize({0.65,0.65});

    m_renderer->AddChild(m_AnimatedBackground);

    m_CurrentState = State::MenuUpdate;
}

void App::MenuUpdate() {
    LOG_TRACE("MenuUpdate");
    if (Util::Input::IsKeyPressed(Util::Keycode::KP_ENTER)|| Util::Input::IsKeyPressed(Util::Keycode::RETURN)) {
        m_CurrentState = State::START;
    }
    m_renderer->Update();
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
        }
}

void App::Start() {
    LOG_TRACE("Start");
    switch(level) {
            case 1:
                m_SceneManager = std::make_shared<Level1>();
                break;
            case 2:
                m_SceneManager = std::make_shared<Level2>();
                break;
            case 3:
                m_SceneManager = std::make_shared<Level3>();
                break;
    }
    m_SceneManager->Start();
    m_CurrentState = State::UPDATE;
}

void App::Update() {
    m_SceneManager->update();
    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    if (Util::Input::IsKeyUp(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
