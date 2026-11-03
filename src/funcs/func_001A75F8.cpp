struct Vec1A75F8 {
    float x, y, z, w;
};

struct Params1A75F8;
struct Obj1A75F8;
extern "C" int func_001E8398(Params1A75F8* p, unsigned int name, int* out, int required);
extern "C" void* func_00229668(int id, int a);
extern "C" void func_0022A090(void* o, Vec1A75F8* out);
extern "C" void func_001A6CA0(Obj1A75F8* o, Params1A75F8* p, Vec1A75F8* v);

struct Obj1A75F8 {
    void MoveTo(Params1A75F8* params);
};

void Obj1A75F8::MoveTo(Params1A75F8* params)
{
    int id = 0;
    func_001E8398(params, 0xA1DC81F9, &id, 0);
    if (id) {
        Vec1A75F8 pos;
        func_0022A090(func_00229668(id, 1), &pos);
        func_001A6CA0(this, params, &pos);
    }
}
