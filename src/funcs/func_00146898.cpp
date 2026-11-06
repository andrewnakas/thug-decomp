extern "C" void func_00170600(void* p, int a);

struct Col_00146898 {
    unsigned char r, g, b, a;
};

extern "C" void func_00170758(void* p, unsigned int c);

struct Obj_00146898 {
    char pad[0x30];
    void* m30;
    char pad34[0x4C];
    Col_00146898 m80;
    void SetColor(Col_00146898* c);
};

void Obj_00146898::SetColor(Col_00146898* c)
{
    m80 = *c;
    if (m30) {
        func_00170600(m30, 1);
        func_00170758(m30, *(unsigned int*)c);
    }
}
