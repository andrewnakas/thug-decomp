extern char D_00379E70[];

struct Srv_002B4F10 {
    char pad[0x18];
    char m18[0x10];
    int m28;
};

struct Node_002B4F10 {
    int m0;
    Srv_002B4F10* data;
    int m8;
    Node_002B4F10* next;
    int m10;
    Srv_002B4F10* GetData() { return data; }
    Node_002B4F10* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002B4F10 {
    int m0;
    Node_002B4F10* cur;
    void* vt;
    It_002B4F10() { vt = D_00379E70; cur = 0; }
    ~It_002B4F10() { vt = D_00379E70; }
    Srv_002B4F10* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Srv_002B4F10* First(Node_002B4F10* h)
    {
        cur = h;
        return Next();
    }
};

struct Mgr_002B4F10 {
    char pad[0x124];
    Node_002B4F10 m124;
    char pad138[4];
    Node_002B4F10 m13C;
};

extern "C" int func_00336228(char* a, char* b);

extern "C" int func_002B4F10(Mgr_002B4F10* m, char* name, int addr)
{
    It_002B4F10 it;
    Srv_002B4F10* s;
    for (s = it.First(&m->m124); s; s = it.Next()) {
        if (s->m28 == addr && !func_00336228(s->m18, name))
            return 1;
    }
    for (s = it.First(&m->m13C); s; s = it.Next()) {
        if (s->m28 == addr && !func_00336228(s->m18, name))
            return 1;
    }
    return 0;
}
