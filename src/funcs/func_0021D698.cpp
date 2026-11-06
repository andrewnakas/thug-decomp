extern "C" float sqrtf(float);

struct Vec_0021D698 {
    float x, y, z, w;
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Obj_0021D698 {
    char pad[0xB0];
    Vec_0021D698 m_pos;
};

extern void* D_0038FC78;
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" Obj_0021D698* func_0022DD38(void* mgr);

extern "C" bool func_0021D698(void* params, void* script)
{
    float dist;
    if (!func_001E7EB0(params, 0, &dist, 0))
        return false;
    Obj_0021D698* o = func_0022DD38(D_0038FC78);
    if (o) {
        Vec_0021D698* v = &o->m_pos;
        if (v->Length() < dist)
            return true;
    }
    return false;
}
