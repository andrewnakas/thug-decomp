struct Vec_00229CC8 {
    float x, y, z, w;
    Vec_00229CC8() {}
    Vec_00229CC8(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}
};

struct Array_00229CC8 {
    char pad[0xC];
    unsigned int m_size;
};

extern "C" Array_00229CC8* func_001E55B8(unsigned int key, int a);
extern "C" unsigned short* func_00229C20(unsigned int key, unsigned short* count);
extern "C" void* func_001E9378(Array_00229CC8* a, unsigned int i);
extern "C" bool func_001E7FA8(void* params, unsigned int key, Vec_00229CC8* out, int required);

int func_00229CC8(unsigned int key, Vec_00229CC8* target)
{
    int best = -1;
    float bestDist = 1e20f;
    Array_00229CC8* arr = func_001E55B8(0xC472ECC5, 0);
    unsigned short count = 0;
    unsigned short* p = func_00229C20(key, &count);
    while (count) {
        Vec_00229CC8 pos;
        func_001E7FA8(func_001E9378(arr, *p), 0x7F261953, &pos, 0);
        Vec_00229CC8 d(pos.x - target->x, pos.y - target->y, pos.z - target->z, pos.w - target->w);
        float dist = d.x * d.x + d.y * d.y + d.z * d.z;
        if (dist < bestDist) {
            best = *p;
            bestDist = dist;
        }
        p++;
        count--;
    }
    return best;
}
