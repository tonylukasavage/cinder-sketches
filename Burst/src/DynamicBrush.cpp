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
    int life;
    float radius;
    int shapeIndex;
    
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
    life = 120;
    radius = 30.0f;
    shapeIndex = 0;
    
    // enable transparency
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void DynamicBrush::mouseDrag( MouseEvent event )
{
    particles.push_back(
        Particle(Vec2f(event.getX(),event.getY()), color, radius, life)
    );
}

void DynamicBrush::keyDown(KeyEvent event) {
    switch (event.getChar()) {
        case 'c':
            color = randomColor();
            break;
        case 'e':
            radius++;
            break;
        case 'r':
            radius--;
            break;
        case 'd':
            life++;
            break;
        case 'f':
            life--;
            break;
        case 's':
            if (shapeIndex < 1) {
                shapeIndex++;
            } else {
                shapeIndex = 0;
            }
        default:
            break;
    }
}

void DynamicBrush::update()
{
}

void DynamicBrush::draw()
{
	// clear out the window with black
	gl::clear( Color( 255, 255, 255 ) );
    
    // draw particles, eliminate "dead" ones
    pIter = particles.begin();
    while(pIter != particles.end()) {
        if (pIter->getLife() <= 0) {
            pIter = particles.erase(pIter);
        } else {
            pIter->update();
            pIter->draw(shapeIndex);
            pIter++;
        }
    }
}

CINDER_APP_BASIC( DynamicBrush, RendererGl )
