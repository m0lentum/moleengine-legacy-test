#include "StatePaused.hpp"
#include <SFML/Window/Keyboard.hpp>

namespace tg
{
   void StatePaused::continuousUpdate(const sf::Time &timeElapsed)
   {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
      {
		  m_manager->transitionTo("PLAYING");
      }
   }

   void StatePaused::fixedUpdate()
   {

   }
   
   void StatePaused::draw(sf::RenderTarget& target, sf::RenderStates states) const
   {
    
   }

   StatePaused::StatePaused()
   {
      
   }

   StatePaused::~StatePaused()
   {
      
   }
}
