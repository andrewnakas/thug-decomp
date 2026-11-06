extern "C" void* func_0010FAC8();
extern "C" float func_0033E9B8(void* p);

struct V4_00279D18 {
    float x, y, z, w;
    V4_00279D18() {}
    V4_00279D18(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
};

struct Body_00279D18 {
    char pad[0xB0];
    V4_00279D18 mB0;
};

struct Obj_00279D18 {
    char pad[0xC];
    Body_00279D18* mC;
    V4_00279D18 Get();
};

V4_00279D18 Obj_00279D18::Get()
{
    Body_00279D18* b = mC;
    float s = func_0033E9B8(func_0010FAC8());
    return V4_00279D18(b->mB0.x * s, b->mB0.y * s, b->mB0.z * s, b->mB0.w * s);
}
