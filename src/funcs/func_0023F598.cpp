struct Item_0023F598 {
    char m_pad[0x14];
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual bool IsA();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual bool IsB();
};

struct List_0023F598;

struct Obj_0023F598;
extern "C" int func_0023C040(Obj_0023F598* self);
extern "C" Item_0023F598* func_00243C18(List_0023F598* list, int* idx, int* out);

struct Obj_0023F598 {
    int m0;
    char m4[4];
    bool Check();
};

bool Obj_0023F598::Check()
{
    int n = func_0023C040(this);
    int tmp;
    for (int i = 0; i < n; i++) {
        Item_0023F598* it = func_00243C18((List_0023F598*)m4, &i, &tmp);
        if (it->IsA() && it->IsB())
            return true;
    }
    return false;
}
