extern "C" void* func_001E6E90(void* list, void* prev);
extern "C" unsigned int func_001E53A0(void* p, int a);
extern "C" void* func_002CC830();
extern "C" void func_002CC1F8(void* p, void* a, void* b);

struct Node_002C8568 {
    char pad0[0x8];
    void* m8;
};

struct Obj_002C8568 {
    char pad0[0x80];
    char m80[0x4C];
    void* mCC;
    unsigned int mD0;
    void Load(void* list);
};

void Obj_002C8568::Load(void* list)
{
    if (!list) return;
    unsigned int mask = 0;
    Node_002C8568* n = (Node_002C8568*)func_001E6E90(list, 0);
    while (n) {
        mask |= func_001E53A0(n->m8, 0);
        n = (Node_002C8568*)func_001E6E90(list, n);
    }
    mD0 = mask;
    func_002CC1F8(func_002CC830(), mCC, m80);
}
