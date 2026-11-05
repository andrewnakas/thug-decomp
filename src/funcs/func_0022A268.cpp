struct Vec_0022A268 {
    float x, y, z, w;
};

extern "C" bool func_001E7FA8(void* params, unsigned int name, Vec_0022A268* out, int required);

bool Get_0022A268(void* params, Vec_0022A268* out)
{
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 0.0f;
    out->w = 1.0f;
    return func_001E7FA8(params, 0x9D2D0915, out, 0);
}
