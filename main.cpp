#include "game/game.h"

int main(int argc, char* argv[]) {
    return Game::Singleton::getInstance().parseScenario(argc, argv);
}
