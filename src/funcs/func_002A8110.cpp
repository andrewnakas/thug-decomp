extern char D_00392198[];
extern char D_003920C0[];
extern char D_00378990[];

struct Msg_002A8110 {
    unsigned char type;
    char pad1;
    short len;
    void* data;
    int m8;
    int mC;
    unsigned char m10;
    char pad11[0xF];
};

struct Chat_002A8110 {
    unsigned char m0;
    char m1[0x10];
    char m11[0xA0 - 0x11];
};

struct Inner_002A8110 {
    char pad[0x18];
    int m18;
    int Get() { return m18; }
};

struct Elem_002A8110 {
    char pad[0x18];
    Inner_002A8110* m18;
    char pad1C[0x34 - 0x1C];
    char m34[4];
};

struct Obj_002A8110;
extern "C" int func_001FA800(Msg_002A8110* m);
extern "C" Elem_002A8110* func_002A56E0(Obj_002A8110* o);
extern "C" char* func_00331A9C(char* d, const char* s);
extern "C" int func_002B1FE8(void* item);
extern "C" int func_00331BB8(const char* s);
extern "C" void func_00200C00(void* w, Msg_002A8110* m);
extern "C" void* func_001190D0(int size);
extern "C" void* func_001E6978(void* p);
extern "C" int func_003331D0(char* buf, char* fmt, ...);
extern "C" void func_001E7138(void* p, char* name, char* value);
extern "C" void func_001F0370(char* s, void* a, int b, int c);
extern "C" void func_001E6AE8(void* p, int v);

struct Obj_002A8110 {
    char pad[0x18];
    void* m18;
    void Say(char* text);
};

void Obj_002A8110::Say(char* text)
{
    Chat_002A8110 chat;
    char buf[0x100];
    Msg_002A8110 msg;
    func_001FA800(&msg);
    if (!text[0])
        return;
    Elem_002A8110* e = func_002A56E0(this);
    func_00331A9C(chat.m1, e->m34);
    func_00331A9C(chat.m11, text);
    if (func_002B1FE8(e))
        chat.m0 = 8;
    else
        chat.m0 = e->m18->Get();
    int len = func_00331BB8(text);
    msg.len = len + 0x12;
    msg.type = 0x4C;
    msg.mC = 2;
    msg.m10 = 8;
    msg.data = &chat;
    func_00200C00(m18, &msg);
    void* s = func_001E6978(func_001190D0(8));
    func_003331D0(buf, D_00392198, e->m34, text);
    func_001E7138(s, D_003920C0, buf);
    func_001F0370(D_00378990, s, 0, 0);
    if (s)
        func_001E6AE8(s, 3);
}
