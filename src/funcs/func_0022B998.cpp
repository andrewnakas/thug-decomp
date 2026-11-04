extern char D_00372728[];
extern int D_0038881C;

struct Heap_0022B998 {
    char pad[0xE4];
    void* m_E4;
};

extern Heap_0022B998* D_00388A70;

struct Entry_0022B998 {
    int m_0;
    char m_list[0x4C];
    char m_50[0x44];
};

struct Inputs_0022B998 {
    char pad[8];
    Entry_0022B998 m_entries[1];
};

extern Inputs_0022B998* D_0038C3C0;

struct Lists_0022B998 {
    char pad[8];
    char m_list[1];
};

extern Lists_0022B998* D_0038C308;

struct Handler_0022B998 {
    char pad[0x1C];
    void* m_1C;
    int m_20;
    int m_index;
};

struct Server_0022B998 {
    int pad;
    char m_disp[1];
};

struct Viewer_0022B998 {
    char pad[0x18];
    Handler_0022B998* m_18;
    Handler_0022B998* m_1C;
    void* m_20;
    void* m_24;
    char pad28[0x34];
    Server_0022B998* m_5C;
};

typedef int (*MsgHandler_0022B998)(void* msg);

extern "C" int func_0022B5B0(void* msg);
extern "C" int func_0022B6E0(void* msg);
extern "C" int func_0022B6E8(void* msg);
extern "C" int func_0022B638(void* msg);
extern "C" int func_0022B750(void* msg);
extern "C" int func_0022B800(void* msg);
extern "C" int func_0022B820(void* msg);
extern "C" void* func_001FBF60(void* disp, int id, MsgHandler_0022B998 h, int flags, void* data, int mask);
extern "C" void func_0010A950(Heap_0022B998* heap, void* a);
extern "C" void func_0010A9B0(Heap_0022B998* heap);
extern "C" void func_00105260(void* list, void* node);
extern "C" int func_00103F28(const char* fmt, ...);

static inline void AddHandler_0022B998(Inputs_0022B998* in, Handler_0022B998* h)
{
    func_00105260(in->m_entries[h->m_index].m_list, h);
    h->m_1C = in->m_entries[h->m_index].m_50;
    h->m_20 = in->m_entries[h->m_index].m_0;
}

void func_0022B998(Viewer_0022B998* viewer)
{
    Inputs_0022B998* in = D_0038C3C0;
    Lists_0022B998* lists = D_0038C308;
    func_0010A950(D_00388A70, D_00388A70->m_E4);
    if (!D_0038881C) {
        func_001FBF60(viewer->m_5C->m_disp, 0x20, func_0022B5B0, 3, 0, 0x80);
        func_001FBF60(viewer->m_5C->m_disp, 0x21, func_0022B6E0, 3, 0, 0x80);
        func_001FBF60(viewer->m_5C->m_disp, 0x22, func_0022B6E8, 3, 0, 0x80);
        func_001FBF60(viewer->m_5C->m_disp, 0x2A, func_0022B638, 3, 0, 0x80);
        func_001FBF60(viewer->m_5C->m_disp, 0x23, func_0022B750, 3, viewer, 0x80);
        func_001FBF60(viewer->m_5C->m_disp, 0x24, func_0022B800, 3, viewer, 0x80);
        func_001FBF60(viewer->m_5C->m_disp, 0x2B, func_0022B820, 3, viewer, 0x80);
    }
    func_00105260(lists->m_list, viewer->m_20);
    AddHandler_0022B998(in, viewer->m_18);
    func_00103F28(D_00372728);
    AddHandler_0022B998(in, viewer->m_1C);
    func_00105260(lists->m_list, viewer->m_24);
    func_0010A9B0(D_00388A70);
}
