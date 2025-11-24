#include "takecaketochildreninputhandler.h"

TakeCakeToChildrenInputHandler::TakeCakeToChildrenInputHandler(std::shared_ptr<Player> player, State &state, bool &reset)
    : m_player(player)
    , m_state(&state)
{
    m_reset = &reset;
    *m_reset = false;
}

void TakeCakeToChildrenInputHandler::handleKeyPressed(RenderWindow &window, Event &event)
{
    if (event.key.code == sf::Keyboard::Escape) {
        getPointerToSMRC()->switchScreen("Fnaf2Menu");
        if (*m_state == State::PLAYING)
            *m_state = State::PAUSED;
    }
    if (event.key.code == sf::Keyboard::Enter) {
        switch(*m_state) {
        case State::PLAYING:
            *m_state = State::PAUSED;
            break;
        case State::PAUSED:
            *m_state = State::PLAYING;
            break;
        case State::OVER:
            m_player->forcedMovement(sf::Vector2<float>(window.getSize().x / 2, window.getSize().y / 2));
            *m_reset = true;
            *m_state = State::PLAYING;
            break;
        default:
            break;
        };
    }
    m_player->input_pressed(event);
}

void TakeCakeToChildrenInputHandler::handleKeyReleased(RenderWindow &window, Event &event)
{
    m_player->input_released(event);
}
