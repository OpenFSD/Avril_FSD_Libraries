#pragma once

namespace Avril_FSD
{
	class Praise1_Input
	{
	public:
		Praise1_Input();
		virtual ~Praise1_Input();

		float Get_mouse_delta_X();
		float Get_mouse_delta_Y();

		void Set_mouse_delta_X(float value);
		void Set_mouse_delta_Y(float value);
	};
}