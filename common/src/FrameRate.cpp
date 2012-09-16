//
//  Utils.cpp
//  BlackAndBlue
//
//  Created by Tony Lukasavage on 9/16/12.
//
//

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/Utilities.h"
#include "FrameRate.h"

using namespace savagelook;
using namespace ci;
using namespace ci::app;

namespace savagelook {
    FrameRate::FrameRate() {
        
    }
    
    FrameRate::FrameRate(App *app) {
        this->setup(app);
    }

    void FrameRate::setup(App *app) {
        this->app = app;
        font = Font("Arial", 16.0f );
    }

    void FrameRate::draw() {
        gl::drawString( "FPS: " + toString(app->getAverageFps()), Vec2f( 10.0f, 10.0f ), Color::white(), font );
    }
}