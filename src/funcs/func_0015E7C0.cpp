struct Target_0015E7C0 {
    char pad0[0x50];
    float x;
    float y;
    float z;
};

extern void* D_0038FC78;
extern "C" Target_0015E7C0* func_0022DE70(void* p, int a);

struct Obj_0015E7C0 {
    char pad0[0x28];
    int m28;
    int m2C;
    char pad30[0x44 - 0x30];
    int m44;
    char pad48[0x490 - 0x48];
    unsigned char m490[0x400];
    void Update();
};

extern "C" void func_0015DE88(Obj_0015E7C0* self, float x, float z);
extern "C" void func_0015D8A0(Obj_0015E7C0* self, float x, float z);
extern "C" void func_0015CF50(Obj_0015E7C0* self, float x, float z);

void Obj_0015E7C0::Update()
{
    if (!m2C)
        return;
    Target_0015E7C0* t = func_0022DE70(D_0038FC78, 0);
    if (!t)
        return;
    float x = t->x;
    float z = t->z;
    if (m44) {
        func_0015DE88(this, x, z);
        func_0015D8A0(this, x, z);
    } else {
        func_0015CF50(this, x, z);
    }
    if (!m28)
        return;
    for (int i = 0; i < 0x400; i++) {
        if (m490[i] != 0xFE) {
            if (m490[i] != 0xFF)
                goto inc;
            continue;
        }
        m28--;
    inc:
        m490[i]++;
    }
}
