struct Node_0029C1A0 {
    char pad[4];
    Node_0029C1A0* m4;
};
struct Obj_0029C1A0;
extern "C" int func_0029C020(Obj_0029C1A0* p);
extern "C" int func_0029C048(Obj_0029C1A0* p);
extern "C" void func_001E7200(void* p, unsigned int key, int v);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" void func_0029A078(Node_0029C1A0* n, void* s);
extern "C" void func_001E78A8(void* p, unsigned int key, void* s);
extern "C" void func_001E7360(void* s, unsigned int name, unsigned int v);
extern "C" int func_0029B468(Obj_0029C1A0* p);
extern "C" void* func_00122CF8(int size);
extern "C" void* func_001E8DD0(void* p);
extern "C" void func_001E8E98(void* arr, int n, int type);
extern "C" void func_001E9170(void* arr, int i, void* s);
extern "C" void func_001E7720(void* s, unsigned int name, void* arr);
extern "C" void func_00184EB0(Obj_0029C1A0* p, void* s);

struct Obj_0029C1A0 {
    char pad[0x24];
    Node_0029C1A0* m24;
    Node_0029C1A0* m28;
    void GetDebugInfo(void* s);
};

void Obj_0029C1A0::GetDebugInfo(void* p)
{
    func_001E7200(p, 0x8C75A6C1, func_0029C020(this));
    func_001E7200(p, 0xE954B3D4, func_0029C048(this));
    if (m28) {
        void* s = func_001E6978(func_001190D0(8));
        func_0029A078(m28, s);
        func_001E78A8(p, 0xE234F2B2, s);
    } else {
        func_001E7360(p, 0xE234F2B2, 0xDA3403B0);
    }
    int n = func_0029B468(this);
    if (n) {
        int k = 0;
        void* arr = func_001E8DD0(func_00122CF8(16));
        func_001E8E98(arr, n, 10);
        for (Node_0029C1A0* e = m24; e; e = e->m4) {
            void* s = func_001E6978(func_001190D0(8));
            func_0029A078(e, s);
            func_001E9170(arr, k++, s);
        }
        func_001E7720(p, 0x7E17DFA9, arr);
    }
    func_00184EB0(this, p);
}
