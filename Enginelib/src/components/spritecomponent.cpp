#include "spritecomponent.hpp"
#include "../basics/vector2d.hpp"
#include "../basics/helpers.hpp"
#include "../graphicsmanager.hpp"
#include "../basics/rect.hpp"
#include "../basics/sprite.hpp"
#include "../filesystem/resourcefile.hpp"


void SpriteComponent::load_sprite_from_image(ResourceFile * file)
{
	m_sprite = GraphicsManager::load_sprite(file);
}

void SpriteComponent::render() {
	if (m_sprite)
	{
		GraphicsManager::render_texture(
			*m_sprite,
			Vector2D(m_owner->transform().get_position()),
			m_owner->transform().get_scale(),
			m_owner->transform().get_rotation(),
			m_centered
		);
	}
}