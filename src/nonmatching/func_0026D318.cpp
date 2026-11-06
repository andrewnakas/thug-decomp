/* fuzzy: 94.5 */
extern "C" void* func_001190D0(int n);
extern "C" void* func_001E6978(void* p);
extern "C" void func_001E6AE8(void* p, int n);
extern "C" void func_001E7200(void* s, unsigned int id, int v);
extern "C" void func_001E70C0(void* s, unsigned int id, int v);
extern "C" unsigned int func_001F0D78(const char* s);
extern "C" void func_001F0210(unsigned int name, void* params, int a, int b, int c);
extern "C" int func_0026CBA0(void* p);
extern "C" void* func_00240850();
extern "C" int func_0023CFF0(void* o);
extern "C" void func_0023D0A8(void* o, int i);
extern "C" int func_0026CB68(void* p);
extern "C" int func_0026CBB0(void* p);
extern "C" void func_0026CB70(void* p);
extern "C" void func_0026CB98(void* p);
extern char D_003762E0[];

struct Node_0026D318 {
    int m0;
    int m4;
    int m8;
    Node_0026D318* mC;
    Node_0026D318* Valid()
    {
        Node_0026D318* r = 0;
        if (m4 != -1)
            r = this;
        return r;
    }
};

struct List_0026D318 {
    char pad[0x10];
    Node_0026D318* m10;
    void Run();
};

void List_0026D318::Run()
{
    char count = 0;
    int i = 0;
    for (Node_0026D318* n = m10->Valid(); n; n = n->mC->Valid()) {
        if (func_0026CBA0(n)) {
            void* o = func_00240850();
            if (func_0023CFF0(o))
                func_0023D0A8(o, i);
            if (!func_0026CB68(n)) {
                count++;
                void* params = func_001E6978(func_001190D0(8));
                if (count >= 2)
                    func_001E7200(params, func_001F0D78(D_003762E0), count);
                func_001E70C0(params, 0xC69CE365, func_0026CBB0(n));
                func_001F0210(0x318EAF64, params, 0, 0, 0);
                if (params)
                    func_001E6AE8(params, 3);
            }
            func_0026CB70(n);
        }
        func_0026CB98(n);
        i++;
    }
}
