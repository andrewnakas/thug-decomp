extern "C" void* func_0023AFE8(void* arr, int i);
extern "C" int func_00104328(void* a, int b);

struct Obj_00239B88 {
    char pad0[0x44];
    char m_44[0x14];
    int m_58;
    int Count(int key);
};

int Obj_00239B88::Count(int key)
{
    int n = 0;
    for (int i = 0; i < m_58; i++) {
        char* e = (char*)func_0023AFE8(m_44, i);
        if (func_00104328(e + 0x1C, key)) {
            n++;
        }
    }
    return n;
}
