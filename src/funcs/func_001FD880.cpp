/* sym: _$_13Conn_001FD880 = 0x00201A68 */
struct Conn_001FD880 {
    ~Conn_001FD880();
};

struct Node_001FD880 {
    int m0;
    Conn_001FD880* data;
    int m8;
    Node_001FD880* next;
    Node_001FD880* Valid() { return ~(int)data != 0 ? this : 0; }
    Conn_001FD880* GetData() { return data; }
};

extern char D_00366B58[];

struct It_001FD880 {
    int m0;
    Node_001FD880* cur;
    void* vt;
    It_001FD880() { vt = D_00366B58; cur = 0; }
    ~It_001FD880() { vt = D_00366B58; }
    Conn_001FD880* Next()
    {
        cur = cur->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Conn_001FD880* Advance(Node_001FD880* c)
    {
        cur = c->next->Valid();
        if (!cur) return 0;
        return cur->GetData();
    }
    Conn_001FD880* First(Node_001FD880* h)
    {
        cur = h;
        return Next();
    }
};

struct Net_001FD880 {
    char pad0[4];
    char m4[0x181C];
    int m1820;
    char pad1824[0x2AB4];
    Node_001FD880 m42D8;
    void Shutdown();
};

extern "C" int func_00201288(Net_001FD880* n);
extern "C" void func_003253C0(int s);
extern "C" void func_001FC128(char* p);

void Net_001FD880::Shutdown()
{
    It_001FD880 it;
    if (!func_00201288(this)) func_003253C0(m1820);
    func_001FC128(m4);
    Conn_001FD880* c = it.First(&m42D8);
    if (c) {
        It_001FD880* p = &it;
        do {
            Conn_001FD880* next = p->Advance(it.cur);
            delete c;
            c = next;
        } while (c);
    }
}
