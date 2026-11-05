/* sym: _$_12Obj_001F0F28 = 0x001EE4D8 */
struct Obj_001F0F28 {
    char m_pad[0xCC];
    unsigned int m_flags;
    char m_padD0[0xC];
    int m_refs;
    ~Obj_001F0F28();
};

extern "C" Obj_001F0F28* func_001EE410(Obj_001F0F28* prev);
extern "C" bool func_001EE620(Obj_001F0F28* o);

extern "C" void func_001F0F28()
{
    Obj_001F0F28* o = func_001EE410(0);
    while (o) {
        Obj_001F0F28* next = func_001EE410(o);
        if (!func_001EE620(o) && (o->m_flags & 1) == 0 && !o->m_refs)
            delete o;
        o = next;
    }
}
