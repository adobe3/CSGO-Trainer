#pragma once

#include "../../Stdafx.h"

namespace Math 
{
    struct Vector3
    {
        float x, y, z;
    };

    struct view_matrix_t
    {
        float matrix[16];
    };

    struct Vector3 WorldToScreen(const struct Vector3 pos, struct view_matrix_t matrix);
}