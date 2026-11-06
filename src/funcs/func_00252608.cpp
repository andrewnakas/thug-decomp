struct Obj_00252608 {
    char pad[0x10];
    char m_name[0x400];
    unsigned int m_len[1];
};

extern "C" char* func_00331A9C(char* dst, const char* src);
extern "C" unsigned int func_00331BB8(const char* s);
extern "C" void func_00104028(void* str, const char* s);

extern "C" void* func_00252608(void* ret, Obj_00252608* o, int idx)
{
    char buf[256];
    func_00331A9C(buf, o->m_name);
    for (unsigned int i = 0; i < func_00331BB8(buf); i++) {
        if (i >= o->m_len[idx])
            buf[i] = '-';
    }
    func_00104028(ret, buf);
    return ret;
}
