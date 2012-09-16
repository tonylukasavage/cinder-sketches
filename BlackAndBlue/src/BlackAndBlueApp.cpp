#include "Particle.h"
#include "FrameRate.h"
#include "Utils.h"

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const int pCount = 5000;

class BlackAndBlueApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
	void setup();	
	void draw();
private:
    Particle particles[pCount];
    savagelook::FrameRate frameRate;
};

void BlackAndBlueApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 600 );
	settings->setFrameRate( 60.0f );
}

void BlackAndBlueApp::setup()
{
    // setup frame rate display
    frameRate.setup(this);
    
    // enable transparency
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void BlackAndBlueApp::draw()
{
	// clear out the window with white
    gl::clear( Color( 255, 255, 255 ) ); 
    
    // draw particles
    for (int i = 0; i < pCount; i++) {
        particles[i].draw();
    }
    
    // show frame rate
    frameRate.draw();
    
    // capture each frame
    //savagelook::captureFrame(this);
}

CINDER_APP_BASIC( BlackAndBlueApp, RendererGl )
