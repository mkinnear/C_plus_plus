/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilton <hilton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 04:27:57 by hilton            #+#    #+#             */
/*   Updated: 2018/10/30 04:27:57 by hilton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie::Zombie() : m_animTime(0.0f), m_zombieState(eZombieState::ALIVE)
{
}

Zombie::~Zombie()
{
}

void Zombie::init(const float& speed, const glm::vec2& pos, const eZombies& index)
{
	m_index = index;
	m_speed = speed;
	m_position = pos;
	m_health = 50;
	// Set white Color
	m_color = Gameengine::ColorRGBA8(255, 255, 255, 255);
	Gameengine::GLTexture texture = Gameengine::ResourceManager::getTexture("Textures/bomberman2/sprites/old/enemy2_sprite.png");
	m_texture.init(texture, glm::ivec2(7, 12));
	//m_textureID = Gameengine::ResourceManager::getTexture("Textures/bomberman/enemy1.png").id;
}

void Zombie::setZombieState(eZombieState state)
{
	m_zombieState = state;
}

eZombieState Zombie::getZombieState(void) const
{
	return m_zombieState;
}

void Zombie::update(const std::vector<std::string>& levelData,
	std::vector<Human*>& humans,
	std::vector<Zombie*>& zombies,
	float deltaTime) 
{

	(void)zombies;
	m_deltaTime = deltaTime;
	
	// Find the closest human
	Human* closestHuman = getNearestHuman(humans);

	glm::vec2 direction;
	//std::cout << m_direction.x << " " << m_direction.y << std::endl;
	
	// If we found a human, move towards him
	if (closestHuman != nullptr) {
		// Get the direction vector twoards the player
		m_direction = glm::normalize(closestHuman->getPosition() - m_position);
		//std::cout << "Normalized: " << m_direction.x << " " << m_direction.y << std::endl;


		//std::cout << m_direction.x << " " << m_direction.y << std::endl;
		m_position += m_direction * m_speed * deltaTime;
	}
	else {
		//collide(levelData);
		glm::ivec2 gridPosition;
		gridPosition.x = static_cast<int>(floor(m_position.x / (float)TILE_WIDTH));
		gridPosition.y = static_cast<int>(floor(m_position.y / (float)TILE_WIDTH));
		
		if (gridPosition.x < (int)ZERO){
			direction = right;
		}
		if (gridPosition.x >= (int)levelData[0].size()){
			direction = left;
		}
		if (gridPosition.y < (int)ZERO){
			direction = up;
		}
		if (gridPosition.y >= (int)levelData.size()) {
			direction = down;
		}
		
		if (levelData[gridPosition.y][gridPosition.x + 1] == SOFT_BRICK) {
			direction = up;
		// Right soft brick
		/*std::cout << "right: " << levelData[gridPosition.y][gridPosition.x + 1];
		std::cout << " Position: " << gridPosition.y << " " << gridPosition.x + 1 << std::endl;
*/
		}
		if (levelData[gridPosition.y][gridPosition.x - 1] == SOFT_BRICK) {
			// Left soft brick
			/*std::cout << "left: " << levelData[gridPosition.y][gridPosition.x - 1];
			std::cout << " Position: " << gridPosition.y << " " << gridPosition.x - 1 << std::endl;
*/
			direction = down;
		}
		if (levelData[gridPosition.y - 1][gridPosition.x] == SOFT_BRICK) {
			// down soft brick
			/*std::cout << "down " << levelData[gridPosition.y - 1][gridPosition.x];
			std::cout << " Position: " << gridPosition.y - 1 << " " << gridPosition.x << std::endl;
*/
			direction = right;
		}
		if (levelData[gridPosition.y + 1][gridPosition.x] == SOFT_BRICK) {
			// Up soft brick
			/*std::cout << "UP " << levelData[gridPosition.y + 1][gridPosition.x];
			std::cout << " Position: " << gridPosition.y + 1 << " " << gridPosition.x << std::endl;
*/
			direction = left;
		}

		if (levelData[gridPosition.y][gridPosition.x + 1] == HARD_BRICK) {
			// Right soft brick
			/*std::cout << "right: " << levelData[gridPosition.y][gridPosition.x + 1];
			std::cout << " Position: " << gridPosition.y << " " << gridPosition.x + 1 << std::endl;
*/
			direction = up;
		}
		if (levelData[gridPosition.y][gridPosition.x - 1] == HARD_BRICK) {
			// Left soft brick
			/*std::cout << "left: " << levelData[gridPosition.y][gridPosition.x - 1];
			std::cout << " Position: " << gridPosition.y << " " << gridPosition.x - 1 << std::endl;
*/
			direction = down;
		}
		if (levelData[gridPosition.y - 1][gridPosition.x] == HARD_BRICK) {
			// down soft brick
			/*std::cout << "down " << levelData[gridPosition.y - 1][gridPosition.x];
			std::cout << " Position: " << gridPosition.y - 1 << " " << gridPosition.x << std::endl;
*/
			direction = right;
		}
		if (levelData[gridPosition.y + 1][gridPosition.x] == HARD_BRICK) {
			// Up soft brick
			/*std::cout << "UP " << levelData[gridPosition.y + 1][gridPosition.x];
			std::cout << " Position: " << gridPosition.y + 1 << " " << gridPosition.x << std::endl;
*/
			direction = left;
		}
		// if (m_direction.x > m_direction.y && m_direction.x > 0.0f) {//Up
		// direction = up
		// }
		// else if (m_direction.x < m_direction.y && m_direction.x < 0.0f) {//Down
		// 	direction = down
		// }
		// else if (m_direction.x < m_direction.y && m_direction.y > 0.0f) {//Left
		// 	direction = left
		// }
		// else if (m_direction.x > m_direction.y && m_direction.y < 0.0f) {//Right
		// 	direction = right
		// }
		// else {
		// 	direction.x = 1.0f;
		// 	direction.y = 0.0f;
		// }
		m_direction = glm::normalize(direction);

		m_position += m_direction * m_speed * deltaTime;
	}

	// Do collision
	collideWithLevel(levelData);
}

