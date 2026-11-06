extern void* D_00392068;

struct Msg_00215B68 {
    unsigned char m_id;
    char m_pad1[0xB];
    int m_type;
    unsigned char m_size;
    char m_pad11[0xF];
    Msg_00215B68();
};

struct Obj_00215B68 {
    char m_pad0[0x1C];
    int m_kind;
    char m_pad20[0x2FC];
    int m31C;
    int m320;
};

struct Script_00215B68 {
    char m_pad[0xBC];
    Obj_00215B68* m_obj;
};

extern "C" void* func_002A39E0(void* mgr, int id);
/* sym: __12Msg_00215B68 = 0x001FA800 */
extern "C" void func_00200C00(void* conn, Msg_00215B68* m);

bool Cmd_00215B68(void* params, Script_00215B68* script)
{
    void* mgr = D_00392068;
    Obj_00215B68* o = 0;
    if (script) {
        Obj_00215B68* p = script->m_obj;
        if (p && p->m_kind == 1)
            o = p;
    }
    if (o && o->m31C) {
        void* conn = func_002A39E0(mgr, o->m320);
        if (conn) {
            Msg_00215B68 m;
            m.m_id = 0x45;
            m.m_type = 2;
            m.m_size = 8;
            func_00200C00(conn, &m);
        }
    }
    return true;
}
