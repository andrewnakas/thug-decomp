struct Obj_001F0B50 {
    char pad0[0xCC];
    unsigned int mCC;
    int mD0;
};

extern "C" Obj_001F0B50* func_001EE410(Obj_001F0B50* o);
extern "C" bool func_001F00E8(Obj_001F0B50* o, unsigned int name);
extern "C" void func_001EE9E0(Obj_001F0B50* o);
extern "C" void func_001EEB60(Obj_001F0B50* o);

extern "C" void func_001F0B50(unsigned int name, int id, Obj_001F0B50* skip)
{
    Obj_001F0B50* o = func_001EE410(0);
    while (o) {
        Obj_001F0B50* next = func_001EE410(o);
        if ((o->mCC & 1) && o != skip && func_001F00E8(o, name) && o->mD0 == id) {
            func_001EE9E0(o);
            func_001EEB60(o);
        }
        o = next;
    }
}
