struct Slot_002BBF60 {
    char pad0[8];
    void* m8;
};

struct Mgr_002BBF60 {
    void* m0;
};

struct Obj_002BBF60;
extern "C" Slot_002BBF60* func_002BB3B0(Obj_002BBF60* o, int idx);
extern "C" Mgr_002BBF60* func_002C0368();
extern "C" int func_002B7740(void* a, void* key, int c);

struct Obj_002BBF60 {
    char pad0[0x30];
    unsigned int m30;
    int Select(int i);
};

int Obj_002BBF60::Select(int i)
{
    if (!(i < m30 && i >= 0))
        return 0;
    void* sel = func_002C0368()->m0;
    return func_002B7740(sel, func_002BB3B0(this, i)->m8, 0);
}
