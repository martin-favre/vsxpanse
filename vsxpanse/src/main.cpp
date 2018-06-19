#include "engine.hpp"
#include "components/transform.hpp"
#include "components/spritecomponent.hpp"
#include "components/playercontroller_cmp.hpp"
#include "components/harvestercontroller_cmp.hpp"
#include "components/guicontrol_cmp.hpp"
#include "map/gridmap.hpp"
#undef main


ResourceArchive * g_archive;

void generate_resources()
{
	GameObject * resource = Engine::add_gameobject<GameObject>();
	resource->transform().set_position(Vector2D(200, 200));
	ResourceFile * file = g_archive->get_item("Images\\resource.png");
	resource->add_component<SpriteComponent>()->load_sprite_from_image(file);
	
}

void set_up_a_harvester()
{
	GameObject * harv = Engine::add_gameobject<GameObject>();
	harv->name() = "Harvester";
	SpriteComponent * sc = harv->add_component<SpriteComponent>();
	ResourceFile * file = g_archive->get_item("Images\\harvester.png");
	sc->load_sprite_from_image(file);
}

void set_up_player()
{
	GameObject * player = Engine::add_gameobject<GameObject>();
	player->name() = "Player";
	SpriteComponent * sc = player->add_component<SpriteComponent>();
	ResourceFile * file = g_archive->get_item("Images\\player.png");
	player->add_component<PlayerControllerCmp>();
	player->transform().set_position(Vector2D(10, 10));
	sc->load_sprite_from_image(file);
}

void set_up_gui_controls()
{
	GameObject * gui = Engine::add_gameobject<GameObject>();
	gui->add_component<GuiControlCmp>();
}

void set_up_gameobjects()
{
	set_up_player();
	set_up_a_harvester();
	generate_resources();
	set_up_gui_controls();
}

int main()
{
	Engine::initialize();
	g_archive = new ResourceArchive("Resources");
	GridMap::initialize(Vector2DInt(100, 100), g_archive);
	Engine::register_scene("tmp", set_up_gameobjects);
	Engine::load_scene("tmp");
	Engine::start();
	Engine::teardown();
    return 0;
}

	