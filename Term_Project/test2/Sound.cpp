#include "pch.h"

#include "Sound.hpp"

Sound* Sound::instance = nullptr;

Sound::Sound() {
	pieceMoveSoundBuffer.loadFromFile(FILE_pieceMoveSound);
	pieceMoveSound.setBuffer(pieceMoveSoundBuffer);
	pieceMoveSound.setVolume(VOLUME_pieceMoveSound);

	buttonClickedSoundBuffer.loadFromFile(FILE_buttonClickedSound);
	buttonClickedSound.setBuffer(buttonClickedSoundBuffer);
	buttonClickedSound.setVolume(VOLUME_buttonClickedSound);

	backGroundMusic.openFromFile(FILE_backGroundMusic);
	backGroundMusic.setVolume(VOLUME_backGroundMusic);
	backGroundMusic.setLoop(true);
}