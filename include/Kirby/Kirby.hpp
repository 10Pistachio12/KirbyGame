//
// Created by 10Pis on 2025/3/24.
//

#ifndef KIRBY_HPP
#define KIRBY_HPP

#include "AnimationObject.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Core/Context.hpp"

enum class Action {
    Idle,
    Walking,
    Running,
    Down,
    Jump,
    //Slide,
    //Drop,
    //Celebrate
};

enum class Direction {
    Left,
    Right
};

class m_kirby final : public AnimationObject {
public:
    m_kirby()
        : AnimationObject(4, RESOURCE_DIR"/image/Kirby/original_Kirby/Idle/idle_", 1),
          CurrentState(Action::Idle),
          Facing(Direction::Right),
          walkSpeed(0.05f),
          runSpeed(0.1f),
          slideSpeed(0.13f),
          jumpHeight(0.15f),
          doubleTapTimer(0),
          waitingSecondTap(false),
          lastKeyPressed(Util::Keycode::UNKNOWN) {}

    void SetCurrentState(Action state);

    Action GetCurrentState();

    Action GetCurrentState() const;

    void SetCharacterSize(glm::vec2 size);
    std::shared_ptr<AnimationObject> GetCurrentAnimation();

    bool IfCollide(const std::shared_ptr<GameObject>& Object);

    //void Update();

private:
    std::shared_ptr<AnimationObject> Idle = std::make_shared<AnimationObject>(4, RESOURCE_DIR"/image/Kirby/original_Kirby/Idle/idle_", 1);
    std::shared_ptr<AnimationObject> Walking = std::make_shared<AnimationObject>(9, RESOURCE_DIR"/image/Kirby/original_Kirby/Walk/walk_", 1);
    std::shared_ptr<AnimationObject> Running = std::make_shared<AnimationObject>(3, RESOURCE_DIR"/image/Kirby/original_Kirby/Run/run_", 1);
    std::shared_ptr<AnimationObject> Down = std::make_shared<AnimationObject>(3, RESOURCE_DIR"/image/Kirby/original_Kirby/Down/down_", 1);
    std::shared_ptr<AnimationObject> Jump = std::make_shared<AnimationObject>(2, RESOURCE_DIR"/image/Kirby/original_Kirby/Jump/jump_", 1);
    //std::shared_ptr<AnimationObject> Slide = std::make_shared<AnimationObject>(2, RESOURCE_DIR"/image/Kirby/Jump/jump_", 1);


    Action CurrentState;
    Direction Facing;

    float walkSpeed;
    float runSpeed;
    float slideSpeed;
    float jumpHeight;

    float doubleTapTimer;
    bool waitingSecondTap;
    Util::Keycode lastKeyPressed;

    void HandleMovement(float deltaTime);
    void HandleDoubleTap(float deltaTime, Util::Keycode key);
};



#endif //KIRBY_HPP
