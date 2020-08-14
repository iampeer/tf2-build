#include "movement_recorder.h"

c_movement_recorder g_movement_recorder;

void c_movement_recorder::record_movement(user_cmd* cmd, c_baseentity* ent)
{
	// record
	if (GetAsyncKeyState(VK_XBUTTON1)) 
	{
		movement_record record{
			cmd->forward_move, cmd->side_move, cmd->up_move,
			cmd->viewangles, ent->get_abs_origin(),
			cmd->buttons
		};

		records.emplace_back(record);
	}

	// reproduce
	if (GetAsyncKeyState(VK_XBUTTON2))
	{
		vector3d eye_pos = ent->get_eye_position();
		vector3d dest = records[0].abs_origin;

		if (dest.is_null())
		{
			return;
		}
		
		float distance = vector3d_distance(dest, eye_pos);

		if (distance > 1.f)
		{
			vector3d ang;
			vector3d fwrd = dest - eye_pos;

			vector3d_angles(fwrd, ang);

			cmd->viewangles = ang;
			cmd->forward_move = distance;
		}
	}

	// clear
	if (GetAsyncKeyState(VK_DELETE))
	{
	
	}
};