typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_00246A30 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00246A30() {}
    Vec_00246A30(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Obj_00246A30 {
    char pad0[0x50];
    Vec_00246A30 m50;
};

extern void* D_0038C608;
extern void* D_0038FC78;
extern "C" bool func_001E8398(void* params, unsigned int name, unsigned int* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int name, int* out, int required);
extern "C" void func_001E7200(void* params, unsigned int name, int value);
extern "C" Obj_00246A30* func_00187B48(void* self, unsigned int id);
extern "C" Obj_00246A30* func_0022DD38(void* self);

struct Cmd_00246A30 {
    char pad0[0x20];
    void* m20;
    bool Run();
};

bool Cmd_00246A30::Run()
{
    unsigned int id;
    func_001E8398(m20, 0x8E18F3B3, &id, 1);
    Obj_00246A30* o = func_00187B48(D_0038C608, id);
    Obj_00246A30* sk = func_0022DD38(D_0038FC78);
    if (sk) {
        if (o) {
            Vec_00246A30 d(o->m50.x - sk->m50.x, o->m50.y - sk->m50.y, o->m50.z - sk->m50.z, o->m50.w - sk->m50.w);
            float oy = o->m50.y;
            float dy = sk->m50.y - oy;
            float dist = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z - dy * dy);
            int inches = (int)dist;
            int feet = (int)(dist / 12.0f);
            int rem = inches % 12;
            func_001E7200(m20, 0xCB48C8E8, feet);
            func_001E7200(m20, 0x644FC146, rem);
            int best = 0;
            func_001E7DE8(m20, 0x78FFB85C, &best, 0);
            if ((float)best < dist) {
                func_001E7200(m20, 0x78FFB85C, inches);
                func_001E7200(m20, 0x24BF3AE4, feet);
                func_001E7200(m20, 0x9B49F28D, rem);
                return true;
            }
        }
    }
    return false;
}
