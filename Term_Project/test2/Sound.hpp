#pragma once
#ifndef SOUND_HPP
#define SOUND_HPP

#include "SFML/Audio.hpp"

#include "Game.hpp"

class Sound {
	
	private:

		Sound();
		//Sound(const Sound& other) {};
		static Sound*instance;

		sf::SoundBuffer pieceMoveSoundBuffer;
		sf::Sound pieceMoveSound;
		sf::SoundBuffer buttonClickedSoundBuffer;
		sf::Sound buttonClickedSound;
		sf::Music backGroundMusic;

	public:

		static Sound* getInstance() {
			if (instance == 0) {
				instance = new Sound();
			}
			return instance;
		}

		void PlayButtonClickedSound() { buttonClickedSound.play(); }
		void PlayPieceMoveSound() { pieceMoveSound.play(); }
		void PlayBackGroundMusic() { backGroundMusic.play(); }
		void PauseBackGroundMusic() { backGroundMusic.pause(); }
};

#endif