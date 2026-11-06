struct Item_001A06C8 {
    char pad0[0xA4];
    int mA4;
};

struct Obj_001A06C8 {
    void Fn(Item_001A06C8* o);
};

extern "C" int func_001A0D78(Obj_001A06C8* self, Item_001A06C8* o);
extern "C" void func_001EE5E8(Item_001A06C8* o);

void Obj_001A06C8::Fn(Item_001A06C8* o)
{
    if (o->mA4 == 5 && func_001A0D78(this, o))
        func_001EE5E8(o);
}
