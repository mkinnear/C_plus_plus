/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agent.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hilton <hilton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 04:26:49 by hilton            #+#    #+#             */
/*   Updated: 2018/10/30 04:26:49 by hilton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Agent.h"


Agent::Agent()
{
}


Agent::~Agent()
{
}

void Agent::draw(Gameengine::SpriteBatch& m_spriteBatch)
{
		const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

		glm::vec4 destRect;
		destRect.x = m_position.x;
		destRect.y = m_position.y;
		destRect.z = AGENT_WIDTH;
		destRect.w = AGENT_WIDTH;

		m_spriteBatch.draw(destRect, uvRect, m_textureID, 0.0f, m_color, m_direction);
}

bool Agent::applyDamage(float damage) {

	m_health -= damage;
	// If we died, return true
	if (m_health <= 0) {
		return true;
	}
	return false;
}

bool Agent::collideWithLevel(const std::vector<std::string>& levelData)
{
	std::vector<glm::vec2> collideTilePositions;

	// Check  the four corners
	// first corner
	checkTilePosition(levelData,
						collideTilePositions,
						m_position.x,
						m_position.y);
	
	// second corner
	checkTilePosition(levelData,
						collideTilePositions,
						m_position.x + AGENT_WIDTH,
						m_position.y);
	
	// third corner
	checkTilePosition(levelData,
						collideTilePositions,
						m_position.x,
						m_position.y + AGENT_WIDTH);
	
	// four corner
	checkTilePosition(levelData,
						collideTilePositions,
						m_position.x + AGENT_WIDTH,
						m_position.y + AGENT_WIDTH);

	// Check if there was no collision
	if (collideTilePositions.size() == 0) {
		return false;
	}

	// do the collision
	for (size_t i = 0; i < collideTilePositions.size(); i++) {
		collideWithTile(collideTilePositions[i]);
	}
	return true;
}

// Circular collision
bool Agent::collideWithAgent(Agent* agent) {

	// Minimum distance before there is a collision
	

	// Center position of this agent
	glm::vec2 centerPosA = m_position + glm::vec2(AGENT_RADIUS);
	// Center position of the parameter agent
	glm::vec2 centerPosB = agent->getPosition() + glm::vec2(AGENT_RADIUS);

	// Distance vector between the two agents
	glm::vec2 distVec = centerPosA - centerPosB;

	// Length of the distance vector
	float distance = glm::length(distVec);

	// Depth of the collision
	float collisionDepth = MIN_CIRCULAR_COLLISION_DISTANCE - distance;

	// If collision depth > 0 then we did collide
	if (collisionDepth > 0) {

		// Get the direction times the collision depth so we can push them away from each other
		glm::vec2 collisionDepthVec = glm::normalize(distVec) * collisionDepth;

		// Push them in opposite directions
		m_position += collisionDepthVec / 2.0f;
		agent->m_position -= collisionDepthVec / 2.0f;

		return true;
	}
	return false;
}

// Circular collision
void Agent::checkTilePosition(const std::vector<std::string>& levelData,
	std::vector<glm::vec2>& collideTilePositions,
	float x,
	float y) 
{


	// Get the position of this corner in grid-space
	glm::vec2 gridPos = glm::vec2(floor(x / (float)TILE_WIDTH),
		floor(y / (float)TILE_WIDTH));

	// If we are outside the world, just return
	if (gridPos.x < 0 || gridPos.x >= levelData[0].size() ||
		gridPos.y < 0 || gridPos.y >= levelData.size()) {
		return;
	}

	// If this is not an air tile, we should collide with it
	if (levelData[gridPos.y][gridPos.x] != '.') {
		collideTilePositions.push_back(gridPos * (float)TILE_WIDTH + glm::vec2((float)TILE_WIDTH / 2.0f));
		//std::cout << "Collision: " << collideTilePositions[collideTilePositions.size() - 1].x << " " << collideTilePositions[collideTilePositions.size() - 1].y << std::endl;
	}
}

// AABB (Axis Aligned Bounding Box) collision
void Agent::collideWithTile(glm::vec2 tilePos)
{
	// The minimum distance before a collision occurs

	// Center position of the agent
	glm::vec2 centerAgentPos = m_position + glm::vec2(AGENT_RADIUS);
	// Vector from the agent to the tile
	glm::vec2 distVec = centerAgentPos - tilePos;

	// Get the depth of the collision
	float xDepth = MIN_AABB_COLLIDE_DISTANCE - abs(distVec.x);
	float yDepth = MIN_AABB_COLLIDE_DISTANCE - abs(distVec.y);

	// If both the depths are > 0, then we collided
	if (xDepth > 0 && yDepth > 0) {

		// Check which collision depth is less
		if (std::max(xDepth, 0.0f) < std::max(yDepth, 0.0f)) {
			// X collsion depth is smaller so we push in X direction
			if (distVec.x < 0) {
				m_position.x -= xDepth;
			}
			else {
				m_position.x += xDepth;
			}
		}
		else {
			// Y collsion depth is smaller so we push in X direction
			if (distVec.y < 0) {
				m_position.y -= yDepth;
			}
			else {
				m_position.y += yDepth;
			}
		}
	}
	//std::cout << m_position.x << " " << m_position.y << std::endl;
}


