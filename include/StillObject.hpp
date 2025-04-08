//
// Created by 10Pis on 2025/3/31.
//

#ifndef STILLOBJECT_HPP
#define STILLOBJECT_HPP

#include <string>
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"

class StillObject : public Util::GameObject {
public:
    StillObject(std::string ImagePath) : ImagePath(ImagePath) {m_Drawable = std::make_shared<Util::Image>(ImagePath);};

    void SetPosition(const glm::vec2& position) {
        m_Transform.translation = position;
    }

    void SetSize(const glm::vec2& size) {
        m_Transform.scale = size;
    }

    glm::vec2 GetPosition() const {
        return m_Transform.translation;
    }

    std::shared_ptr<Core::Drawable> GetDrawable() const {
        return m_Drawable;
    }

    void SetImagePath(const std::string &path) {
        this->ImagePath = path;
        auto img = std::dynamic_pointer_cast<Util::Image>(m_Drawable);
        if (img) img->SetImage(path);
    }

    bool collision(const GameObject& other) {
        glm::vec2 posA = this->GetTransform().translation;
        glm::vec2 sizeA = this->GetScaledSize();
        glm::vec2 posB = other.GetTransform().translation;
        glm::vec2 sizeB = other.GetScaledSize();

        bool collisionX = std::abs(posA.x - posB.x) * 2 < (sizeA.x + sizeB.x);
        bool collisionY = std::abs(posA.y - posB.y) * 2 < (sizeA.y + sizeB.y);
        return collisionX && collisionY;
    }

protected:
    std::string ImagePath;
};


#endif //STILLOBJECT_HPP
