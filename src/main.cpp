#include "../Headers/Engine.hpp"
#include "../Headers/Pendulum.hpp"

int main () {
    Engine engine;

    srand(static_cast<unsigned>(time(NULL)));

    int input;
    std::cout << "Quantos pêndulos você quer adicionar? (Mínimo 1 e Máximo 10)" << std::endl;
    std::cin >> input;

    if(input <= 10 && input > 0) {
        for(int i = 0 ; i < input ; i++) {
            float length = rand() % 401 + 100;
            float angle = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) * (M_PI / 2.0f);

            Pendulum pendulum(length, 400.0, 0.0, angle);
            engine.addPendulum(pendulum);
        }
    } else {
        std::cout << "Inválido.";
        return -1;
    } 

    while(engine.running()) {
        engine.update();
        engine.render();
    }

    engine.~Engine();
}