struct Entry_001F28F8 {
    int m_id;
    int m_done;
};

struct Obj_001F28F8 {
    char pad[0x148];
    Entry_001F28F8 m_entries[19];
    char pad1E0[8];
    int m_cur;
    int m_count;
};

extern "C" int func_001F1268(void* arg, int id);
extern "C" void func_001F1478(Obj_001F28F8* o);
extern "C" void func_001F2890(Obj_001F28F8* o, void* arg);

extern "C" void func_001F28F8(Obj_001F28F8* o, void* arg)
{
    do {
        if (!o->m_count)
            break;
        int i = o->m_cur;
        if (o->m_entries[i].m_done)
            break;
        if (!func_001F1268(arg, o->m_entries[i].m_id))
            break;
        func_001F1478(o);
    } while (1);
    func_001F2890(o, arg);
}
