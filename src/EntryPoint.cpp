#include <iostream>

//SFML:
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


int main() {
	sf::RenderWindow window;

	sf::Sound sound;

	sf::VideoMode mode = { 1024, 576, 32 };
	window.create(mode, "eNement", sf::Style::Default);

	std::cin.get();
}