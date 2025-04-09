#include "App.hpp"

#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "StillObject.hpp"
#include "iostream"

void App::MENU() {
    LOG_TRACE("MENU");
    m_Background = std::make_shared<StillObject> (RESOURCE_DIR "/image/Background/Menu/frame_0000.png");
    m_Background->SetPosition({0,0});
    m_Background->SetZIndex(49);
    m_Background->SetSize({1.6,1.2});
    m_renderer = std::make_shared<Util::Renderer>();
    m_renderer->AddChild(m_Background);


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
