//
// Created by 10Pis on 2025/3/27.
//

#ifndef LEVEL1_HPP
#define LEVEL1_HPP

#include "SceneManager.hpp"

class Level1 : public SceneManager{
public:
    Level1() {
        m_Background = std::make_shared<StillObject>(RESOURCE_DIR "/image/Background/Level_1.png");
        m_Background->SetSize({2.8,3.3});
    };
    void condition() override {
        switch (Condition_num) {

        }
    }

};

#endif //LEVEL1_HPP

