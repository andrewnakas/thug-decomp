extern char D_0037BDC0[];
extern char D_0037B770[];
extern "C" int func_00336228(char* a, char* b);
extern "C" void func_001F0370(char* s, int a, int b, int c);

struct Data_002D1050 {
    char pad0[0x18];
    char m18[0x40];
    int m58;
    int m5C;
    int m60;
};

struct Node_002D1050 {
    int m0;
    Data_002D1050* data;
    int m8;
    Node_002D1050* next;
    Data_002D1050* GetData() { return data; }
    Node_002D1050* Valid() { return (int)data != -1 ? this : 0; }
};

struct It_002D1050 {
    int m0;
    Node_002D1050* cur;
    void* vt;
    It_002D1050() { vt = D_0037BDC0; cur = 0; }
    ~It_002D1050() { vt = D_0037BDC0; }
    Data_002D1050* Next() {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Data_002D1050* First(Node_002D1050* h) {
        cur = h;
        return Next();
    }
};

struct Obj_002D1050 {
    char pad0[0x18];
    Node_002D1050 m18;
};

extern "C" void func_002D0198(Obj_002D1050* o, Data_002D1050* d);

void func_002D1050(void* a, void* b, char* name, void* c, int v, Obj_002D1050* o)
{
    It_002D1050 it;
    if (!name) return;
    for (Data_002D1050* d = it.First(&o->m18); d; d = it.Next()) {
        if (!func_00336228(d->m18, name)) {
            if (!d->m58) d->m58 = v;
            d->m60 = 1;
            func_002D0198(o, d);
            func_001F0370(D_0037B770, 0, 0, 0);
            break;
        }
    }
}
