//
// Created by 10Pis on 2025/3/24.
//

#ifndef KIRBY_HPP
#define KIRBY_HPP

#include "AnimationObject.hpp"

enum Action{
    Idle,
    Walking,
    Running,
    Down,
    Jump,
    Slide
 };

class m_kirby final : public AnimationObject {
public:
    m_kirby() : AnimationObject(4,RESOURCE_DIR"/image/Kirby/commit_kirby/Idle/idle_", 1) {};

    void SetCurrentState(Action state);

    void SetCharacterSize(glm::vec2 size);

    Action GetCurrentState();

    std::shared_ptr<AnimationObject> GetCurrentAnimation();

    bool IfCollide(const std::shared_ptr<GameObject> &Object);

    //void Update() ;

private:
    std::shared_ptr<AnimationObject> Idle = std::make_shared<AnimationObject>(4,RESOURCE_DIR"/image/Kirby/commit_kirby/Idle/idle_", 1);
    std::shared_ptr<AnimationObject> Walking = std::make_shared<AnimationObject>(11,RESOURCE_DIR"/image/Kirby/commit_kirby/Walk/walk_", 1);
    std::shared_ptr<AnimationObject> Running = std::make_shared<AnimationObject>(8,RESOURCE_DIR"/image/Kirby/commit_kirby/Run/run_", 1);
    std::shared_ptr<AnimationObject> Down = std::make_shared<AnimationObject>(4,RESOURCE_DIR"/image/Kirby/commit_kirby/Down/down_", 1);
    std::shared_ptr<AnimationObject> Jump = std::make_shared<AnimationObject>(11,RESOURCE_DIR"/image/Kirby/commit_kirby/Jump/jump_", 1);
    std::shared_ptr<AnimationObject> Slide = std::make_shared<AnimationObject>(3,RESOURCE_DIR"/image/Kirby/commit_kirby/Slide/slide_", 1);

    Action CurrentState = Action::Idle;

};

#endif //KIRBY_HPP
