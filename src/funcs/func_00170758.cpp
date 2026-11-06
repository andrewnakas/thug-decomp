struct Node_00170758 {
    char pad0[0x3C];
    unsigned int m3C;
    void Fn(unsigned int col);
};

extern "C" void func_00170600(Node_00170758* self, int v);

void Node_00170758::Fn(unsigned int col)
{
    if (col == 0x80808080)
        func_00170600(this, 0);
    m3C = col;
}
