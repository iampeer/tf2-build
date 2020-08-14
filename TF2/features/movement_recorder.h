#pragma once

#include "../main.h"
#include <vector>

struct movement_record
{
	float forward_move, side_move, up_move;
	vector3d view_angles, abs_origin;
	int buttons;
};

class c_movement_recorder 
{
public:
	void record_movement(user_cmd* cmd, c_baseentity* ent);
	std::vector<movement_record> records;
private:

}; extern c_movement_recorder g_movement_recorder;

