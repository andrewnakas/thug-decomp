struct Item_001A5438 {
    char pad0[0xA4];
    int mA4;
};

extern "C" void func_001EE5E8(Item_001A5438* o);

struct Obj_001A5438 {
    char pad0[0x1C];
    unsigned int m1C;
    char pad20[0x34 - 0x20];
    float m34;
    void Fn(Item_001A5438* o);
};

extern "C" int func_001A5620(Obj_001A5438* self);
extern "C" int func_001A5630(Obj_001A5438* self);

void Obj_001A5438::Fn(Item_001A5438* o)
{
    int ok;
    switch (o->mA4) {
    case 4:
        ok = func_001A5620(this);
        break;
    case 6:
        ok = m1C & 0x100;
        break;
    case 8:
        ok = func_001A5630(this);
        break;
    case 7:
        goto check7;
    default:
        return;
    }
    if (!ok)
        func_001EE5E8(o);
    return;
check7:
    if (m34 <= 0.0f)
        func_001EE5E8(o);
}
