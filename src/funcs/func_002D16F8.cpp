extern char D_0037BDC0[];
extern char D_00392B40[];
extern char D_00392B48[];
extern char D_0037B9C0[];

struct Rec_002D16F8 {
    char pad[0x18];
    char name[0x44];
    int m5C;
};

struct Node_002D16F8 {
    int m0;
    Rec_002D16F8* data;
    int m8;
    Node_002D16F8* next;
    Rec_002D16F8* GetData() { return data; }
    Node_002D16F8* Valid(unsigned k = 0) { return k < ~(unsigned)data ? this : 0; }
};

struct It_002D16F8 {
    int m0;
    Node_002D16F8* cur;
    void* vt;
    It_002D16F8() { vt = D_0037BDC0; }
    ~It_002D16F8() { vt = D_0037BDC0; }
    Rec_002D16F8* Next()
    {
        cur = cur->next->Valid();
        if (!cur)
            return 0;
        return cur->GetData();
    }
    Rec_002D16F8* First(Node_002D16F8* h)
    {
        cur = h;
        return Next();
    }
};

struct List_002D16F8 {
    char pad[0x18];
    Node_002D16F8 head;
};

struct Params_002D16F8;
extern "C" int func_00336228(char* a, char* b);
extern "C" int func_00334120(char* s);
extern "C" void* func_001190D0(int size);
extern "C" Params_002D16F8* func_001E6978(void* mem);
extern "C" int func_001F0D78(char* s);
extern "C" void func_001E73C8(Params_002D16F8* p, char* name, int v);
extern "C" void func_001E7268(Params_002D16F8* p, char* name, int v);
extern "C" void func_001F0370(char* s, Params_002D16F8* p, int b, int c);
extern "C" void func_001E6AE8(Params_002D16F8* p, int flags);

extern "C" void func_002D16F8(void* a0, void* a1, char* name, void* a3, char* value, List_002D16F8* list)
{
    It_002D16F8 it;
    for (Rec_002D16F8* r = it.First(&list->head); r; r = it.Next()) {
        if (func_00336228(r->name, name))
            continue;
        int v = func_00334120(value);
        r->m5C = v;
        int rank = (int)(v * (1.0f / 290.0f));
        Params_002D16F8* p = func_001E6978(func_001190D0(8));
        func_001E73C8(p, D_00392B48, func_001F0D78(r->name));
        func_001E7268(p, D_00392B40, rank);
        func_001F0370(D_0037B9C0, p, 0, 0);
        if (p)
            func_001E6AE8(p, 3);
        break;
    }
}
