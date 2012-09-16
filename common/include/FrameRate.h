//
//  FrameRate.h
//
//  Created by Tony Lukasavage on 9/16/12.
//  Class for showing the current average framerate
//

#ifndef __SavageLook__FrameRate__
#define __SavageLook__FrameRate__

#include "cinder/app/App.h"
#include "cinder/Font.h"

using namespace ci;
using namespace ci::app;

namespace savagelook {
    class FrameRate {
    public:
        FrameRate();
        FrameRate(App *app);
        void setup(App *app);
        void draw();
    private:
        App *app;
        Font font;
    };
}

#endif /* defined(__SavageLook__Utils__) */
