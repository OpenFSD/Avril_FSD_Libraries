#pragma once

namespace Avril_FSD
{
	class Praise1_Output
	{
	public:
		Praise1_Output();
		virtual ~Praise1_Output();
		std::array<float, 3> GetFowards();
		std::array<float, 3> GetUp();
		std::array<float, 3> GetRight();
		void SetFowards(std::array<float, 3> fowards);
		void SetUp(std::array<float, 3> up);
		void SetRight(std::array<float, 3> right);
	};
}