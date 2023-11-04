module;
#include <SDL.h>
module xegesis.elemental;
import <stdexcept>;
import <string>;

namespace xegesis
{
	Application::Application(const InitFlag flag) {
		if (0 > SDL_Init(flag)) { //if the initialisation is failed
			throw std::runtime_error {
				std::string {
					"Failed to init sdl library\nMessage from sdl:\n" } +
				SDL_GetError() };
		}
	}
	Application::~Application() {
		SDL_Quit();
	}
	
	void Application::addFlag(const InitFlag flag) {
		ms_flag |= flag;
		return;
	}

	InitFlag Application::ms_flag {};

	InitFlagAdder::InitFlagAdder(const InitFlag flag) {
		Application::addFlag(flag);
	}
}//namespace
