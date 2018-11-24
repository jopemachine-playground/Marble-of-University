#pragma once
#ifndef SOUND_HPP
#define SOUND_HPP

#include "SFML/Audio.hpp"

#include "Game.hpp"

class Sound {
	
	private:
		sf::SoundBuffer pieceMoveSoundBuffer;
		sf::Sound pieceMoveSound;
		sf::SoundBuffer buttonClickedSoundBuffer;
		sf::Sound buttonClickedSound;
		sf::Music backGroundMusic;

	public:
		Sound();
		void PlayButtonClickedSound() { buttonClickedSound.play(); }
		void PlayPieceMoveSound() { pieceMoveSound.play(); }
		void PlayBackGroundMusic() { backGroundMusic.play(); }
		void PauseBackGroundMusic() { backGroundMusic.pause(); }
};

#endif