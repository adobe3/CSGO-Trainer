#pragma once

#include "../../Stdafx.h"

namespace Math 
{
    struct Vector3
    {
        float x, y, z;
    };

    struct ViewMatrix
    {
        float matrix[16];
    };

    struct Vector3 WorldToScreen(const struct Vector3 pos, struct ViewMatrix matrix);
}