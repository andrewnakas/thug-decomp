extern char D_0037BEC0[];

struct Data_002D6340 {
    char pad[0x1C];
    char m1C[4];
};

struct Node_002D6340 {
    int m0;
    Data_002D6340* data;
    int m8;
    int mC;
    Node_002D6340* next;
    Data_002D6340* GetData() { return data; }
    Node_002D6340* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct It_002D6340 {
    int m0;
    Node_002D6340* cur;
    Data_002D6340* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D6340* First(Node_002D6340* h) {
        cur = h;
        return Next();
    }
};

struct Mgr_002D6340 {
    char pad[0x350];
    Node_002D6340 m350;
    char pad364[0x368 - 0x364];
    It_002D6340 m368;
    char pad370[0x374 - 0x370];
    Data_002D6340* m374;
};

struct Net_002D6340 {
    char pad[8];
    Mgr_002D6340* m8;
};

struct Script_002D6340 {
    char pad[0x18];
    void* m18;
};

extern Net_002D6340* D_00392068;
extern "C" void func_001E7138(void* p, char* name, char* value);

extern "C" bool func_002D6340(void* params, Script_002D6340* s)
{
    Mgr_002D6340* m = D_00392068->m8;
    m->m374 = m->m368.Next();
    if (!m->m374)
        m->m374 = m->m368.First(&m->m350);
    func_001E7138(s->m18, D_0037BEC0, m->m374->m1C);
    return true;
}
