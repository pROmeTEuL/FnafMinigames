#include "takecaketochildreninputhandler.h"

TakeCakeToChildrenInputHandler::TakeCakeToChildrenInputHandler(std::shared_ptr<Player> player)
    : m_player(player)
{

}

void TakeCakeToChildrenInputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{
    if (Keyboard::isKeyPressed(Keyboard::Escape)) {
        getPointerToSMRC()->switchScreen("Fnaf2Menu");
    }
    m_player->input_pressed(event);
}

void TakeCakeToChildrenInputHandler::handleKeyReleased(RenderWindow &window, Event &event)
{
    m_player->input_released(event);
}
