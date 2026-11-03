extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);

struct Vec_001367E0 {
    float x, y, z, w;
    void RotateX(float a)
    {
        float s = func_00341068(a);
        float c = func_00340F60(a);
        float ty = y;
        float tz = z;
        y = c * ty - s * tz;
        z = s * ty + c * tz;
    }
    void RotateY(float a)
    {
        float s = func_00341068(a);
        float c = func_00340F60(a);
        float tx = x;
        float tz = z;
        x = c * tx + s * tz;
        z = -s * tx + c * tz;
    }
};

extern "C" int func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" int func_001E7EB0(void* params, unsigned int key, float* out, int required);
extern "C" int func_001E7FA8(void* params, unsigned int key, Vec_001367E0* out, int required);
extern "C" int func_00135E50(int idx, Vec_001367E0* dir);

extern "C" int func_001367E0(void* params)
{
    int idx;
    func_001E7DE8(params, 0x7F8C98FE, &idx, 0);
    Vec_001367E0 dir;
    dir.x = 0.0f;
    dir.y = 0.0f;
    dir.z = 1.0f;
    dir.w = 0.0f;
    if (func_001E7FA8(params, 0xC1B52E4C, &dir, 0)) {
        dir.w = 0.0f;
    } else {
        float heading;
        float pitch;
        if (func_001E7EB0(params, 0xFD4BC03E, &heading, 0) && func_001E7EB0(params, 0xD8604126, &pitch, 0)) {
            dir.RotateX(pitch * 0.01745329425f);
            dir.RotateY(heading * 0.01745329425f);
        }
    }
    return func_00135E50(idx, &dir);
}