void Zombie::draw(Gameengine::SpriteBatch& m_spriteBatch)
{
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

	glm::vec4 destRect;
	destRect.x = m_position.x;
	destRect.y = m_position.y;
	destRect.z = AGENT_WIDTH;
	destRect.w = AGENT_WIDTH;


	static int numTiles = 3;
	int tileIndex = 0;
	static float animSpeed = 0.1f;
	
	tileIndex = m_index;
	if (m_zombieState == eZombieState::DEAD) {
		tileIndex += 3;
		numTiles = 5;
	}
	else {
		tileIndex = m_index;
		numTiles = 7;
	}
	if (m_animTime < 0.0f) {
		m_animTime = 0.4f;
	}
	//std::cout << "animTime:    " << m_animTime << std::endl;
	m_animTime = m_animTime + animSpeed * m_deltaTime;

	tileIndex = tileIndex + static_cast<int>(m_animTime) % numTiles;
	//std::cout << "deltaTime:    " << m_deltaTime << std::endl;
	//std::cout << "animSpeed:    " << animSpeed << std::endl;
	//std::cout << "animTime:    " << m_animTime << std::endl;
	m_spriteBatch.draw(destRect,
						m_texture.getUVs(tileIndex),
						m_texture.texture.id,
						0.0f,
						m_color,
						m_direction);
	//m_spriteBatch.draw(destRect, uvRect, m_textureID, 0.0f, m_color, m_direction);
}

eZombies Zombie::getIndex() const
{
	return m_index;
}

void Zombie::draw(Gameengine::SpriteBatch& m_spriteBatch, int indexTil)
{
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

	glm::vec4 destRect;
	destRect.x = m_position.x;
	destRect.y = m_position.y;
	destRect.z = AGENT_WIDTH;
	destRect.w = AGENT_WIDTH;


	m_spriteBatch.draw(destRect,
		m_texture.getUVs(indexTil),
		m_texture.texture.id,
		0.0f,
		m_color,
		m_direction);
	//m_spriteBatch.draw(destRect, uvRect, m_textureID, 0.0f, m_color, m_direction);
}

void Zombie::collide(const std::vector<std::string>& levelData)
{

	bool test = true;


		if (collideWithLevel(levelData) && test) {
			m_direction = left;
			// if (collideWithLevel(levelData) && test) {
			// 	m_direction = right;
			// }
		}
		else if (collideWithLevel(levelData) && test) {
			m_direction = right;
			// if (collideWithLevel(levelData) && test) {
			// 	m_direction = left;
			// }
		}
		else if (collideWithLevel(levelData) && test) {
			m_direction = up;
			// if (collideWithLevel(levelData) && test) {
			// 	m_direction = down;
			// }
		}
		else if (collideWithLevel(levelData) && test) {
			m_direction = down;
			//  
		}

	
}

Human* Zombie::getNearestHuman(std::vector<Human*>& humans) 
{
	Human* closestHuman = nullptr;
	float smallestDistance = 200.0f;

	for (size_t i = 0; i < humans.size(); i++) {
		// Get the direction vector
		glm::vec2 distVec = humans[i]->getPosition() - m_position;
		// Get distance
		float distance = glm::length(distVec);

		// If this person is closer than the closest person, this is the new closest
		if (distance < smallestDistance) {
			smallestDistance = distance;
			closestHuman = humans[i];
		}
	}

	return closestHuman;
}
