extern char D_0037BEC0[];

struct Data_002D6290 {
    char pad[0x1C];
    char m1C[4];
};

struct Node_002D6290 {
    int m0;
    Data_002D6290* data;
    Node_002D6290* prev;
    Node_002D6290* next;
    Data_002D6290* GetData() { return data; }
    Node_002D6290* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct It_002D6290 {
    int m0;
    Node_002D6290* cur;
    Data_002D6290* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D6290* First(Node_002D6290* h) {
        cur = h;
        return Next();
    }
};

struct Mgr_002D6290 {
    char pad[0x350];
    Node_002D6290 m350;
    char pad360[0x368 - 0x360];
    It_002D6290 m368;
    char pad370[0x374 - 0x370];
    Data_002D6290* m374;
};

struct Net_002D6290 {
    char pad[8];
    Mgr_002D6290* m8;
};

struct Script_002D6290 {
    char pad[0x18];
    void* m18;
};

extern Net_002D6290* D_00392068;
extern "C" void func_001E7138(void* p, char* name, char* value);

extern "C" bool func_002D6290(void* params, Script_002D6290* s)
{
    Mgr_002D6290* m = D_00392068->m8;
    m->m374 = m->m368.Next();
    if (!m->m374)
        m->m374 = m->m368.First(&m->m350);
    func_001E7138(s->m18, D_0037BEC0, m->m374->m1C);
    return true;
}
