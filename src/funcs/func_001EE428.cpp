/* sym: __13Link_001EE428 = 0x00183BF0 */
struct Triple_001EE428 {
    int a, b, c;
    Triple_001EE428() { b = 0; c = 0; a = 0; }
};

struct Link_001EE428 {
    int m0;
    int m4;
    int m8;
    Link_001EE428();
};

struct Script_001EE428;
extern Script_001EE428* D_0038E7D8;
extern int D_0038E7DC;
extern int D_0038E7E0;

struct Script_001EE428 {
    int m0;
    Script_001EE428* m_next;
    Script_001EE428* m_prev;
    char padC[0x20 - 0xC];
    int m20[5];
    int* m34;
    char pad38[0x3C - 0x38];
    int m3C[0x16];
    int* m94;
    char pad98[0xAC - 0x98];
    int m_id;
    char padB0[0xB8 - 0xB0];
    int mB8;
    Triple_001EE428 mBC;
    char padC8[0xDC - 0xC8];
    int mDC;
    char padE0[0xE8 - 0xE0];
    Link_001EE428 mE8;

    Script_001EE428();
};

Script_001EE428::Script_001EE428()
{
    int* p = (int*)this;
    for (unsigned int i = 0; i < 0x3D; i++)
        *p++ = 0;
    m_next = D_0038E7D8;
    if (D_0038E7D8)
        D_0038E7D8->m_prev = this;
    D_0038E7D8 = this;
    D_0038E7DC++;
    m_id = D_0038E7E0++;
    mB8 = -1;
    m94 = m3C;
    m34 = m20;
    mDC = 0;
}
