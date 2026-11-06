/* fuzzy: 58.6 */
struct MsgDesc_002006C8 {
    unsigned char m_id;
    unsigned char m1;
    unsigned short m_length;
    void* m_data;
    int m8;
    int m_priority;
    unsigned char m_queue;
    char pad11[0xF];
};

struct Header_002006C8 {
    char m_name[0x20];
    int m_size;
    int m_seq;
    int m_crc;
    unsigned char m_type;
    char m_data[0x100];
};

struct Cont_002006C8 {
    int m_seq;
    char m_data[0x100];
};

struct Pending_002006C8 {
    int m_size;
    int m_seq;
    unsigned char m_type;
    char m_name[0x23];
    char* m_buf;
    char* m_cur;
    unsigned char m_queue;
    int m_count;
    int pad3C;
    int m_flag;
};

struct Node_002006C8 {
    char pad[0xC];
    Node_002006C8* m_next;
    Node_002006C8* m_prev;
};

struct Heap_002006C8 {
    char pad[0xF4];
    int mF4;
};

struct Mgr_002006C8 {
    char pad0[0x48];
    int m48;
    char pad4C[0x80 - 0x4C];
    int m_count[0x800 / 4];
    int m880;
    char pad884[0x209C - 0x884];
    Node_002006C8 m_list;
};

extern Heap_002006C8* D_00388A70;
extern "C" void func_001FA800(MsgDesc_002006C8*);
extern "C" int func_001053C8(char*, int);
extern "C" char* func_00331A9C(char*, char*);
extern "C" void* func_00331404(void*, void*, int);
extern "C" int func_001FF970(void*, int, MsgDesc_002006C8*, int);
extern "C" void func_0010A950(Heap_002006C8*, int);
extern "C" void* func_0010A638(Heap_002006C8*, int, int, int);
extern "C" Pending_002006C8* func_001FA780(void*);
extern "C" void* func_001046B0(int);
extern "C" Node_002006C8* func_001FA758(void*, Pending_002006C8*);
extern "C" void func_0010A9B0(Heap_002006C8*);

void func_002006C8(void* conn, Mgr_002006C8* mgr, unsigned char type, unsigned short size, char* data,
                   char* name, unsigned char queue, int stream, int keep)
{
    Header_002006C8 hdr;
    Cont_002006C8 cont;
    MsgDesc_002006C8 desc;
    func_001FA800(&desc);
    int chunk = size;
    bool small = size <= 0x100;
    if (!small)
        chunk = 0x100;
    hdr.m_size = size;
    hdr.m_seq = mgr->m880;
    hdr.m_crc = func_001053C8(data, size);
    hdr.m_type = type;
    func_00331A9C(hdr.m_name, name);
    func_00331404(hdr.m_data, data, size > 0x100 ? 0x100 : size);
    desc.m_id = 0xE;
    desc.m_length = chunk + 0x30;
    desc.m_priority = 2;
    desc.m1 = 1;
    desc.m_data = &hdr;
    desc.m_queue = queue;
    func_001FF970(conn, mgr->m48, &desc, 1);
    if (!small) {
        if (stream) {
            if (chunk < size) {
                data += chunk;
                do {
                    int n = size - chunk;
                    if (n > 0x100)
                        n = 0x100;
                    cont.m_seq = mgr->m880;
                    func_00331404(cont.m_data, data, n);
                    chunk += n;
                    data += n;
                    desc.m_length = n + 4;
                    desc.m_id = 0xF;
                    desc.m_data = &cont;
                    desc.m_priority = 2;
                    desc.m_queue = queue;
                    desc.m1 = 1;
                    func_001FF970(conn, mgr->m48, &desc, 1);
                } while (chunk < size);
            }
        } else {
            func_0010A950(D_00388A70, D_00388A70->mF4);
            int blocks = (size - 1) / 256;
            char* buf;
            if (keep) {
                buf = data;
            } else {
                buf = (char*)func_0010A638(D_00388A70, size, 1, 0);
                func_00331404(buf, data, size);
            }
            void* mem = func_0010A638(D_00388A70, 0x44, 1, 0);
            char* cur = buf + chunk;
            Pending_002006C8* p = func_001FA780(mem);
            Node_002006C8* node = func_001FA758(func_001046B0(0x1C), p);
            p->m_size = size;
            p->m_seq = mgr->m880;
            p->m_type = type;
            func_00331A9C(p->m_name, name);
            p->m_queue = queue;
            p->m_buf = buf;
            p->m_cur = cur;
            int* cnt = &mgr->m_count[queue];
            p->m_count = *cnt;
            p->m_flag = keep;
            Node_002006C8* head = &mgr->m_list;
            node->m_next = head;
            node->m_prev = head->m_prev;
            head->m_prev->m_next = node;
            head->m_prev = node;
            *cnt += blocks;
            func_0010A9B0(D_00388A70);
        }
    }
    mgr->m880++;
}
