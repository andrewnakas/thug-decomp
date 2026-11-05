struct Obj_0029A2C8;
extern "C" void func_0029A218(Obj_0029A2C8* o);

struct Obj_0029A2C8 {
    char pad0[0x38];
    char m38[4];
    char* Name();
};

char* Obj_0029A2C8::Name()
{
    func_0029A218(this);
    return m38;
}
