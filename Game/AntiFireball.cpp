#include "AntiFireball.hpp"

std::vector<AntiFireball> antiFireballVector;

void createAntiFireball(int x, int y) {
    AntiFireball newAntiFireball = {{395, 361, 160, 129}, {x, y, 60, 60}, 10, true};
    antiFireballVector.push_back(newAntiFireball);
}

void updateAntiFireballs() {
    for (auto& antiFireball : antiFireballVector) {
        if (antiFireball.active) {
            antiFireball.moverRect.x -= antiFireball.speed;

            // Check if the anti-fireball is out of bounds
            if (antiFireball.moverRect.x + antiFireball.moverRect.w < 0) {
                antiFireball.active = false;  // Deactivate the anti-fireball
            }
        }
    }
}

void drawAntiFireballs(SDL_Renderer* gRenderer, SDL_Texture* assets) {
    for (const auto& antiFireball : antiFireballVector) {
        if (antiFireball.active) {
            SDL_RenderCopy(gRenderer, assets, &antiFireball.srcRect, &antiFireball.moverRect);
        }
    }
}
