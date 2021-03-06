#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "vector"
#include "LoaderParams.h"

class Game
{
  private:
  Game() {}
  static Game* s_pInstance;

  public:
  static Game* Instance()
  {
    if(s_pInstance == 0)
    {
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }
  SDL_Renderer* getRenderer() const {return m_pRenderer;}


  bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
  void render();
  void update();
  bool running();
  void handleEvents();
  void clean();

  private:
  SDL_Window* m_pWindow;
  SDL_Renderer* m_pRenderer;
  std::vector<GameObject*> m_gameObjects;
  int m_currentFrame;
  bool m_bRunning;
};
typedef Game TheGame;