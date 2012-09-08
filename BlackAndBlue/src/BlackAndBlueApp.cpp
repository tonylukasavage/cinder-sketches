#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"
#include "cinder/Rand.h"
#include "cinder/Utilities.h"
#include "math.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const int pCount = 5000;

class BlackAndBlueApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
	void setup();	
	void update();
	void draw();
private:
    Particle particles[pCount];
    Font mFont;
};

void BlackAndBlueApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 600 );
	settings->setFrameRate( 60.0f );
}

void BlackAndBlueApp::setup()
{
    mFont = Font( "Arial", 16.0f );
    
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void BlackAndBlueApp::update()
{
}

void BlackAndBlueApp::draw()
{
	// clear out the window with white
    gl::clear( Color( 255, 255, 255 ) ); 
    
    // draw particles
    for (int i = 0; i < pCount; i++) {
        particles[i].draw();
    }
    
    gl::drawString( "Framerate: " + toString(getAverageFps()), Vec2f( 10.0f, 10.0f ), Color::white(), mFont );
}

CINDER_APP_BASIC( BlackAndBlueApp, RendererGl )
