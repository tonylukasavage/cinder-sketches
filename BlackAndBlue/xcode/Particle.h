//
//  Particle.h
//  lifecycle
//
//  Created by default on 9/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BlackAndBlue_Particle_h
#define BlackAndBlue_Particle_h

#include "cinder/Vector.h"
#include "cinder/Color.h"

using namespace ci;

class Particle {
public:
    Particle();

    void setup();
    void draw();
    void update();
    
private:
    Vec2f pos;
    ColorA color;
    float baseRadius, radius;
    float scale;

    bool scaleUp;
    float max, min;
};

#endif
