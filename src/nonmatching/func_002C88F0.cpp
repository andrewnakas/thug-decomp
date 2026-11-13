/* fuzzy: 84.6 */
struct Box_002C88F0 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    void Set(unsigned char px, signed char py, unsigned char pz, unsigned char pw, unsigned char ph, unsigned char pd)
    {
        x = px; y = py; z = pz; w = pw; h = ph; d = pd;
    }
    void SetRange(int x0, int z0, int x1, int z1)
    {
        Set(x0, 0, z0, x1 - x0 + 1, 1, z1 - z0 + 1);
    }
};

struct Obj_002C88F0 {
    char pad0[0x54];
    unsigned char m54;
    void GetBox(Box_002C88F0* out);
};

extern "C" void func_002C88A0(Obj_002C88F0* self, unsigned char* a, unsigned char* b, unsigned char* c, unsigned char* d);

void Obj_002C88F0::GetBox(Box_002C88F0* out)
{
    if (!m54) {
        out->Set(0, 0, 0, 0, 0, 0);
        return;
    }
    unsigned char x0, z0, x1, z1;
    func_002C88A0(this, &x0, &z0, &x1, &z1);
    out->SetRange(x0, z0, x1, z1);
}
