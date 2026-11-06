struct Obj_001F0AB0 {
    char m_pad0[0xAC];
    int mAC;
    char m_padB0[0xCC - 0xB0];
    int m_flags;
    int mD0;
};

extern "C" Obj_001F0AB0* func_001EE410(Obj_001F0AB0* prev);
extern "C" void func_001EE9E0(Obj_001F0AB0* o);
extern "C" void func_001EEB60(Obj_001F0AB0* o);

extern "C" void func_001F0AB0(int key)
{
    Obj_001F0AB0* o = func_001EE410(0);
    while (o) {
        Obj_001F0AB0* next = func_001EE410(o);
        if ((o->m_flags & 1) && (o->mD0 == key || o->mAC == key)) {
            func_001EE9E0(o);
            func_001EEB60(o);
        }
        o = next;
    }
}
