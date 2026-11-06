struct Obj_001F0D00 {
    char m_pad0[0xCC];
    int m_flags;
    int mD0;
};

extern "C" Obj_001F0D00* func_001EE410(Obj_001F0D00* prev);

extern "C" Obj_001F0D00* func_001F0D00(int key)
{
    Obj_001F0D00* o = func_001EE410(0);
    while (o) {
        Obj_001F0D00* next = func_001EE410(o);
        if ((o->m_flags & 1) && o->mD0 == key)
            return o;
        o = next;
    }
    return 0;
}
