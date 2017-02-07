//-----------------------------------------------------------------------------
// OpenBlockCraft -- A 3D block based game
// Copyright(C) 2017 Jeff Hutchinson
//
// This program is free software : you can redistribute it and / or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>
//-----------------------------------------------------------------------------

#include "noise.hpp"

Noise::Noise()
{
	mSeed = 0;
	mContext = nullptr;
}

Noise::~Noise()
{
	if (mContext != nullptr)
	{
		open_simplex_noise_free(mContext);
		mContext = nullptr;
	}
}

void Noise::setSeed(const int64_t seed)
{
	if (mContext != nullptr)
	{
		open_simplex_noise_free(mContext);
		mContext = nullptr;
	}
	open_simplex_noise(seed, &mContext);
}

double Noise::noise2(double x, double y)
{
	return open_simplex_noise2(mContext, x, y);
}