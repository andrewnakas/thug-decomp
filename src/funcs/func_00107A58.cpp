extern "C" void* func_001046B0(int);
extern "C" void* func_003315B8(void*, int, int);
extern "C" char* func_0010BDE0(int);
extern char D_0035AEF0[];
extern char D_0035AE80[];

struct Node_00107A58 {
    int m0;
    void* m_data;
    int m8;
    Node_00107A58* m_next;
    Node_00107A58* m_prev;
    void* m_vtbl;
};

struct Stream_00107A58 {
    int m0;
    Node_00107A58* m_node;
    int pad8[2];
    int m_10;
    int m_14;
    int m_18;
    char* m_1C;
    char m_20[0x20];
    char m_40[0x20];
    char m_60[0x20];
    char pad80[0xC4 - 0x80];
    int m_C4;
    int padC8;
    int m_CC;
    int m_D0;
    int m_D4;
    char* m_D8;
    int m_DC;
    int m_E0;
    int m_E4;
    int m_E8;
    void* m_vtbl;
    Stream_00107A58(int a, int b, int c);
};

Stream_00107A58::Stream_00107A58(int a, int b, int c)
{
    m_C4 = 0;
    m_CC = 0;
    m_vtbl = D_0035AEF0;
    Node_00107A58* n = (Node_00107A58*)func_001046B0(0x18);
    n->m_data = this;
    n->m8 = 0;
    n->m_vtbl = D_0035AE80;
    n->m_next = n;
    n->m_prev = n;
    m_E4 = a;
    m_10 = b;
    m_14 = c;
    m_E8 = 1;
    m_DC = 0;
    m_E0 = 0;
    m_CC = 0;
    m_D4 = 0;
    m_D0 = 0;
    m_18 = 0;
    m_node = n;
    func_003315B8(m_60, 0, 0x20);
    func_003315B8(m_40, 0xFF, 0x20);
    m_40[1] = 1;
    m_40[0] = 0;
    func_003315B8(m_20, 0, 0x20);
    m_D8 = func_0010BDE0(0x13F);
    m_1C = (char*)(((unsigned int)m_D8 + 0x3F) & 0xFFFFFFC0);
    func_003315B8(m_1C, 0, 0x100);
}
