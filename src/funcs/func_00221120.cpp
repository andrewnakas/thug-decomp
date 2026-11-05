struct Node_00221120 {
    int m0;
    int data;
    int m8;
    Node_00221120* next;
    Node_00221120* Valid() { if (~data == 0) return 0; return this; }
    unsigned int Count()
    {
        unsigned int n = 0;
        Node_00221120* p = next;
        Node_00221120* q;
        while ((q = p->Valid()) != 0) {
            p = q->next;
            n++;
        }
        return n;
    }
};

struct Skater_00221120 {
    char pad0[0x31C];
    int m31C;
};

struct Mgr_00221120 {
    char pad0[0x30];
    Node_00221120 m30;
};

extern Mgr_00221120* D_0038FC78;
extern "C" int func_001E8708(void* params, unsigned int id);
extern "C" Skater_00221120* func_0022DE70(Mgr_00221120* m, unsigned int i);
extern "C" int func_00203360(Skater_00221120* s);
extern "C" void func_00238088(int a, int on);

bool func_00221120(void* params, void* script)
{
    Mgr_00221120* mgr = D_0038FC78;
    unsigned int i = 0;
    int off = func_001E8708(params, 0x929EB4D5);
    for (; i < mgr->m30.Count(); i++) {
        Skater_00221120* s = func_0022DE70(mgr, i);
        if (s->m31C) func_00238088(func_00203360(s), off ^ 1);
    }
    return true;
}
