//
// Created by 10Pis on 2025/3/27.
//

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "AnimationObject.hpp"
#include "StillObject.hpp"


class Enemy : public AnimationObject {
public:
    Enemy(const size_t size, const std::string &Path) : AnimationObject(size,Path) {};
    void SetEnemyVect(const std::vector<std::shared_ptr<Enemy>> &enemies) {
        this->enemies() = enemies;
    };
    virtual void Action() = 0;
    virtual void GotHit() = 0;
private:
    std::vector<std::shared_ptr<Enemy>> enemies();
};

#endif //ENEMY_HPP
