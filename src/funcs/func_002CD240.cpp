struct Node_002CD240 {
    int m0;
    int m4;
    unsigned char m8;
    signed char m9;
    unsigned char mA;
    char padB;
    int mC;
    unsigned char m10;
    unsigned char m11;
    char pad12[6];
    Node_002CD240* m18;
};

struct Def_002CD240 {
    char pad0[0x34];
    unsigned int m34;
};

extern "C" void* func_002CE5C8(unsigned int size);
extern "C" Node_002CD240* func_002CC8A8(void* p);
extern "C" void* func_002C0368();
extern "C" int func_002BE5F0(void* p, unsigned int key, int v);
extern "C" int func_002C4750();
extern "C" int func_002C4770();

struct Obj_002CD240 {
    int m0;
    Def_002CD240* m4;
    unsigned char m8;
    signed char m9;
    unsigned char mA;
    char padB;
    int mC;
    int m10;
    int m14;
    Node_002CD240* m18;
    bool Build();
};

bool Obj_002CD240::Build()
{
    if (!m4)
        return true;
    switch (m4->m34) {
    case 0x16C20A54:
    case 0x1F74467F:
    case 0x61C53AC2:
    case 0x66A8FEDB:
    case 0x88A69FF7:
    case 0x8FCB5BEE:
    case 0xF8CC6B78:
    case 0xFFA1AF61:
        break;
    default:
        return true;
    }
    int h = m9;
    int failed = 0;
    Node_002CD240* head = 0;
    Node_002CD240* first = 0;
    while (h > 0) {
        if (func_002C4750() == func_002C4770()) {
            failed = 1;
            break;
        }
        Node_002CD240* n = func_002CC8A8(func_002CE5C8(0x1C));
        if (!first)
            first = n;
        if (h == m9)
            n->m4 = func_002BE5F0(func_002C0368(), 0x2C5B0277, 0);
        else
            n->m4 = func_002BE5F0(func_002C0368(), 0x72372C50, 0);
        n->m8 = m8;
        n->m9 = h;
        h--;
        n->mA = mA;
        n->m10 = 1;
        n->m11 = 1;
        n->mC = mC;
        n->m18 = head;
        head = n;
    }
    if (head) {
        first->m18 = m18;
        m18 = head;
    }
    return failed ^ 1;
}
