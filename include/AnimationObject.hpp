//
// Created by 10Pis on 2025/3/31.
//

#ifndef ANIMATIONOBJECT_HPP
#define ANIMATIONOBJECT_HPP

#include <sstream>
#include <iomanip>
#include <string>
#include "Util/GameObject.hpp"
#include "Util/Animation.hpp"

enum Way {left,right};

class AnimationObject : public Util::GameObject{
public:
    AnimationObject(const size_t size,std::string Path,  int digits){
        for(size_t i = 0;i < size;i++) {
            std::ostringstream oss;
            oss << Path << std::setw(digits) << std::setfill('0') << i << ".png";
            AddImagePath(oss.str());
        }
        m_Drawable = std::make_shared<Util::Animation>(AnimationPaths,true,62.5,true ,100);
    }

    Way GetWay(){return way;}

    glm::vec2 GetPosition() {return m_Transform.translation;}

    void SetWay(Way way){this->way = way;}

    void SetPosition(const glm::vec2 &position) {m_Transform.translation = position;}

    void SetSize(glm::vec2 size) {m_Transform.scale = size;}

    void AddImagePath(std::string ImagePath) {
        AnimationPaths.push_back(ImagePath);
    }

    std::shared_ptr<Core::Drawable> GetDrawable() {return m_Drawable;}

    bool collision(const GameObject& other) {
        glm::vec2 posA = this->GetPosition();
        glm::vec2 sizeA = this->GetScaledSize();
        glm::vec2 posB = other.GetTransform().translation;
        glm::vec2 sizeB = other.GetScaledSize();

        bool collisionX = std::abs(posA.x - posB.x) * 2 < (sizeA.x + sizeB.x);
        bool collisionY = std::abs(posA.y - posB.y) * 2 < (sizeA.y + sizeB.y);
        return collisionX && collisionY;
    }

protected:
    std::shared_ptr<Util::Animation> Animations;
    std::vector<std::string> AnimationPaths;
    Way way = left;
};

#endif //ANIMATIONOBJECT_HPP
