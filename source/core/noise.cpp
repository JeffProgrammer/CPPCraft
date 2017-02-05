//-----------------------------------------------------------------------------
// noise.cpp
//
// Copyright(c) 2017 Jeff Hutchinson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
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