#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BurstApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDrag( MouseEvent event );
	void update();
	void draw();
private:
    std::vector<Particle> particles;
    std::vector<Particle>::iterator pIter;
};

void BurstApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 600 );
	settings->setFrameRate( 60.0f );
}

void BurstApp::setup()
{
    // enable transparency
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void BurstApp::mouseDrag( MouseEvent event )
{
    particles.push_back(Particle(Vec2f(event.getX(),event.getY())));
}

void BurstApp::update()
{
}

void BurstApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 255, 255, 255 ) );
    
    pIter = particles.begin();
    while(pIter != particles.end()) {
        if (pIter->getLife() <= 0) {
            pIter = particles.erase(pIter);
        } else {
            pIter->update();
            pIter->draw();
            pIter++;
        }
    }
}

CINDER_APP_BASIC( BurstApp, RendererGl )