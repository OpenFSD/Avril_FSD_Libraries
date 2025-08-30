#pragma once

namespace Avril_FSD
{
	class Praise1_Output
	{
	public:
		Praise1_Output();
		virtual ~Praise1_Output();
		std::vector<float> GetFowards();
		std::vector<float> GetUp();
		std::vector<float> GetRight();
		void SetFowards(std::vector<float> fowards);
		void SetUp(std::vector<float> up);
		void SetRight(std::vector<float> right);
	};
}