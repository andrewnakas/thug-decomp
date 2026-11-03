struct Color_00299F38 {
    unsigned char r, g, b, a;
};

struct Node_00299F38 {
    char pad[0x2C];
    Node_00299F38* next;
};

extern "C" void* func_001E55B8(unsigned int crc, int a);
extern "C" void* func_001E93A0(void* p, int i);
extern "C" int func_001E9270(void* p, int i);
extern "C" void func_00299368(Node_00299F38* n, Color_00299F38* c);

struct Obj_00299F38 {
    char pad[0xC];
    Node_00299F38* head;
    void SetColor(int idx);
};

void Obj_00299F38::SetColor(int idx)
{
    void* arr = func_001E93A0(func_001E55B8(0x7F1BA1AA, 0), idx);
    Color_00299F38 c;
    c.r = func_001E9270(arr, 0);
    c.g = func_001E9270(arr, 1);
    c.b = func_001E9270(arr, 2);
    c.a = 0x80;
    for (Node_00299F38* n = head; n; n = n->next) {
        Color_00299F38 t = c;
        func_00299368(n, &t);
    }
}
