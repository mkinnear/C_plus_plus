/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilton <hilton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 04:28:01 by hilton            #+#    #+#             */
/*   Updated: 2018/10/30 04:28:01 by hilton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H 
#define ZOMBIE_H

#include "include/ResourceManager.h"
#include "include/Includes.h"

#include "Agent.h"
#include "Human.h"

class Zombie : public Agent
{
public:
	Zombie();
	~Zombie();

	void init(const float& speed, const glm::vec2& pos, const eZombies& index);

	virtual void update(const std::vector<std::string>& levelData,
		std::vector<Human*>& humans,
		std::vector<Zombie*>& zombies,
		float deltaTime) override;
	void draw(Gameengine::SpriteBatch& m_spriteBatch) override;
	void draw(Gameengine::SpriteBatch& m_spriteBatch, int indexTile);
	eZombies getIndex() const;

	void setZombieState(eZombieState state);
	eZombieState getZombieState(void) const;

private:

	Human* getNearestHuman(std::vector<Human*>& humans);
	void collide(const std::vector<std::string>& levelData);
	eZombies m_index;
	float m_animTime;
	eZombieState m_zombieState;
};

#endif 