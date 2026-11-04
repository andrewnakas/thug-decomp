extern char D_00379EA0[];
extern char D_00378CE8[];
extern char D_003924C8[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct Head_002B51A0 {
    int m0;
    unsigned int m_data;
    int m8;
    Head_002B51A0* m_next;
    Head_002B51A0* m_prev;
    void* m_vt;
    Head_002B51A0() {
        m_data = 0xFFFFFFFF;
        m8 = 0;
        m_next = this;
        m_prev = this;
        m_vt = D_00378CE8;
    }
};

struct Node_002B51A0 {
    int m0;
    void* m_data;
    int m8;
    Node_002B51A0* m_next;
    Node_002B51A0* m_prev;
    void* m_vt;
    Node_002B51A0(void* d) {
        m_vt = D_00379EA0;
        m_data = d;
        m8 = 0;
        m_next = this;
        m_prev = this;
    }
};

struct Obj_002B51A0 : Node_002B51A0 {
    char pad18[0x30 - 0x18];
    int m30;
    int m34;
    int m38;
    int m3C;
    int m40;
    char m44[0x20];
    char m64[0x24];
    int m88;
    unsigned char m8C;
    int m90;
    int m94;
    int m98;
    int m9C;
    int mA0;
    int mA4;
    int mA8;
    int mAC;
    Head_002B51A0 m_list;
    Obj_002B51A0();
};

Obj_002B51A0::Obj_002B51A0() : Node_002B51A0(this)
{
    m9C = 0;
    mA0 = 0;
    m30 = 0;
    func_003331D0(m44, D_003924C8);
    func_003331D0(m64, D_003924C8);
    m38 = 8;
    m8C = 2;
    m34 = 1;
    m40 = 1;
    m98 = 1;
    m3C = 0;
    m90 = 0;
    m94 = 0;
    m88 = 0;
    mA4 = 0;
    mA8 = 0;
    mAC = 0;
}
