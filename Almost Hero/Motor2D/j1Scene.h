#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include "p2DynArray.h"
#include "j1Timer.h"
#include "j1Collisions.h"

#define MAX_RED_NOTES_ON_SCREEN 10


struct SDL_Texture;

enum NOTE_COLOR {

	NOTE_NON = -1,
	NOTE_BLUE,
	NOTE_YELLOW,
	NOTE_PINK,
	NOTE_VIOLET

};

struct Note {

	SDL_Texture *note_tex = nullptr;
	SDL_Rect note_rect = { 0, 0, 35, 35 };

	float scale = 0.1f;

	fPoint nPosition;

	Collider *note_collider = nullptr;

	NOTE_COLOR nColor = NOTE_NON;

};

struct Smasher {

	Collider* smasher_collider = nullptr;
	SDL_Rect smasher_rect;
};

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

private:

	SDL_Texture* guitar_tex;

	SDL_Rect Bottom_Limit;
	Collider* Bottom_coll;

	//Notes
	//Note *violet_note;
	//Note *blue_note;
	//Note *yellow_note;
	//Note *pink_note;

	//Note Smashers
	Smasher smBlue;
	Smasher smPink;
	Smasher smViolet;
	Smasher smYellow;

	//Notes attributes
	fPoint nVelocity = fPoint(0.27f, 1.0f);
	fPoint nIpos = fPoint(825.0f, 82.0f);

	void OnCollision(Collider *c1, Collider *c2);
	Note* CreateNote(fPoint pos, int note_num, NOTE_COLOR color);
	Smasher CreateSmasher(int smasher_num, COLLIDER_TYPE smasher_collider);
	void MoveNote(Note* note);

};

#endif