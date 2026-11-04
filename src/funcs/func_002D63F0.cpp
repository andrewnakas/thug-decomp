extern char D_0037C1F0[];
extern char D_0037C208[];

struct Node_002D63F0 {
    int m0;
    void* data;
    int m8;
    Node_002D63F0* next;
    Node_002D63F0* prev;
    void* tag;
    Node_002D63F0(void* d, void* t) { data = d; m8 = 0; next = this; prev = this; tag = t; }
};

struct Obj_002D63F0 : Node_002D63F0 {
    int m18;
    char pad1C[0x18];
    Node_002D63F0 list;
    Obj_002D63F0();
};

Obj_002D63F0::Obj_002D63F0() : Node_002D63F0(this, D_0037C1F0), list((void*)-1, D_0037C208)
{
    m18 = 0;
}
