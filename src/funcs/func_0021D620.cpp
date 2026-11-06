struct Vec_0021D620 {
    float x, y, z, w;
};

struct Obj_0021D620 {
    char m_pad0[0xB0];
    Vec_0021D620 m_vel;
};

extern void* D_0038FC78;

extern "C" float sqrtf(float);
extern "C" bool func_001E7EB0(void* params, int name, float* out, int required);
extern "C" Obj_0021D620* func_0022DD38(void* mgr);

bool Cmd_0021D620(void* params)
{
    float d;
    if (!func_001E7EB0(params, 0, &d, 0))
        return false;
    Obj_0021D620* o = func_0022DD38(D_0038FC78);
    if (!o)
        return false;
    Vec_0021D620* v = &o->m_vel;
    if (d < sqrtf(v->x * v->x + v->y * v->y + v->z * v->z))
        return true;
    return false;
}
