extern char D_00362480[];
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_001E7DE8(void* params, unsigned int name, int* out, int req);
extern "C" int func_001E8398(void* params, unsigned int name, unsigned int* out, int req);
extern "C" int func_001E7E58(void* params, const char* name, int* out, int req);
extern "C" void* func_001DC428(unsigned int id);
extern "C" void* func_0026C3E0(unsigned int id);

struct Obj_001A3DA0;
extern "C" int func_001A3D70(Obj_001A3DA0* o);
extern "C" int func_001DF490(Obj_001A3DA0* o, unsigned int name, float e, float a, float b, int c, int flag, void* obj, unsigned int d);

struct Obj_001A3DA0 {
    char pad[0x28];
    void* m28;
    int Method(void* params);
};

int Obj_001A3DA0::Method(void* params)
{
    if (!func_001A3D70(this))
        return 0;
    float a;
    float b;
    int c;
    unsigned int d;
    float e;
    void* obj = 0;
    d = 0;
    e = 0.0f;
    a = 100.0f;
    b = 100.0f;
    c = 50;
    func_001E7EB0(params, 0xF6A36814, &a, 0);
    func_001E7EB0(params, 0xD8604126, &b, 0);
    func_001E7DE8(params, 0x9D5923D8, &c, 0);
    func_001E8398(params, 0x40C698AF, &d, 0);
    if (func_001E7EB0(params, 0xFF2020EC, &e, 0))
        e *= 12.0f;
    unsigned int id;
    if (func_001E8398(params, 0x0C6AC50A, &id, 0))
        obj = func_001DC428(id);
    unsigned int id2;
    if (func_001E8398(params, 0x8A7132CE, &id2, 0))
        m28 = func_0026C3E0(id2);
    else
        m28 = 0;
    unsigned int name;
    if (func_001E8398(params, 0, &name, 0)) {
        int flag = 1;
        func_001E7E58(params, D_00362480, &flag, 0);
        return func_001DF490(this, name, e, a, b, c, flag, obj, d) != 0;
    }
    return 0;
}
