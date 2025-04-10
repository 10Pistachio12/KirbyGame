//
// Created by benson on 2025/3/14.
//

#ifndef LEVEL_HPP
#define LEVEL_HPP
#include "StillObject.hpp"
#include "Enemy.hpp"
#include "SceneObject.hpp"
#include "Kirby.hpp"
#include "Util/Input.hpp"
#include "Util/Renderer.hpp"
#include <iostream>

class SceneManager{
public:
    virtual ~SceneManager() = default;

    void SetBackGround(std::shared_ptr<StillObject> Background);
    void SetSceneObject(std::shared_ptr<SceneObject> SceneObject);
    virtual void condition() = 0;
    void Start() {
        m_kirby->SetPosition({-500,-200});
        m_kirby->SetCurrentState(Action::Idle);
        m_kirby->SetZIndex(60);
        m_kirby->SetSize({2,2});
        m_Background->SetPosition({0,0});
        m_renderer->AddChild(m_Background);
        m_renderer->AddChild(m_kirby);
    }
    void update() {
        if (Util::Input::IsKeyPressed(Util::Keycode::SPACE)) {
            std::cout<<m_kirby->GetPosition().x<<" "<<m_kirby->GetPosition().y<<std::endl;
        }
        if(Util::Input::IsKeyPressed(Util::Keycode::D)) {
            if (m_kirby->GetPosition().x >= 0) {
                m_Background->SetPosition({m_Background->GetPosition().x - 4,m_Background->GetPosition().y});
                for(const auto &enemy : Enemies) {
                    enemy->SetPosition({enemy->GetPosition().x - 4,enemy->GetPosition().y});
                }
            }
            else {
                m_kirby->SetPosition({m_kirby->GetPosition().x + 4,m_kirby->GetPosition().y});
            }
            m_kirby->SetSize({2,2});
            m_kirby->SetCurrentState(Action::Running);
    }


        if(Util::Input::IsKeyPressed(Util::Keycode::A)) {
            if(m_kirby->GetPosition().x - 1 <= -620) {
                m_kirby->SetPosition({-620,m_kirby->GetPosition().y});
            }
            m_kirby->SetPosition({m_kirby->GetPosition().x - 4,m_kirby->GetPosition().y});
            m_kirby->SetSize({-2,2});
            m_kirby->SetCurrentState(Action::Running);
        }

        if(Util::Input::IsKeyPressed(Util::Keycode::S)) {
            m_kirby->SetCurrentState(Action::Down);
        }

        if(Util::Input::IsKeyPressed(Util::Keycode::W)) {
            m_kirby->SetCurrentState(Action::Jump);
            m_kirby->SetPosition({m_kirby->GetPosition().x,m_kirby->GetPosition().y + 1});
        }


        if(!Util::Input::IsKeyPressed(Util::Keycode::S) &&
            !Util::Input::IsKeyPressed(Util::Keycode::W) &&
            !Util::Input::IsKeyPressed(Util::Keycode::A) &&
            !Util::Input::IsKeyPressed(Util::Keycode::D)) {
            m_kirby->SetCurrentState(Action::Idle);
            }
        for (const auto& enemy : Enemies) {
            enemy->Action();
        }
        this->condition();
        m_renderer->Update();

    }


protected:
    std::shared_ptr<Util::Renderer> m_renderer = std::make_shared<Util::Renderer>();
    std::shared_ptr<m_kirby> m_kirby = std::make_shared<class m_kirby>();
    std::shared_ptr<StillObject> m_Background;
    std::vector<std::shared_ptr<Enemy>> Enemies;
    std::shared_ptr<SceneObject> SceneObject;
    size_t Condition_num = 1;
    int moveDistance = 0;
};
#endif //LEVEL_HPP
