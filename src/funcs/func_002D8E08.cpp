struct Obj_002D8E08_B {
    char pad0[0x78];
    int m78;
};

struct Obj_002D8E08_A {
    char pad0[0x10];
    Obj_002D8E08_B* m10;
};

extern Obj_002D8E08_A* D_00392068;

extern "C" void func_002D55F0(void* p, int v);
extern "C" void func_002D55F8(void* p, int v);
extern "C" void func_002D5600(void* p, int v);
extern "C" void func_002D8BC8(Obj_002D8E08_B* p, int mode, int arg, int flag);
extern "C" void func_002D8A98(Obj_002D8E08_B* p, int arg);

int func_002D8E08(int a0, int result, int arg, int a3, void* task)
{
    func_002D55F0(task, 100);
    if (result == 0) {
        Obj_002D8E08_A* mgr = D_00392068;
        func_002D55F8(task, 1);
        func_002D5600(task, 0);
        Obj_002D8E08_B* p = mgr->m10;
        switch (p->m78) {
        case 0:
        case 1:
            func_002D8BC8(p, p->m78, arg, 0);
            break;
        case 2:
        case 3:
            func_002D8BC8(p, p->m78, arg, 1);
            break;
        case 4:
            func_002D8A98(p, arg);
            break;
        }
    } else {
        func_002D55F8(task, 2);
        func_002D5600(task, result);
    }
    return 1;
}
