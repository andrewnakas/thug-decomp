extern "C" bool func_00201288(void* p);

struct Obj_002A19A8;
extern "C" bool func_002A1998(Obj_002A19A8* self);

struct Obj_002A19A8 {
    char pad[0x14];
    void* m14;
    void* m18;
    bool Busy();
};

bool Obj_002A19A8::Busy()
{
    if (!func_002A1998(this))
        return false;
    if (m14 && !func_00201288(m14))
        return true;
    if (m18 && !func_00201288(m18))
        return true;
    return false;
}
