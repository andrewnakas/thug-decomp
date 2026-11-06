struct Vec_001E8998 {
    int m0;
    float x;
    float y;
};

extern "C" int func_001E8090(void* params, unsigned int name, float* x, float* y, bool required);

extern "C" int func_001E8998(void* params, unsigned int name, Vec_001E8998* out, int required)
{
    float x;
    float y;
    y = x = 0.0f;
    int found = func_001E8090(params, name, &x, &y, required != 0);
    out->x = x;
    out->y = y;
    return found;
}
