#ifndef __SOUND_MANAGER_H__
# define __SOUND_MANAGER_H__

#include <string>
#include <map>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>

using namespace std;

class SoundManager
{
public:
	bool					init();
	const sf::SoundBuffer &	sound(string soundName);
	sf::Music &				music(string musicName);

public:
	static SoundManager *	get();

private:
	SoundManager() {}

private:
	map<string, sf::Music *>		_musics;
	map<string, sf::SoundBuffer *>	_sounds;

private:
	static SoundManager *	_instance;
};

#endif // !__SOUND_MANAGER_H__
