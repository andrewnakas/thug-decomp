struct Col_00299368 {
    unsigned char r, g, b, a;
    Col_00299368(int r, int g, int b, int a);
};

extern "C" void func_00134F28(void* p, Col_00299368 c);

struct Obj_00299368 {
    char pad[0x34];
    void* m34;
    void* m38;
    void SetColor(Col_00299368 c);
};

void Obj_00299368::SetColor(Col_00299368 c)
{
    if (m38)
        func_00134F28(m38, c);
    if (m34)
        func_00134F28(m34, c);
}
