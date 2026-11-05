struct Obj_001F0A18 {
    char m_pad[0xCC];
    unsigned int m_flags;
};

extern "C" Obj_001F0A18* func_001EE410(Obj_001F0A18* prev);
extern "C" bool func_001EFFE8(Obj_001F0A18* o, int arg);
extern "C" void func_001EE9E0(Obj_001F0A18* o);
extern "C" void func_001EEB60(Obj_001F0A18* o);

extern "C" void func_001F0A18(int arg)
{
    Obj_001F0A18* o = func_001EE410(0);
    while (o) {
        Obj_001F0A18* next = func_001EE410(o);
        if ((o->m_flags & 1) && func_001EFFE8(o, arg)) {
            func_001EE9E0(o);
            func_001EEB60(o);
        }
        o = next;
    }
}
