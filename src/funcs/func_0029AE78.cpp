struct Arr_0029AE78 {
    char pad[0xC];
    unsigned int size;
    unsigned int GetSize() { return size; }
};

struct Node_0029AE78 {
    char pad[0x10];
    float pos[4];
    int on;
};

struct Obj_0029AE78;
extern "C" void func_0029B290(Obj_0029AE78* o);
extern "C" void* func_0029B378(Obj_0029AE78* o);
extern "C" Node_0029AE78* func_00299830(void* g);
extern "C" bool func_001E8248(void* s, unsigned int name, Arr_0029AE78** out, int a);
extern "C" void* func_001E9378(Arr_0029AE78* a, int i);
extern "C" bool func_001E7FA8(void* s, unsigned int name, float* v, int a);
extern "C" bool func_001E8708(void* s, unsigned int name);

struct Obj_0029AE78 {
    char pad[0x28];
    void* m28;
    void Load(void* in);
};

void Obj_0029AE78::Load(void* in)
{
    func_0029B290(this);
    Arr_0029AE78* arr = 0;
    func_001E8248(in, 0x244550A6, &arr, 0);
    if (!arr)
        return;
    for (unsigned int i = 0; i < arr->GetSize(); i++) {
        void* gs = func_001E9378(arr, i);
        func_0029B378(this);
        Arr_0029AE78* narr = 0;
        func_001E8248(gs, 0xD84571D6, &narr, 1);
        for (unsigned int j = 0; j < narr->GetSize(); j++) {
            Node_0029AE78* nd = func_00299830(m28);
            void* s = func_001E9378(narr, j);
            func_001E7FA8(s, 0x7F261953, nd->pos, 0);
            if (func_001E8708(s, 0xDCDED772))
                nd->on = 1;
        }
    }
}
