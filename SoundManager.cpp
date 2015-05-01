#include "SoundManager.h"

SoundManager * SoundManager::_instance = NULL;

bool SoundManager::init()
{
	sf::Music * music;

	music = new sf::Music();
	if (!music->openFromFile("sounds/night-01.wav"))
	{
		return false;
	}
	this->_musics["night"] = music;

	return true;
}

const sf::SoundBuffer & SoundManager::sound(string soundName)
{
	return *this->_sounds[soundName];
}

sf::Music & SoundManager::music(string musicName)
{
	return *this->_musics[musicName];
}

SoundManager * SoundManager::get()
{
	if (SoundManager::_instance == NULL)
	{
		SoundManager::_instance = new SoundManager();
	}

	return SoundManager::_instance;
}
