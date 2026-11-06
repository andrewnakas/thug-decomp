extern "C" float sqrtf(float);
extern void* D_00392068;
extern float D_003911A0;

struct V4_002789E8 {
    float x, y, z, w;
    V4_002789E8() {}
    V4_002789E8(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    void Set(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

struct Body_002789E8 {
    char pad[0x50];
    V4_002789E8 m50;
};

struct Obj_002789E8;
extern "C" Body_002789E8* func_002A8498(void* net);
extern "C" V4_002789E8 func_00279D88(Obj_002789E8* self);

struct Obj_002789E8 {
    int m0;
    bool InRange();
};

bool Obj_002789E8::InRange()
{
    Body_002789E8* b = func_002A8498(D_00392068);
    V4_002789E8 d;
    V4_002789E8 p = func_00279D88(this);
    d.Set(p.x - b->m50.x, p.y - b->m50.y, p.z - b->m50.z, p.w - b->m50.w);
    if (sqrtf(d.x * d.x + d.y * d.y + d.z * d.z) < D_003911A0)
        return true;
    return false;
}
