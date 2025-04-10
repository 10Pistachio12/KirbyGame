//
// Created by 10Pis on 2025/3/27.
//

#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include "SceneManager.hpp"

class Level1 : public SceneManager{
public:
    Level1() {
        m_renderer = std::make_shared<Util::Renderer>();
        m_Background = std::make_shared<StillObject>(RESOURCE_DIR "/image/Background/Level_1.png");
        m_Background->SetSize({1.4,1.4});
        m_Background->SetPosition({0,0});
        m_Background->SetZIndex(20);
        m_renderer->AddChild(m_Background);
    };
    void condition() override {
        switch (Condition_num) {

        }
    }

};

#endif //LEVEL1_HPP

