//
// Created by 10Pis on 2025/3/27.
//

#include "Kirby.hpp"

void m_kirby::SetCurrentState(const Action state){
    CurrentState = state;
    this->SetDrawable(GetCurrentAnimation()->GetDrawable());
};

Action m_kirby::GetCurrentState() {
    return CurrentState;
};

std::shared_ptr<AnimationObject> m_kirby::GetCurrentAnimation(){
    switch(CurrentState){
        case(Action::Idle):
            return Idle;
            break;
        case (Action::Walking):
            return Walking;
            break;
        case(Action::Running):
            return Running;
            break;
        case(Action::Down):
            return Down;
            break;
        case(Action::Jump):
            return Jump;
            break;
        default:
            return nullptr;
            break;
    }
}
bool m_kirby::IfCollide(const std::shared_ptr<GameObject> &Object) {
    if (Object->GetTransform().translation.x <= this->GetPosition().x + this->GetScaledSize().x / 2 &&
        Object->GetTransform().translation.x >= this->GetPosition().x - this->GetScaledSize().x / 2 &&
        Object->GetTransform().translation.y <= this->GetPosition().y + this->GetScaledSize().y / 2 &&
        Object->GetTransform().translation.y >= this->GetPosition().x - this->GetScaledSize().x / 2) {
        return true;
        }
    return false;
}

