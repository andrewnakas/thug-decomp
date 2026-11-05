struct Obj_002C8CC8;
extern "C" void func_002C74D8(Obj_002C8CC8* o);
extern "C" int func_002C8CA0(Obj_002C8CC8* o, int v);

struct Obj_002C8CC8 {
    char pad0[0x6C];
    int m6C;
    void Set(int v);
};

void Obj_002C8CC8::Set(int v)
{
    func_002C74D8(this);
    m6C = func_002C8CA0(this, v);
}
