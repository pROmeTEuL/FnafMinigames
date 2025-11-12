#include "takecaketochildreninputhandler.h"

TakeCakeToChildrenInputHandler::TakeCakeToChildrenInputHandler(std::shared_ptr<Player> player, bool &paused)
    : m_player(player)
{
    m_paused = &paused;
}

void TakeCakeToChildrenInputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{
    if (event.key.code == sf::Keyboard::Escape) {
        getPointerToSMRC()->switchScreen("Fnaf2Menu");
        *m_paused = true;
    }
    if (event.key.code == sf::Keyboard::Enter) {
        *m_paused = !(*m_paused);
    }
    m_player->input_pressed(event);
}

void TakeCakeToChildrenInputHandler::handleKeyReleased(RenderWindow &window, Event &event)
{
    m_player->input_released(event);
}
