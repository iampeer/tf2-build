#ifndef IVDEBUGOVERLAY_H
#define IVDEBUGOVERLAY_H
#ifdef _WIN32
#pragma once
#endif

class ivdebugoverlay
{
public:

	int screen_position(const vector3d& in, vector3d& out)
	{
		using original_fn = int(__thiscall*)(PVOID, const vector3d&, vector3d&);
		return u::call_vfunc<original_fn>(this, 10)(this, in, out);
	}

};

#endif // !IVDEBUGOVERLAY_H