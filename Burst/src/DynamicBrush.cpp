#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Color.h"
#include "cinder/Rand.h"
#include "Particle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class DynamicBrush : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDrag( MouseEvent event );
    void keyDown( KeyEvent event );
	void update();
	void draw();
private:
    std::vector<Particle> particles;
    std::vector<Particle>::iterator pIter;
    ColorA color;
    
    ColorA randomColor();
};

ColorA DynamicBrush::randomColor() {
    float (*rand)(float) = Rand::randFloat;
    return ColorA(rand(1.0f),rand(1.0f),rand(1.0f),1.0f);
}

void DynamicBrush::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 800, 600 );
	settings->setFrameRate( 60.0f );
}

void DynamicBrush::setup()
{
    color = randomColor();
    
    // enable transparency
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void DynamicBrush::mouseDrag( MouseEvent event )
{
    particles.push_back(
        Particle(Vec2f(event.getX(),event.getY()), color)
    );
}

void DynamicBrush::keyDown(KeyEvent event) {
    if (event.getChar() == 'c') {
        color = randomColor();
    }
}

void DynamicBrush::update()
{
}

void DynamicBrush::draw()
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

CINDER_APP_BASIC( DynamicBrush, RendererGl )
