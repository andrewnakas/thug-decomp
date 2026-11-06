struct Obj_001F0E08 {
    char m_pad0[0xC8];
    int mC8;
};

extern "C" Obj_001F0E08* func_001EE410(Obj_001F0E08* prev);
extern "C" int func_001F00E8(Obj_001F0E08* o, int key);
extern "C" void func_001EE9E0(Obj_001F0E08* o);
extern "C" void func_001EEB60(Obj_001F0E08* o);

extern "C" void func_001F0E08(int key, int owner)
{
    for (Obj_001F0E08* o = func_001EE410(0); o; o = func_001EE410(o)) {
        if (func_001F00E8(o, key) && (!owner || o->mC8 == owner)) {
            func_001EE9E0(o);
            func_001EEB60(o);
        }
    }
}
