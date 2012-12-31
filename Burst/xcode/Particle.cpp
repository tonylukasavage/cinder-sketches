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
    setup(Vec2f(Rand::randFloat(800.0f),Rand::randFloat(600.0f)));
}

Particle::Particle(Vec2f pos) {
    setup(pos);
}

int Particle::getLife() {
    return life;
}

void Particle::setup(Vec2f pos) {
    this->pos = pos;
    color = ColorA(0.0f, 0.0f, 1.0f, 1.0f);
    currentRadius = radius = 30.0f;
    life = 120;
}

void Particle::update() {
    float ratio = life/120.0f;
    currentRadius = radius * ratio;
    color = ColorA(0.0f, 0.0f, 1.0f, ratio);
    life--;
}

void Particle::draw() {
    gl::color(color);
    gl::drawSolidCircle(pos, currentRadius);
}
