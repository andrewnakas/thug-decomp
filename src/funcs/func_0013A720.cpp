extern "C" int func_001E8398(void* params, unsigned int id, unsigned int* out, int req);
extern "C" int func_001E8708(void* params, unsigned int id);
extern "C" void* func_00139468(void* node, unsigned int id);
extern "C" void func_00139410(void* node, unsigned int key, void* a, void* b, bool f);
extern "C" void func_00138970(void* a, void* b, bool f);
extern void* D_00393EF4;

bool Cmd_0013A720(void* params, void* script)
{
    unsigned int a;
    unsigned int b;
    unsigned int key = 0;
    func_001E8398(params, 0x9FBBDB72, &a, 0);
    func_001E8398(params, 0xE126E035, &b, 0);
    func_001E8398(params, 0x941CBBBA, &key, 0);
    bool f = !func_001E8708(params, 0x5905256B);
    void* p = func_00139468(D_00393EF4, a);
    if (p) {
        void* q = func_00139468(D_00393EF4, b);
        if (q) {
            if (key)
                func_00139410(D_00393EF4, key, p, q, f);
            else
                func_00138970(p, q, f);
        }
    }
    return true;
}
