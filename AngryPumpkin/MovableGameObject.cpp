#include "MovableGameObject.h"
#include "Water.h"
#include "Pumpkin.h"
#include "EvilPumpkin.h"
#include "Player.h"
#include "Game.h"

void MovableGameObject::setTextureForSprite()
{
	switch (direction)
	{
	case Direction::UP:
		sprite.setTexture(textureUp);
		break;
	case Direction::DOWN:
		sprite.setTexture(textureDown);
		break;
	case Direction::RIGHT:
		sprite.setTexture(textureRight);
		break;
	case Direction::LEFT:
		sprite.setTexture(textureLeft);
		break;
	}
}

bool MovableGameObject::calculateBoardCollision()
{
	if (position.x - size.x * 0.5f <= 0.f || position.x + size.x * 0.5f >= GameState::getScreenWidth() ||
		position.y - size.y * 0.5f <= GameState::getUpBoard() || position.y + size.y * 0.5f >= GameState::getScreenHeight())
	{
		return true;
	}
	return false;
}

MovableGameObject::MovableGameObject()
{
	direction = Direction(rand() % 4);
	speed = OBJECT_SPEED;
	assert(eatSoundBuffer.loadFromFile(RESOURCES_PATH + "Eat.wav"));
	eatSound.setBuffer(eatSoundBuffer);
}


void MovableGameObject::updateMovableObject(float deltaTime, Game& game)
{
	changeDirection();

	switch (direction)
	{
	case Direction::UP:
		sprite.setTexture(textureUp);
		position.y -= speed * deltaTime;
		break;
	case Direction::DOWN:
		sprite.setTexture(textureDown);
		position.y += speed * deltaTime;
		break;
	case Direction::RIGHT:
		sprite.setTexture(textureRight);
		position.x += speed * deltaTime;
		break;
	case Direction::LEFT:
		sprite.setTexture(textureLeft);
		position.x -= speed * deltaTime;
		break;
	}

	for (auto& it : game.getStaticGameObjectsMap()) {
		if (it.first == typeid(Pumpkin).name())
		{
			float dx = position.x - it.second->getPosition().x;
			float dy = position.y - it.second->getPosition().y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size.x + it.second->getSize().x) * 0.5f)
			{
				handlingPumpkinCollision();
				it.second.get()->setPosition(game.generateNewPosition());
				it.second.get()->update();
			}
		}
		if (it.first == typeid(Water).name())
		{
			sf::Vector2f wallPosition = it.second->getPosition();
			float halfWallSize_x = it.second->getSize().x * 0.5f;
			float halfWallSize_y = it.second->getSize().y * 0.5f;
			if (abs(wallPosition.y - position.y) <= halfWallSize_y + size.y * 0.5f && abs(wallPosition.x - position.x) <= halfWallSize_x + size.x * 0.5f)
			{
				position = sprite.getPosition();
				handlingWallCollision();
			}
		}
	}

	auto player = game.getMovableGameObjectsMap().find(typeid(Player).name())->second;
	for (auto& it : game.getMovableGameObjectsMap()) {
		if (it.first == typeid(EvilPumpkin).name())
		{
			float dx = player.get()->getPosition().x - it.second->getPosition().x;
			float dy = player.get()->getPosition().y - it.second->getPosition().y;
			float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size.x + it.second->getSize().x) * 0.5f)
			{
				GameState::setGameOverStatus(true);
			}
		}
	}

	if (calculateBoardCollision()) {
		position = sprite.getPosition();
		handlingBorderCollision();
	}

	sprite.setPosition(position);
}