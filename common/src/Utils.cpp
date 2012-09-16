#include "Utils.h"

#include "cinder/Utilities.h"
#include "cinder/ImageIo.h"

using namespace ci;
using namespace ci::app;

namespace savagelook {
    void captureFrame(App *app) {
        writeImage( "../../../capture/image_" + toString(app->getElapsedFrames()) + ".png", app->copyWindowSurface());
    }
}