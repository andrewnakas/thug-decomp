extern char* D_0038C308;
extern int D_00392428;

struct Obj_002B5608;
extern "C" void func_00105260(void* list, void* p);
extern "C" int func_002B5690(Obj_002B5608* o);
extern "C" void func_001048F0(void* p);

struct Obj_002B5608 {
    char pad[0x98];
    void* m98;
    char pad9C[0x194 - 0x9C];
    int m194;
    void SetState(int s);
};

void Obj_002B5608::SetState(int s)
{
    m194 = s;
    switch (s) {
    case 1:
        func_00105260(D_0038C308 + 8, m98);
        SetState(func_002B5690(this));
        D_00392428 = 0;
        break;
    case 2:
        func_001048F0(m98);
        break;
    }
}
