struct Obj_001F0460 {
    char pad[0xCC];
    int m_flags;
};
extern "C" Obj_001F0460* func_001EE410(Obj_001F0460* prev);

extern "C" void func_001F0460(int on)
{
    for (Obj_001F0460* o = func_001EE410(0); o; o = func_001EE410(o)) {
        if (o->m_flags & 1)
            o->m_flags = (o->m_flags & ~4) | ((on & 1) << 2);
    }
}
