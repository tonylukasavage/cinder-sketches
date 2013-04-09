//
//  Particle.cpp
//  Burst
//
//  Created by Tony Lukasavage on 12/30/12.
//
//

#include "Particle.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <iostream>

using namespace ci;

Particle::Particle() {
    setup(
        Vec2f(Rand::randFloat(800.0f),Rand::randFloat(600.0f)),
        ColorA(Rand::randFloat(1.0f),Rand::randFloat(1.0f),Rand::randFloat(1.0f),1.0f),
        30.0f,
        120
    );
}

Particle::Particle(Vec2f pos, ColorA color, float radius, int life) {
    setup(pos, color, radius, life);
}

float Particle::getLife() {
    return currentLife;
}

void Particle::setup(Vec2f pos, ColorA color, float radius, int life) {
    this->pos = pos;
    this->color = color;
    this->currentRadius = this->radius = radius;
    this->currentLife = this->life = life;
}

void Particle::update() {
    float ratio = currentLife/life;
    currentRadius = radius * ratio;
    color.a = ratio;
    currentLife--;
}

void Particle::draw(int shapeIndex) {
    gl::color(color);
    if (shapeIndex == 0) {
        gl::drawSolidCircle(pos, currentRadius);
    } else if (shapeIndex == 1) {
        float halfRad = currentRadius/2.0f;
        Rectf rect = Rectf(pos.x-halfRad,pos.y-halfRad,pos.x+halfRad,pos.y+halfRad);
        gl::drawSolidRect(rect);
    }
}
