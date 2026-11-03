struct Node_002AB2E8 {
    int m0;
    int m4;
    int m8;
    Node_002AB2E8* mC;
    Node_002AB2E8* Valid() { return m4 != -1 ? this : 0; }
    Node_002AB2E8* Next() { return mC->Valid(); }
};

struct Ob_002AB2E8 {
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void Hide();
    virtual void Show();
};

struct List_002AB2E8 {
    Node_002AB2E8 head;
    unsigned int Count() {
        unsigned int n = 0;
        for (Node_002AB2E8* p = head.Next(); p; p = p->Next()) n++;
        return n;
    }
};

struct Game_002AB2E8 {
    char pad[0x30];
    List_002AB2E8 m30;
};

extern Game_002AB2E8* D_0038FC78;
extern char D_00378BC8[];
extern "C" void* func_0022E358(void* p);
extern "C" int func_0024F8D8(void* p, char* s);
extern "C" Ob_002AB2E8* func_0022DE70(Game_002AB2E8* g, int i);

struct Obj_002AB2E8 {
    char pad[0x160];
    int m160;
    void SetVisible(int v);
};

void Obj_002AB2E8::SetVisible(int v)
{
    if (v == m160) return;
    m160 = v;
    if (func_0024F8D8(func_0022E358(D_0038FC78), D_00378BC8)) return;
    if (m160) {
        Game_002AB2E8* g = D_0038FC78;
        unsigned int n = g->m30.Count();
        for (unsigned int i = 0; i < n; i++) {
            Ob_002AB2E8* o = func_0022DE70(g, i);
            if (o) o->Show();
        }
    } else {
        Game_002AB2E8* g = D_0038FC78;
        unsigned int n = g->m30.Count();
        for (unsigned int i = 0; i < n; i++) {
            Ob_002AB2E8* o = func_0022DE70(g, i);
            if (o) o->Hide();
        }
    }
}
