#ifndef STATE_PAUSED_HPP
#define STATE_PAUSED_HPP

#include <ME/GameStateManager.hpp>

namespace tg
{
  class StatePaused : public me::GameState
  {
  public:
    virtual void continuousUpdate(const sf::Time &timeElapsed);
    virtual void fixedUpdate();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    StatePaused();
    ~StatePaused();
  };
}



#endif //STATE_PAUSED_HPP
