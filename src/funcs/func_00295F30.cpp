struct Params_00295F30 { char pad[0x10]; };
struct Vec_00295F30 {
    float x, y, z, w;
    Vec_00295F30(float a, float b, float c) { x = a; y = b; z = c; w = 1.0f; }
};
struct Info_00295F30 { char pad[0x7C]; float m7C; };
struct Obj_00295F30 {
    char pad[0xA5C8];
    Info_00295F30* mA5C8;
    void Send();
};

extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int v);
extern "C" void func_00295AF0(Obj_00295F30* o, Vec_00295F30* v, float* a, float* b);
extern "C" void func_001E7410(void* s, unsigned int name, float x, float y, float z);
extern "C" void func_001E72B0(void* s, unsigned int name, float f);
extern "C" void func_001F0210(unsigned int, void*, int, int, int);

void Obj_00295F30::Send()
{
    Params_00295F30 s;
    func_001E6978(&s);
    Vec_00295F30 v(0.0f, 0.0f, 0.0f);
    float a = 0.0f;
    float b = 0.0f;
    func_00295AF0(this, &v, &a, &b);
    v.y += a;
    func_001E7410(&s, 0x7F261953, v.x, v.y, v.z);
    func_001E72B0(&s, 0xFF7EBAF6, mA5C8->m7C);
    func_001F0210(0xDEA7FE56, &s, 0, 0, 0);
    func_001E6AE8(&s, 2);
}
