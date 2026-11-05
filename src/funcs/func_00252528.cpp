extern void* D_0038FC78;
extern "C" void* func_0022DF08(void* p, int i);
extern "C" unsigned int func_00331BB8(const char* s);

struct Obj_00252528 {
    char pad[0x10];
    char m10[0x400];
    unsigned int m410[8];
    bool Fn();
};

bool Obj_00252528::Fn()
{
    for (int i = 0; i < 8; i++) {
        if (func_0022DF08(D_0038FC78, i)) {
            if (m410[i] >= func_00331BB8(m10)) return true;
        }
    }
    return false;
}
