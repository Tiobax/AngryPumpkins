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
			const float dx = position.x - it.second->getPosition().x;
			const float dy = position.y - it.second->getPosition().y;
			const float distance = sqrt(dx * dx + dy * dy);
			if (distance < (size.x + it.second->getSize().x) * 0.5f)
			{
				handlingPumpkinCollision();
				it.second.get()->setPosition(game.generateNewPosition());
				it.second.get()->update();
			}
		}
		if (it.first == typeid(Water).name())
		{
			const sf::Vector2f waterPosition = it.second->getPosition();
			const float halfWaterSizeX = it.second->getSize().x * 0.5f;
			const float halfWaterSizeY = it.second->getSize().y * 0.5f;
			if (abs(waterPosition.y - position.y) <= halfWaterSizeY + size.y * 0.5f && abs(waterPosition.x - position.x) <= halfWaterSizeX + size.x * 0.5f)
			{
				position = sprite.getPosition();
				handlingWallCollision();
			}
		}
	}

	const auto player = game.getMovableGameObjectsMap().find(typeid(Player).name())->second;
	for (auto& it : game.getMovableGameObjectsMap()) {
		if (it.first == typeid(EvilPumpkin).name())
		{
			const float dx = player.get()->getPosition().x - it.second->getPosition().x;
			const float dy = player.get()->getPosition().y - it.second->getPosition().y;
			const float distance = sqrt(dx * dx + dy * dy);
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