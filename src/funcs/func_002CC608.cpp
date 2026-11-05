extern "C" void func_002B7188(void* p, int v);

struct Ent_002CC608 {
    char pad[0xC];
    void* mC;
    void* m10;
};

struct Mgr_002CC608 {
    int m0;
    Ent_002CC608* m4[32];
    void Show(int i);
};

void Mgr_002CC608::Show(int i)
{
    if (m4[i]) {
        if (m4[i]->mC)
            func_002B7188(m4[i]->mC, 1);
        if (m4[i]->m10)
            func_002B7188(m4[i]->m10, 1);
    }
}
