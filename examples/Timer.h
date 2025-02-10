#pragma once

#include <cstdint>


namespace Example
{
   /// grabs the time of day
   class Timer
   {
   public:
      Timer();
      void Update();

      // @return the ms ticks since SDL_Init in seconds
      double GetSeconds() const;

   private:
      uint32_t _ticks;
   };
}

