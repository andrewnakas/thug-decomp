extern char D_0037C6E8[];
extern char D_00392DE8[];
extern "C" int func_003331D0(char* buf, const char* fmt, ...);

struct Node_002D88A8 {
    int m0;
    void* data;
    int m8;
    Node_002D88A8* next;
    Node_002D88A8* prev;
    void* tag;
    Node_002D88A8(void* d, void* t) { data = d; m8 = 0; next = this; prev = this; tag = t; }
};

struct Obj_002D88A8 : Node_002D88A8 {
    char pad18[0x3C - 0x18];
    int m3C;
    int m40;
    char pad44[0xC];
    char m50;
    char pad51[0x150 - 0x51];
    char m150[0x20];
    Obj_002D88A8();
};

Obj_002D88A8::Obj_002D88A8() : Node_002D88A8(this, D_0037C6E8)
{
    m40 = 0;
    m3C = 0;
    m50 = 0;
    func_003331D0(m150, D_00392DE8);
}
