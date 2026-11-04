typedef int qword_00223D18 __attribute__((mode(TI)));

union Vec_00223D18 {
    qword_00223D18 q;
    struct {
        float x, y, z, w;
    } v;
};

struct MsgDesc_00223D18 {
    unsigned char m_Id;
    unsigned char pad1;
    unsigned short m_Length;
    void* m_Data;
    int pad8;
    int m_Priority;
    unsigned char m_Queue;
    char pad11[0xF];
};

struct MsgData_00223D18 {
    int m_a;
    int pad[3];
    Vec_00223D18 m_pos;
    Vec_00223D18 m_dir;
    unsigned int m_name;
    int m_int;
    float m_float;
    unsigned char m_id;
};

extern void* D_00392068;

extern "C" bool func_001E8398(void* params, unsigned int key, unsigned int* out, int required);
extern "C" bool func_001E7FA8(void* params, unsigned int key, Vec_00223D18* out, int required);
extern "C" bool func_001E7EB0(void* params, unsigned int key, float* out, int required);
extern "C" bool func_001E7DE8(void* params, unsigned int key, int* out, int required);
extern "C" void* func_002A39E0(void* a, int b);
extern "C" void func_001FA800(MsgDesc_00223D18* desc);
extern "C" void func_00200C00(void* client, MsgDesc_00223D18* desc);

bool func_00223D18(void* params)
{
    void* mgr = D_00392068;
    Vec_00223D18 pos;
    Vec_00223D18 dir;
    MsgDesc_00223D18 desc;
    MsgData_00223D18 data;
    unsigned int id;
    unsigned int name;
    float f;
    int i;
    func_001E8398(params, 0x0830ECAF, &id, 0);
    func_001E8398(params, 0x7321A8D6, &name, 0);
    func_001E7FA8(params, 0x7F261953, &pos, 0);
    func_001E7FA8(params, 0x0C4C809E, &dir, 0);
    func_001E7EB0(params, 0x13B9DA7B, &f, 0);
    func_001E7DE8(params, 0xC48391A5, &i, 0);
    void* client = func_002A39E0(mgr, 0);
    if (client) {
        func_001FA800(&desc);
        data.m_id = id;
        data.m_pos.q = pos.q;
        data.m_dir.q = dir.q;
        data.m_int = i;
        data.m_float = f;
        data.m_name = name;
        desc.m_Id = 0x83;
        desc.m_Data = &data;
        desc.m_Length = 0x40;
        desc.m_Priority = 2;
        desc.m_Queue = 8;
        data.m_a = 0;
        func_00200C00(client, &desc);
    }
    return true;
}
