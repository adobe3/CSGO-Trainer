#include "../Utilities.h"

 Utilities::Vector3 Utilities::WorldToScreen(const struct Vector3 pos, struct view_matrix_t matrix) 
 {
    Vector3 out;
    float _x = matrix.matrix[0] * pos.x + matrix.matrix[1] * pos.y + matrix.matrix[2] * pos.z + matrix.matrix[3];
    float _y = matrix.matrix[4] * pos.x + matrix.matrix[5] * pos.y + matrix.matrix[6] * pos.z + matrix.matrix[7];
    out.z = matrix.matrix[12] * pos.x + matrix.matrix[13] * pos.y + matrix.matrix[14] * pos.z + matrix.matrix[15];

    _x *= 1.f / out.z;
    _y *= 1.f / out.z;

    RECT rect;
    GetWindowRect(FindWindowA(NULL, skCrypt("Counter-Strike: Global Offensive - Direct3D 9")), &rect);

    int width = rect.right - rect.left;
    int height = rect.bottom + rect.left;

    out.x = width * .5f;
    out.y = height * .5f;

    out.x += 0.5f * _x * width + 0.5f;
    out.y -= 0.5f * _y * height + 0.5f;

    return out;
}