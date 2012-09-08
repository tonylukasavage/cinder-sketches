#include "Particle.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <iostream>

using namespace ci;

Particle::Particle() {
    setup();
}

void Particle::setup() {
    pos = Vec2f(Rand::randFloat(800.0f),Rand::randFloat(600.0f));
    color = ColorA(0.0f, 0.0f, Rand::randFloat(), Rand::randFloat());
    baseRadius = radius = Rand::randFloat(5.0f, 50.0f);
    scale = Rand::randFloat(1.0f,2.0f);
    scaleUp = Rand::randBool();
    
    max = baseRadius * scale;
    min = baseRadius * (1/scale);
}

void Particle::draw() {
    float speed = 0.75f;
    
    gl::color(color);
    if (scaleUp) {
        radius += speed;
        if (radius >= max) {
            radius = max;
            scaleUp = false;
        }
    } else {
        radius -= speed;
        if (radius <= min) {
            radius = min;
            scaleUp = true;
        }
    }
    gl::drawSolidCircle(pos, radius, 4);
}