//
// Created by 10Pis on 2025/4/4.
//
#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include "StillObject.hpp"
class SceneObject : public StillObject{
public:
    SceneObject(std::string path,glm::vec2 position) : StillObject(path) {
        this->SetPosition(position);
    }

private:
};

#endif //SCENEOBJECT_HPP
