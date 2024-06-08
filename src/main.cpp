#include "../Headers/Engine.hpp"
#include "../Headers/Pendulum.hpp"

int main () {
    Pendulum pendulum(300.0, 400.0, 0.0, M_PI / 4);
    Engine engine;

    engine.addPendulum(pendulum);

    while(engine.running()) {
        engine.update();
        engine.render();
    }
}