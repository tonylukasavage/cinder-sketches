//
//  Particle.h
//  Burst
//
//  Created by Tony Lukasavage on 12/30/12.
//
//

#ifndef __Burst__Particle__
#define __Burst__Particle__

#include "cinder/Vector.h"
#include "cinder/Color.h"

using namespace ci;

class Particle {
public:
    Particle();
    Particle(Vec2f pos, ColorA color, float radius, int life);
    
    void setup(Vec2f pos, ColorA color, float radius, int life);
    void draw(int shapeIndex);
    void update();
    
    float getLife();
    
private:
    Vec2f pos;
    ColorA color;
    float radius, currentRadius;
    float life, currentLife;
};

#endif /* defined(__Burst__Particle__) */
