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
    Particle(Vec2f pos, ColorA color);
    
    void setup(Vec2f pos, ColorA color);
    void draw();
    void update();
    
    int getLife();
    
private:
    Vec2f pos;
    ColorA color;
    float radius, currentRadius;
    int life;
};

#endif /* defined(__Burst__Particle__) */
