struct Obj_0021C5A0;
extern void* D_0038C608;
extern "C" Obj_0021C5A0* func_00187278(void* mgr, unsigned int type);
extern "C" int func_0013E9C8(void* p, int i);
extern "C" int func_0013E9D8(void* p);

struct Info_0021C5A0 {
    char pad[0x1C];
    int m1C;
};

struct Base_0021C5A0 {
    int m0;
    int m4;
    int m8;
    Info_0021C5A0* mC;
    int m10;
    Obj_0021C5A0* m14;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10(unsigned int name, void* params, void* script);
};

struct Obj_0021C5A0 : Base_0021C5A0 {
    char pad[0x260 - 0x1C];
    void* m260;
};

bool Cmd_0021C5A0(void* params, void* script)
{
    int ids[32];
    int count = 0;
    for (Obj_0021C5A0* o = func_00187278(D_0038C608, 0x286A8D26); o; o = o->m14) {
        if (o->mC->m1C != 3) continue;
        void* list = o->m260;
        bool added = false;
        for (int i = 0; i < func_0013E9D8(list); i++) {
            int id = func_0013E9C8(list, i);
            bool found = false;
            for (int k = 0; k < count; k++) {
                if (id == ids[k]) found = true;
            }
            if (!found) {
                ids[count] = id;
                count++;
                added = true;
            }
        }
        if (added) o->V10(0x83F9BE15, params, script);
    }
    return true;
}
