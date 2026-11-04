struct Obj_001EE948 {
    char pad0[0x14];
    void* m14;
    void* m18;
    void* Find(unsigned int name);
};

extern "C" bool func_001E87F0(void* s, unsigned int name);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AC8(void* dst, unsigned int src);

void* Obj_001EE948::Find(unsigned int name)
{
    void* s = 0;
    if (name) {
        if ((m14 && func_001E87F0(m14, name)) || (m18 && func_001E87F0(m18, name))) {
            s = func_001E6978(func_001190D0(8));
            func_001E6AC8(s, name);
        }
    }
    return s;
}
