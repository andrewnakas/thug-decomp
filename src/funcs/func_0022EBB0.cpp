extern void* D_00392068;

class Iter_0022EBB0 {
public:
    void* m_node;
    int m_index;
    Iter_0022EBB0() : m_index(0) {}
    virtual ~Iter_0022EBB0() {}
    virtual void Run();
};

struct MsgDesc_0022EBB0 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct Data_0022EBB0 {
    char m_id;
};

struct Skater_0022EBB0 {
    char pad[0x18];
    int m_id;
    char pad1C[0x2DC - 0x1C];
    void* m_2DC;
    int GetId() const { return m_id; }
};

extern "C" bool func_002A8560(void* net);
extern "C" bool func_002A24D8(void* net);
extern "C" void* func_0022E358(void* g);
extern "C" unsigned int func_0024F938(void* p);
extern "C" Skater_0022EBB0* func_0022DE70(void* g, int i);
extern "C" void func_00278AA0(void* p, int a);
extern "C" void* func_002A8498(void* net);
extern "C" bool func_00268108(void* p);
extern "C" bool func_002789E8(void* p);
extern "C" void* func_002A52F0(void* net, unsigned short id);
extern "C" void func_002B2BC0(void* p, int a);
extern "C" void* func_002A53F8(void* net, Iter_0022EBB0* it, int a);
extern "C" void* func_002A5490(void* net, Iter_0022EBB0* it, int a);
extern "C" bool func_002B1FC8(void* p);
extern "C" void func_001FA800(MsgDesc_0022EBB0* desc);
extern "C" void* func_002A39D8(void* net);
extern "C" int func_002B3080(void* p);
extern "C" void func_001FF970(void* client, int conn, MsgDesc_0022EBB0* desc);

void func_0022EBB0(void* self)
{
    void* net = D_00392068;
    if (func_002A8560(net))
        return;
    if (!func_002A24D8(net) && func_0024F938(func_0022E358(self)) != 0xBFF33600 &&
        func_0024F938(func_0022E358(self)) != 0x3D6D444F && func_0024F938(func_0022E358(self)) != 0x6EF8FDA0 &&
        func_0024F938(func_0022E358(self)) != 0x5D32129C && func_0024F938(func_0022E358(self)) != 0x6C5FF266)
        return;
    int i;
    Skater_0022EBB0* sk;
    for (i = 0; i < 8; i++) {
        sk = func_0022DE70(self, i);
        if (sk)
            func_00278AA0(sk->m_2DC, 0);
    }
    if (func_0024F938(func_0022E358(self)) != 0x6EF8FDA0 && func_0024F938(func_0022E358(self)) != 0x5D32129C)
        return;
    void* mgr = func_002A8498(net);
    if (!mgr || func_00268108(mgr))
        return;
    for (i = 0; i < 8; i++) {
        sk = func_0022DE70(self, i);
        if (sk && func_002789E8(sk->m_2DC)) {
            Iter_0022EBB0 it;
            func_002B2BC0(func_002A52F0(net, sk->GetId()), 1);
            for (void* p = func_002A53F8(net, &it, 1); p; p = func_002A5490(net, &it, 1)) {
                if (func_002B1FC8(p))
                    continue;
                MsgDesc_0022EBB0 desc;
                func_001FA800(&desc);
                void* client = func_002A39D8(net);
                Data_0022EBB0 data;
                data.m_id = sk->GetId();
                desc.m_Data = &data;
                desc.m_Length = 1;
                desc.m_Id = 0x55;
                desc.m_Priority = 2;
                desc.m_Queue = 8;
                func_001FF970(client, func_002B3080(p), &desc);
            }
            return;
        }
    }
}
