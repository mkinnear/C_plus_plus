/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AudioEngine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilton <hilton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 01:33:42 by hilton            #+#    #+#             */
/*   Updated: 2018/10/30 01:33:42 by hilton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AUDIOENGINE_H
#define AUDIOENGINE_H

#include "Includes.h"
#include "Error.h"

namespace Gameengine {

	class SoundEffect {
	public:
		friend class AudioEngine;

		/// Plays the effect file
		/// @param loops: If loops == -1, loop forever,
		/// otherwise play it loops+1 times 
		void play(int loops = 0);
	private:
		Mix_Chunk* m_chunk = nullptr;
	};

	class Music {
	public:
		friend class AudioEngine;

		/// Plays the music file
		/// @param loops: If loops == -1, loop forever,
		/// otherwise play it loops times 
		void play(int loops = 1);

		/// Pauses whatever song is currently playing
		static void pause();
		/// Stops whatever song is currently playing
		static void stop();
		/// Resumes whatever song is currently playing
		static void resume();
	private:
		Mix_Music* m_music = nullptr;
	};

	class AudioEngine {
	public:
		AudioEngine();
		~AudioEngine();

		void init();
		void destroy();

		SoundEffect loadSoundEffect(const std::string& filePath);
		Music loadMusic(const std::string& filePath);
	private:

		std::map<std::string, Mix_Chunk*> m_effectMap; ///< Effects cache
		std::map<std::string, Mix_Music*> m_musicMap; ///< Music cache

		bool m_isInitialized = false;
	};

}

#endif 